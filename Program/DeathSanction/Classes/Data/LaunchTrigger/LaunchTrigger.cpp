#include"LaunchTrigger.h"
#include"Model\Character\Character.h"
#include "Model\Character\Factory\EnemyFactory.h"
#include "Model\Character\Factory\BulletFactory.h"
#include "Model\Character\Factory\GimmickFactory.h"


//=============================================================
//
// 敵出撃トリガー
// 敵出撃データをトリガーにして敵出撃というイベントを実行させる
//
//=============================================================
//デストラクタ
CEnemyLaunchTrigger::~CEnemyLaunchTrigger()
{
	SAFE_DELETE(this->m_pLaunchData);
}

/**
* @desc イベントを実行できるかどうか
* @return true...実行可能
*/
bool CEnemyLaunchTrigger::isTrigger()
{
	if (this->m_pLaunchData == NULL)
	{
		return false;
	}
	return true;
}

/**
* @desc 設定されている敵出撃データを元に敵を生成する
*/
CCharacter* CEnemyLaunchTrigger::action()
{
	//敵を生成
	CCharacter* pEnemyChara = CEnemyFactoryManager::getInstance()->create(
		this->m_pLaunchData->m_type,
		this->m_pLaunchData->m_pos.x,
		this->m_pLaunchData->m_pos.y);

	//発射し終わったかどうかのフラグを立てる
	this->m_activeFlag = false;

	return pEnemyChara;
}


////=============================================================
////
//// ギミック出撃トリガー
//// ギミック出撃データをトリガーにして敵出撃というイベントを実行させる
////
////=============================================================
////デストラクタ
//CGimmickLaunchTrigger::~CGimmickLaunchTrigger()
//{
//	SAFE_DELETE(this->m_pLaunchData);
//}
//
///**
//* @desc イベントを実行できるかどうか
//* @return true...実行可能
//*/
//bool CGimmickLaunchTrigger::isTrigger()
//{
//	if (this->m_pLaunchData == NULL)
//	{
//		return false;
//	}
//	return true;
//}
//
///**
//* @desc 設定されている敵出撃データを元に敵を生成する
//*/
//CCharacter* CGimmickLaunchTrigger::action()
//{
//	//敵を生成
//	CCharacter* pGimmickChara = CGimmickFactoryManager::getInstance()->create(
//		this->m_pLaunchData->m_type,
//		this->m_pLaunchData->m_pos.x,
//		this->m_pLaunchData->m_pos.y);
//
//	//発射し終わったかどうかのフラグを立てる
//	this->m_activeFlag = false;
//
//	return pGimmickChara;
//}
//
//
//
////=============================================
////
//// 弾出撃トリガー
////　弾出撃データをトリガーとして弾出撃というイベントを実行させる
////
////=============================================
//
///**
//* @desc コンストラクタ
//* @param 敵出撃データ
//* @tips 敵出撃データをトリガーとして設定する
//*/
//CBulletLaunchTrigger::CBulletLaunchTrigger(CBulletLaunchData* pLaunchData)
//	: m_pLaunchData(pLaunchData)
//{
//
//}
//
////デストラクタ
//CBulletLaunchTrigger::~CBulletLaunchTrigger()
//{
//
//	SAFE_DELETE(this->m_pLaunchData);
//}
//
//
///**
//* @desc 設定されているトリガーがイベントを行えるかどうか
//* @param true...イベントの実行が可能
//* @tips イベントの実行可能条件は派生クラスによって変化する
//*/
//
//
//bool CBulletLaunchTrigger::isTrigger()
//{
//	if (this->m_pLaunchData == NULL)
//	{
//		return false;
//	}
//	return true;
//}
//
///**
//* @desc トリガーイベントの実行
//*		ここでのイベントはキャラクターの生成
//*/
//CCharacter* CBulletLaunchTrigger::action()
//{
//	//敵を生成
//	CCharacter* pBulletChara = CBulletFactoryManager::getInstance()->create(
//																			this->m_pLaunchData->m_type,
//																			this->m_pLaunchData->m_pos.x,
//																			this->m_pLaunchData->m_pos.y,
//																			this->m_pLaunchData->m_shotLaunchVector);
//
//	//発射し終わったかどうかのフラグを立てる
//	this->m_activeFlag = false;
//
//	return pBulletChara;
//}



//=============================================
//
// 出撃スケジューラー
// Singleton
//
//=============================================

//共有インスタンス本体
CLaunchScheduler* CLaunchScheduler::m_pSharedSchedular = NULL;


//コンストラクタ
CLaunchScheduler::CLaunchScheduler()
{


}

//共有インスタンスの取得
CLaunchScheduler* CLaunchScheduler::getInstance()
{
	if (CLaunchScheduler::m_pSharedSchedular == NULL)
	{
		CLaunchScheduler::m_pSharedSchedular = new CLaunchScheduler();
	}
	return CLaunchScheduler::m_pSharedSchedular;
}

//共有インスタンスの破棄
void CLaunchScheduler::removeInstance()
{
	SAFE_DELETE(CLaunchScheduler::m_pSharedSchedular);
}

//デストラクタ
CLaunchScheduler::~CLaunchScheduler()
{
	SAFE_DELETE(this->m_pLauncher);
}

/**
* @desc 発射台の生成
* @param 発射台に設定する出撃スケジュールのアドレス
*/
void CLaunchScheduler::createLaunch(std::vector<CLaunchTrigger*>* pLaunchSchedule)
{
	if (this->m_pLauncher == NULL)
	{
		//発射台を生成し出撃スケジュールを発射台に設定
		this->m_pLauncher = new CLauncher(pLaunchSchedule);
	}
}

/**
* @desc キャラクターの出撃
* @param 取り付けるレイヤー
*/
void CLaunchScheduler::launchCharacters(cocos2d::Layer* pLayer)
{
	//スケジューラーに取り付けられている起動できるトリガーを全て起動する
	std::shared_ptr<CLauncher::CLaunchTriggerItarator>itr = this->m_pLauncher->iterator();
	//次の起動可能な出撃トリガーがあるかどうかをチェック
	while (itr->hasNext() == true)
	{
		//起動可能な出撃トリガーを取得して出撃トリガーイテレーターを次へ進める
		CLaunchTrigger* pTrigger = itr->next();

		//出撃トリガーを起動
		CCharacter* pChara = pTrigger->action();

		//NULLチェック
		if (pChara != NULL)
		{
			//キャラクターをキャラクターの集まりに取り付ける
			CCharacterAggregate::getInstance()->add(pChara);

			//キャラクターをメインレイヤーに取り付ける
			pLayer->addChild(pChara);
		}
	}
}


