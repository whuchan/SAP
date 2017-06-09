#include"PlayerStateIdle.h"
#include"Model\Character\PlayerCharacter.h"
#include"cocos2d.h"
#include "Lib\Input\InputManager.h"

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
void CPlayerStateIdle::execute(float deltaTime)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player; Idle");
#endif//_DEBUG_PLAYER_STATE
	if (inputflag.m_d || inputflag.m_a)
	{
		this->toWalk();
		return;
	}

	if (inputflag.getTrigger(kInputType::W) &&
		this->m_pOwner->m_intCurrentLine < STAGE_MAX_LINE)
	{
		
		//ラインアップ状態へ
		this->toLineUp();
		return;
	}
	else if (inputflag.getTrigger(kInputType::S) &&
		this->m_pOwner->m_intCurrentLine > 0)
	{
		//ラインダウン状態へ
		this->toLineDown();
		return;
	}

	if (inputflag.getTrigger(kInputType::C))
	{
		this->toAttack1();
		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerStateIdle::exit(void)
{
	this->m_isNext = false;
}
//EOF