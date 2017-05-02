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
#include "PlayerState.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CPlayerState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerState::CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer),m_pGirl(pGirl){}

/**
 * @desc	�f�X�g���N�^ 
 */
CPlayerState::~CPlayerState(void){}

/**
 * @desc	�ҋ@��Ԃֈڍs
 */
void CPlayerState::toIdle(void)
{

	//�v���C���[�̏��
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::IDLE;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	���s��Ԃֈڍs
 */
void CPlayerState::toWalk(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::WALK;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�W�����v��Ԃֈڍs
 */
void CPlayerState::toJump(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::JUMP;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	������Ԃֈڍs
 */
void CPlayerState::toFall(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::FALL;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
 * @desc	�U����Ԃֈڍs
 */
void CPlayerState::toAttack(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
 * @desc	�W�����v�U���ֈڍs
 */
void CPlayerState::toJumpAttack(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_ATTACK;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
 * @desc	�U�����󂯂���Ԃֈڍs
 */
void CPlayerState::toUnderAttack(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UNDER_ATTACK;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;

	this->m_isNext = true;
}


/*
 * @desc	���͂ޏ�Ԃֈڍs
 */
void CPlayerState::toGrasp(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::GRASP;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/*
 *	@desc	���P�l��������Ԃֈڍs
 */
void CPlayerState::toHold(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pPlayer->m_state = (int)PLAYER_STATE::HOLD;

	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pPlayer->m_state;

	//�ҋ@������I��
	this->m_isNext = true;
}

//==========================================
//
// Class: CPlayerIdleState
//
// �v���C���[ �ҋ@ ��ԃN���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerIdleState::CPlayerIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer,pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerIdleState::~CPlayerIdleState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerIdleState::start(void)
{
	
}

/**
 * @desc	�X�V����
 */
void CPlayerIdleState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
	
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�v���C���[���U�����󂯂���
	if (this->m_pPlayer->m_underAttack) {
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
	}
	
	//�����Ƀ}�[�N�p�[�e�B�N�����o�����Ă��邩�m�F
	if (pGirl->getPlayerAndGirlActionMark()) {
		//�o�����Ă�����
		//�������@���P�l�������@�̃L�[��������Ă��邩�`�F�b�N
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//����q���E��Ԃֈڍs
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
			}
			else
			{
				//����q������Ԃֈڍs
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
			}
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHold();

		}

	}


	//����𑕔�
	if (pointerInputController->getEquipFlag())
	{
		//�E����������Ԃֈڍs
	//	this->toEquipRight();
	//	return;
	}

	//�E�U��
	if (pointerInputController->getAttackFlag()) {
		//�E�U����Ԃֈڍs(�P����)
		this->toAttack();
		return;
	}

	//�E�����W�����v
	if (pointerInputController->getJumpFlag()) {
		//�E�����W�����v��Ԃֈڍs
		this->toJump();
		return;
	}

	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toWalk();
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
		return;
	}


	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���������s��Ԃֈڍs
		this->toWalk();
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerIdleState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerWalkState
//
// �v���C���[ ���s ��ԃN���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerWalkState::CPlayerWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerWalkState::~CPlayerWalkState(void){}

/**
 * @desc	 �J�n����
 */
void CPlayerWalkState::start(void)
{

}

/**
 * @desc	�X�V����
 */
void CPlayerWalkState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�v���C���[���U�����󂯂���
	if (this->m_pPlayer->m_underAttack) {
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
	}

	//�����Ƀ}�[�N�p�[�e�B�N�����o�����Ă��邩�m�F
	if (pGirl->getPlayerAndGirlActionMark()) {
		//�o�����Ă�����
		//�������@���P�l�������@�̃L�[��������Ă��邩�`�F�b�N
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//����q���E��Ԃֈڍs
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
			}
			else
			{
				//����q������Ԃֈڍs
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
			}
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHold();

		}

	}

	//�v���C���[�����ֈړ����Ă�����
	if (this->m_pPlayer->m_pMove->m_vel.y < 0.0f) {
		//������Ԃֈڍs����
		this->toFall();

		return;
	}


	//����𑕔�
	if (pointerInputController->getEquipFlag())
	{
		//�E����������Ԃֈڍs
	//	this->toEquipRight();
	//	return;
	}
	
	//�U��
	if (pointerInputController->getAttackFlag()) {
		//�U����Ԃֈڍs
		this->toAttack();
		return;
	}

	//�W�����v
	if (pointerInputController->getJumpFlag()) {
		//�W�����v��Ԃֈڍs
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

	//�ҋ@��Ԃֈڍs
	this->toIdle();
}

/**
 * @desk	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerWalkState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::WALK])[0]->stop();

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerJumpState
//
// �v���C���[ �W�����v ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerJumpState::CPlayerJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerJumpState::~CPlayerJumpState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerJumpState::start(void)
{
	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->start();

	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	�X�V����
*/
void CPlayerJumpState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���U�����󂯂���
	if (this->m_pPlayer->m_underAttack) {
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
	}

	if (pointerInputController->getAttackFlag()) {
		//�E�W�����v�U����Ԃֈڍs����
		//this->toJumpAttack();
		return;
	}

	//�v���C���[�̑��x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�E�ړ�
	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
		this->m_pPlayer->m_pMove->m_vel.x += 1.0f;
	}
	//���ړ�
	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
		this->m_pPlayer->m_pMove->m_vel.x += -1.0f;
	}

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
void CPlayerJumpState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerFallState
//
// �v���C���[ ���� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerFallState::CPlayerFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerFallState::~CPlayerFallState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerFallState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	�X�V����
*/
void CPlayerFallState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���U�����󂯂���
	if (this->m_pPlayer->m_underAttack) {
		//�U�����󂯂���Ԃֈڍs
		this->toUnderAttack();
	}

	if (pointerInputController->getAttackFlag()) {
		//�E�W�����v�U����Ԃֈڍs����
		//this->toJumpAttack();
		return;
	}

	//�v���C���[�̑��x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�E�ړ�
	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
		this->m_pPlayer->m_pMove->m_accele.x = 2.0f;
	}
	//���ړ�
	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
		this->m_pPlayer->m_pMove->m_accele.x = -2.0f;
	}

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
void CPlayerFallState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;


	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerAttackState
//
// �v���C���[ �U�� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerAttackState::CPlayerAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerAttackState::~CPlayerAttackState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerAttackState::start(void)
{

	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();

	//�U���A�N�V�������X�^�[�g������
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();

	//�A���t���O��false�Ŏn�߂�
	this->m_pPlayer->m_chainAttackFlag = false;
}

/**
 * @desc	�X�V����
 */
void CPlayerAttackState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�U���{�^���������ꂽ��
	if (pointerInputController->getAttackFlag())
	{
		//�U���A���t���O��true �ɂ���
		this->m_pPlayer->m_chainAttackFlag = true;
	}

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//�ҋ@��Ԃֈڍs
		this->toIdle();
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerAttackState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerJumpAttackState
//
// �v���C���[ �W�����v�U�� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerJumpAttackState::CPlayerJumpAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerJumpAttackState::~CPlayerJumpAttackState(){}

/**
 * @desc	�J�n����
 */
void CPlayerJumpAttackState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
	
	//�v���C���[�̃W�����v�A�N�V�������~������B
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->stop();

	//�v���C���[�̂����ړ����x���O�ɖ߂�
	this->m_pPlayer->m_pMove->m_vel.y = 0.0f;


	//�_���[�W�L�����N�^�[�����f�[�^���쐬
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
		cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_right, this->m_pPlayer->m_pMove->m_pos.y),
		1);
	//�_���[�W�L�����N�^�[�����g���K�[���쐬
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);


}

/**
 * @desc	�X�V����
 */
void CPlayerJumpAttackState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd() && this->m_pPlayer->m_pMove->m_vel.y == 0.0f)
	{
		//�E�����ҋ@��Ԃ֖߂�
		this->toIdle();
		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerJumpAttackState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerUnderAttackState
//
// �v���C���[ �U�����󂯂� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerUnderAttackState::CPlayerUnderAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerUnderAttackState::~CPlayerUnderAttackState() {}

/**
* @desc	�J�n����
*/
void CPlayerUnderAttackState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();

	//���݂̃A�N�V�������X�^�[�g������B
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::UNDER_ATTACK])[0]->start();
}

/**
* @desc	�X�V����
*/
void CPlayerUnderAttackState::update(void)
{
	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//�ҋ@��Ԃ֖߂�
		this->toIdle();

		this->m_pPlayer->m_underAttack = false;

		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerUnderAttackState::onChangeEvent(void)
{
	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspState
//
// �v���C���[ ����q�� ��ԃN���X
//
// 2016/12/26
//						Author Harada 
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerGraspState::CPlayerGraspState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerGraspState::~CPlayerGraspState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerGraspState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
 * @desc	�X�V����
 */
void CPlayerGraspState::update(void)
{
	//�D�揇�ŏ������Ă���

	//����q���A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE);
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerGraspState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldState
//
// �v���C���[ ���P�l������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerHoldState::CPlayerHoldState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerHoldState::~CPlayerHoldState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerHoldState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
* @desc	�X�V����
*/
void CPlayerHoldState::update(void)
{
	//�D�揇�ŏ������Ă���

	//����q���A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//�������ҋ@��Ԃֈڍs
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE);
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerHoldState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	this->m_isNext = false;
}
//EOF