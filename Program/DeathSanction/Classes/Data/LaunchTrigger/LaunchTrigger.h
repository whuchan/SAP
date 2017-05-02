#pragma once

#include<stdio.h>
#include<memory>
#include"cocos2d.h"
#include"Constants.h"
#include"Data/LaunchData/LaunchData.h"

//=============================================
// 前方宣言
//=============================================
class CCharacter;

//=============================================
//
// 出撃トリガー
//
//=============================================
class CLaunchTrigger
{
public:
	//有効フラグ false...出撃スケジュールから取り外す
	bool m_activeFlag = false;

	//コンストラクタ
	CLaunchTrigger()
	{
		this->m_activeFlag = true;
	}

	//デストラクタ
	virtual ~CLaunchTrigger()
	{
	
	}

	/**
	* @desc 発射し終わったかどうか
	* @return true...発射した false...発射していない
	* @tips	発射し終わったかどうかは派生クラスによって
	*		フラグが変化する場合が存在する
	*/
	virtual bool isLaunched(void)
	{
		return this->m_activeFlag;
	}

	/**
	* @desc 設定されているトリガーがイベントを行えるかどうか
	* @param true...イベントの実行が可能
	* @tips イベントの実行可能条件は派生クラスによって変化する
	*/
	virtual bool isTrigger() = 0;

	/**
	* @desc トリガーイベントの実行
	*		ここでのイベントはキャラクターの生成
	*/
	virtual CCharacter* action() = 0;
};

//=============================================
//
// 敵出撃トリガー
//　敵出撃データをトリガーとして敵出撃というイベントを実行させる
//
//=============================================
class CEnemyLaunchTrigger :public CLaunchTrigger
{
private:
	//出撃データ
	CEnemyLaunchData* m_pLaunchData = NULL;

public:
	/**
	* @desc コンストラクタ
	* @param 敵出撃データ
	* @tips 敵出撃データをトリガーとして設定する
	*/
	CEnemyLaunchTrigger(CEnemyLaunchData* pLaunchData)
		: m_pLaunchData(pLaunchData)
	{

	}

	//デストラクタ
	~CEnemyLaunchTrigger();


	/**
	* @desc 設定されているトリガーがイベントを行えるかどうか
	* @param true...イベントの実行が可能
	* @tips イベントの実行可能条件は派生クラスによって変化する
	*/
	bool isTrigger()override;

	/**
	* @desc トリガーイベントの実行
	*		ここでのイベントはキャラクターの生成
	*/
	virtual CCharacter* action()override;

};

////=============================================
////
//// ギミック出撃トリガー
////　ギミック出撃データをトリガーとしてギミック出撃というイベントを実行させる
////
////=============================================
//class CGimmickLaunchTrigger :public CLaunchTrigger
//{
//private:
//	//出撃データ
//	CGimmickLaunchData* m_pLaunchData = NULL;
//
//public:
//	/**
//	* @desc コンストラクタ
//	* @param 敵出撃データ
//	* @tips 敵出撃データをトリガーとして設定する
//	*/
//	CGimmickLaunchTrigger(CGimmickLaunchData* pLaunchData)
//		: m_pLaunchData(pLaunchData)
//	{
//
//	}
//
//	//デストラクタ
//	~CGimmickLaunchTrigger();
//
//
//	/**
//	* @desc 設定されているトリガーがイベントを行えるかどうか
//	* @param true...イベントの実行が可能
//	* @tips イベントの実行可能条件は派生クラスによって変化する
//	*/
//	bool isTrigger()override;
//
//	/**
//	* @desc トリガーイベントの実行
//	*		ここでのイベントはキャラクターの生成
//	*/
//	virtual CCharacter* action()override;
//
//};



////=============================================
////
//// 弾出撃トリガー
////　弾出撃データをトリガーとして弾出撃というイベントを実行させる
////
////=============================================
//
//class CBulletLaunchTrigger :public CLaunchTrigger
//{
//private:
//	//出撃データ
//	CBulletLaunchData* m_pLaunchData = NULL;
//
//public:
//	/**
//	* @desc コンストラクタ
//	* @param 敵出撃データ
//	* @tips 敵出撃データをトリガーとして設定する
//	*/
//
//	CBulletLaunchTrigger(CBulletLaunchData* pLaunchData);
//
//	//デストラクタ
//	~CBulletLaunchTrigger();
//
//
//	/**
//	* @desc 設定されているトリガーがイベントを行えるかどうか
//	* @param true...イベントの実行が可能
//	* @tips イベントの実行可能条件は派生クラスによって変化する
//	*/
//	bool isTrigger()override;
//
//	/**
//	* @desc トリガーイベントの実行
//	*		ここでのイベントはキャラクターの生成
//	*/
//	virtual CCharacter* action()override;
//
//};


//=============================================
//
// 発射台
//　出撃スケジュールの参照を設定して
//　出撃スケジュールに取り付けらている出撃トリガーの順番通りに
//	イベントを実行していく
//　つまり取り付けられた順番通りに出撃を行っていく
//
//=============================================
class CLauncher
{
public:
	//出撃スケジュールの参照(つまりこのクラスで生成や破棄を行わない)
	//１フレームに出撃させるトリガーイベントの集まり
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;

	/**
	* @desc コンストラクタ
	* @param 出撃スケジュールのアドレス
	*/
	CLauncher(std::vector<CLaunchTrigger*>*pLaunchSchedule)
		:m_pLaunchSchedule(pLaunchSchedule)
	{

	}

	//デストラクタ
	virtual ~CLauncher()
	{

	}

	/**
	* @desc 出撃トリガーを出撃スケジュールに追加する
	*/
	void add(CLaunchTrigger* pTrigger)
	{
		this->m_pLaunchSchedule->push_back(pTrigger);
	}

	/**
	* @desc 出撃スケジュールのサイズの取得
	*/
	int getSize(void)
	{
		return (int)this->m_pLaunchSchedule->size();
	}

	/**
	* @desc 出撃トリガーの取得
	* @param　添字番号
	*/
	CLaunchTrigger* getAt(int index)
	{
		//最大要素数以上の際はNULLを返す
		if (this->getSize() <= index)
		{
			return NULL;
		}

		return (*this->m_pLaunchSchedule)[index];
	}

	//=============================================
	//
	// 出撃トリガーイテレーター
	//	発射台に取り付けられているトリガーを発射可能か調べて
	//　発射可能なら１づつ出撃させる為の操作を行うクラス
	// Aggregateの中に実装
	// Iterator
	//
	//=============================================
	class CLaunchTriggerItarator
	{
	public:
		//発射台
		CLauncher* m_pLauncher = NULL;

		//現在参照中の番号
		int m_triggerCount = 0;

		//コンストラクタ
		CLaunchTriggerItarator(CLauncher* pLauncher)
			: m_pLauncher(pLauncher)
		{

		}

		/**
		* @desc 出撃トリガーの次があるかどうかを調べる
		*		もしくは出撃トリガーが起動可能かどうかを調べる
		*/
		bool hasNext()
		{
			//トリガーイベントの集まりのサイズを調べる
			if (this->m_pLauncher->getSize() <= this->m_triggerCount)
			{
				return false;
			}

			//出撃トリガーが起動可能かどうかを調べる
			if (this->m_pLauncher->getAt(this->m_triggerCount)->isTrigger() == false)
			{
				//起動可能で無い場合は添字番号を次に進めて
				this->m_triggerCount++;
				//次をチェック
				return this->hasNext();
			}
			return true;
		}
	

		/**
		* @desc 現在の出撃トリガーを取得し添字番号を次にすすめる
		*/
		CLaunchTrigger* next()
		{
			CLaunchTrigger* pTrrigger = this->m_pLauncher->getAt(this->m_triggerCount);
			this->m_triggerCount++;
			return pTrrigger;
		}

	};
		
	
	/**
	* @desc　出撃トリガーイテレーターの生成
	* @param 出撃トリガーイテレーター
	*/
	std::shared_ptr<CLaunchTriggerItarator>iterator()
	{
			return std::shared_ptr<CLaunchTriggerItarator>(new CLaunchTriggerItarator(this));
	}
};

//=============================================
//
// 出撃スケジューラー
// Singleton
//
//=============================================
class CLaunchScheduler
{
	//=========================================
	// ここからSingleton設定
	//=========================================

private:
	//共有インスタンス
	static CLaunchScheduler* m_pSharedSchedular;

	//コンストラクタ
	CLaunchScheduler();

public:
	//共有インスタンスの取得
	static CLaunchScheduler* getInstance();

	//共有インスタンスの破棄
	static void removeInstance();

	//デストラクタ
	~CLaunchScheduler();

	//=========================================
	// ここまでがSingleton設定
	//=========================================

public:
	//発射台
	CLauncher* m_pLauncher = NULL;

	/**
	* @desc 発射台の生成
	* @param 発射台に設定する出撃スケジュールのアドレス
	*/
	void createLaunch(std::vector<CLaunchTrigger*>* pLaunchSchedule);

	/**
	* @desc キャラクターの出撃
	* @param 取り付けるレイヤー
	*/
	void launchCharacters(cocos2d::Layer* pLayer);
};

