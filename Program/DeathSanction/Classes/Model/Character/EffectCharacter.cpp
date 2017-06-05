#include "EffectCharacter.h"
#include "Lib\Input\InputManager.h"
#include "Model\Map\Map.h"

//コンストラクタ
CEffectCharacter::CEffectCharacter()
{
	//キャラクタータイプをダメージキャラクターに設定
	this->m_charaType = CHARACTER_TYPE::EFFECT;

}

//デストラクタ
CEffectCharacter::~CEffectCharacter()
{

}

//初期化処理
bool CEffectCharacter::init()
{
	//キャラクタークラスの初期化
	if (CCharacter::init() == false)
	{
		CCLOG("弾キャラクター初期化に失敗");
		return false;
	}

	return true;
}

/**
* @desc　初期化処理
* @param 初期位置X
* @param 初期位置Y
*/
bool CEffectCharacter::init(float posX, float posY)
{
	//キャラクタークラスの初期化
	if (CCharacter::init() == false)
	{
		CCLOG("敵キャラクター初期化に失敗");
		return false;
	}
	return true;
}


//移動処理
void CEffectCharacter::moveFunction(float deltaTime)
{
	// アクション
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

	//物理計算
	if (this->m_mapPhysical[this->m_intPhysicalState])
	{
		for (CPhysical* pointerPhysical : (*this->m_mapPhysical[this->m_intPhysicalState]))
		{
			pointerPhysical->update(deltaTime, this->m_pMove);
		}
	}
	//移動計算
	this->m_pMove->moveBy(deltaTime);
}

//アニメーション処理
void CEffectCharacter::animationFunction(float deltaTime)
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
void CEffectCharacter::collision()
{
	//死んでいたら飛ばす
	if (this->m_isAlive == false)
	{
		return;
	}

	//空間との衝突判定を行う
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas))
	{
		pArea->collision(this);
	}

	//全てのキャラクターとの衝突判定
	std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();
	for (CCharacter* pChara : (*pCharacters))
	{
		//キャラクター１との衝突判定
		this->collision(pChara);
	}
}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
void CEffectCharacter::checkState(float deltaTime)
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
void CEffectCharacter::applayFunction()
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
bool CEffectCharacter::collision(CCharacter* pChara)
{
	//敵だったら
	if (pChara->m_charaType == CHARACTER_TYPE::ENEMY)
	{
		//自身の衝突判定
		CCollisionRect myRect(*this->m_pBody, this->m_pMove->m_pos);

		//敵の衝突判定矩形
		CCollisionRect eneRect(*pChara->m_pBody, pChara->m_pMove->m_pos);

		if (myRect.collision(&eneRect) == true)
		{
			//衝突判定後の処理
			pChara->hits(this);

			return true;
		}
	}

	return false;
}


/**
* @desc 衝突判定後の処理
* @param 衝突してきたキャラクタ-
*/
void CEffectCharacter::hits(CCharacter* pChara)
{
	//死んでいたら飛ばす
	if (this->m_isAlive == false)
	{
		return;
	}

	//プレイヤーの足下の位置
	float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

	//敵の中心位置
	float enePosY = this->m_pMove->m_pos.y;

	//敵より上かどうか
	float posY = playerFeetPosY - enePosY;
	if (posY > 0.0f)
	{
		//上だった
		CCLOG("Win");

		//敵の死亡フラグを立てる
		//つまり生きていいるか死んでいるかのフラグにfalseを入れる
		this->m_isAlive = false;

		//敵死亡アクションを起動する
		(*this->m_mapAction[this->m_intActionState])[0]->start();

		//=====================================================================
		// めり込んだ分戻す
		//=====================================================================
		//めり込んだ分の計算
		float boundary = playerFeetPosY - (this->m_pMove->m_pos.y + this->m_pBody->m_top);

		//最終敵に戻す値
		pChara->m_pMove->m_pos.y -= boundary;

		//=====================================================================
		// ジャンプアクションの再起動
		//=====================================================================
		//ジャンプアクションの再起動
		(*pChara->m_mapAction[pChara->m_intActionState])[0]->restart(pChara);

	}
	else
	{
		//下だった
		CCLOG("Lose");
	}
}


/**
* @desc 下領域と衝突した際のイベントコールバック
* @param マップチップID
* 画面端の際は０
*/
void CEffectCharacter::collisionBottomCallback(int event)
{
	//有効フラグを下げる
	this->m_activeFlag = false;
}

/**
* @desc 上領域と衝突した際のイベントコールバック
* @param マップチップID
* 画面端の際は０
*/
void CEffectCharacter::collisionTopCallback(int event)
{
	//有効フラグを下げる
	this->m_activeFlag = false;
}

/**
* @desc 右領域と衝突した際のイベントコールバック
* @param マップチップID
* 画面端の際は０
*/
void CEffectCharacter::collisionRightCallback(int event)
{
	//有効フラグを下げる
	this->m_activeFlag = false;
}

/**
* @desc 左領域と衝突した際のイベントコールバック
* @param マップチップID
* 画面端の際は０
*/
void CEffectCharacter::collisionLeftCallback(int event)
{
	//有効フラグを下げる
	this->m_activeFlag = false;
}