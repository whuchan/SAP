#pragma once

#include <stdio.h>
#include "cocos2d.h"

//================================================================
// �u���b�N�i�}�b�v�`�b�v�j���
// 
//================================================================
enum class BLOCK_TYPE : int
{
	NONE = 0,//��������
};

//================================================================
// �G�̎��
// �u���b�N�ԍ��Ɉˑ�
//================================================================
enum class ENEMY_TYPE :int
{
	NONE			= 0,		//�����Ȃ�
	HENCHMAN_TYPE_A = 102,	//�N���{�[
	LEATHERFACE		= 108,//�m�R�m�R
	PATAPATA		= 109,//�p�^�p�^
	KILLERBATTERY	= 124,//�L���[�C��
	KILLER			= 1124,//�L���[
};

//================================================================
// �M�~�b�N�̎��
//================================================================
enum class GIMMICK_TYPE :int
{
	NONE		= 0,		//�����Ȃ�
	DAMEGE_LEFT	= 146,		//�_���[�W��
	DAMEGE_UP	= 147,		//�_���[�W��
	DAMEGE_RIGHT= 148,		//�_���[�W�E
	DAMEGE_DOWN = 149,		//�_���[�W��
	ROLL		= 156,		//���
	TIKUWA		= 157,		//������
	NOTE		= 158,		//���˂�
	HATENA		= 159,		//�L�����N�^�[�o��
};

//================================================================
// �_���[�W�̎��
// �u���b�N�ԍ��Ɉˑ�
//================================================================
enum class DAMAGE_TYPE :int
{
	NONE = 0,		//�����Ȃ�
	PLAYER_ATTACK_1 = 1,
};

//================================================================
// �G�t�F�N�g�̎��
// �u���b�N�ԍ��Ɉˑ�
//================================================================
enum class EFFECT_TYPE :int
{
	NONE = 0,		//�����Ȃ�
	PLAYER_HIT_1 = 1,
};



//================================================================
// �O���錾
//================================================================
class CEnemyLaunchData;
//class CGimmickLaunchData;

//================================================================
// �}�b�v�N���X
//================================================================
class CMap : public cocos2d::TMXTiledMap
{
public:
	//============================================================
	//�}�b�v�^�C�v
	//============================================================
	enum class LAYER_TYPE :int
	{
		NORMAL			= 0,//�ʏ�}�b�v
		LAUNCH_ENEMY	= 1,//�G�o���p
		LAUNCH_GIMMICK  = 2,//�M�~�b�N�o���p
	};

	//============================================================
	//�}�b�v�ɂ�郌�C���[�̖��O
	//============================================================
	std::vector<std::string> m_layerName
	{
		"normal",
		"launchenemy",
		"launchgimmick",

	};

public:
	//�R���X�g���N�^
	CMap()
	{
	}

	//����
	static CMap* create(const std::string& tmxFile)
	{
		CMap* pMap = new(std::nothrow)CMap();
		if (pMap->initWithTMXFile(tmxFile))
		{
			pMap->autorelease();
			return pMap;
		}
		CC_SAFE_DELETE(pMap);
		return NULL;
	}

	/**
	* @desc �^�C���̂Q�����z���̍��W���擾
	* @param ��������_�Ƃ����z���̍��W�ʒu
	*/
	cocos2d::Point getTileCoord(cocos2d::Point pos);

	/**
	* @desc �^�C���ʒu�̎擾
	* @param ���������_�Ƃ��đΏۂ̍��W�ʒu
	*/
	cocos2d::Point getTilePosition(cocos2d::Point pos);

	/**
	* @desc �_�ƃ}�b�v�`�b�v�Ƃ̏Փ˔���
	* @param �ΏۈʒuX
	* @param �ΏۈʒuY
	*/
	bool hitTest(float posX, float posY);

	/**
	* @desc�@�^�C���ԍ��̊m�F
	* @param �Q�����z����X�ʒu
	* @param �Q�����z����Y�ʒu
	* @param ���C���[�^�C�v
	* @return �^�C���ԍ�(�u���b�N�ԍ��A�}�b�v�`�b�v�ԍ��A�}�b�v�`�b�vID)
	* @tips�@checkTile�Ƃ������O�ɂ��Ă���̂�
	*        enchant.js�ɂ̓f�t�H���g�Ń}�b�v�N���X��
	*        checkTile�Ƃ����֐������݂��Ă���
	*        �����@�\�������Ă���̂Ŗ��O�𓝈ꂵ�Ă���
	*/
	BLOCK_TYPE checkTile(float posX, float posY,LAYER_TYPE layerType= LAYER_TYPE::NORMAL);

	/**
	* @desc �^�C���̕ύX
	* @param �ύX����}�b�v�`�b�vID
	* @param �_���Փ˂��Ă���^�C���A���̓_��X���W
	* @param �_���Փ˂��Ă���^�C���A���̓_��Y���W
	* @param ���C���[�^�C�v
	* @return true...����
	*/
	bool changeTile(int mapChipID, float posX, float posY,LAYER_TYPE layerType = LAYER_TYPE::NORMAL);


	/**
	* @desc �G�̏o������
	*/
	void checkEnemyLaunch(float posX,float posY);

	/**
	* @desc �M�~�b�N�̏o������
	*/
//	void checkGimmickLaunch(float posX, float posY);


	/**
	* @desc �G�o����̓G�o�����C���[�̃^�C���̍폜
	* @param �G�o���f�[�^
	*/
	void removeLaunchEnemyBlock(CEnemyLaunchData* pLaunchData);

	/**
	* @desc �M�~�b�N�o����̓G�o�����C���[�̃^�C���̍폜
	* @param �M�~�b�N�o���f�[�^
	*/
//	void removeLaunchGimmickBlock(CGimmickLaunchData* pLaunchData);


private:
	//�G�o�����C��(�}�b�v�̂Q�����z���̃^�C���̂��ʒu)
	//�Q�O�͉�ʂ̒[�{1����
	int m_lauchEnemyLine = 27;

	//�M�~�b�N�o�����C��(�}�b�v�̂Q�����z���̃^�C���̂��ʒu)
	//�O�͉�ʂ̍��[
//	int m_lauchGimmickLine = 0;
};

//==============================================================
// �}�b�v�Ǘ��N���X
//==============================================================
class CMapManager
{
private:
	//==========================================================
	// �V���O���g���ݒ�
	//==========================================================
	//�R���X�g���N�^
	CMapManager();
	CMapManager(const CMapManager& customMapMgr_);

	//���L�C���X�^���X
	static CMapManager* m_pSharedMapManager;

public:
	//���L�C���X�^���X�̎擾
	static CMapManager* getInstance();

	//�j��
	static void removeInstance();

	//�f�X�g���N�^
	~CMapManager();

private:
	//�}�b�v
	CMap* m_pMap = NULL;

public:
	//�}�b�v�̐���
	CMap* createMap(const std::string& fileName_);

	//�}�b�v�̎擾
	CMap* getMap();
};