//==========================================
//
// File: EffectFactory.h
//
// エフェクト工場ファイル
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================
#include"EffectFactory.h"

/**
* @desc コンストラクタ
*/
CEffectPartsFactory::CEffectPartsFactory()
{

}
/**
* @desc デストラクタ
*/
CEffectPartsFactory::~CEffectPartsFactory()
{

}


/**
* @desc 移動データの取得
* @return 移動データ
*/
CMove*	CEffectPartsFactory::getMove(void)
{
	//移動データの作成
	return new CMove();
}


/**
* @desc 実体データの取得
* @return 実体データ
*/
CBody*	CEffectPartsFactory::getBody(void)
{
	//実体データの作成
	return new CBody();
}

/**
* @desc 衝突判定領域データ群の取得
* @return 衝突判定領域データ群
*/
std::vector<CCollisionArea*>* CEffectPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}

/**
* @desc 状態遷移マシンの取得
* @return 状態遷移マシンのインスタンス
*/
CStateMachine* CEffectPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}
//EOF