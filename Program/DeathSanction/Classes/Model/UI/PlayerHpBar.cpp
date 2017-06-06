//==========================================
//
// File: PlayerHpBar.h
//
// PlayerのHpを表示する ファイル
//
// 2017/06/16
//						Author Shinya Ueba
//==========================================

#include "PlayerHpBar.h"

//コンストラクタ
CPlayerHpBar::CPlayerHpBar(CCharacter* const pOwner):m_pOwner(pOwner)
{

}

//デストラクタ
CPlayerHpBar::~CPlayerHpBar()
{

}

//初期化処理
bool CPlayerHpBar::init(float posX, float posY)
{
	if (cocos2d::Sprite::init() == false)
	{
		CCLOG("CPlayerHpBarの初期化に失敗");
		return false;
	}

	//位置の設定
	this->setPosition(posX,posY);

	//テクスチャの設定
	this->setTexture(IMAGE_PLAYER_HP_BAR);

	//update()メンバ呼び出し関数
	this->scheduleUpdate();

	return true;
}

//更新処理
void CPlayerHpBar::update(float deltaTime)
{
	if (!this->m_pOwner)
	{
		return;
	}

	float value = this->m_pOwner->m_status.getHp() / this->m_pOwner->m_status.getmaxHp();

	this->setScaleX(value);
}

//EOF