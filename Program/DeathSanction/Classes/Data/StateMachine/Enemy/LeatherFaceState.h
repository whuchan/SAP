#pragma once
#include "Data\StateMachine\Enemy\EnemyState.h"
#include "Model\Character\HenchmanTypeAEnemy.h"

class CLeatherFaceState :public CStateBase
{
public:
	CLeatherFaceState(CHenchmanTypeAEnemy* const pOwner);

	~CLeatherFaceState();
};