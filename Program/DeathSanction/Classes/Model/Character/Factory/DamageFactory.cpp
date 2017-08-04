//==========================================
//
// File: DamageFactory.h
//
// ダメージ工場 ファイル
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================


#include"DamageFactory.h"

/**
* @desc コンストラクタ
*/
CDamagePartsFactory::CDamagePartsFactory()
{

}
/**
* @desc デストラクタ
*/
CDamagePartsFactory::~CDamagePartsFactory()
{

}


/**
* @desc 移動データの取得
* @return 移動データ
*/
CMove*	CDamagePartsFactory::getMove(void)
{
	//移動データの作成
	return new CMove();
}


/**
* @desc 実体データの取得
* @return 実体データ
*/
CBody*	CDamagePartsFactory::getBody(void)
{
	//実体データの作成
	return new CBody();
}

/**
* @desc 衝突判定領域データ群の取得
* @return 衝突判定領域データ群
*/
std::vector<CCollisionArea*>* CDamagePartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}

/**
* @desc 状態遷移マシンの取得
* @return 状態遷移マシンのインスタンス
*/
CStateMachine* CDamagePartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}
//EOF