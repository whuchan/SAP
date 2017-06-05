#include "HenchmanTypeAStateIdle.h"
//==========================================
//
// File: CHenchmanTypeAStateIdle.cpp
//
// �q��A�ҋ@��� �t�@�C��
//
// 2017/06/05
//						Author Shinya Ueba
//==========================================


/**
* @desc	�R���X�g���N�^
*/
CHenchmanTypeAStateIdle::CHenchmanTypeAStateIdle(CHenchmanTypeAEnemy* const pOwner) :CHenchmanTypeAState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CHenchmanTypeAStateIdle::~CHenchmanTypeAStateIdle(void)
{

}

/**
* @desc	�J�n����
*/
void CHenchmanTypeAStateIdle::enter(void)
{

}
/**
* @desc	�X�V����
*/
void CHenchmanTypeAStateIdle::execute(float deltaTime)
{
#ifdef _DEBUG_ENEMY_STATE
	log("Enemy: LineDown");
#endif //_DEBUG_ENEMY_STATE

}
/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CHenchmanTypeAStateIdle::exit(void)
{
	this->m_isNext = false;
}
//EOF