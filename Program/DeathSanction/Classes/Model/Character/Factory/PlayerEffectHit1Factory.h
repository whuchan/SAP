#pragma once
#include "EffectFactory.h"
#include "Model\Character\EffectCharacter.h"

//=======================================================
//
// プレイヤーアタック１工場クラス
//
//=======================================================
class CPlayerEffectHit1Factory : public CEffectCreateFactory<CEffectCharacter>
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerEffectHit1Factory();
	/**
	* @desc デストラクタ
	*/
	~CPlayerEffectHit1Factory();
protected:
	/**
	* @desc	 移動データを設定
	* @param 敵キャラクターインスタンスのアドレス
	* @param 初期座標X
	* @param 初期座標Y
	*/
	void settingMove(CCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 テクスチャーを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingTexture(CCharacter* pCharacter)override;
	/**
	* @desc	 アニメーションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingAnimations(CCharacter* pCharacter)override;
	/**
	* @desc	 物理演算データ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingPhysicals(CCharacter* pCharacter)override;
	/**
	* @desc	 アクションデータ群を設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingActions(CCharacter* pCharacter)override;
	/**
	* @desc	 実体データを設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingBody(CCharacter* pCharacter)override;
	/**
	* @desc 衝突判定領域データ群の設定
	* @param 衝突判定領域データ群
	*/
	void settingCollisionAreas(CCharacter* pCharacter)override;

	/**
	* @desc 状態遷移マシンの設定
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingStateMachine(CCharacter* pCharacter)override;

	/**
	* @desc	 初期化処理
	* @param 敵キャラクターインスタンスのアドレス
	*/
	void settingInitialize(CCharacter* pCharacter)override;
};
//EOF