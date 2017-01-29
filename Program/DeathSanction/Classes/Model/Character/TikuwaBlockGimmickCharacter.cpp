#include"TikuwaBlockGimmickCharacter.h"


//コンストラクタ
CTikuwaBlockGimmickCharacter::CTikuwaBlockGimmickCharacter()
{
	
}

//デストラクタ
CTikuwaBlockGimmickCharacter::~CTikuwaBlockGimmickCharacter()
{

}

//状態チェック
void CTikuwaBlockGimmickCharacter::checkState()
{




	if (this->m_state == (int)STATE::FALL)
	{
		//下に画面端があるかどうかをチェック
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
* @desc プレイヤーとの衝突判定後の処理
* @param 衝突してきたキャラクタ-
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
* @desc 敵との衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CTikuwaBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

