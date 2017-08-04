#pragma once
#include"cocos2d.h"
#include"Constants.h"

//=======================================================
// 前方宣言
//=======================================================
class CCharacter;
class CFactory;

//=======================================================
// アクションクラス
//=======================================================
class CAction
{
public:
	//デストラクタ
	virtual ~CAction()
	{

	}
	//アクションを開始する際に呼び出す
	virtual void start() = 0;
	//アクションの更新処理
	virtual void update(CCharacter* pChara) = 0;
	//アクションを終了する際に呼び出す
	virtual void stop() = 0;

	/**
	* @desc アクションの再起動
	* @param 再起動するキャラクター
	* @tips 標準敵なアクションの再起動
	* ここではキャラクターは使用しない
	*/
	virtual void restart(CCharacter* pChara)
	{
		//アクションの停止
		this->stop();

		//アクションの開始
		this->start();
	}

};

//=======================================================
//　直線移動アクション
//=======================================================
class CActionMoveStraight : public CAction
{
private:
	//アクション中かどうかのフラグ true...アクション中
	bool m_inAction = false;

public:

	/**
	* @desc コンストラクタ
	*/
	CActionMoveStraight();



	/**
	* @desc アクション開始
	*/
	void start(void)override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop(void)override;
};

//=======================================================
//　弾発射アクション
//=======================================================
//class CActionShotBullet : public CAction
//{
//private:
//	//アクション中かどうかのフラグ true...アクション中
//	bool m_inAction = false;
//
//	//弾発射インターバル
//	int m_interval = 0;
//
//	//弾発射カウンター
//	int m_counter = 0;
//
//	//弾タイプ
//	int m_type;
//
//public:
//
//	/**
//	* @desc コンストラクタ
//	* @param 弾タイプ
//	* @param 弾発射間隔
//	*/
//	CActionShotBullet(int type, int interval);
//
//	/**
//	* @desc アクション開始
//	*/
//	void start(void)override;
//
//	/**
//	* @desc 更新処理
//	* @param アクションを行う対象のキャラクター
//	*/
//	void update(CCharacter* pChara)override;
//
//	/**
//	* @desc アクション終了
//	*/
//	void stop(void)override;
//};


//=======================================================
// ジャンプ
// ジャンプに関する処理を行い内部処理として移動データに対して変更を加える
//	tips:
//  cocos2dxのActionクラスにもジャンプは存在するが
//  Actionクラスに依存しているので重力や摩擦やマップチップなどの影響を考えると初めのうちは分離して考えた方が理解しやすい
//=======================================================
class CActionJump : public CAction
{
public:
	//ジャンプ加速補正値
	float m_floatCorrectionValue = 0.0f;


protected:
	//ジャンプ加速度
	float m_accele = 0.0f;

	
	//ジャンプブースト
	int m_boost = 0;
	//現在のジャンプブースト
	int m_currentBoost = 0;
	//ジャンプ中かどうかのフラグ true...ジャンプ中
	bool m_isJumping = false;

	//ジャンプ開始フラグ
	bool m_isJumpStart = false;
public:
	//コンストラクタ
	CActionJump(float accele,int boost):
		m_accele(accele),m_boost(boost)
	{

		this->start();
	}

	/**
	* @desc ジャンプ処理
	* @param 加速度
	* @param ジャンプブースト
	* @tips　ジャンプボタンが押された際に値の設定と共に呼び出す
	*/
	void start()override
	{
		//ジャンプ開始
		this->m_isJumpStart = true;
	}

	/**
	* @desc 更新処理(ジャンプ移動計算)
	* @param ジャンプする対象のキャラクター
	* @tips	 上キーが押されたらこの関数を呼び出す
	*/
	void update(CCharacter* pChara);

	/**
	* @desc ジャンプ終了
	* @tips 着地した際にこの関数を呼び出す
	*/
	void stop()override
	{
		//ジャンプ中フラグを下ろす
		this->m_isJumping = false;
	}

	/**
	* @desc アクションの再起動
	* @param 再起動するキャラクター
	* @tips 標準敵なアクションの再起動
	* ここではキャラクターは使用しない
	*/
	virtual void restart(CCharacter* pChara)override;
	
};

//=======================================================
//　敵死亡アクション
//=======================================================
class CActionEnemyDead : public CAction
{
protected:
	//横移動速度
	float m_velX = 0.0f;

	//はねる速度
	float m_leapVelY = 0.0f;

	//アクション中かどうかのフラグtrue...アクション中
	bool m_inAction = false;

	//アクション開始フラグtrue...アクション開始
	bool m_isStart = false;

public:
	/**
	* @desc コンストラクタ
	* @param 横移動速度
	* @param はねる速度
	*/
	CActionEnemyDead(float velX, float leapVelY);

	/**
	* @desc アクション開始
	*/
	void start()override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop()override;
};


//=======================================================
//　重力演算を加えて敵死亡アクションを行う
//=======================================================
class CActionEnemyDeadAndAddGravity : public CAction
{
protected:
	//横移動速度
	float m_velX = 0.0f;

	//はねる速度
	float m_leapVelY = 0.0f;

	//アクション中かどうかのフラグtrue...アクション中
	bool m_inAction = false;

	//アクション開始フラグtrue...アクション開始
	bool m_isStart = false;

public:
	/**
	* @desc コンストラクタ
	* @param 横移動速度
	* @param はねる速度
	*/
	CActionEnemyDeadAndAddGravity(float velX, float leapVelY);

	/**
	* @desc アクション開始
	*/
	void start()override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop()override;
};


//=======================================================
//　敵死亡アクション後に死亡位置から敵を出撃させる
//=======================================================
class CActionEnemyDeadAndCreateEnemy : public CAction
{
protected:
	//{ ENEMY_TYPE }出撃させる敵のタイプ
	int m_type;

	//アクション中かどうかのフラグtrue...アクション中
	bool m_inAction = false;

	//アクション開始フラグtrue...アクション開始
	bool m_isStart = false;

public:
	/**
	* @desc コンストラクタ
	* @param 出撃させる敵のタイプ
	*/
	CActionEnemyDeadAndCreateEnemy( int type );

	/**
	* @desc アクション開始
	*/
	void start()override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop()override;
};

//=======================================================
//　上下移動アクション
//=======================================================
class CActionUpAndDownMove : public CAction
{
private:
	//アクション中かどうかのフラグ true...アクション中
	bool m_inAction = false;

	//基準位置
	cocos2d::Point m_basePos;

	//半径
	float m_radius = 0.0f;

	//速度
	float m_vel = 0.0f;

	//カウンター
	float m_counter = 0.0f;

public:
	/**
	* @desc コンストラクタ
	* @param 基準位置
	* @param 半径
	* @param 速度
	*/
	CActionUpAndDownMove(cocos2d::Point basePos, float radius,float vel);

	/**
	* @desc アクション開始
	*/
	void start(void)override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop(void)override;
};



//=======================================================
//　定期的に敵を出撃させる
//=======================================================
class CActionIntervalCreateEnemy : public CAction
{
protected:
	//{ ENEMY_TYPE }出撃させる敵のタイプ
	int m_type;

	//アクション中かどうかのフラグtrue...アクション中
	bool m_inAction = false;

	//アクション開始フラグtrue...アクション開始
	bool m_isStart = false;

	//出撃間隔
	int m_interval = 0;

	//出撃カウンター
	int m_counter = 0;

	//出撃させる修正位置
	cocos2d::Point m_launchFixPos = cocos2d::Point(0.0f, 0.0f);


public:
	/**
	* @desc コンストラクタ
	* @param 出撃させるキャラクターの生成工場
	* @param 出撃間隔
	* @param 出撃させる位置
	*/
	CActionIntervalCreateEnemy(int type,int interval,cocos2d::Point launchPos = cocos2d::Point(0.0f,0.0f));

	/**
	* @desc アクション開始
	*/
	void start()override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop()override;
};
