//==========================================
//
// File: PlayerStaminaBar.h
//
// PlayerのStaminaを表示する ファイル
//
// 2017/06/16
//						Author Shinya Ueba
//==========================================

#include "PlayerStaminaBar.h"

//コンストラクタ
CPlayerStaminaBar::CPlayerStaminaBar(CCharacter* const pOwner) :m_pOwner(pOwner)
{

}

//デストラクタ
CPlayerStaminaBar::~CPlayerStaminaBar()
{

}

//初期化処理
bool CPlayerStaminaBar::init(float posX, float posY)
{
	if (cocos2d::Sprite::init() == false)
	{
		CCLOG("CPlayerStaminaBarの初期化に失敗");
		return false;
	}

	//位置の設定
	this->setPosition(posX, posY);

	//テクスチャの設定
	this->setTexture(IMAGE_PLAYER_STAMINA_BAR);

	//update()メンバ呼び出し関数
	this->scheduleUpdate();


	this->offsetPosition = cocos2d::Vec2(posX,posY);

	return true;
}

//更新処理
void CPlayerStaminaBar::update(float deltaTime)
{
	if (!this->m_pOwner)
	{
		return;
	}

	float value = this->m_pOwner->m_status.getStamina() / this->m_pOwner->m_status.getMaxStamina();

	this->setScaleX(value);

	cocos2d::Vec2 pos = this->offsetPosition;

	pos.x -= (this->getTextureRect().size.width * (1.0f-value)) * 0.5f;

	this->setPosition(pos);
}

//EOF