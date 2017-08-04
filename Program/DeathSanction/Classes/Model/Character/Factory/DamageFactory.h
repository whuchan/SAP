#pragma once
//==========================================
//
// File: DamageFactory.h
//
// �_���[�W�H�� �w�b�_�[�t�@�C��
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================
#include "CharacterFactory.h"
#include"../DamageCharacter.h"
#include "Model\Map\Map.h"

//=======================================================
//
// �_���[�W�p�[�c�H��N���X
//
//=======================================================
class CDamagePartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CDamagePartsFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CDamagePartsFactory();


	/**
	* @desc �ړ��f�[�^�̎擾
	* @return �ړ��f�[�^
	*/
	CMove*						getMove(void)override;

	/**
	* @desc ���̃f�[�^�̎擾
	* @return ���̃f�[�^
	*/
	CBody*						getBody(void)override;

	/**
	* @desc �Փ˔���̈�f�[�^�Q�̎擾
	* @return �Փ˔���̈�f�[�^�Q
	*/
	std::vector<CCollisionArea*>* getCollisionAreas(void)override;

	/**
	* @desc ��ԑJ�ڃ}�V���̎擾
	* @return ��ԑJ�ڃ}�V���̃C���X�^���X
	*/
	virtual CStateMachine* getStateMachine(void)override;

};


//=======================================================
//
// �_���[�W�����H��
//
//=======================================================
template <class T>
class CDamageCreateFactory : public CCharacterFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CDamageCreateFactory()
	{

	}

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CDamageCreateFactory()
	{

	}

protected:
	virtual CCharacter* createCharacter(void)
	{
		//�G�L�����N�^�[�̐���
		CCharacter* pCharacter = T::create();

		//�G�L�����N�^�[���i�����H��̐���
		CDamagePartsFactory factory;

		//�ړ��f�[�^�̐ݒ�
		pCharacter->addMove(factory.getMove());
		//���̃f�[�^�̐ݒ�
		pCharacter->addBody(factory.getBody());
		//�Փ˔���f�[�^�Q�̐ݒ�
		pCharacter->addCollisionAreas(factory.getCollisionAreas());
		//��ԑJ�ڃ}�V���̐ݒ�
		//pCharacter->addStateMachine(factory.getStateMachine());


		return pCharacter;
	}
};

//EOF