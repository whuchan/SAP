#pragma once

#include "PlayerState.h"

//==========================================
//
// Class: CPlayerStateWalk
//
// �v���C���[ �ҋ@ ��ԃN���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateWalk :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerStateWalk(CPlayerCharacter* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerStateWalk(void);

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
};
//EOF