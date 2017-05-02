#pragma once
#include "cocos2d.h"
#include "../Character.h"

//===============================================
// �O���錾
//===============================================
//class CBody;
//class CMove;
//class CStateMachine;
//class CCollisionArea;
//===============================================
//
// CCharacter�����H��N���X�i���ۃN���X�j
//
//===============================================
class CCharacterPartsFactory
{
public:
	/**
	* �R���X�g���N�^
	*/
	CCharacterPartsFactory();
	/**
	* �f�X�g���N�^
	*/
	virtual ~CCharacterPartsFactory();

	//==============================================================
	//
	// �������z�֐�
	//
	//==============================================================
	virtual CMove*						getMove(void) = 0;
	virtual CBody*						getBody(void) = 0;
	virtual std::vector<CCollisionArea*>* getCollisionAreas(void) = 0;
	/**
	* @desc ��ԑJ�ڃ}�V���̎擾
	* @return ��ԑJ�ڃ}�V���̃C���X�^���X
	*/
	virtual CStateMachine* getStateMachine(void) = 0;
};
//EOF