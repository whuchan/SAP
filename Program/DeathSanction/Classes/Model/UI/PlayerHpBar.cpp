//==========================================
//
// File: PlayerHpBar.h
//
// Player��Hp��\������ �t�@�C��
//
// 2017/06/16
//						Author Shinya Ueba
//==========================================

#include "PlayerHpBar.h"

//�R���X�g���N�^
CPlayerHpBar::CPlayerHpBar(CCharacter* const pOwner):m_pOwner(pOwner)
{

}

//�f�X�g���N�^
CPlayerHpBar::~CPlayerHpBar()
{

}

//����������
bool CPlayerHpBar::init(float posX, float posY)
{
	if (cocos2d::Sprite::init() == false)
	{
		CCLOG("CPlayerHpBar�̏������Ɏ��s");
		return false;
	}

	//�ʒu�̐ݒ�
	this->setPosition(posX,posY);

	//�e�N�X�`���̐ݒ�
	this->setTexture(IMAGE_PLAYER_HP_BAR);

	//update()�����o�Ăяo���֐�
	this->scheduleUpdate();

	return true;
}

//�X�V����
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