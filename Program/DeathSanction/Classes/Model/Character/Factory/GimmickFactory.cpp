#include"GimmickFactory.h"
#include"Model\Character\TikuwaBlockGimmickCharacter.h"
#include"Model\Character\NoteBlockGimmickCharacter.h"
/**
* @desc �R���X�g���N�^
*/
CGimmickFactory::CGimmickFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CGimmickFactory::~CGimmickFactory()
{

}

/**
* @desc �M�~�b�N�L�����N�^�[�𐶐�
* @param �������WX
* @param �������WY
*/
CGimmickCharacter* CGimmickFactory::create(float posX, float posY)
{
	//�M�~�b�N�L�����N�^�[�̐���
	CGimmickCharacter* pCharacter = this->createGimmick();


	//���̃f�[�^�̐ݒ�
	this->settingBody(pCharacter);
	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	this->settingAnimations(pCharacter);
	//�ړ��f�[�^�̐ݒ�
	this->settingMove(pCharacter, posX, posY);
	//�������Z�f�[�^�Q�̐ݒ�
	this->settingPhysicals(pCharacter);
	//�A�N�V�����f�[�^�Q�̐ݒ�
	this->settingActions(pCharacter);
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
// �M�~�b�N�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CDamageBlockGimmickCreateFactory::CDamageBlockGimmickCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CDamageBlockGimmickCreateFactory::~CDamageBlockGimmickCreateFactory()
{

}

/**
* @desc �M�~�b�N�L�����N�^�[�̐���
* @return �M�~�b�N�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CGimmickCharacter*  CDamageBlockGimmickCreateFactory::createGimmick(void)
{
	//�M�~�b�N�L�����N�^�[�̐���
	CGimmickCharacter* pCharacter = CDamageBlockGimmickCharacter::create();

	//�M�~�b�N�L�����N�^�[���i�����H��̐���
	CGimmickPartsFactory factory;

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	pCharacter->addAnimations(factory.getAnimations());
	//�ړ��f�[�^�̐ݒ�
	pCharacter->addMove(factory.getMove());
	//�������Z�f�[�^�Q�̐ݒ�
	pCharacter->addPhysicals(factory.getPhysicals());
	//�A�N�V�����f�[�^�Q�̐ݒ�
	pCharacter->addActions(factory.getActions());
	//���̃f�[�^�̐ݒ�
	pCharacter->addBody(factory.getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}



/**
* @desc �R���X�g���N�^
*/
CGimmickPartsFactory::CGimmickPartsFactory()
{

}
/**
* @desc �f�X�g���N�^
*/
CGimmickPartsFactory::~CGimmickPartsFactory()
{

}

/**
* @desc �A�j���[�V�����f�[�^�Q�̎擾
* @return �A�j���[�V�����f�[�^�Q
*/
std::vector<CAnimation*>* CGimmickPartsFactory::getAnimations(void)
{
	//�A�j���[�V�����f�[�^�Q�̍쐬
	return new std::vector<CAnimation*>();
}

/**
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove*	CGimmickPartsFactory::getMove(void)
{
	//�ړ��f�[�^�̍쐬
	return new CMove();
}
/**
* @desc �������Z�f�[�^�Q�擾
* @return �������Z�f�[�^�Q
*/
std::vector<CPhysical*>* CGimmickPartsFactory::getPhysicals(void)
{
	//�K�p�����镨�����Z�쐬
	return new std::vector<CPhysical*>();
}

/**
* @desc �A�N�V�����f�[�^�Q�̎擾
* @return �A�N�V�����f�[�^�Q
*/
std::vector<CAction*>* CGimmickPartsFactory::getActions(void)
{
	//�s����A�N�V�����Q���쐬
	return new std::vector<CAction*>();
}

/**
* @desc ���̃f�[�^�̎擾
* @return ���̃f�[�^
*/
CBody*	CGimmickPartsFactory::getBody(void)
{
	//���̃f�[�^�̍쐬
	return new CBody();
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̎擾
* @return �Փ˔���̈�f�[�^�Q
*/
std::vector<CCollisionArea*>* CGimmickPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}



//=======================================================
//
//�@�_���[�W�u���b�N�M�~�b�N�H��N���X
//
//=======================================================

/**
* @desc �R���X�g���N�^
*/
CDamageBlockGimmickFactory::CDamageBlockGimmickFactory(int type):m_type(type)
{

}

/**
* @desc �f�X�g���N�^
*/
CDamageBlockGimmickFactory::~CDamageBlockGimmickFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CDamageBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CDamageBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_DAMAGEBLOCK_GIMMICK);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CDamageBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//�A�j���[�V�����f�[�^�Q�̎擾
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//�����A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipNotAnimation());


	switch ((TYPE)this->m_type)
	{
	case TYPE::LEFT:	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
						(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));
						break;

	case TYPE::UP:		//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
						(*pAnimations)[0]->addChipData(new CChip(32, 0, 32, 32));
						break;

	case TYPE::RIGHT:	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
						(*pAnimations)[0]->addChipData(new CChip(64, 0, 32, 32));
						break;

	case TYPE::DOWN:	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
						(*pAnimations)[0]->addChipData(new CChip(96, 0, 32, 32));
						break;
	}

	
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CDamageBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CDamageBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CDamageBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CDamageBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//��̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	//��_�̐ݒ�
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 ����������
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CDamageBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
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
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}

//=======================================================
//
// �M�~�b�N�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CRollBlockGimmickCreateFactory::CRollBlockGimmickCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CRollBlockGimmickCreateFactory::~CRollBlockGimmickCreateFactory()
{

}

/**
* @desc �M�~�b�N�L�����N�^�[�̐���
* @return �M�~�b�N�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CGimmickCharacter*  CRollBlockGimmickCreateFactory::createGimmick(void)
{
	//�M�~�b�N�L�����N�^�[�̐���
	CGimmickCharacter* pCharacter = CRollBlockGimmickCharacter::create();

	//�M�~�b�N�L�����N�^�[���i�����H��̐���
	CGimmickPartsFactory factory;

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	pCharacter->addAnimations(factory.getAnimations());
	//�ړ��f�[�^�̐ݒ�
	pCharacter->addMove(factory.getMove());
	//�������Z�f�[�^�Q�̐ݒ�
	pCharacter->addPhysicals(factory.getPhysicals());
	//�A�N�V�����f�[�^�Q�̐ݒ�
	pCharacter->addActions(factory.getActions());
	//���̃f�[�^�̐ݒ�
	pCharacter->addBody(factory.getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}



//=======================================================
//
//�@���u���b�N�M�~�b�N�H��N���X
//
//=======================================================

/**
* @desc �R���X�g���N�^
*/
CRollBlockGimmickFactory::CRollBlockGimmickFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CRollBlockGimmickFactory::~CRollBlockGimmickFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CRollBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CRollBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_ROLLBLOCK_GIMMICK);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CRollBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//�A�j���[�V�����f�[�^�Q�̎擾
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//�����A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipNotAnimation());

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));

	//�����A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipAnimation(10,4,true));
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[1]->addChipData(new CChip(0, 0, 32, 32));
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CRollBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CRollBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CRollBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CRollBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//��̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	//��_�̐ݒ�
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 ����������
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CRollBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
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
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}

//=======================================================
//
// �M�~�b�N�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CTikuwaBlockGimmickCreateFactory::CTikuwaBlockGimmickCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CTikuwaBlockGimmickCreateFactory::~CTikuwaBlockGimmickCreateFactory()
{

}

/**
* @desc �M�~�b�N�L�����N�^�[�̐���
* @return �M�~�b�N�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CGimmickCharacter*  CTikuwaBlockGimmickCreateFactory::createGimmick(void)
{
	//�M�~�b�N�L�����N�^�[�̐���
	CGimmickCharacter* pCharacter = CTikuwaBlockGimmickCharacter::create();

	//�M�~�b�N�L�����N�^�[���i�����H��̐���
	CGimmickPartsFactory factory;

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	pCharacter->addAnimations(factory.getAnimations());
	//�ړ��f�[�^�̐ݒ�
	pCharacter->addMove(factory.getMove());
	//�������Z�f�[�^�Q�̐ݒ�
	pCharacter->addPhysicals(factory.getPhysicals());
	//�A�N�V�����f�[�^�Q�̐ݒ�
	pCharacter->addActions(factory.getActions());
	//���̃f�[�^�̐ݒ�
	pCharacter->addBody(factory.getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}


//=======================================================
//
//�@������u���b�N�M�~�b�N�H��N���X
//
//=======================================================

/**
* @desc �R���X�g���N�^
*/
CTikuwaBlockGimmickFactory::CTikuwaBlockGimmickFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CTikuwaBlockGimmickFactory::~CTikuwaBlockGimmickFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CTikuwaBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CTikuwaBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_TIKUWABLOCK_GIMMICK);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CTikuwaBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//�A�j���[�V�����f�[�^�Q�̎擾
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//�����A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipNotAnimation());

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CTikuwaBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CTikuwaBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CTikuwaBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-16, 16, 16, -16);
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CTikuwaBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

}
/**
* @desc	 ����������
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CTikuwaBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
{
	//��Ԃ̐ݒ�
	pCharacter->m_state = 0;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pCharacter->m_isAlive = true;

	//�ʒu�𔽉f
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//��_��ݒ�
	((CTikuwaBlockGimmickCharacter*)pCharacter)->m_vec2BasePosition = pCharacter->getPosition();

	

	//�`�b�v�f�[�^�𔽉f
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}


//=======================================================
//
// �M�~�b�N�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CNoteBlockGimmickCreateFactory::CNoteBlockGimmickCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CNoteBlockGimmickCreateFactory::~CNoteBlockGimmickCreateFactory()
{

}

/**
* @desc �M�~�b�N�L�����N�^�[�̐���
* @return �M�~�b�N�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CGimmickCharacter*  CNoteBlockGimmickCreateFactory::createGimmick(void)
{
	//�M�~�b�N�L�����N�^�[�̐���
	CGimmickCharacter* pCharacter = CNoteBlockGimmickCharacter::create();

	//�M�~�b�N�L�����N�^�[���i�����H��̐���
	CGimmickPartsFactory factory;

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	pCharacter->addAnimations(factory.getAnimations());
	//�ړ��f�[�^�̐ݒ�
	pCharacter->addMove(factory.getMove());
	//�������Z�f�[�^�Q�̐ݒ�
	pCharacter->addPhysicals(factory.getPhysicals());
	//�A�N�V�����f�[�^�Q�̐ݒ�
	pCharacter->addActions(factory.getActions());
	//���̃f�[�^�̐ݒ�
	pCharacter->addBody(factory.getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}


//=======================================================
//
//�@���˂�u���b�N�M�~�b�N�H��N���X
//
//=======================================================

/**
* @desc �R���X�g���N�^
*/
CNoteBlockGimmickFactory::CNoteBlockGimmickFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CNoteBlockGimmickFactory::~CNoteBlockGimmickFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CNoteBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNoteBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_NOTEBLOCK_GIMMICK);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNoteBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//�A�j���[�V�����f�[�^�Q�̎擾
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//�����A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipAnimation(10,4,true));

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNoteBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNoteBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNoteBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CNoteBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//��̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	//��_�̐ݒ�
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 ����������
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CNoteBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
{
	//��Ԃ̐ݒ�
	pCharacter->m_state = 0;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pCharacter->m_isAlive = true;

	//�ʒu�𔽉f
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	((CNoteBlockGimmickCharacter*)pCharacter)->m_vec2BasePosition = pCharacter->getPosition();

	//�`�b�v�f�[�^�𔽉f
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}

//=======================================================
//
// �M�~�b�N�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CHatenaBlockGimmickCreateFactory::CHatenaBlockGimmickCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CHatenaBlockGimmickCreateFactory::~CHatenaBlockGimmickCreateFactory()
{

}

/**
* @desc �M�~�b�N�L�����N�^�[�̐���
* @return �M�~�b�N�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CGimmickCharacter*  CHatenaBlockGimmickCreateFactory::createGimmick(void)
{
	//�M�~�b�N�L�����N�^�[�̐���
	CGimmickCharacter* pCharacter = CHatenaBlockGimmickCharacter::create();

	//�M�~�b�N�L�����N�^�[���i�����H��̐���
	CGimmickPartsFactory factory;

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	pCharacter->addAnimations(factory.getAnimations());
	//�ړ��f�[�^�̐ݒ�
	pCharacter->addMove(factory.getMove());
	//�������Z�f�[�^�Q�̐ݒ�
	pCharacter->addPhysicals(factory.getPhysicals());
	//�A�N�V�����f�[�^�Q�̐ݒ�
	pCharacter->addActions(factory.getActions());
	//���̃f�[�^�̐ݒ�
	pCharacter->addBody(factory.getBody());
	//�Փ˔���f�[�^�Q�̐ݒ�
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}


//=======================================================
//
//�@�L�����N�^�[���o������u���b�N�M�~�b�N�H��N���X
//
//=======================================================

/**
* @desc �R���X�g���N�^
*/
CHatenaBlockGimmickFactory::CHatenaBlockGimmickFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CHatenaBlockGimmickFactory::~CHatenaBlockGimmickFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CHatenaBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CHatenaBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_HATENABLOCK_GIMMICK);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CHatenaBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//�A�j���[�V�����f�[�^�Q�̎擾
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//�ʏ�A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipAnimation(10,4,true));

	//�ʏ�A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));

	//�Փˌ�A�j���[�V�����̐ݒ�
	pAnimations->push_back(new CChipNotAnimation());

	//�Փˌ�A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pAnimations)[1]->addChipData(new CChip(128, 0, 32, 32));

}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CHatenaBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CHatenaBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CHatenaBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CHatenaBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//��̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//�}�b�v�`�b�v�E�̏Փ˂����ۂ̃C�x���g��ݒ�
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pCollisionTerritory);


	//��_�̐ݒ�
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//��ʒ[�̏Փ˔����Ԃ����t����
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 ����������
* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CHatenaBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
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
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}


//=======================================================
//
// �M�~�b�N�L�����N�^�[�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
//�V���O���g���C���X�^���X
CGimmickFactoryManager* CGimmickFactoryManager::m_pSharedManager = NULL;

/*
* @desc �R���X�g���N�^
*/
CGimmickFactoryManager::CGimmickFactoryManager()
{
	//�M�~�b�N�H��Q�̐���
	this->m_pFactories = new std::map<GIMMICK_TYPE, CGimmickFactory*>();

	//�H��𐶐����Ď��t���Ă���
	//�A�z�z��̃L�[�̓}�b�v�`�b�vID�ɐݒ�
	//�N���{�[�����H��̎��t��
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_LEFT] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_LEFT);
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_RIGHT] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_RIGHT);
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_UP] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_UP);
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_DOWN] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_DOWN);
	(*this->m_pFactories)[GIMMICK_TYPE::ROLL] = new CRollBlockGimmickFactory();
	(*this->m_pFactories)[GIMMICK_TYPE::TIKUWA] = new CTikuwaBlockGimmickFactory();
	(*this->m_pFactories)[GIMMICK_TYPE::NOTE] = new CNoteBlockGimmickFactory();
	(*this->m_pFactories)[GIMMICK_TYPE::HATENA] = new CHatenaBlockGimmickFactory();
}

/**
* @desc �f�X�g���N�^
*/
CGimmickFactoryManager::~CGimmickFactoryManager()
{
	//�M�~�b�N�����H��Q�̔j��
	std::map<GIMMICK_TYPE, CGimmickFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//�M�~�b�N�����H��Q�̔j��
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc �V���O���g���F�F�C���X�^���X�̎擾
* @return �V���O���g���C���X�^���X
*/
CGimmickFactoryManager* CGimmickFactoryManager::getInstance(void)
{
	if (CGimmickFactoryManager::m_pSharedManager == NULL)
	{
		CGimmickFactoryManager::m_pSharedManager = new CGimmickFactoryManager();
	}
	return CGimmickFactoryManager::m_pSharedManager;
}

/**
* @desc �M�~�b�N�L�����N�^�[�𐶐�
* @param �����^�C�v
* @param �������WX
* @param �������WY
* @param �M�~�b�N�̔��˕����̃x�N�g��(�M�~�b�N�̌����x�N�g��)
*/
CGimmickCharacter* CGimmickFactoryManager::create(GIMMICK_TYPE type, float posX, float posY)
{

	return (*this->m_pFactories)[type]->create(posX, posY);

}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CGimmickFactoryManager::removeInstance()
{
	SAFE_DELETE(CGimmickFactoryManager::m_pSharedManager);
}
