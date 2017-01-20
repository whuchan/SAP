#include "BulletCharacter.h"
#include "Lib\Input\InputManager.h"
#include "Model\Map\Map.h"

//�R���X�g���N�^
CBulletCharacter::CBulletCharacter()
{
	//�L�����N�^�[�^�C�v��G�L�����N�^�[�ɐݒ�
	this->m_charaType = CHARACTER_TYPE::BULLET;

}

//�f�X�g���N�^
CBulletCharacter::~CBulletCharacter()
{

}

//����������
bool CBulletCharacter::init()
{
	//�L�����N�^�[�N���X�̏�����
	if (CCharacter::init() == false)
	{
		CCLOG("�e�L�����N�^�[�������Ɏ��s");
		return false;
	}

	return true;
}

/**
* @desc�@����������
* @param �����ʒuX
* @param �����ʒuY
*/
bool CBulletCharacter::init(float posX, float posY)
{
	//�L�����N�^�[�N���X�̏�����
	if (CCharacter::init() == false)
	{
		CCLOG("�G�L�����N�^�[�������Ɏ��s");
		return false;
	}
	return true;
}


//�ړ�����
void CBulletCharacter::moveFunc()
{
	//���t�����Ă���A�N�V�����̍X�V
	for (CAction* pAction : (*m_pActions))
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
void CBulletCharacter::animationFunc()
{
	//�A�j���[�V����
	(*this->m_pAnimations)[this->m_state]->update();
}

/**
* @desc ��ԂƂ̏Փ˔��菈��
*/
void CBulletCharacter::collision()
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
void CBulletCharacter::checkState()
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
void CBulletCharacter::applyFunc()
{
	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[this->m_state]->getCurrentChip());

}


/**
* @desc �L�����N�^�[�P�̂Ƃ̏Փ˔��菈��
* @param �L�����N�^�[�̃A�h���X
* @return true...�Փ˂���
*/
bool CBulletCharacter::collision(CCharacter* pChara)
{
	//�G��������
	if (pChara->m_charaType == CHARACTER_TYPE::ENEMY)
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
void CBulletCharacter::hits(CCharacter* pChara)
{
	//����ł������΂�
	if (this->m_isAlive == false)
	{
		return;
	}

	//�v���C���[�̑����̈ʒu
	float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

	//�G�̒��S�ʒu
	float enePosY = this->m_pMove->m_pos.y;

	//�G���ォ�ǂ���
	float posY = playerFeetPosY - enePosY;
	if (posY > 0.0f)
	{
		//�ゾ����
		CCLOG("Win");

		//�G�̎��S�t���O�𗧂Ă�
		//�܂萶���Ă����邩����ł��邩�̃t���O��false������
		this->m_isAlive = false;

		//�G���S�A�N�V�������N������
		(*this->m_pActions)[0]->start();

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
		(*pChara->m_pActions)[0]->restart(pChara);

	}
	else
	{
		//��������
		CCLOG("Lose");
	}
}


/**
* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CBulletCharacter::collisionBottomCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}

/**
* @desc ��̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CBulletCharacter::collisionTopCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}

/**
* @desc �E�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CBulletCharacter::collisionRightCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}

/**
* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CBulletCharacter::collisionLeftCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}