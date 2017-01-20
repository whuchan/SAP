#pragma once
#include"../EnemyCharacter.h"
#include "Model\Map\Map.h"

//=======================================================
//
// �G�p�[�c�H��N���X
//
//=======================================================
class CEnemyPartsFactory : public CCharacterPartsFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEnemyPartsFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CEnemyPartsFactory();

	/**
	* @desc �A�j���[�V�����f�[�^�Q�̎擾
	* @return �A�j���[�V�����f�[�^�Q
	*/
	std::vector<CAnimation*>*	getAnimations(void)override;
	/**
	* @desc �ړ��f�[�^�̎擾
	* @return �ړ��f�[�^
	*/
	CMove*						getMove(void)override;

	/**
	* @desc �������Z�f�[�^�Q�擾
	* @return �������Z�f�[�^�Q
	*/
	std::vector<CPhysical*>*	getPhysicals(void)override;

	/**
	* @desc �A�N�V�����f�[�^�Q�̎擾
	* @return �A�N�V�����f�[�^�Q
	*/
	std::vector<CAction*>*		getActions(void)override;

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
// �G�H��(����)�N���X
//
//=======================================================
class CEnemyFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEnemyFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CEnemyFactory();

	/**
	* @desc �G�L�����N�^�[�C���X�^���X����
	* @return �G�L�����N�^�[�C���X�^���X
	*/
	virtual CEnemyCharacter* create(float posX,float posY);

protected:

	/**
	* @desc
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual CEnemyCharacter* createEnemy(void) = 0;
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	virtual void settingMove(CEnemyCharacter* pCharacter, float posX, float posY) = 0;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingTexture(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingAnimations(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc �������Z�f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingPhysicals(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc �A�N�V�����f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingActions(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc ���̃f�[�^�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingBody(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	virtual void settingCollisionAreas(CEnemyCharacter* pCharacter) = 0;
	/**
	* @desc ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingInitialize(CEnemyCharacter* pCharacter) = 0;

};

//=======================================================
//
// �G�����H��
//
//=======================================================
class CEnemyCreateFactory : public CEnemyFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEnemyCreateFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CEnemyCreateFactory();

protected:
	virtual CEnemyCharacter* createEnemy(void)override;

};


//=======================================================
//
// �N���{�[�H��N���X
//
//=======================================================
class CKuriboFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CKuriboFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CKuriboFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};

//=======================================================
//
// �΃m�R�m�R�����H��N���X
//
//=======================================================
class CGreenNokoNokoFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CGreenNokoNokoFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CGreenNokoNokoFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};

//=======================================================
//
// �΃p�^�p�^�����H��N���X
//
//=======================================================
class CGreenPataPataFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CGreenPataPataFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CGreenPataPataFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};


//=======================================================
//
// �L���[�����H��N���X
//
//=======================================================
class CKillerFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CKillerFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CKillerFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};

//=======================================================
//
// �L���[���˖C�䐶���H��N���X
//
//=======================================================
class CKillerBatteryFactory : public CEnemyCreateFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CKillerBatteryFactory();
	/**
	* @desc �f�X�g���N�^
	*/
	~CKillerBatteryFactory();
protected:
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingTexture(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �������Z�f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingActions(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ���̃f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingBody(CEnemyCharacter* pCharacter)override;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �Փ˔���̈�f�[�^�Q
	*/
	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
	/**
	* @desc	 ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	void settingInitialize(CEnemyCharacter* pCharacter)override;
};



//=======================================================
//
// �G�H���Ǘ��N���X
//
// �V���O���g��
//
//=======================================================
class CEnemyFactoryManager
{
private:
	/*
	* @desc �R���X�g���N�^
	*/
	CEnemyFactoryManager();
public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CEnemyFactoryManager();

	/**
	* @desc �V���O���g���F�F�C���X�^���X�̎擾
	* @return �V���O���g���C���X�^���X
	*/
	static CEnemyFactoryManager* getInstance(void);
	/**
	* @desc �G�L�����N�^�[�𐶐�
	* @param �����^�C�v
	*/
	CEnemyCharacter* create(ENEMY_TYPE type, float posX, float posY);
	/**
	* @desc �V���O���g���C���X�^���X�̉��
	*/
	static void removeInstance();

private:
	//�G�����H��Q
	std::map<ENEMY_TYPE,CEnemyFactory*>* m_pFactories = NULL;
	//�V���O���g���C���X�^���X
	static CEnemyFactoryManager* m_pSharedManager;
};