#include"PlayerStateLineUp.h"
#include "Model\Character\PlayerCharacter.h"
#include "Lib\Input\InputManager.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateLineUp
//
// �v���C���[ ���C���A�b�v ��ԃN���X
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerStateLineUp::CPlayerStateLineUp(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CPlayerStateLineUp::~CPlayerStateLineUp(void)
{

}

/**
* @desc	�J�n����
*/
void CPlayerStateLineUp::enter(void)
{
	this->m_pOwner->m_intCurrentLine++;

	// 1�b�����āA�X�P�[�����k������
	ScaleTo* pOrder = ScaleTo::create(1.0, 1.0f - this->m_pOwner->m_intCurrentLine * 0.2f);
	this->m_pAction = this->m_pOwner->runAction(pOrder);
	CC_SAFE_RETAIN(this->m_pAction); // ����ɊJ������Ȃ��悤�ɎQ�ƃJ�E���^�𑝂₷

	
}

/**
* @desc	�X�V����
*/
void CPlayerStateLineUp::execute(void)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: LineUp");
#endif //_DEBUG_PLAYER_STATE
	if (this->m_pAction->isDone())
	{
		//�ҋ@��Ԃֈڍs
		this->toIdle();
		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerStateLineUp::exit(void)
{
	this->m_isNext = false;

	//�g��Ȃ��Ȃ�����������
	CC_SAFE_RELEASE(this->m_pAction);
}
//EOF