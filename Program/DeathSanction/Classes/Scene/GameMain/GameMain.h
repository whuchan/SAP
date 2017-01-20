#pragma once

//=========================================================================
//	�ǉ��̃C���N���[�h�͂�������
//=========================================================================
#include "cocos2d.h"
#include "Constants.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"

//=========================================================================
//	�O���錾
//=========================================================================
class CStage;

//==========================================
//
// �V���O���g��
//
// Class: CGameMainManager
//
// �Q�[�����C�� �X�e�[�W�Ǘ��N���X   
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================
class CGameMainManager
{
public:
	enum class STAGE_NUMBER : int
	{
		ONE = 0,
		MAX_STAGE_NUMBER,
	};
	
private:
	/**
	* @desc �R���X�g���N�^
	*/
	CGameMainManager();

public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CGameMainManager();

	/**
	* @desc		�w�肵���X�e�[�W�̃V�[���𐶐�
	* @param	�X�e�[�W�i���o�[
	* @return	�X�e�[�W�����t�����V�[���C���X�^���X
	*/
	cocos2d::Scene* CGameMainManager::createScene(int intStageNumber);

	/**
	* @desc		���L�C���X�^���X�擾
	* @return	���L�C���X�^���X
	*/
	static CGameMainManager* getInstance(void);

	/**
	* @desc		���L�C���X�^���X�j��
	*/
	static void removeInstance(void);

private:
	// ���L�C���X�^���X
	static CGameMainManager* m_pointerSharedGameMainManager;

	CStage* m_pointerCurrentStage = NULL;

};

//EOF