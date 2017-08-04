#include "HenchmanTypeAStateMove.h"
#include "Model\Character\Character.h"
#include "Lib\Math\CustomMath.h"

//==========================================
//
// File: CHenchmanTypeAStateMove.cpp
//
// 子分A待機状態 ファイル
//
// 2017/06/05
//						Author Shinya Ueba
//==========================================


/**
* @desc	コンストラクタ
*/
CHenchmanTypeAStateMove::CHenchmanTypeAStateMove(CHenchmanTypeAEnemy* const pOwner) :CHenchmanTypeAState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CHenchmanTypeAStateMove::~CHenchmanTypeAStateMove(void)
{

}

/**
* @desc	開始処理
*/
void CHenchmanTypeAStateMove::enter(void)
{
	this->m_pTarget = CCharacterAggregate::getInstance()->getPlayer();
}
/**
* @desc	更新処理
*/
void CHenchmanTypeAStateMove::execute(float deltaTime)
{
#ifdef _DEBUG_ENEMY_STATE
	log("Enemy: Move");
#endif //_DEBUG_ENEMY_STATE
	float length = CustomMath::distance(this->m_pTarget->m_pMove->m_pos,this->m_pOwner->m_pMove->m_pos);

//	if ()
	{
		this->toIdle();
		return;
	}
}
/**
* @desc	状態が変わるときの処理
*/
void CHenchmanTypeAStateMove::exit(void)
{
	this->m_isNext = false;
}
//EOF