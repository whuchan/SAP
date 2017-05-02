//==========================================
//
// File: MouseKingState.cpp
//
// MouseKing ��ԑJ�� �t�@�C��
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "MouseKingState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\MouseKing\MouseKingCharacter.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CMouseKingState
//
// MouseKing ��� ���N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseKingState::CMouseKingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseKingState::~CMouseKingState(void)
{

}

/**
* @desc �ҋ@��Ԃֈڍs
*/
void CMouseKingState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �p�j��Ԃֈڍs
*/
void CMouseKingState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �U����Ԃֈڍs
*/
void CMouseKingState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



/**
* @desc �U�����󂯂Ă����Ԃֈڍs
*/
void CMouseKingState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc ���S��Ԃֈڍs
*/
void CMouseKingState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc �U���ł���擾
* @return true...�ł��� false...�o���Ȃ�
*/
bool CMouseKingState::checkEnableAttack(void)
{

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();


	if (this->m_pOwner->m_attackInterval <= 0)
	{
		if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 384.0f ||
			customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 384.0f)
		{
			return true;
		}
	}
	else
	{
		//�U���Ԋu�����炷
		this->m_pOwner->m_attackInterval--;
	}

	return false;
}


//==========================================
//
// Class: CMouseKingIdleState
//
// MouseKing �ҋ@ ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseKingIdleState::CMouseKingIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseKingIdleState::~CMouseKingIdleState()
{

}

/**
* @desc	�J�n����
*/
void CMouseKingIdleState::start(void)
{
	//�I�[�i�[�̃A�N�V������start���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

	//�����_���ŃA�N�V�������Ԃ�ݒ�(30~60)
	this->m_actionInterval = rand() % 30 + 31;
}

/**
* @desc �X�V����
*/
void CMouseKingIdleState::update(void)
{
	//�J�E���^�[���C���N�������g
	this->m_actionCounter++;

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�U���ł��邩�H
	if (this->checkEnableAttack())
	{
		//�U����Ԃֈڍs
		this->toAttack();
		return;
	}

	//�U�����󂯂����H
	if (this->m_pOwner->m_underAttack)
	{
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
		return;
	}

	//�J�E���^�[���C���^�[�o���ȏ�Ȃ�
	if (this->m_actionCounter >= this->m_actionInterval) {
		//�J�E���^�[�����Z�b�g
		this->m_actionCounter = 0;

		//���܂悢�s���Ɉڍs
		this->toWandering();
		return;
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMouseKingIdleState::onChangeEvent(void)
{
	//�I�[�i�[�̃A�N�V������stop���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->stop();

	this->m_actionInterval = 45;

	this->m_actionCounter = 0;

	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseKingWanderingState
//
// MouseKing �p�j ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseKingWanderingState::CMouseKingWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseKingWanderingState::~CMouseKingWanderingState()
{

}

/**
* @desc	�J�n����
*/
void CMouseKingWanderingState::start(void)
{
	//�I�[�i�[�̃A�N�V������start���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

	//�����_���ŕ���������ݒ�
	this->m_vec = (rand() % 3) - 1;
	//�����_���ŃA�N�V�������Ԃ�ݒ�(30~60)
	this->m_actionInterval = rand() % 30 + 31;

	if (this->m_vec == 0)
	{
		//������~
		for (CAction* pAction : (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState]))
		{
			pAction->stop();
		}
		//�ҋ@��ԂɈڍs
		this->toIdle();
		return;
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
void CMouseKingWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�U���ł��邩�H
	if (this->checkEnableAttack())
	{
		//�U����Ԃֈڍs
		this->toAttack();
		return;
	}

	//�U�����󂯂����H
	if (this->m_pOwner->m_underAttack)
	{
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
		return;
	}

	//�J�E���^�[���C���N�������g
	this->m_actionCounter++;
	//�J�E���^�[���C���^�[�o���ȏ�Ȃ�
	if (this->m_actionCounter >= this->m_actionInterval) {
		//�J�E���^�[�����Z�b�g
		this->m_actionCounter = 0;
		//�J�n��ԂɈڍs
		this->start();
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMouseKingWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseKingAttackState
//
// MouseKing�@�U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseKingAttackState::CMouseKingAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseKingAttackState::~CMouseKingAttackState()
{

}

/**
* @desc	�J�n����
*/
void CMouseKingAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//�A�j���[�V���������Z�b�g
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();

	CMouseKingCharacter* pOwner = (CMouseKingCharacter*)this->m_pOwner;

	this->m_nextAttackOrder = m_nextAttackOrder * -1;
	switch (this->m_nextAttackOrder)
	{
	case 1:
			if (pOwner->m_pHenchmans[0])
			{
				if (pOwner->m_pHenchmans[0]->m_isAlive)
				{
					pOwner->m_pHenchmans[0]->setAttackOrder(true);
					this->m_pOrderChara = pOwner->m_pHenchmans[0];
				}
				else
				{
					//�����F������NULL�����Ȃ��Ɖ��̂��\�����Ȃ��f�[�^���c��
					pOwner->m_pHenchmans[0] = NULL;
				}
			}
			
			break;

	case -1:
			if (pOwner->m_pHenchmans[1])
			{
				if (pOwner->m_pHenchmans[1]->m_isAlive)
				{
					pOwner->m_pHenchmans[1]->setAttackOrder(true);
					this->m_pOrderChara = pOwner->m_pHenchmans[1];
				}
				else
				{
					//�����F������NULL�����Ȃ��Ɖ��̂��\�����Ȃ��f�[�^���c��
					pOwner->m_pHenchmans[1] = NULL;
				}
			}
			break;

	default:break;
	}
}

/**
* @desc �X�V����
*/
void CMouseKingAttackState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if (!this->m_pOrderChara || this->m_pOrderChara->getAttackOrder() == false)
	{
			//�ҋ@��Ԃֈڍs
			this->toIdle();
			return;
	}
	
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMouseKingAttackState::onChangeEvent(void)
{
	this->m_pOrderChara = NULL;
	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseKingUnderAttackState
//
// MouseKing �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseKingUnderAttackState::CMouseKingUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseKingUnderAttackState::~CMouseKingUnderAttackState()
{

}

/**
* @desc	�J�n����
*/
void CMouseKingUnderAttackState::start(void)
{
	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
	(*this->m_pOwner->m_mapAction[(int)this->m_pOwner->m_actionState])[0]->start();


	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	if (this->m_pOwner->m_pMove->m_pos.x >= pPlayer->m_pMove->m_pos.x)
	{
		this->m_vec = 1;
	}
	else
	{
		this->m_vec = -1;
	}
}

/**
* @desc �X�V����
*/
void CMouseKingUnderAttackState::update(void)
{

	//���S�������H
	if (!this->m_pOwner->m_isAlive)
	{
		this->toDead();
		return;
	}

	if (this->m_pOwner->m_pMove->m_vel.y == 0.0f)
	{
		//�U���󂯂Ă����Ԃ����낷
		this->m_pOwner->m_underAttack = false;

		//�ҋ@��Ԃ�
		this->toIdle();
		return;
	}

	//������ݒ�
	this->m_pOwner->m_pMove->m_vel.x = 6.0f * this->m_vec;
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMouseKingUnderAttackState::onChangeEvent(void)
{
	//�������O��
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�A�N�V�������Z�b�g
	(*this->m_pOwner->m_mapAction[(int)ENEMY_MOUSEKING_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseKingDeadState
//
// MouseKing �U�����󂯂� ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseKingDeadState::CMouseKingDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseKingDeadState::~CMouseKingDeadState()
{

}

/**
* @desc	�J�n����
*/
void CMouseKingDeadState::start(void)
{
	//���ŃJ�E���^�[��ݒ�
	this->m_disappearanceCounter = 300;
}

/**
* @desc �X�V����
*/
void CMouseKingDeadState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		if (this->m_pOwner->getNumberOfRunningActions() <= 0 &&
			this->m_disappearanceCounter <= 120)
		{

			this->m_pOwner->setOpacity(50);
			this->m_pOwner->runAction(CCBlink::create((float)3.0f, (int)15));
		}

		//���Ԍo�߂ŏ���
		if (this->m_disappearanceCounter <= 0)
		{
			//�L���t���O��������
			this->m_pOwner->m_activeFlag = false;
		}

		this->m_disappearanceCounter--;
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMouseKingDeadState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}


//EOF