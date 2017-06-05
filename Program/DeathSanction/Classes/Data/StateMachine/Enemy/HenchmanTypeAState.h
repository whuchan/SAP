#pragma once
//==========================================
//
// File: HenchmanTypeAState.h
//
// エネミー状態遷移 ヘッダーファイル
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "EnemyState.h"
#include "Classes\Model\Character\HenchmanTypeAEnemy.h"


//==========================================
//
// Class: CHenchmanTypeAEnemy
//
// 子分A 状態 基底クラス
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================
class CHenchmanTypeAState : public CEnemyState<CHenchmanTypeAEnemy>
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CHenchmanTypeAState(CHenchmanTypeAEnemy* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CHenchmanTypeAState(void);

	
};
//EOF