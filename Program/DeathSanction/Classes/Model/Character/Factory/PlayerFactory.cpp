#include"PlayerFactory.h"
#include"Model\Character\BulletCharacter.h"


/**
* @desc �R���X�g���N�^
*/
CPlayerFactory::CPlayerFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CPlayerFactory::~CPlayerFactory()
{

}

/**
* @desc �v���C���[�L�����N�^�[�𐶐�
* @param �����^�C�v
*/
CPlayerCharacter* CPlayerFactory::create(void)
{
	//�v���C���[�L�����N�^�[�̐���
	CPlayerCharacter* pPlayer = this->createPlayer();

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	this->settingAnimations(pPlayer);
	//�ړ��f�[�^�̐ݒ�
	this->settingMove(pPlayer);
	//�������Z�f�[�^�Q�̐ݒ�
	this->settingPhysicals(pPlayer);
	//�A�N�V�����f�[�^�Q�̐ݒ�
	this->settingActions(pPlayer);
	//���̃f�[�^�̐ݒ�
	this->settingBody(pPlayer);
	//�e�N�X�`���̐ݒ�
	this->settingTexture(pPlayer);
	//�Փ˔���f�[�^�Q�̐ݒ�
	this->settingCollisionAreas(pPlayer);
	//�����ݒ�
	this->settingInitialize(pPlayer);



	/*
	* �v�Z�f�[�^�̂܂܂ŋN������ƂP�t���[���Y������������̂�
	*�@���������̍Ō�ɒl��Sprite�ɔ��f����
	*/
	pPlayer->applyFunc();


	return pPlayer;
}



//=======================================================
//
// �v���C���[�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CPlayerCreateFactory::CPlayerCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CPlayerCreateFactory::~CPlayerCreateFactory()
{

}

/**
* @desc �v���C���[�L�����N�^�[�̐���
* @return �v���C���[�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CPlayerCharacter*  CPlayerCreateFactory::createPlayer(void)
{
	//�v���C���[�L�����N�^�[�̐���
	CPlayerCharacter* pPlayer = CPlayerCharacter::create();

	//�v���C���[�L�����N�^�[���i�����H��̐���
	CCharacterPartsFactory* pFactory = new CPlayerPartsFactory();

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	pPlayer->addAnimations(pFactory->getAnimations());
	//�ړ��f�[�^�̐ݒ�
	pPlayer->addMove(pFactory->getMove());
	//�������Z�f�[�^�Q�̐ݒ�
	pPlayer->addPhysicals(pFactory->getPhysicals());
	//�A�N�V�����f�[�^�Q�̐ݒ�
	pPlayer->addActions(pFactory->getActions());
	//���̃f�[�^�̐ݒ�
	pPlayer->addBody(pFactory->getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pPlayer->addCollisionAreas(pFactory->getCollisionAreas());



	//�v���C���[�L�����N�^�[���i�����H��̉��
	SAFE_DELETE(pFactory);

	return pPlayer;
}



/**
* @desc �R���X�g���N�^
*/
CPlayerPartsFactory::CPlayerPartsFactory()
{

}
/**
* @desc �f�X�g���N�^
*/
CPlayerPartsFactory::~CPlayerPartsFactory()
{

}

/**
* @desc �A�j���[�V�����f�[�^�Q�̎擾
* @return �A�j���[�V�����f�[�^�Q
*/
std::vector<CAnimation*>* CPlayerPartsFactory::getAnimations(void)
{
	//�A�j���[�V�����f�[�^�Q�̍쐬
	std::vector<CAnimation*>* pAnimations = new std::vector<CAnimation*>;
	//�����A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipNotAnimation());
	//���s�A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipListAnimation(10, true));
	//�_���[�W���󂯂��Ƃ��̃A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipNotAnimation());
	//�����Ă���Ƃ��̃A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipNotAnimation());

	return pAnimations;
}

/**
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove*	CPlayerPartsFactory::getMove(void)
{
	//�ړ��f�[�^�̍쐬
	return new CMove();
}
/**
* @desc �������Z�f�[�^�Q�擾
* @return �������Z�f�[�^�Q
*/
std::vector<CPhysical*>* CPlayerPartsFactory::getPhysicals(void)
{
	//�K�p�����镨�����Z�쐬
	return new std::vector<CPhysical*>;
}

/**
* @desc �A�N�V�����f�[�^�Q�̎擾
* @return �A�N�V�����f�[�^�Q
*/
std::vector<CAction*>* CPlayerPartsFactory::getActions(void)
{
	//�s����A�N�V�����Q���쐬
	return new std::vector<CAction*>;
	
}

/**
* @desc ���̃f�[�^�̎擾
* @return ���̃f�[�^
*/
CBody*	CPlayerPartsFactory::getBody(void)
{
	//���̃f�[�^�̍쐬
	return new CBody();
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̎擾
* @return �Փ˔���̈�f�[�^�Q
*/
std::vector<CCollisionArea*>* CPlayerPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>;
}


/**
* @desc �R���X�g���N�^
*/
CBasePlayerFactory::CBasePlayerFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CBasePlayerFactory::~CBasePlayerFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingMove(CPlayerCharacter* pPlayer)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pPlayer->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(320.0f, 320.0f);

	pPlayer->m_shotLaunchVector = cocos2d::Vec2(1.0f, 0.0f);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingTexture(CPlayerCharacter* pPlayer)
{
	//�e�N�X�`���̐ݒ�
	pPlayer->setTexture(IMAGE_PLAYER);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingAnimations(CPlayerCharacter* pPlayer)
{
	//�A�j���[�V�����f�[�^�Q�̎擾
	std::vector<CAnimation*>* pAnimations = pPlayer->getAnimations();
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[(int)CPlayerCharacter::STATE::STAND]->addChipData(new CChip(0, 0, 64, 64));
	//���s�A�j���[�V�����ɐݒ肷��P���ڂ̃`�b�v�f�[�^�̍쐬
	(*pAnimations)[(int)CPlayerCharacter::STATE::WALK]->addChipData(new CChip(64, 0, 64, 64));
	//���s�A�j���[�V�����ɐݒ肷��Q���ڂ̃`�b�v�f�[�^�̍쐬
	(*pAnimations)[(int)CPlayerCharacter::STATE::WALK]->addChipData(new CChip(128, 0, 64, 64));
	//�_���[�W���󂯂��Ƃ��̃A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[(int)CPlayerCharacter::STATE::HIT]->addChipData(new CChip(192, 0, 64, 64));
	//�����Ă���Ƃ��̃A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[(int)CPlayerCharacter::STATE::FALING]->addChipData(new CChip(256, 0, 64, 64));
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingPhysicals(CPlayerCharacter* pPlayer)
{
	//�������Z�f�[�^�Q�̎擾
	std::vector<CPhysical*>* pPhysicals = pPlayer->getPhysicals();
	//�d�͉��Z�̐ݒ�
	pPhysicals->push_back(new CPhysicalGravity());
	//���C���Z�̐ݒ�
	pPhysicals->push_back(new CPhysicalFriction(6.0f));
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingActions(CPlayerCharacter* pPlayer)
{
	//�A�N�V�����f�[�^�Q�̎擾
	std::vector<CAction*>* pActions = pPlayer->getActions();

	//�W�����v�A�N�V������ݒ�
	pActions->push_back(new CActionJump(3.0f, 4));

	//�ʏ�e���˃A�N�V������ݒ�
	pActions->push_back(new CActionShotBullet((int)BULLET_TYPE::NORMAL,20));

	//�J�X�^���e���˃A�N�V������ݒ�
	pActions->push_back(new CActionShotBullet((int)BULLET_TYPE::CUSTOM, 20));

	//�t�@�C�A�[�{�[���e���˃A�N�V������ݒ�
	pActions->push_back(new CActionShotBullet((int)BULLET_TYPE::FIREBALL, 20));
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingBody(CPlayerCharacter* pPlayer)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pPlayer->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-32, 32, 32, -32);
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CBasePlayerFactory::settingCollisionAreas(CPlayerCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());

	//��ʉ��[�̗̈�𐶐�
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//��ʉ��[�̏Փ˂����ۂ̃C�x���g��ݒ�
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//��ʉ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);

 

	//��ʒ[�̏Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pEndOfScreenArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, -32)));

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pEndOfScreenArea);

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�

	//���̃}�b�v�`�b�v�̈�𐶐�
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//���̃}�b�v�`�b�v�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N��ݒ�
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pMapChipBottomTerritory);
	//��̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//�E�̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());


	//��_�̐ݒ�
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤X���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16, -32)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤X���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-16, -32)));

	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iX���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16, 32)));
	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iX���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-16, 32)));

	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, 16)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, -16)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, 16)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, -16)));


	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 ����������
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingInitialize(CPlayerCharacter* pPlayer)
{
	//��Ԃ̐ݒ�
	pPlayer->m_state = (int)CPlayerCharacter::STATE::FALING;

	//�L���t���O�𗧂Ă�
	pPlayer->m_activeFlag = true;
}

//=======================================================
//
// �v���C���[�L�����N�^�[�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
//�V���O���g���C���X�^���X
CPlayerFactoryManager* CPlayerFactoryManager::m_pSharedFactory=NULL;

/*
* @desc �R���X�g���N�^
*/
CPlayerFactoryManager::CPlayerFactoryManager()
{	
	//�H��𐶐����Ď��t���Ă���
	this->m_pFactories.push_back(new CBasePlayerFactory());

}

/**
* @desc �f�X�g���N�^
*/
CPlayerFactoryManager::~CPlayerFactoryManager()
{
	for (CPlayerFactory* pFactory : this->m_pFactories)
	{
		SAFE_DELETE(pFactory);
	}
}

/**
* @desc �V���O���g���F�F�C���X�^���X�̎擾
* @return �V���O���g���C���X�^���X
*/
CPlayerFactoryManager* CPlayerFactoryManager::getInstance(void)
{
	if (m_pSharedFactory == NULL)
	{
		m_pSharedFactory = new CPlayerFactoryManager();
	}
	return m_pSharedFactory;
}

/**
* @desc �v���C���[�L�����N�^�[�𐶐�
* @param �����^�C�v
*/
CPlayerCharacter* CPlayerFactoryManager::create(CPlayerFactoryManager::TYPE type)
{
	return this->m_pFactories[(int)type]->create();
}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CPlayerFactoryManager::removeInstance()
{
	SAFE_DELETE(m_pSharedFactory);
}