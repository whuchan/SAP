//==========================================
//
// File: SoundManager.cpp
//
// 音楽管理 ファイル
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"Lib\Sound\SoundManager.h"

using namespace cocos2d::experimental;


//==========================================
//
// シングルトン
//
// Class: CSoundManager
//
// 音楽管理クラス   
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// 静的変数定義
//==========================================
// 共有インスタンス
CSoundManager* CSoundManager::m_pointerSharedSoundManager = NULL;



/**
* @desc コンストラクタ
*/
CSoundManager::CSoundManager()
{

}

/**
* @desc デストラクタ
*/
CSoundManager::~CSoundManager()
{
	std::map<std::string, int>::iterator iteratorIndex = this->m_mapMusicID.begin();

	while (iteratorIndex != this->m_mapMusicID.end()) {
		iteratorIndex->second = NULL;
		iteratorIndex++;
	}
	this->m_mapMusicID.clear();
}

/*
*	@desc	BGMの音量設定
*	@param　任意の音量
*/
void CSoundManager::setBGMVolume(float floatVolume)
{
	this->m_floatBGMVolume = floatVolume;
}

/*
*	@desc	効果音の音量設定
*	@param　任意の音量
*/
void CSoundManager::setSEVolume(float floatVolume)
{
	this->m_floatSEVolume = floatVolume;
}

/**
*	@desc	効果音の音量の取得
*	@return  音量
*/
float CSoundManager::getSEVolume(void)
{
	return this->m_floatSEVolume;
}

/*
*	@desc	対象音楽IDの登録
*	@param	登録する音楽の名称
*	@param	扱いたい音楽のID
*/
void CSoundManager::setMusicID(std::string stringMusicName, int intMusicID)
{
	this->m_mapMusicID[stringMusicName] = intMusicID;
}

/*
*	@desc	対象音楽IDの取得
*	@param	扱いたい音楽の名称
*	@return	扱いたい音楽のID
*/
int CSoundManager::getMusicID(std::string stringMusicName)
{
	return this->m_mapMusicID[stringMusicName];
}

/*
*	@desc	指定の音をフェードインさせる
*	@param	対象音楽の名称
*/
void CSoundManager::fadeIn(std::string stringMusicName)
{
	int intMusicID = this->getMusicID(stringMusicName);

	float floatVolume = AudioEngine::getVolume(intMusicID);

	// MAX Volume 出なければ足す
	if (floatVolume < this->m_floatBGMVolume) {
		AudioEngine::setVolume(intMusicID, floatVolume + 0.01f);
	}
}

/*
*	@desc	指定の音をフェードアウト
*	@param	対象音楽の名称
*/
void CSoundManager::fadeOut(std::string stringMusicName)
{
	int intMusicID = this->getMusicID(stringMusicName);

	float floatVolume = AudioEngine::getVolume(intMusicID);

	// MAX Volume 出なければ足す
	if (floatVolume > 0.0f) {
		AudioEngine::setVolume(intMusicID, floatVolume - 0.01f);
	}
	else {
		// 音楽を止める
		AudioEngine::stop(intMusicID);
	}
}

/**
* @desc 共有インスタンス取得
* @return	共有インスタンス
*/
CSoundManager* CSoundManager::getInstance(void)
{
	if (CSoundManager::m_pointerSharedSoundManager == NULL)
	{
		CSoundManager::m_pointerSharedSoundManager = new CSoundManager();
	}
	return CSoundManager::m_pointerSharedSoundManager;
}

/**
* @desc		共有インスタンス破棄
*/
void CSoundManager::removeInstance(void)
{
	SAFE_DELETE(CSoundManager::m_pointerSharedSoundManager);
}
//EOF