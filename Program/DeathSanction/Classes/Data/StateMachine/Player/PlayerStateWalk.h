#pragma once

#include "PlayerState.h"

//==========================================
//
// Class: CPlayerStateWalk
//
// プレイヤー 待機 状態クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateWalk :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerStateWalk(CPlayerCharacter* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerStateWalk(void);

	/**
	* @desc	開始処理
	*/
	void enter(void)override;
	/**
	* @desc	更新処理
	*/
	void execute(void)override;

	/**
	* @desc	状態が変わるときの処理
	*/
	void exit(void)override;

private:
};
//EOF