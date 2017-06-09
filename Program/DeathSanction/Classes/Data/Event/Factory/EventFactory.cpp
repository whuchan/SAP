#include "EventFactory.h"

/**
* @desc コンストラクタ
*/
CEventPartsFactory::CEventPartsFactory()
{

}

/**
* @desc デストラクタ
*/
CEventPartsFactory::~CEventPartsFactory()
{

}

/**
* @desc 状態遷移マシンの取得
* @return 状態遷移マシンのインスタンス
*/
CStateMachine* CEventPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}