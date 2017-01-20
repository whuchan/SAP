#include"RollBlockGimmickCharacter.h"
#include "Model\Character\PlayerCharacter.h"


//�R���X�g���N�^
CRollBlockGimmickCharacter::CRollBlockGimmickCharacter()
{


}

//�f�X�g���N�^
CRollBlockGimmickCharacter::~CRollBlockGimmickCharacter()
{

}

//��ԃ`�F�b�N
void CRollBlockGimmickCharacter::checkState()
{
	if (this->m_state == (int)STATE::THROUGH)
	{
		if (this->m_intInterval > 0)
		{
			this->m_intInterval--;
		}
		else
		{
			if ((*this->m_pAnimations)[this->m_intAnimationState]->getCurrentFrame()==3)
			{
				this->m_state = (int)STATE::NORMAL;
				this->m_intAnimationState = (int)STATE::NORMAL;
			}
		}
	}
}



/**
* @desc �v���C���[�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CRollBlockGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	if (this->m_state == (int)STATE::THROUGH)
	{
		return;
	}

	CGimmickCharacter::hitsPlayerCharacter(pChara);
	

	if (pChara->m_pMove->m_pos.y < this->m_pMove->m_pos.y + this->m_pBody->m_bottom)
	{
		if (this->m_state == (int)STATE::NORMAL && pChara->m_state == (int)CPlayerCharacter::STATE::JUMPING)
		{
			this->m_intInterval = 120;
			this->m_state = (int)STATE::THROUGH;
			this->m_intAnimationState = (int)STATE::THROUGH;
		}
	}

}

/**
* @desc �G�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CRollBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

