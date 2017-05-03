#include"PlayerStateIdle.h"
#include"Model\Character\PlayerCharacter.h"
#include"cocos2d.h"
#include "Lib\Input\InputManager.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateIdle
//
// �v���C���[ �ҋ@ ��ԃN���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerStateIdle::CPlayerStateIdle(CPlayerCharacter* const pOwner):CPlayerState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CPlayerStateIdle::~CPlayerStateIdle(void) {}

/**
* @desc	�J�n����
*/
void CPlayerStateIdle::enter(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerStateIdle::execute(void)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player; Idle");
#endif//_DEBUG_PLAYER_STATE
	

	if (inputflag.m_d || inputflag.m_a)
	{
		this->toWalk();
		return;
	}
	log("Player; Idle");
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
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerStateIdle::exit(void)
{
	this->m_isNext = false;
}
//EOF