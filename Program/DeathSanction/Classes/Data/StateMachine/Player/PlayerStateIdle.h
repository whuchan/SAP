#pragma once

#include "PlayerState.h"

//==========================================
//
// Class: CPlayerStateIdle
//
// プレイヤー 待機 状態クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateIdle :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerStateIdle(CPlayerCharacter* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerStateIdle(void);

	/**
	* @desc	開始処理
	*/
	void enter(void)override;
	/**
	* @desc	更新処理
	*/
	void execute(float deltaTime)override;

	/**
	* @desc	状態が変わるときの処理
	*/
	void exit(void)override;

private:
};
