//==========================================
//
// File: PlayerStaminaBar.h
//
// Player��Stamina��\������ �t�@�C��
//
// 2017/06/16
//						Author Shinya Ueba
//==========================================

#include "PlayerStaminaBar.h"

//�R���X�g���N�^
CPlayerStaminaBar::CPlayerStaminaBar(CCharacter* const pOwner) :m_pOwner(pOwner)
{

}

//�f�X�g���N�^
CPlayerStaminaBar::~CPlayerStaminaBar()
{

}

//����������
bool CPlayerStaminaBar::init(float posX, float posY)
{
	if (cocos2d::Sprite::init() == false)
	{
		CCLOG("CPlayerStaminaBar�̏������Ɏ��s");
		return false;
	}

	//�ʒu�̐ݒ�
	this->setPosition(posX, posY);

	//�e�N�X�`���̐ݒ�
	this->setTexture(IMAGE_PLAYER_STAMINA_BAR);

	//update()�����o�Ăяo���֐�
	this->scheduleUpdate();


	this->offsetPosition = cocos2d::Vec2(posX,posY);

	return true;
}

//�X�V����
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