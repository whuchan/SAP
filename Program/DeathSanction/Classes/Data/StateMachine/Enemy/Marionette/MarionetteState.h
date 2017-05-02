#pragma once
//==========================================
//
// File: MarionetteState.h
//
// Marionette�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../EnemyState.h"
#include "cocos2d.h"

//==========================================
// �O���錾
//==========================================

//==========================================
//
// Class: CMarionetteIdleState
//
// Marionette  ��� ���N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteState : public CEnemyState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMarionetteState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMarionetteState(void);

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
// Class: CMarionetteIdleState
//
// Marionette �ҋ@ ��� �N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteIdleState : public CMarionetteState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMarionetteIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMarionetteIdleState(void);

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
// Class: CMarionetteWanderingState
//
// Marionette �p�j ��� �N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteWanderingState : public CMarionetteState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMarionetteWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMarionetteWanderingState(void);

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
	cocos2d::Vec2 m_targetPositions[3];

	//���낤�낷�����
	int m_vec = 1;
};



//==========================================
//
// Class: CMarionetteAttackState
//
// Marionette �U�� ��� �N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteAttackState : public CMarionetteState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMarionetteAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMarionetteAttackState(void);

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
// Class: CMarionetteUnderAttackState
//
// Marionette �U�����󂯂� ��� �N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteUnderAttackState : public CMarionetteState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMarionetteUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMarionetteUnderAttackState(void);

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
// Class: CMarionetteDeadState
//
// Marionette ���S ��� �N���X
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteDeadState : public CMarionetteState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMarionetteDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMarionetteDeadState(void);

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