#pragma once
//==========================================
//
// File: MouseState.h
//
// Mouse�@��ԑJ�� �w�b�_�[�t�@�C��
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

//==========================================
//
// Class: CMouseIdleState
//
// Mouse  ��� ���N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseState : public CEnemyState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseState(void);

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

};

//==========================================
//
// Class: CMouseIdleState
//
// Mouse �ҋ@ ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseIdleState : public CMouseState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseIdleState(void);

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
// Class: CMouseWanderingState
//
// Mouse �p�j ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseWanderingState : public CMouseState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseWanderingState(void);

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
	//���낤�낷�����
	int m_vec = 1;
};



//==========================================
//
// Class: CMouseAttackState
//
// Mouse �U�� ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseAttackState : public CMouseState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseAttackState(void);

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
// Class: CMouseUnderAttackState
//
// Mouse �U�����󂯂� ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseUnderAttackState : public CMouseState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseUnderAttackState(void);

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
// Class: CMouseDeadState
//
// Mouse ���S ��� �N���X
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseDeadState : public CMouseState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMouseDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMouseDeadState(void);

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