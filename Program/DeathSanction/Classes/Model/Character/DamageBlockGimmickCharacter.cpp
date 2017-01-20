#include"DamageBlockGimmickCharacter.h"


//コンストラクタ
CDamageBlockGimmickCharacter::CDamageBlockGimmickCharacter()
{


}

//デストラクタ
CDamageBlockGimmickCharacter::~CDamageBlockGimmickCharacter()
{

}

/**
* @desc プレイヤーとの衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CDamageBlockGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	CGimmickCharacter::hitsPlayerCharacter(pChara);
	
	CCLOG("死にました");
}

/**
* @desc 敵との衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CDamageBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

