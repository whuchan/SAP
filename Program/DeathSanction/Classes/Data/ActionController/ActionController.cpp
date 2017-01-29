#include "ActionController.h"
#include "Model\Character\Character.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"
#include "Model\Character\Factory\EnemyFactory.h"
#include"Model\Character\BulletCharacter.h"



//=======================================================
//�@�����ړ��A�N�V����
//=======================================================
/**
* @desc �R���X�g���N�^
*/
CActionMoveStraight::CActionMoveStraight()
{
	//�����Ɠ����ɊJ�n
	this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionMoveStraight::start(void)
{
	//�A�N�V�����J�n
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionMoveStraight::update(CCharacter* pChara)
{
	if (this->m_inAction!=false)
	{
		pChara->m_pMove->m_vel.x = pChara->m_pMove->m_speed * pChara->m_shotLaunchVector.x;
		pChara->m_pMove->m_vel.y = pChara->m_pMove->m_speed * pChara->m_shotLaunchVector.y;
	}
	this->stop();
}

/**
* @desc �A�N�V�����I��
*/
void CActionMoveStraight::stop(void)
{


	//�A�N�V�����I��
	this->m_inAction = false;
}



//=======================================================
//�@�e���˂P�A�N�V����
//=======================================================
/**
* @desc �R���X�g���N�^
* @param �e�^�C�v
* @param �e���ˊԊu
*/
CActionShotBullet::CActionShotBullet(int type, int interval)
{
	//�e�^�C�v
	this->m_type = type;
	//�e���ˊԊu
	this->m_interval = interval;
}

/**
* @desc �A�N�V�����J�n
*/
void CActionShotBullet::start(void)
{
	//�A�N�V�����J�n
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionShotBullet::update(CCharacter* pChara)
{

	

	if (this->m_inAction != false)
	{
		if(this->m_counter > 0 )
		{
			this->m_counter--;

			if (this->m_counter <= 0)
			{
				this->stop();
			}
		}
		else
		{
			//�G�o���f�[�^�i�o���̏��j�̐���
			CBulletLaunchData* pLaunchData = new CBulletLaunchData((BULLET_TYPE)this->m_type, pChara->m_pMove->m_pos, pChara->m_shotLaunchVector);

			//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
			CBulletLaunchTrigger* pTrigger = new CBulletLaunchTrigger(pLaunchData);

			//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
			CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

			//�J�E���^�[�����Z�b�g
			this->m_counter = this->m_interval;
		}
	}
}

/**
* @desc �A�N�V�����I��
*/
void CActionShotBullet::stop(void)
{
	//�A�N�V�����I��
	this->m_inAction = false;
}


//=======================================================
//�@�W�����v�ړ��A�N�V����
//=======================================================
/**
* @desc �X�V�����i�W�����v�ړ��v�Z�j
* @param �W�����v����Ώۂ̃L�����N�^�[
* @tips ��L�[�������ꂽ�炱�̊֐����Ăяo��
*/
void CActionJump::update(CCharacter* pChara)
{
	if (this->m_isJumping == true)
	{
		//�W�����v��

		
		
		//�W�����v�u�[�X�g�����炵�Ă���
		this->m_currentBoost--;

		//�W�����v�u�[�X�g���O��菬�����ꍇ
		if ((this->m_isJumpStart == false) || (this->m_currentBoost < 0))
		{
			//�����x���O�ɂ���
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
	else if (this->m_isJumpStart == true)
	{
		//�W�����v�J�n

		//�����̉����x�ɒl��ݒ�
		pChara->m_pMove->m_accele.y = this->m_floatCorrectionValue + this->m_accele;


		this->m_floatCorrectionValue = 0.0f;

		//���t���[���A�����x��K�p�����邩��ݒ�
		this->m_currentBoost = this->m_boost;
		//�W�����v�t���O��true�ɂ���
		this->m_isJumping = true;
	}

	

	//�W�����v�J�n�t���O��������
	this->m_isJumpStart = false;
}

/**
* @desc �A�N�V�����̍ċN��
* @param �ċN������L�����N�^�[
* @tips �W���G�ȃA�N�V�����̍ċN��
* �����ł̓L�����N�^�[�͎g�p���Ȃ�
*/
void CActionJump::restart(CCharacter* pChara)
{
	//Y�����̑��x�Ɖ����x�̃��Z�b�g
	pChara->m_pMove->m_vel.y = 0.0f;
	pChara->m_pMove->m_accele.y = 0.0f;

	//�A�N�V�����̒�~
	this->stop();

	//�A�N�V�����̊J�n
	this->start();
}


//=======================================================
//�@�G���S�A�N�V����
//=======================================================
/**
* @desc �R���X�g���N�^
* @param ���ړ����x
* @param �͂˂鑬�x
*/
CActionEnemyDead::CActionEnemyDead(float velX, float leapVelY) :m_velX(velX), m_leapVelY(leapVelY)
{
	//�R���X�g���N�^�̕����ŃA�N�V�����̊J�n���s��
	//this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionEnemyDead::start()
{
	//�A�N�V�����J�n
	this->m_isStart = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionEnemyDead::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//�A�N�V������

		//��ʂ̊O�ɏo����
		if (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_top < WINDOW_BOTTOM)
		{
			//�A�N�V�������~
			this->stop();

			//�L���t���O��������
			pChara->m_activeFlag = false;
		}
	}
	else if (this->m_isStart == true)
	{
		//�A�N�V�����J�n

		//�A�N�V�������̃t���O�𗧂Ă�
		this->m_inAction = true;

		//�͂˂鑬�x�Ɖ��ړ����x��ݒ肷��
		pChara->m_pMove->m_vel.set(this->m_velX,this->m_leapVelY);

		//�A�N�V�����J�n�t���O�͉�����
		this->m_isStart = false;
	}
}

/**
* @desc �A�N�V�����I��
*/
void CActionEnemyDead::stop()
{
	//�A�N�V�������t���O�����낷
	this->m_inAction = false;
}



//=======================================================
//�@�G���S�A�N�V����
//=======================================================
/**
* @desc �R���X�g���N�^
* @param ���ړ����x
* @param �͂˂鑬�x
*/
CActionEnemyDeadAndAddGravity::CActionEnemyDeadAndAddGravity(float velX, float leapVelY) :m_velX(velX), m_leapVelY(leapVelY)
{
	//�R���X�g���N�^�̕����ŃA�N�V�����̊J�n���s��
	//this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionEnemyDeadAndAddGravity::start()
{
	//�A�N�V�����J�n
	this->m_isStart = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionEnemyDeadAndAddGravity::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//�A�N�V������

		//��ʂ̊O�ɏo����
		if (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_top < WINDOW_BOTTOM)
		{
			//�A�N�V�������~
			this->stop();

			//�L���t���O��������
			pChara->m_activeFlag = false;
		}
	}
	else if (this->m_isStart == true)
	{
		//�A�N�V�����J�n


		//�A�N�V�������̃t���O�𗧂Ă�
		this->m_inAction = true;

		//�͂˂鑬�x�Ɖ��ړ����x��ݒ肷��
		pChara->m_pMove->m_vel.set(this->m_velX, this->m_leapVelY);

		//�A�N�V�����J�n�t���O�͉�����
		this->m_isStart = false;
	}
}

/**
* @desc �A�N�V�����I��
*/
void CActionEnemyDeadAndAddGravity::stop()
{
	//�A�N�V�������t���O�����낷
	this->m_inAction = false;
}



/**
* @desc �R���X�g���N�^
* @param �o��������G�̃^�C�v
*/
CActionEnemyDeadAndCreateEnemy::CActionEnemyDeadAndCreateEnemy(int type)
	:m_type(type)
{

}

/**
* @desc �A�N�V�����J�n
*/
void CActionEnemyDeadAndCreateEnemy::start()
{
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionEnemyDeadAndCreateEnemy::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//�L���t���O�����낷
		pChara->m_activeFlag = false;

		//�\���ɂ���
		pChara->setVisible(false);

		//==================================
		// �����ł͏o���̏����o���g���K�[�Ƃ���
		// �o���X�P�W���[���[�Ɏ��t���邾��
		//==================================
		//�G�o���f�[�^�i�o���̏��j�̐���
		CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
			(ENEMY_TYPE)this->m_type,
			pChara->m_pMove->m_pos
		);

		//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
		CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

		//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
		CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

		
		//�A�N�V�������t���O�����낷
		this->m_inAction = false;
	}
}

/**
* @desc �A�N�V�����I��
*/
void CActionEnemyDeadAndCreateEnemy::stop()
{
	this->m_inAction = false;
}

//=======================================================
//�@�㉺�ړ��A�N�V����
//=======================================================
/**
* @desc �R���X�g���N�^
* @param ��ʒu
* @param ���a
* @param ���x
*/
CActionUpAndDownMove::CActionUpAndDownMove(cocos2d::Point basePos, float radius, float vel)
	:m_basePos(basePos),m_radius(radius),m_vel(vel)
{
	this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionUpAndDownMove::start(void)
{
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionUpAndDownMove::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//X�ʒu�͊�_�̂܂�
		pChara->m_pMove->m_pos.x = this->m_basePos.x;
		//Y�ʒu��sin�J�[�u�^��
		pChara->m_pMove->m_pos.y = sinf(this->m_counter)*this->m_radius + this->m_basePos.y;

		//�J�E���^�[�𑬓x���X�V
		this->m_counter += this->m_vel;
	}
}

/**
* @desc �A�N�V�����I��
*/
void CActionUpAndDownMove::stop(void)
{
	this->m_inAction = false;
}


//=======================================================
//�@����I�ɓG���o��������
//=======================================================


/**
* @desc �R���X�g���N�^
* @param �o��������G�̃^�C�v
* @param �o���Ԋu
* @param �o��������C���ʒu
*/
CActionIntervalCreateEnemy::CActionIntervalCreateEnemy(int type,int interval, cocos2d::Point launchPos)
	:m_type(type),m_interval(interval),m_launchFixPos(launchPos)
{
	this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionIntervalCreateEnemy::start()
{
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionIntervalCreateEnemy::update(CCharacter* pChara)
{
	if (this->m_inAction == true)
	{
		//�J�E���^�[���X�V
		this->m_counter++;
		if (this->m_counter >= this->m_interval)
		{

			//==================================
			// �����ł͏o���̏����o���g���K�[�Ƃ���
			// �o���X�P�W���[���[�Ɏ��t���邾��
			//==================================
			//�G�o���f�[�^�i�o���̏��j�̐���
			CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
				(ENEMY_TYPE)this->m_type,
				pChara->m_pMove->m_pos + this->m_launchFixPos
			);

			//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
			CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

			//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
			CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

			this->m_counter = 0;
		}
	}
}

/**
* @desc �A�N�V�����I��
*/
void CActionIntervalCreateEnemy::stop()
{
	this->m_inAction = false;
}



