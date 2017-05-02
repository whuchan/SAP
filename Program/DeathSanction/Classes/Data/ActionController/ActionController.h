#pragma once
#include"cocos2d.h"
#include"Constants.h"

//=======================================================
// �O���錾
//=======================================================
class CCharacter;
class CFactory;

//=======================================================
// �A�N�V�����N���X
//=======================================================
class CAction
{
public:
	//�f�X�g���N�^
	virtual ~CAction()
	{

	}
	//�A�N�V�������J�n����ۂɌĂяo��
	virtual void start() = 0;
	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) = 0;
	//�A�N�V�������I������ۂɌĂяo��
	virtual void stop() = 0;

	/**
	* @desc �A�N�V�����̍ċN��
	* @param �ċN������L�����N�^�[
	* @tips �W���G�ȃA�N�V�����̍ċN��
	* �����ł̓L�����N�^�[�͎g�p���Ȃ�
	*/
	virtual void restart(CCharacter* pChara)
	{
		//�A�N�V�����̒�~
		this->stop();

		//�A�N�V�����̊J�n
		this->start();
	}

};

//=======================================================
//�@�����ړ��A�N�V����
//=======================================================
class CActionMoveStraight : public CAction
{
private:
	//�A�N�V���������ǂ����̃t���O true...�A�N�V������
	bool m_inAction = false;

public:

	/**
	* @desc �R���X�g���N�^
	*/
	CActionMoveStraight();



	/**
	* @desc �A�N�V�����J�n
	*/
	void start(void)override;

	/**
	* @desc �X�V����
	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc �A�N�V�����I��
	*/
	void stop(void)override;
};

//=======================================================
//�@�e���˃A�N�V����
//=======================================================
//class CActionShotBullet : public CAction
//{
//private:
//	//�A�N�V���������ǂ����̃t���O true...�A�N�V������
//	bool m_inAction = false;
//
//	//�e���˃C���^�[�o��
//	int m_interval = 0;
//
//	//�e���˃J�E���^�[
//	int m_counter = 0;
//
//	//�e�^�C�v
//	int m_type;
//
//public:
//
//	/**
//	* @desc �R���X�g���N�^
//	* @param �e�^�C�v
//	* @param �e���ˊԊu
//	*/
//	CActionShotBullet(int type, int interval);
//
//	/**
//	* @desc �A�N�V�����J�n
//	*/
//	void start(void)override;
//
//	/**
//	* @desc �X�V����
//	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
//	*/
//	void update(CCharacter* pChara)override;
//
//	/**
//	* @desc �A�N�V�����I��
//	*/
//	void stop(void)override;
//};


//=======================================================
// �W�����v
// �W�����v�Ɋւ��鏈�����s�����������Ƃ��Ĉړ��f�[�^�ɑ΂��ĕύX��������
//	tips:
//  cocos2dx��Action�N���X�ɂ��W�����v�͑��݂��邪
//  Action�N���X�Ɉˑ����Ă���̂ŏd�͂▀�C��}�b�v�`�b�v�Ȃǂ̉e�����l����Ə��߂̂����͕������čl���������������₷��
//=======================================================
class CActionJump : public CAction
{
public:
	//�W�����v�����␳�l
	float m_floatCorrectionValue = 0.0f;


protected:
	//�W�����v�����x
	float m_accele = 0.0f;

	
	//�W�����v�u�[�X�g
	int m_boost = 0;
	//���݂̃W�����v�u�[�X�g
	int m_currentBoost = 0;
	//�W�����v�����ǂ����̃t���O true...�W�����v��
	bool m_isJumping = false;

	//�W�����v�J�n�t���O
	bool m_isJumpStart = false;
public:
	//�R���X�g���N�^
	CActionJump(float accele,int boost):
		m_accele(accele),m_boost(boost)
	{

		this->start();
	}

	/**
	* @desc �W�����v����
	* @param �����x
	* @param �W�����v�u�[�X�g
	* @tips�@�W�����v�{�^���������ꂽ�ۂɒl�̐ݒ�Ƌ��ɌĂяo��
	*/
	void start()override
	{
		//�W�����v�J�n
		this->m_isJumpStart = true;
	}

	/**
	* @desc �X�V����(�W�����v�ړ��v�Z)
	* @param �W�����v����Ώۂ̃L�����N�^�[
	* @tips	 ��L�[�������ꂽ�炱�̊֐����Ăяo��
	*/
	void update(CCharacter* pChara);

	/**
	* @desc �W�����v�I��
	* @tips ���n�����ۂɂ��̊֐����Ăяo��
	*/
	void stop()override
	{
		//�W�����v���t���O�����낷
		this->m_isJumping = false;
	}

	/**
	* @desc �A�N�V�����̍ċN��
	* @param �ċN������L�����N�^�[
	* @tips �W���G�ȃA�N�V�����̍ċN��
	* �����ł̓L�����N�^�[�͎g�p���Ȃ�
	*/
	virtual void restart(CCharacter* pChara)override;
	
};

//=======================================================
//�@�G���S�A�N�V����
//=======================================================
class CActionEnemyDead : public CAction
{
protected:
	//���ړ����x
	float m_velX = 0.0f;

	//�͂˂鑬�x
	float m_leapVelY = 0.0f;

	//�A�N�V���������ǂ����̃t���Otrue...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�����J�n�t���Otrue...�A�N�V�����J�n
	bool m_isStart = false;

public:
	/**
	* @desc �R���X�g���N�^
	* @param ���ړ����x
	* @param �͂˂鑬�x
	*/
	CActionEnemyDead(float velX, float leapVelY);

	/**
	* @desc �A�N�V�����J�n
	*/
	void start()override;

	/**
	* @desc �X�V����
	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc �A�N�V�����I��
	*/
	void stop()override;
};


//=======================================================
//�@�d�͉��Z�������ēG���S�A�N�V�������s��
//=======================================================
class CActionEnemyDeadAndAddGravity : public CAction
{
protected:
	//���ړ����x
	float m_velX = 0.0f;

	//�͂˂鑬�x
	float m_leapVelY = 0.0f;

	//�A�N�V���������ǂ����̃t���Otrue...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�����J�n�t���Otrue...�A�N�V�����J�n
	bool m_isStart = false;

public:
	/**
	* @desc �R���X�g���N�^
	* @param ���ړ����x
	* @param �͂˂鑬�x
	*/
	CActionEnemyDeadAndAddGravity(float velX, float leapVelY);

	/**
	* @desc �A�N�V�����J�n
	*/
	void start()override;

	/**
	* @desc �X�V����
	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc �A�N�V�����I��
	*/
	void stop()override;
};


//=======================================================
//�@�G���S�A�N�V������Ɏ��S�ʒu����G���o��������
//=======================================================
class CActionEnemyDeadAndCreateEnemy : public CAction
{
protected:
	//{ ENEMY_TYPE }�o��������G�̃^�C�v
	int m_type;

	//�A�N�V���������ǂ����̃t���Otrue...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�����J�n�t���Otrue...�A�N�V�����J�n
	bool m_isStart = false;

public:
	/**
	* @desc �R���X�g���N�^
	* @param �o��������G�̃^�C�v
	*/
	CActionEnemyDeadAndCreateEnemy( int type );

	/**
	* @desc �A�N�V�����J�n
	*/
	void start()override;

	/**
	* @desc �X�V����
	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc �A�N�V�����I��
	*/
	void stop()override;
};

//=======================================================
//�@�㉺�ړ��A�N�V����
//=======================================================
class CActionUpAndDownMove : public CAction
{
private:
	//�A�N�V���������ǂ����̃t���O true...�A�N�V������
	bool m_inAction = false;

	//��ʒu
	cocos2d::Point m_basePos;

	//���a
	float m_radius = 0.0f;

	//���x
	float m_vel = 0.0f;

	//�J�E���^�[
	float m_counter = 0.0f;

public:
	/**
	* @desc �R���X�g���N�^
	* @param ��ʒu
	* @param ���a
	* @param ���x
	*/
	CActionUpAndDownMove(cocos2d::Point basePos, float radius,float vel);

	/**
	* @desc �A�N�V�����J�n
	*/
	void start(void)override;

	/**
	* @desc �X�V����
	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc �A�N�V�����I��
	*/
	void stop(void)override;
};



//=======================================================
//�@����I�ɓG���o��������
//=======================================================
class CActionIntervalCreateEnemy : public CAction
{
protected:
	//{ ENEMY_TYPE }�o��������G�̃^�C�v
	int m_type;

	//�A�N�V���������ǂ����̃t���Otrue...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�����J�n�t���Otrue...�A�N�V�����J�n
	bool m_isStart = false;

	//�o���Ԋu
	int m_interval = 0;

	//�o���J�E���^�[
	int m_counter = 0;

	//�o��������C���ʒu
	cocos2d::Point m_launchFixPos = cocos2d::Point(0.0f, 0.0f);


public:
	/**
	* @desc �R���X�g���N�^
	* @param �o��������L�����N�^�[�̐����H��
	* @param �o���Ԋu
	* @param �o��������ʒu
	*/
	CActionIntervalCreateEnemy(int type,int interval,cocos2d::Point launchPos = cocos2d::Point(0.0f,0.0f));

	/**
	* @desc �A�N�V�����J�n
	*/
	void start()override;

	/**
	* @desc �X�V����
	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc �A�N�V�����I��
	*/
	void stop()override;
};
