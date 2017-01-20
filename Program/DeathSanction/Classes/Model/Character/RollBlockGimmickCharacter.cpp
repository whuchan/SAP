#include"RollBlockGimmickCharacter.h"
#include "Model\Character\PlayerCharacter.h"


//コンストラクタ
CRollBlockGimmickCharacter::CRollBlockGimmickCharacter()
{


}

//デストラクタ
CRollBlockGimmickCharacter::~CRollBlockGimmickCharacter()
{

}

//状態チェック
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
* @desc プレイヤーとの衝突判定後の処理
* @param 衝突してきたキャラクタ-
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
* @desc 敵との衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CRollBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

