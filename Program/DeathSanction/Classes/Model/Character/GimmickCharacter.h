#pragma once
#include "Character.h"


//================================================================
// �����^�C�v
//================================================================
enum DIRECTION_TYPE : int
{
	LEFT	= 0,	//��
	UP		= 1,	//��
	RIGHT	= 2,	//�E
	DOWN	= 3,	//��
};


//======================================================
//
// �M�~�b�N�L�����N�^�[�̊��N���X�ƂȂ�N���X
//
//======================================================
class CGimmickCharacter : public CCharacter
{
public:
	//�R���X�g���N�^
	CGimmickCharacter();

	//�f�X�g���N�^
	virtual ~CGimmickCharacter();

	//����������
	virtual bool init()override;

	/**
	* @desc�@����������
	* @param �����ʒuX
	* @param �����ʒuY
	* @tips create()�����o�֐��̒���init()�����o�֐����Ăяo���Ă��邪
	* ����A����create()�����o�֐����I�[�o�[���[�h����
	* �������󂯎���Ă���̂�init()�����o�֐���
	* �I�[�o�[���[�h����K�v������
	*/
	virtual bool init(float posX, float posY);

	
	//�ړ�����
	void moveFunction(float deltaTime)override;

	//�A�j���[�V��������
	void animationFunction(float deltaTime)override;

	//��ԂƂ̏Փ˔��菈��
	virtual void collision()override;

	//��ԃ`�F�b�N
	virtual void checkState(float deltaTime)override;

	//���f����
	void applayFunction()override;



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
	void hits(CCharacter* pChara)override;


	
protected:

	/**
	* @desc �v���C���[�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara);

	/**
	* @desc �G�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsEnemyCharacter(CCharacter* pChara) = 0;

};