#include"DamageFactoryManager.h"
#include "Model\Character\Factory\PlayerAttack1Factory.h"
//=======================================================
//
// �_���[�W�L�����N�^�[�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
//�V���O���g���C���X�^���X
CDamageFactoryManager* CDamageFactoryManager::m_pSharedManager = NULL;

/*
* @desc �R���X�g���N�^
*/
CDamageFactoryManager::CDamageFactoryManager()
{
	//�G�H��Q�̐���
	this->m_pFactories = new std::map<DAMAGE_TYPE, CCharacterFactory*>();

	//�H��𐶐����Ď��t���Ă���
	//�A�z�z��̃L�[�̓}�b�v�`�b�vID�ɐݒ�
	(*this->m_pFactories)[DAMAGE_TYPE::PLAYER_ATTACK_1] = new CPlayerAttack1Factory();
}

/**
* @desc �f�X�g���N�^
*/
CDamageFactoryManager::~CDamageFactoryManager()
{
	//�G�����H��Q�̔j��
	std::map<DAMAGE_TYPE, CCharacterFactory*>::iterator itr = this->m_pFactories->begin();

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
CDamageFactoryManager* CDamageFactoryManager::getInstance(void)
{
	if (CDamageFactoryManager::m_pSharedManager == NULL)
	{
		CDamageFactoryManager::m_pSharedManager = new CDamageFactoryManager();
	}
	return CDamageFactoryManager::m_pSharedManager;
}

/**
* @desc �G�L�����N�^�[�𐶐�
* @param �����^�C�v
* @param �������WX
* @param �������WY
*/
CCharacter* CDamageFactoryManager::create(DAMAGE_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CDamageFactoryManager::removeInstance()
{
	SAFE_DELETE(CDamageFactoryManager::m_pSharedManager);
}