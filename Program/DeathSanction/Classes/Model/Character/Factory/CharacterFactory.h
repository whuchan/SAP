#pragma once
#include "cocos2d.h"
#include "../Character.h"

//===============================================
// �O���錾
//===============================================
//class CBody;
//class CMove;
//class CStateMachine;
//class CCollisionArea;
//===============================================
//
// CCharacter�����H��N���X�i���ۃN���X�j
//
//===============================================
class CCharacterPartsFactory
{
public:
	/**
	* �R���X�g���N�^
	*/
	CCharacterPartsFactory();
	/**
	* �f�X�g���N�^
	*/
	virtual ~CCharacterPartsFactory();

	//==============================================================
	//
	// �������z�֐�
	//
	//==============================================================
	virtual CMove*						getMove(void) = 0;
	virtual CBody*						getBody(void) = 0;
	virtual std::vector<CCollisionArea*>* getCollisionAreas(void) = 0;
	/**
	* @desc ��ԑJ�ڃ}�V���̎擾
	* @return ��ԑJ�ڃ}�V���̃C���X�^���X
	*/
	virtual CStateMachine* getStateMachine(void) = 0;
};


//=======================================================
//
// �L�����N�^�[�H��(����)�N���X
//
//=======================================================
class CCharacterFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CCharacterFactory()
	{

	}
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CCharacterFactory()
	{

	}

	/**
	* @desc �G�L�����N�^�[�𐶐�
	* @param �������WX
	* @param �������WY
	* @return �G�L�����N�^�[�C���X�^���X
	*/
	virtual CCharacter* create(float posX, float posY)
	{
		//�G�L�����N�^�[�̐���
		CCharacter* pCharacter = this->createCharacter();

		//�A�j���[�V�����f�[�^�Q�̐ݒ�
		this->settingAnimations(pCharacter);
		//�ړ��f�[�^�̐ݒ�
		this->settingMove(pCharacter, posX, posY);
		//�������Z�f�[�^�Q�̐ݒ�
		this->settingPhysicals(pCharacter);
		//�A�N�V�����f�[�^�Q�̐ݒ�
		this->settingActions(pCharacter);
		//���̃f�[�^�̐ݒ�
		this->settingBody(pCharacter);
		//�e�N�X�`���̐ݒ�
		this->settingTexture(pCharacter);
		//�Փ˔���f�[�^�Q�̐ݒ�
		this->settingCollisionAreas(pCharacter);
		//��ԑJ�ڃ}�V���̐ݒ�
		this->settingStateMachine(pCharacter);

		//�����ݒ�
		this->settingInitialize(pCharacter);

		return pCharacter;
	}

protected:

	/**
	* @desc
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual CCharacter* createCharacter(void) = 0;
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	virtual void settingMove(CCharacter* pCharacter, float posX, float posY) = 0;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingTexture(CCharacter* pCharacter) = 0;
	/**
	* @desc �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingAnimations(CCharacter* pCharacter) = 0;
	/**
	* @desc �������Z�f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingPhysicals(CCharacter* pCharacter) = 0;
	/**
	* @desc �A�N�V�����f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingActions(CCharacter* pCharacter) = 0;
	/**
	* @desc ���̃f�[�^�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingBody(CCharacter* pCharacter) = 0;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingCollisionAreas(CCharacter* pCharacter) = 0;
	/**
	* @desc ��ԑJ�ڃ}�V���̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual	void settingStateMachine(CCharacter* pCharacter) = 0;

	/**
	* @desc ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingInitialize(CCharacter* pCharacter) = 0;

};

//EOF