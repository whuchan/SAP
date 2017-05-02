//==========================================
//
// File: EnemyState.cpp
//
// �G ��ԑJ�� �t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "EnemyState.h"


//==========================================
//
// Class: CEnemyState
//
// �G  ��� ���N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================



/**
* @desc �R���X�g���N�^
* @param �R�m�̃A�h���X
* @param �����̃A�h���X
* @param �^�[�Q�b�g�̎�� 
*
*/
CEnemyState::CEnemyState(	CEnemyCharacter* const pOwner,
							CPlayerCharacterBoy* const pPlayer,
							CGirlCharacter* const pGirl
	)
	:m_pOwner(pOwner),m_pPlayer(pPlayer),m_pGirl(pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CEnemyState::~CEnemyState()
{

}

//EOF