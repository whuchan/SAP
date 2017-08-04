#pragma once
#include "Model\Map\Map.h"
#include "Data\Event\Factory\EventFactory.h"

//=======================================================
//
// 敵工事管理クラス
//
// シングルトン
//
//=======================================================
class CEventFactoryManager
{
private:
	/*
	* @desc コンストラクタ
	*/
	CEventFactoryManager();
public:
	/**
	* @desc デストラクタ
	*/
	~CEventFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CEventFactoryManager* getInstance(void);
	/**
	* @desc 敵キャラクターを生成
	* @param 生成タイプ
	*/
	CEvent* create(EVENT_TYPE type, float posX, float posY);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();

private:
	//敵生成工場群
	std::map<EVENT_TYPE, CEventFactory*>* m_pFactories = NULL;
	//シングルトンインスタンス
	static CEventFactoryManager* m_pSharedManager;
};
//EOF