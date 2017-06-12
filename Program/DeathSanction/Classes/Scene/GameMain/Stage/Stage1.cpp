//==========================================
//
// File: CStage1.cpp
//
// �X�e�[�W�P �t�@�C��
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

#include "Stage1.h"

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
#include"Model\Character\Factory\EnemyFactory.h"
#include"Model\Character\Factory\GimmickFactory.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"
#include "Model\UI\PlayerHpBar.h"
#include "Model\UI\PlayerStaminaBar.h"

using namespace cocos2d::experimental;


/*
*	@desc	�R���X�g���N�^
*/
CStage1::CStage1()
{

}

/*
*	@desc	�f�X�g���N�^
*/
CStage1::~CStage1()
{

}


/**
*	@desc	������
*	@return	true...����	false...���s
*/
bool CStage1::init() {

	// �e���C���[�̏�����
	if (CStage::init() == false) {
		return false;
	}

	//UI���C���[�̐����Ǝ��t��
	this->m_pUILayer = Layer::create();
	this->addChild(this->m_pUILayer);

	//���C�����C���[�̐����Ǝ��t��
	this->m_pMainLayer = Layer::create();
	this->addChild(this->m_pMainLayer);

	//�}�b�v�̐����Ǝ��t��
	this->m_pMainLayer->addChild(CMapManager::getInstance()->createMap(MAP_DATA_SAMPLE));

	//�L�����N�^�[�̏W�܂�̐���
	this->m_pCharacters = new std::vector<CCharacter*>();
	//�L�����N�^�[�̏W�܂��CCharacterAggregate�֐ݒ肷��
	CCharacterAggregate::getInstance()->set(this->m_pCharacters);

	//�o���X�P�W���[���̐���
	this->m_pLaunchSchedule = new std::vector<CLaunchTrigger*>();

	//�o���X�P�W���[�����o���X�P�W���[���[�Ɏ��t����
	CLaunchScheduler::getInstance()->createLaunch(this->m_pLaunchSchedule);


	// �v���C���[�̐����Ǝ��t��
	CCharacter* pPlayerChara = CPlayerFactoryManager::getInstance()->create(CPlayerFactoryManager::TYPE::BASE);
	//�v���C���[�P�̃^�O��ݒ�
	pPlayerChara->m_tag = TAG_PLAYER_1;
	//CCharacterAggregate�Ƀv���C���[��ǉ�
	CCharacterAggregate::getInstance()->add(pPlayerChara);
	//�v���C���[�����C���[�ɒǉ�
	this->m_pMainLayer->addChild(pPlayerChara);


	//�v���C���[UI�̐����Ǝ��t��
	CPlayerHpBar* pPlayerHpBar = CPlayerHpBar::create(pPlayerChara,150, WINDOW_TOP - 64);
	this->m_pUILayer->addChild(pPlayerHpBar);
	CPlayerStaminaBar* pPlayerStaminaBar = CPlayerStaminaBar::create(pPlayerChara, 150, WINDOW_TOP - 96);
	this->m_pUILayer->addChild(pPlayerStaminaBar);



	//�X�N���[�����s��ꂽ���ɓG�̏o��������s��
	CMap* pMap = CMapManager::getInstance()->getMap();

	//�X�N���[�����s��ꂽ���ɃM�~�b�N�̏o��������s��

	//�}�b�v�̈ʒu���擾
	//cocos2d::Point pt = this->m_pMainLayer->getPosition();
	//	pMap->checkGimmickLaunch(pt.x, pt.y);

	// �^�C�g��BGM�̍Đ�
	int musicID = AudioEngine::play2d(SOUND_STAGE_1_BGM, true, 0.0f);
	// ID�ݒ�
	CSoundManager::getInstance()->setMusicID(BGM_STAGE1, musicID);

	return true;

}

//EOF