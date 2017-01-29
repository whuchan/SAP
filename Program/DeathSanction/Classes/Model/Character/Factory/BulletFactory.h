#pragma once

#pragma once
#include"../BulletCharacter.h"
#include"../FireBallBulletCharacter.h"
#include "Model\Map\Map.h"

//=======================================================
//
// �e�p�[�c�H��N���X
//
//=======================================================
class CBulletPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBulletPartsFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CBulletPartsFactory();

	/**
	* @desc �ړ��f�[�^�̎擾
	* @return �ړ��f�[�^
	*/
	CMove*						getMove(void)override;

	/**
	* @desc ���̃f�[�^�̎擾
	* @return ���̃f�[�^
	*/
	CBody*						getBody(void)override;

	/**
	* @desc �Փ˔���̈�f�[�^�Q�̎擾
	* @return �Փ˔���̈�f�[�^�Q
	*/
	std::vector<CCollisionArea*>* getCollisionAreas(void)override;

};

//=======================================================
//
// �e�H��(����)�N���X
//
//=======================================================
class CBulletFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBulletFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBulletFactory();

	/**
	* @desc �e�L�����N�^�[�C���X�^���X����
	* @return �e�L�����N�^�[�C���X�^���X
	*/
	virtual CBulletCharacter* create(float posX, float posY, cocos2d::Vec2 shotLaunchVector);

protected:

	/**
	* @desc
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual CBulletCharacter* createBullet(void) = 0;
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	virtual void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector) = 0;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingTexture(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingAnimations(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc �������Z�f�[�^�Q�̐ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingPhysicals(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc �A�N�V�����f�[�^�Q�̐ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingActions(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc ���̃f�[�^�̐ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingBody(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	virtual void settingCollisionAreas(CBulletCharacter* pCharacter) = 0;
	/**
	* @desc ����������
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingInitialize(CBulletCharacter* pCharacter) = 0;

};

//=======================================================
//
// �e�����H��
//
//=======================================================
class CBulletCreateFactory : public CBulletFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBulletCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBulletCreateFactory();

protected:
	virtual CBulletCharacter* createBullet(void)override;

};


//=======================================================
//
// �m�[�}���e�H��N���X
//
//=======================================================
class CNormalBulletFactory : public CBulletCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNormalBulletFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CNormalBulletFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CBulletCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CBulletCharacter* pCharacter)override;
};


//=======================================================
//
// �J�X�^���e�H��N���X
//
//=======================================================
class CCustomBulletFactory : public CBulletCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CCustomBulletFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CCustomBulletFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CBulletCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CBulletCharacter* pCharacter)override;
};


//=======================================================
//
// �t�@�C�A�[�{�[���e�����H��
//
//=======================================================
class CFireBallBulletCreateFactory : public CBulletFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CFireBallBulletCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CFireBallBulletCreateFactory();

protected:
	virtual CFireBallBulletCharacter* createBullet(void)override;

};


//=======================================================
//
// �t�@�C�A�[�{�[���e�H��N���X
//
//=======================================================
class CFireBallBulletFactory : public CFireBallBulletCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CFireBallBulletFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CFireBallBulletFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CBulletCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CBulletCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �e�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CBulletCharacter* pCharacter)override;
};


//=======================================================
//
// �e�H���Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CBulletFactoryManager
{
private:
	/*
	* @desc �R���X�g���N�^
	*/
	CBulletFactoryManager();
public:
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CBulletFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CBulletFactoryManager* getInstance(void);
	/**
	* @desc �e�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CBulletCharacter* create(BULLET_TYPE type, float posX, float posY,cocos2d::Vec2  shotLaunchVector);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();

private:
	//�e�����H��Q
	std::map<BULLET_TYPE, CBulletFactory*>* m_pFactories = NULL;
	//�V���O���g���C���X�^���X
	static CBulletFactoryManager* m_pSharedManager;
};