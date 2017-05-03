#include"PlayerStateWalk.h"
#include"Model\Character\PlayerCharacter.h"
#include "Lib\Input\InputManager.h"
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
void CPlayerStateWalk::execute(float deltaTime)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: Walk");
#endif // _DEBUG_PLAYER_STATE

	this->m_pOwner->m_pMove->m_accele.x = 0.0f;


	if (inputflag.m_d)
	{
		this->m_pOwner->m_pMove->m_accele.x = 0.7f;
		return;
	}

	if (inputflag.m_a)
	{
		this->m_pOwner->m_pMove->m_accele.x = -0.7f;
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
	
	//何もしなかったら、待機状態へ
	this->toIdle();
	return;
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerStateWalk::exit(void)
{
	this->m_isNext = false;

	this->m_pOwner->m_pMove->m_accele.x = 0.0f;
}
//EOF