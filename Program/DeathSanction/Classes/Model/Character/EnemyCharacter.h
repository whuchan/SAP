#pragma once
#include "Character.h"

//======================================================
//
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//
//======================================================
template <class T>
class CEnemyCharacter : public CCharacter
{
public:
	//�R���X�g���N�^
	CEnemyCharacter()
	{
		//�L�����N�^�[�^�C�v��G�L�����N�^�[�ɐݒ�
		this->m_charaType = CHARACTER_TYPE::ENEMY;
	}

	//�f�X�g���N�^
	virtual ~CEnemyCharacter()
	{

	}

	//����������
	bool init()
	{
		//�L�����N�^�[�N���X�̏�����
		if (CCharacter::init() == false)
		{
			CCLOG("�v���C���[�L�����N�^�[�������Ɏ��s");
			return false;
		}

		return true;
	}

	/**
	* @desc�@����������
	* @param �����ʒuX
	* @param �����ʒuY
	* @tips create()�����o�֐��̒���init()�����o�֐����Ăяo���Ă��邪
	* ����A����create()�����o�֐����I�[�o�[���[�h����
	* �������󂯎���Ă���̂�init()�����o�֐���
	* �I�[�o�[���[�h����K�v������
	*/
	bool init(float posX, float posY)
	{
		//�L�����N�^�[�N���X�̏�����
		if (CCharacter::init() == false)
		{
			CCLOG("�G�L�����N�^�[�������Ɏ��s");
			return false;
		}
		return true;
	}

	/**
	* @desc CREATE_FUNC
	* @tips �O��͓G�o���f�[�^�Ƃ����G��p�̃N���X�����݂��Ă����̂�
	* ���̃N���X�ɒ��������Ă����͐����Ȃ�������
	* ����̓}�b�v�̏��ɂ��o���ʒu�̌���Ƃ������ڂ��K�v�ɂȂ�
	* �}�b�v���V���O���g�����@�����̂Œ��������Ă����Ȃ��悤�Ɏv���邪
	* �ŏI�I�ɕK�v�ƂȂ�͈̂ʒu������
	* �Ȃ̂Ő����Ɠ����Ɉʒu���擾������
	* �����������Acocos2dx�̋@�\�ł��鎩����delete�̋@�\���g������
	* �Ȃ̂�create�ÓI�����o�֐����J�X�^�}�C�Y����
	*/
	//CREATE_FUNC(CEnemyCharacter);
	static  T* create()
	{
		T* pRet = new(std::nothrow)T();
		if (pRet&&pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

	/**
	* @desc CREATE_FUNC�}�N�����I�[�o�[���C�h
	* @param �����ʒuX
	* @param �����ʒuY
	* @tips �����ʒu��K�v�Ƃ���̂͐����̒i�K�ł͂Ȃ�
	*       init�̒i�K�ł���
	*/
	static T* create(float posX,float posY)
	{
		T* pRet = new(std::nothrow)T();
		if (pRet&&pRet->init(posX,posY))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

	//�ړ�����
	void moveFunction(float deltaTime)
	{
		// �A�N�V����
		if (this->m_mapAction[this->m_intActionState])
		{
			std::map<int, CAction*>::iterator itaratorAction = this->m_mapAction[this->m_intActionState]->begin();

			while (itaratorAction != this->m_mapAction[this->m_intActionState]->end())
			{
				if (itaratorAction->second)
				{
					itaratorAction->second->update(this);
				}
				itaratorAction++;
			}
		}

		//�����v�Z
		if (this->m_mapPhysical[this->m_intPhysicalState])
		{
			for (CPhysical* pointerPhysical : (*this->m_mapPhysical[this->m_intPhysicalState]))
			{
				pointerPhysical->update(deltaTime, this->m_pMove);
			}
		}

		//�ړ��v�Z
		this->m_pMove->moveBy(deltaTime);
	}

	//�A�j���[�V��������
	void animationFunction(float deltaTime)
	{
		//�A�j���[�V����
		if (this->m_mapAnimation[this->m_intAnimationState])
		{
			this->m_mapAnimation[this->m_intAnimationState]->update();
		}
	}

	//��ԂƂ̏Փ˔��菈��
	virtual void collision()
	{
		//����ł������΂�
		if (this->m_isAlive == false)
		{
			return;
		}

		//��ԂƂ̏Փ˔�����s��
		for (CCollisionArea* pArea : (*this->m_pCollisionAreas))
		{
			pArea->collision(this);
		}
	}

	//��ԃ`�F�b�N
	void checkState(float deltaTime)
	{
		//�����̔���
		if (this->m_pMove->m_vel.x != 0)
		{
			if (this->m_pMove->m_vel.x > 0)
			{
				//�E�����ɐݒ�
				this->setScale(1.0f, 1.0f);
			}
			else
			{
				//�������ɐݒ�
				this->setScale(-1.0f, 1.0f);
			}
		}
	}

	//���f����
	void applayFunction()
	{
		//�ʒu�f�[�^�𔽉f
		this->setPosition(this->m_pMove->m_pos);

		//�`�b�v�f�[�^�𔽉f
		this->setTextureRect(this->m_mapAnimation[this->m_intAnimationState]->getCurrentChip());
	}

	

	/**
	* @desc �L�����N�^�[�P�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)
	{
		return true;
	}
	
	/**
	* @desc �Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	void hits(CCharacter* pChara)
	{
		//����ł������΂�
		if (this->m_isAlive == false)
		{
			return;
		}

		switch (pChara->m_charaType)
		{
			//�v���C���[�������ꍇ
		case CHARACTER_TYPE::PLAYER:	this->hitsPlayerCharacter(pChara);
			break;

			//�e�������ꍇ
		case CHARACTER_TYPE::BULLET:	this->hitsBulletCharacter(pChara);
			break;
		default:break;
		}
	}

protected:

	/**
	* @desc �v���C���[�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara)
	{
		//�v���C���[�̑����̈ʒu
		float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

		//�G�̒��S�ʒu
		float enePosY = this->m_pMove->m_pos.y;

		//�G���ォ�ǂ���
		float posY = playerFeetPosY - enePosY;
		if (posY > 0.0f)
		{

			//�G�̎��S�t���O�𗧂Ă�
			//�܂萶���Ă����邩����ł��邩�̃t���O��false������
			this->m_isAlive = false;

			//�G���S�A�N�V�������N������
			(*this->m_mapAction[this->m_intActionState])[0]->start();

			//=====================================================================
			// �߂荞�񂾕��߂�
			//=====================================================================
			//�߂荞�񂾕��̌v�Z
			float boundary = playerFeetPosY - (this->m_pMove->m_pos.y + this->m_pBody->m_top);

			//�ŏI�G�ɖ߂��l
			pChara->m_pMove->m_pos.y -= boundary;

			//=====================================================================
			// �W�����v�A�N�V�����̍ċN��
			//=====================================================================
			//�W�����v�A�N�V�����̍ċN��
			(*pChara->m_mapAction[pChara->m_intActionState])[0]->restart(pChara);

		}
		else
		{

		}
	}

	/**
	* @desc �e�Ƃ̏Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hitsBulletCharacter(CCharacter* pChara)
	{
		//�e�̗L���t���O��������
		pChara->m_activeFlag = false;

		//�G�̎��S�t���O�𗧂Ă�
		//�܂萶���Ă����邩����ł��邩�̃t���O��false������
		this->m_isAlive = false;

		//�G���S�A�N�V�������N������
		(*this->m_mapAction[this->m_intActionState])[0]->start();
	}

};