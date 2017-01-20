#pragma once
//==========================================
//
// File: SoundManager.h
//
// ���y�Ǘ� �w�b�_�[�t�@�C��
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================

#include	"cocos2d.h"
#include	"Constants.h"

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
class CSoundManager
{

private:
	/**
	* @desc �R���X�g���N�^
	*/
	CSoundManager();

public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CSoundManager();
	
	/**
	* @desc		���L�C���X�^���X�擾
	* @return	���L�C���X�^���X
	*/
	static CSoundManager* getInstance(void);

	/**
	* @desc		���L�C���X�^���X�j��
	*/
	static void removeInstance(void);

	/**
	*	@desc	BGM�̉��ʐݒ�
	*	@param�@�C�ӂ̉���
	*/
	void setBGMVolume(float floatVolume);

	/**
	*	@desc	���ʉ��̉��ʐݒ�
	*	@param�@�C�ӂ̉���
	*/
	void setSEVolume(float floatVolume);

	/**
	*	@desc	���ʉ��̉��ʂ̎擾
	*	@return  ����
	*/
	float getSEVolume(void);
	
	/*
	*	@desc	�Ώۉ��yID�̓o�^
	*	@param	�o�^���鉹�y�̖���
	*	@param	�����������y��ID
	*/
	void setMusicID(std::string stringMusicName, int intMusicID);

	/*
	*	@desc	�Ώۉ��yID�̎擾
	*	@param	�����������y�̖���
	*	@return	�����������y��ID
	*/
	int getMusicID(std::string stringMusicName);

	/*
	*	@desc	�w��̉����t�F�[�h�C��������
	*	@param	�Ώۉ��y�̖���
	*/
	void fadeIn(std::string stringMusicName);

	/*
	*	@desc	�w��̉����t�F�[�h�A�E�g
	*	@param	�Ώۉ��y�̖���
	*/
	void fadeOut(std::string stringMusicName);

	
private:

	// ���L�C���X�^���X
	static CSoundManager* m_pointerSharedSoundManager;

	// �Ώۉ��yID
	std::map<std::string, int>	m_mapMusicID;

	// BGM�̉���
	float m_floatBGMVolume = 0.0f;
	// ���ʉ��̉���
	float m_floatSEVolume = 0.0f;
};
//EOF