//==========================================
//
// File: GameMain.cpp
//
// �Q�[�����C���Ǘ� �t�@�C��
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "Scene\GameMain\GameMain.h"
#include"Scene\GameMain\Stage\Stage1.h"

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

//==========================================
// �ÓI�ϐ���`
//==========================================
// ���L�C���X�^���X
CGameMainManager* CGameMainManager::m_pointerSharedGameMainManager = NULL;

/**
* @desc �R���X�g���N�^
*/
CGameMainManager::CGameMainManager()
{

}

/**
* @desc �f�X�g���N�^
*/
CGameMainManager::~CGameMainManager()
{

}

/**
* @desc		�w�肵���X�e�[�W�̃V�[���𐶐�
* @param	�X�e�[�W�i���o�[
* @return	�X�e�[�W�����t�����V�[���C���X�^���X
*/
cocos2d::Scene* CGameMainManager::createScene(int intStageNumber)
{
	// �V�[���̐���
	cocos2d::Scene* pointerScene = cocos2d::Scene::create();

	// GameMain ���C���[�̐���
	switch( (STAGE_NUMBER)intStageNumber )
	{
	case STAGE_NUMBER::ONE:	this->m_pointerCurrentStage = CStage1::create();
							break;

	default:				this->m_pointerCurrentStage = CStage1::create();
							break;
	}

	// CStage���C���[���V�[���Ɏ��t����
	pointerScene->addChild(this->m_pointerCurrentStage, 0, TAG_GAME_MAIN);

	return pointerScene;
}



/**
* @desc ���L�C���X�^���X�擾
* @return	���L�C���X�^���X
*/
CGameMainManager* CGameMainManager::getInstance(void)
{
	if (CGameMainManager::m_pointerSharedGameMainManager == NULL)
	{
		CGameMainManager::m_pointerSharedGameMainManager = new CGameMainManager();
	}
	return CGameMainManager::m_pointerSharedGameMainManager;
}

/**
* @desc		���L�C���X�^���X�j��
*/
void CGameMainManager::removeInstance(void)
{
	SAFE_DELETE(CGameMainManager::m_pointerSharedGameMainManager);
}
//EOF