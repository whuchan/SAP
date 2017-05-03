//==========================================
//
// File: StateMachine.cpp
//
// ��ԑJ�ڃ}�V�� �t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
#include"StateMachine.h"
#include "Constants.h"


/**
* @desc �R���X�g���N�^
*/
CStateBase::CStateBase(void)
{

}

/**
* @desc �f�X�g���N�^
*/
CStateBase::~CStateBase(void)
{

}

/**
* @desc	�J�n����
*/
void CStateBase::enter(void)
{


}

/**
* @desc �X�V����
*/
void CStateBase::execute(float deltaTime)
{


}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CStateBase::exit(void)
{

}

/**
* @desc �؂�ւ���������擾
*/
bool CStateBase::isNext(void)
{ 
	return this->m_isNext;
}

/**
* @desc ���̏�Ԃ̃L�[���擾����
*/
int CStateBase::getNextKey(void)
{
	return this->m_nextRegisterKey;
}



//==========================================
//
// Class: CStateMachine
//
// ��ԊǗ��N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CStateMachine::CStateMachine(void) :m_pNowState()
{

}

/**
* @desc �f�X�g���N�^
*/
CStateMachine::~CStateMachine(void)
{
	//���t������ԃf�[�^���폜
	std::map<int, CStateBase* >::iterator itr = this->m_mapState.begin();
	while (itr != this->m_mapState.end()) {
		//�N���X�̃C���X�^���X���폜
		SAFE_DELETE(itr->second);
		//�C�e���[�^�[���X�V
		itr++;
	}
}

/**
* @desc �X�V����
*/
void CStateMachine::update(float deltaTime)
{
	if (!this->m_pNowState)
	{
		return;
	}
	
	//���݂̏�Ԃ��X�V
	this->m_pNowState->execute(deltaTime);

	//���̏�Ԃֈڂ�邩�m�F
	if (this->m_pNowState->isNext())
	{
		//���݂̃X�e�[�g�̏I���������s��
		this->m_pNowState->exit();

		std::map<int, CStateBase* >::iterator itr = this->m_mapState.find(this->m_pNowState->getNextKey());
		if (itr == this->m_mapState.end())
		{
			return;
		}
		//���̏�Ԃ֑J��
		this->m_pNowState = itr->second;
		//���̏�Ԃ��J�n
		this->m_pNowState->enter();
	}
}

/**
* @desc ��Ԃ�o�^����
* @param �o�^����B�ꖳ��̃L�[
* @param 
*/
void CStateMachine::registerState(const int key,CStateBase* const pState)
{
	//��Ԃ�o�^����
	this->m_mapState[key] = pState;
}

/**
* @desc �ŏ�����J�n�����Ԃ�ݒ肷��
* @param �ݒ肷��L�[
*/
void CStateMachine::setStartState(const int key)
{
	std::map<int, CStateBase* >::iterator itr = this->m_mapState.find(key);
	if (itr == this->m_mapState.end())
	{
		return;
	}
	
	this->m_pNowState = itr->second;
	this->m_pNowState->enter();
}

/**
* @desc �o�^�������̂��폜����
* @param �폜����L�[
*/
void CStateMachine::deregistration(const int key)
{
	std::map<int, CStateBase* >::iterator itr = this->m_mapState.find(key);
	if (itr == this->m_mapState.end())
	{
		return;
	}
	this->m_mapState.erase(itr);
}

/**
* @desc �S�Ă̓o�^���폜����
*/
void CStateMachine::allDeregistration(void)
{
	this->m_mapState.clear();
}
//EOF