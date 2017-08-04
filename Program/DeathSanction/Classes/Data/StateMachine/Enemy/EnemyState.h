#pragma once
//==========================================
//
// File: EnemyState.h
//
// �G�l�~�[��ԑJ�� �w�b�_�[�t�@�C��
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../StateMachine.h"

//==========================================
//
// Class: CEnemyState
//
// �G�l�~�[ ��� ���N���X
//
// 2017/05/15
//						Author Shinya Ueba
//==========================================
template <class T>
class CEnemyState : public CStateBase
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CEnemyState(T* const pOwner):m_pOwner(pOwner)
	{

	}
	
	/**
	* @desc	�f�X�g���N�^
	*/
	virtual ~CEnemyState(void)
	{

	}

	/**
	*	@desc	�ҋ@��Ԃֈڍs
	*/
	void toIdle(void)
	{
		//�G�l�~�[�̏��
		this->m_pOwner->m_state = (int)T::STATE::IDLE;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//�ҋ@������I��
		this->m_isNext = true;
	}


	/**
	*	@desc	�ړ���Ԃֈڍs
	*/
	void toMove(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::MOVE;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//�ҋ@������I��
		this->m_isNext = true;
	}

	/**
	*	@desc	���C���A�b�v��Ԃֈڍs
	*/
	void toLineUp(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::LINE_UP;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//�ҋ@������I��
		this->m_isNext = true;
	}

	/**
	*	@desc	���C���_�E����Ԃֈڍs
	*/
	void toLineDown(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::LINE_DOWN;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//�ҋ@������I��
		this->m_isNext = true;
	}

	///**
	// * @desc	�U����Ԃֈڍs
	// */
	void toAttack(void)
	{
		this->m_pOwner->m_state = (int)T::STATE::ATTACK;

		this->m_nextRegisterKey = this->m_pOwner->m_state;
		//�ҋ@������I��
		this->m_isNext = true;
	}


	/**
	* @desc	�J�n����
	*/
	virtual void enter(void)
	{

	}

	/**
	* @desc �X�V����
	*/
	virtual void execute(float deltaTime)
	{

	}

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	virtual void exit(void)
	{

	}

protected:
	//�Q�Ƃ���G�l�~�[�L�����N�^�[
	T* m_pOwner = NULL;
};
//EOF