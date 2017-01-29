#include"BulletFactory.h"

/**
* @desc �R���X�g���N�^
*/
CBulletFactory::CBulletFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CBulletFactory::~CBulletFactory()
{

}

/**
* @desc �e�L�����N�^�[�𐶐�
* @param �������WX
* @param �������WY
*/
CBulletCharacter* CBulletFactory::create(float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//�e�L�����N�^�[�̐���
	CBulletCharacter* pCharacter = this->createBullet();

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	this->settingAnimations(pCharacter);
	//�ړ��f�[�^�̐ݒ�
	this->settingMove(pCharacter, posX, posY, shotLaunchVector);
	//�������Z�f�[�^�Q�̐ݒ�
	this->settingPhysicals(pCharacter);
	//�A�N�V�����f�[�^�Q�̐ݒ�
	this->settingActions(pCharacter);
	//���̃f�[�^�̐ݒ�
	this->settingBody(pCharacter);
	//�e�N�X�`���̐ݒ�
	this->settingTexture(pCharacter);
	//�Փ˔���f�[�^�Q�̐ݒ�
	this->settingCollisionAreas(pCharacter);
	//�����ݒ�
	this->settingInitialize(pCharacter);

	return pCharacter;
}



//=======================================================
//
// �e�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CBulletCreateFactory::CBulletCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CBulletCreateFactory::~CBulletCreateFactory()
{

}

/**
* @desc �e�L�����N�^�[�̐���
* @return �e�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CBulletCharacter*  CBulletCreateFactory::createBullet(void)
{
	//�e�L�����N�^�[�̐���
	CBulletCharacter* pCharacter = CBulletCharacter::create();

	//�e�L�����N�^�[���i�����H��̐���
	CBulletPartsFactory factory;

	//�ړ��f�[�^�̐ݒ�
	pCharacter->addMove(factory.getMove());
	//���̃f�[�^�̐ݒ�
	pCharacter->addBody(factory.getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}



/**
* @desc �R���X�g���N�^
*/
CBulletPartsFactory::CBulletPartsFactory()
{

}
/**
* @desc �f�X�g���N�^
*/
CBulletPartsFactory::~CBulletPartsFactory()
{

}

/**
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove*	CBulletPartsFactory::getMove(void)
{
	//�ړ��f�[�^�̍쐬
	return new CMove();
}


/**
* @desc ���̃f�[�^�̎擾
* @return ���̃f�[�^
*/
CBody*	CBulletPartsFactory::getBody(void)
{
	//���̃f�[�^�̍쐬
	return new CBody();
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̎擾
* @return �Փ˔���̈�f�[�^�Q
*/
std::vector<CCollisionArea*>* CBulletPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}



//=======================================================
//
// �m�[�}���e�H��N���X
//
//=======================================================

/**
* @desc �R���X�g���N�^
*/
CNormalBulletFactory::CNormalBulletFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CNormalBulletFactory::~CNormalBulletFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CNormalBulletFactory::settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);

	//�����x�̐ݒ�͌Œ�
	pMove->m_speed = 5.0f;

	//�e�̔��˕����̃x�N�g��
	pCharacter->m_shotLaunchVector = shotLaunchVector;
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNormalBulletFactory::settingTexture(CBulletCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_NORMAL_BULLET);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNormalBulletFactory::settingAnimations(CBulletCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(0, 0, 16, 16));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNormalBulletFactory::settingPhysicals(CBulletCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNormalBulletFactory::settingActions(CBulletCharacter* pCharacter)
{
	pCharacter->m_intActionState = 0;

	//�A�N�V�����f�[�^�Q�̎擾
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionMoveStraight();

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNormalBulletFactory::settingBody(CBulletCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-8, 8, 8, -8);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CNormalBulletFactory::settingCollisionAreas(CBulletCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	

	//��ʊO�Փ˔����Ԃ̐���
	
	CCollisionArea* pOutOfScreenArea = new CCollisionAreaOutOfScreen(pCharacter->getBody());
	//��ʉE�[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenRight());
	//��ʍ��[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenLeft());

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pOutOfScreenArea);

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�
	
	
	//�E�̃}�b�v�`�b�v�̈�𐶐�
	CCollisionTerritory*  pCollisionTerritory = new CCollisionTerritoryMapChipRight();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	//�E�̃}�b�v�`�b�v�̈�𐶐�
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipLeft();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionLeftCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);

	//��_�̐ݒ�
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, 2)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, -2)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, 2)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, -2)));


	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 ����������
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNormalBulletFactory::settingInitialize(CBulletCharacter* pCharacter)
{
	//��Ԃ̐ݒ�
	pCharacter->m_state = 0;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pCharacter->m_isAlive = true;

	//�ʒu�𔽉f
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
}

//=======================================================
//
// �J�X�^���e�H��N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CCustomBulletFactory::CCustomBulletFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CCustomBulletFactory::~CCustomBulletFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CCustomBulletFactory::settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);

	//�����x�̐ݒ�͌Œ�
	pMove->m_speed = 3.0f;

	//�e�̔��˕����̃x�N�g��
	pCharacter->m_shotLaunchVector = shotLaunchVector;
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CCustomBulletFactory::settingTexture(CBulletCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_NORMAL_BULLET);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CCustomBulletFactory::settingAnimations(CBulletCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(0, 0, 16, 16));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CCustomBulletFactory::settingPhysicals(CBulletCharacter* pCharacter)
{
	//�������Z�f�[�^�Q�̎擾
	pCharacter->m_intPhysicalState = 0;
	
	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//�d�͉��Z�̐ݒ�
	pointerPhysical->push_back(new CPhysicalGravity(-0.15f));

	//�d�͉��Z�̐ݒ�
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CCustomBulletFactory::settingActions(CBulletCharacter* pCharacter)
{
	//�A�N�V�����f�[�^�Q�̎擾
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionMoveStraight();

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;

}

/**
* @desc	 ���̃f�[�^��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CCustomBulletFactory::settingBody(CBulletCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-8, 8, 8, -8);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CCustomBulletFactory::settingCollisionAreas(CBulletCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================


	//��ʊO�Փ˔����Ԃ̐���
	CCollisionArea* pOutOfScreenArea = new CCollisionAreaOutOfScreen(pCharacter->getBody());
	//��ʉE�[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenRight());
	//��ʍ��[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenLeft());
	//��ʉ��[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenBottom());
	
	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pOutOfScreenArea);

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�


	//�E�̃}�b�v�`�b�v�̈�𐶐�
	CCollisionTerritory*  pCollisionTerritory = new CCollisionTerritoryMapChipRight();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	//�E�̃}�b�v�`�b�v�̈�𐶐�
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipLeft();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionLeftCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//�}�b�v�`�b�v���̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	//��_�̐ݒ�
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, 2)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, -2)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, 2)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, -2)));


	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(2, -4)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-2, -4)));


	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}

/**
* @desc	 ����������
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CCustomBulletFactory::settingInitialize(CBulletCharacter* pCharacter)
{
	//��Ԃ̐ݒ�
	pCharacter->m_state = 0;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pCharacter->m_isAlive = true;

	//�ʒu�𔽉f
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
}


//=======================================================
//
//�t�@�C�A�[�{�[�� �e�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CFireBallBulletCreateFactory::CFireBallBulletCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CFireBallBulletCreateFactory::~CFireBallBulletCreateFactory()
{

}

/**
* @desc �e�L�����N�^�[�̐���
* @return �e�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CFireBallBulletCharacter*  CFireBallBulletCreateFactory::createBullet(void)
{
	//�e�L�����N�^�[�̐���
	CFireBallBulletCharacter* pCharacter = CFireBallBulletCharacter::create();

	//�e�L�����N�^�[���i�����H��̐���
	CBulletPartsFactory factory;

	//�ړ��f�[�^�̐ݒ�
	pCharacter->addMove(factory.getMove());
	//���̃f�[�^�̐ݒ�
	pCharacter->addBody(factory.getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}




//=======================================================
//
// �t�@�C�A�[�{�[���e�H��N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CFireBallBulletFactory::CFireBallBulletFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CFireBallBulletFactory::~CFireBallBulletFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CFireBallBulletFactory::settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);

	//�����x�̐ݒ�͌Œ�
	pMove->m_speed = 3.0f;

	//�e�̔��˕����̃x�N�g��
	pCharacter->m_shotLaunchVector = shotLaunchVector;
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CFireBallBulletFactory::settingTexture(CBulletCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_FIREBALL_BULLET);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CFireBallBulletFactory::settingAnimations(CBulletCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipListAnimation(10, true);

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(0, 0, 16, 16));
	pointerAnimation->addChipData(new CChip(16, 0, 16, 16));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CFireBallBulletFactory::settingPhysicals(CBulletCharacter* pCharacter)
{
	//�������Z�f�[�^�Q�̎擾
	pCharacter->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//�d�͉��Z�̐ݒ�
	pointerPhysical->push_back(new CPhysicalGravity(-0.15f));

	//�d�͉��Z�̐ݒ�
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;	
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CFireBallBulletFactory::settingActions(CBulletCharacter* pCharacter)
{
	//�A�N�V�����f�[�^�Q�̎擾
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionJump(3.0f, 4);
	(*mapAction)[1] = new CActionMoveStraight();

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
}

/**
* @desc	 ���̃f�[�^��ݒ�
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CFireBallBulletFactory::settingBody(CBulletCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-8, 8, 8, -8);
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CFireBallBulletFactory::settingCollisionAreas(CBulletCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================


	//��ʊO�Փ˔����Ԃ̐���
	CCollisionArea* pOutOfScreenArea = new CCollisionAreaOutOfScreen(pCharacter->getBody());
	//��ʉE�[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenRight());
	//��ʍ��[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenLeft());
	//��ʉ��[�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenBottom());

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pOutOfScreenArea);

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�


	//�E�̃}�b�v�`�b�v�̈�𐶐�
	CCollisionTerritory*  pCollisionTerritory = new CCollisionTerritoryMapChipRight();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	//�E�̃}�b�v�`�b�v�̈�𐶐�
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipLeft();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionLeftCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//�}�b�v�`�b�v���̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	//��_�̐ݒ�
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, 4)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, -4)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, 4)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�iY���������炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, -4)));


	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(4, -8)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-4, -8)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, -8)));

	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}



/**
* @desc	 ����������
* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CFireBallBulletFactory::settingInitialize(CBulletCharacter* pCharacter)
{
	//��Ԃ̐ݒ�
	pCharacter->m_state = 0;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pCharacter->m_isAlive = true;

	//�ʒu�𔽉f
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
}


//=======================================================
//
// �e�L�����N�^�[�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
//�V���O���g���C���X�^���X
CBulletFactoryManager* CBulletFactoryManager::m_pSharedManager = NULL;

/*
* @desc �R���X�g���N�^
*/
CBulletFactoryManager::CBulletFactoryManager()
{
	//�e�H��Q�̐���
	this->m_pFactories = new std::map<BULLET_TYPE, CBulletFactory*>();

	//�H��𐶐����Ď��t���Ă���
	//�A�z�z��̃L�[�̓}�b�v�`�b�vID�ɐݒ�
	//�N���{�[�����H��̎��t��
	(*this->m_pFactories)[BULLET_TYPE::NORMAL] = new CNormalBulletFactory();
	(*this->m_pFactories)[BULLET_TYPE::CUSTOM] = new CCustomBulletFactory();
	(*this->m_pFactories)[BULLET_TYPE::FIREBALL] = new CFireBallBulletFactory();
}

/**
* @desc �f�X�g���N�^
*/
CBulletFactoryManager::~CBulletFactoryManager()
{
	//�e�����H��Q�̔j��
	std::map<BULLET_TYPE, CBulletFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//�e�����H��Q�̔j��
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc �V���O���g���F�F�C���X�^���X�̎擾
* @return �V���O���g���C���X�^���X
*/
CBulletFactoryManager* CBulletFactoryManager::getInstance(void)
{
	if (CBulletFactoryManager::m_pSharedManager == NULL)
	{
		CBulletFactoryManager::m_pSharedManager = new CBulletFactoryManager();
	}
	return CBulletFactoryManager::m_pSharedManager;
}

/**
* @desc �e�L�����N�^�[�𐶐�
* @param �����^�C�v
* @param �������WX
* @param �������WY
* @param �e�̔��˕����̃x�N�g��(�e�̌����x�N�g��)
*/
CBulletCharacter* CBulletFactoryManager::create(BULLET_TYPE type, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	return (*this->m_pFactories)[type]->create(posX, posY,shotLaunchVector);
}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CBulletFactoryManager::removeInstance()
{
	SAFE_DELETE(CBulletFactoryManager::m_pSharedManager);
}
