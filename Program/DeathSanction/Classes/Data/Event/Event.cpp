#include "Event.h"

CEvent::CEvent()
{

}

CEvent::~CEvent()
{
	//��ԑJ�ڃ}�V���̍폜
	SAFE_DELETE(this->m_stateMachine);
}
