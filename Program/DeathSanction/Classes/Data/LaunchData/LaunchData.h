#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\BulletCharacter.h"

//==============================================
//　敵出撃データ
//==============================================
class CEnemyLaunchData
{
public:
	//敵のタイプ
	ENEMY_TYPE m_type;
	//出撃位置
	cocos2d::Point m_pos;

	//コンストラクタ
	CEnemyLaunchData(ENEMY_TYPE type, cocos2d::Point pos)
		:m_type(type), m_pos(pos)
	{

	}
};

//==============================================
//　弾出撃データ
//==============================================
class CBulletLaunchData
{
public:
	//敵のタイプ
	BULLET_TYPE m_type;
	//出撃位置
	cocos2d::Point m_pos;
	//発射方向ベクトル
	cocos2d::Vec2 m_shotLaunchVector;


	//コンストラクタ
	CBulletLaunchData(BULLET_TYPE type, cocos2d::Point pos, cocos2d::Vec2 shotLaunchVector)
		:m_type(type), m_pos(pos), m_shotLaunchVector(shotLaunchVector)
	{

	}
};

//==============================================
//　ギミック出撃データ
//==============================================
class CGimmickLaunchData
{
public:
	//ギミックのタイプ
	GIMMICK_TYPE m_type;
	//出撃位置
	cocos2d::Point m_pos;

	//コンストラクタ
	CGimmickLaunchData(GIMMICK_TYPE type, cocos2d::Point pos)
		:m_type(type), m_pos(pos)
	{

	}
};
