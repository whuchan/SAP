#include "HenchmanTypeAStateIdle.h"
//==========================================
//
// File: CHenchmanTypeAStateIdle.cpp
//
// 子分A待機状態 ファイル
//
// 2017/06/05
//						Author Shinya Ueba
//==========================================


/**
* @desc	コンストラクタ
*/
CHenchmanTypeAStateIdle::CHenchmanTypeAStateIdle(CHenchmanTypeAEnemy* const pOwner) :CHenchmanTypeAState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CHenchmanTypeAStateIdle::~CHenchmanTypeAStateIdle(void)
{

}

/**
* @desc	開始処理
*/
void CHenchmanTypeAStateIdle::enter(void)
{

}
/**
* @desc	更新処理
*/
void CHenchmanTypeAStateIdle::execute(float deltaTime)
{
#ifdef _DEBUG_ENEMY_STATE
	log("Enemy: LineDown");
#endif //_DEBUG_ENEMY_STATE

}
/**
* @desc	状態が変わるときの処理
*/
void CHenchmanTypeAStateIdle::exit(void)
{
	this->m_isNext = false;
}
//EOF