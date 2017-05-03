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
void CPlayerStateWalk::execute(void)
{
	this->m_pOwner->m_pMove->m_accele.x = 0.0f;

	log("Player: Walk");

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