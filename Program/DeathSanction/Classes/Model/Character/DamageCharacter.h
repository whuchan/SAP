#pragma once
#include "Character.h"

//================================================================
// 弾の種類
//================================================================

enum class DAMAGE_TYPE :int
{
	NORMAL = 0,		//標準
	CUSTOM = 1,		//カスタム
	FIREBALL = 2,	//ファイアーボール
};

//======================================================
//
// 弾キャラクターの基底クラスとなるクラス
//
//======================================================
class CDamageCharacter : public CCharacter
{
public:
	//コンストラクタ
	CDamageCharacter();

	//デストラクタ
	virtual ~CDamageCharacter();

	//初期化処理
	virtual bool init()override;

	/**
	* @desc　初期化処理
	* @param 初期位置X
	* @param 初期位置Y
	* @tips create()メンバ関数の中でinit()メンバ関数を呼び出しているが
	* 今回、そのcreate()メンバ関数をオーバーロードして
	* 引数を受け取っているのでinit()メンバ関数も
	* オーバーロードする必要がある
	*/
	virtual bool init(float posX, float posY);

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
	//CREATE_FUNC(CDamageCharacter);
	static CDamageCharacter* create()
	{
		CDamageCharacter* pRet = new(std::nothrow)CDamageCharacter();
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
	static CDamageCharacter* create(float posX, float posY)
	{
		CDamageCharacter* pRet = new(std::nothrow)CDamageCharacter();
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

	//移動処理
	void moveFunction(float deltaTime)override;

	//アニメーション処理
	void animationFunction(float deltaTime)override;

	//空間との衝突判定処理
	virtual void collision()override;

	//状態チェック
	void checkState(float deltaTime)override;

	//反映処理
	void applayFunction()override;



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


	/**
	* @desc 下領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionBottomCallback(int event)override;

	/**
	* @desc 上領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionTopCallback(int event)override;

	/**
	* @desc 右領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionRightCallback(int event)override;

	/**
	* @desc 左領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionLeftCallback(int event)override;

};
