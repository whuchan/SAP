#pragma once

#pragma once
#include"../BulletCharacter.h"
#include"../FireBallBulletCharacter.h"
#include "Model\Map\Map.h"

//=======================================================
//
// 弾パーツ工場クラス
//
//=======================================================
class CBulletPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBulletPartsFactory();
	/**
	* @desc デストラクタ
	*/
	~CBulletPartsFactory();

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

};

//=======================================================
//
// 弾工場(抽象)クラス
//
//=======================================================
class CBulletFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBulletFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CBulletFactory();

	/**
	* @desc 弾キャラクターインスタンス生成
	* @return 弾キャラクターインスタンス
	*/
	virtual CBulletCharacter* create(float posX, float posY, cocos2d::Vec2 shotLaunchVector);

protected:

	/**
	* @desc
	* @param 弾キャラクターインスタンスのアドレス
	*/
	virtual CBulletCharacter* createBullet(void) = 0;
	/**
	* @desc	 移動データを設定
	* @param 弾キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	virtual void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector) = 0;
	/**
	* @desc	 テクスチャーを設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	virtual void settingTexture(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc アニメーションデータ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	virtual void settingAnimations(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc 物理演算データ群の設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	virtual void settingPhysicals(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc アクションデータ群の設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	virtual void settingActions(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc 実体データの設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	virtual void settingBody(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	virtual void settingCollisionAreas(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc 初期化処理
	* @param 弾キャラクターインスタンスのアドレス
	*/
	virtual void settingInitialize(CBulletCharacter* pCharacter) = 0;

};

//=======================================================
//
// 弾生成工場
//
//=======================================================
class CBulletCreateFactory : public CBulletFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBulletCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CBulletCreateFactory();

protected:
	virtual CBulletCharacter* createBullet(void)override;

};


//=======================================================
//
// ノーマル弾工場クラス
//
//=======================================================
class CNormalBulletFactory : public CBulletCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNormalBulletFactory();
	/**
	* @desc デストラクタ
	*/
	~CNormalBulletFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 弾キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingTexture(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingActions(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingBody(CBulletCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CBulletCharacter* pCharacter)override;
};


//=======================================================
//
// カスタム弾工場クラス
//
//=======================================================
class CCustomBulletFactory : public CBulletCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CCustomBulletFactory();
	/**
	* @desc デストラクタ
	*/
	~CCustomBulletFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 弾キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingTexture(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingActions(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingBody(CBulletCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CBulletCharacter* pCharacter)override;
};


//=======================================================
//
// ファイアーボール弾生成工場
//
//=======================================================
class CFireBallBulletCreateFactory : public CBulletFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CFireBallBulletCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CFireBallBulletCreateFactory();

protected:
	virtual CFireBallBulletCharacter* createBullet(void)override;

};


//=======================================================
//
// ファイアーボール弾工場クラス
//
//=======================================================
class CFireBallBulletFactory : public CFireBallBulletCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CFireBallBulletFactory();
	/**
	* @desc デストラクタ
	*/
	~CFireBallBulletFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 弾キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingTexture(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingActions(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingBody(CBulletCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param 弾キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CBulletCharacter* pCharacter)override;
};


//=======================================================
//
// 弾工事管理クラス
//
// シングルトン
//
//=======================================================
class CBulletFactoryManager
{
private:
	/*
	* @desc コンストラクタ
	*/
	CBulletFactoryManager();
public:
	/**
	* @desc デストラクタ
	*/
	virtual ~CBulletFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CBulletFactoryManager* getInstance(void);
	/**
	* @desc 弾キャラクターを生成
	* @param 生成タイプ
	*/
	CBulletCharacter* create(BULLET_TYPE type, float posX, float posY,cocos2d::Vec2  shotLaunchVector);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();

private:
	//弾生成工場群
	std::map<BULLET_TYPE, CBulletFactory*>* m_pFactories = NULL;
	//シングルトンインスタンス
	static CBulletFactoryManager* m_pSharedManager;
};