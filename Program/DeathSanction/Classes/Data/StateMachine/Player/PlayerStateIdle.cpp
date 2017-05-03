#include"PlayerStateIdle.h"
#include"cocos2d.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateIdle
//
// プレイヤー 待機 状態クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerStateIdle::CPlayerStateIdle(CPlayerCharacter* const pOwner):CPlayerState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CPlayerStateIdle::~CPlayerStateIdle(void) {}

/**
* @desc	開始処理
*/
void CPlayerStateIdle::enter(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerStateIdle::execute(void)
{
	log("Player; Idle");
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerStateIdle::exit(void)
{
	this->m_isNext = false;
}
//EOF