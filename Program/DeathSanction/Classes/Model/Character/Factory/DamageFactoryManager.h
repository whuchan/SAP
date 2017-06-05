#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\DamageCharacter.h"
#include "Model\Character\Factory\DamageFactory.h"

//=======================================================
//
// �G�H���Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CDamageFactoryManager
{
private:
	/*
	* @desc �R���X�g���N�^
	*/
	CDamageFactoryManager();
public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CDamageFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CDamageFactoryManager* getInstance(void);
	/**
	* @desc �G�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CCharacter* create(DAMAGE_TYPE type, float posX, float posY);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();

private:
	//�G�����H��Q
	std::map<DAMAGE_TYPE, CCharacterFactory*>* m_pFactories = NULL;
	//�V���O���g���C���X�^���X
	static CDamageFactoryManager* m_pSharedManager;
};
//EOF