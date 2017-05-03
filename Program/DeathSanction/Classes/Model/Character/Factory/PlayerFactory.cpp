#include"PlayerFactory.h"
#include"Model\Character\BulletCharacter.h"
#include "Data\StateMachine\Player\PlayerStateIdle.h"
#include "Data\StateMachine\Player\PlayerStateWalk.h"
#include "Data\StateMachine\Player\PlayerStateLineUp.h"
#include "Data\StateMachine\Player\PlayerStateLineDown.h"


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
	//��ԑJ�ڃ}�V���̐ݒ�
	this->settingStateMachine(pPlayer);
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

	//�ړ��f�[�^�̐ݒ�
	pPlayer->addMove(pFactory->getMove());
	//���̃f�[�^�̐ݒ�
	pPlayer->addBody(pFactory->getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pPlayer->addCollisionAreas(pFactory->getCollisionAreas());

	//��ԑJ�ڃ}�V���̐ݒ�
	pPlayer->addStateMachine(pFactory->getStateMachine());

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
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove*	CPlayerPartsFactory::getMove(void)
{
	//�ړ��f�[�^�̍쐬
	return new CMove();
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
* @desc ��ԑJ�ڃ}�V���̎擾
* @return ��ԑJ�ڃ}�V���̃C���X�^���X
*/
CStateMachine* CPlayerPartsFactory::getStateMachine()
{
	return new CStateMachine();
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
	pPlayer->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(0, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::IDLE] = pointerAnimation;

	pointerAnimation = new CChipListAnimation(10, true);

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(64, 0, 64, 64));
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(128, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::WALK] = pointerAnimation;

	pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(192, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::HIT] = pointerAnimation;

	pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(128, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::FALING] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingPhysicals(CPlayerCharacter* pPlayer)
{

	//�������Z�f�[�^�Q�̎擾
	pPlayer->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//�d�͉��Z�̐ݒ�
	pointerPhysical->push_back(new CPhysicalGravity());
	pointerPhysical->push_back(new CPhysicalFriction(6.0f));
	//�d�͉��Z�̐ݒ�
	pPlayer->m_mapPhysical[pPlayer->m_intPhysicalState] = pointerPhysical;
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingActions(CPlayerCharacter* pPlayer)
{
	pPlayer->m_intActionState = 0;

	//�A�N�V�����f�[�^�Q�̎擾
	std::map<int,CAction*>* mapAction = new std::map<int,CAction*>();

	//�W�����v�A�N�V������ݒ�
	(*mapAction)[(int)CPlayerCharacter::ACTION::JUMP] = new CActionJump(3.0f, 4);

	//�ʏ�e���˃A�N�V������ݒ�
	//(*mapAction)[(int)CPlayerCharacter::ACTION::SHOT_NORMAL_BULLET] = new CActionShotBullet((int)BULLET_TYPE::NORMAL, 20);

	////�J�X�^���e���˃A�N�V������ݒ�
	//(*mapAction)[(int)CPlayerCharacter::ACTION::SHOT_CUSTOM_BULLET] = new CActionShotBullet((int)BULLET_TYPE::CUSTOM, 20);

	////�t�@�C�A�[�{�[���e���˃A�N�V������ݒ�
	//(*mapAction)[(int)CPlayerCharacter::ACTION::SHOT_FIREBALL_BULLET] = new CActionShotBullet((int)BULLET_TYPE::FIREBALL, 20);

	pPlayer->m_mapAction[pPlayer->m_intActionState] = mapAction;
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
* @desc ��ԑJ�ڃ}�V���̐ݒ�
* @param ���t����L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CBasePlayerFactory::settingStateMachine(CPlayerCharacter* pCharacter)
{
	//�ҋ@���
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::IDLE, new CPlayerStateIdle(pCharacter));

	//���s���
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::WALK, new CPlayerStateWalk(pCharacter));

	//���C���A�b�v���
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_UP, new CPlayerStateLineUp(pCharacter));

	//���C���_�E�����
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_DOWN, new CPlayerStateLineDown(pCharacter));


	//������Ԃ̐ݒ�
	pCharacter->m_stateMachine->setStartState((int)CPlayerCharacter::STATE::IDLE);
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