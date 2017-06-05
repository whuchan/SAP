//==========================================
//
// File: CHenchmanTypeAState.cpp
//
// �q��A��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "HenchmanTypeAState.h"


//==========================================
//
// Class: CHenchmanTypeAState
//
// �G�l�~�[ ��� ���N���X
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================

/**
* @desc	�R���X�g���N�^
*/
CHenchmanTypeAState::CHenchmanTypeAState(CHenchmanTypeAEnemy* const pOwner) :CEnemyState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CHenchmanTypeAState::~CHenchmanTypeAState(void)
{

}
/////**
//// * @desc	�W�����v��Ԃֈڍs
//// */
////void CHenchmanTypeAState::toJump(void)
////{
////	this->m_pOwner->m_state			= (int)CEnemyCharacter::STATE::JUMP;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
//
/////**
//// * @desc	������Ԃֈڍs
//// */
////void CHenchmanTypeAState::toFall(void)
////{
////	this->m_pOwner->m_state			= (int)CEnemyCharacter::STATE::FALL;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
//
//
/////**
////* @desc	�ړ���Ԃֈڍs
////*/
////void CHenchmanTypeAState::toMove(void) {
////	this->m_pOwner->m_state = (int)CHenchmanTypeAEnemy::STATE::MOVE;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
////
/////**
////* @desc	���C���A�b�v��Ԃֈڍs
////*/
////void CHenchmanTypeAState::toLineUp(void) {
////	this->m_pOwner->m_state = (int)CHenchmanTypeAEnemy::STATE::LINE_UP;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
////
/////**
////* @desc	���C���_�E����Ԃֈڍs
////*/
////void CHenchmanTypeAState::toLineDown(void) {
////	this->m_pOwner->m_state = (int)CHenchmanTypeAEnemy::STATE::LINE_DOWN;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
////
////
/////**
//// * @desc	�U����Ԃֈڍs
//// */
////void CHenchmanTypeAState::toAttack(void) {
////	this->m_pOwner->m_state			= (int)CHenchmanTypeAEnemy::STATE::ATTACK;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
////
//
/////**
//// * @desc	�W�����v�U���ֈڍs
//// */
////void CHenchmanTypeAState::toJumpAttack(void) {
////	this->m_pOwner->m_state = (int)CEnemyCharacter::STATE::JUMP_ATTACK;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
//
//
/////**
//// * @desc	�U�����󂯂���Ԃֈڍs
//// */
////void CHenchmanTypeAState::toUnderAttack(void) {
////	this->m_pOwner->m_state = (int)CEnemyCharacter::STATE::UNDER_ATTACK;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////
////	this->m_isNext = true;
////}
////
////
/////*
//// * @desc	���͂ޏ�Ԃֈڍs
//// */
////void CHenchmanTypeAState::toGrasp(void)
////{
////	this->m_pOwner->m_state			= (int)CEnemyCharacter::STATE::GRASP;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
////
////
/////*
//// *	@desc	���P�l��������Ԃֈڍs
//// */
////void CHenchmanTypeAState::toHold(void)
////{
////	//���̑����I�ȃG�l�~�[�̏��
////	this->m_pOwner->m_state = (int)CEnemyCharacter::STATE::HOLD;
////
////	//���̑����I�ȃG�l�~�[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////
////	//�ҋ@������I��
////	this->m_isNext = true;
////}
//
//
//
//
//////==========================================
//////
////// Class: CEnemyJumpState
//////
////// �G�l�~�[ �W�����v ��ԃN���X
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
//// * @desc	�R���X�g���N�^
//// */
////CEnemyJumpState::CEnemyJumpState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	�f�X�g���N�^
////*/
////CEnemyJumpState::~CEnemyJumpState(void) {}
////
/////**
////* @desc	�J�n����
////*/
////void CEnemyJumpState::start(void)
////{
////	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::JUMP])[0]->start();
////
////	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
////}
////
/////**
////* @desc	�X�V����
////*/
////void CEnemyJumpState::update(void)
////{
////	//�D�揇�ŏ������Ă���
////	//���̓R���g���[���[�̎擾
////	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
////
////	//�G�l�~�[���U�����󂯂���
////	if (this->m_pOwner->m_underAttack) {
////		//�U�����󂯂���Ԃֈڍs
////		this->toUnderAttack();
////	}
////
////	if (pointerInputController->getAttackFlag()) {
////		//�E�W�����v�U����Ԃֈڍs����
////		//this->toJumpAttack();
////		return;
////	}
////
////	//�G�l�~�[�̑��x���ێ�������
////	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
////
////	//�E�ړ�
////	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
////		this->m_pOwner->m_pMove->m_vel.x += 1.0f;
////	}
////	//���ړ�
////	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
////		this->m_pOwner->m_pMove->m_vel.x += -1.0f;
////	}
////
////	//�G�l�~�[�����ֈړ����Ă�����
////	if (this->m_pOwner->m_pMove->m_vel.y <= 0.0f) {
////		//������Ԃֈڍs����
////		this->toFall();
////
////		return;
////	}
////
////	//�������W�����v
////	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
////		//�J�n�������ċN������
////		this->start();
////		return;
////	}
////}
////
/////**
////* @desc	��Ԃ��ς��Ƃ��̏���
////*/
////void CEnemyJumpState::onChangeEvent(void)
////{
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::JUMP])[0]->restart(this->m_pOwner);
////
////
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyFallState
//////
////// �G�l�~�[ ���� ��ԃN���X
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
////* @desc	�R���X�g���N�^
////*/
////CEnemyFallState::CEnemyFallState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	�f�X�g���N�^
////*/
////CEnemyFallState::~CEnemyFallState(void) {}
////
/////**
////* @desc	�J�n����
////*/
////void CEnemyFallState::start(void)
////{
////	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
////}
////
/////**
////* @desc	�X�V����
////*/
////void CEnemyFallState::update(void)
////{
////	//�D�揇�ŏ������Ă���
////
////	//���̓R���g���[���[�̎擾
////	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
////
////	//�G�l�~�[���U�����󂯂���
////	if (this->m_pOwner->m_underAttack) {
////		//�U�����󂯂���Ԃֈڍs
////		this->toUnderAttack();
////	}
////
////	if (pointerInputController->getAttackFlag()) {
////		//�E�W�����v�U����Ԃֈڍs����
////		//this->toJumpAttack();
////		return;
////	}
////
////	//�G�l�~�[�̑��x���ێ�������
////	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
////
////	//�E�ړ�
////	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
////		this->m_pOwner->m_pMove->m_accele.x = 2.0f;
////	}
////	//���ړ�
////	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
////		this->m_pOwner->m_pMove->m_accele.x = -2.0f;
////	}
////
////	//�G�l�~�[�����ֈړ����Ă�����
////	if (this->m_pOwner->m_pMove->m_vel.y == 0.0f) {
////		//������Ԃֈڍs����
////		this->toIdle();
////
////		return;
////	}
////
////}
////
/////**
////* @desc	��Ԃ��ς��Ƃ��̏���
////*/
////void CEnemyFallState::onChangeEvent(void)
////{
////	this->m_pOwner->m_pMove->m_accele.x = 0.0f;
////
////	this->m_pOwner->m_pMove->m_vel.x = 0.0f;
////
////
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyAttackState
//////
////// �G�l�~�[ �U�� ��ԃN���X
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
//// * @desc	�R���X�g���N�^
//// */
////CEnemyAttackState::CEnemyAttackState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl){}
////
/////**
//// * @desc	�f�X�g���N�^
//// */
////CEnemyAttackState::~CEnemyAttackState(void){}
////
/////**
//// * @desc	�J�n����
//// */
////void CEnemyAttackState::start(void)
////{
////
////	//���݂̃A�j���[�V���������Z�b�g
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////
////	//�U���A�N�V�������X�^�[�g������
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::ATTACK])[0]->start();
////
////	//�A���t���O��false�Ŏn�߂�
////	this->m_pOwner->m_chainAttackFlag = false;
////}
////
/////**
//// * @desc	�X�V����
//// */
////void CEnemyAttackState::update(void)
////{
////	//�D�揇�ŏ������Ă���
////	//���̓R���g���[���[�̎擾
////	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
////
////	//�U���{�^���������ꂽ��
////	if (pointerInputController->getAttackFlag())
////	{
////		//�U���A���t���O��true �ɂ���
////		this->m_pOwner->m_chainAttackFlag = true;
////	}
////
////	//�A�j���[�V�������I���������ǂ����̃t���O
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//�ҋ@��Ԃֈڍs
////		this->toIdle();
////	}
////}
////
/////**
//// * @desc	��Ԃ��ς��Ƃ��̏���
//// */
////void CEnemyAttackState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
////	this->m_isNext = false;
////}
////
//////==========================================
//////
////// Class: CEnemyJumpAttackState
//////
////// �G�l�~�[ �W�����v�U�� ��ԃN���X
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
//// * @desc	�R���X�g���N�^
//// */
////CEnemyJumpAttackState::CEnemyJumpAttackState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
//// * @desc	�f�X�g���N�^
//// */
////CEnemyJumpAttackState::~CEnemyJumpAttackState(){}
////
/////**
//// * @desc	�J�n����
//// */
////void CEnemyJumpAttackState::start(void)
////{
////	//���݂̃A�j���[�V���������Z�b�g
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////	
////	//�G�l�~�[�̃W�����v�A�N�V�������~������B
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::JUMP])[0]->stop();
////
////	//�G�l�~�[�̂����ړ����x���O�ɖ߂�
////	this->m_pOwner->m_pMove->m_vel.y = 0.0f;
////
////
////	//�_���[�W�L�����N�^�[�����f�[�^���쐬
////	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
////		cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
////		1);
////	//�_���[�W�L�����N�^�[�����g���K�[���쐬
////	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);
////
////	//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
////	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
////
////
////}
////
/////**
//// * @desc	�X�V����
//// */
////void CEnemyJumpAttackState::update(void)
////{
////	//�A�j���[�V�������I���������ǂ����̃t���O
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd() && this->m_pOwner->m_pMove->m_vel.y == 0.0f)
////	{
////		//�E�����ҋ@��Ԃ֖߂�
////		this->toIdle();
////		return;
////	}
////}
////
/////**
//// * @desc	��Ԃ��ς��Ƃ��̏���
//// */
////void CEnemyJumpAttackState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyUnderAttackState
//////
////// �G�l�~�[ �U�����󂯂� ��ԃN���X
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
////* @desc	�R���X�g���N�^
////*/
////CEnemyUnderAttackState::CEnemyUnderAttackState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	�f�X�g���N�^
////*/
////CEnemyUnderAttackState::~CEnemyUnderAttackState() {}
////
/////**
////* @desc	�J�n����
////*/
////void CEnemyUnderAttackState::start(void)
////{
////	//���݂̃A�j���[�V���������Z�b�g
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////
////	//���݂̃A�N�V�������X�^�[�g������B
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::UNDER_ATTACK])[0]->start();
////}
////
/////**
////* @desc	�X�V����
////*/
////void CEnemyUnderAttackState::update(void)
////{
////	//�A�j���[�V�������I���������ǂ����̃t���O
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//�ҋ@��Ԃ֖߂�
////		this->toIdle();
////
////		this->m_pOwner->m_underAttack = false;
////
////		return;
////	}
////}
////
/////**
////* @desc	��Ԃ��ς��Ƃ��̏���
////*/
////void CEnemyUnderAttackState::onChangeEvent(void)
////{
////	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyGraspState
//////
////// �G�l�~�[ ����q�� ��ԃN���X
//////
////// 2016/12/26
//////						Author Harada 
//////==========================================
/////**
//// * @desc	�R���X�g���N�^
//// */
////CEnemyGraspState::CEnemyGraspState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl){}
////
/////**
//// * @desc	�f�X�g���N�^
//// */
////CEnemyGraspState::~CEnemyGraspState(void){}
////
/////**
//// * @desc	�J�n����
//// */
////void CEnemyGraspState::start(void)
////{
////	//���݂̃A�j���[�V���������Z�b�g
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////}
////
/////**
//// * @desc	�X�V����
//// */
////void CEnemyGraspState::update(void)
////{
////	//�D�揇�ŏ������Ă���
////
////	//����q���A�j���[�V�������I�������
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//�E�����ҋ@��Ԃֈڍs
////		this->m_pOwner->m_EnemyAndGirlState = (int)Enemy_AND_GIRL_STATE::GRAPS_HANDS;
////
////		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_EnemyAndGirlState]->setStartState((int)CEnemyCharacter::STATE::IDLE);
////	}
////}
////
/////**
//// * @desc	��Ԃ��ς��Ƃ��̏���
//// */
////void CEnemyGraspState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyHoldState
//////
////// �G�l�~�[ ���P�l������ ��ԃN���X
//////
////// 2017/ 1/ 5
//////						Author Harada
//////==========================================
/////**
////* @desc	�R���X�g���N�^
////*/
////CEnemyHoldState::CEnemyHoldState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	�f�X�g���N�^
////*/
////CEnemyHoldState::~CEnemyHoldState(void) {}
////
/////**
////* @desc	�J�n����
////*/
////void CEnemyHoldState::start(void)
////{
////	//���݂̃A�j���[�V���������Z�b�g
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////}
////
/////**
////* @desc	�X�V����
////*/
////void CEnemyHoldState::update(void)
////{
////	//�D�揇�ŏ������Ă���
////
////	//����q���A�j���[�V�������I�������
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//�������ҋ@��Ԃֈڍs
////		this->m_pOwner->m_EnemyAndGirlState = (int)Enemy_AND_GIRL_STATE::HOLD_THE_PRINCESS;
////
////		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_EnemyAndGirlState]->setStartState((int)CEnemyCharacter::STATE::IDLE);
////	}
////}
////
/////**
////* @desc	��Ԃ��ς��Ƃ��̏���
////*/
////void CEnemyHoldState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	this->m_isNext = false;
////}
////EOF