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
#include "Classes\Model\Character\PlayerCharacter.h"



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
CPlayerState::CPlayerState(CPlayerCharacter* const pOwner):m_pOwner(pOwner)
{

}

/**
 * @desc	�f�X�g���N�^ 
 */
CPlayerState::~CPlayerState(void)
{

}

/**
 * @desc	�ҋ@��Ԃֈڍs
 */
void CPlayerState::toIdle(void)
{

	//�v���C���[�̏��
	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::IDLE;

	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	���s��Ԃֈڍs
 */
void CPlayerState::toWalk(void)
{
	this->m_pOwner->m_state				= (int)CPlayerCharacter::STATE::WALK;

	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
*	@desc	���C���A�b�v��Ԃֈڍs
*/
void CPlayerState::toLineUp(void)
{
	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::LINE_UP;

	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
*	@desc	���C���_�E����Ԃֈڍs
*/
void CPlayerState::toLineDown(void)
{
	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::LINE_DOWN;

	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�U����Ԃֈڍs
*/
void CPlayerState::toAttack1(void)
{
	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::ATTACK_1;

	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}




///**
// * @desc	�W�����v��Ԃֈڍs
// */
//void CPlayerState::toJump(void)
//{
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::JUMP;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//�ҋ@������I��
//	this->m_isNext = true;
//}
//
///**
// * @desc	������Ԃֈڍs
// */
//void CPlayerState::toFall(void)
//{
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::FALL;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//�ҋ@������I��
//	this->m_isNext = true;
//}
//
//
///**
// * @desc	�U����Ԃֈڍs
// */
//void CPlayerState::toAttack(void) {
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::ATTACK;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//�ҋ@������I��
//	this->m_isNext = true;
//}
//
//
///**
// * @desc	�W�����v�U���ֈڍs
// */
//void CPlayerState::toJumpAttack(void) {
//	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::JUMP_ATTACK;
//
//	this->m_nextRegisterKey = this->m_pOwner->m_state;
//	//�ҋ@������I��
//	this->m_isNext = true;
//}
//
//
///**
// * @desc	�U�����󂯂���Ԃֈڍs
// */
//void CPlayerState::toUnderAttack(void) {
//	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::UNDER_ATTACK;
//
//	this->m_nextRegisterKey = this->m_pOwner->m_state;
//
//	this->m_isNext = true;
//}
//
//
///*
// * @desc	���͂ޏ�Ԃֈڍs
// */
//void CPlayerState::toGrasp(void)
//{
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::GRASP;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//�ҋ@������I��
//	this->m_isNext = true;
//}
//
//
///*
// *	@desc	���P�l��������Ԃֈڍs
// */
//void CPlayerState::toHold(void)
//{
//	//���̑����I�ȃv���C���[�̏��
//	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::HOLD;
//
//	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
//	this->m_nextRegisterKey = this->m_pOwner->m_state;
//
//	//�ҋ@������I��
//	this->m_isNext = true;
//}




////==========================================
////
//// Class: CPlayerJumpState
////
//// �v���C���[ �W�����v ��ԃN���X
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
// * @desc	�R���X�g���N�^
// */
//CPlayerJumpState::CPlayerJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	�f�X�g���N�^
//*/
//CPlayerJumpState::~CPlayerJumpState(void) {}
//
///**
//* @desc	�J�n����
//*/
//void CPlayerJumpState::start(void)
//{
//	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::JUMP])[0]->start();
//
//	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
//}
//
///**
//* @desc	�X�V����
//*/
//void CPlayerJumpState::update(void)
//{
//	//�D�揇�ŏ������Ă���
//	//���̓R���g���[���[�̎擾
//	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
//
//	//�v���C���[���U�����󂯂���
//	if (this->m_pOwner->m_underAttack) {
//		//�U�����󂯂���Ԃֈڍs
//		this->toUnderAttack();
//	}
//
//	if (pointerInputController->getAttackFlag()) {
//		//�E�W�����v�U����Ԃֈڍs����
//		//this->toJumpAttack();
//		return;
//	}
//
//	//�v���C���[�̑��x���ێ�������
//	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
//
//	//�E�ړ�
//	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
//		this->m_pOwner->m_pMove->m_vel.x += 1.0f;
//	}
//	//���ړ�
//	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
//		this->m_pOwner->m_pMove->m_vel.x += -1.0f;
//	}
//
//	//�v���C���[�����ֈړ����Ă�����
//	if (this->m_pOwner->m_pMove->m_vel.y <= 0.0f) {
//		//������Ԃֈڍs����
//		this->toFall();
//
//		return;
//	}
//
//	//�������W�����v
//	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
//		//�J�n�������ċN������
//		this->start();
//		return;
//	}
//}
//
///**
//* @desc	��Ԃ��ς��Ƃ��̏���
//*/
//void CPlayerJumpState::onChangeEvent(void)
//{
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::JUMP])[0]->restart(this->m_pOwner);
//
//
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerFallState
////
//// �v���C���[ ���� ��ԃN���X
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
//* @desc	�R���X�g���N�^
//*/
//CPlayerFallState::CPlayerFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	�f�X�g���N�^
//*/
//CPlayerFallState::~CPlayerFallState(void) {}
//
///**
//* @desc	�J�n����
//*/
//void CPlayerFallState::start(void)
//{
//	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
//}
//
///**
//* @desc	�X�V����
//*/
//void CPlayerFallState::update(void)
//{
//	//�D�揇�ŏ������Ă���
//
//	//���̓R���g���[���[�̎擾
//	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
//
//	//�v���C���[���U�����󂯂���
//	if (this->m_pOwner->m_underAttack) {
//		//�U�����󂯂���Ԃֈڍs
//		this->toUnderAttack();
//	}
//
//	if (pointerInputController->getAttackFlag()) {
//		//�E�W�����v�U����Ԃֈڍs����
//		//this->toJumpAttack();
//		return;
//	}
//
//	//�v���C���[�̑��x���ێ�������
//	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
//
//	//�E�ړ�
//	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
//		this->m_pOwner->m_pMove->m_accele.x = 2.0f;
//	}
//	//���ړ�
//	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
//		this->m_pOwner->m_pMove->m_accele.x = -2.0f;
//	}
//
//	//�v���C���[�����ֈړ����Ă�����
//	if (this->m_pOwner->m_pMove->m_vel.y == 0.0f) {
//		//������Ԃֈڍs����
//		this->toIdle();
//
//		return;
//	}
//
//}
//
///**
//* @desc	��Ԃ��ς��Ƃ��̏���
//*/
//void CPlayerFallState::onChangeEvent(void)
//{
//	this->m_pOwner->m_pMove->m_accele.x = 0.0f;
//
//	this->m_pOwner->m_pMove->m_vel.x = 0.0f;
//
//
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerAttackState
////
//// �v���C���[ �U�� ��ԃN���X
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
// * @desc	�R���X�g���N�^
// */
//CPlayerAttackState::CPlayerAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl){}
//
///**
// * @desc	�f�X�g���N�^
// */
//CPlayerAttackState::~CPlayerAttackState(void){}
//
///**
// * @desc	�J�n����
// */
//void CPlayerAttackState::start(void)
//{
//
//	//���݂̃A�j���[�V���������Z�b�g
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//
//	//�U���A�N�V�������X�^�[�g������
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::ATTACK])[0]->start();
//
//	//�A���t���O��false�Ŏn�߂�
//	this->m_pOwner->m_chainAttackFlag = false;
//}
//
///**
// * @desc	�X�V����
// */
//void CPlayerAttackState::update(void)
//{
//	//�D�揇�ŏ������Ă���
//	//���̓R���g���[���[�̎擾
//	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
//
//	//�U���{�^���������ꂽ��
//	if (pointerInputController->getAttackFlag())
//	{
//		//�U���A���t���O��true �ɂ���
//		this->m_pOwner->m_chainAttackFlag = true;
//	}
//
//	//�A�j���[�V�������I���������ǂ����̃t���O
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//�ҋ@��Ԃֈڍs
//		this->toIdle();
//	}
//}
//
///**
// * @desc	��Ԃ��ς��Ƃ��̏���
// */
//void CPlayerAttackState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
//	this->m_isNext = false;
//}
//
////==========================================
////
//// Class: CPlayerJumpAttackState
////
//// �v���C���[ �W�����v�U�� ��ԃN���X
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
// * @desc	�R���X�g���N�^
// */
//CPlayerJumpAttackState::CPlayerJumpAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
// * @desc	�f�X�g���N�^
// */
//CPlayerJumpAttackState::~CPlayerJumpAttackState(){}
//
///**
// * @desc	�J�n����
// */
//void CPlayerJumpAttackState::start(void)
//{
//	//���݂̃A�j���[�V���������Z�b�g
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//	
//	//�v���C���[�̃W�����v�A�N�V�������~������B
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::JUMP])[0]->stop();
//
//	//�v���C���[�̂����ړ����x���O�ɖ߂�
//	this->m_pOwner->m_pMove->m_vel.y = 0.0f;
//
//
//	//�_���[�W�L�����N�^�[�����f�[�^���쐬
//	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
//		cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
//		1);
//	//�_���[�W�L�����N�^�[�����g���K�[���쐬
//	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);
//
//	//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
//	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
//
//
//}
//
///**
// * @desc	�X�V����
// */
//void CPlayerJumpAttackState::update(void)
//{
//	//�A�j���[�V�������I���������ǂ����̃t���O
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd() && this->m_pOwner->m_pMove->m_vel.y == 0.0f)
//	{
//		//�E�����ҋ@��Ԃ֖߂�
//		this->toIdle();
//		return;
//	}
//}
//
///**
// * @desc	��Ԃ��ς��Ƃ��̏���
// */
//void CPlayerJumpAttackState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerUnderAttackState
////
//// �v���C���[ �U�����󂯂� ��ԃN���X
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
//* @desc	�R���X�g���N�^
//*/
//CPlayerUnderAttackState::CPlayerUnderAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	�f�X�g���N�^
//*/
//CPlayerUnderAttackState::~CPlayerUnderAttackState() {}
//
///**
//* @desc	�J�n����
//*/
//void CPlayerUnderAttackState::start(void)
//{
//	//���݂̃A�j���[�V���������Z�b�g
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//
//	//���݂̃A�N�V�������X�^�[�g������B
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::UNDER_ATTACK])[0]->start();
//}
//
///**
//* @desc	�X�V����
//*/
//void CPlayerUnderAttackState::update(void)
//{
//	//�A�j���[�V�������I���������ǂ����̃t���O
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//�ҋ@��Ԃ֖߂�
//		this->toIdle();
//
//		this->m_pOwner->m_underAttack = false;
//
//		return;
//	}
//}
//
///**
//* @desc	��Ԃ��ς��Ƃ��̏���
//*/
//void CPlayerUnderAttackState::onChangeEvent(void)
//{
//	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerGraspState
////
//// �v���C���[ ����q�� ��ԃN���X
////
//// 2016/12/26
////						Author Harada 
////==========================================
///**
// * @desc	�R���X�g���N�^
// */
//CPlayerGraspState::CPlayerGraspState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl){}
//
///**
// * @desc	�f�X�g���N�^
// */
//CPlayerGraspState::~CPlayerGraspState(void){}
//
///**
// * @desc	�J�n����
// */
//void CPlayerGraspState::start(void)
//{
//	//���݂̃A�j���[�V���������Z�b�g
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//}
//
///**
// * @desc	�X�V����
// */
//void CPlayerGraspState::update(void)
//{
//	//�D�揇�ŏ������Ă���
//
//	//����q���A�j���[�V�������I�������
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//�E�����ҋ@��Ԃֈڍs
//		this->m_pOwner->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS;
//
//		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_playerAndGirlState]->setStartState((int)CPlayerCharacter::STATE::IDLE);
//	}
//}
//
///**
// * @desc	��Ԃ��ς��Ƃ��̏���
// */
//void CPlayerGraspState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerHoldState
////
//// �v���C���[ ���P�l������ ��ԃN���X
////
//// 2017/ 1/ 5
////						Author Harada
////==========================================
///**
//* @desc	�R���X�g���N�^
//*/
//CPlayerHoldState::CPlayerHoldState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	�f�X�g���N�^
//*/
//CPlayerHoldState::~CPlayerHoldState(void) {}
//
///**
//* @desc	�J�n����
//*/
//void CPlayerHoldState::start(void)
//{
//	//���݂̃A�j���[�V���������Z�b�g
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//}
//
///**
//* @desc	�X�V����
//*/
//void CPlayerHoldState::update(void)
//{
//	//�D�揇�ŏ������Ă���
//
//	//����q���A�j���[�V�������I�������
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//�������ҋ@��Ԃֈڍs
//		this->m_pOwner->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS;
//
//		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_playerAndGirlState]->setStartState((int)CPlayerCharacter::STATE::IDLE);
//	}
//}
//
///**
//* @desc	��Ԃ��ς��Ƃ��̏���
//*/
//void CPlayerHoldState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	this->m_isNext = false;
//}
//EOF