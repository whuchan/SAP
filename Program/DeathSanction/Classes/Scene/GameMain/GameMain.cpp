
//
//  GameMain.cpp
//  ActionGame
//
//  Created by ��H�T��
//
//

#include "GameMain.h"

// ����
#include "Lib/Input/InputManager.h"
// ���������p
#include <stdlib.h>
#include <time.h>
// �T�E���h�p
#include "SimpleAudioEngine.h"

#include"Model\Map\Map.h"
#include"Model\Character\Character.h"
#include"Model\Character\Factory\PlayerFactory.h"
#include"Model\Character\Factory\EnemyFactory.h"
#include"Model\Character\Factory\GimmickFactory.h"
#include "Data\LaunchData\LaunchData.h"

using namespace CocosDenshion;



/**
 *	@desc	�V�[���̐���
 *	@return	CMain ���C���[�������V�[���N���X�C���X�^���X
 *	@tips	�ÓI�����o�֐�
 */
cocos2d::Scene* CGameMain::createScene() {
	
	// �V�[���̐���
	cocos2d::Scene* pScene = cocos2d::Scene::create();
	
	// GameMain ���C���[�̐���
	CGameMain* pLayer = CGameMain::create() ;
	
	// CMain ���C���[���V�[���Ɏ��t����
	pScene->addChild( pLayer, 0, TAG_GAME_MAIN ) ;
	
	// ���������V�[����Ԃ�
	return pScene ;
}

/**
 *	@desc	�L�[�{�[�h�̃L�[���������ۂ̃C�x���g
 *	@param	�L�[�R�[�h
 *	@param	�C�x���g
 */
void CGameMain::onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event ) {

	// ���͊Ǘ��ɓ��͏������ϑ�
	CInputManager::getInstance()->onKeyPressed( keyCode ) ;
}

/**
 *	@desc	�L�[�{�[�h�̃L�[�𗣂����ۂ̃C�x���g
 *	@param	�L�[�R�[�h
 *	@param	�C�x���g
 */
void CGameMain::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event ) {

	// ���͊Ǘ��ɓ��͏������ϑ�
	CInputManager::getInstance()->onKeyReleased( keyCode ) ;
}

// �f�X�g���N�^
CGameMain::~CGameMain() {

	// BGM �̒�~
	SimpleAudioEngine::getInstance()->stopBackgroundMusic() ;
	
	// �S�Ă̌��ʉ����~
	SimpleAudioEngine::getInstance()->stopAllEffects() ;

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
bool CGameMain::init() {
	
	// �e���C���[�̏�����
	if ( Layer::init() == false ) {
		return false ;
	}
	
	// ��������
	srand( (unsigned int)time( NULL ) ) ;
	
	// �L�[�{�[�h���̓C�x���g�󂯎��ݒ�
	this->setKeyboardEnabled(true) ;
	
	// update �֐� ( �X�V�����֐� ) �Ăяo���ݒ�
	// ���̕�������������R�����g�A�E�g����� update �֐����Ă΂�Ȃ��Ȃ�̂Œ���
	this->scheduleUpdate() ;
	
	
	//=========================================================================
	//
	//	�������珉�����A�����ݒ�̃R�[�h��ǉ�
	//
	//=========================================================================
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
	

	//�X�N���[�����s��ꂽ���ɓG�̏o��������s��
	CMap* pMap = CMapManager::getInstance()->getMap();
	//�}�b�v�̈ʒu���擾
	cocos2d::Point pt = this->m_pMainLayer->getPosition();
	pMap->checkGimmickLaunch(pt.x, pt.y);




	//=========================================================================
	//
	//	�����܂łɏ������A�����ݒ�̃R�[�h��ǉ�
	//
	//=========================================================================
	
	return true ;
	
}

/**
 *	@desc	�X�V����
 *	@param	�P�t���[���o�ߎ���
 */
void CGameMain::update( float deltaTime_ ) {

	// esc �L�[����������Q�[���I��
	if ( inputflag.m_esc == true ) {
		cocos2d::Director::getInstance()->end() ;
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
}


/*
* @desc ��ʃX�N���[��
* @tips ����͋����X�N���[���ł͂Ȃ��L�����N�^�[�̈ړ��ɂ���ʂ̃X�N���[���ƂȂ�
*/
void CGameMain::scroll()
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
		pMap->checkGimmickLaunch(pt.x, pt.y);
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


