#include"EnemyFactoryManager.h"
#include "Model\Character\Factory\HenchmanTypeAFactory.h"
//=======================================================
//
// �G�L�����N�^�[�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
//�V���O���g���C���X�^���X
CEnemyFactoryManager* CEnemyFactoryManager::m_pSharedManager = NULL;

/*
* @desc �R���X�g���N�^
*/
CEnemyFactoryManager::CEnemyFactoryManager()
{
	//�G�H��Q�̐���
	this->m_pFactories = new std::map<ENEMY_TYPE, CCharacterFactory*>();

	//�H��𐶐����Ď��t���Ă���
	//�A�z�z��̃L�[�̓}�b�v�`�b�vID�ɐݒ�
	//�N���{�[�����H��̎��t��
	//(*this->m_pFactories)[ENEMY_TYPE::KURIBO] = new CKuriboFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::NOKONOKO] = new CGreenNokoNokoFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::PATAPATA] = new CGreenPataPataFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::KILLERBATTERY] = new CKillerBatteryFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::KILLER] = new CKillerFactory();

	(*this->m_pFactories)[ENEMY_TYPE::KURIBO] = new CHenchmanTypeAFactory();
}

/**
* @desc �f�X�g���N�^
*/
CEnemyFactoryManager::~CEnemyFactoryManager()
{
	//�G�����H��Q�̔j��
	std::map<ENEMY_TYPE, CCharacterFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//�G�����H��Q�̔j��
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc �V���O���g���F�F�C���X�^���X�̎擾
* @return �V���O���g���C���X�^���X
*/
CEnemyFactoryManager* CEnemyFactoryManager::getInstance(void)
{
	if (CEnemyFactoryManager::m_pSharedManager == NULL)
	{
		CEnemyFactoryManager::m_pSharedManager = new CEnemyFactoryManager();
	}
	return CEnemyFactoryManager::m_pSharedManager;
}

/**
* @desc �G�L�����N�^�[�𐶐�
* @param �����^�C�v
* @param �������WX
* @param �������WY
*/
CCharacter* CEnemyFactoryManager::create(ENEMY_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CEnemyFactoryManager::removeInstance()
{
	SAFE_DELETE(CEnemyFactoryManager::m_pSharedManager);
}