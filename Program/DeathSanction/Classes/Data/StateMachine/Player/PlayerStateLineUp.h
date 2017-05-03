#pragma once

#include "PlayerState.h"
#include "cocos2d.h"

//==========================================
//
// Class: CPlayerStateLineUp
//
// �v���C���[ ���C���A�b�v ��ԃN���X
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
class CPlayerStateLineUp :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerStateLineUp(CPlayerCharacter* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerStateLineUp(void);

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