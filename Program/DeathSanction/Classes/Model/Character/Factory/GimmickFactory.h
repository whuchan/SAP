#pragma once
#include"../GimmickCharacter.h"
#include"../DamageBlockGimmickCharacter.h"
#include"../HatenaBlockGimmickCharacter.h"
#include"../NoteBlockGimmickCharacter.h"
#include"../RollBlockGimmickCharacter.h"
#include"../TikuwaBlockGimmickCharacter.h"

#include "Model\Map\Map.h"

//=======================================================
//
// ギミックパーツ工場クラス
//
//=======================================================
class CGimmickPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CGimmickPartsFactory();
	/**
	* @desc デストラクタ
	*/
	~CGimmickPartsFactory();


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
// ギミック工場(抽象)クラス
//
//=======================================================
class CGimmickFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CGimmickFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CGimmickFactory();

	/**
	* @desc ギミックキャラクターインスタンス生成
	* @return ギミックキャラクターインスタンス
	*/
	virtual CGimmickCharacter* create(float posX, float posY);

protected:

	/**
	* @desc
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	virtual CGimmickCharacter* createGimmick(void) = 0;
	/**
	* @desc	 移動データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	virtual void settingMove(CGimmickCharacter* pCharacter, float posX, float posY) = 0;
	/**
	* @desc	 テクスチャーを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	virtual void settingTexture(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc アニメーションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	virtual void settingAnimations(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc 物理演算データ群の設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	virtual void settingPhysicals(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc アクションデータ群の設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	virtual void settingActions(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc 実体データの設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	virtual void settingBody(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	virtual void settingCollisionAreas(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc 初期化処理
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	virtual void settingInitialize(CGimmickCharacter* pCharacter) = 0;

};

//=======================================================
//
// ギミック生成工場
//
//=======================================================
class CDamageBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CDamageBlockGimmickCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CDamageBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// ダメージブロックギミック工場クラス
//
//=======================================================
class CDamageBlockGimmickFactory : public CDamageBlockGimmickCreateFactory
{
public:

	enum class TYPE :int
	{
		LEFT = 146,		//ダメージ左
		UP = 147,		//ダメージ上
		RIGHT = 148,		//ダメージ右
		DOWN = 149,		//ダメージ下
	};
private:
	int m_type = (int)TYPE::LEFT;

public:
	/**
	* @desc コンストラクタ
	*/
	CDamageBlockGimmickFactory( int type);
	/**
	* @desc デストラクタ
	*/
	~CDamageBlockGimmickFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// ギミック生成工場
//
//=======================================================
class CRollBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CRollBlockGimmickCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CRollBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// 回るブロックギミック工場クラス
//
//=======================================================
class CRollBlockGimmickFactory : public CRollBlockGimmickCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CRollBlockGimmickFactory();
	/**
	* @desc デストラクタ
	*/
	~CRollBlockGimmickFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// ギミック生成工場
//
//=======================================================
class CTikuwaBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CTikuwaBlockGimmickCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CTikuwaBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;
};


//=======================================================
//
// 落ちるブロックギミック工場クラス
//
//=======================================================
class CTikuwaBlockGimmickFactory : public CTikuwaBlockGimmickCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CTikuwaBlockGimmickFactory();
	/**
	* @desc デストラクタ
	*/
	~CTikuwaBlockGimmickFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// ギミック生成工場
//
//=======================================================
class CNoteBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNoteBlockGimmickCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CNoteBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// 跳ねるブロックギミック工場クラス
//
//=======================================================
class CNoteBlockGimmickFactory : public CNoteBlockGimmickCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNoteBlockGimmickFactory();
	/**
	* @desc デストラクタ
	*/
	~CNoteBlockGimmickFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// ギミック生成工場
//
//=======================================================
class CHatenaBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CHatenaBlockGimmickCreateFactory();
	/**
	* @desc デストラクタ
	*/
	virtual ~CHatenaBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// キャラクターが出現するブロックギミック工場クラス
//
//=======================================================
class CHatenaBlockGimmickFactory : public CHatenaBlockGimmickCreateFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CHatenaBlockGimmickFactory();
	/**
	* @desc デストラクタ
	*/
	~CHatenaBlockGimmickFactory();
protected:
	/**
	* @desc	 移動データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 初期化処理
	* @param ギミックキャラクターインスタンスのアドレス
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};


//=======================================================
//
// ギミック工事管理クラス
//
// シングルトン
//
//=======================================================
class CGimmickFactoryManager
{
private:
	/*
	* @desc コンストラクタ
	*/
	CGimmickFactoryManager();
public:
	/**
	* @desc デストラクタ
	*/
	virtual ~CGimmickFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CGimmickFactoryManager* getInstance(void);
	/**
	* @desc ギミックキャラクターを生成
	* @param 生成タイプ
	*/
	CGimmickCharacter* create(GIMMICK_TYPE type, float posX, float posY);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();

private:
	//ギミック生成工場群
	std::map<GIMMICK_TYPE, CGimmickFactory*>* m_pFactories = NULL;
	//シングルトンインスタンス
	static CGimmickFactoryManager* m_pSharedManager;
};