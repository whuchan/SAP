#pragma once
//==========================================
//
// File: DamageState.h
//
// �_���[�W�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../StateMachine.h"

//==========================================
// �O���錾
//==========================================
class CDamageCharacter;

//==========================================
//
// Class: CDamageState
//
// �_���[�W ��� ���N���X
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CDamageState : public CStateBase
{
public:

	/**
	* @desc �R���X�g���N�^
	* @param ���L����L�����N�^�[
	*/
	CDamageState(CDamageCharacter* const pOwner);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CDamageState(void);

protected:
	//���̏�Ԃ�ۗL����L�����N�^�[
	CDamageCharacter* m_pOwner = NULL;
};
//EOF