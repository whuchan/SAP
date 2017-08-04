#pragma once

#include<stdio.h>
#include<memory>
#include"cocos2d.h"
#include"Constants.h"
#include"Data/LaunchData/LaunchData.h"

//=============================================
// �O���錾
//=============================================
class CCharacter;

//=============================================
//
// �o���g���K�[
//
//=============================================
class CLaunchTrigger
{
public:
	//�L���t���O false...�o���X�P�W���[��������O��
	bool m_activeFlag = false;

	//�R���X�g���N�^
	CLaunchTrigger()
	{
		this->m_activeFlag = true;
	}

	//�f�X�g���N�^
	virtual ~CLaunchTrigger()
	{
	
	}

	/**
	* @desc ���˂��I��������ǂ���
	* @return true...���˂��� false...���˂��Ă��Ȃ�
	* @tips	���˂��I��������ǂ����͔h���N���X�ɂ����
	*		�t���O���ω�����ꍇ�����݂���
	*/
	virtual bool isLaunched(void)
	{
		return this->m_activeFlag;
	}

	/**
	* @desc �ݒ肳��Ă���g���K�[���C�x���g���s���邩�ǂ���
	* @param true...�C�x���g�̎��s���\
	* @tips �C�x���g�̎��s�\�����͔h���N���X�ɂ���ĕω�����
	*/
	virtual bool isTrigger() = 0;

	/**
	* @desc �g���K�[�C�x���g�̎��s
	*		�����ł̃C�x���g�̓L�����N�^�[�̐���
	*/
	virtual CCharacter* action() = 0;
};

//=============================================
//
// �G�o���g���K�[
//�@�G�o���f�[�^���g���K�[�Ƃ��ēG�o���Ƃ����C�x���g�����s������
//
//=============================================
class CEnemyLaunchTrigger :public CLaunchTrigger
{
private:
	//�o���f�[�^
	CEnemyLaunchData* m_pLaunchData = NULL;

public:
	/**
	* @desc �R���X�g���N�^
	* @param �G�o���f�[�^
	* @tips �G�o���f�[�^���g���K�[�Ƃ��Đݒ肷��
	*/
	CEnemyLaunchTrigger(CEnemyLaunchData* pLaunchData)
		: m_pLaunchData(pLaunchData)
	{

	}

	//�f�X�g���N�^
	~CEnemyLaunchTrigger();


	/**
	* @desc �ݒ肳��Ă���g���K�[���C�x���g���s���邩�ǂ���
	* @param true...�C�x���g�̎��s���\
	* @tips �C�x���g�̎��s�\�����͔h���N���X�ɂ���ĕω�����
	*/
	bool isTrigger()override;

	/**
	* @desc �g���K�[�C�x���g�̎��s
	*		�����ł̃C�x���g�̓L�����N�^�[�̐���
	*/
	virtual CCharacter* action()override;

};

////=============================================
////
//// �M�~�b�N�o���g���K�[
////�@�M�~�b�N�o���f�[�^���g���K�[�Ƃ��ăM�~�b�N�o���Ƃ����C�x���g�����s������
////
////=============================================
//class CGimmickLaunchTrigger :public CLaunchTrigger
//{
//private:
//	//�o���f�[�^
//	CGimmickLaunchData* m_pLaunchData = NULL;
//
//public:
//	/**
//	* @desc �R���X�g���N�^
//	* @param �G�o���f�[�^
//	* @tips �G�o���f�[�^���g���K�[�Ƃ��Đݒ肷��
//	*/
//	CGimmickLaunchTrigger(CGimmickLaunchData* pLaunchData)
//		: m_pLaunchData(pLaunchData)
//	{
//
//	}
//
//	//�f�X�g���N�^
//	~CGimmickLaunchTrigger();
//
//
//	/**
//	* @desc �ݒ肳��Ă���g���K�[���C�x���g���s���邩�ǂ���
//	* @param true...�C�x���g�̎��s���\
//	* @tips �C�x���g�̎��s�\�����͔h���N���X�ɂ���ĕω�����
//	*/
//	bool isTrigger()override;
//
//	/**
//	* @desc �g���K�[�C�x���g�̎��s
//	*		�����ł̃C�x���g�̓L�����N�^�[�̐���
//	*/
//	virtual CCharacter* action()override;
//
//};



////=============================================
////
//// �e�o���g���K�[
////�@�e�o���f�[�^���g���K�[�Ƃ��Ēe�o���Ƃ����C�x���g�����s������
////
////=============================================
//
//class CBulletLaunchTrigger :public CLaunchTrigger
//{
//private:
//	//�o���f�[�^
//	CBulletLaunchData* m_pLaunchData = NULL;
//
//public:
//	/**
//	* @desc �R���X�g���N�^
//	* @param �G�o���f�[�^
//	* @tips �G�o���f�[�^���g���K�[�Ƃ��Đݒ肷��
//	*/
//
//	CBulletLaunchTrigger(CBulletLaunchData* pLaunchData);
//
//	//�f�X�g���N�^
//	~CBulletLaunchTrigger();
//
//
//	/**
//	* @desc �ݒ肳��Ă���g���K�[���C�x���g���s���邩�ǂ���
//	* @param true...�C�x���g�̎��s���\
//	* @tips �C�x���g�̎��s�\�����͔h���N���X�ɂ���ĕω�����
//	*/
//	bool isTrigger()override;
//
//	/**
//	* @desc �g���K�[�C�x���g�̎��s
//	*		�����ł̃C�x���g�̓L�����N�^�[�̐���
//	*/
//	virtual CCharacter* action()override;
//
//};


//=============================================
//
// ���ˑ�
//�@�o���X�P�W���[���̎Q�Ƃ�ݒ肵��
//�@�o���X�P�W���[���Ɏ��t����Ă���o���g���K�[�̏��Ԓʂ��
//	�C�x���g�����s���Ă���
//�@�܂���t����ꂽ���Ԓʂ�ɏo�����s���Ă���
//
//=============================================
class CLauncher
{
public:
	//�o���X�P�W���[���̎Q��(�܂肱�̃N���X�Ő�����j�����s��Ȃ�)
	//�P�t���[���ɏo��������g���K�[�C�x���g�̏W�܂�
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;

	/**
	* @desc �R���X�g���N�^
	* @param �o���X�P�W���[���̃A�h���X
	*/
	CLauncher(std::vector<CLaunchTrigger*>*pLaunchSchedule)
		:m_pLaunchSchedule(pLaunchSchedule)
	{

	}

	//�f�X�g���N�^
	virtual ~CLauncher()
	{

	}

	/**
	* @desc �o���g���K�[���o���X�P�W���[���ɒǉ�����
	*/
	void add(CLaunchTrigger* pTrigger)
	{
		this->m_pLaunchSchedule->push_back(pTrigger);
	}

	/**
	* @desc �o���X�P�W���[���̃T�C�Y�̎擾
	*/
	int getSize(void)
	{
		return (int)this->m_pLaunchSchedule->size();
	}

	/**
	* @desc �o���g���K�[�̎擾
	* @param�@�Y���ԍ�
	*/
	CLaunchTrigger* getAt(int index)
	{
		//�ő�v�f���ȏ�̍ۂ�NULL��Ԃ�
		if (this->getSize() <= index)
		{
			return NULL;
		}

		return (*this->m_pLaunchSchedule)[index];
	}

	//=============================================
	//
	// �o���g���K�[�C�e���[�^�[
	//	���ˑ�Ɏ��t�����Ă���g���K�[�𔭎ˉ\�����ׂ�
	//�@���ˉ\�Ȃ�P�Âo��������ׂ̑�����s���N���X
	// Aggregate�̒��Ɏ���
	// Iterator
	//
	//=============================================
	class CLaunchTriggerItarator
	{
	public:
		//���ˑ�
		CLauncher* m_pLauncher = NULL;

		//���ݎQ�ƒ��̔ԍ�
		int m_triggerCount = 0;

		//�R���X�g���N�^
		CLaunchTriggerItarator(CLauncher* pLauncher)
			: m_pLauncher(pLauncher)
		{

		}

		/**
		* @desc �o���g���K�[�̎������邩�ǂ����𒲂ׂ�
		*		�������͏o���g���K�[���N���\���ǂ����𒲂ׂ�
		*/
		bool hasNext()
		{
			//�g���K�[�C�x���g�̏W�܂�̃T�C�Y�𒲂ׂ�
			if (this->m_pLauncher->getSize() <= this->m_triggerCount)
			{
				return false;
			}

			//�o���g���K�[���N���\���ǂ����𒲂ׂ�
			if (this->m_pLauncher->getAt(this->m_triggerCount)->isTrigger() == false)
			{
				//�N���\�Ŗ����ꍇ�͓Y���ԍ������ɐi�߂�
				this->m_triggerCount++;
				//�����`�F�b�N
				return this->hasNext();
			}
			return true;
		}
	

		/**
		* @desc ���݂̏o���g���K�[���擾���Y���ԍ������ɂ����߂�
		*/
		CLaunchTrigger* next()
		{
			CLaunchTrigger* pTrrigger = this->m_pLauncher->getAt(this->m_triggerCount);
			this->m_triggerCount++;
			return pTrrigger;
		}

	};
		
	
	/**
	* @desc�@�o���g���K�[�C�e���[�^�[�̐���
	* @param �o���g���K�[�C�e���[�^�[
	*/
	std::shared_ptr<CLaunchTriggerItarator>iterator()
	{
			return std::shared_ptr<CLaunchTriggerItarator>(new CLaunchTriggerItarator(this));
	}
};

//=============================================
//
// �o���X�P�W���[���[
// Singleton
//
//=============================================
class CLaunchScheduler
{
	//=========================================
	// ��������Singleton�ݒ�
	//=========================================

private:
	//���L�C���X�^���X
	static CLaunchScheduler* m_pSharedSchedular;

	//�R���X�g���N�^
	CLaunchScheduler();

public:
	//���L�C���X�^���X�̎擾
	static CLaunchScheduler* getInstance();

	//���L�C���X�^���X�̔j��
	static void removeInstance();

	//�f�X�g���N�^
	~CLaunchScheduler();

	//=========================================
	// �����܂ł�Singleton�ݒ�
	//=========================================

public:
	//���ˑ�
	CLauncher* m_pLauncher = NULL;

	/**
	* @desc ���ˑ�̐���
	* @param ���ˑ�ɐݒ肷��o���X�P�W���[���̃A�h���X
	*/
	void createLaunch(std::vector<CLaunchTrigger*>* pLaunchSchedule);

	/**
	* @desc �L�����N�^�[�̏o��
	* @param ���t���郌�C���[
	*/
	void launchCharacters(cocos2d::Layer* pLayer);
};

