#pragma once
#include "Model\Map\Map.h"
#include "Model\Character\EffectCharacter.h"
#include "Model\Character\Factory\CharacterFactory.h"

//=======================================================
//
// 敵工事管理クラス
//
// シングルトン
//
//=======================================================
class CEffectFactoryManager
{
private:
	/*
	* @desc コンストラクタ
	*/
	CEffectFactoryManager();
public:
	/**
	* @desc デストラクタ
	*/
	~CEffectFactoryManager();

	/**
	* @desc シングルトン：：インスタンスの取得
	* @return シングルトンインスタンス
	*/
	static CEffectFactoryManager* getInstance(void);
	/**
	* @desc 敵キャラクターを生成
	* @param 生成タイプ
	*/
	CCharacter* create(EFFECT_TYPE type, float posX, float posY);
	/**
	* @desc シングルトンインスタンスの解放
	*/
	static void removeInstance();

private:
	//敵生成工場群
	std::map<EFFECT_TYPE, CCharacterFactory*>* m_pFactories = NULL;
	//シングルトンインスタンス
	static CEffectFactoryManager* m_pSharedManager;
};
//EOF