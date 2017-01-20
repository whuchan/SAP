#include "PlayerCharacter.h"
#include "Model\Map\Map.h"
#include "Lib/Input/InputManager.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"

//�R���X�g���N�^
CPlayerCharacter::CPlayerCharacter()
{
	//�L�����N�^�[�^�C�v���v���C���[�L�����N�^�[�ɐݒ�
	this->m_charaType = CHARACTER_TYPE::PLAYER;

}
//�f�X�g���N�^
CPlayerCharacter::~CPlayerCharacter()
{

}

bool CPlayerCharacter::init()
{
	//�L�����N�^�[�N���X�̏�����
	if (CCharacter::init() == false)
	{
		CCLOG("CPlayerCharacter�������Ɏ��s");
		return false;
	}	

	return true;
}

void CPlayerCharacter::update(float deltaTime)
{
	//x���̉����x�̏�����
	this->m_pMove->m_accele.x = 0.0f;

	//�L�����N�^�[�̍X�V�����Ăяo��
	CCharacter::update(deltaTime);

}

/**
* @desc ���͏���
* @tips �ړ������ŌĂяo��
*/
void CPlayerCharacter::inputFunc()
{
	if (inputflag.m_left == true)
	{
		this->m_pMove->m_accele.x = -0.7f;
	}

	if (inputflag.m_right == true)
	{
		this->m_pMove->m_accele.x = 0.7f;
	}

	if (inputflag.m_up == true)
	{
		//�W�����v���J�n������
		(*this->m_pActions)[(int)ACTION::JUMP]->start();
	}

	//�e�𔭎˂���
	if (inputflag.m_z == true)
	{

		if (this->getScaleX() >= 0)
		{
			this->m_shotLaunchVector = cocos2d::Vec2(1.0, 0.0f);
		}
		else
		{
			this->m_shotLaunchVector = cocos2d::Vec2(-1.0, 0.0f);
		}
		(*this->m_pActions)[(int)ACTION::SHOT_FIREBALL_BULLET]->start();
	}

	//�e�𔭎˂���
	if (inputflag.m_x == true)
	{
		if (this->getScaleX() >= 0)
		{
			this->m_shotLaunchVector = cocos2d::Vec2(1.0, 1.0f);
		}
		else
		{
			this->m_shotLaunchVector = cocos2d::Vec2(-1.0, 1.0f);
		}

		(*this->m_pActions)[(int)ACTION::SHOT_CUSTOM_BULLET]->start();
	}
}

/**
* @desc �ړ�����
*/
void CPlayerCharacter::moveFunc()
{
	/*
	* ���͏���
	*�@������͓͂��͂ɂ��ړ��Ƃ����J�e�S���ň���
	*/
	this->inputFunc();

	//�A�N�V�����v�Z
	for (CAction* pAction : (*this->m_pActions))
	{
		pAction->update(this);
	}

	//�����v�Z
	for (CPhysical* pPhysical : (*m_pPhysicals))
	{
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

//�A�j���[�V��������
void CPlayerCharacter::animationFunc()
{
	//�A�j���[�V����
	(*this->m_pAnimations)[m_state]->update();
}

/**
* @desc ��ԂƂ̏Փ˔��菈��
*/
void CPlayerCharacter::collision()
{
	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas))
	{
		pArea->collision(this);
	}

	//�S�ẴL�����N�^�[�Ƃ̏Փ˔���
	std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();
	for (CCharacter* pChara : (*pCharacters))
	{
		//�L�����N�^�[�P�Ƃ̏Փ˔���
		this->collision(pChara);
	}
}

/**
* @desc ��ԃ`�F�b�N
* @tips �l���`�F�b�N���Č��݂̏�Ԃ�ύX����
*/
void CPlayerCharacter::checkState()
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
	
	//��Ԃ̔���
	if (this->m_pMove->m_vel.y > 0.0f)
	{
		//�����̑��x���v���X�Ƃ������Ƃ̓W�����v���Ă�����
		this->m_state = (int)STATE::JUMPING;
	}
	else if (this->m_pMove->m_vel.y < 0.0f)
	{
		//y���̑��x���}�C�i�X�Ƃ������Ƃ͗����Ă�����
		this->m_state = (int)STATE::FALING;
	}
	else if (this->m_pMove->m_vel.x != 0)
	{
		//�����Ă���
		this->m_state = (int)STATE::WALK;
	}
	else
	{
		//�����Ă���
		this->m_state = (int)STATE::STAND;
	}
}

/**
* @desc ���f����
*/
void CPlayerCharacter::applyFunc()
{
	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[m_state]->getCurrentChip());
}

/**
* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
* @param �L�����N�^�[�̃A�h���X
* @return true...�Փ˂���
*/
bool CPlayerCharacter::collision(CCharacter* pChara)
{
	//�G��������
	if (pChara->m_charaType == CHARACTER_TYPE::ENEMY||
		pChara->m_charaType == CHARACTER_TYPE::GIMMICK)
	{
		//���g�̏Փ˔���
		CCollisionRect myRect(*this->m_pBody, this->m_pMove->m_pos);

		//�G�̏Փ˔����`
		CCollisionRect eneRect(*pChara->m_pBody, pChara->m_pMove->m_pos);

		if (myRect.collision(&eneRect) == true)
		{
			//�Փ˔����̏���
			pChara->hits(this);

			return true;
		}
	}

	return false;
}

/**
* @desc �Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CPlayerCharacter::hits(CCharacter* pChara)
{

}