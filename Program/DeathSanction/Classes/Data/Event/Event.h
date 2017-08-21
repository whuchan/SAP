#pragma once

#include"Data\StateMachine\StateMachine.h"
#include "Constants.h"
#include "cocos2d.h"


/**
* @class イベント基底クラス
*/
class CEvent
{
public:
	CEvent();
	virtual ~CEvent();

	virtual bool initialize(void) = 0;

	/**
	* @desc 開始処理
	*/
	virtual void start(void) = 0;

	/**
	* @desc 更新処理
	*/
	virtual void update(void) = 0;

	/**
	* @desc 終了処理	
	*/
	virtual void end(void) = 0;

	/**
	* @desc 終了判定処理
	*/
	virtual void checkEnd(void) = 0;

	//イベント座標
	cocos2d::Vec2 m_pos;

	//イベント終了フラグ
	bool m_isEnd = false;

	//状態
	int m_intState = 0;

	//ステートマシーン
	CStateMachine* m_stateMachine = NULL;
};

