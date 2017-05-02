#pragma once
//==========================================
//
// File: PlayerStateGraps.h
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
//		�����Ǝ���q�������
//
// 2017/ 1/ 5
//						Author Harada
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../StateMachine.h"

//==========================================
// �O���錾
//==========================================
class CPlayerCharacterBoy;
class CGirlCharacter;

//==========================================
//
// Class: CPlayerStateHold
//
// �v���C���[ ���P�l�������@��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateHold : public CStateBase {
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerStateHold(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	virtual ~CPlayerStateHold(void);

	/**
	 * @desc	�ҋ@��Ԃֈڍs
	 */
	void toIdle(void);

	/**
	 * @desc	���s��Ԃֈڍs
	 */
	void toWalk(void);

	/**
	 * @desc	�W�����v��Ԃֈڍs
	 */
	void toJump(void);

	/**
	 * @desc	������Ԃֈڍs
	 */
	void toFall(void);

	/**
	 * @desc	���P�l��������Ԃ���ʏ��Ԃֈڍs
	 */
	void toFreeIdle(void);

protected:
	//�Q�Ƃ���v���C���[�L�����N�^�[
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//�Q�Ƃ���K�[���L�����N�^�[
	CGirlCharacter*		m_pGirl = NULL;
};



//==========================================
//
// Class: CPlayerHoldIdleState
//
// �v���C���[ ���P�l������ �ҋ@ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldIdleState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldIdleState(void);

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
// Class: CPlayerHoldWalkState
//
// �v���C���[ ���P�l������ ���s ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldWalkState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
 	 */
	~CPlayerHoldWalkState(void);

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
// Class: CPlayerHoldJumpState
//
// �v���C���[ ���P�l������ �W�����v ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldJumpState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldJumpState(void);

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

	//�W�����v����X�����x
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldFallState
//
// �v���C���[ ���P�l������ ���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldFallState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldFallState(void);

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
	//�W�����v����X�����x
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldReleaseState
//
// �v���C���[ ���P�l������ ���낷 ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldReleaseState :public CPlayerStateHold
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerHoldReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerHoldReleaseState(void);

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
	//�W�����v����X�����x
	float m_velX;
};
