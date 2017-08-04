#pragma once
#include "EnemyCharacter.h"

//======================================================
//
// 敵キャラクターの基底クラスとなるクラス
//
//======================================================

class CHenchmanTypeAEnemy : public CEnemyCharacter<CHenchmanTypeAEnemy>
{
public:
	//=========================================================
	// 定数
	//=========================================================
	//プレイヤーの状態
	enum class STATE :int
	{
		IDLE			= 0,
		MOVE			= 1,
		ATTACK			= 2,
		LINE_UP			= 3,
		LINE_DOWN		= 4,
		JUMP			= 5,
		FALLING			= 6,		//降下
		APPLY_DAMAGE	= 7,
		DEAD			= 8,
	};

public:
	//コンストラクタ
	CHenchmanTypeAEnemy();

	//デストラクタ
	virtual ~CHenchmanTypeAEnemy();

	////初期化処理
	//bool init()override;

	///**
	//* @desc CREATE_FUNCマクロをオーバーライド
	//* @param 初期位置X
	//* @param 初期位置Y
	//* @tips 初期位置を必要とするのは生成の段階ではなく
	//*       initの段階である
	//*/
	//static CEnemyCharacter* create(float posX, float posY)
	//{
	//	CEnemyCharacter* pRet = new(std::nothrow)CEnemyCharacter();
	//	if (pRet&&pRet->init(posX, posY))
	//	{
	//		pRet->autorelease();
	//		return pRet;
	//	}
	//	else
	//	{
	//		delete pRet;
	//		pRet = NULL;
	//		return NULL;
	//	}
	//}

	////移動処理
	//void moveFunction(float deltaTime)override;

	////アニメーション処理
	//void animationFunction(float deltaTime)override;

	////空間との衝突判定処理
	//virtual void collision()override;

	////状態チェック
	//void checkState(float deltaTime)override;

	////反映処理
	//void applayFunction()override;



	///**
	//* @desc キャラクター１体との衝突判定処理
	//* @param キャラクターのアドレス
	//* @return true...衝突した
	//*/
	//bool collision(CCharacter* pChara)override;

	///**
	//* @desc 衝突判定後の処理
	//* @param 衝突してきたキャラクタ-
	//*/
	//void hits(CCharacter* pChara)override;

protected:

	///**
	//* @desc プレイヤーとの衝突判定後の処理
	//* @param 衝突してきたキャラクタ-
	//*/
	//virtual void hitsPlayerCharacter(CCharacter* pChara);

	///**
	//* @desc 弾との衝突判定後の処理
	//* @param 衝突してきたキャラクタ-
	//*/
	//virtual void hitsBulletCharacter(CCharacter* pChara);

};