#pragma once
#include "GimmickCharacter.h"


//======================================================
//
// 敵が出現するブロックギミックキャラクターの基底クラスとなるクラス
//
//======================================================
class CHatenaBlockGimmickCharacter : public CGimmickCharacter
{
public:

	enum class STATE : int
	{
		NONE = 0,
		USED = 1,
	};


	//コンストラクタ
	CHatenaBlockGimmickCharacter();

	//デストラクタ
	virtual ~CHatenaBlockGimmickCharacter();

	/**
	* @desc CREATE_FUNC
	* @tips 前回はギミック出撃データというギミック専用のクラスが存在していたので
	* このクラスに直書きしても問題は生じなかったが
	* 今回はマップの情報による出撃位置の決定という項目が必要になる
	* マップをシングルトン化　したので直書きしても問題ないように思われるが
	* 最終的に必要となるのは位置だけだ
	* なので生成と同時に位置を取得したい
	* だがしかし、cocos2dxの機能である自動でdeleteの機能も使いたい
	* なのでcreate静的メンバ関数をカスタマイズする
	*/
	//CREATE_FUNC(CGimmickCharacter);
	static CHatenaBlockGimmickCharacter* create()
	{
		CHatenaBlockGimmickCharacter* pRet = new(std::nothrow)CHatenaBlockGimmickCharacter();
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
	static CHatenaBlockGimmickCharacter* create(float posX, float posY)
	{
		CHatenaBlockGimmickCharacter* pRet = new(std::nothrow)CHatenaBlockGimmickCharacter();
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
	* @desc プレイヤーとの衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara)override;

	/**
	* @desc 敵との衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsEnemyCharacter(CCharacter* pChara)override;
};