#include "PlayerCharacter.h"
#include "Model\Map\Map.h"
#include "Lib/Input/InputManager.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"

//コンストラクタ
CPlayerCharacter::CPlayerCharacter()
{
	//キャラクタータイプをプレイヤーキャラクターに設定
	this->m_charaType = CHARACTER_TYPE::PLAYER;

}
//デストラクタ
CPlayerCharacter::~CPlayerCharacter()
{

}

bool CPlayerCharacter::init()
{
	//キャラクタークラスの初期化
	if (CCharacter::init() == false)
	{
		CCLOG("CPlayerCharacter初期化に失敗");
		return false;
	}	

	return true;
}

void CPlayerCharacter::update(float deltaTime)
{
	//x軸の加速度の初期化
	this->m_pMove->m_accele.x = 0.0f;

	//キャラクターの更新処理呼び出し
	CCharacter::update(deltaTime);

}

/**
* @desc 入力処理
* @tips 移動処理で呼び出す
*/
void CPlayerCharacter::inputFunc()
{



}

/**
* @desc 移動処理
*/
void CPlayerCharacter::moveFunc()
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
			pointerPhysical->update(this->m_pMove);
		}
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CPlayerCharacter::animationFunc()
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
void CPlayerCharacter::collision()
{
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
void CPlayerCharacter::checkState()
{
	if (this->m_stateMachine)
	{
		//状態遷移マシンの更新
		this->m_stateMachine->update();
	}
	

	/*
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
	
	//状態の判定
	if (this->m_pMove->m_vel.y > 0.0f)
	{
		//ｙ軸の速度がプラスということはジャンプしている状態
		this->m_state = (int)STATE::JUMPING;
	}
	else if (this->m_pMove->m_vel.y < 0.0f)
	{
		//y軸の速度がマイナスということは落ちている状態
		this->m_state = (int)STATE::FALING;
	}
	else if (this->m_pMove->m_vel.x != 0)
	{
		//歩いている
		this->m_state = (int)STATE::WALK;
	}
	else
	{
		//立っている
		this->m_state = (int)STATE::STAND;
	}
	*/
}

/**
* @desc 反映処理
*/
void CPlayerCharacter::applyFunc()
{
	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect(this->m_mapAnimation[this->m_intAnimationState]->getCurrentChip());
}

/**
* @desc キャラクター1体との衝突判定処理
* @param キャラクターのアドレス
* @return true...衝突した
*/
bool CPlayerCharacter::collision(CCharacter* pChara)
{
	//敵だったら
	if (pChara->m_charaType == CHARACTER_TYPE::ENEMY||
		pChara->m_charaType == CHARACTER_TYPE::GIMMICK)
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
void CPlayerCharacter::hits(CCharacter* pChara)
{

}