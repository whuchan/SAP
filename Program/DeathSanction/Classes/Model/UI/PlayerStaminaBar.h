#pragma once
//==========================================
//
// File: PlayerStaminaBar.h
//
// PlayerのStaminaを表示する ヘッダーファイル
//
// 2017/06/16
//						Author Shinya Ueba
//==========================================
#include"Classes\Model\Character\Character.h"

//==============================================
// PlayerのStaminaを表示するクラス
//==============================================
class CPlayerStaminaBar : public cocos2d::Sprite
{
public:
	//コンストラクタ
	CPlayerStaminaBar(CCharacter* const pOwner);

	//デストラクタ
	virtual ~CPlayerStaminaBar();

	//初期化処理
	virtual bool init(float posX, float posY);

	//更新処理
	virtual void update(float deltaTime)override;


	/**
	* @desc CREATE_FUNCマクロをオーバーライド
	* @param 初期位置X
	* @param 初期位置Y
	* @tips 初期位置を必要とするのは生成の段階ではなく
	*       initの段階である
	*/
	static CPlayerStaminaBar* create(CCharacter* const pOwner, float posX, float posY)
	{
		CPlayerStaminaBar* pRet = new(std::nothrow)CPlayerStaminaBar(pOwner);
		if (pRet&&pRet->init(posX, posY))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

public:
	//参照するキャラクター
	CCharacter* m_pOwner;
};

//EOF