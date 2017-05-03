#include"PlayerStateLineDown.h"
#include "Model\Character\PlayerCharacter.h"
#include"cocos2d.h"
#include "Lib\Input\InputManager.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateLineDown
//
// プレイヤー ラインダウン 状態クラス
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerStateLineDown::CPlayerStateLineDown(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CPlayerStateLineDown::~CPlayerStateLineDown(void) {}

/**
* @desc	開始処理
*/
void CPlayerStateLineDown::enter(void)
{
	this->m_pOwner->m_intCurrentLine--;

	// 1秒かけて、スケールを拡大する
	ScaleTo* pOrder = ScaleTo::create(1.0, 1.0f - this->m_pOwner->m_intCurrentLine * 0.2f);
	this->m_pAction = this->m_pOwner->runAction(pOrder);
	CC_SAFE_RETAIN(this->m_pAction); // 勝手に開放されないように参照カウンタを増やす
}

/**
* @desc	更新処理
*/
void CPlayerStateLineDown::execute(void)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: LineDown");
#endif //_DEBUG_PLAYER_STATE
	if (this->m_pAction->isDone())
	{
		//待機状態へ移行
		this->toIdle();
		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerStateLineDown::exit(void)
{
	this->m_isNext = false;


	//使わなくなったら解放する
	CC_SAFE_RELEASE(this->m_pAction);
}
//EOF