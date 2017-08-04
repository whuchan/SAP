#include "HenchmanTypeAStateMove.h"
#include "Model\Character\Character.h"
#include "Lib\Math\CustomMath.h"

//==========================================
//
// File: CHenchmanTypeAStateMove.cpp
//
// �q��A�ҋ@��� �t�@�C��
//
// 2017/06/05
//						Author Shinya Ueba
//==========================================


/**
* @desc	�R���X�g���N�^
*/
CHenchmanTypeAStateMove::CHenchmanTypeAStateMove(CHenchmanTypeAEnemy* const pOwner) :CHenchmanTypeAState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CHenchmanTypeAStateMove::~CHenchmanTypeAStateMove(void)
{

}

/**
* @desc	�J�n����
*/
void CHenchmanTypeAStateMove::enter(void)
{
	this->m_pTarget = CCharacterAggregate::getInstance()->getPlayer();
}
/**
* @desc	�X�V����
*/
void CHenchmanTypeAStateMove::execute(float deltaTime)
{
#ifdef _DEBUG_ENEMY_STATE
	log("Enemy: Move");
#endif //_DEBUG_ENEMY_STATE
	float length = CustomMath::distance(this->m_pTarget->m_pMove->m_pos,this->m_pOwner->m_pMove->m_pos);

//	if ()
	{
		this->toIdle();
		return;
	}
}
/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CHenchmanTypeAStateMove::exit(void)
{
	this->m_isNext = false;
}
//EOF