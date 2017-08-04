#include"EffectFactoryManager.h"
#include "Model\Character\Factory\PlayerEffectHit1Factory.h"
//=======================================================
//
// �_���[�W�L�����N�^�[�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
//�V���O���g���C���X�^���X
CEffectFactoryManager* CEffectFactoryManager::m_pSharedManager = NULL;

/*
* @desc �R���X�g���N�^
*/
CEffectFactoryManager::CEffectFactoryManager()
{
	//�G�H��Q�̐���
	this->m_pFactories = new std::map<EFFECT_TYPE, CCharacterFactory*>();

	//�H��𐶐����Ď��t���Ă���
	//�A�z�z��̃L�[�̓}�b�v�`�b�vID�ɐݒ�
	(*this->m_pFactories)[EFFECT_TYPE::PLAYER_HIT_1] = new CPlayerEffectHit1Factory();
}

/**
* @desc �f�X�g���N�^
*/
CEffectFactoryManager::~CEffectFactoryManager()
{
	//�G�����H��Q�̔j��
	std::map<EFFECT_TYPE, CCharacterFactory*>::iterator itr = this->m_pFactories->begin();

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
CEffectFactoryManager* CEffectFactoryManager::getInstance(void)
{
	if (CEffectFactoryManager::m_pSharedManager == NULL)
	{
		CEffectFactoryManager::m_pSharedManager = new CEffectFactoryManager();
	}
	return CEffectFactoryManager::m_pSharedManager;
}

/**
* @desc �G�L�����N�^�[�𐶐�
* @param �����^�C�v
* @param �������WX
* @param �������WY
*/
CCharacter* CEffectFactoryManager::create(EFFECT_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CEffectFactoryManager::removeInstance()
{
	SAFE_DELETE(CEffectFactoryManager::m_pSharedManager);
}