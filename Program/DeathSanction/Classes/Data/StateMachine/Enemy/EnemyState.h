#pragma once
//==========================================
//
// File: EnemyState.h
//
// エネミー状態遷移 ヘッダーファイル
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../StateMachine.h"

//==========================================
//
// Class: CEnemyState
//
// エネミー 状態 基底クラス
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================
template <class T>
class CEnemyState : public CStateBase
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CEnemyState(T* const pOwner):m_pOwner(pOwner)
	{

	}
	
	/**
	* @desc	デストラクタ
	*/
	virtual ~CEnemyState(void)
	{

	}

	/**
	*	@desc	待機状態へ移行
	*/
	void toIdle(void)
	{
		//エネミーの状態
		this->m_pOwner->m_state = (int)T::STATE::IDLE;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//待機動作を終了
		this->m_isNext = true;
	}


	/**
	*	@desc	移動状態へ移行
	*/
	void toMove(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::MOVE;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//待機動作を終了
		this->m_isNext = true;
	}

	/**
	*	@desc	ラインアップ状態へ移行
	*/
	void toLineUp(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::LINE_UP;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//待機動作を終了
		this->m_isNext = true;
	}

	/**
	*	@desc	ラインダウン状態へ移行
	*/
	void toLineDown(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::LINE_DOWN;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//待機動作を終了
		this->m_isNext = true;
	}

	///**
	// * @desc	攻撃状態へ移行
	// */
	void toAttack(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::ATTACK;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//待機動作を終了
		this->m_isNext = true;
	}


	/**
	* @desc	開始処理
	*/
	virtual void enter(void)
	{

	}

	/**
	* @desc 更新処理
	*/
	virtual void execute(float deltaTime)
	{

	}

	/**
	* @desc 状態が変わるときの処理
	*/
	virtual void exit(void)
	{

	}

protected:
	//参照するエネミーキャラクター
	T* m_pOwner = NULL;
};
//EOF