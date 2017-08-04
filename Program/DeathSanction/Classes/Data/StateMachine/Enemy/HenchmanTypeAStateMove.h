#pragma once
//==========================================
//
// File: CHenchmanTypeAStateMove.h
//
// �q��A�ړ���� �w�b�_�[�t�@�C��
//
// 2017/07/03
//						Author Shinya Ueba
//==========================================
#include"HenchmanTypeAState.h"

class CHenchmanTypeAStateMove :public CHenchmanTypeAState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CHenchmanTypeAStateMove(CHenchmanTypeAEnemy* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	virtual ~CHenchmanTypeAStateMove(void);

	/**
	* @desc	�J�n����
	*/
	void enter(void)override;

	/**
	* @desc	�X�V����
	*/
	void execute(float deltaTime)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void exit(void)override;

private:
	CCharacter* m_pTarget = NULL;
};
//EOF