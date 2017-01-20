#pragma once
#include "cocos2d.h"
#include "Constants.h"

//=================================================
// 実体データ
//=================================================
class CBody
{
public:
	float m_left;
	float m_top;
	float m_right;
	float m_bottom;


	//コンストラクタ
	CBody()
	{

	}

	//コンストラクタ
	CBody(float left,float top,float right,float bottom)
		:m_left(left),m_top(top),m_right(right),m_bottom(bottom)
	{

	}

	//値の設定
	void set(float left, float top, float right, float bottom)
	{
		this->m_left	= left;
		this->m_top		= top;
		this->m_right	= right;
		this->m_bottom	= bottom;
	}
};

//===================================================================
// 前方宣言
//===================================================================
//点
class CCollisionPoint;
//短径
class CCollisionRect;

//===================================================================
// 衝突判定用クラス
//===================================================================
class CCollision
{
public:
	//デストラクタ
	virtual ~CCollision()
	{

	}

	//点が衝突してきたときの衝突判定
	virtual bool collision(CCollisionPoint*)	= 0;
	//矩形が衝突してきたときの衝突判定
	virtual bool collision(CCollisionRect*)		= 0;
};


//===================================================================
// 点
//===================================================================
class CCollisionPoint :public CCollision
{
public:
	//点の位置
	cocos2d::Point m_pos;

	//位置がそのまま衝突判定用の点になる
	CCollisionPoint(cocos2d::Point pos) :m_pos(pos)
	{

	}

	/**
	* @desc 点と点の衝突判定
	* @param 点
	*/
	bool collision(CCollisionPoint* pPt)override;

	/**
	* @desc 点と矩形の衝突判定
	* @param 矩形
	*/
	bool collision(CCollisionRect* pRect)override;
};

//===================================================================
// 衝突判定用矩形
//===================================================================
class CCollisionRect : public CCollision
{
public:
	//コンストラクタ
	CBody m_body;

	/**
	* @desc 実体がそのまま衝突判定用の矩形になる
	*/
	CCollisionRect(CBody body) :m_body(body)
	{

	}

	/**
	* @desc 現在位置と実体から衝突判定用の矩形を設定
	* @param 実体
	* @param 位置
	*/
	CCollisionRect(CBody body, cocos2d::Vec2 pos);

	/**
	* @desc 矩形と点の衝突判定
	* @param 点
	* @tips CPointとCRectの衝突判定はCPointクラスに実装しているので
	* 引数として受け取ったpPtからcollisionを呼び出す
	*/
	bool collision(CCollisionPoint*)override;

	/**
	* @desc 矩形と矩形の衝突判定
	* @param 矩形
	*/
	bool collision(CCollisionRect*)override;
};