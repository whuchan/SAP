#pragma once

#include "EnemyState.h"
#include "cocos2d.h"

//==========================================
//
// Class: CEnemyStateLineUp
//
// プレイヤー ラインアップ 状態クラス
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
template <class T >
class CEnemyStateLineUp :public CEnemyState<T>
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CEnemyStateLineUp(T* const pOwner) :CEnemyState(pOwner)
	{

	}

	/**
	* @desc	デストラクタ
	*/
	virtual~CEnemyStateLineUp(void)
	{

	}

	/**
	* @desc	開始処理
	*/
	void enter(void)override
	{
		this->m_pOwner->m_intCurrentLine++;

		// 1秒かけて、スケールを縮小する
		ScaleTo* pOrder = ScaleTo::create(0.5, 1.0f - this->m_pOwner->m_intCurrentLine * 0.2f);
		this->m_pAction = this->m_pOwner->runAction(pOrder);
		CC_SAFE_RETAIN(this->m_pAction); // 勝手に開放されないように参照カウンタを増やす

										 //ジャンプアクションのスタート関数を開始
										 //(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::ACTION::JUMP])[0]->start();

		this->m_pOwner->m_pMove->m_vel.y = sqrtf(((CPhysicalGravity::GRAVITY * 0.6f) * (CPhysicalGravity::GRAVITY * 0.6f)) / 2.0f);

	}
	/**
	* @desc	更新処理
	*/
	void execute(float deltaTime)override
	{
#ifdef _DEBUG_ENEMY_STATE
		log("Enemy: LineUp");
#endif //_DEBUG_ENEMY_STATE

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
	void exit(void)override
	{
		this->m_isNext = false;

		//使わなくなったら解放する
		CC_SAFE_RELEASE(this->m_pAction);
	}

private:
	cocos2d::Action* m_pAction = NULL;
};
//EOF