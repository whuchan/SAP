#pragma once
//==========================================
//
// File: BaronState.h
//
// Baron�@��ԑJ�� �w�b�_�[�t�@�C��
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
// Class: CBaronIdleState
//
// Baron  ��� ���N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronState : public CEnemyState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBaronState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBaronState(void);

	/**
	* @desc �ҋ@��Ԃֈڍs
	*/
	void toIdle(void);

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
// Class: CBaronIdleState
//
// Baron �ҋ@ ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronIdleState : public CBaronState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBaronIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBaronIdleState(void);

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
// Class: CBaronAttackState
//
// Baron �U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronAttackState : public CBaronState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBaronAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBaronAttackState(void);

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
// Class: CBaronUnderAttackState
//
// Baron �U�����󂯂� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronUnderAttackState : public CBaronState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBaronUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBaronUnderAttackState(void);

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
// Class: CBaronDeadState
//
// Baron ���S ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronDeadState : public CBaronState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBaronDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBaronDeadState(void);

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