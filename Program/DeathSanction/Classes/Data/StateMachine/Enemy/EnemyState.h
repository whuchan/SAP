#pragma once
//==========================================
//
// File: EnemyState.h
//
// �G�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../StateMachine.h"

//==========================================
// �O���錾
//==========================================
class CEnemyCharacter;
class CPlayerCharacterBoy;
class CGirlCharacter;

//==========================================
//
// Class: CEnemyState
//
// �G ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CEnemyState : public CStateBase
{
public:

	/**
	* @desc �R���X�g���N�^
	* @param �R�m�̃A�h���X
	* @param �����̃A�h���X
	* @param �^�[�Q�b�g�̎�� 
	*/
	CEnemyState(CEnemyCharacter* const pOwner,
				CPlayerCharacterBoy* const pPlayer,
				CGirlCharacter* const pGirl
		);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CEnemyState(void);
	
protected:
	//���̏�Ԃ�ۗL����L�����N�^�[
	CEnemyCharacter* m_pOwner = NULL;

	//�Q�Ƃ���v���C���[�L�����N�^�[r
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//�Q�Ƃ���K�[���L�����N�^�[
	CGirlCharacter*		m_pGirl = NULL;
};
//EOF