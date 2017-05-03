#pragma once
//==========================================
//
// File: PlayerState.h
//
// プレイヤー状態遷移 ヘッダーファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../StateMachine.h"


//#define _DEBUG_PLAYER_STATE

//==========================================
// 前方宣言
//==========================================
class CPlayerCharacter;

//==========================================
//
// Class: CPlayerState
//
// プレイヤー 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerState : public CStateBase
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerState(CPlayerCharacter* const pOwner);

	/**
	 * @desc	デストラクタ
	 */
	virtual ~CPlayerState(void);

	/**
	 *	@desc	待機状態へ移行
	 */
	void toIdle(void);

	/**
	 *	@desc	歩行状態へ移行
	 */
	void toWalk(void);

	/**
	*	@desc	ラインアップ状態へ移行
	*/
	void toLineUp(void);

	/**
	*	@desc	ラインダウン状態へ移行
	*/
	void toLineDown(void);


	///**
	// *	@desc	ジャンプ状態へ移行
	// */
	//void toJump(void);

	///**
	// * @desc	攻撃状態へ移行
	// */
	//void toAttack(void);

	///**
	// * @desc	ジャンプ攻撃へ移行
	// */
	//void toJumpAttack(void);

	///**
	// * @desc	攻撃を受けた状態へ移行
	// */
	//void toUnderAttack(void);

	///*
	// *	@desc	手を掴む状態へ移行
	// */
	//void toGrasp(void);

	///*
	// *	@desc	お姫様抱っこ状態へ移行
	// */
	//void toHold(void);

protected:
	//参照するプレイヤーキャラクター
	CPlayerCharacter* m_pOwner = NULL;
};


////==========================================
////
//// Class: CPlayerJumpState
////
//// プレイヤー ジャンプ 状態クラス
////
//// 2016/12/25
////						Author Shinya Ueba
////==========================================
//class CPlayerJumpState :public CPlayerState
//{
//public:
//	/**
//	* @desc	コンストラクタ
//	*/
//	CPlayerJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);
//
//	/**
//	* @desc	デストラクタ
//	*/
//	~CPlayerJumpState(void);
//
//	/**
//	* @desc	開始処理
//	*/
//	void start(void)override;
//	/**
//	* @desc	更新処理
//	*/
//	void update(void)override;
//
//	/**
//	* @desc	状態が変わるときの処理
//	*/
//	void onChangeEvent(void)override;
//
//	//ジャンプ中のX軸速度
//	float m_velX;
//
//private:
//};
//
////==========================================
////
//// Class: CPlayerFallState
////
//// プレイヤー 落下 状態クラス
////
//// 2016/12/25
////						Author Shinya Ueba
////==========================================
//class CPlayerFallState :public CPlayerState
//{
//public:
//	/**
//	* @desc	コンストラクタ
//	*/
//	CPlayerFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);
//
//	/**
//	* @desc	デストラクタ
//	*/
//	~CPlayerFallState(void);
//
//	/**
//	* @desc	開始処理
//	*/
//	void start(void)override;
//	/**
//	* @desc	更新処理
//	*/
//	void update(void)override;
//
//	/**
//	* @desc	状態が変わるときの処理
//	*/
//	void onChangeEvent(void)override;
//
//	//ジャンプ中のX軸速度
//	float m_velX;
//
//private:
//};
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
//class CPlayerAttackState :public CPlayerState
//{
//public:
//	/**
//	 * @desc	コンストラクタ
//	 */
//	CPlayerAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);
//
//	/**
//	 * @desc	デストラクタ
//	 */
//	~CPlayerAttackState(void);
//
//	/**
//	 * @desc	開始処理
//	 */
//	void start(void)override;
//	
//	/**
//	 * @desc	更新処理
//	 */
//	void update(void)override;
//
//	/**
//	 * @desc	状態が変わるときの処理
//	 */
//	void onChangeEvent(void)override;
//
//private:
//	//連撃フラグ
//	bool m_chainAttackFlag = false;
//
//};
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
//class CPlayerJumpAttackState :public CPlayerState
//{
//public:
//	/**
//	* @desc	コンストラクタ
//	*/
//	CPlayerJumpAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);
//
//	/**
//	* @desc	デストラクタ
//	*/
//	~CPlayerJumpAttackState(void);
//
//	/**
//	* @desc	開始処理
//	*/
//	void start(void)override;
//
//	/**
//	* @desc	更新処理
//	*/
//	void update(void)override;
//
//	/**
//	* @desc	状態が変わるときの処理
//	*/
//	void onChangeEvent(void)override;
//
//};
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
//class CPlayerUnderAttackState :public CPlayerState
//{
//public:
//	/**
//	* @desc	コンストラクタ
//	*/
//	CPlayerUnderAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);
//
//	/**
//	* @desc	デストラクタ
//	*/
//	~CPlayerUnderAttackState(void);
//
//	/**
//	* @desc	開始処理
//	*/
//	void start(void)override;
//
//	/**
//	* @desc	更新処理
//	*/
//	void update(void)override;
//
//	/**
//	* @desc	状態が変わるときの処理
//	*/
//	void onChangeEvent(void)override;
//
//};
//
////==========================================
////
//// Class: CPlayerGraspState
////
//// プレイヤー 手をつなぐ 状態クラス
////
//// 2016/12/27
////						Author Shinya Ueba
////==========================================
//class CPlayerGraspState :public CPlayerState
//{
//public:
//	/**
//	 * @desc	コンストラクタ
//	 */
//	CPlayerGraspState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);
//
//	/**
//	 * @desc	デストラクタ
//	 */
//	~CPlayerGraspState(void);
//
//	/**
//	 * @desc	開始処理
//	 */
//	void start(void)override;
//	
//	/**
//	 * @desc	更新処理
//	 */
//	void update(void)override;
//
//	/**
//	 * @desc	状態が変わるときの処理
//	 */
//	void onChangeEvent(void)override;
//
//private:
//};
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
//class CPlayerHoldState :public CPlayerState
//{
//public:
//	/**
//	 * @desc	コンストラクタ
//	 */
//	CPlayerHoldState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);
//
//	/**
//	 * @desc	デストラクタ
//	 */
//	~CPlayerHoldState(void);
//
//	/**
//	 * @desc	開始処理
//	 */
//	void start(void)override;
//
//	/**
//	 * @desc	更新処理
//	 */
//	void update(void)override;
//
//	/**
//	 * @desc	状態が変わるときの処理
//	 */
//	void onChangeEvent(void)override;
//
//private:
//};
//
//
//EOF