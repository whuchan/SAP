#pragma once
//==========================================
//
// File: CHenchmanTypeAStateIdle.h
//
// �q��A�ҋ@��� �w�b�_�[�t�@�C��
//
// 2017/06/05
//						Author Shinya Ueba
//==========================================
#include"HenchmanTypeAState.h"

class CHenchmanTypeAStateIdle :public CHenchmanTypeAState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CHenchmanTypeAStateIdle(CHenchmanTypeAEnemy* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	virtual ~CHenchmanTypeAStateIdle(void);
	
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
};
//EOF