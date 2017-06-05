#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\EnemyCharacter.h"
#include "Model\Character\Factory\EnemyFactory.h"

//=======================================================
//
// 敵工事管理クラス
//
// シングルトン
//
//=======================================================
class CEnemyFactoryManager
{
private:
	/*
	* @desc コンストラクタ
	*/
	CEnemyFactoryManager();
public:
	/**
	* @desc デストラクタ
	*/
	~CEnemyFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CEnemyFactoryManager* getInstance(void);
	/**
	* @desc 敵キャラクターを生成
	* @param 生成タイプ
	*/
	CCharacter* create(ENEMY_TYPE type, float posX, float posY);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();

private:
	//敵生成工場群
	std::map<ENEMY_TYPE, CCharacterFactory*>* m_pFactories = NULL;
	//シングルトンインスタンス
	static CEnemyFactoryManager* m_pSharedManager;
};
//EOF