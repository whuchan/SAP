#pragma once
//==========================================
//
// File: CHenchmanTypeAStateIdle.h
//
// 子分A待機状態 ヘッダーファイル
//
// 2017/06/05
//						Author Shinya Ueba
//==========================================
#include"HenchmanTypeAState.h"

class CHenchmanTypeAStateIdle :public CHenchmanTypeAState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CHenchmanTypeAStateIdle(CHenchmanTypeAEnemy* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	virtual ~CHenchmanTypeAStateIdle(void);
	
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
};
//EOF