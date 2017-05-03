#pragma once
#include "GimmickCharacter.h"


//======================================================
//
// �W�����v����u���b�N�M�~�b�N�L�����N�^�[�̊��N���X�ƂȂ�N���X
//
//======================================================
class CNoteBlockGimmickCharacter : public CGimmickCharacter
{
public:
	enum STATE :int
	{
		NORMAL		= 0,
		HIT_TOP		= 1,
		HIT_BOTTOM	= 2,
	};

	cocos2d::Vec2 m_vec2BasePosition = cocos2d::Vec2(0.0f,0.0f);

	//�R���X�g���N�^
	CNoteBlockGimmickCharacter();

	//�f�X�g���N�^
	virtual ~CNoteBlockGimmickCharacter();

	/**
	* @desc CREATE_FUNC
	* @tips �O��̓M�~�b�N�o���f�[�^�Ƃ����M�~�b�N��p�̃N���X�����݂��Ă����̂�
	* ���̃N���X�ɒ��������Ă����͐����Ȃ�������
	* ����̓}�b�v�̏��ɂ��o���ʒu�̌���Ƃ������ڂ��K�v�ɂȂ�
	* �}�b�v���V���O���g�����@�����̂Œ��������Ă����Ȃ��悤�Ɏv���邪
	* �ŏI�I�ɕK�v�ƂȂ�͈̂ʒu������
	* �Ȃ̂Ő����Ɠ����Ɉʒu���擾������
	* �����������Acocos2dx�̋@�\�ł��鎩����delete�̋@�\���g������
	* �Ȃ̂�create�ÓI�����o�֐����J�X�^�}�C�Y����
	*/
	//CREATE_FUNC(CGimmickCharacter);
	static CNoteBlockGimmickCharacter* create()
	{
		CNoteBlockGimmickCharacter* pRet = new(std::nothrow)CNoteBlockGimmickCharacter();
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
	static CNoteBlockGimmickCharacter* create(float posX, float posY)
	{
		CNoteBlockGimmickCharacter* pRet = new(std::nothrow)CNoteBlockGimmickCharacter();
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

	//��ԃ`�F�b�N
	virtual void checkState(float deltaTime)override;



	/**
	* @desc �v���C���[�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara)override;

	/**
	* @desc �G�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsEnemyCharacter(CCharacter* pChara)override;


};