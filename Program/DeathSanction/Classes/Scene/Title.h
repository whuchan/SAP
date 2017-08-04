#pragma once
//==========================================
//
// File: Title.h
//
// �^�C�g���V�[���t�@�C��
//
// 2016/12/21
//						Author Shinya Ueba
//
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"cocos2d.h"

//==========================================
//
// Class: CTitle
//
// �L�[�{�[�h���̓R���g���[���[�N���X
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CTitle : public cocos2d::Layer
{
public:
	/*
	* @desc �R���X�g���N�^
	*/
	CTitle();

	/*
	* @desc �f�X�g���N�^
	*/
	~CTitle();

	/**
	* @desc		�V�[���̐���
	* @return	CTitle���C���[�������V�[���N���X�C���X�^���X
	* @tips		�ÓI�����o�֐�
	*/
	static cocos2d::Scene* createScene();

	//create()�ÓI�����o�֐��̍쐬
	CREATE_FUNC(CTitle);

	/**
	* @desc ������
	* @return true...���� false...���s
	*/
	bool init() override;

	/**
	* @desc  �X�V����
	* @param �o�ߎ���
	*/
	void update(float deltaTime) override;

	/**
	* @desc		�Q�[�����C���ɑJ��
	* @param	�^�C�g�����C���[�̃C���X�^���X
	* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
	*/
	void callbackChangeGameMain(cocos2d::Ref* pSender);

	/*
	* @desc�@�Q�[���I��
	* @param �^�C�g�����C���[�̃C���X�^���X
	* @tips	 �Q�[���I���{�^���������ꂽ���ɌĂяo�����
	*/
	void callbackEndGame(cocos2d::Ref* pSender);
};


//EOF