#include"PlayerStateIdle.h"
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
	log("Player; Idle");

	if (inputflag.m_d || inputflag.m_a)
	{
		this->toWalk();
		return;
	}

	if (inputflag.m_w)
	{
		return;
	}

	if (inputflag.m_s)
	{
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