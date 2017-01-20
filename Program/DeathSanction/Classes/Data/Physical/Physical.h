#pragma once
#include "Data/Move//Move.h"

//===============================================
//�������Z�N���X
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
//�d�͔��f�N���X
//===============================================
class CPhysicalGravity : public CPhysical
{
public:
	//�d�͌W��
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
		//�����̑��x���v�Z�i�d�͌v�Z�j
		//pMove->m_vel.y += pMove->m_accele.y + CPhysicalGravity::GRAVITY;
		pMove->m_vel.y += pMove->m_accele.y + this->m_gravity;
	}
};


//===============================================
//���C���f�N���X
//===============================================
class CPhysicalFriction : public CPhysical
{
public:
	//���C�W��
	constexpr static const float FRICTION = 0.3f;
protected:
	//�ő呬�x
	float m_maxSpeed = 0.0f;
public:
	//�R���X�g���N�^
	CPhysicalFriction(float maxSpeed) :m_maxSpeed(maxSpeed)
	{

	}

	/**
	* @desc �X�V����(���C�̌v�Z)
	*/
	void update(CMove* pMove)override
	{
		//���C
		float friction = 0.0f;

		//�E�Ɉړ����Ă�����
		if (pMove->m_vel.x > CPhysicalFriction::FRICTION)
		{
			friction = -CPhysicalFriction::FRICTION;
		}
		else if (pMove->m_vel.x > 0.0f)
		{
			//���x�����C�W���ȉ��ɂȂ�����
			//���C-���x=0
			//�ɂȂ�悤�ɂ���
			friction = -pMove->m_vel.x;
		}

		//���Ɉړ�������
		if (pMove->m_vel.x < -CPhysicalFriction::FRICTION)
		{
			friction = CPhysicalFriction::FRICTION;
		}
		else if (pMove->m_vel.x < 0.0f)
		{
			//���C-���x=0
			friction = -pMove->m_vel.x;
		}

		//�����̑��x���v�Z(���C�v�Z)
		pMove->m_vel.x += pMove->m_accele.x + friction;

		//x���̍ō����x���v�Z
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
