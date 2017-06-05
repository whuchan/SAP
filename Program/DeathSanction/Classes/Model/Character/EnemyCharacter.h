#pragma once
#include "Character.h"

//======================================================
//
// 敵キャラクターの基底クラスとなるクラス
//
//======================================================
template <class T>
class CEnemyCharacter : public CCharacter
{
public:
	//コンストラクタ
	CEnemyCharacter()
	{
		//キャラクタータイプを敵キャラクターに設定
		this->m_charaType = CHARACTER_TYPE::ENEMY;
	}

	//デストラクタ
	virtual ~CEnemyCharacter()
	{

	}

	//初期化処理
	bool init()
	{
		//キャラクタークラスの初期化
		if (CCharacter::init() == false)
		{
			CCLOG("プレイヤーキャラクター初期化に失敗");
			return false;
		}

		return true;
	}

	/**
	* @desc　初期化処理
	* @param 初期位置X
	* @param 初期位置Y
	* @tips create()メンバ関数の中でinit()メンバ関数を呼び出しているが
	* 今回、そのcreate()メンバ関数をオーバーロードして
	* 引数を受け取っているのでinit()メンバ関数も
	* オーバーロードする必要がある
	*/
	bool init(float posX, float posY)
	{
		//キャラクタークラスの初期化
		if (CCharacter::init() == false)
		{
			CCLOG("敵キャラクター初期化に失敗");
			return false;
		}
		return true;
	}

	/**
	* @desc CREATE_FUNC
	* @tips 前回は敵出撃データという敵専用のクラスが存在していたので
	* このクラスに直書きしても問題は生じなかったが
	* 今回はマップの情報による出撃位置の決定という項目が必要になる
	* マップをシングルトン化　したので直書きしても問題ないように思われるが
	* 最終的に必要となるのは位置だけだ
	* なので生成と同時に位置を取得したい
	* だがしかし、cocos2dxの機能である自動でdeleteの機能も使いたい
	* なのでcreate静的メンバ関数をカスタマイズする
	*/
	//CREATE_FUNC(CEnemyCharacter);
	static  T* create()
	{
		T* pRet = new(std::nothrow)T();
		if (pRet&&pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

	/**
	* @desc CREATE_FUNCマクロをオーバーライド
	* @param 初期位置X
	* @param 初期位置Y
	* @tips 初期位置を必要とするのは生成の段階ではなく
	*       initの段階である
	*/
	static T* create(float posX,float posY)
	{
		T* pRet = new(std::nothrow)T();
		if (pRet&&pRet->init(posX,posY))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

	//移動処理
	void moveFunction(float deltaTime)
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
	void animationFunction(float deltaTime)
	{
		//アニメーション
		if (this->m_mapAnimation[this->m_intAnimationState])
		{
			this->m_mapAnimation[this->m_intAnimationState]->update();
		}
	}

	//空間との衝突判定処理
	virtual void collision()
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
	}

	//状態チェック
	void checkState(float deltaTime)
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
	void applayFunction()
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
	bool collision(CCharacter* pChara)
	{
		return true;
	}
	
	/**
	* @desc 衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	void hits(CCharacter* pChara)
	{
		//死んでいたら飛ばす
		if (this->m_isAlive == false)
		{
			return;
		}

		switch (pChara->m_charaType)
		{
			//プレイヤーだった場合
		case CHARACTER_TYPE::PLAYER:	this->hitsPlayerCharacter(pChara);
			break;

			//弾だった場合
		case CHARACTER_TYPE::BULLET:	this->hitsBulletCharacter(pChara);
			break;
		default:break;
		}
	}

protected:

	/**
	* @desc プレイヤーとの衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsPlayerCharacter(CCharacter* pChara)
	{
		//プレイヤーの足下の位置
		float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

		//敵の中心位置
		float enePosY = this->m_pMove->m_pos.y;

		//敵より上かどうか
		float posY = playerFeetPosY - enePosY;
		if (posY > 0.0f)
		{

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

		}
	}

	/**
	* @desc 弾との衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hitsBulletCharacter(CCharacter* pChara)
	{
		//弾の有効フラグを下げる
		pChara->m_activeFlag = false;

		//敵の死亡フラグを立てる
		//つまり生きていいるか死んでいるかのフラグにfalseを入れる
		this->m_isAlive = false;

		//敵死亡アクションを起動する
		(*this->m_mapAction[this->m_intActionState])[0]->start();
	}

};