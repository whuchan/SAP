#pragma once
#include "EnemyCharacter.h"

//======================================================
//
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//
//======================================================

class CHenchmanTypeAEnemy : public CEnemyCharacter<CHenchmanTypeAEnemy>
{
public:
	//=========================================================
	// �萔
	//=========================================================
	//�v���C���[�̏��
	enum class STATE :int
	{
		IDLE			= 0,
		MOVE			= 1,
		ATTACK			= 2,
		LINE_UP			= 3,
		LINE_DOWN		= 4,
		JUMP			= 5,
		FALLING			= 6,		//�~��
		APPLY_DAMAGE	= 7,
		DEAD			= 8,
	};

public:
	//�R���X�g���N�^
	CHenchmanTypeAEnemy();

	//�f�X�g���N�^
	virtual ~CHenchmanTypeAEnemy();

	////����������
	//bool init()override;

	///**
	//* @desc CREATE_FUNC�}�N�����I�[�o�[���C�h
	//* @param �����ʒuX
	//* @param �����ʒuY
	//* @tips �����ʒu��K�v�Ƃ���̂͐����̒i�K�ł͂Ȃ�
	//*       init�̒i�K�ł���
	//*/
	//static CEnemyCharacter* create(float posX, float posY)
	//{
	//	CEnemyCharacter* pRet = new(std::nothrow)CEnemyCharacter();
	//	if (pRet&&pRet->init(posX, posY))
	//	{
	//		pRet->autorelease();
	//		return pRet;
	//	}
	//	else
	//	{
	//		delete pRet;
	//		pRet = NULL;
	//		return NULL;
	//	}
	//}

	////�ړ�����
	//void moveFunction(float deltaTime)override;

	////�A�j���[�V��������
	//void animationFunction(float deltaTime)override;

	////��ԂƂ̏Փ˔��菈��
	//virtual void collision()override;

	////��ԃ`�F�b�N
	//void checkState(float deltaTime)override;

	////���f����
	//void applayFunction()override;



	///**
	//* @desc �L�����N�^�[�P�̂Ƃ̏Փ˔��菈��
	//* @param �L�����N�^�[�̃A�h���X
	//* @return true...�Փ˂���
	//*/
	//bool collision(CCharacter* pChara)override;

	///**
	//* @desc �Փ˔����̏���
	//* @param �Փ˂��Ă����L�����N�^-
	//*/
	//void hits(CCharacter* pChara)override;

protected:

	///**
	//* @desc �v���C���[�Ƃ̏Փ˔����̏���
	//* @param �Փ˂��Ă����L�����N�^-
	//*/
	//virtual void hitsPlayerCharacter(CCharacter* pChara);

	///**
	//* @desc �e�Ƃ̏Փ˔����̏���
	//* @param �Փ˂��Ă����L�����N�^-
	//*/
	//virtual void hitsBulletCharacter(CCharacter* pChara);

};