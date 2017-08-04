#include"PlayerAttack1Factory.h"


///////////////////////////////////////////////////////////////////////

/**
* @desc �R���X�g���N�^
*/
CPlayerAttack1Factory::CPlayerAttack1Factory()
{

}

/**
* @desc �f�X�g���N�^
*/
CPlayerAttack1Factory::~CPlayerAttack1Factory()
{

}

/**
* @desc	 �ړ��f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
* @param �������WX
* @param �������WY
*/
void CPlayerAttack1Factory::settingMove(CCharacter* pCharacter, float posX, float posY)
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
void CPlayerAttack1Factory::settingTexture(CCharacter* pCharacter)
{
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_ENEMY);
}
/**
* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CPlayerAttack1Factory::settingAnimations(CCharacter* pCharacter)
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
void CPlayerAttack1Factory::settingPhysicals(CCharacter* pCharacter)
{
	/*
	//�������Z�f�[�^�Q�̎擾
	pCharacter->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//�d�͉��Z�̐ݒ�
	pointerPhysical->push_back(new CPhysicalGravity());

	//�d�͉��Z�̐ݒ�
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
	*/
}
/**
* @desc	 �A�N�V�����f�[�^�Q��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CPlayerAttack1Factory::settingActions(CCharacter* pCharacter)
{
	/*
	//�A�N�V�����f�[�^�Q�̎擾
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionEnemyDead(2.0f, 6.0f);

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
	*/
}
/**
* @desc	 ���̃f�[�^��ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CPlayerAttack1Factory::settingBody(CCharacter* pCharacter)
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
void CPlayerAttack1Factory::settingCollisionAreas(CCharacter* pCharacter)
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
* @desc ��ԑJ�ڃ}�V���̐ݒ�
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CPlayerAttack1Factory::settingStateMachine(CCharacter* pCharacter)
{
	/*
	//�ҋ@���
	pCharacter->m_stateMachine->registerState((int)CPlayerAttack1Enemy::STATE::IDLE, new CPlayerAttack1StateIdle((CPlayerAttack1Enemy*)pCharacter));

	
	//���s���
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::WALK, new CPlayerStateWalk(pCharacter));

	//���C���A�b�v���
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_UP, new CPlayerStateLineUp(pCharacter));

	//���C���_�E�����
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_DOWN, new CPlayerStateLineDown(pCharacter));
	

	//������Ԃ̐ݒ�
	pCharacter->m_stateMachine->setStartState((int)CPlayerAttack1Enemy::STATE::IDLE);

	*/
}

/**
* @desc	 ����������
* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
*/
void CPlayerAttack1Factory::settingInitialize(CCharacter* pCharacter)
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
//EOF