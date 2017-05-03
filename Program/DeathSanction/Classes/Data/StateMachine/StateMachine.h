#pragma once
//==========================================
//
// File: StateMachine.h
//
// ��ԑJ�ڃ}�V�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include <map>

//==========================================
//
// Class: CStateBase
//
// ��ԑJ�� ���N���X  
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CStateBase
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CStateBase(void);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CStateBase(void);

	/**
	* @desc	�J�n����
	*/
	virtual void enter(void) = 0;

	/**
	* @desc �X�V����
	*/
	virtual void execute(void) = 0;

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	virtual void exit(void) = 0;

	/**
	* @desc �؂�ւ���������擾
	*/
	bool isNext(void);

	/**
	* @desc ���̏�Ԃ̃L�[���擾����
	*/
	int getNextKey(void);

protected:
	// ���ɍs�����߂̏���
	bool m_isNext = false;

	//���ɐi�ރX�e�[�g�̃L�[
	int m_nextRegisterKey = 0;

};


//==========================================
//
// Class: CStateMachine
//
// ��ԊǗ��N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CStateMachine
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CStateMachine(void);

	/**
	* @desc �f�X�g���N�^
	*/
	~CStateMachine(void);

	/**
	* @desc �X�V����
	*/
	void update(void);
	
	/**
	* @desc ��Ԃ�o�^����
	* @param �o�^����B�ꖳ��̃L�[
	* @param �o�^������
	*/
	void registerState(const int key, CStateBase* const pState);

	// �ŏ�����n�߂��Ԃ�ݒ�
	
	/**
	* @desc �ŏ�����J�n�����Ԃ�ݒ肷��
	* @param�@�ݒ肷��L�[
	*/
	void setStartState(const int key);

	// �o�^�������̂��폜����
	
	/**
	* @desc �o�^�������̂��폜����
	* @param �폜����L�[
	*/
	void deregistration(const int key);

	/**
	* @desc �S�Ă̓o�^���폜����
	*/
	void allDeregistration(void);

private:
	//��Ԋi�[�p�}�b�v
	std::map<int, CStateBase* > m_mapState;
	//���݂̏��
	CStateBase* m_pNowState = NULL;
};
//EOF