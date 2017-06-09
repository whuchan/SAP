//==========================================
//
// File: CStage.cpp
//
// ステージ１ ファイル
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

#include "Stage.h"

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
#include"Model\Character\Factory\EnemyFactoryManager.h"
#include"Model\Character\Factory\GimmickFactory.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"


/**
*	@desc	キーボードのキーを押した際のイベント
*	@param	キーコード
*	@param	イベント
*/
void CStage::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {

	// 入力管理に入力処理を委託
	CInputManager::getInstance()->onKeyPressed(keyCode);
}

/**
*	@desc	キーボードのキーを離した際のイベント
*	@param	キーコード
*	@param	イベント
*/
void CStage::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) {

	// 入力管理に入力処理を委託
	CInputManager::getInstance()->onKeyReleased(keyCode);
}

/*
*	@desc	コンストラクタ
*/
CStage::CStage()
{

}

/*
*	@desc	デストラクタ
*/
CStage::~CStage()
{
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
bool CStage::init() {

	// 親レイヤーの初期化
	if (Layer::init() == false) {
		return false;
	}

	// 乱数生成
	srand((unsigned int)time(NULL));

	// キーボード入力イベント受け取り設定
	this->setKeyboardEnabled(true);

	// update 関数 ( 更新処理関数 ) 呼び出し設定
	// この部分を消したりコメントアウトすると update 関数が呼ばれなくなるので注意
	this->scheduleUpdate();

	return true;

}

/**
*	@desc	更新処理
*	@param	１フレーム経過時間
*/
void CStage::update(float deltaTime_) {

	

	// esc キーを押したらゲーム終了
	if (inputflag.m_esc == true) {
		cocos2d::Director::getInstance()->end();
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

	//入力更新処理
	inputflag.update();
}


/*
* @desc 画面スクロール
* @tips 今回は強制スクロールではなくキャラクターの移動による画面のスクロールとなる
*/
void CStage::scroll()
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

		//スクロールが行われた時にギミックの出撃判定を行う
		//		pMap->checkGimmickLaunch(pt.x, pt.y);
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


/**
*	@desc	チェックと取り外し処理 ( 単体 )
*	@tips	有効フラグが false のインスタンスをレイヤーから取り外す
*/
template <typename Ty>
void CStage::checkAndRemove(Ty* pChara) {

	if (pChara->m_activeFlag == false) {
		pChara->removeFromParent();
	}
}

/**
*	@desc	チェックと取り外し処理 ( 複数 )
*	@tips	有効フラグが false のインスタンスをレイヤーと std::vector から取り外す
*/
template <typename Ty>
void CStage::checkAndRemove(std::vector<Ty*>* pCharas) {

	// ローカル変数の型のテンプレート引数の指定として
	// テンプレート引数を指定する場合は typename 指定をつけなければならない
	typename std::vector<Ty*>::iterator itr = pCharas->begin();
	while (itr != pCharas->end()) {

		if ((*itr)->m_activeFlag == false) {

			(*itr)->removeFromParent();
			itr = pCharas->erase(itr);

		}
		else {
			itr++;
		}
	}
}

/**
* @desc チェックと解放
* @tips 有効フラグがfalseのインスタンスを解放しstd::vectorから取り外す
*/
template <typename Ty>
void CStage::checkAndDelete(std::vector<Ty*>* pVector)
{
	//ローカル変数の型のテンプレート引数の指定として
	//テンプレート引数を指定する場合はtypename指定をつけなければならない
	typename std::vector<Ty*>::iterator itr = pVector->begin();

	while (itr != pVector->end())
	{
		if ((*itr)->m_activeFlag == false)
		{
			SAFE_DELETE((*itr));

			itr = pVector->erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

/**
* @desc メインレイヤーの取得
* @return メインレイヤーインスタンス
*/
cocos2d::Layer* CStage::getMainLayer()
{
	return this->m_pMainLayer;
}

/**
* @desc UIレイヤーの取得
* @return UIレイヤーインスタンス
*/
cocos2d::Layer* CStage::getUILayer()
{
	return this->m_pUILayer;
}

//EOF