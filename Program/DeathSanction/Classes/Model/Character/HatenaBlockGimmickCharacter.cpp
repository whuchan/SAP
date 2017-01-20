#include"HatenaBlockGimmickCharacter.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"
#include "Model\Character\PlayerCharacter.h"


//コンストラクタ
CHatenaBlockGimmickCharacter::CHatenaBlockGimmickCharacter()
{


}

//デストラクタ
CHatenaBlockGimmickCharacter::~CHatenaBlockGimmickCharacter()
{

}


/**
* @desc プレイヤーとの衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CHatenaBlockGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	CGimmickCharacter::hitsPlayerCharacter(pChara);

	if (pChara->m_pMove->m_pos.y < this->m_pMove->m_pos.y + this->m_pBody->m_bottom)
	{
		if (this->m_state == (int)STATE::NONE && pChara->m_state == (int)CPlayerCharacter::STATE::JUMPING)
		{
			//==================================
			// ここでは出撃の情報を出撃トリガーとして
			// 出撃スケジューラーに取り付けるだけ
			//==================================
			//敵出撃データ（出撃の情報）の生成
			CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
				ENEMY_TYPE::NOKONOKO,
				this->m_pMove->m_pos
			);

			//出撃トリガーを生成し、敵出撃データを設定
			CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

			//出撃トリガーを出撃スケジュールとして追加する
			CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

			this->m_state = (int)STATE::USED;
			this->m_intAnimationState = (int)STATE::USED;
		}
	}
}

/**
* @desc 敵との衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CHatenaBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

