//==========================================
//
// File: CStage1.cpp
//
// ステージ１ ファイル
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

#include "Stage1.h"

//==========================================
// ヘッダインクルード
//==========================================
// 入力
#include "Lib/Input/InputManager.h"
//音楽再生用
#include "Lib\Sound\SoundManager.h"

// 乱数生成用
#include <stdlib.h>
#include <time.h>

#include"Model\Map\Map.h"
#include"Model\Character\Character.h"
#include"Model\Character\Factory\PlayerFactory.h"
#include"Model\Character\Factory\EnemyFactory.h"
#include"Model\Character\Factory\GimmickFactory.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"
#include "Model\UI\PlayerHpBar.h"
#include "Model\UI\PlayerStaminaBar.h"

using namespace cocos2d::experimental;


/*
*	@desc	コンストラクタ
*/
CStage1::CStage1()
{

}

/*
*	@desc	デストラクタ
*/
CStage1::~CStage1()
{

}


/**
*	@desc	初期化
*	@return	true...成功	false...失敗
*/
bool CStage1::init() {

	// 親レイヤーの初期化
	if (CStage::init() == false) {
		return false;
	}

	//UIレイヤーの生成と取り付け
	this->m_pUILayer = Layer::create();
	this->addChild(this->m_pUILayer);

	//メインレイヤーの生成と取り付け
	this->m_pMainLayer = Layer::create();
	this->addChild(this->m_pMainLayer);

	//マップの生成と取り付け
	this->m_pMainLayer->addChild(CMapManager::getInstance()->createMap(MAP_DATA_SAMPLE));

	//キャラクターの集まりの生成
	this->m_pCharacters = new std::vector<CCharacter*>();
	//キャラクターの集まりをCCharacterAggregateへ設定する
	CCharacterAggregate::getInstance()->set(this->m_pCharacters);

	//出撃スケジュールの生成
	this->m_pLaunchSchedule = new std::vector<CLaunchTrigger*>();

	//出撃スケジュールを出撃スケジューラーに取り付ける
	CLaunchScheduler::getInstance()->createLaunch(this->m_pLaunchSchedule);


	// プレイヤーの生成と取り付け
	CCharacter* pPlayerChara = CPlayerFactoryManager::getInstance()->create(CPlayerFactoryManager::TYPE::BASE);
	//プレイヤー１のタグを設定
	pPlayerChara->m_tag = TAG_PLAYER_1;
	//CCharacterAggregateにプレイヤーを追加
	CCharacterAggregate::getInstance()->add(pPlayerChara);
	//プレイヤーをレイヤーに追加
	this->m_pMainLayer->addChild(pPlayerChara);


	//プレイヤーUIの生成と取り付け
	CPlayerHpBar* pPlayerHpBar = CPlayerHpBar::create(pPlayerChara,150, WINDOW_TOP - 64);
	this->m_pUILayer->addChild(pPlayerHpBar);
	CPlayerStaminaBar* pPlayerStaminaBar = CPlayerStaminaBar::create(pPlayerChara, 150, WINDOW_TOP - 96);
	this->m_pUILayer->addChild(pPlayerStaminaBar);



	//スクロールが行われた時に敵の出撃判定を行う
	CMap* pMap = CMapManager::getInstance()->getMap();

	//スクロールが行われた時にギミックの出撃判定を行う

	//マップの位置を取得
	//cocos2d::Point pt = this->m_pMainLayer->getPosition();
	//	pMap->checkGimmickLaunch(pt.x, pt.y);

	// タイトルBGMの再生
	int musicID = AudioEngine::play2d(SOUND_STAGE_1_BGM, true, 0.0f);
	// ID設定
	CSoundManager::getInstance()->setMusicID(BGM_STAGE1, musicID);

	return true;

}

//EOF