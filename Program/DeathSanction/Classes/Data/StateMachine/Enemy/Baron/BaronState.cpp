//==========================================
//
// File: BaronState.cpp
//
// Baron ��ԑJ�� �t�@�C��
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "BaronState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\EnemyCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CBaronState
//
// Baron ��� ���N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CBaronState::CBaronState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CBaronState::~CBaronState(void)
{

}

/**
* @desc �ҋ@��Ԃֈڍs
*/
void CBaronState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �U����Ԃֈڍs
*/
void CBaronState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �U�����󂯂Ă����Ԃֈڍs
*/
void CBaronState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc ���S��Ԃֈڍs
*/
void CBaronState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc �U���ł���擾
* @return true...�ł��� false...�o���Ȃ�
*/
bool CBaronState::checkEnableAttack(void)
{

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();


	if (this->m_pOwner->m_attackInterval <= 0)
	{
		if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 768.0f ||
			customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 768.0f)
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
// Class: CBaronIdleState
//
// Baron �ҋ@ ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CBaronIdleState::CBaronIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CBaronIdleState::~CBaronIdleState()
{

}

/**
* @desc	�J�n����
*/
void CBaronIdleState::start(void)
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
void CBaronIdleState::update(void)
{
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
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CBaronIdleState::onChangeEvent(void)
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
// Class: CBaronAttackState
//
// Baron�@�U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CBaronAttackState::CBaronAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CBaronAttackState::~CBaronAttackState()
{

}

/**
* @desc	�J�n����
*/
void CBaronAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 120;

	//�A�j���[�V���������Z�b�g
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CBaronAttackState::update(void)
{
	//�U�����󂯂����H
	if (this->m_pOwner->m_underAttack)
	{
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
		return;
	}

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		//�_���[�W�L�����N�^�[�����f�[�^���쐬
		CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
			cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
			300, DAMAGE_TYPE::SMOKE);
		//�_���[�W�L�����N�^�[�����g���K�[���쐬
		CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

		//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
		CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);

		//�ҋ@��Ԃֈڍs
		this->toIdle();
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CBaronAttackState::onChangeEvent(void)
{

	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CBaronUnderAttackState
//
// Baron �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CBaronUnderAttackState::CBaronUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CBaronUnderAttackState::~CBaronUnderAttackState()
{

}

/**
* @desc	�J�n����
*/
void CBaronUnderAttackState::start(void)
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
void CBaronUnderAttackState::update(void)
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
void CBaronUnderAttackState::onChangeEvent(void)
{
	//�������O��
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�A�N�V�������Z�b�g
	(*this->m_pOwner->m_mapAction[(int)ENEMY_BARON_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CBaronDeadState
//
// Baron �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CBaronDeadState::CBaronDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CBaronDeadState::~CBaronDeadState()
{

}

/**
* @desc	�J�n����
*/
void CBaronDeadState::start(void)
{
	//���ŃJ�E���^�[��ݒ�
	this->m_disappearanceCounter = 300;
}

/**
* @desc �X�V����
*/
void CBaronDeadState::update(void)
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
void CBaronDeadState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}

