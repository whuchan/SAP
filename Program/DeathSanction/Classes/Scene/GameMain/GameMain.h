#pragma once

//=========================================================================
//	追加のインクルードはここから
//=========================================================================
#include "cocos2d.h"
#include "Constants.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"

//=========================================================================
//	前方宣言
//=========================================================================
class CStage;

//==========================================
//
// シングルトン
//
// Class: CGameMainManager
//
// ゲームメイン ステージ管理クラス   
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================
class CGameMainManager
{
public:
	enum class STAGE_NUMBER : int
	{
		ONE = 0,
		MAX_STAGE_NUMBER,
	};
	
private:
	/**
	* @desc コンストラクタ
	*/
	CGameMainManager();

public:
	/**
	* @desc デストラクタ
	*/
	~CGameMainManager();

	/**
	* @desc		指定したステージのシーンを生成
	* @param	ステージナンバー
	* @return	ステージを取り付けたシーンインスタンス
	*/
	cocos2d::Scene* CGameMainManager::createScene(int intStageNumber);

	/**
	* @desc		共有インスタンス取得
	* @return	共有インスタンス
	*/
	static CGameMainManager* getInstance(void);

	/**
	* @desc		共有インスタンス破棄
	*/
	static void removeInstance(void);

private:
	// 共有インスタンス
	static CGameMainManager* m_pointerSharedGameMainManager;

	CStage* m_pointerCurrentStage = NULL;

};

//EOF