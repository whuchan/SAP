#pragma once

#include "PlayerState.h"

//==========================================
//
// Class: CPlayerStateAttack1
//
// �v���C���[ �U���P ��ԃN���X
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================
class CPlayerStateAttack1 :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerStateAttack1(CPlayerCharacter* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerStateAttack1(void);

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
//EOF