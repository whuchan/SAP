#pragma once
//==========================================
//
// File: NutCrackerState.h
//
// NutCracker�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../EnemyState.h"

//==========================================
// �O���錾
//==========================================
class CCharacter;

//==========================================
//
// Class: CNutCrackerIdleState
//
// NutCracker  ��� ���N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerState : public CEnemyState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNutCrackerState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNutCrackerState(void);

	/**
	* @desc �ҋ@��Ԃֈڍs
	*/
	void toIdle(void);

	/**
	* @desc �p�j��Ԃֈڍs
	*/
	void toWandering(void);

	/**
	* @desc �ǐՏ�Ԃֈڍs
	*/
	void toChase(void);

	/**
	* @desc �U����Ԃֈڍs
	*/
	void toAttack(void);

	/**
	* @desc �U�����󂯂Ă����Ԃֈڍs
	*/
	void toUnderAttack(void);


	/**
	* @desc ���S��Ԃֈڍs
	*/
	void toDead(void);


	/**
	* @desc �U���ł���擾
	* @return true...�ł��� false...�o���Ȃ�
	*/
	bool checkEnableAttack(void);

};

//==========================================
//
// Class: CNutCrackerIdleState
//
// NutCracker �ҋ@ ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerIdleState : public CNutCrackerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNutCrackerIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNutCrackerIdleState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:
	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;
};

//==========================================
//
// Class: CNutCrackerWanderingState
//
// NutCracker �p�j ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerWanderingState : public CNutCrackerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNutCrackerWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNutCrackerWanderingState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:

	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//���낤�낷�����
	int m_vec = 1;
};


//==========================================
//
// Class: CNutCrackerChaseState
//
// NutCracker �ǐ� ��� �N���X
//
//						Author Shinya Ueba
// 2017/01/09
//==========================================
class CNutCrackerChaseState : public CNutCrackerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNutCrackerChaseState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNutCrackerChaseState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:
	CCharacter* m_pTarget = NULL;
	int m_vec = 0;
};

//==========================================
//
// Class: CNutCrackerAttackState
//
// NutCracker �U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerAttackState : public CNutCrackerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNutCrackerAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNutCrackerAttackState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:
};

//==========================================
//
// Class: CNutCrackerUnderAttackState
//
// NutCracker �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerUnderAttackState : public CNutCrackerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNutCrackerUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNutCrackerUnderAttackState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:
	//������ԕ���
	int m_vec = 1;
};


//==========================================
//
// Class: CNutCrackerDeadState
//
// NutCracker ���S ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerDeadState : public CNutCrackerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNutCrackerDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNutCrackerDeadState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:
	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//���ł���܂ł̃J�E���^�[
	int m_disappearanceCounter = 0;
};
//EOF