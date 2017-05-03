#include"PlayerStateWalk.h"
#include"Model\Character\PlayerCharacter.h"
#include "Lib\Input\InputManager.h"
#include "cocos2d.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateWalk
//
// �v���C���[ �ҋ@ ��ԃN���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerStateWalk::CPlayerStateWalk(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CPlayerStateWalk::~CPlayerStateWalk(void) {}

/**
* @desc	�J�n����
*/
void CPlayerStateWalk::enter(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerStateWalk::execute(float deltaTime)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: Walk");
#endif // _DEBUG_PLAYER_STATE

	this->m_pOwner->m_pMove->m_accele.x = 0.0f;


	if (inputflag.m_d)
	{
		this->m_pOwner->m_pMove->m_accele.x = 0.7f;
		return;
	}

	if (inputflag.m_a)
	{
		this->m_pOwner->m_pMove->m_accele.x = -0.7f;
		return;
	}

	if (inputflag.getTrigger(kInputType::W) &&
		this->m_pOwner->m_intCurrentLine < STAGE_MAX_LINE)
	{
		//���C���A�b�v��Ԃ�
		this->toLineUp();
		return;
	}
	else if (inputflag.getTrigger(kInputType::S) &&
		this->m_pOwner->m_intCurrentLine > 0)
	{
		//���C���_�E����Ԃ�
		this->toLineDown();
		return;
	}
	
	//�������Ȃ�������A�ҋ@��Ԃ�
	this->toIdle();
	return;
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerStateWalk::exit(void)
{
	this->m_isNext = false;

	this->m_pOwner->m_pMove->m_accele.x = 0.0f;
}
//EOF