//==========================================
//
// File: SoundManager.cpp
//
// ���y�Ǘ� �t�@�C��
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"Lib\Sound\SoundManager.h"

using namespace cocos2d::experimental;


//==========================================
//
// �V���O���g��
//
// Class: CSoundManager
//
// ���y�Ǘ��N���X   
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// �ÓI�ϐ���`
//==========================================
// ���L�C���X�^���X
CSoundManager* CSoundManager::m_pointerSharedSoundManager = NULL;



/**
* @desc �R���X�g���N�^
*/
CSoundManager::CSoundManager()
{

}

/**
* @desc �f�X�g���N�^
*/
CSoundManager::~CSoundManager()
{
	std::map<std::string, int>::iterator iteratorIndex = this->m_mapMusicID.begin();

	while (iteratorIndex != this->m_mapMusicID.end()) {
		iteratorIndex->second = NULL;
		iteratorIndex++;
	}
	this->m_mapMusicID.clear();
}

/*
*	@desc	BGM�̉��ʐݒ�
*	@param�@�C�ӂ̉���
*/
void CSoundManager::setBGMVolume(float floatVolume)
{
	this->m_floatBGMVolume = floatVolume;
}

/*
*	@desc	���ʉ��̉��ʐݒ�
*	@param�@�C�ӂ̉���
*/
void CSoundManager::setSEVolume(float floatVolume)
{
	this->m_floatSEVolume = floatVolume;
}

/**
*	@desc	���ʉ��̉��ʂ̎擾
*	@return  ����
*/
float CSoundManager::getSEVolume(void)
{
	return this->m_floatSEVolume;
}

/*
*	@desc	�Ώۉ��yID�̓o�^
*	@param	�o�^���鉹�y�̖���
*	@param	�����������y��ID
*/
void CSoundManager::setMusicID(std::string stringMusicName, int intMusicID)
{
	this->m_mapMusicID[stringMusicName] = intMusicID;
}

/*
*	@desc	�Ώۉ��yID�̎擾
*	@param	�����������y�̖���
*	@return	�����������y��ID
*/
int CSoundManager::getMusicID(std::string stringMusicName)
{
	return this->m_mapMusicID[stringMusicName];
}

/*
*	@desc	�w��̉����t�F�[�h�C��������
*	@param	�Ώۉ��y�̖���
*/
void CSoundManager::fadeIn(std::string stringMusicName)
{
	int intMusicID = this->getMusicID(stringMusicName);

	float floatVolume = AudioEngine::getVolume(intMusicID);

	// MAX Volume �o�Ȃ���Α���
	if (floatVolume < this->m_floatBGMVolume) {
		AudioEngine::setVolume(intMusicID, floatVolume + 0.01f);
	}
}

/*
*	@desc	�w��̉����t�F�[�h�A�E�g
*	@param	�Ώۉ��y�̖���
*/
void CSoundManager::fadeOut(std::string stringMusicName)
{
	int intMusicID = this->getMusicID(stringMusicName);

	float floatVolume = AudioEngine::getVolume(intMusicID);

	// MAX Volume �o�Ȃ���Α���
	if (floatVolume > 0.0f) {
		AudioEngine::setVolume(intMusicID, floatVolume - 0.01f);
	}
	else {
		// ���y���~�߂�
		AudioEngine::stop(intMusicID);
	}
}

/**
* @desc ���L�C���X�^���X�擾
* @return	���L�C���X�^���X
*/
CSoundManager* CSoundManager::getInstance(void)
{
	if (CSoundManager::m_pointerSharedSoundManager == NULL)
	{
		CSoundManager::m_pointerSharedSoundManager = new CSoundManager();
	}
	return CSoundManager::m_pointerSharedSoundManager;
}

/**
* @desc		���L�C���X�^���X�j��
*/
void CSoundManager::removeInstance(void)
{
	SAFE_DELETE(CSoundManager::m_pointerSharedSoundManager);
}
//EOF