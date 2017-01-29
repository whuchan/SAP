#include "GimmickCharacter.h"
#include "PlayerCharacter.h"

#include "Model\Map\Map.h"

//コンストラクタ
CGimmickCharacter::CGimmickCharacter()
{
	//キャラクタータイプを敵キャラクターに設定
	this->m_charaType = CHARACTER_TYPE::GIMMICK;

}

//デストラクタ
CGimmickCharacter::~CGimmickCharacter()
{

}

//初期化処理
bool CGimmickCharacter::init()
{
	//キャラクタークラスの初期化
	if (CCharacter::init() == false)
	{
		CCLOG("ギミックキャラクター初期化に失敗");
		return false;
	}

	return true;
}

/**
* @desc　初期化処理
* @param 初期位置X
* @param 初期位置Y
*/
bool CGimmickCharacter::init(float posX, float posY)
{
	//キャラクタークラスの初期化
	if (CCharacter::init() == false)
	{
		CCLOG("ギミックキャラクター初期化に失敗");
		return false;
	}
	return true;
}


//移動処理
void CGimmickCharacter::moveFunc()
{
	// アクション
	if (this->m_mapAction[this->m_intActionState])
	{
		for (CAction* pointerAction : (*this->m_mapAction[this->m_intActionState]))
		{
			pointerAction->update(this);
		}
	}

	//物理計算
	if (this->m_mapPhysical[this->m_intPhysicalState])
	{
		for (CPhysical* pointerPhysical : (*this->m_mapPhysical[this->m_intPhysicalState]))
		{
			pointerPhysical->update(this->m_pMove);
		}
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CGimmickCharacter::animationFunc()
{
	//アニメーション
	if (this->m_mapAnimation[this->m_intAnimationState])
	{
		this->m_mapAnimation[this->m_intAnimationState]->update();
	}
}

/**
* @desc 空間との衝突判定処理
*/
void CGimmickCharacter::collision()
{
	//空間との衝突判定を行う
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas))
	{
		pArea->collision(this);
	}

}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
void CGimmickCharacter::checkState()
{
	//向きの判定
	if (this->m_pMove->m_vel.x != 0)
	{
		if (this->m_pMove->m_vel.x > 0)
		{
			//右向きに設定
			this->setScale(1.0f, 1.0f);
		}
		else
		{
			//左向きに設定
			this->setScale(-1.0f, 1.0f);
		}
	}
}

//反映処理
void CGimmickCharacter::applyFunc()
{
	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect(this->m_mapAnimation[this->m_intAnimationState]->getCurrentChip());

}


/**
* @desc キャラクター１体との衝突判定処理
* @param キャラクターのアドレス
* @return true...衝突した
*/
bool CGimmickCharacter::collision(CCharacter* pChara)
{	
	//死んでいたら飛ばす
	if (this->m_isAlive == false)
	{
		return false;
	}


	return true;
}


/**
* @desc 衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CGimmickCharacter::hits(CCharacter* pChara)
{
	if (pChara->m_charaType == CHARACTER_TYPE::PLAYER)
	{
		//自身の衝突判定
		CCollisionRect rectGimmick(*this->m_pBody, this->m_pMove->m_pos);

		//プレイヤーの衝突判定矩形
		CCollisionRect rectPlayer(*pChara->m_pBody, pChara->m_pMove->m_pos);

		if (rectGimmick.collision(&rectPlayer) == true)
		{
			//衝突判定後の処理
			//pChara->hits(this);
			this->hitsPlayerCharacter(pChara);
		}
	}
}



/**
* @desc プレイヤーとの衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	//プレイヤーの左側の位置
	float floatPlayerLeftPositionX = pChara->m_pMove->m_pos.x + pChara->m_pBody->m_left;

	//プレイヤーの右側の位置
	float floatPlayerRightPositionX = pChara->m_pMove->m_pos.x + pChara->m_pBody->m_right;

	//プレイヤーの下側の位置
	float floatPlayerBottomPositionY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

	//プレイヤーの上側の位置
	float floatPlayerTopPositionY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_top;


	//ギミックの中心位置
	float floatGimmickPositionX = this->m_pMove->m_pos.x;
	float floatGimmickPositionY = this->m_pMove->m_pos.y;
	


//	float floatPositionY = floatPlayerBottomPositionY - floatGimmickPositionY;

	
	//=====================================================================
	// めり込んだ分戻す
	//=====================================================================

	
	if (floatPlayerBottomPositionY - this->m_pMove->m_pos.y > 0.0f)
	{

		//めり込んだ分の計算
		float boundary = floatPlayerBottomPositionY - (this->m_pMove->m_pos.y + this->m_pBody->m_top);

		//最終敵に戻す値
		pChara->m_pMove->m_pos.y -= boundary;

		(*pChara->m_mapAction[pChara->m_intActionState])[0]->stop();

		//リセットする値
		pChara->m_pMove->m_vel.y = 0.0f;
		pChara->m_pMove->m_accele.y = 0.0f;

		pChara->m_state = (int)CPlayerCharacter::STATE::STAND;

		return;
	}
	
	if (floatPlayerTopPositionY - this->m_pMove->m_pos.y < 0.0f)
	{

		//めり込んだ分の計算
		float boundary = floatPlayerTopPositionY - (this->m_pMove->m_pos.y + this->m_pBody->m_bottom);

		//最終敵に戻す値
		pChara->m_pMove->m_pos.y -= boundary;

		//リセットする値
		pChara->m_pMove->m_vel.y = 0.0f;
		pChara->m_pMove->m_accele.y = 0.0f;
		return;
	}

	if (floatPlayerLeftPositionX - this->m_pMove->m_pos.x > 0.0f)
	{

		//めり込んだ分の計算
		float floatBoundary = floatPlayerLeftPositionX - (this->m_pMove->m_pos.x + this->m_pBody->m_right);

		//最終敵に戻す値
		pChara->m_pMove->m_pos.x -= floatBoundary;

		//リセットする値
		pChara->m_pMove->m_vel.x = 0.0f;
		pChara->m_pMove->m_accele.x = 0.0f;

		return;
	}


	if (floatPlayerRightPositionX - this->m_pMove->m_pos.x < 0.0f)
	{

		//めり込んだ分の計算
		float floatBoundary = floatPlayerRightPositionX - (this->m_pMove->m_pos.x + this->m_pBody->m_left);

		//最終敵に戻す値
		pChara->m_pMove->m_pos.x -= floatBoundary;

		//リセットする値
		pChara->m_pMove->m_vel.x = 0.0f;
		pChara->m_pMove->m_accele.x = 0.0f;

		return;
	}

}
