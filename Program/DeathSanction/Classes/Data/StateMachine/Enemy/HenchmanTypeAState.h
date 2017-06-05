#pragma once
//==========================================
//
// File: HenchmanTypeAState.h
//
// �G�l�~�[��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "EnemyState.h"
#include "Classes\Model\Character\HenchmanTypeAEnemy.h"


//==========================================
//
// Class: CHenchmanTypeAEnemy
//
// �q��A ��� ���N���X
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================
class CHenchmanTypeAState : public CEnemyState<CHenchmanTypeAEnemy>
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CHenchmanTypeAState(CHenchmanTypeAEnemy* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CHenchmanTypeAState(void);

	
};
//EOF