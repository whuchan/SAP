#pragma once
//==========================================
//
// File: MouseKingState.h
//
// MouseKing�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/01/11
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
class CMouseCharacter;
//==========================================
//
// Class: CMouseKingIdleState
//
// MouseKing  ��� ���N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingState : public CEnemyState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseKingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseKingState(void);

	/**
	* @desc �ҋ@��Ԃֈڍs
	*/
	void toIdle(void);

	/**
	* @desc �p�j��Ԃֈڍs
	*/
	void toWandering(void);

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
// Class: CMouseKingIdleState
//
// MouseKing �ҋ@ ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingIdleState : public CMouseKingState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseKingIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseKingIdleState(void);

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
// Class: CMouseKingWanderingState
//
// MouseKing �p�j ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingWanderingState : public CMouseKingState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseKingWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseKingWanderingState(void);

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
// Class: CMouseKingAttackState
//
// MouseKing �U�� ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingAttackState : public CMouseKingState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseKingAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseKingAttackState(void);

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
	int m_nextAttackOrder = -1;
	CMouseCharacter* m_pOrderChara = NULL;

};

//==========================================
//
// Class: CMouseKingUnderAttackState
//
// MouseKing �U�����󂯂� ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingUnderAttackState : public CMouseKingState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseKingUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseKingUnderAttackState(void);

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
// Class: CMouseKingDeadState
//
// MouseKing ���S ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingDeadState : public CMouseKingState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseKingDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseKingDeadState(void);

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