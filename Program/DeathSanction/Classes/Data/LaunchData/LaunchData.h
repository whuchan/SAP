#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\BulletCharacter.h"

//==============================================
//�@�G�o���f�[�^
//==============================================
class CEnemyLaunchData
{
public:
	//�G�̃^�C�v
	ENEMY_TYPE m_type;
	//�o���ʒu
	cocos2d::Point m_pos;

	//�R���X�g���N�^
	CEnemyLaunchData(ENEMY_TYPE type, cocos2d::Point pos)
		:m_type(type), m_pos(pos)
	{

	}
};

//==============================================
//�@�e�o���f�[�^
//==============================================
class CBulletLaunchData
{
public:
	//�G�̃^�C�v
	BULLET_TYPE m_type;
	//�o���ʒu
	cocos2d::Point m_pos;
	//���˕����x�N�g��
	cocos2d::Vec2 m_shotLaunchVector;


	//�R���X�g���N�^
	CBulletLaunchData(BULLET_TYPE type, cocos2d::Point pos, cocos2d::Vec2 shotLaunchVector)
		:m_type(type), m_pos(pos), m_shotLaunchVector(shotLaunchVector)
	{

	}
};

//==============================================
//�@�M�~�b�N�o���f�[�^
//==============================================
class CGimmickLaunchData
{
public:
	//�M�~�b�N�̃^�C�v
	GIMMICK_TYPE m_type;
	//�o���ʒu
	cocos2d::Point m_pos;

	//�R���X�g���N�^
	CGimmickLaunchData(GIMMICK_TYPE type, cocos2d::Point pos)
		:m_type(type), m_pos(pos)
	{

	}
};
