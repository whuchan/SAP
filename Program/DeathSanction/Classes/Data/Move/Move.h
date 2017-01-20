#pragma once

#include"cocos2d.h"
#include"Constants.h"

//===================================================
// 移動データ
//===================================================
class CMove
{
public:
	//位置
	cocos2d::Vec2 m_pos;
	//速度
	cocos2d::Vec2 m_vel;
	//加速度
	cocos2d::Vec2 m_accele;
	//速さ
	float m_speed;

	/**
	* @desc 移動
	*/
	virtual void moveBy()
	{
		//速度による移動
		this->m_pos += m_vel;
	}
};