#pragma once

#include "PlayerState.h"
#include "cocos2d.h"

//==========================================
//
// Class: CPlayerStateLineUp
//
// プレイヤー ラインダウン 状態クラス
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
class CPlayerStateLineDown :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerStateLineDown(CPlayerCharacter* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerStateLineDown(void);

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
	cocos2d::Action* m_pAction = NULL;
};
//EOF