#include"PlayerStateLineUp.h"
#include "Model\Character\PlayerCharacter.h"
#include "Lib\Input\InputManager.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateLineUp
//
// プレイヤー ラインアップ 状態クラス
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerStateLineUp::CPlayerStateLineUp(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CPlayerStateLineUp::~CPlayerStateLineUp(void)
{

}

/**
* @desc	開始処理
*/
void CPlayerStateLineUp::enter(void)
{
	this->m_pOwner->m_intCurrentLine++;

	// 1秒かけて、スケールを縮小する
	ScaleTo* pOrder = ScaleTo::create(0.5, 1.0f - this->m_pOwner->m_intCurrentLine * 0.2f);
	this->m_pAction = this->m_pOwner->runAction(pOrder);
	CC_SAFE_RETAIN(this->m_pAction); // 勝手に開放されないように参照カウンタを増やす

	//ジャンプアクションのスタート関数を開始
	//(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::ACTION::JUMP])[0]->start();

	this->m_pOwner->m_pMove->m_vel.y = sqrtf(((CPhysicalGravity::GRAVITY * 0.6f) * (CPhysicalGravity::GRAVITY * 0.6f)) / 2.0f);
}

/**
* @desc	更新処理
*/
void CPlayerStateLineUp::execute(float deltaTime)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: LineUp");
#endif //_DEBUG_PLAYER_STATE

	if (inputflag.m_d)
	{
		this->m_pOwner->m_pMove->m_vel.x = 100.0f;
	}
	else if (inputflag.m_a)
	{
		this->m_pOwner->m_pMove->m_vel.x = -100.0f;
	}


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
void CPlayerStateLineUp::exit(void)
{
	this->m_isNext = false;

	//使わなくなったら解放する
	CC_SAFE_RELEASE(this->m_pAction);

	//(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::ACTION::JUMP])[0]->restart(this->m_pOwner);
}
//EOF