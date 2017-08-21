#pragma once

#include"Data\StateMachine\StateMachine.h"
#include "Constants.h"
#include "cocos2d.h"


/**
* @class �C�x���g���N���X
*/
class CEvent
{
public:
	CEvent();
	virtual ~CEvent();

	virtual bool initialize(void) = 0;

	/**
	* @desc �J�n����
	*/
	virtual void start(void) = 0;

	/**
	* @desc �X�V����
	*/
	virtual void update(void) = 0;

	/**
	* @desc �I������	
	*/
	virtual void end(void) = 0;

	/**
	* @desc �I�����菈��
	*/
	virtual void checkEnd(void) = 0;

	//�C�x���g���W
	cocos2d::Vec2 m_pos;

	//�C�x���g�I���t���O
	bool m_isEnd = false;

	//���
	int m_intState = 0;

	//�X�e�[�g�}�V�[��
	CStateMachine* m_stateMachine = NULL;
};

