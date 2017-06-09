#include"PlayerStateAttack1.h"
#include"Model\Character\PlayerCharacter.h"
#include "Lib\Input\InputManager.h"
#include "cocos2d.h"
#include "Model\Character\Factory\DamageFactoryManager.h"
#include "Model\Character\Character.h"
using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateAttack1
//
// プレイヤー　攻撃1 状態クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerStateAttack1::CPlayerStateAttack1(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CPlayerStateAttack1::~CPlayerStateAttack1(void) {}

/**
* @desc	開始処理
*/
void CPlayerStateAttack1::enter(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerStateAttack1::execute(float deltaTime)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: Attack1");
#endif // _DEBUG_PLAYER_STATE


	Vec2 luanchPos = this->m_pOwner->m_pMove->m_pos;
	CCharacterAggregate::getInstance()->add(CDamageFactoryManager::getInstance()->create(DAMAGE_TYPE::PLAYER_ATTACK_1, luanchPos.x, luanchPos.y));

	this->toIdle();
	return;
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerStateAttack1::exit(void)
{
	this->m_isNext = false;
}
//EOF