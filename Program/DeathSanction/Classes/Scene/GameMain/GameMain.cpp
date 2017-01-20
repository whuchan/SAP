
//
//  GameMain.cpp
//  ActionGame
//
//  Created by 上羽慎哉
//
//

#include "GameMain.h"

// 入力
#include "Lib/Input/InputManager.h"
// 乱数生成用
#include <stdlib.h>
#include <time.h>
// サウンド用
#include "SimpleAudioEngine.h"

#include"Model\Map\Map.h"
#include"Model\Character\Character.h"
#include"Model\Character\Factory\PlayerFactory.h"
#include"Model\Character\Factory\EnemyFactory.h"
#include"Model\Character\Factory\GimmickFactory.h"
#include "Data\LaunchData\LaunchData.h"

using namespace CocosDenshion;



/**
 *	@desc	シーンの生成
 *	@return	CMain レイヤーを内包したシーンクラスインスタンス
 *	@tips	静的メンバ関数
 */
cocos2d::Scene* CGameMain::createScene() {
	
	// シーンの生成
	cocos2d::Scene* pScene = cocos2d::Scene::create();
	
	// GameMain レイヤーの生成
	CGameMain* pLayer = CGameMain::create() ;
	
	// CMain レイヤーをシーンに取り付ける
	pScene->addChild( pLayer, 0, TAG_GAME_MAIN ) ;
	
	// 生成したシーンを返す
	return pScene ;
}

/**
 *	@desc	キーボードのキーを押した際のイベント
 *	@param	キーコード
 *	@param	イベント
 */
void CGameMain::onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event ) {

	// 入力管理に入力処理を委託
	CInputManager::getInstance()->onKeyPressed( keyCode ) ;
}

/**
 *	@desc	キーボードのキーを離した際のイベント
 *	@param	キーコード
 *	@param	イベント
 */
void CGameMain::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event ) {

	// 入力管理に入力処理を委託
	CInputManager::getInstance()->onKeyReleased( keyCode ) ;
}

// デストラクタ
CGameMain::~CGameMain() {

	// BGM の停止
	SimpleAudioEngine::getInstance()->stopBackgroundMusic() ;
	
	// 全ての効果音を停止
	SimpleAudioEngine::getInstance()->stopAllEffects() ;

	//敵生成工場管理クラスの解放
	CEnemyFactoryManager::removeInstance();

	//プレイヤー生成工場管理クラスの解放
	CPlayerFactoryManager::removeInstance();

	//キャラクターの集まりの破棄
	SAFE_DELETE(this->m_pCharacters);


	//出撃トリガーの破棄
	for (CLaunchTrigger* pTrigger : (*this->m_pLaunchSchedule))
	{
		SAFE_DELETE(pTrigger);
	}
	//出撃スケジュールの破棄
	SAFE_DELETE(this->m_pLaunchSchedule);

	//CCharacterAggregateの共有インスタンスの破棄
	CCharacterAggregate::removeInstance();

}


/**
 *	@desc	初期化
 *	@return	true...成功	false...失敗
 */
bool CGameMain::init() {
	
	// 親レイヤーの初期化
	if ( Layer::init() == false ) {
		return false ;
	}
	
	// 乱数生成
	srand( (unsigned int)time( NULL ) ) ;
	
	// キーボード入力イベント受け取り設定
	this->setKeyboardEnabled(true) ;
	
	// update 関数 ( 更新処理関数 ) 呼び出し設定
	// この部分を消したりコメントアウトすると update 関数が呼ばれなくなるので注意
	this->scheduleUpdate() ;
	
	
	//=========================================================================
	//
	//	ここから初期化、初期設定のコードを追加
	//
	//=========================================================================
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
	

	//スクロールが行われた時に敵の出撃判定を行う
	CMap* pMap = CMapManager::getInstance()->getMap();
	//マップの位置を取得
	cocos2d::Point pt = this->m_pMainLayer->getPosition();
	pMap->checkGimmickLaunch(pt.x, pt.y);




	//=========================================================================
	//
	//	ここまでに初期化、初期設定のコードを追加
	//
	//=========================================================================
	
	return true ;
	
}

/**
 *	@desc	更新処理
 *	@param	１フレーム経過時間
 */
void CGameMain::update( float deltaTime_ ) {

	// esc キーを押したらゲーム終了
	if ( inputflag.m_esc == true ) {
		cocos2d::Director::getInstance()->end() ;
	}

	//=========================================================================
	//
	//	ここから更新処理のコードを追加
	//
	//=========================================================================
	
	//=========================================================
	// 出撃スケジューラーの起動
	//=========================================================
	//キャラクターを出撃させる
	CLaunchScheduler::getInstance()->launchCharacters(this->m_pMainLayer);

	//出撃の完了したトリガーを全て取り外す
	this->checkAndDelete(this->m_pLaunchSchedule);

	//=========================================================================
	//	衝突判定処理に関するコードの追加はここから
	//=========================================================================
	
	
	
	//=========================================================================
	//	画面のスクロール
	//=========================================================================
	this->scroll();
	

	//=========================================================================
	//	取り外しに関するコードの追加はここから
	//=========================================================================
	this->checkAndRemove(this->m_pCharacters);
	
	//=========================================================================
	//
	//	ここまでに更新処理のコードを追加
	//
	//=========================================================================
}


/*
* @desc 画面スクロール
* @tips 今回は強制スクロールではなくキャラクターの移動による画面のスクロールとなる
*/
void CGameMain::scroll()
{
	//マップの位置を取得
	cocos2d::Point pt = this->m_pMainLayer->getPosition();

	//プレイヤーキャラクターの取得
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	//プレイヤーの位置が３分の２を超えたら
	if (pt.x > (WINDOW_RIGHT / 3.0) * 2.0f - pPlayerChara->m_pMove->m_pos.x)
	{
		//原点位置を超えた分に設定する
		pt.x = (WINDOW_RIGHT / 3.0) * 2.0f - pPlayerChara->m_pMove->m_pos.x;

		//超えた分を設定する
		this->m_pMainLayer->setPosition(pt);

		//スクロールが行われた時に敵の出撃判定を行う
		CMap* pMap = CMapManager::getInstance()->getMap();
		pMap->checkEnemyLaunch(pt.x, pt.y);
		pMap->checkGimmickLaunch(pt.x, pt.y);
	}
	else if (pt.x < (WINDOW_RIGHT / 3.0) - pPlayerChara->m_pMove->m_pos.x)
	{
		//プレイヤーの位置が３分の１以下になったら

		//原点位置を超えた分に設定する
		pt.x = (WINDOW_RIGHT / 3.0) - pPlayerChara->m_pMove->m_pos.x;
	
		//超えた分を設定する
		this->m_pMainLayer->setPosition(pt);
	}

	
	
}


