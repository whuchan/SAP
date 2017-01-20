#pragma once
//==========================================
//
// File: SoundManager.h
//
// 音楽管理 ヘッダーファイル
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================

#include	"cocos2d.h"
#include	"Constants.h"

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
class CSoundManager
{

private:
	/**
	* @desc コンストラクタ
	*/
	CSoundManager();

public:
	/**
	* @desc デストラクタ
	*/
	~CSoundManager();
	
	/**
	* @desc		共有インスタンス取得
	* @return	共有インスタンス
	*/
	static CSoundManager* getInstance(void);

	/**
	* @desc		共有インスタンス破棄
	*/
	static void removeInstance(void);

	/**
	*	@desc	BGMの音量設定
	*	@param　任意の音量
	*/
	void setBGMVolume(float floatVolume);

	/**
	*	@desc	効果音の音量設定
	*	@param　任意の音量
	*/
	void setSEVolume(float floatVolume);

	/**
	*	@desc	効果音の音量の取得
	*	@return  音量
	*/
	float getSEVolume(void);
	
	/*
	*	@desc	対象音楽IDの登録
	*	@param	登録する音楽の名称
	*	@param	扱いたい音楽のID
	*/
	void setMusicID(std::string stringMusicName, int intMusicID);

	/*
	*	@desc	対象音楽IDの取得
	*	@param	扱いたい音楽の名称
	*	@return	扱いたい音楽のID
	*/
	int getMusicID(std::string stringMusicName);

	/*
	*	@desc	指定の音をフェードインさせる
	*	@param	対象音楽の名称
	*/
	void fadeIn(std::string stringMusicName);

	/*
	*	@desc	指定の音をフェードアウト
	*	@param	対象音楽の名称
	*/
	void fadeOut(std::string stringMusicName);

	
private:

	// 共有インスタンス
	static CSoundManager* m_pointerSharedSoundManager;

	// 対象音楽ID
	std::map<std::string, int>	m_mapMusicID;

	// BGMの音量
	float m_floatBGMVolume = 0.0f;
	// 効果音の音量
	float m_floatSEVolume = 0.0f;
};
//EOF