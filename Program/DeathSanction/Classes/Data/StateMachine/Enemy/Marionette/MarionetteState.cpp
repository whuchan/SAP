//==========================================
//
// File: MarionetteState.cpp
//
// Marionette ��ԑJ�� �t�@�C��
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "MarionetteState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\Marionette\MarionetteCharacter.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Model\Map\Map.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CMarionetteState
//
// Marionette ��� ���N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMarionetteState::CMarionetteState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMarionetteState::~CMarionetteState(void)
{

}

/**
* @desc �ҋ@��Ԃֈڍs
*/
void CMarionetteState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �p�j��Ԃֈڍs
*/
void CMarionetteState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �U����Ԃֈڍs
*/
void CMarionetteState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



/**
* @desc �U�����󂯂Ă����Ԃֈڍs
*/
void CMarionetteState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc ���S��Ԃֈڍs
*/
void CMarionetteState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc �U���ł���擾
* @return true...�ł��� false...�o���Ȃ�
*/
bool CMarionetteState::checkEnableAttack(void)
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
// Class: CMarionetteIdleState
//
// Marionette �ҋ@ ��� �N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMarionetteIdleState::CMarionetteIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMarionetteIdleState::~CMarionetteIdleState()
{

}

/**
* @desc	�J�n����
*/
void CMarionetteIdleState::start(void)
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
void CMarionetteIdleState::update(void)
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
void CMarionetteIdleState::onChangeEvent(void)
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
// Class: CMarionetteWanderingState
//
// Marionette �p�j ��� �N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMarionetteWanderingState::CMarionetteWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{
	this->m_targetPositions[CMarionetteCharacter::IDLE_POSITION::RIGHT] = cocos2d::Point(WINDOW_RIGHT - this->m_pOwner->m_pBody->m_right,0);
	this->m_targetPositions[CMarionetteCharacter::IDLE_POSITION::CENTER] = cocos2d::Point(WINDOW_RIGHT*0.5f, 0);
	this->m_targetPositions[CMarionetteCharacter::IDLE_POSITION::LEFT] = cocos2d::Point(0, 0);
}

/**
* @desc �f�X�g���N�^
*/
CMarionetteWanderingState::~CMarionetteWanderingState()
{

}

/**
* @desc	�J�n����
*/
void CMarionetteWanderingState::start(void)
{
	//�I�[�i�[�̃A�N�V������start���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

	//�A�b�v�L���X�g
	CMarionetteCharacter* pMarionette = (CMarionetteCharacter*)this->m_pOwner;

	pMarionette->m_numIdlePosition = rand() % (int)CMarionetteCharacter::IDLE_POSITION::MAX_IDLE_POSITION;

	cocos2d::Vec2 positionLayer = CCharacterAggregate::getInstance()->getLayer()->getPosition();
	if ( (this->m_targetPositions[pMarionette->m_numIdlePosition].x - positionLayer.x) - this->m_pOwner->m_pMove->m_pos.x >= 0.0f)
	{
		this->m_vec = 1;
	}
	else
	{
		this->m_vec = -1;
	}

	//������ݒ�
	this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(-1.0);
	}


	//�A�j���[�V���������Z�b�g
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();


}

/**
* @desc �X�V����
*/
void CMarionetteWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	
	//�U�����󂯂����H
	if (this->m_pOwner->m_underAttack)
	{
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
		return;
	}

	//�A�b�v�L���X�g
	CMarionetteCharacter* pMarionette = (CMarionetteCharacter*)this->m_pOwner;

	cocos2d::Vec2 positionLayer = CCharacterAggregate::getInstance()->getLayer()->getPosition();
	if (abs( (this->m_targetPositions[pMarionette->m_numIdlePosition].x - positionLayer.x ) - this->m_pOwner->m_pMove->m_pos.x) < this->m_pOwner->m_status.getSpeed() + 256)
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
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMarionetteWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CMarionetteAttackState
//
// Marionette�@�U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMarionetteAttackState::CMarionetteAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMarionetteAttackState::~CMarionetteAttackState()
{

}

/**
* @desc	�J�n����
*/
void CMarionetteAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//�A�j���[�V���������Z�b�g
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();

	
}

/**
* @desc �X�V����
*/
void CMarionetteAttackState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		cocos2d::Point fallKnifeLaunchPoints[4];

		//�A�b�v�L���X�g
		CMarionetteCharacter* pMarionette = (CMarionetteCharacter*)this->m_pOwner;

		cocos2d::Vec2 positionLayer = CCharacterAggregate::getInstance()->getLayer()->getPosition();
		switch(pMarionette->m_numIdlePosition)
		{
		case CMarionetteCharacter::IDLE_POSITION::RIGHT:
															fallKnifeLaunchPoints[0] = cocos2d::Point( -positionLayer.x + 224.0f,952.0f);
															fallKnifeLaunchPoints[1] = cocos2d::Point(-positionLayer.x + 704.0f, 952.0f);
															fallKnifeLaunchPoints[2] = cocos2d::Point(-positionLayer.x + 1184.0f, 952.0f);
															fallKnifeLaunchPoints[3] = cocos2d::Point(-positionLayer.x + 1664.0f, 952.0f);
															break;
		case CMarionetteCharacter::IDLE_POSITION::CENTER:
															fallKnifeLaunchPoints[0] = cocos2d::Point(-positionLayer.x + 224.0f, 952.0f);
															fallKnifeLaunchPoints[1] = cocos2d::Point(-positionLayer.x + 704.0f, 952.0f);
															fallKnifeLaunchPoints[2] = cocos2d::Point(-positionLayer.x + 1184.0f, 952.0f);
															fallKnifeLaunchPoints[3] = cocos2d::Point(-positionLayer.x + 1664.0f, 952.0f);

															break;
		case CMarionetteCharacter::IDLE_POSITION::LEFT:	
															fallKnifeLaunchPoints[0] = cocos2d::Point(-positionLayer.x + 224.0f, 952.0f);
															fallKnifeLaunchPoints[1] = cocos2d::Point(-positionLayer.x + 704.0f, 952.0f);
															fallKnifeLaunchPoints[2] = cocos2d::Point(-positionLayer.x + 1184.0f, 952.0f);
															fallKnifeLaunchPoints[3] = cocos2d::Point(-positionLayer.x + 1664.0f, 952.0f);

															break;
		default:
			break;
		}

		CDamageLaunchData* pLaunchData = NULL;
		CDamageLaunchTrigger* pLaunchTrigger = NULL;
		for (int index = 0; index < CMarionetteCharacter::IDLE_POSITION::MAX_IDLE_POSITION; index++)
		{
			//�_���[�W�L�����N�^�[�����f�[�^���쐬
			pLaunchData = new CDamageLaunchData(this->m_pOwner,
				fallKnifeLaunchPoints[index],
				500, DAMAGE_TYPE::FALL_KNIFE);
			//�_���[�W�L�����N�^�[�����g���K�[���쐬
			pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

			//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
			CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
		}

		//�ҋ@��Ԃֈڍs
		this->toIdle();
		return;
	}

}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMarionetteAttackState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CMarionetteUnderAttackState
//
// Marionette �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMarionetteUnderAttackState::CMarionetteUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMarionetteUnderAttackState::~CMarionetteUnderAttackState()
{

}

/**
* @desc	�J�n����
*/
void CMarionetteUnderAttackState::start(void)
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
void CMarionetteUnderAttackState::update(void)
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
void CMarionetteUnderAttackState::onChangeEvent(void)
{
	//�������O��
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�A�N�V�������Z�b�g
	(*this->m_pOwner->m_mapAction[(int)ENEMY_MARIONETTE_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CMarionetteDeadState
//
// Marionette �U�����󂯂� ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMarionetteDeadState::CMarionetteDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMarionetteDeadState::~CMarionetteDeadState()
{

}

/**
* @desc	�J�n����
*/
void CMarionetteDeadState::start(void)
{
	//���ŃJ�E���^�[��ݒ�
	this->m_disappearanceCounter = 300;
}

/**
* @desc �X�V����
*/
void CMarionetteDeadState::update(void)
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
void CMarionetteDeadState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}


//EOF