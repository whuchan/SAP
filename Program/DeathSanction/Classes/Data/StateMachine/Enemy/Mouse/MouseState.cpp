//==========================================
//
// File: MouseState.cpp
//
// Mouse ��ԑJ�� �t�@�C��
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "MouseState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Model\Character\EnemyCharacter\MouseKing\MouseKingCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CMouseState
//
// Mouse ��� ���N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseState::CMouseState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseState::~CMouseState(void)
{

}

/**
* @desc �ҋ@��Ԃֈڍs
*/
void CMouseState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �p�j��Ԃֈڍs
*/
void CMouseState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �U����Ԃֈڍs
*/
void CMouseState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



/**
* @desc �U�����󂯂Ă����Ԃֈڍs
*/
void CMouseState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc ���S��Ԃֈڍs
*/
void CMouseState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}




//==========================================
//
// Class: CMouseIdleState
//
// Mouse �ҋ@ ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseIdleState::CMouseIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseIdleState::~CMouseIdleState()
{

}

/**
* @desc	�J�n����
*/
void CMouseIdleState::start(void)
{
	//�I�[�i�[�̃A�N�V������start���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();
}

/**
* @desc �X�V����
*/
void CMouseIdleState::update(void)
{
	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�}�E�X�L�����N�^�[�փA�b�v�L���X�g
	CMouseCharacter* pOwner = (CMouseCharacter*)this->m_pOwner;

	if (!pOwner->m_pMaster->m_isAlive)
	{
		pOwner->m_isAlive = false;
		this->toDead();
	}


	//�U���ł��邩�H
	if (pOwner->getAttackOrder())
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


	//
	cocos2d::Vec2 vec2TargetPos = pOwner->m_pMaster->m_pMove->m_pos;
	if (pOwner->m_pMaster->getScaleX() < 0)
	{
		switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
		{
		case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x += 128.0f;
			break;
		case HENCHMAN_POSITION_TYPE::DEFENDER:
			vec2TargetPos.x += 64.0f;
			break;
		default:break;
		}
	}
	else
	{
		switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
		{
		case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x -= 128.0f;
			break;
		case HENCHMAN_POSITION_TYPE::DEFENDER:
			vec2TargetPos.x -= 64.0f;
			break;
		default:break;
		}
	}



	//�A�C�h����Ԃɖ߂邩
	if (customMath->length(vec2TargetPos, pOwner->m_pMove->m_pos) >= 3.0f && pOwner->m_pMove->m_vel.y >= 0.0f)
	{
		//���܂悢�s���Ɉڍs
		this->toWandering();
		return;
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMouseIdleState::onChangeEvent(void)
{
	//�I�[�i�[�̃A�N�V������stop���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->stop();

	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseWanderingState
//
// Mouse �p�j ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseWanderingState::CMouseWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseWanderingState::~CMouseWanderingState()
{

}

/**
* @desc	�J�n����
*/
void CMouseWanderingState::start(void)
{
	//�I�[�i�[�̃A�N�V������start���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

}

/**
* @desc �X�V����
*/
void CMouseWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�}�E�X�L�����N�^�[�փA�b�v�L���X�g
	CMouseCharacter* pOwner = (CMouseCharacter*)this->m_pOwner;

	if (!pOwner->m_pMaster->m_isAlive)
	{
		pOwner->m_isAlive = false;
		this->toDead();
	}


	//�U���ł��邩�H
	if (pOwner->getAttackOrder())
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

	if (pOwner->m_pMaster)
	{
		cocos2d::Vec2 vec2TargetPos = pOwner->m_pMaster->m_pMove->m_pos;
		if (pOwner->m_pMaster->getScaleX() < 0)
		{
			switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
			{
			case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x += 128.0f;
				break;
			case HENCHMAN_POSITION_TYPE::DEFENDER:
				vec2TargetPos.x += 64.0f;
				break;
			default:break;
			}
			this->m_vec = 1;
		}
		else
		{
			switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
			{
			case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x -= 128.0f;
				break;
			case HENCHMAN_POSITION_TYPE::DEFENDER:
				vec2TargetPos.x -= 64.0f;
				break;
			default:break;
			}
			this->m_vec = -1;
		}



		//�A�C�h����Ԃɖ߂邩
		if (customMath->length(vec2TargetPos, pOwner->m_pMove->m_pos) < 3.0f)
		{
			if (pOwner->m_pMaster->getScaleX() < 0)
			{
				switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
				{
				case HENCHMAN_POSITION_TYPE::FORWARD:	pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x + 128.0f;
					break;
				case HENCHMAN_POSITION_TYPE::DEFENDER:
					pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x + 64.0f;
					break;
				default:break;
				}
			}
			else
			{
				switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
				{
				case HENCHMAN_POSITION_TYPE::FORWARD:	pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x - 128.0f;
					break;
				case HENCHMAN_POSITION_TYPE::DEFENDER:
					pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x - 64.0f;
					break;
				default:break;
				}
			}



			this->toIdle();
			return;
		}
		else
		{
			//������ݒ�
			this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

			pOwner->setScaleX(this->m_vec * -1.0f);
		}
	}

}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMouseWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseAttackState
//
// Mouse�@�U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseAttackState::CMouseAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseAttackState::~CMouseAttackState()
{

}

/**
* @desc	�J�n����
*/
void CMouseAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//�A�j���[�V���������Z�b�g
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CMouseAttackState::update(void)
{
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
void CMouseAttackState::onChangeEvent(void)
{
	//�}�E�X�L�����N�^�[�փA�b�v�L���X�g
	CMouseCharacter* pOwner = (CMouseCharacter*)this->m_pOwner;
	//�U�����߃t���O�����낷
	pOwner->setAttackOrder(false);

	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseUnderAttackState
//
// Mouse �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseUnderAttackState::CMouseUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseUnderAttackState::~CMouseUnderAttackState()
{

}

/**
* @desc	�J�n����
*/
void CMouseUnderAttackState::start(void)
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
void CMouseUnderAttackState::update(void)
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
void CMouseUnderAttackState::onChangeEvent(void)
{
	//�������O��
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�A�N�V�������Z�b�g
	(*this->m_pOwner->m_mapAction[(int)ENEMY_MOUSE_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseDeadState
//
// Mouse �U�����󂯂� ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMouseDeadState::CMouseDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMouseDeadState::~CMouseDeadState()
{

}

/**
* @desc	�J�n����
*/
void CMouseDeadState::start(void)
{
	//���ŃJ�E���^�[��ݒ�
	this->m_disappearanceCounter = 300;
}

/**
* @desc �X�V����
*/
void CMouseDeadState::update(void)
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
void CMouseDeadState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}


//EOF