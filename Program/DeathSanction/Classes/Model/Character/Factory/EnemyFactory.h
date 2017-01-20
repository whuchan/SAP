#pragma once
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
	* @desc アニメーションデータ群の取得
	* @return アニメーションデータ群
	*/
	std::vector<CAnimation*>*	getAnimations(void)override;
	/**
	* @desc 移動データの取得
	* @return 移動データ
	*/
	CMove*						getMove(void)override;

	/**
	* @desc 物理演算データ群取得
	* @return 物理演算データ群
	*/
	std::vector<CPhysical*>*	getPhysicals(void)override;

	/**
	* @desc アクションデータ群の取得
	* @return アクションデータ群
	*/
	std::vector<CAction*>*		getActions(void)override;

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

};

//=======================================================
//
// 敵工場(抽象)クラス
//
//=======================================================
class CEnemyFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CEnemyFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CEnemyFactory();

	/**
	* @desc 敵キャラクターインスタンス生成
	* @return 敵キャラクターインスタンス
	*/
	virtual CEnemyCharacter* create(float posX,float posY);

protected:

	/**
	* @desc
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual CEnemyCharacter* createEnemy(void) = 0;
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	virtual void settingMove(CEnemyCharacter* pCharacter, float posX, float posY) = 0;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingTexture(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingAnimations(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc 物理演算データ群の設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingPhysicals(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc アクションデータ群の設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingActions(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc 実体データの設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingBody(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	virtual void settingCollisionAreas(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	virtual void settingInitialize(CEnemyCharacter* pCharacter) = 0;

};

//=======================================================
//
// 敵生成工場
//
//=======================================================
class CEnemyCreateFactory : public CEnemyFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CEnemyCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CEnemyCreateFactory();

protected:
	virtual CEnemyCharacter* createEnemy(void)override;

};


//=======================================================
//
// クリボー工場クラス
//
//=======================================================
class CKuriboFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CKuriboFactory();
	/**
	* @desc デストラクタ
	*/
	~CKuriboFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};

//=======================================================
//
// 緑ノコノコ生成工場クラス
//
//=======================================================
class CGreenNokoNokoFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CGreenNokoNokoFactory();
	/**
	* @desc デストラクタ
	*/
	~CGreenNokoNokoFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};

//=======================================================
//
// 緑パタパタ生成工場クラス
//
//=======================================================
class CGreenPataPataFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CGreenPataPataFactory();
	/**
	* @desc デストラクタ
	*/
	~CGreenPataPataFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};


//=======================================================
//
// キラー生成工場クラス
//
//=======================================================
class CKillerFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CKillerFactory();
	/**
	* @desc デストラクタ
	*/
	~CKillerFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};

//=======================================================
//
// キラー発射砲台生成工場クラス
//
//=======================================================
class CKillerBatteryFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CKillerBatteryFactory();
	/**
	* @desc デストラクタ
	*/
	~CKillerBatteryFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};



//=======================================================
//
// 敵工事管理クラス
//
// シングルトン
//
//=======================================================
class CEnemyFactoryManager
{
private:
	/*
	* @desc コンストラクタ
	*/
	CEnemyFactoryManager();
public:
	/**
	* @desc デストラクタ
	*/
	~CEnemyFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CEnemyFactoryManager* getInstance(void);
	/**
	* @desc 敵キャラクターを生成
	* @param 生成タイプ
	*/
	CEnemyCharacter* create(ENEMY_TYPE type, float posX, float posY);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();

private:
	//敵生成工場群
	std::map<ENEMY_TYPE,CEnemyFactory*>* m_pFactories = NULL;
	//シングルトンインスタンス
	static CEnemyFactoryManager* m_pSharedManager;
};