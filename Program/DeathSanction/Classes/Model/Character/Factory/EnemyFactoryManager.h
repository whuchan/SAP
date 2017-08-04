#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\EnemyCharacter.h"
#include "Model\Character\Factory\EnemyFactory.h"

//=======================================================
//
// �G�H���Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CEnemyFactoryManager
{
private:
	/*
	* @desc �R���X�g���N�^
	*/
	CEnemyFactoryManager();
public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CEnemyFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CEnemyFactoryManager* getInstance(void);
	/**
	* @desc �G�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CCharacter* create(ENEMY_TYPE type, float posX, float posY);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();

private:
	//�G�����H��Q
	std::map<ENEMY_TYPE, CCharacterFactory*>* m_pFactories = NULL;
	//�V���O���g���C���X�^���X
	static CEnemyFactoryManager* m_pSharedManager;
};
//EOF