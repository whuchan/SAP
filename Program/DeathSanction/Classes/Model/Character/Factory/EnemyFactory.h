#pragma once
#include "CharacterFactory.h"
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

	/**
	* @desc ��ԑJ�ڃ}�V���̎擾
	* @return ��ԑJ�ڃ}�V���̃C���X�^���X
	*/
	virtual CStateMachine* getStateMachine(void)override;

};

//=======================================================
//
// �G�H��(����)�N���X
//
//=======================================================
class CCharacterFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CCharacterFactory()
	{

	}
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CCharacterFactory()
	{

	}

	/**
	* @desc �G�L�����N�^�[�𐶐�
	* @param �������WX
	* @param �������WY
	* @return �G�L�����N�^�[�C���X�^���X
	*/
	virtual CCharacter* create(float posX, float posY)
	{
		//�G�L�����N�^�[�̐���
		CCharacter* pCharacter = this->createCharacter();

		//�A�j���[�V�����f�[�^�Q�̐ݒ�
		this->settingAnimations(pCharacter);
		//�ړ��f�[�^�̐ݒ�
		this->settingMove(pCharacter, posX, posY);
		//�������Z�f�[�^�Q�̐ݒ�
		this->settingPhysicals(pCharacter);
		//�A�N�V�����f�[�^�Q�̐ݒ�
		this->settingActions(pCharacter);
		//���̃f�[�^�̐ݒ�
		this->settingBody(pCharacter);
		//�e�N�X�`���̐ݒ�
		this->settingTexture(pCharacter);
		//�Փ˔���f�[�^�Q�̐ݒ�
		this->settingCollisionAreas(pCharacter);
		//��ԑJ�ڃ}�V���̐ݒ�
		this->settingStateMachine(pCharacter);

		//�����ݒ�
		this->settingInitialize(pCharacter);

		return pCharacter;
	}

protected:

	/**
	* @desc
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual CCharacter* createCharacter(void) = 0;
	/**
	* @desc	 �ړ��f�[�^��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	* @param �������WX
	* @param �������WY
	*/
	virtual void settingMove(CCharacter* pCharacter, float posX, float posY) = 0;
	/**
	* @desc	 �e�N�X�`���[��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingTexture(CCharacter* pCharacter) = 0;
	/**
	* @desc �A�j���[�V�����f�[�^�Q��ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingAnimations(CCharacter* pCharacter) = 0;
	/**
	* @desc �������Z�f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingPhysicals(CCharacter* pCharacter) = 0;
	/**
	* @desc �A�N�V�����f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingActions(CCharacter* pCharacter) = 0;
	/**
	* @desc ���̃f�[�^�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingBody(CCharacter* pCharacter) = 0;
	/**
	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingCollisionAreas(CCharacter* pCharacter) = 0;
	/**
	* @desc ��ԑJ�ڃ}�V���̐ݒ�
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual	void settingStateMachine(CCharacter* pCharacter) = 0;

	/**
	* @desc ����������
	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
	*/
	virtual void settingInitialize(CCharacter* pCharacter) = 0;

};

//=======================================================
//
// �G�����H��
//
//=======================================================
template <class T>
class CEnemyCreateFactory : public CCharacterFactory
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CEnemyCreateFactory()
	{

	}
	
	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CEnemyCreateFactory()
	{

	}

protected:
	virtual CCharacter* createCharacter(void)
	{
		//�G�L�����N�^�[�̐���
		CCharacter* pCharacter = T::create();

		//�G�L�����N�^�[���i�����H��̐���
		CEnemyPartsFactory factory;

		//�ړ��f�[�^�̐ݒ�
		pCharacter->addMove(factory.getMove());
		//���̃f�[�^�̐ݒ�
		pCharacter->addBody(factory.getBody());
		//�Փ˔���f�[�^�Q�̐ݒ�
		pCharacter->addCollisionAreas(factory.getCollisionAreas());
		//��ԑJ�ڃ}�V���̐ݒ�
		pCharacter->addStateMachine(factory.getStateMachine());


		return pCharacter;
	}
};


////=======================================================
////
//// �N���{�[�H��N���X
////
////=======================================================
//class CKuriboFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc �R���X�g���N�^
//	*/
//	CKuriboFactory();
//	/**
//	* @desc �f�X�g���N�^
//	*/
//	~CKuriboFactory();
//protected:
//	/**
//	* @desc	 �ړ��f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	* @param �������WX
//	* @param �������WY
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 �e�N�X�`���[��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �������Z�f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ���̃f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
//	* @param �Փ˔���̈�f�[�^�Q
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ����������
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
////=======================================================
////
//// �΃m�R�m�R�����H��N���X
////
////=======================================================
//class CGreenNokoNokoFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc �R���X�g���N�^
//	*/
//	CGreenNokoNokoFactory();
//	/**
//	* @desc �f�X�g���N�^
//	*/
//	~CGreenNokoNokoFactory();
//protected:
//	/**
//	* @desc	 �ړ��f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	* @param �������WX
//	* @param �������WY
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 �e�N�X�`���[��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �������Z�f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ���̃f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
//	* @param �Փ˔���̈�f�[�^�Q
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ����������
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
////=======================================================
////
//// �΃p�^�p�^�����H��N���X
////
////=======================================================
//class CGreenPataPataFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc �R���X�g���N�^
//	*/
//	CGreenPataPataFactory();
//	/**
//	* @desc �f�X�g���N�^
//	*/
//	~CGreenPataPataFactory();
//protected:
//	/**
//	* @desc	 �ړ��f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	* @param �������WX
//	* @param �������WY
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 �e�N�X�`���[��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �������Z�f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ���̃f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
//	* @param �Փ˔���̈�f�[�^�Q
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ����������
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
//
////=======================================================
////
//// �L���[�����H��N���X
////
////=======================================================
//class CKillerFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc �R���X�g���N�^
//	*/
//	CKillerFactory();
//	/**
//	* @desc �f�X�g���N�^
//	*/
//	~CKillerFactory();
//protected:
//	/**
//	* @desc	 �ړ��f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	* @param �������WX
//	* @param �������WY
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 �e�N�X�`���[��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �������Z�f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ���̃f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
//	* @param �Փ˔���̈�f�[�^�Q
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ����������
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//
////=======================================================
////
//// �L���[���˖C�䐶���H��N���X
////
////=======================================================
//class CKillerBatteryFactory : public CEnemyCreateFactory
//{
//public:
//	/**
//	* @desc �R���X�g���N�^
//	*/
//	CKillerBatteryFactory();
//	/**
//	* @desc �f�X�g���N�^
//	*/
//	~CKillerBatteryFactory();
//protected:
//	/**
//	* @desc	 �ړ��f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	* @param �������WX
//	* @param �������WY
//	*/
//	void settingMove(CEnemyCharacter* pCharacter, float posX, float posY)override;
//	/**
//	* @desc	 �e�N�X�`���[��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingTexture(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�j���[�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingAnimations(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �������Z�f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingPhysicals(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 �A�N�V�����f�[�^�Q��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingActions(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ���̃f�[�^��ݒ�
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingBody(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc �Փ˔���̈�f�[�^�Q�̐ݒ�
//	* @param �Փ˔���̈�f�[�^�Q
//	*/
//	void settingCollisionAreas(CEnemyCharacter* pCharacter)override;
//	/**
//	* @desc	 ����������
//	* @param �G�L�����N�^�[�C���X�^���X�̃A�h���X
//	*/
//	void settingInitialize(CEnemyCharacter* pCharacter)override;
//};
//


//EOF