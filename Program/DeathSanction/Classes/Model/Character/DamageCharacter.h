#pragma once
#include "Character.h"

//================================================================
// �e�̎��
//================================================================

enum class DAMAGE_TYPE :int
{
	NORMAL = 0,		//�W��
	CUSTOM = 1,		//�J�X�^��
	FIREBALL = 2,	//�t�@�C�A�[�{�[��
};

//======================================================
//
// �e�L�����N�^�[�̊��N���X�ƂȂ�N���X
//
//======================================================
class CDamageCharacter : public CCharacter
{
public:
	//�R���X�g���N�^
	CDamageCharacter();

	//�f�X�g���N�^
	virtual ~CDamageCharacter();

	//����������
	virtual bool init()override;

	/**
	* @desc�@����������
	* @param �����ʒuX
	* @param �����ʒuY
	* @tips create()�����o�֐��̒���init()�����o�֐����Ăяo���Ă��邪
	* ����A����create()�����o�֐����I�[�o�[���[�h����
	* �������󂯎���Ă���̂�init()�����o�֐���
	* �I�[�o�[���[�h����K�v������
	*/
	virtual bool init(float posX, float posY);

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
	//CREATE_FUNC(CDamageCharacter);
	static CDamageCharacter* create()
	{
		CDamageCharacter* pRet = new(std::nothrow)CDamageCharacter();
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
	static CDamageCharacter* create(float posX, float posY)
	{
		CDamageCharacter* pRet = new(std::nothrow)CDamageCharacter();
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

	//�ړ�����
	void moveFunction(float deltaTime)override;

	//�A�j���[�V��������
	void animationFunction(float deltaTime)override;

	//��ԂƂ̏Փ˔��菈��
	virtual void collision()override;

	//��ԃ`�F�b�N
	void checkState(float deltaTime)override;

	//���f����
	void applayFunction()override;



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


	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionBottomCallback(int event)override;

	/**
	* @desc ��̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionTopCallback(int event)override;

	/**
	* @desc �E�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionRightCallback(int event)override;

	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionLeftCallback(int event)override;

};
