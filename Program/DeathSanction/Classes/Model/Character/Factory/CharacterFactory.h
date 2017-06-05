#pragma once
#include "cocos2d.h"
#include "../Character.h"

//===============================================
// 前方宣言
//===============================================
//class CBody;
//class CMove;
//class CStateMachine;
//class CCollisionArea;
//===============================================
//
// CCharacter生成工場クラス（抽象クラス）
//
//===============================================
class CCharacterPartsFactory
{
public:
	/**
	* コンストラクタ
	*/
	CCharacterPartsFactory();
	/**
	* デストラクタ
	*/
	virtual ~CCharacterPartsFactory();

	//==============================================================
	//
	// 純粋仮想関数
	//
	//==============================================================
	virtual CMove*						getMove(void) = 0;
	virtual CBody*						getBody(void) = 0;
	virtual std::vector<CCollisionArea*>* getCollisionAreas(void) = 0;
	/**
	* @desc 状態遷移マシンの取得
	* @return 状態遷移マシンのインスタンス
	*/
	virtual CStateMachine* getStateMachine(void) = 0;
};


//=======================================================
//
// キャラクター工場(抽象)クラス
//
//=======================================================
class CCharacterFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CCharacterFactory()
	{

	}
	/**
	* @desc デストラクタ
	*/
	virtual ~CCharacterFactory()
	{

	}

	/**
	* @desc 敵キャラクターを生成
	* @param 初期座標X
	* @param 初期座標Y
	* @return 敵キャラクターインスタンス
	*/
	virtual CCharacter* create(float posX, float posY)
	{
		//敵キャラクターの生成
		CCharacter* pCharacter = this->createCharacter();

		//アニメーションデータ群の設定
		this->settingAnimations(pCharacter);
		//移動データの設定
		this->settingMove(pCharacter, posX, posY);
		//物理演算データ群の設定
		this->settingPhysicals(pCharacter);
		//アクションデータ群の設定
		this->settingActions(pCharacter);
		//実体データの設定
		this->settingBody(pCharacter);
		//テクスチャの設定
		this->settingTexture(pCharacter);
		//衝突判定データ群の設定
		this->settingCollisionAreas(pCharacter);
		//状態遷移マシンの設定
		this->settingStateMachine(pCharacter);

		//初期設定
		this->settingInitialize(pCharacter);

		return pCharacter;
	}

protected:

	/**
	* @desc
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual CCharacter* createCharacter(void) = 0;
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	virtual void settingMove(CCharacter* pCharacter, float posX, float posY) = 0;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingTexture(CCharacter* pCharacter) = 0;
	/**
	* @desc アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingAnimations(CCharacter* pCharacter) = 0;
	/**
	* @desc 物理演算データ群の設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingPhysicals(CCharacter* pCharacter) = 0;
	/**
	* @desc アクションデータ群の設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingActions(CCharacter* pCharacter) = 0;
	/**
	* @desc 実体データの設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingBody(CCharacter* pCharacter) = 0;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingCollisionAreas(CCharacter* pCharacter) = 0;
	/**
	* @desc 状態遷移マシンの設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual	void settingStateMachine(CCharacter* pCharacter) = 0;

	/**
	* @desc 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingInitialize(CCharacter* pCharacter) = 0;

};

//EOF