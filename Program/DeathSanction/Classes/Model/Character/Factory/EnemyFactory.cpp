#include"EnemyFactory.h"



/**
* @desc �R���X�g���N�^
*/
CEnemyFactory::CEnemyFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CEnemyFactory::~CEnemyFactory()
{

}

/**
* @desc �G�L�����N�^�[�𐶐�
* @param �������WX
* @param �������WY
*/
CEnemyCharacter* CEnemyFactory::create(float posX, float posY)
{
	//�G�L�����N�^�[�̐���
	CEnemyCharacter* pCharacter = this->createEnemy();

	//�A�j���[�V�����f�[�^�Q�̐ݒ�
	this->settingAnimations(pCharacter);
	//�ړ��f�[�^�̐ݒ�
	this->settingMove(pCharacter,posX,posY);
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
// �G�L�����N�^�[�����N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CEnemyCreateFactory::CEnemyCreateFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CEnemyCreateFactory::~CEnemyCreateFactory()
{

}

/**
* @desc �G�L�����N�^�[�̐���
* @return �G�L�����N�^�[�̃C���X�^���X�̃A�h���X
*/
CEnemyCharacter*  CEnemyCreateFactory::createEnemy(void)
{
	//�G�L�����N�^�[�̐���
	CEnemyCharacter* pCharacter = CEnemyCharacter::create();

	//�G�L�����N�^�[���i�����H��̐���
	CEnemyPartsFactory factory;

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
CEnemyPartsFactory::CEnemyPartsFactory()
{

}
/**
* @desc �f�X�g���N�^
*/
CEnemyPartsFactory::~CEnemyPartsFactory()
{

}


/**
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove*	CEnemyPartsFactory::getMove(void)
{
	//�ړ��f�[�^�̍쐬
	return new CMove();
}


/**
* @desc ���̃f�[�^�̎擾
* @return ���̃f�[�^
*/
CBody*	CEnemyPartsFactory::getBody(void)
{
	//���̃f�[�^�̍쐬
	return new CBody();
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̎擾
* @return �Փ˔���̈�f�[�^�Q
*/
std::vector<CCollisionArea*>* CEnemyPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}




/**
* @desc �R���X�g���N�^
*/
CKuriboFactory::CKuriboFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CKuriboFactory::~CKuriboFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CKuriboFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);

	//�����x�̐ݒ�͌Œ�i�f�o�b�O�Ƃ��ăN���{�[�̑��x�͓������x�^���j
	pCharacter->getMove()->m_vel.set(-1.0f, 0.0f);

}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKuriboFactory::settingTexture(CEnemyCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_ENEMY);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKuriboFactory::settingAnimations(CEnemyCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(0, 0, 64, 64));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKuriboFactory::settingPhysicals(CEnemyCharacter* pCharacter)
{
	//�������Z�f�[�^�Q�̎擾
	pCharacter->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//�d�͉��Z�̐ݒ�
	pointerPhysical->push_back(new CPhysicalGravity());

	//�d�͉��Z�̐ݒ�
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKuriboFactory::settingActions(CEnemyCharacter* pCharacter)
{
	//�A�N�V�����f�[�^�Q�̎擾
	std::vector<CAction*>* pointerAction = new std::vector<CAction*>();

	//
	pointerAction->push_back(new CActionEnemyDead(2.0f, 6.0f));

	pCharacter->m_mapAction[pCharacter->m_intActionState] = pointerAction;
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKuriboFactory::settingBody(CEnemyCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-32, 32, 32, -32);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CKuriboFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());


	//��ʉ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pEndOfScreenArea);

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
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
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKuriboFactory::settingInitialize(CEnemyCharacter* pCharacter)
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
// �΃m�R�m�R�����H��N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CGreenNokoNokoFactory::CGreenNokoNokoFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CGreenNokoNokoFactory::~CGreenNokoNokoFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CGreenNokoNokoFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);

	//�����x�̐ݒ�
	pCharacter->getMove()->m_vel.set(-1.0f, 0.0f);

}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenNokoNokoFactory::settingTexture(CEnemyCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_NOKONOKO);

	//�������ɐݒ�
	pCharacter->setScale(-1.0f,-1.0f);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenNokoNokoFactory::settingAnimations(CEnemyCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipListAnimation(10, true);

	//���s�A�j���[�V����
	pointerAnimation->addChipData(new CChip(0, 0, 32, 54));
	pointerAnimation->addChipData(new CChip(32, 0, 32, 54));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenNokoNokoFactory::settingPhysicals(CEnemyCharacter* pCharacter)
{
	//�������Z�f�[�^�Q�̎擾
	pCharacter->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//�d�͉��Z�̐ݒ�
	pointerPhysical->push_back(new CPhysicalGravity());

	//�d�͉��Z�̐ݒ�
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenNokoNokoFactory::settingActions(CEnemyCharacter* pCharacter)
{
	//�A�N�V�����f�[�^�Q�̎擾
	std::vector<CAction*>* pointerAction = new std::vector<CAction*>();

	//�G���S�A�N�V�������O�ԖڂŐݒ�
	pointerAction->push_back(new CActionEnemyDead(2.0f, 6.0f));

	pCharacter->m_mapAction[pCharacter->m_intActionState] = pointerAction;
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenNokoNokoFactory::settingBody(CEnemyCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-16, 27, 16, -27);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CGreenNokoNokoFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());


	//��ʉ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pEndOfScreenArea);

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
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
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenNokoNokoFactory::settingInitialize(CEnemyCharacter* pCharacter)
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
// �΃p�^�p�^�����H��N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CGreenPataPataFactory::CGreenPataPataFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CGreenPataPataFactory::~CGreenPataPataFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CGreenPataPataFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenPataPataFactory::settingTexture(CEnemyCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_PATAPATA);

	//�e�N�X�`���̃f�t�H���g�̌������������ɐݒ�
	pCharacter->setScale(-1.0f, 1.0f);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenPataPataFactory::settingAnimations(CEnemyCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipListAnimation(10, true);

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(0, 0, 56, 56));
	pointerAnimation->addChipData(new CChip(56, 0, 56, 56));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenPataPataFactory::settingPhysicals(CEnemyCharacter* pCharacter)
{
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenPataPataFactory::settingActions(CEnemyCharacter* pCharacter)
{
	//�A�N�V�����f�[�^�Q�̎擾
	std::vector<CAction*>* pointerAction = new std::vector<CAction*>();

	//�G���S�A�N�V������ݒ�
	//�G�L�����N�^�[�̃A�N�V�����ɓG���S���G�����A�N�V���������t����i�m�R�m�R��ݒ�j
	pointerAction->push_back(new CActionEnemyDeadAndCreateEnemy((int)ENEMY_TYPE::NOKONOKO));

	//�㉺�ړ��A�N�V�����̎��t��
	//��_�������ʒu�ɐݒ肷��
	pointerAction->push_back(new CActionUpAndDownMove(pCharacter->m_pMove->m_pos, 100, 0.02f));

	pCharacter->m_mapAction[pCharacter->m_intActionState] = pointerAction;
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenPataPataFactory::settingBody(CEnemyCharacter* pCharacter)
{
	//���̃f�[�^�̎擾
	CBody* pBody = pCharacter->getBody();

	//���̃f�[�^�̐ݒ�
	pBody->set(-28, 28, 28, -28);


}

/**
* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
* @param �Փ˔���̈�f�[�^�Q
*/
void CGreenPataPataFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
{
	/*
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());


	//��ʉ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pEndOfScreenArea);

	//========================================
	// �}�b�v�Փˋ�Ԃ̐���
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�
	//���̃}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
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
	*/
}
/**
* @desc	 ����������
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CGreenPataPataFactory::settingInitialize(CEnemyCharacter* pCharacter)
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
// �L���[�����H��N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CKillerFactory::CKillerFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CKillerFactory::~CKillerFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CKillerFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX, posY);

	//�����x�̐ݒ�
	pCharacter->getMove()->m_vel.set(-3.0f, 0.0f);

}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerFactory::settingTexture(CEnemyCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_KILLER);

	//�������ɐݒ�
	pCharacter->setScale(-1.0f, -1.0f);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerFactory::settingAnimations(CEnemyCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(32, 0, 32, 32));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerFactory::settingPhysicals(CEnemyCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerFactory::settingActions(CEnemyCharacter* pCharacter)
{
	//�A�N�V�����f�[�^�Q�̎擾
	std::vector<CAction*>* pointerAction = new std::vector<CAction*>();

	pointerAction->push_back(new CActionEnemyDeadAndAddGravity(2.0f, 6.0f));

	pCharacter->m_mapAction[pCharacter->m_intActionState] = pointerAction;
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerFactory::settingBody(CEnemyCharacter* pCharacter)
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
void CKillerFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());

	//��ʉ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pEndOfScreenArea);
}
/**
* @desc	 ����������
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerFactory::settingInitialize(CEnemyCharacter* pCharacter)
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
// �L���[�����H��N���X
//
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CKillerBatteryFactory::CKillerBatteryFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CKillerBatteryFactory::~CKillerBatteryFactory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CKillerBatteryFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
{
	//�ړ��f�[�^�̎擾
	CMove* pMove = pCharacter->getMove();

	//�����ʒu�̐ݒ�
	pMove->m_pos.set(posX+16.0f, posY);
}
/**
* @desc	 �e�N�X�`���[��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerBatteryFactory::settingTexture(CEnemyCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_KILLER);

}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerBatteryFactory::settingAnimations(CEnemyCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pointerAnimation->addChipData(new CChip(0, 0, 32, 32));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 �������Z�f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerBatteryFactory::settingPhysicals(CEnemyCharacter* pCharacter)
{

}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerBatteryFactory::settingActions(CEnemyCharacter* pCharacter)
{
	std::vector<CAction*>* pointerAction = new std::vector<CAction*>();

	//
	pointerAction->push_back(new CActionEnemyDeadAndAddGravity(2.0f, 6.0f));

	pointerAction->push_back(new CActionIntervalCreateEnemy(
															(int)ENEMY_TYPE::KILLER,
															30,
															cocos2d::Point(-16.0f, 0.0f)));

	pCharacter->m_mapAction[pCharacter->m_intActionState] = pointerAction;
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerBatteryFactory::settingBody(CEnemyCharacter* pCharacter)
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
void CKillerBatteryFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
{
	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// �Փ˔����Ԃ̐���
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());

	//��ʉ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փˋ�Ԃ����t����
	pCollisionAreas->push_back(pEndOfScreenArea);
}
/**
* @desc	 ����������
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CKillerBatteryFactory::settingInitialize(CEnemyCharacter* pCharacter)
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
	this->m_pFactories = new std::map<ENEMY_TYPE, CEnemyFactory*>();

	//�H��𐶐����Ď��t���Ă���
	//�A�z�z��̃L�[�̓}�b�v�`�b�vID�ɐݒ�
	//�N���{�[�����H��̎��t��
	(*this->m_pFactories)[ENEMY_TYPE::KURIBO] = new CKuriboFactory();
	(*this->m_pFactories)[ENEMY_TYPE::NOKONOKO] = new CGreenNokoNokoFactory();
	(*this->m_pFactories)[ENEMY_TYPE::PATAPATA] = new CGreenPataPataFactory();
	(*this->m_pFactories)[ENEMY_TYPE::KILLERBATTERY] = new CKillerBatteryFactory();
	(*this->m_pFactories)[ENEMY_TYPE::KILLER] = new CKillerFactory();
}

/**
* @desc �f�X�g���N�^
*/
CEnemyFactoryManager::~CEnemyFactoryManager()
{
	//�G�����H��Q�̔j��
	std::map<ENEMY_TYPE, CEnemyFactory*>::iterator itr = this->m_pFactories->begin();

	while(itr != this->m_pFactories->end())
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
CEnemyCharacter* CEnemyFactoryManager::create(ENEMY_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX,posY);
}

/**
* @desc �V���O���g���C���X�^���X�̉��
*/
void CEnemyFactoryManager::removeInstance()
{
	SAFE_DELETE(CEnemyFactoryManager::m_pSharedManager);
}