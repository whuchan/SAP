#include"EnemyFactoryManager.h"
#include "Model\Character\Factory\HenchmanTypeAFactory.h"
//=======================================================
//
// 敵キャラクター生成クラス管理クラス
//
// シングルトン
//
//=======================================================
//シングルトンインスタンス
CEnemyFactoryManager* CEnemyFactoryManager::m_pSharedManager = NULL;

/*
* @desc コンストラクタ
*/
CEnemyFactoryManager::CEnemyFactoryManager()
{
	//敵工場群の生成
	this->m_pFactories = new std::map<ENEMY_TYPE, CCharacterFactory*>();

	//工場を生成して取り付けていく
	//連想配列のキーはマップチップIDに設定
	//クリボー生成工場の取り付け
	//(*this->m_pFactories)[ENEMY_TYPE::KURIBO] = new CKuriboFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::NOKONOKO] = new CGreenNokoNokoFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::PATAPATA] = new CGreenPataPataFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::KILLERBATTERY] = new CKillerBatteryFactory();
	//(*this->m_pFactories)[ENEMY_TYPE::KILLER] = new CKillerFactory();

	(*this->m_pFactories)[ENEMY_TYPE::KURIBO] = new CHenchmanTypeAFactory();
}

/**
* @desc デストラクタ
*/
CEnemyFactoryManager::~CEnemyFactoryManager()
{
	//敵生成工場群の破棄
	std::map<ENEMY_TYPE, CCharacterFactory*>::iterator itr = this->m_pFactories->begin();

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
CEnemyFactoryManager* CEnemyFactoryManager::getInstance(void)
{
	if (CEnemyFactoryManager::m_pSharedManager == NULL)
	{
		CEnemyFactoryManager::m_pSharedManager = new CEnemyFactoryManager();
	}
	return CEnemyFactoryManager::m_pSharedManager;
}

/**
* @desc 敵キャラクターを生成
* @param 生成タイプ
* @param 初期座標X
* @param 初期座標Y
*/
CCharacter* CEnemyFactoryManager::create(ENEMY_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc シングルトンインスタンスの解放
*/
void CEnemyFactoryManager::removeInstance()
{
	SAFE_DELETE(CEnemyFactoryManager::m_pSharedManager);
}