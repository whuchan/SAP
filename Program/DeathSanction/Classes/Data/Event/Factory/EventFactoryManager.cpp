#include "Data\Event\Factory\EventFactoryManger.h"

//=======================================================
//
// �C�x���g�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
//�V���O���g���C���X�^���X
CEventFactoryManager* CEventFactoryManager::m_pSharedManager = NULL;

/*
* @desc �R���X�g���N�^
*/
CEventFactoryManager::CEventFactoryManager()
{
	//�C�x���g�H��Q�̐���
	this->m_pFactories = new std::map<EVENT_TYPE, CEventFactory*>();

	/*
	//�H��𐶐����Ď��t���Ă���
	//�A�z�z��̃L�[�̓}�b�v�`�b�vID�ɐݒ�
	(*this->m_pFactories)[ENEMY_TYPE::HENCHMAN_TYPE_A] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::LEATHERFACE] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::KILLER] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::KILLERBATTERY] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::PATAPATA] = new CHenchmanTypeAFactory();
	*/	
}

/**
* @desc �f�X�g���N�^
*/
CEventFactoryManager::~CEventFactoryManager()
{
	//�C�x���g�����H��Q�̔j��
	std::map<EVENT_TYPE, CEventFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//�C�x���g�����H��Q�̔j��
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc �V���O���g���F�F�C���X�^���X�̎擾
* @return �V���O���g���C���X�^���X
*/
CEventFactoryManager* CEventFactoryManager::getInstance(void)
{
	if (CEventFactoryManager::m_pSharedManager == NULL)
	{
		CEventFactoryManager::m_pSharedManager = new CEventFactoryManager();
	}
	return CEventFactoryManager::m_pSharedManager;
}

/**
* @desc �C�x���g�𐶐�
* @param �����^�C�v
* @param �������WX
* @param �������WY
*/
CEvent* CEventFactoryManager::create(EVENT_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CEventFactoryManager::removeInstance()
{
	SAFE_DELETE(CEventFactoryManager::m_pSharedManager);
}
//EOF