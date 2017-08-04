//==========================================
//
// File: NutCrackerState.cpp
//
// NutCracker ��ԑJ�� �t�@�C��
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "NutCrackerState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\EnemyCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CNutCrackerState
//
// NutCracker ��� ���N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CNutCrackerState::CNutCrackerState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CNutCrackerState::~CNutCrackerState(void)
{

}

/**
* @desc �ҋ@��Ԃֈڍs
*/
void CNutCrackerState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �p�j��Ԃֈڍs
*/
void CNutCrackerState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �ǐՏ�Ԃֈڍs
*/
void CNutCrackerState::toChase(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::CHASE;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;	
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �U����Ԃֈڍs
*/
void CNutCrackerState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



/**
* @desc �U�����󂯂Ă����Ԃֈڍs
*/
void CNutCrackerState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc ���S��Ԃֈڍs
*/
void CNutCrackerState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc �U���ł���擾
* @return true...�ł��� false...�o���Ȃ�
*/
bool CNutCrackerState::checkEnableAttack(void)
{

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();


	if (this->m_pOwner->m_attackInterval <= 0)
	{
		if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 128.0f ||
			customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 128.0f)
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
// Class: CNutCrackerIdleState
//
// NutCracker �ҋ@ ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CNutCrackerIdleState::CNutCrackerIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CNutCrackerIdleState::~CNutCrackerIdleState()
{

}

/**
* @desc	�J�n����
*/
void CNutCrackerIdleState::start(void)
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
void CNutCrackerIdleState::update(void)
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
void CNutCrackerIdleState::onChangeEvent(void)
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
// Class: CNutCrackerWanderingState
//
// NutCracker �p�j ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CNutCrackerWanderingState::CNutCrackerWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CNutCrackerWanderingState::~CNutCrackerWanderingState()
{

}

/**
* @desc	�J�n����
*/
void CNutCrackerWanderingState::start(void)
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
void CNutCrackerWanderingState::update(void)
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


	//�G�����������H
	CCharacter* pTarget = NULL;
	if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 384.0f)
	{
		pTarget = pPlayer;
	}

	if (customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 384.0f)
	{
		pTarget = pGirl;
	}

	if (pTarget)
	{
		//���E�ɓ����Ă��邩?
		if (this->m_vec > 0)
		{
			if (pTarget->m_pMove->m_pos.x - this->m_pOwner->m_pMove->m_pos.x >= 0.0f)
			{
				//�ǂ��������Ԃ�
				this->toChase();
				return;
			}
		}
		else if (this->m_vec < 0)
		{
			if (this->m_pOwner->m_pMove->m_pos.x - pTarget->m_pMove->m_pos.x >= 0.0f)
			{
				//�ǂ��������Ԃ�
				this->toChase();
				return;
			}
		}
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
void CNutCrackerWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CNutCrackerAttackState
//
// NutCracker�@�U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CNutCrackerAttackState::CNutCrackerAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CNutCrackerAttackState::~CNutCrackerAttackState()
{

}

/**
* @desc	�J�n����
*/
void CNutCrackerAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//�A�j���[�V���������Z�b�g
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CNutCrackerAttackState::update(void)
{
	//�U���𐶐�����A�j���[�V�����t���[���̊m�F
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->getCurrentFrame()==2)
	{
		//�_���[�W�L�����N�^�[�����f�[�^���쐬
		CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
			cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
			1);
		//�_���[�W�L�����N�^�[�����g���K�[���쐬
		CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

		//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
		CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
	}
	else
	{
		//�U�����󂯂����H
		if (this->m_pOwner->m_underAttack)
		{
			//�U�����󂯂���Ԃֈڍs
			this->toUnderAttack();
			return;
		}
	}

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		//�ҋ@��Ԃֈڍs
		this->toIdle();
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CNutCrackerAttackState::onChangeEvent(void)
{

	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CNutCrackerUnderAttackState
//
// NutCracker �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CNutCrackerUnderAttackState::CNutCrackerUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CNutCrackerUnderAttackState::~CNutCrackerUnderAttackState()
{

}

/**
* @desc	�J�n����
*/
void CNutCrackerUnderAttackState::start(void)
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
void CNutCrackerUnderAttackState::update(void)
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
void CNutCrackerUnderAttackState::onChangeEvent(void)
{
	//�������O��
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�A�N�V�������Z�b�g
	(*this->m_pOwner->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CNutCrackerChaseState
//
// NutCracker �ǐ� ��� �N���X
//
//						Author Shinya Ueba
// 2017/01/09
//==========================================
/**
* @desc �R���X�g���N�^
*/
CNutCrackerChaseState::CNutCrackerChaseState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CNutCrackerChaseState::~CNutCrackerChaseState()
{

}

/**
* @desc	�J�n����
*/
void CNutCrackerChaseState::start(void)
{
	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�߂������^�[�Q�b�g�ɂ���
	float distanceToPlayer = customMath->lengthBitweenChara(this->m_pOwner, pPlayer);
	float distanceToGirl = customMath->lengthBitweenChara(this->m_pOwner, pGirl);

	if (distanceToPlayer < distanceToGirl)
	{
		this->m_pTarget = pPlayer;
	}
	else
	{
		this->m_pTarget = pGirl;
	}
}

/**
* @desc �X�V����
*/
void CNutCrackerChaseState::update(void)
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

	if (this->m_pTarget->m_pMove->m_pos.x - this->m_pOwner->m_pMove->m_pos.x > 0.0f)
	{
		this->m_vec = 1;
	}
	else
	{
		this->m_vec = -1;
	}

	//������ݒ�
	this->m_pOwner->m_pMove->m_vel.set(3.0f * this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(-1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(1.0);
	}

	/*
	//�G��������x���ꂽ�烏���_�����O��ԂɈڍs����
	float length = customMath->checkTargetRange(this->m_pOwner, this->m_pOwner->m_targetType);
	//�����ǐՔ͈͓��Ȃ�
	if (length > this->m_pOwner->m_chaseRange) {
		this->toWandering();
	}
	*/
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CNutCrackerChaseState::onChangeEvent(void)
{
	this->m_pTarget = NULL;
	this->m_vec = 0;

	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}
//==========================================
//
// Class: CNutCrackerDeadState
//
// NutCracker �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CNutCrackerDeadState::CNutCrackerDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CNutCrackerDeadState::~CNutCrackerDeadState()
{

}

/**
* @desc	�J�n����
*/
void CNutCrackerDeadState::start(void)
{
	//���ŃJ�E���^�[��ݒ�
	this->m_disappearanceCounter = 300;
}

/**
* @desc �X�V����
*/
void CNutCrackerDeadState::update(void)
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
void CNutCrackerDeadState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}

//EOF