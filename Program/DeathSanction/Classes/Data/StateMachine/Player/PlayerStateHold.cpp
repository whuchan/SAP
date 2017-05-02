#include "PlayerStateHold.h"
#include "Data/Enum/EnumPlayer.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Lib/Input/InputManager.h"

/**
 * @desc	�R���X�g���N�^
 */
CPlayerStateHold::CPlayerStateHold(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer), m_pGirl(pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerStateHold::~CPlayerStateHold(void) {}

/**
 * @desc	�ҋ@��Ԃֈڍs
 */
void CPlayerStateHold::toIdle(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	���s��Ԃֈڍs
 */
void CPlayerStateHold::toWalk(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�W�����v��Ԃֈڍs
 */
void CPlayerStateHold::toJump(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
 * @desc	������Ԃֈڍs
 */
void CPlayerStateHold::toFall(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::FALL;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	���P�l��������Ԃ���ʏ��Ԃֈڍs�i�E�����j
 */
void CPlayerStateHold::toFreeIdle(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::HOLD;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

//==========================================
//
// Class: CPlayerHoldIdleState
//
// �v���C���[ ���P�l������ �ҋ@ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldIdleState::CPlayerHoldIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldIdleState::~CPlayerHoldIdleState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldIdleState::start(void)
{

}

/**
 * @desc	�X�V����
 */
void CPlayerHoldIdleState::update(void)
{
	//�D�揇�ŏ������Ă���


	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�肪�����ꂽ��
	if (!pointerInputController->getHugFlag())
	{
		this->toFreeIdle();

		return;
	}

	//�W�����v
	if (pointerInputController->getJumpFlag())
	{
		//�E�����W�����v��Ԃֈڍs
		this->toJump();
		return;
	}

	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//���s��Ԃֈڍs
		this->toWalk();

		//�E�����֕ύX
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;

		return;
	}


	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���s��Ԃֈڍs
		this->toWalk();
		
		//�������֕ύX
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;

		return;
	}

	
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldIdleState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldWalkState
//
// �v���C���[ ���P�l������ ���s ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldWalkState::CPlayerHoldWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldWalkState::~CPlayerHoldWalkState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldWalkState::start(void)
{

}

/**
 * @desc	�X�V����
 */
void CPlayerHoldWalkState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�肪�����ꂽ��
	if (!pointerInputController->getHugFlag())
	{
		this->toFreeIdle();

		return;
	}

	//�W�����v
	if (pointerInputController->getJumpFlag())
	{
		//�E�����W�����v��Ԃֈڍs
		this->toJump();
		return;
	}


	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�����ɕ��s����
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
		return;
	}

	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���������s��Ԃֈڍs
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
		return;
	}

	

	//�E�����ҋ@��Ԃֈڍs
	this->toIdle();
}

/**
 * @desk	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldWalkState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::WALK])[0]->stop();

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldJumpState
//
// �v���C���[ ���P�l������ �W�����v ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldJumpState::CPlayerHoldJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldJumpState::~CPlayerHoldJumpState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldJumpState::start(void)
{
	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->start();

	//�v���C���[��X���x���L�^����B
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	�X�V����
 */
void CPlayerHoldJumpState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�v���C���[��X���x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�v���C���[�����ֈړ����Ă�����
	if (this->m_pPlayer->m_pMove->m_vel.y <= 0.0f) {
		//������Ԃֈڍs����
		this->toFall();

		return;
	}

	//�������W�����v
	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
		//�J�n�������ċN������
		this->start();
		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldJumpState::onChangeEvent(void)
{
	//�W�����v�I�����Ƀv���C���[�̃W�����v�A�N�V���������Z�b�g����
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldFallState
//
// �v���C���[ ���P�l������ ���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldFallState::CPlayerHoldFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldFallState::~CPlayerHoldFallState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldFallState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	�X�V����
 */
void CPlayerHoldFallState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[�̑��x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�v���C���[�����ֈړ����Ă�����
	if (this->m_pPlayer->m_pMove->m_vel.y == 0.0f) {
		//������Ԃֈڍs����
		this->toIdle();

		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldFallState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;

	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldReleaseState
//
// �v���C���[ ���P�l������ ���낷 ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerHoldReleaseState::CPlayerHoldReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerHoldReleaseState::~CPlayerHoldReleaseState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerHoldReleaseState::start(void)
{
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
* @desc	�X�V����
*/
void CPlayerHoldReleaseState::update(void)
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
void CPlayerHoldReleaseState::onChangeEvent(void)
{

	this->m_isNext = false;
}
