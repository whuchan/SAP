#pragma once
#include "BulletCharacter.h"


//======================================================
//
// �t�@�C�A�[�{�[���N���X
//
//======================================================
class CFireBallBulletCharacter : public CBulletCharacter
{
public:
	//�R���X�g���N�^
	CFireBallBulletCharacter();

	//�f�X�g���N�^
	~CFireBallBulletCharacter();

	/**
	* @desc CREATE_FUNC
	* @tips �O��͒e�o���f�[�^�Ƃ����e��p�̃N���X�����݂��Ă����̂�
	* ���̃N���X�ɒ��������Ă����͐����Ȃ�������
	* ����̓}�b�v�̏��ɂ��o���ʒu�̌���Ƃ������ڂ��K�v�ɂȂ�
	* �}�b�v���V���O���g�����@�����̂Œ��������Ă����Ȃ��悤�Ɏv���邪
	* �ŏI�I�ɕK�v�ƂȂ�͈̂ʒu������
	* �Ȃ̂Ő����Ɠ����Ɉʒu���擾������
	* �����������Acocos2dx�̋@�\�ł��鎩����delete�̋@�\���g������
	* �Ȃ̂�create�ÓI�����o�֐����J�X�^�}�C�Y����
	*/
	//CREATE_FUNC(CBulletCharacter);
	static CFireBallBulletCharacter* create()
	{
		CFireBallBulletCharacter* pRet = new(std::nothrow)CFireBallBulletCharacter();
		if (pRet&&pRet->init())
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

	/**
	* @desc CREATE_FUNC�}�N�����I�[�o�[���C�h
	* @param �����ʒuX
	* @param �����ʒuY
	* @tips �����ʒu��K�v�Ƃ���̂͐����̒i�K�ł͂Ȃ�
	*       init�̒i�K�ł���
	*/
	static CFireBallBulletCharacter* create(float posX, float posY)
	{
		CFireBallBulletCharacter* pRet = new(std::nothrow)CFireBallBulletCharacter();
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

	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionBottomCallback(int event)override;

private:
//	DIRECTION_TYPE m_typeDirection = DIRECTION_TYPE::LEFT;
};
