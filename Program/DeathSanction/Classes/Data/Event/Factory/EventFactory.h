#pragma once
#include "Model\Map\Map.h"
#include "Data\StateMachine\StateMachine.h"
#include "Data\Event\Event.h"

//=======================================================
//
// �C�x���g�p�[�c�H��N���X
//
//=======================================================
class CEventPartsFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEventPartsFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CEventPartsFactory();

	/**
	* @desc ��ԑJ�ڃ}�V���̎擾
	* @return ��ԑJ�ڃ}�V���̃C���X�^���X
	*/
	virtual CStateMachine* getStateMachine(void);

};


//=======================================================
//
//�@�C�x���g�H��(����)�N���X
//
//=======================================================
class CEventFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEventFactory()
	{

	}
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CEventFactory()
	{

	}

	/**
	* @desc �C�x���g�𐶐�
	* @param �������WX
	* @param �������WY
	* @return �C�x���g�C���X�^���X
	*/
	virtual CEvent* create(float posX, float posY)
	{
		//�C�x���g�̐���
		CEvent* pEvent = this->createEvent();

		//��ԑJ�ڃ}�V���̐ݒ�
		this->settingStateMachine(pEvent);

		//�����ݒ�
		this->settingInitialize(pEvent);

		return pEvent;
	}

protected:

	/**
	* @desc
	* @param �C�x���g�C���X�^���X�̃A�h���X
	*/
	virtual CEvent* createEvent(void) = 0;
	
	/**
	* @desc ��ԑJ�ڃ}�V���̐ݒ�
	* @param �C�x���g�C���X�^���X�̃A�h���X
	*/
	virtual	void settingStateMachine(CEvent* pEvent) = 0;

	/**
	* @desc ����������
	* @param �C�x���g�C���X�^���X�̃A�h���X
	*/
	virtual void settingInitialize(CEvent* pEvent) = 0;

};



//=======================================================
//
// �C�x���g�����H��
//
//=======================================================
template <class T>
class CEventCreateFactory : public CEventFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEventCreateFactory()
	{

	}

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CEventCreateFactory()
	{

	}

protected:
	virtual CEvent* createEvent(void)
	{
		//�C�x���g�̐���
		CEvent* pEvent = T::create();

		//�C�x���g���i�����H��̐���
		CEventPartsFactory factory;

		//��ԑJ�ڃ}�V���̐ݒ�
		pEvent->addStateMachine(factory.getStateMachine());

		return pEvent;
	}
};

//EOF