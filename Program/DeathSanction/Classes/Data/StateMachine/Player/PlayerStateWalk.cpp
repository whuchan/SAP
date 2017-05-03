#include"PlayerStateWalk.h"
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
	log("Player: Walk");
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerStateWalk::exit(void)
{
	this->m_isNext = false;
}
//EOF