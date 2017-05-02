#pragma once
//==========================================
//
// File: MaideadState.h
//
// Maidead�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../EnemyState.h"


//==========================================
//
// Class: CMaideadIdleState
//
// Maidead  ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadState : public CEnemyState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadState(	CEnemyCharacter* const pOwner,
					CPlayerCharacterBoy* const pPlayer,
					CGirlCharacter* const pGirl
		);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadState(void);

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
// Class: CMaideadIdleState
//
// Maidead �ҋ@ ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadIdleState : public CMaideadState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadIdleState(	CEnemyCharacter* const pOwner,
						CPlayerCharacterBoy* const pPlayer,
						CGirlCharacter* const pGirl
		);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadIdleState(void);

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
// Class: CMaideadWanderingState
//
// Maidead �p�j ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadWanderingState : public CMaideadState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadWanderingState(	CEnemyCharacter* const pOwner,
							CPlayerCharacterBoy* const pPlayer,
							CGirlCharacter* const pGirl
	
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadWanderingState(void);

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
// Class: CMaideadChaseState
//
// Maidead �ǐ� ��� �N���X
//
//						Author Osumi
// 2016/12/27
//==========================================
class CMaideadChaseState : public CMaideadState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadChaseState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadChaseState(void);

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

};

//==========================================
//
// Class: CMaideadUnderAttackState
//
// Maidead �U�����󂯂� ��� �N���X
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
class CMaideadUnderAttackState : public CMaideadState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadUnderAttackState(void);

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
// Class: CMaideadDeadState
//
// Maidead ���S ��� �N���X
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
class CMaideadDeadState : public CMaideadState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadDeadState(void);

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