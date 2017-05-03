#include"PlayerStateLineDown.h"
#include "Model\Character\PlayerCharacter.h"
#include"cocos2d.h"
#include "Lib\Input\InputManager.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateLineDown
//
// �v���C���[ ���C���_�E�� ��ԃN���X
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerStateLineDown::CPlayerStateLineDown(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CPlayerStateLineDown::~CPlayerStateLineDown(void) {}

/**
* @desc	�J�n����
*/
void CPlayerStateLineDown::enter(void)
{
	this->m_pOwner->m_intCurrentLine--;

	// 1�b�����āA�X�P�[�����g�傷��
	ScaleTo* pOrder = ScaleTo::create(1.0, 1.0f - this->m_pOwner->m_intCurrentLine * 0.2f);
	this->m_pAction = this->m_pOwner->runAction(pOrder);
	CC_SAFE_RETAIN(this->m_pAction); // ����ɊJ������Ȃ��悤�ɎQ�ƃJ�E���^�𑝂₷
}

/**
* @desc	�X�V����
*/
void CPlayerStateLineDown::execute(void)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: LineDown");
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
void CPlayerStateLineDown::exit(void)
{
	this->m_isNext = false;


	//�g��Ȃ��Ȃ�����������
	CC_SAFE_RELEASE(this->m_pAction);
}
//EOF