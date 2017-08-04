#pragma once

#include "EnemyState.h"
#include "cocos2d.h"

//==========================================
//
// Class: CEnemyStateLineUp
//
// �v���C���[ ���C���A�b�v ��ԃN���X
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
template <class T >
class CEnemyStateLineUp :public CEnemyState<T>
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CEnemyStateLineUp(T* const pOwner) :CEnemyState(pOwner)
	{

	}

	/**
	* @desc	�f�X�g���N�^
	*/
	virtual~CEnemyStateLineUp(void)
	{

	}

	/**
	* @desc	�J�n����
	*/
	void enter(void)override
	{
		this->m_pOwner->m_intCurrentLine++;

		// 1�b�����āA�X�P�[�����k������
		ScaleTo* pOrder = ScaleTo::create(0.5, 1.0f - this->m_pOwner->m_intCurrentLine * 0.2f);
		this->m_pAction = this->m_pOwner->runAction(pOrder);
		CC_SAFE_RETAIN(this->m_pAction); // ����ɊJ������Ȃ��悤�ɎQ�ƃJ�E���^�𑝂₷

										 //�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
										 //(*this->m_pOwner->m_mapAction[(int)CEnemyCharacter::ACTION::JUMP])[0]->start();

		this->m_pOwner->m_pMove->m_vel.y = sqrtf(((CPhysicalGravity::GRAVITY * 0.6f) * (CPhysicalGravity::GRAVITY * 0.6f)) / 2.0f);

	}
	/**
	* @desc	�X�V����
	*/
	void execute(float deltaTime)override
	{
#ifdef _DEBUG_ENEMY_STATE
		log("Enemy: LineUp");
#endif //_DEBUG_ENEMY_STATE

		if (inputflag.m_d)
		{
			this->m_pOwner->m_pMove->m_vel.x = 100.0f;
		}
		else if (inputflag.m_a)
		{
			this->m_pOwner->m_pMove->m_vel.x = -100.0f;
		}


		if (this->m_pAction->isDone())
		{
			//�ҋ@��Ԃֈڍs
			this->toIdle();
			return;
		}
	}

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void exit(void)override
	{
		this->m_isNext = false;

		//�g��Ȃ��Ȃ�����������
		CC_SAFE_RELEASE(this->m_pAction);
	}

private:
	cocos2d::Action* m_pAction = NULL;
};
//EOF