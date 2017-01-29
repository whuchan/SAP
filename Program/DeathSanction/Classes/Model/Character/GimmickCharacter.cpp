#include "GimmickCharacter.h"
#include "PlayerCharacter.h"

#include "Model\Map\Map.h"

//�R���X�g���N�^
CGimmickCharacter::CGimmickCharacter()
{
	//�L�����N�^�[�^�C�v��G�L�����N�^�[�ɐݒ�
	this->m_charaType = CHARACTER_TYPE::GIMMICK;

}

//�f�X�g���N�^
CGimmickCharacter::~CGimmickCharacter()
{

}

//����������
bool CGimmickCharacter::init()
{
	//�L�����N�^�[�N���X�̏�����
	if (CCharacter::init() == false)
	{
		CCLOG("�M�~�b�N�L�����N�^�[�������Ɏ��s");
		return false;
	}

	return true;
}

/**
* @desc�@����������
* @param �����ʒuX
* @param �����ʒuY
*/
bool CGimmickCharacter::init(float posX, float posY)
{
	//�L�����N�^�[�N���X�̏�����
	if (CCharacter::init() == false)
	{
		CCLOG("�M�~�b�N�L�����N�^�[�������Ɏ��s");
		return false;
	}
	return true;
}


//�ړ�����
void CGimmickCharacter::moveFunc()
{
	// �A�N�V����
	if (this->m_mapAction[this->m_intActionState])
	{
		for (CAction* pointerAction : (*this->m_mapAction[this->m_intActionState]))
		{
			pointerAction->update(this);
		}
	}

	//�����v�Z
	if (this->m_mapPhysical[this->m_intPhysicalState])
	{
		for (CPhysical* pointerPhysical : (*this->m_mapPhysical[this->m_intPhysicalState]))
		{
			pointerPhysical->update(this->m_pMove);
		}
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

//�A�j���[�V��������
void CGimmickCharacter::animationFunc()
{
	//�A�j���[�V����
	if (this->m_mapAnimation[this->m_intAnimationState])
	{
		this->m_mapAnimation[this->m_intAnimationState]->update();
	}
}

/**
* @desc ��ԂƂ̏Փ˔��菈��
*/
void CGimmickCharacter::collision()
{
	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas))
	{
		pArea->collision(this);
	}

}

/**
* @desc ��ԃ`�F�b�N
* @tips �l���`�F�b�N���Č��݂̏�Ԃ�ύX����
*/
void CGimmickCharacter::checkState()
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
void CGimmickCharacter::applyFunc()
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
bool CGimmickCharacter::collision(CCharacter* pChara)
{	
	//����ł������΂�
	if (this->m_isAlive == false)
	{
		return false;
	}


	return true;
}


/**
* @desc �Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CGimmickCharacter::hits(CCharacter* pChara)
{
	if (pChara->m_charaType == CHARACTER_TYPE::PLAYER)
	{
		//���g�̏Փ˔���
		CCollisionRect rectGimmick(*this->m_pBody, this->m_pMove->m_pos);

		//�v���C���[�̏Փ˔����`
		CCollisionRect rectPlayer(*pChara->m_pBody, pChara->m_pMove->m_pos);

		if (rectGimmick.collision(&rectPlayer) == true)
		{
			//�Փ˔����̏���
			//pChara->hits(this);
			this->hitsPlayerCharacter(pChara);
		}
	}
}



/**
* @desc �v���C���[�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	//�v���C���[�̍����̈ʒu
	float floatPlayerLeftPositionX = pChara->m_pMove->m_pos.x + pChara->m_pBody->m_left;

	//�v���C���[�̉E���̈ʒu
	float floatPlayerRightPositionX = pChara->m_pMove->m_pos.x + pChara->m_pBody->m_right;

	//�v���C���[�̉����̈ʒu
	float floatPlayerBottomPositionY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

	//�v���C���[�̏㑤�̈ʒu
	float floatPlayerTopPositionY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_top;


	//�M�~�b�N�̒��S�ʒu
	float floatGimmickPositionX = this->m_pMove->m_pos.x;
	float floatGimmickPositionY = this->m_pMove->m_pos.y;
	


//	float floatPositionY = floatPlayerBottomPositionY - floatGimmickPositionY;

	
	//=====================================================================
	// �߂荞�񂾕��߂�
	//=====================================================================

	
	if (floatPlayerBottomPositionY - this->m_pMove->m_pos.y > 0.0f)
	{

		//�߂荞�񂾕��̌v�Z
		float boundary = floatPlayerBottomPositionY - (this->m_pMove->m_pos.y + this->m_pBody->m_top);

		//�ŏI�G�ɖ߂��l
		pChara->m_pMove->m_pos.y -= boundary;

		(*pChara->m_mapAction[pChara->m_intActionState])[0]->stop();

		//���Z�b�g����l
		pChara->m_pMove->m_vel.y = 0.0f;
		pChara->m_pMove->m_accele.y = 0.0f;

		pChara->m_state = (int)CPlayerCharacter::STATE::STAND;

		return;
	}
	
	if (floatPlayerTopPositionY - this->m_pMove->m_pos.y < 0.0f)
	{

		//�߂荞�񂾕��̌v�Z
		float boundary = floatPlayerTopPositionY - (this->m_pMove->m_pos.y + this->m_pBody->m_bottom);

		//�ŏI�G�ɖ߂��l
		pChara->m_pMove->m_pos.y -= boundary;

		//���Z�b�g����l
		pChara->m_pMove->m_vel.y = 0.0f;
		pChara->m_pMove->m_accele.y = 0.0f;
		return;
	}

	if (floatPlayerLeftPositionX - this->m_pMove->m_pos.x > 0.0f)
	{

		//�߂荞�񂾕��̌v�Z
		float floatBoundary = floatPlayerLeftPositionX - (this->m_pMove->m_pos.x + this->m_pBody->m_right);

		//�ŏI�G�ɖ߂��l
		pChara->m_pMove->m_pos.x -= floatBoundary;

		//���Z�b�g����l
		pChara->m_pMove->m_vel.x = 0.0f;
		pChara->m_pMove->m_accele.x = 0.0f;

		return;
	}


	if (floatPlayerRightPositionX - this->m_pMove->m_pos.x < 0.0f)
	{

		//�߂荞�񂾕��̌v�Z
		float floatBoundary = floatPlayerRightPositionX - (this->m_pMove->m_pos.x + this->m_pBody->m_left);

		//�ŏI�G�ɖ߂��l
		pChara->m_pMove->m_pos.x -= floatBoundary;

		//���Z�b�g����l
		pChara->m_pMove->m_vel.x = 0.0f;
		pChara->m_pMove->m_accele.x = 0.0f;

		return;
	}

}
