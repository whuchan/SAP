//==========================================
//
// File: CHenchmanTypeAState.cpp
//
// 子分A状態遷移 ヘッダーファイル
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "HenchmanTypeAState.h"


//==========================================
//
// Class: CHenchmanTypeAState
//
// エネミー 状態 基底クラス
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================

/**
* @desc	コンストラクタ
*/
CHenchmanTypeAState::CHenchmanTypeAState(CHenchmanTypeAEnemy* const pOwner) :CEnemyState(pOwner)
{

}

/**
* @desc	デストラクタ
*/
CHenchmanTypeAState::~CHenchmanTypeAState(void)
{

}
/////**
//// * @desc	ジャンプ状態へ移行
//// */
////void CHenchmanTypeAState::toJump(void)
////{
////	this->m_pOwner->m_state			= (int)CEnemyCharacter::STATE::JUMP;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
//
/////**
//// * @desc	落下状態へ移行
//// */
////void CHenchmanTypeAState::toFall(void)
////{
////	this->m_pOwner->m_state			= (int)CEnemyCharacter::STATE::FALL;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
//
//
/////**
////* @desc	移動状態へ移行
////*/
////void CHenchmanTypeAState::toMove(void) {
////	this->m_pOwner->m_state = (int)CHenchmanTypeAEnemy::STATE::MOVE;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
////
/////**
////* @desc	ラインアップ状態へ移行
////*/
////void CHenchmanTypeAState::toLineUp(void) {
////	this->m_pOwner->m_state = (int)CHenchmanTypeAEnemy::STATE::LINE_UP;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
////
/////**
////* @desc	ラインダウン状態へ移行
////*/
////void CHenchmanTypeAState::toLineDown(void) {
////	this->m_pOwner->m_state = (int)CHenchmanTypeAEnemy::STATE::LINE_DOWN;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
////
////
/////**
//// * @desc	攻撃状態へ移行
//// */
////void CHenchmanTypeAState::toAttack(void) {
////	this->m_pOwner->m_state			= (int)CHenchmanTypeAEnemy::STATE::ATTACK;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
////
//
/////**
//// * @desc	ジャンプ攻撃へ移行
//// */
////void CHenchmanTypeAState::toJumpAttack(void) {
////	this->m_pOwner->m_state = (int)CEnemyCharacter::STATE::JUMP_ATTACK;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
//
//
/////**
//// * @desc	攻撃を受けた状態へ移行
//// */
////void CHenchmanTypeAState::toUnderAttack(void) {
////	this->m_pOwner->m_state = (int)CEnemyCharacter::STATE::UNDER_ATTACK;
////
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////
////	this->m_isNext = true;
////}
////
////
/////*
//// * @desc	手を掴む状態へ移行
//// */
////void CHenchmanTypeAState::toGrasp(void)
////{
////	this->m_pOwner->m_state			= (int)CEnemyCharacter::STATE::GRASP;
////
////	this->m_nextRegisterKey				= this->m_pOwner->m_state;
////	//待機動作を終了
////	this->m_isNext = true;
////}
////
////
/////*
//// *	@desc	お姫様抱っこ状態へ移行
//// */
////void CHenchmanTypeAState::toHold(void)
////{
////	//次の総合的なエネミーの状態
////	this->m_pOwner->m_state = (int)CEnemyCharacter::STATE::HOLD;
////
////	//次の総合的なエネミーの状態を次に行くステートとして指定
////	this->m_nextRegisterKey = this->m_pOwner->m_state;
////
////	//待機動作を終了
////	this->m_isNext = true;
////}
//
//
//
//
//////==========================================
//////
////// Class: CEnemyJumpState
//////
////// エネミー ジャンプ 状態クラス
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
//// * @desc	コンストラクタ
//// */
////CEnemyJumpState::CEnemyJumpState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	デストラクタ
////*/
////CEnemyJumpState::~CEnemyJumpState(void) {}
////
/////**
////* @desc	開始処理
////*/
////void CEnemyJumpState::start(void)
////{
////	//ジャンプアクションのスタート関数を開始
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::JUMP])[0]->start();
////
////	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
////}
////
/////**
////* @desc	更新処理
////*/
////void CEnemyJumpState::update(void)
////{
////	//優先順で処理していく
////	//入力コントローラーの取得
////	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
////
////	//エネミーが攻撃を受けたら
////	if (this->m_pOwner->m_underAttack) {
////		//攻撃を受けた状態へ移行
////		this->toUnderAttack();
////	}
////
////	if (pointerInputController->getAttackFlag()) {
////		//右ジャンプ攻撃状態へ移行する
////		//this->toJumpAttack();
////		return;
////	}
////
////	//エネミーの速度を維持させる
////	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
////
////	//右移動
////	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
////		this->m_pOwner->m_pMove->m_vel.x += 1.0f;
////	}
////	//左移動
////	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
////		this->m_pOwner->m_pMove->m_vel.x += -1.0f;
////	}
////
////	//エネミーが下へ移動していたら
////	if (this->m_pOwner->m_pMove->m_vel.y <= 0.0f) {
////		//落下状態へ移行する
////		this->toFall();
////
////		return;
////	}
////
////	//左向きジャンプ
////	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
////		//開始処理を再起動する
////		this->start();
////		return;
////	}
////}
////
/////**
////* @desc	状態が変わるときの処理
////*/
////void CEnemyJumpState::onChangeEvent(void)
////{
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::JUMP])[0]->restart(this->m_pOwner);
////
////
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyFallState
//////
////// エネミー 落下 状態クラス
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
////* @desc	コンストラクタ
////*/
////CEnemyFallState::CEnemyFallState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	デストラクタ
////*/
////CEnemyFallState::~CEnemyFallState(void) {}
////
/////**
////* @desc	開始処理
////*/
////void CEnemyFallState::start(void)
////{
////	this->m_velX = this->m_pOwner->m_pMove->m_vel.x;
////}
////
/////**
////* @desc	更新処理
////*/
////void CEnemyFallState::update(void)
////{
////	//優先順で処理していく
////
////	//入力コントローラーの取得
////	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
////
////	//エネミーが攻撃を受けたら
////	if (this->m_pOwner->m_underAttack) {
////		//攻撃を受けた状態へ移行
////		this->toUnderAttack();
////	}
////
////	if (pointerInputController->getAttackFlag()) {
////		//右ジャンプ攻撃状態へ移行する
////		//this->toJumpAttack();
////		return;
////	}
////
////	//エネミーの速度を維持させる
////	this->m_pOwner->m_pMove->m_vel.x = this->m_velX;
////
////	//右移動
////	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
////		this->m_pOwner->m_pMove->m_accele.x = 2.0f;
////	}
////	//左移動
////	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
////		this->m_pOwner->m_pMove->m_accele.x = -2.0f;
////	}
////
////	//エネミーが下へ移動していたら
////	if (this->m_pOwner->m_pMove->m_vel.y == 0.0f) {
////		//落下状態へ移行する
////		this->toIdle();
////
////		return;
////	}
////
////}
////
/////**
////* @desc	状態が変わるときの処理
////*/
////void CEnemyFallState::onChangeEvent(void)
////{
////	this->m_pOwner->m_pMove->m_accele.x = 0.0f;
////
////	this->m_pOwner->m_pMove->m_vel.x = 0.0f;
////
////
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyAttackState
//////
////// エネミー 攻撃 状態クラス
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
//// * @desc	コンストラクタ
//// */
////CEnemyAttackState::CEnemyAttackState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl){}
////
/////**
//// * @desc	デストラクタ
//// */
////CEnemyAttackState::~CEnemyAttackState(void){}
////
/////**
//// * @desc	開始処理
//// */
////void CEnemyAttackState::start(void)
////{
////
////	//現在のアニメーションをリセット
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////
////	//攻撃アクションをスタートさせる
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::ATTACK])[0]->start();
////
////	//連撃フラグをfalseで始める
////	this->m_pOwner->m_chainAttackFlag = false;
////}
////
/////**
//// * @desc	更新処理
//// */
////void CEnemyAttackState::update(void)
////{
////	//優先順で処理していく
////	//入力コントローラーの取得
////	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
////
////	//攻撃ボタンが押されたか
////	if (pointerInputController->getAttackFlag())
////	{
////		//攻撃連鎖フラグをtrue にする
////		this->m_pOwner->m_chainAttackFlag = true;
////	}
////
////	//アニメーションが終了したかどうかのフラグ
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//待機状態へ移行
////		this->toIdle();
////	}
////}
////
/////**
//// * @desc	状態が変わるときの処理
//// */
////void CEnemyAttackState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	//次のステートへ移行することが確定しているので元に戻しておく
////	this->m_isNext = false;
////}
////
//////==========================================
//////
////// Class: CEnemyJumpAttackState
//////
////// エネミー ジャンプ攻撃 状態クラス
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
//// * @desc	コンストラクタ
//// */
////CEnemyJumpAttackState::CEnemyJumpAttackState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
//// * @desc	デストラクタ
//// */
////CEnemyJumpAttackState::~CEnemyJumpAttackState(){}
////
/////**
//// * @desc	開始処理
//// */
////void CEnemyJumpAttackState::start(void)
////{
////	//現在のアニメーションをリセット
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////	
////	//エネミーのジャンプアクションを停止させる。
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::JUMP])[0]->stop();
////
////	//エネミーのｙ軸移動速度を０に戻す
////	this->m_pOwner->m_pMove->m_vel.y = 0.0f;
////
////
////	//ダメージキャラクター生成データを作成
////	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
////		cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
////		1);
////	//ダメージキャラクター生成トリガーを作成
////	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);
////
////	//作成したトリガーをスケジューラーに登録
////	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
////
////
////}
////
/////**
//// * @desc	更新処理
//// */
////void CEnemyJumpAttackState::update(void)
////{
////	//アニメーションが終了したかどうかのフラグ
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd() && this->m_pOwner->m_pMove->m_vel.y == 0.0f)
////	{
////		//右向き待機状態へ戻す
////		this->toIdle();
////		return;
////	}
////}
////
/////**
//// * @desc	状態が変わるときの処理
//// */
////void CEnemyJumpAttackState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	//次のステートへ移行することが確定しているので元に戻しておく
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyUnderAttackState
//////
////// エネミー 攻撃を受けた 状態クラス
//////
////// 2016/12/25
//////						Author Harada
//////==========================================
/////**
////* @desc	コンストラクタ
////*/
////CEnemyUnderAttackState::CEnemyUnderAttackState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	デストラクタ
////*/
////CEnemyUnderAttackState::~CEnemyUnderAttackState() {}
////
/////**
////* @desc	開始処理
////*/
////void CEnemyUnderAttackState::start(void)
////{
////	//現在のアニメーションをリセット
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////
////	//現在のアクションをスタートさせる。
////	(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::STATE::UNDER_ATTACK])[0]->start();
////}
////
/////**
////* @desc	更新処理
////*/
////void CEnemyUnderAttackState::update(void)
////{
////	//アニメーションが終了したかどうかのフラグ
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//待機状態へ戻す
////		this->toIdle();
////
////		this->m_pOwner->m_underAttack = false;
////
////		return;
////	}
////}
////
/////**
////* @desc	状態が変わるときの処理
////*/
////void CEnemyUnderAttackState::onChangeEvent(void)
////{
////	//次のステートへ移行することが確定しているので元に戻しておく
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyGraspState
//////
////// エネミー 手を繋ぐ 状態クラス
//////
////// 2016/12/26
//////						Author Harada 
//////==========================================
/////**
//// * @desc	コンストラクタ
//// */
////CEnemyGraspState::CEnemyGraspState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl){}
////
/////**
//// * @desc	デストラクタ
//// */
////CEnemyGraspState::~CEnemyGraspState(void){}
////
/////**
//// * @desc	開始処理
//// */
////void CEnemyGraspState::start(void)
////{
////	//現在のアニメーションをリセット
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////}
////
/////**
//// * @desc	更新処理
//// */
////void CEnemyGraspState::update(void)
////{
////	//優先順で処理していく
////
////	//手を繋ぐアニメーションが終わったら
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//右向き待機状態へ移行
////		this->m_pOwner->m_EnemyAndGirlState = (int)Enemy_AND_GIRL_STATE::GRAPS_HANDS;
////
////		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_EnemyAndGirlState]->setStartState((int)CEnemyCharacter::STATE::IDLE);
////	}
////}
////
/////**
//// * @desc	状態が変わるときの処理
//// */
////void CEnemyGraspState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	this->m_isNext = false;
////}
////
////
//////==========================================
//////
////// Class: CEnemyHoldState
//////
////// エネミー お姫様抱っこ 状態クラス
//////
////// 2017/ 1/ 5
//////						Author Harada
//////==========================================
/////**
////* @desc	コンストラクタ
////*/
////CEnemyHoldState::CEnemyHoldState(CEnemyCharacterBoy* const pEnemy, CGirlCharacter* const pGirl)
////	:CHenchmanTypeAState::CEnemyState(pEnemy, pGirl) {}
////
/////**
////* @desc	デストラクタ
////*/
////CEnemyHoldState::~CEnemyHoldState(void) {}
////
/////**
////* @desc	開始処理
////*/
////void CEnemyHoldState::start(void)
////{
////	//現在のアニメーションをリセット
////	(*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->reset();
////}
////
/////**
////* @desc	更新処理
////*/
////void CEnemyHoldState::update(void)
////{
////	//優先順で処理していく
////
////	//手を繋ぐアニメーションが終わったら
////	if ((*this->m_pOwner->m_pMapAnimations)[this->m_pOwner->m_state + this->m_pOwner->m_EnemyAndGirlState + this->m_pOwner->m_EnemyDirectionState]->isEnd())
////	{
////		//左向き待機状態へ移行
////		this->m_pOwner->m_EnemyAndGirlState = (int)Enemy_AND_GIRL_STATE::HOLD_THE_PRINCESS;
////
////		(*this->m_pOwner->m_pStateMachines)[this->m_pOwner->m_EnemyAndGirlState]->setStartState((int)CEnemyCharacter::STATE::IDLE);
////	}
////}
////
/////**
////* @desc	状態が変わるときの処理
////*/
////void CEnemyHoldState::onChangeEvent(void)
////{
////	this->m_pOwner->m_underAttack = false;
////
////	this->m_isNext = false;
////}
////EOF