#pragma once
#include "Data/Move//Move.h"
#include "cocos2d.h"

//===============================================
//物理演算クラス
//===============================================
class CPhysical
{
public:
	virtual ~CPhysical()
	{

	}
	virtual void update(float deltaTime,CMove* pMove) = 0;
};

//===============================================
//重力反映クラス
//===============================================
class CPhysicalGravity : public CPhysical
{
public:
	//重力係数
	constexpr static const float GRAVITY = -980.0f;

private:
	float m_gravity = 0.0f;

public:
	CPhysicalGravity(float gravity = GRAVITY)
	{
		this->m_gravity = gravity;
	}


	void update(float deltaTime,CMove* pMove)override
	{
		//ｙ軸の速度を計算（重力計算）
		//pMove->m_vel.y += pMove->m_accele.y + CPhysicalGravity::GRAVITY;
		pMove->m_vel.y += (pMove->m_accele.y + this->m_gravity) * deltaTime;
	}
};


//===============================================
//摩擦反映クラス
//===============================================
class CPhysicalFriction : public CPhysical
{
public:
	//摩擦係数
	constexpr static const float FRICTION = 0.3f;
protected:
	//最大速度
	float m_maxSpeed = 0.0f;
public:
	//コンストラクタ
	CPhysicalFriction(float maxSpeed) :m_maxSpeed(maxSpeed)
	{

	}

	/**
	* @desc 更新処理(摩擦の計算)
	*/
	void update(float deltaTime,CMove* pMove)override
	{
		//摩擦
		float friction = 0.0f;

		//右に移動していたら
		if (pMove->m_vel.x > CPhysicalFriction::FRICTION)
		{
			friction = -CPhysicalFriction::FRICTION;
		}
		else if (pMove->m_vel.x > 0.0f)
		{
			//速度が摩擦係数以下になったら
			//摩擦-速度=0
			//になるようにする
			friction = -pMove->m_vel.x;
		}

		//左に移動したら
		if (pMove->m_vel.x < -CPhysicalFriction::FRICTION)
		{
			friction = CPhysicalFriction::FRICTION;
		}
		else if (pMove->m_vel.x < 0.0f)
		{
			//摩擦-速度=0
			friction = -pMove->m_vel.x;
		}

		//ｘ軸の速度を計算(摩擦計算)
		pMove->m_vel.x += (pMove->m_accele.x + friction) * deltaTime;

		//x軸の最高速度を計算
		if (pMove->m_vel.x < -this->m_maxSpeed)
		{
			pMove->m_vel.x = -this->m_maxSpeed;
		}
		else if (pMove->m_vel.x > this->m_maxSpeed)
		{
			pMove->m_vel.x = this->m_maxSpeed;
		}
	}
};
