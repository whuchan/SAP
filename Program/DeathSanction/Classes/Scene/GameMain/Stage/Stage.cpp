//==========================================
//
// File: CStage.cpp
//
// �X�e�[�W�P �t�@�C��
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

#include "Stage.h"

//==========================================
// �w�b�_�C���N���[�h
//==========================================
// ����
#include "Lib/Input/InputManager.h"
//���y�Đ��p
#include "Lib\Sound\SoundManager.h"

// ���������p
#include <stdlib.h>
#include <time.h>

#include"Model\Map\Map.h"
#include"Model\Character\Character.h"
#include"Model\Character\Factory\PlayerFactory.h"
#include"Model\Character\Factory\EnemyFactoryManager.h"
#include"Model\Character\Factory\GimmickFactory.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"


/**
*	@desc	�L�[�{�[�h�̃L�[���������ۂ̃C�x���g
*	@param	�L�[�R�[�h
*	@param	�C�x���g
*/
void CStage::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {

	// ���͊Ǘ��ɓ��͏������ϑ�
	CInputManager::getInstance()->onKeyPressed(keyCode);
}

/**
*	@desc	�L�[�{�[�h�̃L�[�𗣂����ۂ̃C�x���g
*	@param	�L�[�R�[�h
*	@param	�C�x���g
*/
void CStage::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) {

	// ���͊Ǘ��ɓ��͏������ϑ�
	CInputManager::getInstance()->onKeyReleased(keyCode);
}

/*
*	@desc	�R���X�g���N�^
*/
CStage::CStage()
{

}

/*
*	@desc	�f�X�g���N�^
*/
CStage::~CStage()
{
	//�G�����H��Ǘ��N���X�̉��
	CEnemyFactoryManager::removeInstance();

	//�v���C���[�����H��Ǘ��N���X�̉��
	CPlayerFactoryManager::removeInstance();

	//�L�����N�^�[�̏W�܂�̔j��
	SAFE_DELETE(this->m_pCharacters);


	//�o���g���K�[�̔j��
	for (CLaunchTrigger* pTrigger : (*this->m_pLaunchSchedule))
	{
		SAFE_DELETE(pTrigger);
	}
	//�o���X�P�W���[���̔j��
	SAFE_DELETE(this->m_pLaunchSchedule);

	//CCharacterAggregate�̋��L�C���X�^���X�̔j��
	CCharacterAggregate::removeInstance();

}


/**
*	@desc	������
*	@return	true...����	false...���s
*/
bool CStage::init() {

	// �e���C���[�̏�����
	if (Layer::init() == false) {
		return false;
	}

	// ��������
	srand((unsigned int)time(NULL));

	// �L�[�{�[�h���̓C�x���g�󂯎��ݒ�
	this->setKeyboardEnabled(true);

	// update �֐� ( �X�V�����֐� ) �Ăяo���ݒ�
	// ���̕�������������R�����g�A�E�g����� update �֐����Ă΂�Ȃ��Ȃ�̂Œ���
	this->scheduleUpdate();

	return true;

}

/**
*	@desc	�X�V����
*	@param	�P�t���[���o�ߎ���
*/
void CStage::update(float deltaTime_) {

	

	// esc �L�[����������Q�[���I��
	if (inputflag.m_esc == true) {
		cocos2d::Director::getInstance()->end();
	}

	//=========================================================================
	//
	//	��������X�V�����̃R�[�h��ǉ�
	//
	//=========================================================================

	//=========================================================
	// �o���X�P�W���[���[�̋N��
	//=========================================================
	//�L�����N�^�[���o��������
	CLaunchScheduler::getInstance()->launchCharacters(this->m_pMainLayer);

	//�o���̊��������g���K�[��S�Ď��O��
	this->checkAndDelete(this->m_pLaunchSchedule);

	//=========================================================================
	//	�Փ˔��菈���Ɋւ���R�[�h�̒ǉ��͂�������
	//=========================================================================



	//=========================================================================
	//	��ʂ̃X�N���[��
	//=========================================================================
	this->scroll();


	//=========================================================================
	//	���O���Ɋւ���R�[�h�̒ǉ��͂�������
	//=========================================================================
	this->checkAndRemove(this->m_pCharacters);

	//=========================================================================
	//
	//	�����܂łɍX�V�����̃R�[�h��ǉ�
	//
	//=========================================================================

	//���͍X�V����
	inputflag.update();
}


/*
* @desc ��ʃX�N���[��
* @tips ����͋����X�N���[���ł͂Ȃ��L�����N�^�[�̈ړ��ɂ���ʂ̃X�N���[���ƂȂ�
*/
void CStage::scroll()
{
	//�}�b�v�̈ʒu���擾
	cocos2d::Point pt = this->m_pMainLayer->getPosition();

	//�v���C���[�L�����N�^�[�̎擾
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	//�v���C���[�̈ʒu���R���̂Q�𒴂�����
	if (pt.x > (WINDOW_RIGHT / 3.0) * 2.0f - pPlayerChara->m_pMove->m_pos.x)
	{
		//���_�ʒu�𒴂������ɐݒ肷��
		pt.x = (WINDOW_RIGHT / 3.0) * 2.0f - pPlayerChara->m_pMove->m_pos.x;

		//����������ݒ肷��
		this->m_pMainLayer->setPosition(pt);

		//�X�N���[�����s��ꂽ���ɓG�̏o��������s��
		CMap* pMap = CMapManager::getInstance()->getMap();
		pMap->checkEnemyLaunch(pt.x, pt.y);

		//�X�N���[�����s��ꂽ���ɃM�~�b�N�̏o��������s��
		//		pMap->checkGimmickLaunch(pt.x, pt.y);
	}
	else if (pt.x < (WINDOW_RIGHT / 3.0) - pPlayerChara->m_pMove->m_pos.x)
	{
		//�v���C���[�̈ʒu���R���̂P�ȉ��ɂȂ�����

		//���_�ʒu�𒴂������ɐݒ肷��
		pt.x = (WINDOW_RIGHT / 3.0) - pPlayerChara->m_pMove->m_pos.x;

		//����������ݒ肷��
		this->m_pMainLayer->setPosition(pt);
	}



}


/**
*	@desc	�`�F�b�N�Ǝ��O������ ( �P�� )
*	@tips	�L���t���O�� false �̃C���X�^���X�����C���[������O��
*/
template <typename Ty>
void CStage::checkAndRemove(Ty* pChara) {

	if (pChara->m_activeFlag == false) {
		pChara->removeFromParent();
	}
}

/**
*	@desc	�`�F�b�N�Ǝ��O������ ( ���� )
*	@tips	�L���t���O�� false �̃C���X�^���X�����C���[�� std::vector ������O��
*/
template <typename Ty>
void CStage::checkAndRemove(std::vector<Ty*>* pCharas) {

	// ���[�J���ϐ��̌^�̃e���v���[�g�����̎w��Ƃ���
	// �e���v���[�g�������w�肷��ꍇ�� typename �w������Ȃ���΂Ȃ�Ȃ�
	typename std::vector<Ty*>::iterator itr = pCharas->begin();
	while (itr != pCharas->end()) {

		if ((*itr)->m_activeFlag == false) {

			(*itr)->removeFromParent();
			itr = pCharas->erase(itr);

		}
		else {
			itr++;
		}
	}
}

/**
* @desc �`�F�b�N�Ɖ��
* @tips �L���t���O��false�̃C���X�^���X�������std::vector������O��
*/
template <typename Ty>
void CStage::checkAndDelete(std::vector<Ty*>* pVector)
{
	//���[�J���ϐ��̌^�̃e���v���[�g�����̎w��Ƃ���
	//�e���v���[�g�������w�肷��ꍇ��typename�w������Ȃ���΂Ȃ�Ȃ�
	typename std::vector<Ty*>::iterator itr = pVector->begin();

	while (itr != pVector->end())
	{
		if ((*itr)->m_activeFlag == false)
		{
			SAFE_DELETE((*itr));

			itr = pVector->erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

/**
* @desc ���C�����C���[�̎擾
* @return ���C�����C���[�C���X�^���X
*/
cocos2d::Layer* CStage::getMainLayer()
{
	return this->m_pMainLayer;
}

/**
* @desc UI���C���[�̎擾
* @return UI���C���[�C���X�^���X
*/
cocos2d::Layer* CStage::getUILayer()
{
	return this->m_pUILayer;
}

//EOF