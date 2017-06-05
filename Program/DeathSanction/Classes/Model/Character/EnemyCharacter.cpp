//#include "EnemyCharacter.h"
//#include "Lib\Input\InputManager.h"
//#include "Model\Map\Map.h"
//
////コンストラクタ
//CEnemyCharacter::CEnemyCharacter()
//{
//	//キャラクタータイプを敵キャラクターに設定
//	this->m_charaType = CHARACTER_TYPE::ENEMY;
//
//}
//
////デストラクタ
//CEnemyCharacter::~CEnemyCharacter()
//{
//
//}
//
////初期化処理
//bool CEnemyCharacter::init()
//{
//	//キャラクタークラスの初期化
//	if (CCharacter::init() == false)
//	{
//		CCLOG("プレイヤーキャラクター初期化に失敗");
//		return false;
//	}
//
//	return true;
//}
//
///**
//* @desc　初期化処理
//* @param 初期位置X
//* @param 初期位置Y
//*/
//bool CEnemyCharacter::init(float posX, float posY)
//{
//	//キャラクタークラスの初期化
//	if (CCharacter::init() == false)
//	{
//		CCLOG("敵キャラクター初期化に失敗");
//		return false;
//	}
//	return true;
//}
//
//
////移動処理
//void CEnemyCharacter::moveFunction(float deltaTime)
//{
//	// アクション
//	if (this->m_mapAction[this->m_intActionState])
//	{
//		std::map<int, CAction*>::iterator itaratorAction = this->m_mapAction[this->m_intActionState]->begin();
//
//		while (itaratorAction != this->m_mapAction[this->m_intActionState]->end())
//		{
//			if (itaratorAction->second)
//			{
//				itaratorAction->second->update(this);
//			}
//			itaratorAction++;
//		}
//	}
//
//	//物理計算
//	if (this->m_mapPhysical[this->m_intPhysicalState])
//	{
//		for (CPhysical* pointerPhysical : (*this->m_mapPhysical[this->m_intPhysicalState]))
//		{
//			pointerPhysical->update(deltaTime,this->m_pMove);
//		}
//	}
//
//	//移動計算
//	this->m_pMove->moveBy(deltaTime);
//}
//
////アニメーション処理
//void CEnemyCharacter::animationFunction(float deltaTime)
//{
//	//アニメーション
//	if (this->m_mapAnimation[this->m_intAnimationState])
//	{
//		this->m_mapAnimation[this->m_intAnimationState]->update();
//	}
//}
//
///**
//* @desc 空間との衝突判定処理
//*/
//void CEnemyCharacter::collision()
//{
//	//死んでいたら飛ばす
//	if (this->m_isAlive == false)
//	{
//		return;
//	}
//
//	//空間との衝突判定を行う
//	for (CCollisionArea* pArea : (*this->m_pCollisionAreas))
//	{
//		pArea->collision(this);
//	}
//}
//
///*
//* @desc 画面範囲端判定処理
//* @tips まだ削除の処理を作成していないので画面下で止める処理のみ実装しておく
//
//void CEnemyCharacter::endOfScreen()
//{
//	cocos2d::Vec2* pPos = &this->m_pMove->m_pos;
//	cocos2d::Vec2* pVel = &this->m_pMove->m_vel;
//	cocos2d::Vec2* pAccele = &this->m_pMove->m_accele;
//
//	//画面下で止めるようにする
//	if (pVel->y < 0.0f && pPos->y + this->m_pBody->m_bottom < WINDOW_BOTTOM)
//	{
//		//設定修正値
//		float boundary = (pPos->y + this->m_pBody->m_bottom) - WINDOW_BOTTOM;
//		pPos->y -= boundary;
//
//		//速度と加速度を０にする
//		pVel->y = 0.0f;
//		pAccele->y = 0.0f;
//	}
//}
//*/
///**
//* @desc 状態チェック
//* @tips 値をチェックして現在の状態を変更する
//*/
//void CEnemyCharacter::checkState(float deltaTime)
//{
//	//向きの判定
//	if (this->m_pMove->m_vel.x != 0)
//	{
//		if (this->m_pMove->m_vel.x > 0)
//		{
//			//右向きに設定
//			this->setScale(1.0f, 1.0f);
//		}
//		else
//		{
//			//左向きに設定
//			this->setScale(-1.0f, 1.0f);
//		}
//	}
//}
//
////反映処理
//void CEnemyCharacter::applayFunction()
//{
//	//位置データを反映
//	this->setPosition(this->m_pMove->m_pos);
//
//	//チップデータを反映
//	this->setTextureRect(this->m_mapAnimation[this->m_intAnimationState]->getCurrentChip());
//
//}
//
//
///**
//* @desc キャラクター１体との衝突判定処理
//* @param キャラクターのアドレス
//* @return true...衝突した
//*/
//bool CEnemyCharacter::collision(CCharacter* pChara)
//{
//	return true;
//}
//
//
///**
//* @desc 衝突判定後の処理
//* @param 衝突してきたキャラクタ-
//*/
//void CEnemyCharacter::hits(CCharacter* pChara)
//{
//	//死んでいたら飛ばす
//	if (this->m_isAlive == false)
//	{
//		return;
//	}
//
//	switch (pChara->m_charaType)
//	{
//	//プレイヤーだった場合
//	case CHARACTER_TYPE::PLAYER:	this->hitsPlayerCharacter(pChara);
//									break;
//
//	//弾だった場合
//	case CHARACTER_TYPE::BULLET:	this->hitsBulletCharacter(pChara);
//									break;
//	default:break;
//	}
//
//}
//
//
///**
//* @desc プレイヤーとの衝突判定後の処理
//* @param 衝突してきたキャラクタ-
//*/
//void CEnemyCharacter::hitsPlayerCharacter(CCharacter* pChara)
//{
//	//プレイヤーの足下の位置
//	float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;
//
//	//敵の中心位置
//	float enePosY = this->m_pMove->m_pos.y;
//
//	//敵より上かどうか
//	float posY = playerFeetPosY - enePosY;
//	if (posY > 0.0f)
//	{
//	
//		//敵の死亡フラグを立てる
//		//つまり生きていいるか死んでいるかのフラグにfalseを入れる
//		this->m_isAlive = false;
//
//		//敵死亡アクションを起動する
//		(*this->m_mapAction[this->m_intActionState])[0]->start();
//
//		//=====================================================================
//		// めり込んだ分戻す
//		//=====================================================================
//		//めり込んだ分の計算
//		float boundary = playerFeetPosY - (this->m_pMove->m_pos.y + this->m_pBody->m_top);
//
//		//最終敵に戻す値
//		pChara->m_pMove->m_pos.y -= boundary;
//
//		//=====================================================================
//		// ジャンプアクションの再起動
//		//=====================================================================
//		//ジャンプアクションの再起動
//		(*pChara->m_mapAction[pChara->m_intActionState])[0]->restart(pChara);
//
//	}
//	else
//	{
//	
//	}
//}
//
///**
//* @desc 弾との衝突判定後の処理
//* @param 衝突してきたキャラクタ-
//*/
//void CEnemyCharacter::hitsBulletCharacter(CCharacter* pChara)
//{
//	//弾の有効フラグを下げる
//	pChara->m_activeFlag = false;
//
//	//敵の死亡フラグを立てる
//	//つまり生きていいるか死んでいるかのフラグにfalseを入れる
//	this->m_isAlive = false;
//
//	//敵死亡アクションを起動する
//	(*this->m_mapAction[this->m_intActionState])[0]->start();
//}
//
//
///**
//* @desc マップとの衝突判定処理
//* @return true...衝突した
//
//bool CEnemyCharacter::collisionMap()
//{
//	//マップを取得
//	CMap* pMap = CMapManager::getInstance()->getMap();
//
//	//状態で判定するので一旦状態のチェックを行う
//	this->checkState();
//
//	//下に移動している場合に下に障害物があったら上に戻す
//	if (this->m_pMove->m_vel.y < 0)
//	{
//		//キャラクターの中心位置から真下にある点の座標を取得
//		cocos2d::Point pt(this->m_pMove->m_pos.x, this->m_pMove->m_pos.y + this->m_pBody->m_bottom);
//
//		/*
//		* 点が画面のどの座標にあるかを調べてその座標に
//		* マップチップが存在するかを調べマップチップが存在していたら
//		* trueを返す
//		
//		if (pMap->hitTest(pt.x, pt.y))
//		{
//			//ブロックのタイプを取得
//			BLOCK_TYPE mapChipID = pMap->checkTile(pt.x,pt.y);
//
//			if (mapChipID != BLOCK_TYPE::NONE)
//			{
//				//タイルのサイズ
//				cocos2d::Size tileSize = pMap->getTileSize();
//
//				//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロックの数＊ブロックの高さ
//				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;
//
//				//修正位置（キャラクターがめり込んでいるブロックの上の位置）= 
//				//キャラクターがめり込んでいるブロックの下のブロックの位置　＋　ブロック１個分 - 位置y
//				float boudary = (pt.y) - (blockPos + tileSize.height);
//
//				//めり込んでいる分を修正
//				this->m_pMove->m_pos.y -= boudary;
//
//				//速度と加速度を０にする
//				this->m_pMove->m_vel.y		= 0.0f;
//				this->m_pMove->m_accele.y	= 0.0f;
//			}
//		}
//	}
//	return true;
//}
//*/