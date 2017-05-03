#include"PlayerStateIdle.h"
#include"cocos2d.h"

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
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerStateIdle::exit(void)
{
	this->m_isNext = false;
}
//EOF