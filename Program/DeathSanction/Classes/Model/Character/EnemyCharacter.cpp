//#include "EnemyCharacter.h"
//#include "Lib\Input\InputManager.h"
//#include "Model\Map\Map.h"
//
////�R���X�g���N�^
//CEnemyCharacter::CEnemyCharacter()
//{
//	//�L�����N�^�[�^�C�v��G�L�����N�^�[�ɐݒ�
//	this->m_charaType = CHARACTER_TYPE::ENEMY;
//
//}
//
////�f�X�g���N�^
//CEnemyCharacter::~CEnemyCharacter()
//{
//
//}
//
////����������
//bool CEnemyCharacter::init()
//{
//	//�L�����N�^�[�N���X�̏�����
//	if (CCharacter::init() == false)
//	{
//		CCLOG("�v���C���[�L�����N�^�[�������Ɏ��s");
//		return false;
//	}
//
//	return true;
//}
//
///**
//* @desc�@����������
//* @param �����ʒuX
//* @param �����ʒuY
//*/
//bool CEnemyCharacter::init(float posX, float posY)
//{
//	//�L�����N�^�[�N���X�̏�����
//	if (CCharacter::init() == false)
//	{
//		CCLOG("�G�L�����N�^�[�������Ɏ��s");
//		return false;
//	}
//	return true;
//}
//
//
////�ړ�����
//void CEnemyCharacter::moveFunction(float deltaTime)
//{
//	// �A�N�V����
//	if (this->m_mapAction[this->m_intActionState])
//	{
//		std::map<int, CAction*>::iterator itaratorAction = this->m_mapAction[this->m_intActionState]->begin();
//
//		while (itaratorAction != this->m_mapAction[this->m_intActionState]->end())
//		{
//			if (itaratorAction->second)
//			{
//				itaratorAction->second->update(this);
//			}
//			itaratorAction++;
//		}
//	}
//
//	//�����v�Z
//	if (this->m_mapPhysical[this->m_intPhysicalState])
//	{
//		for (CPhysical* pointerPhysical : (*this->m_mapPhysical[this->m_intPhysicalState]))
//		{
//			pointerPhysical->update(deltaTime,this->m_pMove);
//		}
//	}
//
//	//�ړ��v�Z
//	this->m_pMove->moveBy(deltaTime);
//}
//
////�A�j���[�V��������
//void CEnemyCharacter::animationFunction(float deltaTime)
//{
//	//�A�j���[�V����
//	if (this->m_mapAnimation[this->m_intAnimationState])
//	{
//		this->m_mapAnimation[this->m_intAnimationState]->update();
//	}
//}
//
///**
//* @desc ��ԂƂ̏Փ˔��菈��
//*/
//void CEnemyCharacter::collision()
//{
//	//����ł������΂�
//	if (this->m_isAlive == false)
//	{
//		return;
//	}
//
//	//��ԂƂ̏Փ˔�����s��
//	for (CCollisionArea* pArea : (*this->m_pCollisionAreas))
//	{
//		pArea->collision(this);
//	}
//}
//
///*
//* @desc ��ʔ͈͒[���菈��
//* @tips �܂��폜�̏������쐬���Ă��Ȃ��̂ŉ�ʉ��Ŏ~�߂鏈���̂ݎ������Ă���
//
//void CEnemyCharacter::endOfScreen()
//{
//	cocos2d::Vec2* pPos = &this->m_pMove->m_pos;
//	cocos2d::Vec2* pVel = &this->m_pMove->m_vel;
//	cocos2d::Vec2* pAccele = &this->m_pMove->m_accele;
//
//	//��ʉ��Ŏ~�߂�悤�ɂ���
//	if (pVel->y < 0.0f && pPos->y + this->m_pBody->m_bottom < WINDOW_BOTTOM)
//	{
//		//�ݒ�C���l
//		float boundary = (pPos->y + this->m_pBody->m_bottom) - WINDOW_BOTTOM;
//		pPos->y -= boundary;
//
//		//���x�Ɖ����x���O�ɂ���
//		pVel->y = 0.0f;
//		pAccele->y = 0.0f;
//	}
//}
//*/
///**
//* @desc ��ԃ`�F�b�N
//* @tips �l���`�F�b�N���Č��݂̏�Ԃ�ύX����
//*/
//void CEnemyCharacter::checkState(float deltaTime)
//{
//	//�����̔���
//	if (this->m_pMove->m_vel.x != 0)
//	{
//		if (this->m_pMove->m_vel.x > 0)
//		{
//			//�E�����ɐݒ�
//			this->setScale(1.0f, 1.0f);
//		}
//		else
//		{
//			//�������ɐݒ�
//			this->setScale(-1.0f, 1.0f);
//		}
//	}
//}
//
////���f����
//void CEnemyCharacter::applayFunction()
//{
//	//�ʒu�f�[�^�𔽉f
//	this->setPosition(this->m_pMove->m_pos);
//
//	//�`�b�v�f�[�^�𔽉f
//	this->setTextureRect(this->m_mapAnimation[this->m_intAnimationState]->getCurrentChip());
//
//}
//
//
///**
//* @desc �L�����N�^�[�P�̂Ƃ̏Փ˔��菈��
//* @param �L�����N�^�[�̃A�h���X
//* @return true...�Փ˂���
//*/
//bool CEnemyCharacter::collision(CCharacter* pChara)
//{
//	return true;
//}
//
//
///**
//* @desc �Փ˔����̏���
//* @param �Փ˂��Ă����L�����N�^-
//*/
//void CEnemyCharacter::hits(CCharacter* pChara)
//{
//	//����ł������΂�
//	if (this->m_isAlive == false)
//	{
//		return;
//	}
//
//	switch (pChara->m_charaType)
//	{
//	//�v���C���[�������ꍇ
//	case CHARACTER_TYPE::PLAYER:	this->hitsPlayerCharacter(pChara);
//									break;
//
//	//�e�������ꍇ
//	case CHARACTER_TYPE::BULLET:	this->hitsBulletCharacter(pChara);
//									break;
//	default:break;
//	}
//
//}
//
//
///**
//* @desc �v���C���[�Ƃ̏Փ˔����̏���
//* @param �Փ˂��Ă����L�����N�^-
//*/
//void CEnemyCharacter::hitsPlayerCharacter(CCharacter* pChara)
//{
//	//�v���C���[�̑����̈ʒu
//	float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;
//
//	//�G�̒��S�ʒu
//	float enePosY = this->m_pMove->m_pos.y;
//
//	//�G���ォ�ǂ���
//	float posY = playerFeetPosY - enePosY;
//	if (posY > 0.0f)
//	{
//	
//		//�G�̎��S�t���O�𗧂Ă�
//		//�܂萶���Ă����邩����ł��邩�̃t���O��false������
//		this->m_isAlive = false;
//
//		//�G���S�A�N�V�������N������
//		(*this->m_mapAction[this->m_intActionState])[0]->start();
//
//		//=====================================================================
//		// �߂荞�񂾕��߂�
//		//=====================================================================
//		//�߂荞�񂾕��̌v�Z
//		float boundary = playerFeetPosY - (this->m_pMove->m_pos.y + this->m_pBody->m_top);
//
//		//�ŏI�G�ɖ߂��l
//		pChara->m_pMove->m_pos.y -= boundary;
//
//		//=====================================================================
//		// �W�����v�A�N�V�����̍ċN��
//		//=====================================================================
//		//�W�����v�A�N�V�����̍ċN��
//		(*pChara->m_mapAction[pChara->m_intActionState])[0]->restart(pChara);
//
//	}
//	else
//	{
//	
//	}
//}
//
///**
//* @desc �e�Ƃ̏Փ˔����̏���
//* @param �Փ˂��Ă����L�����N�^-
//*/
//void CEnemyCharacter::hitsBulletCharacter(CCharacter* pChara)
//{
//	//�e�̗L���t���O��������
//	pChara->m_activeFlag = false;
//
//	//�G�̎��S�t���O�𗧂Ă�
//	//�܂萶���Ă����邩����ł��邩�̃t���O��false������
//	this->m_isAlive = false;
//
//	//�G���S�A�N�V�������N������
//	(*this->m_mapAction[this->m_intActionState])[0]->start();
//}
//
//
///**
//* @desc �}�b�v�Ƃ̏Փ˔��菈��
//* @return true...�Փ˂���
//
//bool CEnemyCharacter::collisionMap()
//{
//	//�}�b�v���擾
//	CMap* pMap = CMapManager::getInstance()->getMap();
//
//	//��ԂŔ��肷��̂ň�U��Ԃ̃`�F�b�N���s��
//	this->checkState();
//
//	//���Ɉړ����Ă���ꍇ�ɉ��ɏ�Q�������������ɖ߂�
//	if (this->m_pMove->m_vel.y < 0)
//	{
//		//�L�����N�^�[�̒��S�ʒu����^���ɂ���_�̍��W���擾
//		cocos2d::Point pt(this->m_pMove->m_pos.x, this->m_pMove->m_pos.y + this->m_pBody->m_bottom);
//
//		/*
//		* �_����ʂ̂ǂ̍��W�ɂ��邩�𒲂ׂĂ��̍��W��
//		* �}�b�v�`�b�v�����݂��邩�𒲂׃}�b�v�`�b�v�����݂��Ă�����
//		* true��Ԃ�
//		
//		if (pMap->hitTest(pt.x, pt.y))
//		{
//			//�u���b�N�̃^�C�v���擾
//			BLOCK_TYPE mapChipID = pMap->checkTile(pt.x,pt.y);
//
//			if (mapChipID != BLOCK_TYPE::NONE)
//			{
//				//�^�C���̃T�C�Y
//				cocos2d::Size tileSize = pMap->getTileSize();
//
//				//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@���@�u���b�N�̐����u���b�N�̍���
//				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;
//
//				//�C���ʒu�i�L�����N�^�[���߂荞��ł���u���b�N�̏�̈ʒu�j= 
//				//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@�{�@�u���b�N�P�� - �ʒuy
//				float boudary = (pt.y) - (blockPos + tileSize.height);
//
//				//�߂荞��ł��镪���C��
//				this->m_pMove->m_pos.y -= boudary;
//
//				//���x�Ɖ����x���O�ɂ���
//				this->m_pMove->m_vel.y		= 0.0f;
//				this->m_pMove->m_accele.y	= 0.0f;
//			}
//		}
//	}
//	return true;
//}
//*/