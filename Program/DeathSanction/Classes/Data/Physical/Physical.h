#pragma once
#include "Data/Move//Move.h"

//===============================================
//•¨—‰‰ŽZƒNƒ‰ƒX
//===============================================
class CPhysical
{
public:
	virtual ~CPhysical()
	{

	}
	virtual void update(CMove* pMove) = 0;
};

//===============================================
//d—Í”½‰fƒNƒ‰ƒX
//===============================================
class CPhysicalGravity : public CPhysical
{
public:
	//d—ÍŒW”
	constexpr static const float GRAVITY = -0.5f;

private:
	float m_gravity = 0.0f;

public:
	CPhysicalGravity(float gravity = -0.5f)
	{
		this->m_gravity = gravity;
	}


	void update(CMove* pMove)override
	{
		//‚™Ž²‚Ì‘¬“x‚ðŒvŽZid—ÍŒvŽZj
		//pMove->m_vel.y += pMove->m_accele.y + CPhysicalGravity::GRAVITY;
		pMove->m_vel.y += pMove->m_accele.y + this->m_gravity;
	}
};


//===============================================
//–€ŽC”½‰fƒNƒ‰ƒX
//===============================================
class CPhysicalFriction : public CPhysical
{
public:
	//–€ŽCŒW”
	constexpr static const float FRICTION = 0.3f;
protected:
	//Å‘å‘¬“x
	float m_maxSpeed = 0.0f;
public:
	//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	CPhysicalFriction(float maxSpeed) :m_maxSpeed(maxSpeed)
	{

	}

	/**
	* @desc XVˆ—(–€ŽC‚ÌŒvŽZ)
	*/
	void update(CMove* pMove)override
	{
		//–€ŽC
		float friction = 0.0f;

		//‰E‚ÉˆÚ“®‚µ‚Ä‚¢‚½‚ç
		if (pMove->m_vel.x > CPhysicalFriction::FRICTION)
		{
			friction = -CPhysicalFriction::FRICTION;
		}
		else if (pMove->m_vel.x > 0.0f)
		{
			//‘¬“x‚ª–€ŽCŒW”ˆÈ‰º‚É‚È‚Á‚½‚ç
			//–€ŽC-‘¬“x=0
			//‚É‚È‚é‚æ‚¤‚É‚·‚é
			friction = -pMove->m_vel.x;
		}

		//¶‚ÉˆÚ“®‚µ‚½‚ç
		if (pMove->m_vel.x < -CPhysicalFriction::FRICTION)
		{
			friction = CPhysicalFriction::FRICTION;
		}
		else if (pMove->m_vel.x < 0.0f)
		{
			//–€ŽC-‘¬“x=0
			friction = -pMove->m_vel.x;
		}

		//‚˜Ž²‚Ì‘¬“x‚ðŒvŽZ(–€ŽCŒvŽZ)
		pMove->m_vel.x += pMove->m_accele.x + friction;

		//xŽ²‚ÌÅ‚‘¬“x‚ðŒvŽZ
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
