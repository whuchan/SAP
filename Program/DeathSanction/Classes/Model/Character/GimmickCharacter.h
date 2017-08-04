#pragma once
#include "Character.h"


//================================================================
// 方向タイプ
//================================================================
enum DIRECTION_TYPE : int
{
	LEFT	= 0,	//左
	UP		= 1,	//上
	RIGHT	= 2,	//右
	DOWN	= 3,	//下
};


//======================================================
//
// ギミックキャラクターの基底クラスとなるクラス
//
//======================================================
class CGimmickCharacter : public CCharacter
{
public:
	//コンストラクタ
	CGimmickCharacter();

	//デストラクタ
	virtual ~CGimmickCharacter();

	//初期化処理
	virtual bool init()override;

	/**
	* @desc　初期化処理
	* @param 初期位置X
	* @param 初期位置Y
	* @tips create()メンバ関数の中でinit()メンバ関数を呼び出しているが
	* 今回、そのcreate()メンバ関数をオーバーロードして
	* 引数を受け取っているのでinit()メンバ関数も
	* オーバーロードする必要がある
	*/
	virtual bool init(float posX, float posY);

	
	//移動処理
	void moveFunction(float deltaTime)override;

	//アニメーション処理
	void animationFunction(float deltaTime)override;

	//空間との衝突判定処理
	virtual void collision()override;

	//状態チェック
	virtual void checkState(float deltaTime)override;

	//反映処理
	void applayFunction()override;



	/**
	* @desc キャラクター１体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	bool collision(CCharacter* pChara)override;

	/**
	* @desc 衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	void hits(CCharacter* pChara)override;


	
protected:

	/**
	* @desc プレイヤーとの衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara);

	/**
	* @desc 敵との衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsEnemyCharacter(CCharacter* pChara) = 0;

};