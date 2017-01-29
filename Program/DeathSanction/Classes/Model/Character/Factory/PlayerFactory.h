#pragma once

#include "../PlayerCharacter.h"

//=======================================================
//
// �v���C���[�L�����N�^�[���i�����N���X
//
//=======================================================
class CPlayerPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerPartsFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerPartsFactory();

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
// �v���C���[�L�����N�^�[����(����)�N���X
//
//=======================================================
class CPlayerFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CPlayerFactory();

	/**
	* @desc �v���C���[�L�����N�^�[�C���X�^���X����
	* @return �v���C���[�L�����N�^�[�C���X�^���X
	*/
	virtual CPlayerCharacter* create(void);

protected:

	/**
	* @desc
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual CPlayerCharacter* createPlayer(void) = 0;
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingMove(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingTexture(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingAnimations(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc �������Z�f�[�^�Q�̐ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingPhysicals(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc �A�N�V�����f�[�^�Q�̐ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingActions(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc ���̃f�[�^�̐ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingBody(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	virtual void settingCollisionAreas(CPlayerCharacter* pCharacter) = 0;
	/**
	* @desc ����������
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingInitialize(CPlayerCharacter* pCharacter) = 0;

};

//=======================================================
//
// �v���C���[�L�����N�^�[�����N���X
//
//=======================================================
class CPlayerCreateFactory : public CPlayerFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CPlayerCreateFactory();

protected:
	/**
	* @desc �v���C���[�L�����N�^�[�̐���
	* @return �v���C���[�L�����N�^�[�̃C���X�^���X�̃A�h���X
	*/
	virtual CPlayerCharacter* createPlayer(void)override;

};


//=======================================================
//
// ��{�^�v���C���[�L�����N�^�[�����N���X
//
//=======================================================
class CBasePlayerFactory : public CPlayerCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CBasePlayerFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CBasePlayerFactory();

	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingMove(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CPlayerCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CPlayerCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �v���C���[�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CPlayerCharacter* pCharacter)override;
};

//=======================================================
//
// �v���C���[�L�����N�^�[�����N���X�Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CPlayerFactoryManager
{
public:
	//�����v���C���[�^�C�v
	enum class TYPE :int
	{
		BASE = 0,
	};

private:
	/*
	* @desc �R���X�g���N�^
	*/
	CPlayerFactoryManager();
public:
	/** 
	* @desc �f�X�g���N�^
	*/
	~CPlayerFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CPlayerFactoryManager* getInstance(void);
	/**
	* @desc �v���C���[�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CPlayerCharacter* create(CPlayerFactoryManager::TYPE type);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();
	
private:	
	//�H��C���X�^���X�i�[�z��
	std::vector<CPlayerFactory*>m_pFactories;
	//�V���O���g���C���X�^���X
	static CPlayerFactoryManager* m_pSharedFactory;
};