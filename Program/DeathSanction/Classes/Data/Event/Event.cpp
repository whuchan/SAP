#include "Event.h"

CEvent::CEvent()
{

}

CEvent::~CEvent()
{
	//状態遷移マシンの削除
	SAFE_DELETE(this->m_stateMachine);
}
