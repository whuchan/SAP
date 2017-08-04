#pragma once
//==========================================
//
// File: CHenchmanTypeAStateMove.h
//
// 子分A移動状態 ヘッダーファイル
//
// 2017/07/03
//						Author Shinya Ueba
//==========================================
#include"HenchmanTypeAState.h"

class CHenchmanTypeAStateMove :public CHenchmanTypeAState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CHenchmanTypeAStateMove(CHenchmanTypeAEnemy* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	virtual ~CHenchmanTypeAStateMove(void);

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
	CCharacter* m_pTarget = NULL;
};
//EOF