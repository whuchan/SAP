#include "Data\Event\Factory\EventFactoryManger.h"

//=======================================================
//
// イベント生成クラス管理クラス
//
// シングルトン
//
//=======================================================
//シングルトンインスタンス
CEventFactoryManager* CEventFactoryManager::m_pSharedManager = NULL;

/*
* @desc コンストラクタ
*/
CEventFactoryManager::CEventFactoryManager()
{
	//イベント工場群の生成
	this->m_pFactories = new std::map<EVENT_TYPE, CEventFactory*>();

	/*
	//工場を生成して取り付けていく
	//連想配列のキーはマップチップIDに設定
	(*this->m_pFactories)[ENEMY_TYPE::HENCHMAN_TYPE_A] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::LEATHERFACE] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::KILLER] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::KILLERBATTERY] = new CHenchmanTypeAFactory();
	(*this->m_pFactories)[ENEMY_TYPE::PATAPATA] = new CHenchmanTypeAFactory();
	*/	
}

/**
* @desc デストラクタ
*/
CEventFactoryManager::~CEventFactoryManager()
{
	//イベント生成工場群の破棄
	std::map<EVENT_TYPE, CEventFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//イベント生成工場群の破棄
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc シングルトン：：インスタンスの取得
* @return シングルトンインスタンス
*/
CEventFactoryManager* CEventFactoryManager::getInstance(void)
{
	if (CEventFactoryManager::m_pSharedManager == NULL)
	{
		CEventFactoryManager::m_pSharedManager = new CEventFactoryManager();
	}
	return CEventFactoryManager::m_pSharedManager;
}

/**
* @desc イベントを生成
* @param 生成タイプ
* @param 初期座標X
* @param 初期座標Y
*/
CEvent* CEventFactoryManager::create(EVENT_TYPE type, float posX, float posY)
{
	return (*this->m_pFactories)[type]->create(posX, posY);
}

/**
* @desc シングルトンインスタンスの解放
*/
void CEventFactoryManager::removeInstance()
{
	SAFE_DELETE(CEventFactoryManager::m_pSharedManager);
}
//EOF