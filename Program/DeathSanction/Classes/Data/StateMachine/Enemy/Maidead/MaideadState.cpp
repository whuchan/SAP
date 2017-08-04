//==========================================
//
// File: MaideadState.cpp
//
// Maidead ��ԑJ�� �t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "MaideadState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\EnemyCharacter.h"
#include "Data\Enum\EnumEnemy.h"

//==========================================
//
// Class: CMaideadState
//
// Maidead ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadState::CMaideadState(	CEnemyCharacter* const pOwner,
								CPlayerCharacterBoy* const pPlayer,
								CGirlCharacter* const pGirl
	)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadState::~CMaideadState(void)
{

}

/**
* @desc �ҋ@��Ԃֈڍs
*/
void CMaideadState::toIdle(void)
{
	this->m_pOwner->m_state				=	(int)ENEMY_MAIDEAD_STATE::IDLE;
	this->m_pOwner->m_animationState	=	(int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState		=	(int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey				=	this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �p�j��Ԃֈڍs
*/
void CMaideadState::toWandering(void)
{
	this->m_pOwner->m_state				= (int)ENEMY_MAIDEAD_STATE::WANDERING;
	this->m_pOwner->m_animationState	= (int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState		= (int)ENEMY_MAIDEAD_ACTION_STATE::WANDERING;
	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �ǐՏ�Ԃֈڍs
*/
void CMaideadState::toChase(void)
{
	this->m_pOwner->m_state				= (int)ENEMY_MAIDEAD_STATE::CHASE;
	this->m_pOwner->m_animationState	= (int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING;	//�A�j���[�V�����̓����_�����O�Ɠ���
	this->m_pOwner->m_actionState		= (int)ENEMY_MAIDEAD_ACTION_STATE::CHASE;
	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc �U�����󂯂Ă����Ԃֈڍs
*/
void CMaideadState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MAIDEAD_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MAIDEAD_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc ���S��Ԃֈڍs
*/
void CMaideadState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MAIDEAD_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MAIDEAD_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


//==========================================
//
// Class: CMaideadIdleState
//
// Maidead �ҋ@ ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadIdleState::CMaideadIdleState(	CEnemyCharacter* const pOwner,
										CPlayerCharacterBoy* const pPlayer,
										CGirlCharacter* const pGirl
	)
	:CMaideadState::CMaideadState(pOwner,pPlayer,pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadIdleState::~CMaideadIdleState()
{

}

/**
* @desc	�J�n����
*/
void CMaideadIdleState::start(void)
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
void CMaideadIdleState::update(void)
{
	//�J�E���^�[���C���N�������g
	this->m_actionCounter++;


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

	// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F
	float length = customMath->checkTargetRange(this->m_pOwner, this->m_pOwner->m_targetType);
	//�����ǐՔ͈͓��Ȃ�
	if (length <= this->m_pOwner->m_chaseRange) {
		this->toChase();
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMaideadIdleState::onChangeEvent(void)
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
// Class: CMaideadWanderingState
//
// Maidead �p�j ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadWanderingState::CMaideadWanderingState(	CEnemyCharacter* const pOwner,
												CPlayerCharacterBoy* const pPlayer,
												CGirlCharacter* const pGirl
	)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadWanderingState::~CMaideadWanderingState()
{

}

/**
* @desc	�J�n����
*/
void CMaideadWanderingState::start(void)
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
		for(CAction* pAction : (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState]))
		{
			pAction->stop();
		}
		//�ҋ@��ԂɈڍs
		this->toIdle();
		return;
	}

	//������ݒ�
	this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec,0.0f);

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(-1.0);
	}
	
}

/**
* @desc �X�V����
*/
void CMaideadWanderingState::update(void)
{
	if (this->isNext())
	{
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

	// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F
	float length = customMath->checkTargetRange(this->m_pOwner, this->m_pOwner->m_targetType);
	//�����ǐՔ͈͓��Ȃ�
	if (length <= this->m_pOwner->m_chaseRange) {
		this->toChase();
	}

}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMaideadWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}



//==========================================
//
// Class: CMaideadUnderAttackState
//
// Maidead �U�����󂯂� ��� �N���X
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadUnderAttackState::CMaideadUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadUnderAttackState::~CMaideadUnderAttackState()
{

}

/**
* @desc	�J�n����
*/
void CMaideadUnderAttackState::start(void)
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
void CMaideadUnderAttackState::update(void)
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
void CMaideadUnderAttackState::onChangeEvent(void)
{
	//�������O��
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�A�N�V�������Z�b�g
	(*this->m_pOwner->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//�ҋ@������I��
	this->m_isNext = false;
}

//==========================================
//
// Class: CMaideadChaseState
//
// Maidead �ǐ� ��� �N���X
//
//						Author Osumi
// 2016/12/27
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadChaseState::CMaideadChaseState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadChaseState::~CMaideadChaseState()
{

}

/**
* @desc	�J�n����
*/
void CMaideadChaseState::start(void)
{
	//�I�[�i�[�̃A�N�V������start���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

}

/**
* @desc �X�V����
*/
void CMaideadChaseState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	//�G��������x���ꂽ�烏���_�����O��ԂɈڍs����
	float length = customMath->checkTargetRange(this->m_pOwner, this->m_pOwner->m_targetType);
	//�����ǐՔ͈͓��Ȃ�
	if (length > this->m_pOwner->m_chaseRange) {
		this->toWandering();
	}

}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMaideadChaseState::onChangeEvent(void)
{
	//�I�[�i�[�̃A�N�V������stop���Ă�
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->stop();

	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}
//==========================================
//
// Class: CMaideadDeadState
//
// Maidead �U�����󂯂� ��� �N���X
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadDeadState::CMaideadDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadDeadState::~CMaideadDeadState()
{

}

/**
* @desc	�J�n����
*/
void CMaideadDeadState::start(void)
{
	//���ŃJ�E���^�[��ݒ�
	this->m_disappearanceCounter = 300;
}

/**
* @desc �X�V����
*/
void CMaideadDeadState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		if(this->m_pOwner->getNumberOfRunningActions()<=0 && 
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
void CMaideadDeadState::onChangeEvent(void)
{
	//�ҋ@������I��
	this->m_isNext = false;
}

//EOF