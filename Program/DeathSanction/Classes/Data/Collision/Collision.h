#pragma once
#include "cocos2d.h"
#include "Constants.h"

//=================================================
// ���̃f�[�^
//=================================================
class CBody
{
public:
	float m_left;
	float m_top;
	float m_right;
	float m_bottom;


	//�R���X�g���N�^
	CBody()
	{

	}

	//�R���X�g���N�^
	CBody(float left,float top,float right,float bottom)
		:m_left(left),m_top(top),m_right(right),m_bottom(bottom)
	{

	}

	//�l�̐ݒ�
	void set(float left, float top, float right, float bottom)
	{
		this->m_left	= left;
		this->m_top		= top;
		this->m_right	= right;
		this->m_bottom	= bottom;
	}
};

//===================================================================
// �O���錾
//===================================================================
//�_
class CCollisionPoint;
//�Z�a
class CCollisionRect;

//===================================================================
// �Փ˔���p�N���X
//===================================================================
class CCollision
{
public:
	//�f�X�g���N�^
	virtual ~CCollision()
	{

	}

	//�_���Փ˂��Ă����Ƃ��̏Փ˔���
	virtual bool collision(CCollisionPoint*)	= 0;
	//��`���Փ˂��Ă����Ƃ��̏Փ˔���
	virtual bool collision(CCollisionRect*)		= 0;
};


//===================================================================
// �_
//===================================================================
class CCollisionPoint :public CCollision
{
public:
	//�_�̈ʒu
	cocos2d::Point m_pos;

	//�ʒu�����̂܂܏Փ˔���p�̓_�ɂȂ�
	CCollisionPoint(cocos2d::Point pos) :m_pos(pos)
	{

	}

	/**
	* @desc �_�Ɠ_�̏Փ˔���
	* @param �_
	*/
	bool collision(CCollisionPoint* pPt)override;

	/**
	* @desc �_�Ƌ�`�̏Փ˔���
	* @param ��`
	*/
	bool collision(CCollisionRect* pRect)override;
};

//===================================================================
// �Փ˔���p��`
//===================================================================
class CCollisionRect : public CCollision
{
public:
	//�R���X�g���N�^
	CBody m_body;

	/**
	* @desc ���̂����̂܂܏Փ˔���p�̋�`�ɂȂ�
	*/
	CCollisionRect(CBody body) :m_body(body)
	{

	}

	/**
	* @desc ���݈ʒu�Ǝ��̂���Փ˔���p�̋�`��ݒ�
	* @param ����
	* @param �ʒu
	*/
	CCollisionRect(CBody body, cocos2d::Vec2 pos);

	/**
	* @desc ��`�Ɠ_�̏Փ˔���
	* @param �_
	* @tips CPoint��CRect�̏Փ˔����CPoint�N���X�Ɏ������Ă���̂�
	* �����Ƃ��Ď󂯎����pPt����collision���Ăяo��
	*/
	bool collision(CCollisionPoint*)override;

	/**
	* @desc ��`�Ƌ�`�̏Փ˔���
	* @param ��`
	*/
	bool collision(CCollisionRect*)override;
};