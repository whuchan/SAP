#include "EventFactory.h"

/**
* @desc �R���X�g���N�^
*/
CEventPartsFactory::CEventPartsFactory()
{

}

/**
* @desc �f�X�g���N�^
*/
CEventPartsFactory::~CEventPartsFactory()
{

}

/**
* @desc ��ԑJ�ڃ}�V���̎擾
* @return ��ԑJ�ڃ}�V���̃C���X�^���X
*/
CStateMachine* CEventPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}