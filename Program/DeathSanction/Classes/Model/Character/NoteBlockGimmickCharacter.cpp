#include"NoteBlockGimmickCharacter.h"
#include"Model\Character\PlayerCharacter.h"
#include "Data\ActionController\ActionController.h"

//コンストラクタ
CNoteBlockGimmickCharacter::CNoteBlockGimmickCharacter()
{


}

//デストラクタ
CNoteBlockGimmickCharacter::~CNoteBlockGimmickCharacter()
{

}

//状態チェック
void CNoteBlockGimmickCharacter::checkState(float deltaTime)
{
	switch (this->m_state)
	{
	case STATE::NORMAL: this->m_pMove->m_pos.set(this->m_vec2BasePosition.x, this->m_vec2BasePosition.y);
						break;
	case STATE::HIT_TOP:
						this->m_pMove->m_pos.set(this->m_vec2BasePosition.x, this->m_vec2BasePosition.y - 5.0f);
						break;

	case STATE::HIT_BOTTOM:
						this->m_pMove->m_pos.set(this->m_vec2BasePosition.x, this->m_vec2BasePosition.y + 5.0f);
						break;
	}


	this->m_state = (int)STATE::NORMAL;
}


/**
* @desc プレイヤーとの衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CNoteBlockGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{


	CGimmickCharacter::hitsPlayerCharacter(pChara);

	if (pChara->m_pMove->m_pos.y > this->m_pMove->m_pos.y + this->m_pBody->m_top)
	{
		//=====================================================================
		// ジャンプアクションの再起動
		//=====================================================================
		//ジャンプアクションの再起動
		CActionJump* pAction = (CActionJump*)(*pChara->m_mapAction[pChara->m_intActionState])[0];
		pAction->m_floatCorrectionValue = 1.5f;

		(*pChara->m_mapAction[pChara->m_intActionState])[0]->restart(pChara);

		this->m_state = (int)STATE::HIT_TOP;
	}
	else if (pChara->m_pMove->m_pos.y < this->m_pMove->m_pos.y + this->m_pBody->m_bottom)
	{
		this->m_state = (int)STATE::HIT_BOTTOM;
	}

	
}

/**
* @desc 敵との衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CNoteBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

