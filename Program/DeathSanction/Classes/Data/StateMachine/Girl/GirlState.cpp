//==========================================
//
// File: GirlState.cpp
//
// Girl��ԑJ�� �t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "GirlState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\GirlCharacter\GirlCharacter.h"
#include "Data\Enum\EnumGirl.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"


//==========================================
//
// Class: CGirlState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlState::CGirlState(CPlayerCharacterGirl* pOwner)
:m_pGirl(pOwner){}

/**
* @desc	�f�X�g���N�^
*/
CGirlState::~CGirlState(void) {}

/**
* @desc	�E�����ҋ@��Ԃֈڍs
*/
void CGirlState::toIdleRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::IDLE_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�������ҋ@��Ԃֈڍs
*/
void CGirlState::toIdleLeft(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::IDLE_LEFT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�E�������s��Ԃֈڍs
*/
void CGirlState::toWalkRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::WALK_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	���������s��Ԃֈڍs
*/
void CGirlState::toWalkLeft(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::WALK_LEFT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_LEFT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



/*
* @desc	�E�������͂ޏ�Ԃֈڍs
*/
void CGirlState::toGraspRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::GRASP_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
* @desc	���������͂ޏ�Ԃֈڍs
*/
void CGirlState::toGraspLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::GRASP_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc	�E�������݂͂Ȃ���ҋ@��Ԃֈڍs
*/
void CGirlState::toGraspIdleRight(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_IDLE_RIGHT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_RIGHT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = (int)GIRL_ACTION_STATE::GRAPS_HAND;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc	���������݂͂Ȃ���ҋ@��Ԃֈڍs
*/
void CGirlState::toGraspIdleLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_IDLE_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = (int)GIRL_ACTION_STATE::GRAPS_HAND;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/*
*	@desc	�E�������݂͂Ȃ��������Ԃֈڍs
*/
void CGirlState::toGraspWalkRight(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_WALK_RIGHT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_RIGHT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = (int)GIRL_ACTION_STATE::GRAPS_HAND;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;

}

/*
*	@desc	���������݂͂Ȃ��������Ԃֈڍs
*/
void CGirlState::toGraspWalkLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_WALK_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = (int)GIRL_ACTION_STATE::GRAPS_HAND;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;

}

/**
* @desc	�E�������P�l��������Ԃֈڍs
*/
void CGirlState::toHoldRight(void) {
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::HOLD_RIGHT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_RIGHT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = (int)GIRL_ACTION_STATE::HOLD_THE_PRINCESS;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	���������P�l��������Ԃֈڍs
*/
void CGirlState::toHoldLeft(void) {
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::HOLD_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = (int)GIRL_ACTION_STATE::HOLD_THE_PRINCESS;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

//==========================================
//
// Class: CGirlIdleRightState
//
// �K�[�� �E���� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlIdleRightState::CGirlIdleRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlIdleRightState::~CGirlIdleRightState(void) {}

/**
* @desc	�J�n����
*/
void CGirlIdleRightState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CGirlIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	

	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS)
	{
		if (pPlayer->m_pMove->m_pos.x <= this->m_pGirl->m_pMove->m_pos.x)
		{
			this->toGraspLeft();
		}
		else
		{
			this->toGraspRight();
		}
	}
	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS) {
		this->toHoldRight();
		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CGirlIdleLeftState
//
// �K�[�� �������@�ҋ@ ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlIdleLeftState::CGirlIdleLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlIdleLeftState::~CGirlIdleLeftState(void) {}

/**
* @desc	�J�n����
*/
void CGirlIdleLeftState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CGirlIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS)
	{
		if (pPlayer->m_pMove->m_pos.x <= this->m_pGirl->m_pMove->m_pos.x)
		{
			this->toGraspLeft();
		}
		else
		{
			this->toGraspRight();
		}
	}
	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS) {
		this->toHoldLeft();
		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGrapsRightState
//
// �K�[�� �E�����@����q�� ��� �N���X
//
// 2016/12/26
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CGirlGraspRightState::CGirlGraspRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner)
{


}

/**
* @desc �f�X�g���N�^
*/
CGirlGraspRightState::~CGirlGraspRightState(void)
{


}

/**
* @desc �J�n����
*/
void CGirlGraspRightState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CGirlGraspRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�����A�j���[�V�������I�������
	if ((*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->isEnd())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toGraspIdleRight();
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CGirlGraspRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGrapsLeftState
//
// �K�[�� �������@����q�� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CGirlGraspLeftState::CGirlGraspLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner)
{


}

/**
* @desc �f�X�g���N�^
*/
CGirlGraspLeftState::~CGirlGraspLeftState(void)
{


}

/**
* @desc �J�n����
*/
void CGirlGraspLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CGirlGraspLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�����A�j���[�V�������I�������
	if ((*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->isEnd())
	{
		//�������ҋ@��Ԃֈڍs
		this->toGraspIdleLeft();
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CGirlGraspLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlGraspIdleRightState
//
// �K�[�� �E�����@����q�� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspIdleRightState::CGirlGraspIdleRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspIdleRightState::~CGirlGraspIdleRightState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspIdleRightState::start(void)
{
	this->m_pGirl->setVisible(false);
}

/**
* @desc	�X�V����
*/
void CGirlGraspIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	//�肪�����ꂽ��
	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE)
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleRight();
		return;
	}

	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS && pPlayer->m_state == (int)PLAYER_STATE::WALK && pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT)
	{
		this->toGraspWalkRight();
	}
	else if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS && pPlayer->m_state == (int)PLAYER_STATE::WALK && pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT)
	{
		this->toGraspWalkLeft();
	}

}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspIdleRightState::onChangeEvent(void)
{
	this->m_pGirl->setVisible(true);

	this->m_isNext = false;
}

//==========================================
//
// Class: CGirlGraspIdleLeftState
//
//�@�K�[�� �������@����q�� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspIdleLeftState::CGirlGraspIdleLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspIdleLeftState::~CGirlGraspIdleLeftState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspIdleLeftState::start(void)
{
	this->m_pGirl->setVisible(false);
}

/**
* @desc	�X�V����
*/
void CGirlGraspIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	//�肪�����ꂽ��
	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE)
	{
		//�������ҋ@��Ԃֈڍs
		this->toIdleLeft();
		return;
	}

	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS && pPlayer->m_state == (int)PLAYER_STATE::WALK &&pPlayer->m_playerDirectionState ==(int)PLATYER_DIRECTION_STATE::RIGHT)
	{
		this->toGraspWalkRight();
	}
	else if  (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS && pPlayer->m_state == (int)PLAYER_STATE::WALK && pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT)
	{
		this->toGraspWalkLeft();
	}

}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspIdleLeftState::onChangeEvent(void)
{
	this->m_pGirl->setVisible(true);

	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlGraspWalkRightState
//
// �K�[�� �E���� ����q���@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspWalkRightState::CGirlGraspWalkRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspWalkRightState::~CGirlGraspWalkRightState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspWalkRightState::start(void)
{
	this->m_pGirl->setVisible(false);
}


/**
* @desc	�X�V����
*/
void CGirlGraspWalkRightState::update(void)
{
	//�D�揇�ŏ������Ă���
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	//�肪�����ꂽ��
	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE)
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleRight();
		return;
	}

	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS && pPlayer->m_state == (int)PLAYER_STATE::IDLE && pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT)
	{
		this->toGraspIdleRight();
		return;
	}
}

/**
* @desk	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspWalkRightState::onChangeEvent(void)
{
	this->m_pGirl->setVisible(true);

	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGraspWalkLeftState
//
// �v���C���[ �般�� ������ ���s ��ԃN���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspWalkLeftState::CGirlGraspWalkLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspWalkLeftState::~CGirlGraspWalkLeftState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspWalkLeftState::start(void)
{
	this->m_pGirl->setVisible(false);
}

/**
* @desc	�X�V����
*/
void CGirlGraspWalkLeftState::update(void)
{
	//�D�揇�ŏ������Ă���
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	//�肪�����ꂽ��
	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE)
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleLeft();
		return;
	}

	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS && pPlayer->m_state == (int)PLAYER_STATE::IDLE && pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT)
	{
		this->toGraspIdleLeft();
		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspWalkLeftState::onChangeEvent(void)
{
	this->m_pGirl->setVisible(true);

	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlHoldIdleRightState
//
// �v���C���[ �E�����@���P�l�������ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlHoldIdleRightState::CGirlHoldIdleRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlHoldIdleRightState::~CGirlHoldIdleRightState(void) {}

/**
* @desc	�J�n����
*/
void CGirlHoldIdleRightState::start(void)
{
	this->m_pGirl->setVisible(false);
}

/**
* @desc	�X�V����
*/
void CGirlHoldIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();


	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE)
	{
		//�t���[�̉E�����̑ҋ@��Ԃֈڍs
		this->toIdleRight();
	}
	if (pPlayer->m_state == (int)PLAYER_STATE::WALK && pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
		//�������ֈڍs
		this->toHoldLeft();
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlHoldIdleRightState::onChangeEvent(void)
{
	this->m_pGirl->setVisible(true);
	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlHoldIdleLeftState
//
// �v���C���[ �������@����q���ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlHoldIdleLeftState::CGirlHoldIdleLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlHoldIdleLeftState::~CGirlHoldIdleLeftState(void) {}

/**
* @desc	�J�n����
*/
void CGirlHoldIdleLeftState::start(void)
{
	this->m_pGirl->setVisible(false);
}

/**
* @desc	�X�V����
*/
void CGirlHoldIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	if (pPlayer->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE)
	{
		//�������ҋ@��Ԃֈڍs
		this->toIdleLeft();
	}
	if (pPlayer->m_state == (int)PLAYER_STATE::WALK && pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
		//�������ֈڍs
		this->toHoldRight();
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlHoldIdleLeftState::onChangeEvent(void)
{
	this->m_pGirl->setVisible(true);

	this->m_isNext = false;
}

//EOF