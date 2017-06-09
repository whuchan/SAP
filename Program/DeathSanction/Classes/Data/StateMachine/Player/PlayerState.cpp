//==========================================
//
// File: PlayerState.cpp
//
// プレイヤー状態遷移 ヘッダーファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "PlayerState.h"
#include "Classes\Model\Character\PlayerCharacter.h"



//==========================================
//
// Class: CPlayerState
//
// プレイヤー 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerState::CPlayerState(CPlayerCharacter* const pOwner):m_pOwner(pOwner)
{

}

/**
 * @desc	デストラクタ 
 */
CPlayerState::~CPlayerState(void)
{

}

/**
 * @desc	待機状態へ移行
 */
void CPlayerState::toIdle(void)
{

	//プレイヤーの状態
	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::IDLE;

	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	歩行状態へ移行
 */
void CPlayerState::toWalk(void)
{
	this->m_pOwner->m_state				= (int)CPlayerCharacter::STATE::WALK;

	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
*	@desc	ラインアップ状態へ移行
*/
void CPlayerState::toLineUp(void)
{
	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::LINE_UP;

	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
*	@desc	ラインダウン状態へ移行
*/
void CPlayerState::toLineDown(void)
{
	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::LINE_DOWN;

	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	攻撃状態へ移行
*/
void CPlayerState::toAttack1(void)
{
	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::ATTACK_1;

	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}




///**
// * @desc	ジャンプ状態へ移行
// */
//void CPlayerState::toJump(void)
//{
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::JUMP;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//待機動作を終了
//	this->m_isNext = true;
//}
//
///**
// * @desc	落下状態へ移行
// */
//void CPlayerState::toFall(void)
//{
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::FALL;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//待機動作を終了
//	this->m_isNext = true;
//}
//
//
///**
// * @desc	攻撃状態へ移行
// */
//void CPlayerState::toAttack(void) {
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::ATTACK;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//待機動作を終了
//	this->m_isNext = true;
//}
//
//
///**
// * @desc	ジャンプ攻撃へ移行
// */
//void CPlayerState::toJumpAttack(void) {
//	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::JUMP_ATTACK;
//
//	this->m_nextRegisterKey = this->m_pOwner->m_state;
//	//待機動作を終了
//	this->m_isNext = true;
//}
//
//
///**
// * @desc	攻撃を受けた状態へ移行
// */
//void CPlayerState::toUnderAttack(void) {
//	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::UNDER_ATTACK;
//
//	this->m_nextRegisterKey = this->m_pOwner->m_state;
//
//	this->m_isNext = true;
//}
//
//
///*
// * @desc	手を掴む状態へ移行
// */
//void CPlayerState::toGrasp(void)
//{
//	this->m_pOwner->m_state			= (int)CPlayerCharacter::STATE::GRASP;
//
//	this->m_nextRegisterKey				= this->m_pOwner->m_state;
//	//待機動作を終了
//	this->m_isNext = true;
//}
//
//
///*
// *	@desc	お姫様抱っこ状態へ移行
// */
//void CPlayerState::toHold(void)
//{
//	//次の総合的なプレイヤーの状態
//	this->m_pOwner->m_state = (int)CPlayerCharacter::STATE::HOLD;
//
//	//次の総合的なプレイヤーの状態を次に行くステートとして指定
//	this->m_nextRegisterKey = this->m_pOwner->m_state;
//
//	//待機動作を終了
//	this->m_isNext = true;
//}




////==========================================
////
//// Class: CPlayerJumpState
////
//// プレイヤー ジャンプ 状態クラス
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
// * @desc	コンストラクタ
// */
//CPlayerJumpState::CPlayerJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	デストラクタ
//*/
//CPlayerJumpState::~CPlayerJumpState(void) {}
//
///**
//* @desc	開始処理
//*/
//void CPlayerJumpState::start(void)
//{
//	//ジャンプアクションのスタート関数を開始
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::JUMP])[0]->start();
//
//	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
//}
//
///**
//* @desc	更新処理
//*/
//void CPlayerJumpState::update(void)
//{
//	//優先順で処理していく
//	//入力コントローラーの取得
//	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
//
//	//プレイヤーが攻撃を受けたら
//	if (this->m_pOwner->m_underAttack) {
//		//攻撃を受けた状態へ移行
//		this->toUnderAttack();
//	}
//
//	if (pointerInputController->getAttackFlag()) {
//		//右ジャンプ攻撃状態へ移行する
//		//this->toJumpAttack();
//		return;
//	}
//
//	//プレイヤーの速度を維持させる
//	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
//
//	//右移動
//	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
//		this->m_pOwner->m_pMove->m_vel.x += 1.0f;
//	}
//	//左移動
//	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
//		this->m_pOwner->m_pMove->m_vel.x += -1.0f;
//	}
//
//	//プレイヤーが下へ移動していたら
//	if (this->m_pOwner->m_pMove->m_vel.y <= 0.0f) {
//		//落下状態へ移行する
//		this->toFall();
//
//		return;
//	}
//
//	//左向きジャンプ
//	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
//		//開始処理を再起動する
//		this->start();
//		return;
//	}
//}
//
///**
//* @desc	状態が変わるときの処理
//*/
//void CPlayerJumpState::onChangeEvent(void)
//{
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::JUMP])[0]->restart(this->m_pOwner);
//
//
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerFallState
////
//// プレイヤー 落下 状態クラス
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
//* @desc	コンストラクタ
//*/
//CPlayerFallState::CPlayerFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	デストラクタ
//*/
//CPlayerFallState::~CPlayerFallState(void) {}
//
///**
//* @desc	開始処理
//*/
//void CPlayerFallState::start(void)
//{
//	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
//}
//
///**
//* @desc	更新処理
//*/
//void CPlayerFallState::update(void)
//{
//	//優先順で処理していく
//
//	//入力コントローラーの取得
//	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
//
//	//プレイヤーが攻撃を受けたら
//	if (this->m_pOwner->m_underAttack) {
//		//攻撃を受けた状態へ移行
//		this->toUnderAttack();
//	}
//
//	if (pointerInputController->getAttackFlag()) {
//		//右ジャンプ攻撃状態へ移行する
//		//this->toJumpAttack();
//		return;
//	}
//
//	//プレイヤーの速度を維持させる
//	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
//
//	//右移動
//	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
//		this->m_pOwner->m_pMove->m_accele.x = 2.0f;
//	}
//	//左移動
//	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
//		this->m_pOwner->m_pMove->m_accele.x = -2.0f;
//	}
//
//	//プレイヤーが下へ移動していたら
//	if (this->m_pOwner->m_pMove->m_vel.y == 0.0f) {
//		//落下状態へ移行する
//		this->toIdle();
//
//		return;
//	}
//
//}
//
///**
//* @desc	状態が変わるときの処理
//*/
//void CPlayerFallState::onChangeEvent(void)
//{
//	this->m_pOwner->m_pMove->m_accele.x = 0.0f;
//
//	this->m_pOwner->m_pMove->m_vel.x = 0.0f;
//
//
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerAttackState
////
//// プレイヤー 攻撃 状態クラス
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
// * @desc	コンストラクタ
// */
//CPlayerAttackState::CPlayerAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl){}
//
///**
// * @desc	デストラクタ
// */
//CPlayerAttackState::~CPlayerAttackState(void){}
//
///**
// * @desc	開始処理
// */
//void CPlayerAttackState::start(void)
//{
//
//	//現在のアニメーションをリセット
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//
//	//攻撃アクションをスタートさせる
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::ATTACK])[0]->start();
//
//	//連撃フラグをfalseで始める
//	this->m_pOwner->m_chainAttackFlag = false;
//}
//
///**
// * @desc	更新処理
// */
//void CPlayerAttackState::update(void)
//{
//	//優先順で処理していく
//	//入力コントローラーの取得
//	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
//
//	//攻撃ボタンが押されたか
//	if (pointerInputController->getAttackFlag())
//	{
//		//攻撃連鎖フラグをtrue にする
//		this->m_pOwner->m_chainAttackFlag = true;
//	}
//
//	//アニメーションが終了したかどうかのフラグ
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//待機状態へ移行
//		this->toIdle();
//	}
//}
//
///**
// * @desc	状態が変わるときの処理
// */
//void CPlayerAttackState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	//次のステートへ移行することが確定しているので元に戻しておく
//	this->m_isNext = false;
//}
//
////==========================================
////
//// Class: CPlayerJumpAttackState
////
//// プレイヤー ジャンプ攻撃 状態クラス
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
// * @desc	コンストラクタ
// */
//CPlayerJumpAttackState::CPlayerJumpAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
// * @desc	デストラクタ
// */
//CPlayerJumpAttackState::~CPlayerJumpAttackState(){}
//
///**
// * @desc	開始処理
// */
//void CPlayerJumpAttackState::start(void)
//{
//	//現在のアニメーションをリセット
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//	
//	//プレイヤーのジャンプアクションを停止させる。
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::JUMP])[0]->stop();
//
//	//プレイヤーのｙ軸移動速度を０に戻す
//	this->m_pOwner->m_pMove->m_vel.y = 0.0f;
//
//
//	//ダメージキャラクター生成データを作成
//	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
//		cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
//		1);
//	//ダメージキャラクター生成トリガーを作成
//	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);
//
//	//作成したトリガーをスケジューラーに登録
//	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
//
//
//}
//
///**
// * @desc	更新処理
// */
//void CPlayerJumpAttackState::update(void)
//{
//	//アニメーションが終了したかどうかのフラグ
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd() && this->m_pOwner->m_pMove->m_vel.y == 0.0f)
//	{
//		//右向き待機状態へ戻す
//		this->toIdle();
//		return;
//	}
//}
//
///**
// * @desc	状態が変わるときの処理
// */
//void CPlayerJumpAttackState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	//次のステートへ移行することが確定しているので元に戻しておく
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerUnderAttackState
////
//// プレイヤー 攻撃を受けた 状態クラス
////
//// 2016/12/25
////						Author Harada
////==========================================
///**
//* @desc	コンストラクタ
//*/
//CPlayerUnderAttackState::CPlayerUnderAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	デストラクタ
//*/
//CPlayerUnderAttackState::~CPlayerUnderAttackState() {}
//
///**
//* @desc	開始処理
//*/
//void CPlayerUnderAttackState::start(void)
//{
//	//現在のアニメーションをリセット
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//
//	//現在のアクションをスタートさせる。
//	(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::STATE::UNDER_ATTACK])[0]->start();
//}
//
///**
//* @desc	更新処理
//*/
//void CPlayerUnderAttackState::update(void)
//{
//	//アニメーションが終了したかどうかのフラグ
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//待機状態へ戻す
//		this->toIdle();
//
//		this->m_pOwner->m_underAttack = false;
//
//		return;
//	}
//}
//
///**
//* @desc	状態が変わるときの処理
//*/
//void CPlayerUnderAttackState::onChangeEvent(void)
//{
//	//次のステートへ移行することが確定しているので元に戻しておく
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerGraspState
////
//// プレイヤー 手を繋ぐ 状態クラス
////
//// 2016/12/26
////						Author Harada 
////==========================================
///**
// * @desc	コンストラクタ
// */
//CPlayerGraspState::CPlayerGraspState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl){}
//
///**
// * @desc	デストラクタ
// */
//CPlayerGraspState::~CPlayerGraspState(void){}
//
///**
// * @desc	開始処理
// */
//void CPlayerGraspState::start(void)
//{
//	//現在のアニメーションをリセット
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//}
//
///**
// * @desc	更新処理
// */
//void CPlayerGraspState::update(void)
//{
//	//優先順で処理していく
//
//	//手を繋ぐアニメーションが終わったら
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//右向き待機状態へ移行
//		this->m_pOwner->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS;
//
//		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_playerAndGirlState]->setStartState((int)CPlayerCharacter::STATE::IDLE);
//	}
//}
//
///**
// * @desc	状態が変わるときの処理
// */
//void CPlayerGraspState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	this->m_isNext = false;
//}
//
//
////==========================================
////
//// Class: CPlayerHoldState
////
//// プレイヤー お姫様抱っこ 状態クラス
////
//// 2017/ 1/ 5
////						Author Harada
////==========================================
///**
//* @desc	コンストラクタ
//*/
//CPlayerHoldState::CPlayerHoldState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
//	:CPlayerState::CPlayerState(pPlayer, pGirl) {}
//
///**
//* @desc	デストラクタ
//*/
//CPlayerHoldState::~CPlayerHoldState(void) {}
//
///**
//* @desc	開始処理
//*/
//void CPlayerHoldState::start(void)
//{
//	//現在のアニメーションをリセット
//	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->reset();
//}
//
///**
//* @desc	更新処理
//*/
//void CPlayerHoldState::update(void)
//{
//	//優先順で処理していく
//
//	//手を繋ぐアニメーションが終わったら
//	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_playerAndGirlState + this->m_pOwner->m_playerDirectionState]->isEnd())
//	{
//		//左向き待機状態へ移行
//		this->m_pOwner->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS;
//
//		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_playerAndGirlState]->setStartState((int)CPlayerCharacter::STATE::IDLE);
//	}
//}
//
///**
//* @desc	状態が変わるときの処理
//*/
//void CPlayerHoldState::onChangeEvent(void)
//{
//	this->m_pOwner->m_underAttack = false;
//
//	this->m_isNext = false;
//}
//EOF