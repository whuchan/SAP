#pragma once
//==========================================
//
// File: PlayerStateGraps.h
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
//		�����Ǝ���q�������
//
// 2017/ 1/ 1
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
// Class: CPlayerState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateGraps : public CStateBase {
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerStateGraps(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	virtual ~CPlayerStateGraps(void);

	/**
	 *	@desc	�ҋ@��Ԃֈڍs
	 */
	void toIdle(void);

	/**
	 *	@desc	���s��Ԃֈڍs
	 */
	void toWalk(void);

	/**
	 * @desc	�U����Ԃֈڍs
	 */
	void toAttack(void);

	/*
	 *	@desc	��𗣂�����Ԃֈڍs
	 */
	void toGrasp(void);

protected:
	//�Q�Ƃ���v���C���[�L�����N�^�[
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//�Q�Ƃ���K�[���L�����N�^�[
	CGirlCharacter*		m_pGirl = NULL;
};




//==========================================
//
// Class: CPlayerGraspIdleState
//
// �v���C���[ ����q�� �ҋ@ ��ԃN���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CPlayerGraspIdleState :public CPlayerStateGraps
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspIdleState(void);

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
// Class: CPlayerGraspWalkState
//
// �v���C���[ ����q�� ���s ��ԃN���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerGraspWalkState :public CPlayerStateGraps
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspWalkState(void);

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
// Class: CPlayerGraspAttackState
//
// �v���C���[ ����q�� �U�� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerGraspAttackState :public CPlayerStateGraps
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspAttackState(void);

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
// Class: CPlayerGraspReleaseState
//
// �v���C���[ ����q�� ��𗣂� ��ԃN���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerGraspReleaseState :public CPlayerStateGraps
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspReleaseState(void);

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
