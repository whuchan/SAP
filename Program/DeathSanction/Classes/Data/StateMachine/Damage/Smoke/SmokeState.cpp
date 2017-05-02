//==========================================
//
// File: SmokeState.cpp
//
// Smoke ��ԑJ�� �t�@�C��
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "SmokeState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\DamageCharacter\DamageCharacter.h"
#include "Data\Enum\EnumDamage.h"

//==========================================
//
// Class: CSmokeState
//
// Smoke ��� ���N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CSmokeState::CSmokeState(CDamageCharacter* const pOwner)
	:CDamageState::CDamageState(pOwner)
{

}

/**
* @desc �f�X�g���N�^
*/
CSmokeState::~CSmokeState(void)
{

}


/**
* @desc �U����Ԃֈڍs
*/
void CSmokeState::toAttack(void)
{
	this->m_pOwner->m_state = (int)DAMAGE_SMOKE_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)DAMAGE_SMOKE_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)DAMAGE_SMOKE_ACTION_STATE::ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



/**
* @desc ���S��Ԃֈڍs
*/
void CSmokeState::toDead(void)
{
	this->m_pOwner->m_state = (int)DAMAGE_SMOKE_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)DAMAGE_SMOKE_ANIMATION_STATE::DEAD;
	this->m_pOwner->m_actionState = (int)DAMAGE_SMOKE_ACTION_STATE::ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



//==========================================
//
// Class: CSmokeAttackState
//
// Smoke�@�U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CSmokeAttackState::CSmokeAttackState(CDamageCharacter* const pOwner)
	:CSmokeState::CSmokeState(pOwner)
{

}

/**
* @desc �f�X�g���N�^
*/
CSmokeAttackState::~CSmokeAttackState()
{

}

/**
* @desc	�J�n����
*/
void CSmokeAttackState::start(void)
{
	//�A�j���[�V���������Z�b�g
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();


	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	if (this->m_pOwner->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x >= 0.0f)
	{
		this->m_vec = -1;
	}
	else
	{
		this->m_vec = 1;
	}


	//������ݒ�
	this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(-1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(1.0);
	}
}

/**
* @desc �X�V����
*/
void CSmokeAttackState::update(void)
{
	//�U�����󂯂����H
	if (this->m_pOwner->m_underAttack)
	{
		//���S��Ԃֈڍs
		this->toDead();
		return;
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CSmokeAttackState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}



//==========================================
//
// Class: CSmokeDeadState
//
// Smoke ���S ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CSmokeDeadState::CSmokeDeadState(CDamageCharacter* const pOwner)
	:CSmokeState::CSmokeState(pOwner)
{

}

/**
* @desc �f�X�g���N�^
*/
CSmokeDeadState::~CSmokeDeadState()
{

}

/**
* @desc	�J�n����
*/
void CSmokeDeadState::start(void)
{

}

/**
* @desc �X�V����
*/
void CSmokeDeadState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		//�L���t���O��������
		this->m_pOwner->m_activeFlag = false;
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CSmokeDeadState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}