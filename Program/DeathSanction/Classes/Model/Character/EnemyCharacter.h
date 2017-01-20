#pragma once
#include "Character.h"

//======================================================
//
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//
//======================================================

class CEnemyCharacter : public CCharacter
{
public:
	//�R���X�g���N�^
	CEnemyCharacter();

	//�f�X�g���N�^
	~CEnemyCharacter();

	//����������
	bool init()override;

	/**
	* @desc�@����������
	* @param �����ʒuX
	* @param �����ʒuY
	* @tips create()�����o�֐��̒���init()�����o�֐����Ăяo���Ă��邪
	* ����A����create()�����o�֐����I�[�o�[���[�h����
	* �������󂯎���Ă���̂�init()�����o�֐���
	* �I�[�o�[���[�h����K�v������
	*/
	bool init(float posX, float posY);

	/**
	* @desc CREATE_FUNC
	* @tips �O��͓G�o���f�[�^�Ƃ����G��p�̃N���X�����݂��Ă����̂�
	* ���̃N���X�ɒ��������Ă����͐����Ȃ�������
	* ����̓}�b�v�̏��ɂ��o���ʒu�̌���Ƃ������ڂ��K�v�ɂȂ�
	* �}�b�v���V���O���g�����@�����̂Œ��������Ă����Ȃ��悤�Ɏv���邪
	* �ŏI�I�ɕK�v�ƂȂ�͈̂ʒu������
	* �Ȃ̂Ő����Ɠ����Ɉʒu���擾������
	* �����������Acocos2dx�̋@�\�ł��鎩����delete�̋@�\���g������
	* �Ȃ̂�create�ÓI�����o�֐����J�X�^�}�C�Y����
	*/
	//CREATE_FUNC(CEnemyCharacter);
	static CEnemyCharacter* create()
	{
		CEnemyCharacter* pRet = new(std::nothrow)CEnemyCharacter();
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
	static CEnemyCharacter* create(float posX,float posY)
	{
		CEnemyCharacter* pRet = new(std::nothrow)CEnemyCharacter();
		if (pRet&&pRet->init(posX,posY))
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

	//�ړ�����
	void moveFunc()override;

	//�A�j���[�V��������
	void animationFunc()override;

	//��ԂƂ̏Փ˔��菈��
	virtual void collision()override;

	//��ԃ`�F�b�N
	void checkState()override;

	//���f����
	void applyFunc()override;

	

	/**
	* @desc �L�����N�^�[�P�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override;
	
	/**
	* @desc �Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	void hits(CCharacter* pChara)override;

protected:

	/**
	* @desc �v���C���[�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara);

	/**
	* @desc �e�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsBulletCharacter(CCharacter* pChara);

};