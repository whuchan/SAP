#pragma once
//==========================================
//
// File: Stage1.h
//
// ステージ１ ヘッダーファイル
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "Stage.h"

//==========================================
//
// Class: CStage1
//
// ステージ1クラス   
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================
class CStage1 : public CStage
{
public:

	/*
	*	@desc	コンストラクタ
	*/
	CStage1();

	/*
	*	@desc	デストラクタ
	*/
	~CStage1();

	/*
	*	@desc	シーン生成時に初期化関数を処理
	*			初期化関数失敗時は NULL を返す
	*/
	CREATE_FUNC(CStage1);

	
	/**
	*	@desc	初期化
	*	@return	true...成功	false...失敗
	*/
	bool init() override;
};

