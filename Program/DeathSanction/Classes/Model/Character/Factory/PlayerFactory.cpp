#include"PlayerFactory.h"
#include"Model\Character\BulletCharacter.h"
#include "Data\StateMachine\Player\PlayerStateIdle.h"
#include "Data\StateMachine\Player\PlayerStateWalk.h"
#include "Data\StateMachine\Player\PlayerStateLineUp.h"
#include "Data\StateMachine\Player\PlayerStateLineDown.h"


/**
* @desc コンストラクタ
*/
CPlayerFactory::CPlayerFactory()
{

}

/**
* @desc デストラクタ
*/
CPlayerFactory::~CPlayerFactory()
{

}

/**
* @desc プレイヤーキャラクターを生成
* @param 生成タイプ
*/
CPlayerCharacter* CPlayerFactory::create(void)
{
	//プレイヤーキャラクターの生成
	CPlayerCharacter* pPlayer = this->createPlayer();

	//アニメーションデータ群の設定
	this->settingAnimations(pPlayer);
	//移動データの設定
	this->settingMove(pPlayer);
	//物理演算データ群の設定
	this->settingPhysicals(pPlayer);
	//アクションデータ群の設定
	this->settingActions(pPlayer);
	//実体データの設定
	this->settingBody(pPlayer);
	//テクスチャの設定
	this->settingTexture(pPlayer);
	//衝突判定データ群の設定
	this->settingCollisionAreas(pPlayer);
	//状態遷移マシンの設定
	this->settingStateMachine(pPlayer);
	//初期設定
	this->settingInitialize(pPlayer);



	/*
	* 計算データのままで起動すると１フレームズレが発生するので
	*　初期化時の最後に値をSpriteに反映する
	*/
	pPlayer->applyFunc();


	return pPlayer;
}



//=======================================================
//
// プレイヤーキャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CPlayerCreateFactory::CPlayerCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CPlayerCreateFactory::~CPlayerCreateFactory()
{

}

/**
* @desc プレイヤーキャラクターの生成
* @return プレイヤーキャラクターのインスタンスのアドレス
*/
CPlayerCharacter*  CPlayerCreateFactory::createPlayer(void)
{
	//プレイヤーキャラクターの生成
	CPlayerCharacter* pPlayer = CPlayerCharacter::create();

	//プレイヤーキャラクター部品生成工場の生成
	CCharacterPartsFactory* pFactory = new CPlayerPartsFactory();

	//移動データの設定
	pPlayer->addMove(pFactory->getMove());
	//実体データの設定
	pPlayer->addBody(pFactory->getBody());
	//衝突判定データ群の設定
	pPlayer->addCollisionAreas(pFactory->getCollisionAreas());

	//状態遷移マシンの設定
	pPlayer->addStateMachine(pFactory->getStateMachine());

	//プレイヤーキャラクター部品生成工場の解放
	SAFE_DELETE(pFactory);

	return pPlayer;
}



/**
* @desc コンストラクタ
*/
CPlayerPartsFactory::CPlayerPartsFactory()
{

}
/**
* @desc デストラクタ
*/
CPlayerPartsFactory::~CPlayerPartsFactory()
{

}


/**
* @desc 移動データの取得
* @return 移動データ
*/
CMove*	CPlayerPartsFactory::getMove(void)
{
	//移動データの作成
	return new CMove();
}

/**
* @desc 実体データの取得
* @return 実体データ
*/
CBody*	CPlayerPartsFactory::getBody(void)
{
	//実体データの作成
	return new CBody();
}

/**
* @desc 衝突判定領域データ群の取得
* @return 衝突判定領域データ群
*/
std::vector<CCollisionArea*>* CPlayerPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>;
}


/**
* @desc 状態遷移マシンの取得
* @return 状態遷移マシンのインスタンス
*/
CStateMachine* CPlayerPartsFactory::getStateMachine()
{
	return new CStateMachine();
}

/**
* @desc コンストラクタ
*/
CBasePlayerFactory::CBasePlayerFactory()
{

}

/**
* @desc デストラクタ
*/
CBasePlayerFactory::~CBasePlayerFactory()
{

}

/**
* @desc	 移動データを設定
* @param プレイヤーキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingMove(CPlayerCharacter* pPlayer)
{
	//移動データの取得
	CMove* pMove = pPlayer->getMove();

	//初期位置の設定
	pMove->m_pos.set(320.0f, 320.0f);

	pPlayer->m_shotLaunchVector = cocos2d::Vec2(1.0f, 0.0f);
}
/**
* @desc	 テクスチャーを設定
* @param プレイヤーキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingTexture(CPlayerCharacter* pPlayer)
{
	//テクスチャの設定
	pPlayer->setTexture(IMAGE_PLAYER);
}
/**
* @desc	 アニメーションデータ群を設定
* @param プレイヤーキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingAnimations(CPlayerCharacter* pPlayer)
{
	pPlayer->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(0, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::IDLE] = pointerAnimation;

	pointerAnimation = new CChipListAnimation(10, true);

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(64, 0, 64, 64));
	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(128, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::WALK] = pointerAnimation;

	pointerAnimation = new CChipNotAnimation();

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(192, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::HIT] = pointerAnimation;

	pointerAnimation = new CChipNotAnimation();

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(128, 0, 64, 64));

	pPlayer->m_mapAnimation[(int)CPlayerCharacter::STATE::FALING] = pointerAnimation;
}
/**
* @desc	 物理演算データ群を設定
* @param プレイヤーキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingPhysicals(CPlayerCharacter* pPlayer)
{

	//物理演算データ群の取得
	pPlayer->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//重力演算の設定
	pointerPhysical->push_back(new CPhysicalGravity());
	pointerPhysical->push_back(new CPhysicalFriction(6.0f));
	//重力演算の設定
	pPlayer->m_mapPhysical[pPlayer->m_intPhysicalState] = pointerPhysical;
}
/**
* @desc	 アクションデータ群を設定
* @param プレイヤーキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingActions(CPlayerCharacter* pPlayer)
{
	pPlayer->m_intActionState = 0;

	//アクションデータ群の取得
	std::map<int,CAction*>* mapAction = new std::map<int,CAction*>();

	//ジャンプアクションを設定
	(*mapAction)[(int)CPlayerCharacter::ACTION::JUMP] = new CActionJump(3.0f, 4);

	//通常弾発射アクションを設定
	//(*mapAction)[(int)CPlayerCharacter::ACTION::SHOT_NORMAL_BULLET] = new CActionShotBullet((int)BULLET_TYPE::NORMAL, 20);

	////カスタム弾発射アクションを設定
	//(*mapAction)[(int)CPlayerCharacter::ACTION::SHOT_CUSTOM_BULLET] = new CActionShotBullet((int)BULLET_TYPE::CUSTOM, 20);

	////ファイアーボール弾発射アクションを設定
	//(*mapAction)[(int)CPlayerCharacter::ACTION::SHOT_FIREBALL_BULLET] = new CActionShotBullet((int)BULLET_TYPE::FIREBALL, 20);

	pPlayer->m_mapAction[pPlayer->m_intActionState] = mapAction;
}


/**
* @desc	 実体データを設定
* @param プレイヤーキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingBody(CPlayerCharacter* pPlayer)
{
	//実体データの取得
	CBody* pBody = pPlayer->getBody();

	//実体データの設定
	pBody->set(-32, 32, 32, -32);
}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CBasePlayerFactory::settingCollisionAreas(CPlayerCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// 衝突判定空間の生成
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());

	//画面下端の領域を生成
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//画面下端の衝突した際のイベントを設定
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//画面下端の領域を設定
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);

 

	//画面端の衝突空間に衝突を行う下の基準点を設定
	pEndOfScreenArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, -32)));

	//画面端の衝突空間を取り付ける
	pCollisionAreas->push_back(pEndOfScreenArea);

	//========================================
	// マップ衝突空間の生成
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//マップチップ衝突空間に領域を設定

	//下のマップチップ領域を生成
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//下のマップチップ領域と衝突した際のイベントコールバックを設定
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//下のマップチップ領域を設定
	pMapArea->addTerritory(pMapChipBottomTerritory);
	//上のマップチップ領域を設定
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//右のマップチップ領域を設定
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//左のマップチップ領域を設定
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());


	//基準点の設定
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16, -32)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-16, -32)));

	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16, 32)));
	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-16, 32)));

	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, 16)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, -16)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, 16)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, -16)));


	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}

/**
* @desc 状態遷移マシンの設定
* @param 取り付けるキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingStateMachine(CPlayerCharacter* pCharacter)
{
	//待機状態
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::IDLE, new CPlayerStateIdle(pCharacter));

	//歩行状態
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::WALK, new CPlayerStateWalk(pCharacter));

	//ラインアップ状態
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_UP, new CPlayerStateLineUp(pCharacter));

	//ラインダウン状態
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_DOWN, new CPlayerStateLineDown(pCharacter));


	//初期状態の設定
	pCharacter->m_stateMachine->setStartState((int)CPlayerCharacter::STATE::IDLE);
}

/**
* @desc	 初期化処理
* @param プレイヤーキャラクターインスタンスのアドレス
*/
void CBasePlayerFactory::settingInitialize(CPlayerCharacter* pPlayer)
{
	//状態の設定
	pPlayer->m_state = (int)CPlayerCharacter::STATE::FALING;

	//有効フラグを立てる
	pPlayer->m_activeFlag = true;
}

//=======================================================
//
// プレイヤーキャラクター生成クラス管理クラス
//
// シングルトン
//
//=======================================================
//シングルトンインスタンス
CPlayerFactoryManager* CPlayerFactoryManager::m_pSharedFactory=NULL;

/*
* @desc コンストラクタ
*/
CPlayerFactoryManager::CPlayerFactoryManager()
{	
	//工場を生成して取り付けていく
	this->m_pFactories.push_back(new CBasePlayerFactory());

}

/**
* @desc デストラクタ
*/
CPlayerFactoryManager::~CPlayerFactoryManager()
{
	for (CPlayerFactory* pFactory : this->m_pFactories)
	{
		SAFE_DELETE(pFactory);
	}
}

/**
* @desc シングルトン：：インスタンスの取得
* @return シングルトンインスタンス
*/
CPlayerFactoryManager* CPlayerFactoryManager::getInstance(void)
{
	if (m_pSharedFactory == NULL)
	{
		m_pSharedFactory = new CPlayerFactoryManager();
	}
	return m_pSharedFactory;
}

/**
* @desc プレイヤーキャラクターを生成
* @param 生成タイプ
*/
CPlayerCharacter* CPlayerFactoryManager::create(CPlayerFactoryManager::TYPE type)
{
	return this->m_pFactories[(int)type]->create();
}

/**
* @desc シングルトンインスタンスの解放
*/
void CPlayerFactoryManager::removeInstance()
{
	SAFE_DELETE(m_pSharedFactory);
}