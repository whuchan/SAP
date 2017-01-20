#pragma once
#include "Character.h"

//===========================================================
//プレイヤーキャラクター
//　今回は更新処理が内部で行われるので
//　入力処理も内部で行い、
//　入力による移動処理というカテゴリで扱う
//===========================================================
class CPlayerCharacter : public CCharacter
{
public:
	//=========================================================
	// 定数
	//=========================================================
	//プレイヤーの状態
	enum class STATE :int
	{
		STAND = 0,
		JUMPING = 0,
		WALK = 1,
		HIT = 2,
		FALING = 3
	};

	//プレイヤーが行えるアクション
	enum class ACTION : int
	{
		JUMP = 0,				//ジャンプ
		SHOT_NORMAL_BULLET = 1, //通常弾発射
		SHOT_CUSTOM_BULLET = 2, //カスタム弾発射
		SHOT_FIREBALL_BULLET = 3,//ファイアーボール弾発射
	};


	//=========================================================
	// 関数
	//=========================================================

	//コンストラクタ
	CPlayerCharacter();
	//デストラクタ
	~CPlayerCharacter();

	//初期化処理
	bool init()override;

	CREATE_FUNC(CPlayerCharacter);

	//更新処理
	void update(float deltaTime)override;

	/**
	* @desc 入力処理
	* @tips 移動処理で呼び出す
	*/
	void inputFunc();

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
	virtual void hits(CCharacter* pChara)override;


	/**
	* @desc 下領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	void collisionBottomCallback(int event)
	{
		//ジャンプを停止させる
		(*this->m_pActions)[(int)ACTION::JUMP]->stop();
	}
};

