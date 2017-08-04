#pragma once
//==========================================
//
// File: DamageFactory.h
//
// ダメージ工場 ヘッダーファイル
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================
#include "CharacterFactory.h"
#include"../DamageCharacter.h"
#include "Model\Map\Map.h"

//=======================================================
//
// ダメージパーツ工場クラス
//
//=======================================================
class CDamagePartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CDamagePartsFactory();
	/**
	* @desc デストラクタ
	*/
	~CDamagePartsFactory();


	/**
	* @desc 移動データの取得
	* @return 移動データ
	*/
	CMove*						getMove(void)override;

	/**
	* @desc 実体データの取得
	* @return 実体データ
	*/
	CBody*						getBody(void)override;

	/**
	* @desc 衝突判定領域データ群の取得
	* @return 衝突判定領域データ群
	*/
	std::vector<CCollisionArea*>* getCollisionAreas(void)override;

	/**
	* @desc 状態遷移マシンの取得
	* @return 状態遷移マシンのインスタンス
	*/
	virtual CStateMachine* getStateMachine(void)override;

};


//=======================================================
//
// ダメージ生成工場
//
//=======================================================
template <class T>
class CDamageCreateFactory : public CCharacterFactory
{
public:
	/**
	* @desc コンストラクタ
	*/
	CDamageCreateFactory()
	{

	}

	/**
	* @desc デストラクタ
	*/
	virtual ~CDamageCreateFactory()
	{

	}

protected:
	virtual CCharacter* createCharacter(void)
	{
		//敵キャラクターの生成
		CCharacter* pCharacter = T::create();

		//敵キャラクター部品生成工場の生成
		CDamagePartsFactory factory;

		//移動データの設定
		pCharacter->addMove(factory.getMove());
		//実体データの設定
		pCharacter->addBody(factory.getBody());
		//衝突判定データ群の設定
		pCharacter->addCollisionAreas(factory.getCollisionAreas());
		//状態遷移マシンの設定
		//pCharacter->addStateMachine(factory.getStateMachine());


		return pCharacter;
	}
};

//EOF