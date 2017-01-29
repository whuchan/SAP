#include"TikuwaBlockGimmickCharacter.h"


//�R���X�g���N�^
CTikuwaBlockGimmickCharacter::CTikuwaBlockGimmickCharacter()
{
	
}

//�f�X�g���N�^
CTikuwaBlockGimmickCharacter::~CTikuwaBlockGimmickCharacter()
{

}

//��ԃ`�F�b�N
void CTikuwaBlockGimmickCharacter::checkState()
{




	if (this->m_state == (int)STATE::FALL)
	{
		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((this->m_pMove->m_pos.y + this->m_pBody->m_top) < WINDOW_BOTTOM)
		{
			this->m_pMove->m_pos.set(this->m_vec2BasePosition);
			this->m_state = (int)STATE::NORMAL;

			this->m_pMove->m_vel.setZero();
		}

		return;
	}



	if (this->m_state == (int)STATE::ON)
	{
		this->m_intShakeActionCounter++;

		if (this->m_intShakeActionCounter >= 5)
		{
			this->m_intShakeActionCounter = 0;

			this->m_floatShakeVector *= -1.0f;

			this->m_pMove->m_pos.set(this->m_vec2BasePosition.x + this->m_floatShakeVector, this->m_pMove->m_pos.y);
		}
	}
	else
	{
		this->m_pMove->m_pos.set(this->m_vec2BasePosition.x,this->m_pMove->m_pos.y);
		this->m_intShakeActionCounter = 0;
		this->m_intHitInterval = 0;
	}
	this->m_state = (int)STATE::NORMAL;
}




/**
* @desc �v���C���[�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CTikuwaBlockGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	CGimmickCharacter::hitsPlayerCharacter(pChara);

	if (pChara->m_pMove->m_pos.y > this->m_pMove->m_pos.y + this->m_pBody->m_top)
	{
		if (this->m_intHitInterval > 60)
		{
			this->m_state = (int)STATE::FALL;

		}
		else
		{
			this->m_state = (int)STATE::ON;
			this->m_intHitInterval++;
		}
	}
	else
	{
		this->m_intHitInterval = 0;
	}
}

/**
* @desc �G�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CTikuwaBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

