#pragma once

#include"cocos2d.h"
#include"Constants.h"

//===================================================
// �ړ��f�[�^
//===================================================
class CMove
{
public:
	//�ʒu
	cocos2d::Vec2 m_pos;
	//���x
	cocos2d::Vec2 m_vel;
	//�����x
	cocos2d::Vec2 m_accele;
	//����
	float m_speed;

	/**
	* @desc �ړ�
	*/
	virtual void moveBy()
	{
		//���x�ɂ��ړ�
		this->m_pos += m_vel;
	}
};