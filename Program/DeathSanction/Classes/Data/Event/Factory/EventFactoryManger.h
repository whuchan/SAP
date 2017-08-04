#pragma once
#include "Model\Map\Map.h"
#include "Data\Event\Factory\EventFactory.h"

//=======================================================
//
// �G�H���Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CEventFactoryManager
{
private:
	/*
	* @desc �R���X�g���N�^
	*/
	CEventFactoryManager();
public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CEventFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CEventFactoryManager* getInstance(void);
	/**
	* @desc �G�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CEvent* create(EVENT_TYPE type, float posX, float posY);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();

private:
	//�G�����H��Q
	std::map<EVENT_TYPE, CEventFactory*>* m_pFactories = NULL;
	//�V���O���g���C���X�^���X
	static CEventFactoryManager* m_pSharedManager;
};
//EOF