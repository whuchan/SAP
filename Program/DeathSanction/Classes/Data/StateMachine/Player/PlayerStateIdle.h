#pragma once

#include "PlayerState.h"

//==========================================
//
// Class: CPlayerStateIdle
//
// �v���C���[ �ҋ@ ��ԃN���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateIdle :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerStateIdle(CPlayerCharacter* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerStateIdle(void);

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
};
