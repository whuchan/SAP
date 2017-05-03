#pragma once

#include"cocos2d.h"
#include"Constants.h"


//======================================
// �O���錾
//======================================
class CCharacter;
class CBody;

//======================================
// �̈�^�C�v
//======================================
enum class TERRITORY_TYPE :int
{
	LEFT,
	TOP,
	RIGHT,
	BOTTOM
};

//======================================
// �Փ˔����_
//======================================
class CCollisionBasePoint
{
public:
	//�̈�^�C�v
	TERRITORY_TYPE m_type;
	//��_
	cocos2d::Point m_pt;

	//�R���X�g���N�^
	CCollisionBasePoint(TERRITORY_TYPE type, cocos2d::Point pt) :m_type(type), m_pt(pt)
	{

	}
};


//======================================
// �Փ˔���̈�
//======================================
class CCollisionTerritory
{
public:
	//�̈�^�C�v
	TERRITORY_TYPE m_type;

	//�R���X�g���N�^
	CCollisionTerritory(TERRITORY_TYPE type) :m_type(type)
	{

	}

	virtual ~CCollisionTerritory()
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara,cocos2d::Point basePt) = 0;

public:
	//�C�x���g�R�[���o�b�N
	//void (CCharacter::*�^��)(int event)��typedef
	//typedef���N���X���ɋL�q���鎖��
	//�N���X�ɂ����L����typedef�ƂȂ�
	typedef void(CCharacter::*EventCallback)(int event);

protected:
	//�C�x���g�R�[���o�b�N
	EventCallback m_pEventCallback = NULL;

public:
	/**
	* @desc �C�x���g�R�[���o�b�N�̐ݒ�
	* @param �ݒ肷��C�x���g�R�[���o�b�N
	* @tips �̈�𐶐����A���������̈��
	* �C�x���g�R�[���o�b�N�i�����o�֐��|�C���^�j��ݒ肷�鎖��
	* ���̗̈�̃C�x���g��������������
	* �o�^���������o�֐��|�C���^���Ăяo�����
	*/
	void setEventCallback(EventCallback pEventCallback)
	{
		this->m_pEventCallback = pEventCallback;
	}

	/**
	* @desc �C�x���g�R�[���o�b�N�̌Ăяo��
	* @param �Ăяo���C���X�^���X
	* @param �C�x���g
	*		�}�b�v�`�b�v�̍ۂ̓}�b�v�`�b�vID���C�x���g�Ƃ��ēn����
	*		��ʒ[�Ȃǂ̓C�x���g�͑��݂��Ȃ��̂�
	*		�f�t�H���g�l�Ƃ��ĂO��ݒ肵�Ă���
	* @tips �̈�̃C�x���g�̔������񂢂��̃����o�֐����Ăяo������
	* �o�^���������o�֐��|�C���^���Ăяo�����
	*/
	void callEventCallback(CCharacter* pChara, int event = 0);
};


//======================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryEndOfScreenBottom:public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryEndOfScreenBottom(): CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// ��ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryEndOfScreenTop :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryEndOfScreenTop() : CCollisionTerritory(TERRITORY_TYPE::TOP)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// �E�ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryEndOfScreenRight :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryEndOfScreenRight() : CCollisionTerritory(TERRITORY_TYPE::RIGHT)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryEndOfScreenLeft :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryEndOfScreenLeft() : CCollisionTerritory(TERRITORY_TYPE::LEFT)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryOutOfScreenBottom :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryOutOfScreenBottom();
	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// ��ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryOutOfScreenTop :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryOutOfScreenTop();
	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// �E�ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryOutOfScreenRight :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::RIGHT�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryOutOfScreenRight();
	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//======================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryOutOfScreenLeft :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::LEFT�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryOutOfScreenLeft();
	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//======================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryMapChipBottom :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryMapChipBottom() : CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// ��ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryMapChipTop :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::TOP�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryMapChipTop() : CCollisionTerritory(TERRITORY_TYPE::TOP)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
//�@�E�ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryMapChipRight :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::RIGHT�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryMapChipRight() : CCollisionTerritory(TERRITORY_TYPE::RIGHT)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryMapChipLeft :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::LEFT�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryMapChipLeft() : CCollisionTerritory(TERRITORY_TYPE::LEFT)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// �Փ˔�����
//======================================
class CCollisionArea
{
protected:
	//�Փˊ�_�Q
	std::vector<CCollisionBasePoint*>* m_pBasePoints = NULL;

	//�Փ˔���̈�Q
	std::vector<CCollisionTerritory*>* m_pTerritories = NULL;

public:
	//�R���X�g���N�^
	CCollisionArea()
	{
		//�Փˊ�_�Q�̐���
		this->m_pBasePoints = new std::vector<CCollisionBasePoint*>();

		//�Փ˔���̈�Q�̐���
		this->m_pTerritories = new std::vector<CCollisionTerritory*>();
	}

	//�f�X�g���N�^
	virtual ~CCollisionArea()
	{
		//�Փˊ�_�Q�̉��
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			SAFE_DELETE(pBasePt);
		}
		SAFE_DELETE(this->m_pBasePoints);

		//�Փ˔���̈�Q�̉��
		for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
		{
			SAFE_DELETE(pTerritory);
		}
		SAFE_DELETE(this->m_pTerritories);
	}


	/**
	* @desc �Փˊ�_�̒ǉ�
	* @param �Փˊ�_
	*/
	virtual void addBasePoint(CCollisionBasePoint* pBasePoint)
	{
		this->m_pBasePoints->push_back(pBasePoint);
	}

	/**
	* @desc �Փ˔���̈�̒ǉ�
	* @param �Փ˔���̈�
	*/
	virtual void addTerritory(CCollisionTerritory* pTerritory)
	{
		this->m_pTerritories->push_back(pTerritory);
	}

	/**
	* @desc �Փ˔���
	* @param �Փ˔���̃L�����N�^�[
	* @tips ���t���[���Ăяo��
	*/
	virtual void collision(CCharacter* pChara) = 0;
};


//======================================
// ��ʒ[�Ƃ̏Փ˔�����
//======================================
class CCollisionAreaEndOfScreen : public CCollisionArea
{
public:
	//�R���X�g���N�^
	CCollisionAreaEndOfScreen()
	{

	}

	/**
	* @desc �R���X�g���N�^
	* @param �Փ˔���p���̃f�[�^
	*/
	CCollisionAreaEndOfScreen(CBody* pBody);


	//�f�X�g���N�^
	~CCollisionAreaEndOfScreen()
	{

	}

	/**
	* @desc �Փ˔���
	* @param �Փ˔���̃L�����N�^�[
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// ��ʊO�Ƃ̏Փ˔�����
//======================================
class CCollisionAreaOutOfScreen : public CCollisionArea
{
public:
	//�R���X�g���N�^
	CCollisionAreaOutOfScreen();
	/**
	* @desc �R���X�g���N�^
	* @param �Փ˔���p���̃f�[�^
	*/
	CCollisionAreaOutOfScreen(CBody* pBody);


	//�f�X�g���N�^
	~CCollisionAreaOutOfScreen();

	/**
	* @desc �Փ˔���
	* @param �Փ˔���̃L�����N�^�[
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// ��ʏ�ɂ���S�Ẵ}�b�v�`�b�v�Ƃ̏Փ˔�����
// �i�}�b�v�Ƃ̏Փ˔����ԁj
//======================================
class CCollisionAreaMap : public CCollisionArea
{
public:
	//�R���X�g���N�^
	CCollisionAreaMap()
	{

	}

	//�f�X�g���N�^
	~CCollisionAreaMap()
	{

	}

	/**
	* @desc �Փ˔���
	* @param �Փ˔���̃L�����N�^�[
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// ��ʏ�ɂ���S�Ẵ}�b�v�`�b�v�Ƃ̏Փ˔�����
// �i�}�b�v�Ƃ̏Փ˔����ԁj
//======================================
class CCollisionAreaLine : public CCollisionArea
{
public:
	//�R���X�g���N�^
	CCollisionAreaLine()
	{

	}

	//�f�X�g���N�^
	~CCollisionAreaLine()
	{

	}

	/**
	* @desc �Փ˔���
	* @param �Փ˔���̃L�����N�^�[
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// ���ɂ��郉�C���Ƃ̏Փ˔���
//======================================
class CCollisionTerritoryLineBottom :public CCollisionTerritory
{
public:
	/**
	* @desc �R���X�g���N�^
	* �̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM�ɐݒ肵�Ă���
	*/
	CCollisionTerritoryLineBottom() : CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
	{

	}

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏ�
	* @param ��_
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
