#include"LaunchTrigger.h"
#include"Model\Character\Character.h"
#include "Model\Character\Factory\EnemyFactory.h"
#include "Model\Character\Factory\BulletFactory.h"
#include "Model\Character\Factory\GimmickFactory.h"


//=============================================================
//
// �G�o���g���K�[
// �G�o���f�[�^���g���K�[�ɂ��ēG�o���Ƃ����C�x���g�����s������
//
//=============================================================
//�f�X�g���N�^
CEnemyLaunchTrigger::~CEnemyLaunchTrigger()
{
	SAFE_DELETE(this->m_pLaunchData);
}

/**
* @desc �C�x���g�����s�ł��邩�ǂ���
* @return true...���s�\
*/
bool CEnemyLaunchTrigger::isTrigger()
{
	if (this->m_pLaunchData == NULL)
	{
		return false;
	}
	return true;
}

/**
* @desc �ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
*/
CCharacter* CEnemyLaunchTrigger::action()
{
	//�G�𐶐�
	CCharacter* pEnemyChara = CEnemyFactoryManager::getInstance()->create(
		this->m_pLaunchData->m_type,
		this->m_pLaunchData->m_pos.x,
		this->m_pLaunchData->m_pos.y);

	//���˂��I��������ǂ����̃t���O�𗧂Ă�
	this->m_activeFlag = false;

	return pEnemyChara;
}


////=============================================================
////
//// �M�~�b�N�o���g���K�[
//// �M�~�b�N�o���f�[�^���g���K�[�ɂ��ēG�o���Ƃ����C�x���g�����s������
////
////=============================================================
////�f�X�g���N�^
//CGimmickLaunchTrigger::~CGimmickLaunchTrigger()
//{
//	SAFE_DELETE(this->m_pLaunchData);
//}
//
///**
//* @desc �C�x���g�����s�ł��邩�ǂ���
//* @return true...���s�\
//*/
//bool CGimmickLaunchTrigger::isTrigger()
//{
//	if (this->m_pLaunchData == NULL)
//	{
//		return false;
//	}
//	return true;
//}
//
///**
//* @desc �ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
//*/
//CCharacter* CGimmickLaunchTrigger::action()
//{
//	//�G�𐶐�
//	CCharacter* pGimmickChara = CGimmickFactoryManager::getInstance()->create(
//		this->m_pLaunchData->m_type,
//		this->m_pLaunchData->m_pos.x,
//		this->m_pLaunchData->m_pos.y);
//
//	//���˂��I��������ǂ����̃t���O�𗧂Ă�
//	this->m_activeFlag = false;
//
//	return pGimmickChara;
//}
//
//
//
////=============================================
////
//// �e�o���g���K�[
////�@�e�o���f�[�^���g���K�[�Ƃ��Ēe�o���Ƃ����C�x���g�����s������
////
////=============================================
//
///**
//* @desc �R���X�g���N�^
//* @param �G�o���f�[�^
//* @tips �G�o���f�[�^���g���K�[�Ƃ��Đݒ肷��
//*/
//CBulletLaunchTrigger::CBulletLaunchTrigger(CBulletLaunchData* pLaunchData)
//	: m_pLaunchData(pLaunchData)
//{
//
//}
//
////�f�X�g���N�^
//CBulletLaunchTrigger::~CBulletLaunchTrigger()
//{
//
//	SAFE_DELETE(this->m_pLaunchData);
//}
//
//
///**
//* @desc �ݒ肳��Ă���g���K�[���C�x���g���s���邩�ǂ���
//* @param true...�C�x���g�̎��s���\
//* @tips �C�x���g�̎��s�\�����͔h���N���X�ɂ���ĕω�����
//*/
//
//
//bool CBulletLaunchTrigger::isTrigger()
//{
//	if (this->m_pLaunchData == NULL)
//	{
//		return false;
//	}
//	return true;
//}
//
///**
//* @desc �g���K�[�C�x���g�̎��s
//*		�����ł̃C�x���g�̓L�����N�^�[�̐���
//*/
//CCharacter* CBulletLaunchTrigger::action()
//{
//	//�G�𐶐�
//	CCharacter* pBulletChara = CBulletFactoryManager::getInstance()->create(
//																			this->m_pLaunchData->m_type,
//																			this->m_pLaunchData->m_pos.x,
//																			this->m_pLaunchData->m_pos.y,
//																			this->m_pLaunchData->m_shotLaunchVector);
//
//	//���˂��I��������ǂ����̃t���O�𗧂Ă�
//	this->m_activeFlag = false;
//
//	return pBulletChara;
//}



//=============================================
//
// �o���X�P�W���[���[
// Singleton
//
//=============================================

//���L�C���X�^���X�{��
CLaunchScheduler* CLaunchScheduler::m_pSharedSchedular = NULL;


//�R���X�g���N�^
CLaunchScheduler::CLaunchScheduler()
{


}

//���L�C���X�^���X�̎擾
CLaunchScheduler* CLaunchScheduler::getInstance()
{
	if (CLaunchScheduler::m_pSharedSchedular == NULL)
	{
		CLaunchScheduler::m_pSharedSchedular = new CLaunchScheduler();
	}
	return CLaunchScheduler::m_pSharedSchedular;
}

//���L�C���X�^���X�̔j��
void CLaunchScheduler::removeInstance()
{
	SAFE_DELETE(CLaunchScheduler::m_pSharedSchedular);
}

//�f�X�g���N�^
CLaunchScheduler::~CLaunchScheduler()
{
	SAFE_DELETE(this->m_pLauncher);
}

/**
* @desc ���ˑ�̐���
* @param ���ˑ�ɐݒ肷��o���X�P�W���[���̃A�h���X
*/
void CLaunchScheduler::createLaunch(std::vector<CLaunchTrigger*>* pLaunchSchedule)
{
	if (this->m_pLauncher == NULL)
	{
		//���ˑ�𐶐����o���X�P�W���[���𔭎ˑ�ɐݒ�
		this->m_pLauncher = new CLauncher(pLaunchSchedule);
	}
}

/**
* @desc �L�����N�^�[�̏o��
* @param ���t���郌�C���[
*/
void CLaunchScheduler::launchCharacters(cocos2d::Layer* pLayer)
{
	//�X�P�W���[���[�Ɏ��t�����Ă���N���ł���g���K�[��S�ċN������
	std::shared_ptr<CLauncher::CLaunchTriggerItarator>itr = this->m_pLauncher->iterator();
	//���̋N���\�ȏo���g���K�[�����邩�ǂ������`�F�b�N
	while (itr->hasNext() == true)
	{
		//�N���\�ȏo���g���K�[���擾���ďo���g���K�[�C�e���[�^�[�����֐i�߂�
		CLaunchTrigger* pTrigger = itr->next();

		//�o���g���K�[���N��
		CCharacter* pChara = pTrigger->action();

		//NULL�`�F�b�N
		if (pChara != NULL)
		{
			//�L�����N�^�[���L�����N�^�[�̏W�܂�Ɏ��t����
			CCharacterAggregate::getInstance()->add(pChara);

			//�L�����N�^�[�����C�����C���[�Ɏ��t����
			pLayer->addChild(pChara);
		}
	}
}


