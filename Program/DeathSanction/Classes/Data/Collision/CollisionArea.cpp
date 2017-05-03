#include "CollisionArea.h"
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"


/**
* @desc �C�x���g�R�[���o�b�N�̌Ăяo��
* @param �Ăяo���C���X�^���X
* �}�b�v�`�b�v�̍ۂ̓u���b�N�^�C�v���C�x���g�Ƃ��ēn����
* ��ʒ[�ȂǂɃC�x���g�͑��݂��Ȃ��̂�
* �f�t�H���g�l�Ƃ��ĂO��ݒ肵�Ă���
*/
void CCollisionTerritory::callEventCallback(CCharacter* pChara, int event)
{
	//�C�x���g�R�[���o�b�N���ݒ肳��Ă��Ȃ���΁A
	//�܂�NULL�Ȃ�Ăяo�����s��Ȃ�
	if (this->m_pEventCallback != NULL)
	{
		//�C�x���g�R�[���o�b�N���Ăяo�������o�֐�����������Ă���
		//�L�����N�^�[����Ăяo�����s��
		(pChara->*m_pEventCallback)(event);
	}
}


//======================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryEndOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//���Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{
		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_BOTTOM;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.y -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;

		}
	}
}

//======================================
// ��ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryEndOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//��Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.y > 0.0f)
	{
		//��ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_TOP;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.y -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}


//======================================
// �E�ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryEndOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//��Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.x > 0.0f)
	{
		//��ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_RIGHT;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.x -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}

//======================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryEndOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//���Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.x < 0.0f)
	{
		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_LEFT;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.x -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}


//======================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �R���X�g���N�^
* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
*/
CCollisionTerritoryOutOfScreenBottom::CCollisionTerritoryOutOfScreenBottom()
	: CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
{

}

/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryOutOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//���Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{
		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}

//======================================
// ��ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �R���X�g���N�^
* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::TOP�ɐݒ肵�Ă���
*/
CCollisionTerritoryOutOfScreenTop::CCollisionTerritoryOutOfScreenTop()
	: CCollisionTerritory(TERRITORY_TYPE::TOP)
{

}

/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryOutOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//��Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.y > 0.0f)
	{
		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}


//======================================
// �E�ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �R���X�g���N�^
* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::RIGHT�ɐݒ肵�Ă���
*/
CCollisionTerritoryOutOfScreenRight::CCollisionTerritoryOutOfScreenRight()
	: CCollisionTerritory(TERRITORY_TYPE::RIGHT)
{
	
}

/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryOutOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	

	//�E�Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.x > 0.0f)
	{
		//�E�ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT * 3)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}


//======================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �R���X�g���N�^
* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::LEFT�ɐݒ肵�Ă���
*/
CCollisionTerritoryOutOfScreenLeft::CCollisionTerritoryOutOfScreenLeft()
	: CCollisionTerritory(TERRITORY_TYPE::LEFT)
{

}

/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryOutOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//���Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.x < 0.0f)
	{
		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}


//======================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryMapChipBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//���Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{

		//�Փ˂��Ă����_(�L�����N�^�[�̓_)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//�Փ˂��Ă���


			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapChipID != BLOCK_TYPE::NONE)
			{
				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara, (int)mapChipID);

				//�߂��ׂ��ʒu�̌v�Z

				//�^�C���T�C�Y�i32�C32�j
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@���@�u���b�N�����u���b�N�̍���
				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

				//�߂��ׂ��ʒu
				// �C���ʒu�i�L�����N�^�[���߂荞��ł���u���b�N�̏�̈ʒu�j= 
				// �L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@�{�@�u���b�N����[�ʒu��
				float boundary = pt.y - (blockPos + tileSize.height);

				//�ŏI�I�ɖ߂��l�i�߂荞�񂾕���߂��j
				pChara->m_pMove->m_pos.y -= boundary;

				//���Z�b�g����l
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;
			}
		}
		
		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) < WINDOW_BOTTOM)
		{
			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) - WINDOW_BOTTOM;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.y -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}

//======================================
// ��ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryMapChipTop::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//��Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.y > 0.0f)
	{

		//�Փ˂��Ă����_(�L�����N�^�[�̓_)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//�Փ˂��Ă���


			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapChipID != BLOCK_TYPE::NONE)
			{
				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara, (int)mapChipID);

				//�߂��ׂ��ʒu�̌v�Z

				//�^�C���T�C�Y�i32�C32�j
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̏�̃u���b�N�̈ʒu�@���@�u���b�N�����u���b�N�̍���
				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

				//�߂��ׂ��ʒu
				// �C���ʒu�i�L�����N�^�[���߂荞��ł���u���b�N�̉��̈ʒu�j= 
				// �L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@�{�@�u���b�N����[�ʒu��
				float boundary = pt.y - blockPos;

				//�ŏI�I�ɖ߂��l�i�߂荞�񂾕���߂��j
				pChara->m_pMove->m_pos.y -= boundary;

				//���Z�b�g����l
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;
			}
		}
	}
}

//======================================
// �E�ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryMapChipRight::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//��Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.x > 0.0f)
	{

		//�Փ˂��Ă����_(�L�����N�^�[�̓_)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//�Փ˂��Ă���


			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapChipID != BLOCK_TYPE::NONE)
			{

				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara, (int)mapChipID);

				//�߂��ׂ��ʒu�̌v�Z

				//�^�C���T�C�Y�i32�C32�j
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̏�̃u���b�N�̈ʒu�@���@�u���b�N�����u���b�N�̕�
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//�߂��ׂ��ʒu
				// �C���ʒu�i�L�����N�^�[���߂荞��ł���u���b�N�̉��̈ʒu�j= 
				// �L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@�{�@�u���b�N����[�ʒu��
				float boundary = pt.x - blockPos;

				//�ŏI�I�ɖ߂��l�i�߂荞�񂾕���߂��j
				pChara->m_pMove->m_pos.x -= boundary;

				//���Z�b�g����l
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}
	}
}

//======================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryMapChipLeft::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//��Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.x < 0.0f)
	{

		//�Փ˂��Ă����_(�L�����N�^�[�̓_)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//�Փ˂��Ă���


			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapChipID != BLOCK_TYPE::NONE)
			{
				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara, (int)mapChipID);

				//�߂��ׂ��ʒu�̌v�Z

				//�^�C���T�C�Y�i32�C32�j
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̏�̃u���b�N�̈ʒu�@���@�u���b�N�����u���b�N�̍���
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//�߂��ׂ��ʒu
				// �C���ʒu�i�L�����N�^�[���߂荞��ł���u���b�N�̉��̈ʒu�j= 
				// �L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@�{�@�u���b�N����[�ʒu��
				float boundary = pt.x - (blockPos + tileSize.width);
				
				//�ŏI�I�ɖ߂��l�i�߂荞�񂾕���߂��j
				pChara->m_pMove->m_pos.x -= boundary;

				//���Z�b�g����l
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}

		
	}
}


//======================================
// ��ʒ[�Ƃ̏Փ˔�����
//======================================
/**
* @desc �R���X�g���N�^
* @param �Փ˔���p���̃f�[�^
*/

CCollisionAreaEndOfScreen::CCollisionAreaEndOfScreen(CBody* pBody)
{
	cocos2d::Point pt;
	//Bottom
	pt.setPoint(0, pBody->m_bottom);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, pt));
	//Top
	pt.setPoint(0, pBody->m_top);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, pt));
	//Right
	pt.setPoint(pBody->m_right, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, pt));
	//Left
	pt.setPoint(pBody->m_left, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, pt));
}

/**
* @desc �Փ˔���
* @param �Փ˔���̃L�����N�^�[
*/
void CCollisionAreaEndOfScreen::collision(CCharacter* pChara)
{
	//�̈敪�J��Ԃ�
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//��_���J��Ԃ�
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//��_�̒��ɓo�^����Ă���Փ˔���̈�^�C�v����v�����炻�̊�_�ŏՓ˔�����s��
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara,pBasePt->m_pt);
			}
		}
		
	}
}


//======================================
// ��ʊO�Ƃ̏Փ˔�����
//======================================
//�R���X�g���N�^
CCollisionAreaOutOfScreen::CCollisionAreaOutOfScreen()
{

}


/**
* @desc �R���X�g���N�^
* @param �Փ˔���p���̃f�[�^
*/
CCollisionAreaOutOfScreen::CCollisionAreaOutOfScreen(CBody* pBody)
{
	cocos2d::Point pt;

	//Bottom
	pt.setPoint(0, pBody->m_top);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, pt));
	//Top
	pt.setPoint(0, pBody->m_bottom);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, pt));
	//Right
	pt.setPoint(pBody->m_left, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, pt));
	//Left
	pt.setPoint(pBody->m_right, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, pt));


	/*
//Bottom
	pt.setPoint(0, pBody->m_bottom);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, pt));
	//Top
	pt.setPoint(0, pBody->m_top);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, pt));
	//Right
	pt.setPoint(pBody->m_right, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, pt));
	//Left
	pt.setPoint(pBody->m_left, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, pt));
	*/
}


//�f�X�g���N�^
CCollisionAreaOutOfScreen::~CCollisionAreaOutOfScreen()
{

}

/**
* @desc �Փ˔���
* @param �Փ˔���̃L�����N�^�[
*/
void CCollisionAreaOutOfScreen::collision(CCharacter* pChara)
{
	//�̈敪�J��Ԃ�
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//��_���J��Ԃ�
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//��_�̒��ɓo�^����Ă���Փ˔���̈�^�C�v����v�����炻�̊�_�ŏՓ˔�����s��
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}

	}
}


/**
* @desc �Փ˔���
* @param �Փ˔���̃L�����N�^�[
*/
void CCollisionAreaMap::collision(CCharacter* pChara)
{
	//�̈敪�J��Ԃ�
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//��_���J��Ԃ�
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//��_�̒��ɓo�^����Ă���Փ˔���̈�^�C�v����v�����炻�̊�_�ŏՓ˔�����s��
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}
}

/**
* @desc �Փ˔���
* @param �Փ˔���̃L�����N�^�[
*/
void CCollisionAreaLine::collision(CCharacter* pChara)
{
	//�̈敪�J��Ԃ�
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//��_���J��Ԃ�
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//��_�̒��ɓo�^����Ă���Փ˔���̈�^�C�v����v�����炻�̊�_�ŏՓ˔�����s��
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}
}


//======================================
// ���ɂ��郉�C���Ƃ̏Փ˔���
//======================================
/**
* @desc �Փ˔���
* @param �ՓˑΏ�
* @param ��_
*/
void CCollisionTerritoryLineBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//���Ɉړ����Ă��邩�ǂ������`�F�b�N
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{
		enum LINE
		{
			FRONT = 0,
			CENTER = 1,
			BACK = 2,
		};

		float floatGround = 0.0f;

		switch (pChara->m_intCurrentLine)
		{
		case FRONT:		floatGround = 32.0f;
						break;
		case CENTER:
						floatGround = 96.0f;
						break;
		case BACK:		
						floatGround = 160.0f;
						break;
		}
		//���Ƀ��C���[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) < floatGround)
		{
			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) - floatGround;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.y -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}
//EOF