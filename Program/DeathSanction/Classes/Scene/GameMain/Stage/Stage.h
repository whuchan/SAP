#pragma once
//==========================================
//
// File: Stage.h
//
// ステージ 基底　ヘッダーファイル
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "cocos2d.h"
#include "Constants.h"

//=========================================================================
//	前方宣言
//=========================================================================
class CCharacter;
class CPlayerCharacter;
class CEnemyLaunchData;
class CGimmickLaunchData;
class CLaunchTrigger;

//==========================================
//
// Class: CStage
//
// ステージ　基底クラス   
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================
class CStage : public cocos2d::Layer
{
public:

	/*
	*	@desc	コンストラクタ
	*/
	CStage();

	/*
	*	@desc	デストラクタ
	*/
	~CStage();

	/**
	*	@desc	キーボードのキーを押した際のイベント
	*	@param	キーコード
	*	@param	イベント
	*/
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;

	/**
	*	@desc	キーボードのキーを離した際のイベント
	*	@param	キーコード
	*	@param	イベント
	*/
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) override;

	/**
	*	@desc	初期化
	*	@return	true...成功	false...失敗
	*/
	virtual bool init() override;

	/**
	* @desc 生成処理
	*/
	CREATE_FUNC(CStage);

	/**
	*	@desc	更新処理
	*	@param	経過時間
	*/
	virtual void update(float deltaTime_) override;

	//=========================================================================
	//	ここまでは理解出来るまでは変更禁止
	//=========================================================================

	/*
	* @desc 画面スクロール
	* @tips 今回は強制スクロールではなくキャラクターの移動による画面のスクロールとなる
	*/
	void scroll();


	/**
	*	@desc	チェックと取り外し処理 ( 単体 )
	*	@tips	有効フラグが false のインスタンスをレイヤーから取り外す
	*/
	template <typename Ty>
	void checkAndRemove(Ty* pChara);
	/**
	*	@desc	チェックと取り外し処理 ( 複数 )
	*	@tips	有効フラグが false のインスタンスをレイヤーと std::vector から取り外す
	*/
	template <typename Ty>
	void checkAndRemove(std::vector<Ty*>* pCharas);

	/**
	* @desc チェックと解放
	* @tips 有効フラグがfalseのインスタンスを解放しstd::vectorから取り外す
	*/
	template <typename Ty>
	void checkAndDelete(std::vector<Ty*>* pVector);


	/**
	* @desc メインレイヤーの取得
	* @return メインレイヤーインスタンス
	*/
	cocos2d::Layer* getMainLayer();

	/**
	* @desc UIレイヤーの取得
	* @return UIレイヤーインスタンス
	*/
	cocos2d::Layer* getUILayer();


protected:

	//=========================================================================
	//	メンバ宣言
	//		ゲームメイン内で使用するメンバはここ以降に記述していく
	//=========================================================================
	//メインレイヤー
	cocos2d::Layer* m_pMainLayer = NULL;

	//UI レイヤー
	cocos2d::Layer* m_pUILayer = NULL;

	//キャラクターの集まりの本体
	std::vector<CCharacter*>* m_pCharacters = NULL;

	//出撃スケジュール
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;
};

