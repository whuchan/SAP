#include"Collision.h"

//===================================================================
// 点
//===================================================================
/**
* @desc 点と点の衝突判定
* @param 点
*/
bool CCollisionPoint::collision(CCollisionPoint* pPt)
{
	if (this->m_pos.x == pPt->m_pos.x)
	{
		if (this->m_pos.y == pPt->m_pos.y)
		{
			return true;
		}
	}
	return false;
}

/**
* @desc 点と矩形の衝突判定
* @param 矩形
*/
bool CCollisionPoint::collision(CCollisionRect* pRect)
{
	if (this->m_pos.x > pRect->m_body.m_left && this->m_pos.x < pRect->m_body.m_right)
	{
		if (this->m_pos.y > pRect->m_body.m_bottom && this->m_pos.y < pRect->m_body.m_top)
		{
			return true;
		}
	}
	return false;
}

//===================================================================
// 矩形
//===================================================================
/**
* @desc 現在位置と実体から衝突判定用の矩形を設定
* @param 実体
* @param 位置
*/
CCollisionRect::CCollisionRect(CBody body, cocos2d::Vec2 pos)
{
	this->m_body.set(	body.m_left + pos.x,
						body.m_top + pos.y,
						body.m_right + pos.x,
						body.m_bottom + pos.y);
}

/**
* @desc 矩形と点の衝突判定
* @param 点
* @tips CPointとCRectの衝突判定はCPointクラスに実装しているので
* 引数として受け取ったpPtからcollisionを呼び出す
*/
bool CCollisionRect::collision(CCollisionPoint* pPt)
{
	return pPt->collision(this);
}

/**
* @desc 矩形と矩形の衝突判定
* @param　矩形
*/
bool CCollisionRect::collision(CCollisionRect* pRect)
{
	//自分の右側と対象の左側と自分の左側と対象の右側
	if (this->m_body.m_right > pRect->m_body.m_left && this->m_body.m_left < pRect->m_body.m_right)
	{
		//自分の上側と対象の下側と自分の下側と対象の上側
		if (this->m_body.m_top > pRect->m_body.m_bottom && this->m_body.m_bottom < pRect->m_body.m_top)
		{
			return true;
		}
	}
	//衝突していない
	return false;
}