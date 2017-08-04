#include"EffectFactoryManager.h"
#include "Model\Character\Factory\PlayerEffectHit1Factory.h"
//=======================================================
//
// ダメージキャラクター生成クラス管理クラス
//
// シングルトン
//
//=======================================================
//シングルトンインスタンス
CEffectFactoryManager* CEffectFactoryManager::m_pSharedManager = NULL;

/*
* @desc コンストラクタ
*/
CEffectFactoryManager::CEffectFactoryManager()
{
	//敵工場群の生成
	this->m_pFactories = new std::map<EFFECT_TYPE, CCharacterFactory*>();

	//工場を生成して取り付けていく
	//連想配列のキーはマップチップIDに設定
	(*this->m_pFactories)[EFFECT_TYPE::PLAYER_HIT_1] = new CPlayerEffectHit1Factory();
}

/**
* @desc デストラクタ
*/
CEffectFactoryManager::~CEffectFactoryManager()
{
	//敵生成工場群の破棄
	std::map<EFFECT_TYPE, CCharacterFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//敵生成工場群の破棄
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc シングルトン：：インスタンスの取得
* @return シングルトンインスタンス
*/
CEffectFactoryManager* CEffectFactoryManager::getInstance(void)
{
	if (CEffectFactoryManager::m_pSharedManager == NULL)
	{
		CEffectFactoryManager::m_pSharedManager = new CEffectFactoryManager();
	}
	return CEffectFactoryManager::m_pSharedManager;
}

/**
* @desc 敵キャラクターを生成
* @param 生成タイプ
* @param 初期座標X
* @param 初期座標Y
*/
CCharacter* CEffectFactoryManager::create(EFFECT_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc シングルトンインスタンスの解放
*/
void CEffectFactoryManager::removeInstance()
{
	SAFE_DELETE(CEffectFactoryManager::m_pSharedManager);
}