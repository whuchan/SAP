#include"DamageFactoryManager.h"
#include "Model\Character\Factory\PlayerAttack1Factory.h"
//=======================================================
//
// ダメージキャラクター生成クラス管理クラス
//
// シングルトン
//
//=======================================================
//シングルトンインスタンス
CDamageFactoryManager* CDamageFactoryManager::m_pSharedManager = NULL;

/*
* @desc コンストラクタ
*/
CDamageFactoryManager::CDamageFactoryManager()
{
	//敵工場群の生成
	this->m_pFactories = new std::map<DAMAGE_TYPE, CCharacterFactory*>();

	//工場を生成して取り付けていく
	//連想配列のキーはマップチップIDに設定
	(*this->m_pFactories)[DAMAGE_TYPE::PLAYER_ATTACK_1] = new CPlayerAttack1Factory();
}

/**
* @desc デストラクタ
*/
CDamageFactoryManager::~CDamageFactoryManager()
{
	//敵生成工場群の破棄
	std::map<DAMAGE_TYPE, CCharacterFactory*>::iterator itr = this->m_pFactories->begin();

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
CDamageFactoryManager* CDamageFactoryManager::getInstance(void)
{
	if (CDamageFactoryManager::m_pSharedManager == NULL)
	{
		CDamageFactoryManager::m_pSharedManager = new CDamageFactoryManager();
	}
	return CDamageFactoryManager::m_pSharedManager;
}

/**
* @desc 敵キャラクターを生成
* @param 生成タイプ
* @param 初期座標X
* @param 初期座標Y
*/
CCharacter* CDamageFactoryManager::create(DAMAGE_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc シングルトンインスタンスの解放
*/
void CDamageFactoryManager::removeInstance()
{
	SAFE_DELETE(CDamageFactoryManager::m_pSharedManager);
}