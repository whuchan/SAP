#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\DamageCharacter.h"
#include "Model\Character\Factory\DamageFactory.h"

//=======================================================
//
// 敵工事管理クラス
//
// シングルトン
//
//=======================================================
class CDamageFactoryManager
{
private:
	/*
	* @desc コンストラクタ
	*/
	CDamageFactoryManager();
public:
	/**
	* @desc デストラクタ
	*/
	~CDamageFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CDamageFactoryManager* getInstance(void);
	/**
	* @desc 敵キャラクターを生成
	* @param 生成タイプ
	*/
	CCharacter* create(DAMAGE_TYPE type, float posX, float posY);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();

private:
	//敵生成工場群
	std::map<DAMAGE_TYPE, CCharacterFactory*>* m_pFactories = NULL;
	//シングルトンインスタンス
	static CDamageFactoryManager* m_pSharedManager;
};
//EOF