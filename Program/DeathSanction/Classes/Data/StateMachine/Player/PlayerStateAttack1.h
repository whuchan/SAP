#pragma once

#include "PlayerState.h"

//==========================================
//
// Class: CPlayerStateAttack1
//
// プレイヤー 攻撃１ 状態クラス
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================
class CPlayerStateAttack1 :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerStateAttack1(CPlayerCharacter* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerStateAttack1(void);

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
//EOF