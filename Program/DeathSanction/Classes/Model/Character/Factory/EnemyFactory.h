#pragma once
#include "CharacterFactory.h"
#include"../EnemyCharacter.h"
#include "Model\Map\Map.h"

//=======================================================
//
// 敵パーツ工場クラス
//
//=======================================================
class CEnemyPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CEnemyPartsFactory();
	/**
	* @desc デストラクタ
	*/
	~CEnemyPartsFactory();


	/**
	* @desc 移動データの取得
	* @return 移動データ
	*/
	CMove*						getMove(void)override;

	/**
	* @desc 実体データの取得
	* @return 実体データ
	*/
	CBody*						getBody(void)override;

	/**
	* @desc 衝突判定領域データ群の取得
	* @return 衝突判定領域データ群
	*/
	std::vector<CCollisionArea*>* getCollisionAreas(void)override;

	/**
	* @desc 状態遷移マシンの取得
	* @return 状態遷移マシンのインスタンス
	*/
	virtual CStateMachine* getStateMachine(void)override;

};


//=======================================================
//
// 敵生成工場
//
//=======================================================
template <class T>
class CEnemyCreateFactory : public CCharacterFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CEnemyCreateFactory()
	{

	}
	
	/**
	* @desc デストラクタ
	*/
	virtual ~CEnemyCreateFactory()
	{

	}

protected:
	virtual CCharacter* createCharacter(void)
	{
		//敵キャラクターの生成
		CCharacter* pCharacter = T::create();

		//敵キャラクター部品生成工場の生成
		CEnemyPartsFactory factory;

		//移動データの設定
		pCharacter->addMove(factory.getMove());
		//実体データの設定
		pCharacter->addBody(factory.getBody());
		//衝突判定データ群の設定
		pCharacter->addCollisionAreas(factory.getCollisionAreas());
		//状態遷移マシンの設定
		pCharacter->addStateMachine(factory.getStateMachine());


		return pCharacter;
	}
};


////=======================================================
////
//// クリボー工場クラス
////
////=======================================================
//class CKuriboFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc コンストラクタ
//	*/
//	CKuriboFactory();
//	/**
//	* @desc デストラクタ
//	*/
//	~CKuriboFactory();
//protected:
//	/**
//	* @desc	 移動データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	* @param 初期座標X
//	* @param 初期座標Y
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 テクスチャーを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アニメーションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 物理演算データ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アクションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 実体データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc 衝突判定領域データ群の設定
//	* @param 衝突判定領域データ群
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 初期化処理
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
////=======================================================
////
//// 緑ノコノコ生成工場クラス
////
////=======================================================
//class CGreenNokoNokoFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc コンストラクタ
//	*/
//	CGreenNokoNokoFactory();
//	/**
//	* @desc デストラクタ
//	*/
//	~CGreenNokoNokoFactory();
//protected:
//	/**
//	* @desc	 移動データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	* @param 初期座標X
//	* @param 初期座標Y
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 テクスチャーを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アニメーションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 物理演算データ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アクションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 実体データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc 衝突判定領域データ群の設定
//	* @param 衝突判定領域データ群
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 初期化処理
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
////=======================================================
////
//// 緑パタパタ生成工場クラス
////
////=======================================================
//class CGreenPataPataFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc コンストラクタ
//	*/
//	CGreenPataPataFactory();
//	/**
//	* @desc デストラクタ
//	*/
//	~CGreenPataPataFactory();
//protected:
//	/**
//	* @desc	 移動データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	* @param 初期座標X
//	* @param 初期座標Y
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 テクスチャーを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アニメーションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 物理演算データ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アクションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 実体データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc 衝突判定領域データ群の設定
//	* @param 衝突判定領域データ群
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 初期化処理
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
//
////=======================================================
////
//// キラー生成工場クラス
////
////=======================================================
//class CKillerFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc コンストラクタ
//	*/
//	CKillerFactory();
//	/**
//	* @desc デストラクタ
//	*/
//	~CKillerFactory();
//protected:
//	/**
//	* @desc	 移動データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	* @param 初期座標X
//	* @param 初期座標Y
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 テクスチャーを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アニメーションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 物理演算データ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アクションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 実体データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc 衝突判定領域データ群の設定
//	* @param 衝突判定領域データ群
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 初期化処理
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
////=======================================================
////
//// キラー発射砲台生成工場クラス
////
////=======================================================
//class CKillerBatteryFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc コンストラクタ
//	*/
//	CKillerBatteryFactory();
//	/**
//	* @desc デストラクタ
//	*/
//	~CKillerBatteryFactory();
//protected:
//	/**
//	* @desc	 移動データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	* @param 初期座標X
//	* @param 初期座標Y
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 テクスチャーを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アニメーションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 物理演算データ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 アクションデータ群を設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 実体データを設定
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc 衝突判定領域データ群の設定
//	* @param 衝突判定領域データ群
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 初期化処理
//	* @param 敵キャラクターインスタンスのアドレス
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//


//EOF