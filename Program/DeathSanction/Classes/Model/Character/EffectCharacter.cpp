#include "EffectCharacter.h"
#include "Lib\Input\InputManager.h"
#include "Model\Map\Map.h"

//�R���X�g���N�^
CEffectCharacter::CEffectCharacter()
{
	//�L�����N�^�[�^�C�v���_���[�W�L�����N�^�[�ɐݒ�
	this->m_charaType = CHARACTER_TYPE::EFFECT;

}

//�f�X�g���N�^
CEffectCharacter::~CEffectCharacter()
{

}

//����������
bool CEffectCharacter::init()
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
bool CEffectCharacter::init(float posX, float posY)
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
void CEffectCharacter::moveFunction(float deltaTime)
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
void CEffectCharacter::animationFunction(float deltaTime)
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
void CEffectCharacter::collision()
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
void CEffectCharacter::checkState(float deltaTime)
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
void CEffectCharacter::applayFunction()
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
bool CEffectCharacter::collision(CCharacter* pChara)
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
void CEffectCharacter::hits(CCharacter* pChara)
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
		//��������
		CCLOG("Lose");
	}
}


/**
* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CEffectCharacter::collisionBottomCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}

/**
* @desc ��̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CEffectCharacter::collisionTopCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}

/**
* @desc �E�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CEffectCharacter::collisionRightCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}

/**
* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CEffectCharacter::collisionLeftCallback(int event)
{
	//�L���t���O��������
	this->m_activeFlag = false;
}