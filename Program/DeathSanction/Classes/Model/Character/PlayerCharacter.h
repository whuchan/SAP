#pragma once
#include "Character.h"

//===========================================================
//�v���C���[�L�����N�^�[
//�@����͍X�V�����������ōs����̂�
//�@���͏����������ōs���A
//�@���͂ɂ��ړ������Ƃ����J�e�S���ň���
//===========================================================
class CPlayerCharacter : public CCharacter
{
public:
	//=========================================================
	// �萔
	//=========================================================
	//�v���C���[�̏��
	enum class STATE :int
	{
		STAND = 0,
		JUMPING = 0,
		WALK = 1,
		HIT = 2,
		FALING = 3
	};

	//�v���C���[���s����A�N�V����
	enum class ACTION : int
	{
		JUMP = 0,				//�W�����v
		SHOT_NORMAL_BULLET = 1, //�ʏ�e����
		SHOT_CUSTOM_BULLET = 2, //�J�X�^���e����
		SHOT_FIREBALL_BULLET = 3,//�t�@�C�A�[�{�[���e����
	};


	//=========================================================
	// �֐�
	//=========================================================

	//�R���X�g���N�^
	CPlayerCharacter();
	//�f�X�g���N�^
	~CPlayerCharacter();

	//����������
	bool init()override;

	CREATE_FUNC(CPlayerCharacter);

	//�X�V����
	void update(float deltaTime)override;

	/**
	* @desc ���͏���
	* @tips �ړ������ŌĂяo��
	*/
	void inputFunc();

	//�ړ�����
	void moveFunc()override;
	//�A�j���[�V��������
	void animationFunc()override;
	//��ԂƂ̏Փ˔��菈��
	virtual void collision()override;
	//��ԃ`�F�b�N
	void checkState()override;
	//���f����
	void applyFunc()override;
	

	/**
	* @desc �L�����N�^�[�P�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override;
	
	/**
	* @desc �Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hits(CCharacter* pChara)override;


	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	void collisionBottomCallback(int event)
	{
		//�W�����v���~������
		(*this->m_pActions)[(int)ACTION::JUMP]->stop();
	}
};

