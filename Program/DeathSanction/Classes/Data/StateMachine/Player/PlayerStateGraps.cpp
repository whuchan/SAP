//==========================================
//
// File: PlayerState.cpp
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "PlayerStateGraps.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"


//==========================================
//
// Class: CPlayerStateGraps
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerStateGraps::CPlayerStateGraps(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer), m_pGirl(pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerStateGraps::~CPlayerStateGraps(void) {}


/**
 * @desc	�ҋ@��Ԃֈڍs
 */
void CPlayerStateGraps::toIdle(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	���s��Ԃֈڍs
 */
void CPlayerStateGraps::toWalk(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�U����Ԃֈڍs
 */
void CPlayerStateGraps::toAttack(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
 * @desc	��𗣂���Ԃֈڍs
 */
void CPlayerStateGraps::toGrasp(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


//==========================================
//
// Class: CPlayerGraspIdleState
//
// �v���C���[ ����q�� �ҋ@ ��ԃN���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspIdleState::CPlayerGraspIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspIdleState::~CPlayerGraspIdleState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspIdleState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerGraspIdleState::update(void)
{
	//�D�揇�ŏ������Ă���


	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���擾
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		this->toGrasp();

		return;
	}

	//�E�����U����Ԃֈڍs
	if (pointerInputController->getAttackFlag()) {
		//�E�����U����Ԃֈڍs
		//this->toAttack();
		return;
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
		//�E�ֈړ��i���s�j
		if (pointerInputController->getRightMoveFlag())
		{
			//�E�������s��Ԃֈڍs
			this->toWalk();
			return;
		}
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
		//���ֈړ��i���s�j
		if (pointerInputController->getLeftMoveFlag())
		{
			//���s��Ԃֈڍs
			this->toWalk();
			return;
		}
	}

	
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspIdleState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspWalkState
//
// �v���C���[ ����q�� ���s ��ԃN���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspWalkState::CPlayerGraspWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspWalkState::~CPlayerGraspWalkState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspWalkState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerGraspWalkState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���擾
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		this->toGrasp();

		return;
	}

	//�E�����U����Ԃֈڍs
	if (pointerInputController->getAttackFlag()) {
		//�E�����U����Ԃֈڍs
		//this->toAttack();
		return;
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
		//�E�ֈړ��i���s�j
		if (pointerInputController->getRightMoveFlag())
		{
			//�E�������s��Ԃֈڍs
			this->toWalk();
			return;
		}
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
		//���ֈړ��i���s�j
		if (pointerInputController->getLeftMoveFlag())
		{
			//���s��Ԃֈڍs
			this->toWalk();
			return;
		}
	}

	//�ҋ@��Ԃֈڍs
	this->toIdle();
}

/**
* @desk	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspWalkState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::WALK])[0]->stop();

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspAttackState
//
// �v���C���[ ����q�� �U�� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspAttackState::CPlayerGraspAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspAttackState::~CPlayerGraspAttackState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspAttackState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();

	//�U���A�N�V�������X�^�[�g������
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();

}

/**
* @desc	�X�V����
*/
void CPlayerGraspAttackState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//�E�����ҋ@��Ԃ֖߂�
		this->toIdle();
		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspAttackState::onChangeEvent(void)
{
	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerGraspReleaseState
//
// �v���C���[ ����q�� ��𗣂� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspReleaseState::CPlayerGraspReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspReleaseState::~CPlayerGraspReleaseState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspReleaseState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
* @desc	�X�V����
*/
void CPlayerGraspReleaseState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE);

		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspReleaseState::onChangeEvent(void)
{
	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
	this->m_isNext = false;
}