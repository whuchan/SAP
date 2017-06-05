#pragma once
#include "DamageFactory.h"
#include "Model\Character\DamageCharacter.h"

//=======================================================
//
// �v���C���[�A�^�b�N�P�H��N���X
//
//=======================================================
class CPlayerAttack1Factory : public CDamageCreateFactory<CDamageCharacter>
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerAttack1Factory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerAttack1Factory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CCharacter* pCharacter)override;

	/**
	* @desc ��ԑJ�ڃ}�V���̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingStateMachine(CCharacter* pCharacter)override;

	/**
	* @desc	 ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CCharacter* pCharacter)override;
};
//EOF