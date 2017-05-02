#pragma once
#include "cocos2d.h"
#include "../Character.h"

//===============================================
// 前方宣言
//===============================================
//class CBody;
//class CMove;
//class CStateMachine;
//class CCollisionArea;
//===============================================
//
// CCharacter生成工場クラス（抽象クラス）
//
//===============================================
class CCharacterPartsFactory
{
public:
	/**
	* コンストラクタ
	*/
	CCharacterPartsFactory();
	/**
	* デストラクタ
	*/
	virtual ~CCharacterPartsFactory();

	//==============================================================
	//
	// 純粋仮想関数
	//
	//==============================================================
	virtual CMove*						getMove(void) = 0;
	virtual CBody*						getBody(void) = 0;
	virtual std::vector<CCollisionArea*>* getCollisionAreas(void) = 0;
	/**
	* @desc 状態遷移マシンの取得
	* @return 状態遷移マシンのインスタンス
	*/
	virtual CStateMachine* getStateMachine(void) = 0;
};
//EOF