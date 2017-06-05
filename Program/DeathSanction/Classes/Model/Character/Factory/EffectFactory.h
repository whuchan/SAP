#pragma once
//==========================================
//
// File: EffectFactory.h
//
// �G�t�F�N�g�H�� �w�b�_�[�t�@�C��
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================
#include "CharacterFactory.h"
#include"../EffectCharacter.h"
#include "Model\Map\Map.h"

//=======================================================
//
// �G�t�F�N�g�p�[�c�H��N���X
//
//=======================================================
class CEffectPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEffectPartsFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CEffectPartsFactory();


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
// �G�t�F�N�g�����H��
//
//=======================================================
template <class T>
class CEffectCreateFactory : public CCharacterFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEffectCreateFactory()
	{

	}

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CEffectCreateFactory()
	{

	}

protected:
	virtual CCharacter* createCharacter(void)
	{
		//�G�L�����N�^�[�̐���
		CCharacter* pCharacter = T::create();

		//�G�L�����N�^�[���i�����H��̐���
		CEffectPartsFactory factory;

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