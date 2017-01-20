#include "Map.h"
#include "Constants.h"
#include "Data\Collision\Collision.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"

/**
* @desc �^�C���̂Q�����z���̍��W���擾
* @param ��������_�Ƃ����z���̍��W�ʒu
*/
cocos2d::Point CMap::getTileCoord(cocos2d::Point pos)
{
	//�}�b�v�̌��_�ʒu
	cocos2d::Point pt = this->getPosition();

	//�}�b�v�^�C���T�C�Y
	cocos2d::Size tileSize = this->getTileSize();

	//�}�b�v�̔z��T�C�Y
	cocos2d::Size mapSize = this->getMapSize();

	int x = (pos.x + pt.x) / tileSize.width;
	int y = ((mapSize.height * tileSize.height) - pos.y) / tileSize.height;

	//���㌴�_(enchant.js)�̏ꍇ
	//int y = (pos_.y + this->getPosition().y)/this->getTileSize().height;

	return cocos2d::Point(x, y);
}

/**
* @desc �^�C���ʒu�̎擾
* @param ���������_�Ƃ��đΏۂ̍��W�ʒu
*/
cocos2d::Point CMap::getTilePosition(cocos2d::Point pos)
{
	//�}�b�v�̌��_�ʒu
	cocos2d::Point pt = this->getPosition();

	//�}�b�v�^�C���T�C�Y
	cocos2d::Size tileSize = this->getTileSize();

	int x = (pos.x + pt.x) / tileSize.width;
	int y = (pos.y + pt.y) / tileSize.height;

	return cocos2d::Point(x * tileSize.width, y * tileSize.height);
}

/**
* @desc �_�ƃ}�b�v�`�b�v�Ƃ̏Փ˔���
* @param �ΏۈʒuX
* @param �ΏۈʒuY
*/
bool CMap::hitTest(float posX, float posY)
{
	//�Ώۂ̏Փ˔���̓_
	CCollisionPoint cpt(cocos2d::Point(posX, posY));

	//�_�ƏՓ˂��Ă���}�b�v�`�b�v�̌��_�i�����̓_�j���擾
	cocos2d::Point basePoint = this->getTilePosition(cocos2d::Point(posX, posY));

	//�}�b�v�`�b�v�̈ʒu�i�}�b�v�`�b�v�̒��S�ʒu�j
	cocos2d::Point tilePos = cocos2d::Point(basePoint.x + 16.0f, basePoint.y + 16.0f);

	//(-16,16,16,-16)
	CCollisionRect crect(CBody(-16, 16, 16, -16), tilePos);

	//collision���g�p���Ĕ���
	return cpt.collision(&crect);
}

/**
* @desc�@�^�C���ԍ��̊m�F
* @param �Q�����z����X�ʒu
* @param �Q�����z����Y�ʒu
* @param ���C���[�^�C�v
* @return �u���b�N�^�C�v
*/
BLOCK_TYPE CMap::checkTile(float posX, float posY, LAYER_TYPE layerType)
{
	//���C���[���擾
	cocos2d::TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//�^�C���̂Q�����z���̍��W���擾
	cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(posX, posY));

	//�}�b�v�̔z��T�C�Y
	cocos2d::Size mapSize = this->getMapSize();

	////////
	//�^�C���̂Q�����z���̍��W��0�����܂��̓}�b�v�T�C�Y���傫���ꍇ
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false)
	{
		return BLOCK_TYPE::NONE;
	}

	//�}�b�v�`�b�v�f�[�^�̎擾
	return (BLOCK_TYPE)pLayer->getTileGIDAt(tileCoord);
}

/**
* @desc �^�C���̕ύX
* @param �ύX����}�b�v�`�b�vID
* @param �_���Փ˂��Ă���^�C���A���̓_��X���W
* @param �_���Փ˂��Ă���^�C���A���̓_��Y���W
* @param ���C���[�^�C�v
* @return true...����
*/
bool CMap::changeTile(int mapChipID, float posX, float posY, LAYER_TYPE layerType)
{
	//���C���[���擾
	cocos2d::TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//�^�C���̂Q�����z���̍��W���擾
	cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(posX, posY));

	//�}�b�v�̔z��T�C�Y
	cocos2d::Size mapSize = this->getMapSize();

	//////
	//�^�C���̂Q�����z���̍��W���O�����܂��̓}�b�v�T�C�Y���傫���ꍇ
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false)
	{
		return false;
	}

	//�}�b�v�`�b�v�f�[�^�̔��f
	pLayer->setTileGID(mapChipID, tileCoord);

	return true;
}

/**
* @desc �G�̏o������
* @return �G�̃^�C�v
*/
void CMap::checkEnemyLaunch(float posX, float posY)
{
	//���C���[�̈ʒu���擾
	cocos2d::Point pt = cocos2d::Point(posX,posY);

	//���C���[�̂��ʒu�ɉ�ʂ̉E�T�C�Y���𑫂����Ƃ�
	//�\������Ă����ʂ̉E�[�̈ʒu���擾�ł���
	float checkPosX = -pt.x + WINDOW_RIGHT;

	//�}�b�v�`�b�v�̃T�C�Y���擾(32,32)
	cocos2d::Size tileSize = this->getTileSize();

	//�^�C���̂Q�����z���̍��W���擾�iX���W�݂̂��`�F�b�N�j
	cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(checkPosX, 0.0f));

	//���ݎQ�ƒ��̓G�o�����C���̃`�F�b�N
	if (this->m_lauchEnemyLine == tileCoord.x)
	{
		//�����珇�Ƀ^�C���T�C�Y���Â^�C�����`�F�b�N���Ă���
		for (float y = tileSize.height * 0.5f; y < WINDOW_TOP; y += tileSize.height)
		{
			//�`�F�b�N����^�C���̍��W��ݒ�ix�͌Œ��y���W���`�F�b�N���Ă����j
			cocos2d::Point tilePos(checkPosX, y);

			//���̂����W�̂Q�����z���̂��ʒu�ɂ���S�Ẵ^�C�����擾
			//���̃^�C���̃^�C���^�C�v�i���G�^�C�v�j���擾
			ENEMY_TYPE eneType = (ENEMY_TYPE)this->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_ENEMY);

			//�G�̃^�C�v��NONE����Ȃ�������o��
			if (eneType != ENEMY_TYPE::NONE)
			{
				//�G�o���f�[�^�i�o���̏��j�̐���
				CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
					eneType,
					tilePos
				);

				if (pLaunchData)
				{
					//�G�o����̓G�o�����C���[�̃^�C�����폜
					this->removeLaunchEnemyBlock(pLaunchData);

					//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
					CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

					//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
					CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

					return;
				}
			}
		}
		//�G�o�����C���̍X�V
		this->m_lauchEnemyLine++;
	}
}

/**
* @desc �M�~�b�N�̏o������
*/
void CMap::checkGimmickLaunch(float posX, float posY)
{
	while (this->m_lauchGimmickLine < this->m_lauchEnemyLine)
	{
		//���C���[�̈ʒu���擾
		cocos2d::Point pt = cocos2d::Point(posX, posY);

		//�}�b�v�`�b�v�̃T�C�Y���擾(32,32)
		cocos2d::Size tileSize = this->getTileSize();

		float checkPosX = 0.0f;


		if (tileSize.width * this->m_lauchGimmickLine >= WINDOW_RIGHT)
		{
			checkPosX = -pt.x + WINDOW_RIGHT;
		}
		else
		{	
			checkPosX = -pt.x + this->m_lauchGimmickLine * tileSize.width;
		}


		//�^�C���̂Q�����z���̍��W���擾�iX���W�݂̂��`�F�b�N�j
		cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(checkPosX, 0.0f));

		//���ݎQ�ƒ��̓G�o�����C���̃`�F�b�N
		if (this->m_lauchGimmickLine == tileCoord.x)
		{
			//�����珇�Ƀ^�C���T�C�Y���Â^�C�����`�F�b�N���Ă���
			for (float y = tileSize.height * 0.5f; y < WINDOW_TOP; y += tileSize.height)
			{
				//�`�F�b�N����^�C���̍��W��ݒ�ix�͌Œ��y���W���`�F�b�N���Ă����j
				cocos2d::Point tilePos(checkPosX, y);

				//���̂����W�̂Q�����z���̂��ʒu�ɂ���S�Ẵ^�C�����擾
				//���̃^�C���̃^�C���^�C�v�i���G�^�C�v�j���擾
				GIMMICK_TYPE gimmickType = (GIMMICK_TYPE)this->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_GIMMICK);

				//�G�̃^�C�v��NONE����Ȃ�������o��
				if (gimmickType != GIMMICK_TYPE::NONE)
				{
					//�G�o���f�[�^�i�o���̏��j�̐���
					CGimmickLaunchData* pLaunchData = new CGimmickLaunchData(
						gimmickType,
						tilePos
					);

					if (pLaunchData)
					{
						//�G�o����̓G�o�����C���[�̃^�C�����폜
						this->removeLaunchGimmickBlock(pLaunchData);

						//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
						CGimmickLaunchTrigger* pTrigger = new CGimmickLaunchTrigger(pLaunchData);

						//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
						CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

						
					}
				}
			}
			//�M�~�b�N�o�����C���̍X�V
			this->m_lauchGimmickLine++;
		}
	}
}



/**
* @desc �G�o����̓G�o�����C���[�̃^�C���̍폜
* @param �G�o���f�[�^
*/
void CMap::removeLaunchEnemyBlock(CEnemyLaunchData* pLaunchData)
{
	//�o�������ꏊ�̓G�o�����C���[�̃}�b�v�`�b�v��ENEMY_TYPE::NONE�ɂ���
	this->changeTile((int)ENEMY_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::LAUNCH_ENEMY);
}

/**
* @desc �M�~�b�N�o����̓G�o�����C���[�̃^�C���̍폜
* @param �M�~�b�N�o���f�[�^
*/
void CMap::removeLaunchGimmickBlock(CGimmickLaunchData* pLaunchData)
{
	//�o�������ꏊ�̃M�~�b�N�o�����C���[�̃}�b�v�`�b�v��GIMMICK_TYPE::NONE�ɂ���
	this->changeTile((int)GIMMICK_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::LAUNCH_GIMMICK);
}




//=============================================================
// �}�b�v�Ǘ��N���X
//=============================================================

//���L�C���X�^���X
CMapManager* CMapManager::m_pSharedMapManager = NULL;


//�R���X�g���N�^
CMapManager::CMapManager()
{

}

//�R���X�g���N�^
CMapManager::CMapManager(const CMapManager& customMapMgr_)
{

}

//���L�C���X�^���X�̎擾
CMapManager* CMapManager::getInstance()
{
	if (CMapManager::m_pSharedMapManager == NULL)
	{
		CMapManager::m_pSharedMapManager = new CMapManager();
	}
	return CMapManager::m_pSharedMapManager;
}

//�f�X�g���N�^
CMapManager::~CMapManager()
{

}

//�j��
void CMapManager::removeInstance()
{
	SAFE_DELETE(CMapManager::m_pSharedMapManager);
}

//�}�b�v�̐���
CMap* CMapManager::createMap(const std::string& fileName_)
{
	//���ɐ�������Ă����琶������Ă�����̂�Ԃ�
	if (this->m_pMap != NULL)
	{
		CCLOG("���ɐ�������Ă��܂�");
		return this->m_pMap;
	}

	//�}�b�v�N���X�̐���
	this->m_pMap = CMap::create(fileName_);

	if (this->m_pMap == NULL)
	{
		CCLOG("�}�b�v�̐����Ɏ��s���܂���!!");
		return NULL;
	}

	//�����ʒu�̐ݒ�
	this->m_pMap->setPosition(0.0f, 0.0f);

	//���t�����Ă���S�Ẵ^�C���̃G�C���A�X�̃f�t�H���g���A���`�G�C���A�X�ɐݒ�
	//������h�~
	for (const auto& child : this->m_pMap->getChildren())
	{
		static_cast<cocos2d::SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
	}

	return this->m_pMap;
}

//�}�b�v�̎擾
CMap* CMapManager::getMap()
{
	return this->m_pMap;
}
