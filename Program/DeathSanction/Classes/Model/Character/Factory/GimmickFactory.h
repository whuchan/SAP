#pragma once
#include"../GimmickCharacter.h"
#include"../DamageBlockGimmickCharacter.h"
#include"../HatenaBlockGimmickCharacter.h"
#include"../NoteBlockGimmickCharacter.h"
#include"../RollBlockGimmickCharacter.h"
#include"../TikuwaBlockGimmickCharacter.h"

#include "Model\Map\Map.h"

//=======================================================
//
// �M�~�b�N�p�[�c�H��N���X
//
//=======================================================
class CGimmickPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CGimmickPartsFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CGimmickPartsFactory();


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
// �M�~�b�N�H��(����)�N���X
//
//=======================================================
class CGimmickFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CGimmickFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CGimmickFactory();

	/**
	* @desc �M�~�b�N�L�����N�^�[�C���X�^���X����
	* @return �M�~�b�N�L�����N�^�[�C���X�^���X
	*/
	virtual CGimmickCharacter* create(float posX, float posY);

protected:

	/**
	* @desc
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual CGimmickCharacter* createGimmick(void) = 0;
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	virtual void settingMove(CGimmickCharacter* pCharacter, float posX, float posY) = 0;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingTexture(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingAnimations(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc �������Z�f�[�^�Q�̐ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingPhysicals(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc �A�N�V�����f�[�^�Q�̐ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingActions(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc ���̃f�[�^�̐ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingBody(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	virtual void settingCollisionAreas(CGimmickCharacter* pCharacter) = 0;
	/**
	* @desc ����������
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingInitialize(CGimmickCharacter* pCharacter) = 0;

};

//=======================================================
//
// �M�~�b�N�����H��
//
//=======================================================
class CDamageBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CDamageBlockGimmickCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CDamageBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// �_���[�W�u���b�N�M�~�b�N�H��N���X
//
//=======================================================
class CDamageBlockGimmickFactory : public CDamageBlockGimmickCreateFactory
{
public:

	enum class TYPE :int
	{
		LEFT = 146,		//�_���[�W��
		UP = 147,		//�_���[�W��
		RIGHT = 148,		//�_���[�W�E
		DOWN = 149,		//�_���[�W��
	};
private:
	int m_type = (int)TYPE::LEFT;

public:
	/**
	* @desc �R���X�g���N�^
	*/
	CDamageBlockGimmickFactory( int type);
	/**
	* @desc �f�X�g���N�^
	*/
	~CDamageBlockGimmickFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// �M�~�b�N�����H��
//
//=======================================================
class CRollBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CRollBlockGimmickCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CRollBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// ���u���b�N�M�~�b�N�H��N���X
//
//=======================================================
class CRollBlockGimmickFactory : public CRollBlockGimmickCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CRollBlockGimmickFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CRollBlockGimmickFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// �M�~�b�N�����H��
//
//=======================================================
class CTikuwaBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CTikuwaBlockGimmickCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CTikuwaBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;
};


//=======================================================
//
// ������u���b�N�M�~�b�N�H��N���X
//
//=======================================================
class CTikuwaBlockGimmickFactory : public CTikuwaBlockGimmickCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CTikuwaBlockGimmickFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CTikuwaBlockGimmickFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// �M�~�b�N�����H��
//
//=======================================================
class CNoteBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNoteBlockGimmickCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CNoteBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// ���˂�u���b�N�M�~�b�N�H��N���X
//
//=======================================================
class CNoteBlockGimmickFactory : public CNoteBlockGimmickCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CNoteBlockGimmickFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CNoteBlockGimmickFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};

//=======================================================
//
// �M�~�b�N�����H��
//
//=======================================================
class CHatenaBlockGimmickCreateFactory : public CGimmickFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CHatenaBlockGimmickCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CHatenaBlockGimmickCreateFactory();

protected:
	virtual CGimmickCharacter* createGimmick(void)override;

};


//=======================================================
//
// �L�����N�^�[���o������u���b�N�M�~�b�N�H��N���X
//
//=======================================================
class CHatenaBlockGimmickFactory : public CHatenaBlockGimmickCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CHatenaBlockGimmickFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CHatenaBlockGimmickFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CGimmickCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CGimmickCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CGimmickCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �M�~�b�N�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CGimmickCharacter* pCharacter)override;
};


//=======================================================
//
// �M�~�b�N�H���Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CGimmickFactoryManager
{
private:
	/*
	* @desc �R���X�g���N�^
	*/
	CGimmickFactoryManager();
public:
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CGimmickFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CGimmickFactoryManager* getInstance(void);
	/**
	* @desc �M�~�b�N�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CGimmickCharacter* create(GIMMICK_TYPE type, float posX, float posY);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();

private:
	//�M�~�b�N�����H��Q
	std::map<GIMMICK_TYPE, CGimmickFactory*>* m_pFactories = NULL;
	//�V���O���g���C���X�^���X
	static CGimmickFactoryManager* m_pSharedManager;
};