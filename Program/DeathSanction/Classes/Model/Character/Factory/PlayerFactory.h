#pragma once

#include "../PlayerCharacter.h"

//=======================================================
//
// プレイヤーキャラクター部品生成クラス
//
//=======================================================
class CPlayerPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerPartsFactory();
	/**
	* @desc デストラクタ
	*/
	~CPlayerPartsFactory();

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
// プレイヤーキャラクター生成(抽象)クラス
//
//=======================================================
class CPlayerFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CPlayerFactory();

	/**
	* @desc プレイヤーキャラクターインスタンス生成
	* @return プレイヤーキャラクターインスタンス
	*/
	virtual CPlayerCharacter* create(void);

protected:

	/**
	* @desc
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual CPlayerCharacter* createPlayer(void) = 0;
	/**
	* @desc	 移動データを設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual void settingMove(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc	 テクスチャーを設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual void settingTexture(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc アニメーションデータ群を設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual void settingAnimations(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc 物理演算データ群の設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual void settingPhysicals(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc アクションデータ群の設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual void settingActions(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc 実体データの設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual void settingBody(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	virtual void settingCollisionAreas(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc 初期化処理
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	virtual void settingInitialize(CPlayerCharacter* pCharacter) = 0;

};

//=======================================================
//
// プレイヤーキャラクター生成クラス
//
//=======================================================
class CPlayerCreateFactory : public CPlayerFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CPlayerCreateFactory();

protected:
	/**
	* @desc プレイヤーキャラクターの生成
	* @return プレイヤーキャラクターのインスタンスのアドレス
	*/
	virtual CPlayerCharacter* createPlayer(void)override;

};


//=======================================================
//
// 基本型プレイヤーキャラクター生成クラス
//
//=======================================================
class CBasePlayerFactory : public CPlayerCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBasePlayerFactory();
	/**
	* @desc デストラクタ
	*/
	~CBasePlayerFactory();

	/**
	* @desc	 移動データを設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	void settingMove(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 テクスチャーを設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	void settingTexture(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	void settingAnimations(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	void settingActions(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	void settingBody(CPlayerCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param プレイヤーキャラクターインスタンスのアドレス
	*/
	void settingInitialize(CPlayerCharacter* pCharacter)override;
};

//=======================================================
//
// プレイヤーキャラクター生成クラス管理クラス
//
// シングルトン
//
//=======================================================
class CPlayerFactoryManager
{
public:
	//生成プレイヤータイプ
	enum class TYPE :int
	{
		BASE = 0,
	};

private:
	/*
	* @desc コンストラクタ
	*/
	CPlayerFactoryManager();
public:
	/** 
	* @desc デストラクタ
	*/
	~CPlayerFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CPlayerFactoryManager* getInstance(void);
	/**
	* @desc プレイヤーキャラクターを生成
	* @param 生成タイプ
	*/
	CPlayerCharacter* create(CPlayerFactoryManager::TYPE type);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();
	
private:	
	//工場インスタンス格納配列
	std::vector<CPlayerFactory*>m_pFactories;
	//シングルトンインスタンス
	static CPlayerFactoryManager* m_pSharedFactory;
};