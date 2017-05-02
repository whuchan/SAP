#pragma once
//==========================================
//
// File: PlayerState.h
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
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
class CPlayerCharacterBoy;
class CGirlCharacter;

//==========================================
//
// Class: CPlayerState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerState : public CStateBase
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	virtual ~CPlayerState(void);

	/**
	 *	@desc	�ҋ@��Ԃֈڍs
	 */
	void toIdle(void);

	/**
	 *	@desc	���s��Ԃֈڍs
	 */
	void toWalk(void);


	/**
	 *	@desc	�W�����v��Ԃֈڍs
	 */
	void toJump(void);

	/**
 	 *	@desc	������Ԃֈڍs
	 */
	void toFall(void);

	/**
	 * @desc	�U����Ԃֈڍs
	 */
	void toAttack(void);

	/**
	 * @desc	�W�����v�U���ֈڍs
	 */
	void toJumpAttack(void);

	/**
	 * @desc	�U�����󂯂���Ԃֈڍs
	 */
	void toUnderAttack(void);

	/*
	 *	@desc	���͂ޏ�Ԃֈڍs
	 */
	void toGrasp(void);

	/*
	 *	@desc	���P�l��������Ԃֈڍs
	 */
	void toHold(void);

protected:
	//�Q�Ƃ���v���C���[�L�����N�^�[
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//�Q�Ƃ���K�[���L�����N�^�[
	CGirlCharacter*		m_pGirl = NULL;
};

//==========================================
//
// Class: CPlayerIdleState
//
// �v���C���[ �ҋ@ ��ԃN���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerIdleState :public CPlayerState
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerIdleState(void);

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
// Class: CPlayerWalkState
//
// �v���C���[ ���s ��ԃN���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerWalkState :public CPlayerState
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerWalkState(void);

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
// Class: CPlayerJumpState
//
// �v���C���[ �W�����v ��ԃN���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerJumpState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerJumpState(void);

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

	//�W�����v����X�����x
	float m_velX;

private:
};

//==========================================
//
// Class: CPlayerFallState
//
// �v���C���[ ���� ��ԃN���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerFallState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerFallState(void);

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

	//�W�����v����X�����x
	float m_velX;

private:
};


//==========================================
//
// Class: CPlayerAttackState
//
// �v���C���[ �U�� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerAttackState :public CPlayerState
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerAttackState(void);

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
	//�A���t���O
	bool m_chainAttackFlag = false;

};

//==========================================
//
// Class: CPlayerJumpAttackState
//
// �v���C���[ �W�����v�U�� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerJumpAttackState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerJumpAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerJumpAttackState(void);

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

};


//==========================================
//
// Class: CPlayerUnderAttackState
//
// �v���C���[ �U�����󂯂� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerUnderAttackState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerUnderAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerUnderAttackState(void);

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

};

//==========================================
//
// Class: CPlayerGraspState
//
// �v���C���[ ����Ȃ� ��ԃN���X
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CPlayerGraspState :public CPlayerState
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerGraspState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerGraspState(void);

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
// Class: CPlayerHoldState
//
// �v���C���[ ���P�l������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldState :public CPlayerState
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldState(void);

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