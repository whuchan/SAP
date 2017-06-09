#include "Event.h"

CEvent::CEvent()
{

}

CEvent::~CEvent()
{
	//ó‘Ô‘JˆÚƒ}ƒVƒ“‚Ìíœ
	SAFE_DELETE(this->m_stateMachine);
}
