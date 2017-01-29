#include "ActionController.h"
#include "Model\Character\Character.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"
#include "Model\Character\Factory\EnemyFactory.h"
#include"Model\Character\BulletCharacter.h"



//=======================================================
//　直線移動アクション
//=======================================================
/**
* @desc コンストラクタ
*/
CActionMoveStraight::CActionMoveStraight()
{
	//生成と同時に開始
	this->start();
}

/**
* @desc アクション開始
*/
void CActionMoveStraight::start(void)
{
	//アクション開始
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionMoveStraight::update(CCharacter* pChara)
{
	if (this->m_inAction!=false)
	{
		pChara->m_pMove->m_vel.x = pChara->m_pMove->m_speed * pChara->m_shotLaunchVector.x;
		pChara->m_pMove->m_vel.y = pChara->m_pMove->m_speed * pChara->m_shotLaunchVector.y;
	}
	this->stop();
}

/**
* @desc アクション終了
*/
void CActionMoveStraight::stop(void)
{


	//アクション終了
	this->m_inAction = false;
}



//=======================================================
//　弾発射１アクション
//=======================================================
/**
* @desc コンストラクタ
* @param 弾タイプ
* @param 弾発射間隔
*/
CActionShotBullet::CActionShotBullet(int type, int interval)
{
	//弾タイプ
	this->m_type = type;
	//弾発射間隔
	this->m_interval = interval;
}

/**
* @desc アクション開始
*/
void CActionShotBullet::start(void)
{
	//アクション開始
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionShotBullet::update(CCharacter* pChara)
{

	

	if (this->m_inAction != false)
	{
		if(this->m_counter > 0 )
		{
			this->m_counter--;

			if (this->m_counter <= 0)
			{
				this->stop();
			}
		}
		else
		{
			//敵出撃データ（出撃の情報）の生成
			CBulletLaunchData* pLaunchData = new CBulletLaunchData((BULLET_TYPE)this->m_type, pChara->m_pMove->m_pos, pChara->m_shotLaunchVector);

			//出撃トリガーを生成し、敵出撃データを設定
			CBulletLaunchTrigger* pTrigger = new CBulletLaunchTrigger(pLaunchData);

			//出撃トリガーを出撃スケジュールとして追加する
			CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

			//カウンターをリセット
			this->m_counter = this->m_interval;
		}
	}
}

/**
* @desc アクション終了
*/
void CActionShotBullet::stop(void)
{
	//アクション終了
	this->m_inAction = false;
}


//=======================================================
//　ジャンプ移動アクション
//=======================================================
/**
* @desc 更新処理（ジャンプ移動計算）
* @param ジャンプする対象のキャラクター
* @tips 上キーが押されたらこの関数を呼び出す
*/
void CActionJump::update(CCharacter* pChara)
{
	if (this->m_isJumping == true)
	{
		//ジャンプ中

		
		
		//ジャンプブーストを減らしていく
		this->m_currentBoost--;

		//ジャンプブーストが０より小さい場合
		if ((this->m_isJumpStart == false) || (this->m_currentBoost < 0))
		{
			//加速度を０にする
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
	else if (this->m_isJumpStart == true)
	{
		//ジャンプ開始

		//ｙ軸の加速度に値を設定
		pChara->m_pMove->m_accele.y = this->m_floatCorrectionValue + this->m_accele;


		this->m_floatCorrectionValue = 0.0f;

		//何フレーム、加速度を適用させるかを設定
		this->m_currentBoost = this->m_boost;
		//ジャンプフラグをtrueにする
		this->m_isJumping = true;
	}

	

	//ジャンプ開始フラグを下げる
	this->m_isJumpStart = false;
}

/**
* @desc アクションの再起動
* @param 再起動するキャラクター
* @tips 標準敵なアクションの再起動
* ここではキャラクターは使用しない
*/
void CActionJump::restart(CCharacter* pChara)
{
	//Y成分の速度と加速度のリセット
	pChara->m_pMove->m_vel.y = 0.0f;
	pChara->m_pMove->m_accele.y = 0.0f;

	//アクションの停止
	this->stop();

	//アクションの開始
	this->start();
}


//=======================================================
//　敵死亡アクション
//=======================================================
/**
* @desc コンストラクタ
* @param 横移動速度
* @param はねる速度
*/
CActionEnemyDead::CActionEnemyDead(float velX, float leapVelY) :m_velX(velX), m_leapVelY(leapVelY)
{
	//コンストラクタの部分でアクションの開始を行う
	//this->start();
}

/**
* @desc アクション開始
*/
void CActionEnemyDead::start()
{
	//アクション開始
	this->m_isStart = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionEnemyDead::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//アクション中

		//画面の外に出たら
		if (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_top < WINDOW_BOTTOM)
		{
			//アクションを停止
			this->stop();

			//有効フラグを下げる
			pChara->m_activeFlag = false;
		}
	}
	else if (this->m_isStart == true)
	{
		//アクション開始

		//アクション中のフラグを立てる
		this->m_inAction = true;

		//はねる速度と横移動速度を設定する
		pChara->m_pMove->m_vel.set(this->m_velX,this->m_leapVelY);

		//アクション開始フラグは下げる
		this->m_isStart = false;
	}
}

/**
* @desc アクション終了
*/
void CActionEnemyDead::stop()
{
	//アクション中フラグを下ろす
	this->m_inAction = false;
}



//=======================================================
//　敵死亡アクション
//=======================================================
/**
* @desc コンストラクタ
* @param 横移動速度
* @param はねる速度
*/
CActionEnemyDeadAndAddGravity::CActionEnemyDeadAndAddGravity(float velX, float leapVelY) :m_velX(velX), m_leapVelY(leapVelY)
{
	//コンストラクタの部分でアクションの開始を行う
	//this->start();
}

/**
* @desc アクション開始
*/
void CActionEnemyDeadAndAddGravity::start()
{
	//アクション開始
	this->m_isStart = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionEnemyDeadAndAddGravity::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//アクション中

		//画面の外に出たら
		if (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_top < WINDOW_BOTTOM)
		{
			//アクションを停止
			this->stop();

			//有効フラグを下げる
			pChara->m_activeFlag = false;
		}
	}
	else if (this->m_isStart == true)
	{
		//アクション開始


		//アクション中のフラグを立てる
		this->m_inAction = true;

		//はねる速度と横移動速度を設定する
		pChara->m_pMove->m_vel.set(this->m_velX, this->m_leapVelY);

		//アクション開始フラグは下げる
		this->m_isStart = false;
	}
}

/**
* @desc アクション終了
*/
void CActionEnemyDeadAndAddGravity::stop()
{
	//アクション中フラグを下ろす
	this->m_inAction = false;
}



/**
* @desc コンストラクタ
* @param 出撃させる敵のタイプ
*/
CActionEnemyDeadAndCreateEnemy::CActionEnemyDeadAndCreateEnemy(int type)
	:m_type(type)
{

}

/**
* @desc アクション開始
*/
void CActionEnemyDeadAndCreateEnemy::start()
{
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionEnemyDeadAndCreateEnemy::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//有効フラグを下ろす
		pChara->m_activeFlag = false;

		//表示にする
		pChara->setVisible(false);

		//==================================
		// ここでは出撃の情報を出撃トリガーとして
		// 出撃スケジューラーに取り付けるだけ
		//==================================
		//敵出撃データ（出撃の情報）の生成
		CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
			(ENEMY_TYPE)this->m_type,
			pChara->m_pMove->m_pos
		);

		//出撃トリガーを生成し、敵出撃データを設定
		CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

		//出撃トリガーを出撃スケジュールとして追加する
		CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

		
		//アクション中フラグを下ろす
		this->m_inAction = false;
	}
}

/**
* @desc アクション終了
*/
void CActionEnemyDeadAndCreateEnemy::stop()
{
	this->m_inAction = false;
}

//=======================================================
//　上下移動アクション
//=======================================================
/**
* @desc コンストラクタ
* @param 基準位置
* @param 半径
* @param 速度
*/
CActionUpAndDownMove::CActionUpAndDownMove(cocos2d::Point basePos, float radius, float vel)
	:m_basePos(basePos),m_radius(radius),m_vel(vel)
{
	this->start();
}

/**
* @desc アクション開始
*/
void CActionUpAndDownMove::start(void)
{
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionUpAndDownMove::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//X位置は基準点のまま
		pChara->m_pMove->m_pos.x = this->m_basePos.x;
		//Y位置はsinカーブ運動
		pChara->m_pMove->m_pos.y = sinf(this->m_counter)*this->m_radius + this->m_basePos.y;

		//カウンターを速度分更新
		this->m_counter += this->m_vel;
	}
}

/**
* @desc アクション終了
*/
void CActionUpAndDownMove::stop(void)
{
	this->m_inAction = false;
}


//=======================================================
//　定期的に敵を出撃させる
//=======================================================


/**
* @desc コンストラクタ
* @param 出撃させる敵のタイプ
* @param 出撃間隔
* @param 出撃させる修正位置
*/
CActionIntervalCreateEnemy::CActionIntervalCreateEnemy(int type,int interval, cocos2d::Point launchPos)
	:m_type(type),m_interval(interval),m_launchFixPos(launchPos)
{
	this->start();
}

/**
* @desc アクション開始
*/
void CActionIntervalCreateEnemy::start()
{
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionIntervalCreateEnemy::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//カウンターを更新
		this->m_counter++;
		if (this->m_counter >= this->m_interval)
		{

			//==================================
			// ここでは出撃の情報を出撃トリガーとして
			// 出撃スケジューラーに取り付けるだけ
			//==================================
			//敵出撃データ（出撃の情報）の生成
			CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
				(ENEMY_TYPE)this->m_type,
				pChara->m_pMove->m_pos + this->m_launchFixPos
			);

			//出撃トリガーを生成し、敵出撃データを設定
			CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

			//出撃トリガーを出撃スケジュールとして追加する
			CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

			this->m_counter = 0;
		}
	}
}

/**
* @desc アクション終了
*/
void CActionIntervalCreateEnemy::stop()
{
	this->m_inAction = false;
}



