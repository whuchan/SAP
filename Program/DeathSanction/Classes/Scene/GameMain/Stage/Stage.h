#pragma once
//==========================================
//
// File: Stage.h
//
// �X�e�[�W ���@�w�b�_�[�t�@�C��
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "cocos2d.h"
#include "Constants.h"

//=========================================================================
//	�O���錾
//=========================================================================
class CCharacter;
class CPlayerCharacter;
class CEnemyLaunchData;
class CGimmickLaunchData;
class CLaunchTrigger;

//==========================================
//
// Class: CStage
//
// �X�e�[�W�@���N���X   
//
// 2017/01/20
//						Author Shinya Ueba
//==========================================
class CStage : public cocos2d::Layer
{
public:

	/*
	*	@desc	�R���X�g���N�^
	*/
	CStage();

	/*
	*	@desc	�f�X�g���N�^
	*/
	~CStage();

	/**
	*	@desc	�L�[�{�[�h�̃L�[���������ۂ̃C�x���g
	*	@param	�L�[�R�[�h
	*	@param	�C�x���g
	*/
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;

	/**
	*	@desc	�L�[�{�[�h�̃L�[�𗣂����ۂ̃C�x���g
	*	@param	�L�[�R�[�h
	*	@param	�C�x���g
	*/
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) override;

	/**
	*	@desc	������
	*	@return	true...����	false...���s
	*/
	virtual bool init() override;

	/**
	* @desc ��������
	*/
	CREATE_FUNC(CStage);

	/**
	*	@desc	�X�V����
	*	@param	�o�ߎ���
	*/
	virtual void update(float deltaTime_) override;

	//=========================================================================
	//	�����܂ł͗����o����܂ł͕ύX�֎~
	//=========================================================================

	/*
	* @desc ��ʃX�N���[��
	* @tips ����͋����X�N���[���ł͂Ȃ��L�����N�^�[�̈ړ��ɂ���ʂ̃X�N���[���ƂȂ�
	*/
	void scroll();


	/**
	*	@desc	�`�F�b�N�Ǝ��O������ ( �P�� )
	*	@tips	�L���t���O�� false �̃C���X�^���X�����C���[������O��
	*/
	template <typename Ty>
	void checkAndRemove(Ty* pChara);
	/**
	*	@desc	�`�F�b�N�Ǝ��O������ ( ���� )
	*	@tips	�L���t���O�� false �̃C���X�^���X�����C���[�� std::vector ������O��
	*/
	template <typename Ty>
	void checkAndRemove(std::vector<Ty*>* pCharas);

	/**
	* @desc �`�F�b�N�Ɖ��
	* @tips �L���t���O��false�̃C���X�^���X�������std::vector������O��
	*/
	template <typename Ty>
	void checkAndDelete(std::vector<Ty*>* pVector);


	/**
	* @desc ���C�����C���[�̎擾
	* @return ���C�����C���[�C���X�^���X
	*/
	cocos2d::Layer* getMainLayer();

	/**
	* @desc UI���C���[�̎擾
	* @return UI���C���[�C���X�^���X
	*/
	cocos2d::Layer* getUILayer();


protected:

	//=========================================================================
	//	�����o�錾
	//		�Q�[�����C�����Ŏg�p���郁���o�͂����ȍ~�ɋL�q���Ă���
	//=========================================================================
	//���C�����C���[
	cocos2d::Layer* m_pMainLayer = NULL;

	//UI ���C���[
	cocos2d::Layer* m_pUILayer = NULL;

	//�L�����N�^�[�̏W�܂�̖{��
	std::vector<CCharacter*>* m_pCharacters = NULL;

	//�o���X�P�W���[��
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;
};

