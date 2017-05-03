#pragma once

#include "PlayerState.h"
#include "cocos2d.h"

//==========================================
//
// Class: CPlayerStateLineUp
//
// �v���C���[ ���C���_�E�� ��ԃN���X
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
class CPlayerStateLineDown :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerStateLineDown(CPlayerCharacter* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerStateLineDown(void);

	/**
	* @desc	�J�n����
	*/
	void enter(void)override;
	/**
	* @desc	�X�V����
	*/
	void execute(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void exit(void)override;

private:
	cocos2d::Action* m_pAction = NULL;
};
//EOF