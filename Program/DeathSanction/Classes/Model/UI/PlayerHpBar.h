#pragma once
//==========================================
//
// File: PlayerHpBar.h
//
// Player��Hp��\������ �w�b�_�[�t�@�C��
//
// 2017/06/16
//						Author Shinya Ueba
//==========================================
#include"Classes\Model\Character\Character.h"

//==============================================
// Player��Hp��\������N���X
//==============================================
class CPlayerHpBar : public cocos2d::Sprite
{
public:
	//�R���X�g���N�^
	CPlayerHpBar(CCharacter* const pOwner);

	//�f�X�g���N�^
	virtual ~CPlayerHpBar();

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
	static CPlayerHpBar* create(CCharacter* const pOwner,float posX, float posY)
	{
		CPlayerHpBar* pRet = new(std::nothrow)CPlayerHpBar(pOwner);
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


	cocos2d::Vec2 offsetPosition;
};

//EOF