//==========================================
//
// File: GameMain.cpp
//
// ゲームメイン管理 ファイル
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "Scene\GameMain\GameMain.h"
#include"Scene\GameMain\Stage\Stage1.h"

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

//==========================================
// 静的変数定義
//==========================================
// 共有インスタンス
CGameMainManager* CGameMainManager::m_pointerSharedGameMainManager = NULL;

/**
* @desc コンストラクタ
*/
CGameMainManager::CGameMainManager()
{

}

/**
* @desc デストラクタ
*/
CGameMainManager::~CGameMainManager()
{

}

/**
* @desc		指定したステージのシーンを生成
* @param	ステージナンバー
* @return	ステージを取り付けたシーンインスタンス
*/
cocos2d::Scene* CGameMainManager::createScene(int intStageNumber)
{
	// シーンの生成
	cocos2d::Scene* pointerScene = cocos2d::Scene::create();

	// GameMain レイヤーの生成
	switch( (STAGE_NUMBER)intStageNumber )
	{
	case STAGE_NUMBER::ONE:	this->m_pointerCurrentStage = CStage1::create();
							break;

	default:				this->m_pointerCurrentStage = CStage1::create();
							break;
	}

	// CStageレイヤーをシーンに取り付ける
	pointerScene->addChild(this->m_pointerCurrentStage, 0, TAG_GAME_MAIN);

	return pointerScene;
}



/**
* @desc 共有インスタンス取得
* @return	共有インスタンス
*/
CGameMainManager* CGameMainManager::getInstance(void)
{
	if (CGameMainManager::m_pointerSharedGameMainManager == NULL)
	{
		CGameMainManager::m_pointerSharedGameMainManager = new CGameMainManager();
	}
	return CGameMainManager::m_pointerSharedGameMainManager;
}

/**
* @desc		共有インスタンス破棄
*/
void CGameMainManager::removeInstance(void)
{
	SAFE_DELETE(CGameMainManager::m_pointerSharedGameMainManager);
}
//EOF