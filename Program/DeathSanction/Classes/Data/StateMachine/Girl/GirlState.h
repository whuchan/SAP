#pragma once
//==========================================
//
// File: GirlState.h
//
// Girl��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../StateMachine.h"


//==========================================
// �O���錾
//==========================================
class CPlayerCharacterGirl;

//==========================================
//
// Class: CGirlState
//
// �K�[�� ��� ���N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlState : public CStateBase
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	virtual ~CGirlState(void);

	/**
	*	@desc	�E�����ҋ@��Ԃֈڍs
	*/
	void toIdleRight(void);

	/**
	*	@desc	�������ҋ@��Ԃֈڍs
	*/
	void toIdleLeft(void);

	/**
	*	@desc	�E�������s��Ԃֈڍs
	*/
	void toWalkRight(void);

	/**
	*	@desc	���������s��Ԃֈڍs
	*/
	void toWalkLeft(void);

	/*
	*	@desc	�E�������͂ޏ�Ԃֈڍs
	*/
	void toGraspRight(void);

	/*
	*	@desc	���������͂ޏ�Ԃֈڍs
	*/
	void toGraspLeft(void);

	/*
	*	@desc	�E�������݂͂Ȃ���ҋ@��Ԃֈڍs
	*/
	void toGraspIdleRight(void);

	/*
	*	@desc	���������݂͂Ȃ���ҋ@��Ԃֈڍs
	*/
	void toGraspIdleLeft(void);

	/*
	*	@desc	�E�������݂͂Ȃ��������Ԃֈڍs
	*/
	void toGraspWalkRight(void);

	/*
	*	@desc	���������݂͂Ȃ��������Ԃֈڍs
	*/
	void toGraspWalkLeft(void);

	/**
	 * @desc	�E�������P�l��������Ԃֈڍs
	 */
	void toHoldRight(void);

	/**
	 * @desc	���������P�l��������Ԃֈڍs
	 */
	void toHoldLeft(void);

protected:
	CPlayerCharacterGirl* m_pGirl = NULL;
};


//==========================================
//
// Class: CGirlIdleRightState
//
// �K�[�� �E�����@�ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlIdleRightState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlIdleRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlIdleRightState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;
	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CGirlIdleLeftState
//
// �K�[�� �������@�ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlIdleLeftState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlIdleLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlIdleLeftState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;
	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CGirlGraspRightState
//
// �K�[�� �E�����@����Ȃ� �N���X
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CGirlGraspRightState :public CGirlState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CGirlGraspRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc �f�X�g���N�^
	*/
	~CGirlGraspRightState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CGirlGraspLeftState
//
// �K�[�� �������@����Ȃ� ��� �N���X
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CGirlGraspLeftState :public CGirlState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CGirlGraspLeftState(CPlayerCharacterGirl* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CGirlGraspLeftState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CGirlGraspIdleRightState
//
// �v���C���[ �E�����@����q���ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspIdleRightState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlGraspIdleRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlGraspIdleRightState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;

	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CGirlGraspIdleLeftState
//
// �v���C���[ �������@����q���ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspIdleLeftState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlGraspIdleLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlGraspIdleLeftState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;
	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};



//==========================================
//
// Class: CGirlGraspWalkRightState
//
// �v���C���[ �E�����@���s ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspWalkRightState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlGraspWalkRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlGraspWalkRightState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;

	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CGirlGraspWalkLeftState
//
// �v���C���[ �������@���s ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspWalkLeftState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlGraspWalkLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlGraspWalkLeftState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;
	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CGirlHoldIdleRightState
//
// �v���C���[ �E�����@���P�l�������ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlHoldIdleRightState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlHoldIdleRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlHoldIdleRightState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;

	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CGirlHoldIdleLeftState
//
// �v���C���[ �������@����q���ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlHoldIdleLeftState :public CGirlState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CGirlHoldIdleLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CGirlHoldIdleLeftState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void)override;
	/**
	* @desc	�X�V����
	*/
	void update(void)override;

	/**
	* @desc	��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void)override;

private:
};

//EOF