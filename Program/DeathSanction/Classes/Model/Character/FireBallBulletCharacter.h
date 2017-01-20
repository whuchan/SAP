#pragma once
#include "BulletCharacter.h"


//======================================================
//
// ファイアーボールクラス
//
//======================================================
class CFireBallBulletCharacter : public CBulletCharacter
{
public:
	//コンストラクタ
	CFireBallBulletCharacter();

	//デストラクタ
	~CFireBallBulletCharacter();

	/**
	* @desc CREATE_FUNC
	* @tips 前回は弾出撃データという弾専用のクラスが存在していたので
	* このクラスに直書きしても問題は生じなかったが
	* 今回はマップの情報による出撃位置の決定という項目が必要になる
	* マップをシングルトン化　したので直書きしても問題ないように思われるが
	* 最終的に必要となるのは位置だけだ
	* なので生成と同時に位置を取得したい
	* だがしかし、cocos2dxの機能である自動でdeleteの機能も使いたい
	* なのでcreate静的メンバ関数をカスタマイズする
	*/
	//CREATE_FUNC(CBulletCharacter);
	static CFireBallBulletCharacter* create()
	{
		CFireBallBulletCharacter* pRet = new(std::nothrow)CFireBallBulletCharacter();
		if (pRet&&pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

	/**
	* @desc CREATE_FUNCマクロをオーバーライド
	* @param 初期位置X
	* @param 初期位置Y
	* @tips 初期位置を必要とするのは生成の段階ではなく
	*       initの段階である
	*/
	static CFireBallBulletCharacter* create(float posX, float posY)
	{
		CFireBallBulletCharacter* pRet = new(std::nothrow)CFireBallBulletCharacter();
		if (pRet&&pRet->init(posX, posY))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

	/**
	* @desc 下領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionBottomCallback(int event)override;

private:
//	DIRECTION_TYPE m_typeDirection = DIRECTION_TYPE::LEFT;
};
