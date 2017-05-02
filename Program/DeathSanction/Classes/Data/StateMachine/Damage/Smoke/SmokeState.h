#pragma once
//==========================================
//
// File: SmokeState.h
//
// Smoke�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../DamageState.h"

//==========================================
//
// Class: CSmokeState
//
// Smoke  ��� ���N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CSmokeState : public CDamageState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CSmokeState(CDamageCharacter* const pOwner);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CSmokeState(void);

	/**
	* @desc �U����Ԃֈڍs
	*/
	void toAttack(void);

	/**
	* @desc ���S��Ԃֈڍs
	*/
	void toDead(void);

};

//==========================================
//
// Class: CSmokeAttackState
//
// Smoke �U�� ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CSmokeAttackState : public CSmokeState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CSmokeAttackState(CDamageCharacter* const pOwner);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CSmokeAttackState(void);

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

	int m_vec = 0;
};

//==========================================
//
// Class: CSmokeDeadState
//
// Smoke ���S ��� �N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CSmokeDeadState : public CSmokeState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CSmokeDeadState(CDamageCharacter* const pOwner);
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CSmokeDeadState(void);

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

//EOF