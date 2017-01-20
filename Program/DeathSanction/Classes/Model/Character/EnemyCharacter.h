#pragma once
#include "Character.h"

//======================================================
//
// 敵キャラクターの基底クラスとなるクラス
//
//======================================================

class CEnemyCharacter : public CCharacter
{
public:
	//コンストラクタ
	CEnemyCharacter();

	//デストラクタ
	~CEnemyCharacter();

	//初期化処理
	bool init()override;

	/**
	* @desc　初期化処理
	* @param 初期位置X
	* @param 初期位置Y
	* @tips create()メンバ関数の中でinit()メンバ関数を呼び出しているが
	* 今回、そのcreate()メンバ関数をオーバーロードして
	* 引数を受け取っているのでinit()メンバ関数も
	* オーバーロードする必要がある
	*/
	bool init(float posX, float posY);

	/**
	* @desc CREATE_FUNC
	* @tips 前回は敵出撃データという敵専用のクラスが存在していたので
	* このクラスに直書きしても問題は生じなかったが
	* 今回はマップの情報による出撃位置の決定という項目が必要になる
	* マップをシングルトン化　したので直書きしても問題ないように思われるが
	* 最終的に必要となるのは位置だけだ
	* なので生成と同時に位置を取得したい
	* だがしかし、cocos2dxの機能である自動でdeleteの機能も使いたい
	* なのでcreate静的メンバ関数をカスタマイズする
	*/
	//CREATE_FUNC(CEnemyCharacter);
	static CEnemyCharacter* create()
	{
		CEnemyCharacter* pRet = new(std::nothrow)CEnemyCharacter();
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
	static CEnemyCharacter* create(float posX,float posY)
	{
		CEnemyCharacter* pRet = new(std::nothrow)CEnemyCharacter();
		if (pRet&&pRet->init(posX,posY))
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

	//移動処理
	void moveFunc()override;

	//アニメーション処理
	void animationFunc()override;

	//空間との衝突判定処理
	virtual void collision()override;

	//状態チェック
	void checkState()override;

	//反映処理
	void applyFunc()override;

	

	/**
	* @desc キャラクター１体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	bool collision(CCharacter* pChara)override;
	
	/**
	* @desc 衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	void hits(CCharacter* pChara)override;

protected:

	/**
	* @desc プレイヤーとの衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara);

	/**
	* @desc 弾との衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsBulletCharacter(CCharacter* pChara);

};