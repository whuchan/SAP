#include"PlayerStateWalk.h"
#include "cocos2d.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateWalk
//
// プレイヤー 待機 状態クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerStateWalk::CPlayerStateWalk(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CPlayerStateWalk::~CPlayerStateWalk(void) {}

/**
* @desc	開始処理
*/
void CPlayerStateWalk::enter(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerStateWalk::execute(void)
{
	log("Player: Walk");
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerStateWalk::exit(void)
{
	this->m_isNext = false;
}
//EOF