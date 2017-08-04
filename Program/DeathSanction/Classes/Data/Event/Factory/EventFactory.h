#pragma once
#include "Model\Map\Map.h"
#include "Data\StateMachine\StateMachine.h"
#include "Data\Event\Event.h"

//=======================================================
//
// イベントパーツ工場クラス
//
//=======================================================
class CEventPartsFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CEventPartsFactory();
	/**
	* @desc デストラクタ
	*/
	~CEventPartsFactory();

	/**
	* @desc 状態遷移マシンの取得
	* @return 状態遷移マシンのインスタンス
	*/
	virtual CStateMachine* getStateMachine(void);

};


//=======================================================
//
//　イベント工場(抽象)クラス
//
//=======================================================
class CEventFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CEventFactory()
	{

	}
	/**
	* @desc デストラクタ
	*/
	virtual ~CEventFactory()
	{

	}

	/**
	* @desc イベントを生成
	* @param 初期座標X
	* @param 初期座標Y
	* @return イベントインスタンス
	*/
	virtual CEvent* create(float posX, float posY)
	{
		//イベントの生成
		CEvent* pEvent = this->createEvent();

		//状態遷移マシンの設定
		this->settingStateMachine(pEvent);

		//初期設定
		this->settingInitialize(pEvent);

		return pEvent;
	}

protected:

	/**
	* @desc
	* @param イベントインスタンスのアドレス
	*/
	virtual CEvent* createEvent(void) = 0;
	
	/**
	* @desc 状態遷移マシンの設定
	* @param イベントインスタンスのアドレス
	*/
	virtual	void settingStateMachine(CEvent* pEvent) = 0;

	/**
	* @desc 初期化処理
	* @param イベントインスタンスのアドレス
	*/
	virtual void settingInitialize(CEvent* pEvent) = 0;

};



//=======================================================
//
// イベント生成工場
//
//=======================================================
template <class T>
class CEventCreateFactory : public CEventFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CEventCreateFactory()
	{

	}

	/**
	* @desc デストラクタ
	*/
	virtual ~CEventCreateFactory()
	{

	}

protected:
	virtual CEvent* createEvent(void)
	{
		//イベントの生成
		CEvent* pEvent = T::create();

		//イベント部品生成工場の生成
		CEventPartsFactory factory;

		//状態遷移マシンの設定
		pEvent->addStateMachine(factory.getStateMachine());

		return pEvent;
	}
};

//EOF