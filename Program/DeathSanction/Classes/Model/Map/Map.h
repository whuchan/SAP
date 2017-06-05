#pragma once

#include <stdio.h>
#include "cocos2d.h"

//================================================================
// ブロック（マップチップ）種類
// 
//================================================================
enum class BLOCK_TYPE : int
{
	NONE = 0,//何も無し
};

//================================================================
// 敵の種類
// ブロック番号に依存
//================================================================
enum class ENEMY_TYPE :int
{
	NONE			= 0,		//何もなし
	HENCHMAN_TYPE_A = 102,	//クリボー
	LEATHERFACE		= 108,//ノコノコ
	PATAPATA		= 109,//パタパタ
	KILLERBATTERY	= 124,//キラー砲台
	KILLER			= 1124,//キラー
};

//================================================================
// ギミックの種類
//================================================================
enum class GIMMICK_TYPE :int
{
	NONE		= 0,		//何もなし
	DAMEGE_LEFT	= 146,		//ダメージ左
	DAMEGE_UP	= 147,		//ダメージ上
	DAMEGE_RIGHT= 148,		//ダメージ右
	DAMEGE_DOWN = 149,		//ダメージ下
	ROLL		= 156,		//回る
	TIKUWA		= 157,		//落ちる
	NOTE		= 158,		//跳ねる
	HATENA		= 159,		//キャラクター出現
};

//================================================================
// ダメージの種類
// ブロック番号に依存
//================================================================
enum class DAMAGE_TYPE :int
{
	NONE = 0,		//何もなし
	PLAYER_ATTACK_1 = 1,
};

//================================================================
// エフェクトの種類
// ブロック番号に依存
//================================================================
enum class EFFECT_TYPE :int
{
	NONE = 0,		//何もなし
	PLAYER_HIT_1 = 1,
};



//================================================================
// 前方宣言
//================================================================
class CEnemyLaunchData;
//class CGimmickLaunchData;

//================================================================
// マップクラス
//================================================================
class CMap : public cocos2d::TMXTiledMap
{
public:
	//============================================================
	//マップタイプ
	//============================================================
	enum class LAYER_TYPE :int
	{
		NORMAL			= 0,//通常マップ
		LAUNCH_ENEMY	= 1,//敵出現用
		LAUNCH_GIMMICK  = 2,//ギミック出撃用
	};

	//============================================================
	//マップによるレイヤーの名前
	//============================================================
	std::vector<std::string> m_layerName
	{
		"normal",
		"launchenemy",
		"launchgimmick",

	};

public:
	//コンストラクタ
	CMap()
	{
	}

	//生成
	static CMap* create(const std::string& tmxFile)
	{
		CMap* pMap = new(std::nothrow)CMap();
		if (pMap->initWithTMXFile(tmxFile))
		{
			pMap->autorelease();
			return pMap;
		}
		CC_SAFE_DELETE(pMap);
		return NULL;
	}

	/**
	* @desc タイルの２次元配列上の座標を取得
	* @param 左上を原点とした配列上の座標位置
	*/
	cocos2d::Point getTileCoord(cocos2d::Point pos);

	/**
	* @desc タイル位置の取得
	* @param 左下を原点として対象の座標位置
	*/
	cocos2d::Point getTilePosition(cocos2d::Point pos);

	/**
	* @desc 点とマップチップとの衝突判定
	* @param 対象位置X
	* @param 対象位置Y
	*/
	bool hitTest(float posX, float posY);

	/**
	* @desc　タイル番号の確認
	* @param ２次元配列上のX位置
	* @param ２次元配列上のY位置
	* @param レイヤータイプ
	* @return タイル番号(ブロック番号、マップチップ番号、マップチップID)
	* @tips　checkTileという名前にしているのは
	*        enchant.jsにはデフォルトでマップクラスに
	*        checkTileという関数が存在していて
	*        同じ機能を持っているので名前を統一している
	*/
	BLOCK_TYPE checkTile(float posX, float posY,LAYER_TYPE layerType= LAYER_TYPE::NORMAL);

	/**
	* @desc タイルの変更
	* @param 変更するマップチップID
	* @param 点が衝突しているタイル、その点のX座標
	* @param 点が衝突しているタイル、その点のY座標
	* @param レイヤータイプ
	* @return true...成功
	*/
	bool changeTile(int mapChipID, float posX, float posY,LAYER_TYPE layerType = LAYER_TYPE::NORMAL);


	/**
	* @desc 敵の出撃判定
	*/
	void checkEnemyLaunch(float posX,float posY);

	/**
	* @desc ギミックの出撃判定
	*/
//	void checkGimmickLaunch(float posX, float posY);


	/**
	* @desc 敵出撃後の敵出撃レイヤーのタイルの削除
	* @param 敵出撃データ
	*/
	void removeLaunchEnemyBlock(CEnemyLaunchData* pLaunchData);

	/**
	* @desc ギミック出撃後の敵出撃レイヤーのタイルの削除
	* @param ギミック出撃データ
	*/
//	void removeLaunchGimmickBlock(CGimmickLaunchData* pLaunchData);


private:
	//敵出撃ライン(マップの２次元配列上のタイルのｘ位置)
	//２０は画面の端＋1つ分の
	int m_lauchEnemyLine = 27;

	//ギミック出撃ライン(マップの２次元配列上のタイルのｘ位置)
	//０は画面の左端
//	int m_lauchGimmickLine = 0;
};

//==============================================================
// マップ管理クラス
//==============================================================
class CMapManager
{
private:
	//==========================================================
	// シングルトン設定
	//==========================================================
	//コンストラクタ
	CMapManager();
	CMapManager(const CMapManager& customMapMgr_);

	//共有インスタンス
	static CMapManager* m_pSharedMapManager;

public:
	//共有インスタンスの取得
	static CMapManager* getInstance();

	//破棄
	static void removeInstance();

	//デストラクタ
	~CMapManager();

private:
	//マップ
	CMap* m_pMap = NULL;

public:
	//マップの生成
	CMap* createMap(const std::string& fileName_);

	//マップの取得
	CMap* getMap();
};