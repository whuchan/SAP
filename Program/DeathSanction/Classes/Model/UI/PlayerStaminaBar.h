#pragma once
//==========================================
//
// File: PlayerStaminaBar.h
//
// Player��Stamina��\������ �w�b�_�[�t�@�C��
//
// 2017/06/16
//						Author Shinya Ueba
//==========================================
#include"Classes\Model\Character\Character.h"

//==============================================
// Player��Stamina��\������N���X
//==============================================
class CPlayerStaminaBar : public cocos2d::Sprite
{
public:
	//�R���X�g���N�^
	CPlayerStaminaBar(CCharacter* const pOwner);

	//�f�X�g���N�^
	virtual ~CPlayerStaminaBar();

	//����������
	virtual bool init(float posX, float posY);

	//�X�V����
	virtual void update(float deltaTime)override;


	/**
	* @desc CREATE_FUNC�}�N�����I�[�o�[���C�h
	* @param �����ʒuX
	* @param �����ʒuY
	* @tips �����ʒu��K�v�Ƃ���̂͐����̒i�K�ł͂Ȃ�
	*       init�̒i�K�ł���
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
	//�Q�Ƃ���L�����N�^�[
	CCharacter* m_pOwner;
};

//EOF