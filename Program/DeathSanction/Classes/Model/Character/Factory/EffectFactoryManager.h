#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\EffectCharacter.h"
#include "Model\Character\Factory\CharacterFactory.h"

//=======================================================
//
// �G�H���Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CEffectFactoryManager
{
private:
	/*
	* @desc �R���X�g���N�^
	*/
	CEffectFactoryManager();
public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CEffectFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CEffectFactoryManager* getInstance(void);
	/**
	* @desc �G�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CCharacter* create(EFFECT_TYPE type, float posX, float posY);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();

private:
	//�G�����H��Q
	std::map<EFFECT_TYPE, CCharacterFactory*>* m_pFactories = NULL;
	//�V���O���g���C���X�^���X
	static CEffectFactoryManager* m_pSharedManager;
};
//EOF