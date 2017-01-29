#include"BulletFactory.h"

/**
* @desc コンストラクタ
*/
CBulletFactory::CBulletFactory()
{

}

/**
* @desc デストラクタ
*/
CBulletFactory::~CBulletFactory()
{

}

/**
* @desc 弾キャラクターを生成
* @param 初期座標X
* @param 初期座標Y
*/
CBulletCharacter* CBulletFactory::create(float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//弾キャラクターの生成
	CBulletCharacter* pCharacter = this->createBullet();

	//アニメーションデータ群の設定
	this->settingAnimations(pCharacter);
	//移動データの設定
	this->settingMove(pCharacter, posX, posY, shotLaunchVector);
	//物理演算データ群の設定
	this->settingPhysicals(pCharacter);
	//アクションデータ群の設定
	this->settingActions(pCharacter);
	//実体データの設定
	this->settingBody(pCharacter);
	//テクスチャの設定
	this->settingTexture(pCharacter);
	//衝突判定データ群の設定
	this->settingCollisionAreas(pCharacter);
	//初期設定
	this->settingInitialize(pCharacter);

	return pCharacter;
}



//=======================================================
//
// 弾キャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CBulletCreateFactory::CBulletCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CBulletCreateFactory::~CBulletCreateFactory()
{

}

/**
* @desc 弾キャラクターの生成
* @return 弾キャラクターのインスタンスのアドレス
*/
CBulletCharacter*  CBulletCreateFactory::createBullet(void)
{
	//弾キャラクターの生成
	CBulletCharacter* pCharacter = CBulletCharacter::create();

	//弾キャラクター部品生成工場の生成
	CBulletPartsFactory factory;

	//移動データの設定
	pCharacter->addMove(factory.getMove());
	//実体データの設定
	pCharacter->addBody(factory.getBody());
	//衝突判定データ群の設定
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}



/**
* @desc コンストラクタ
*/
CBulletPartsFactory::CBulletPartsFactory()
{

}
/**
* @desc デストラクタ
*/
CBulletPartsFactory::~CBulletPartsFactory()
{

}

/**
* @desc 移動データの取得
* @return 移動データ
*/
CMove*	CBulletPartsFactory::getMove(void)
{
	//移動データの作成
	return new CMove();
}


/**
* @desc 実体データの取得
* @return 実体データ
*/
CBody*	CBulletPartsFactory::getBody(void)
{
	//実体データの作成
	return new CBody();
}

/**
* @desc 衝突判定領域データ群の取得
* @return 衝突判定領域データ群
*/
std::vector<CCollisionArea*>* CBulletPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}



//=======================================================
//
// ノーマル弾工場クラス
//
//=======================================================

/**
* @desc コンストラクタ
*/
CNormalBulletFactory::CNormalBulletFactory()
{

}

/**
* @desc デストラクタ
*/
CNormalBulletFactory::~CNormalBulletFactory()
{

}

/**
* @desc	 移動データを設定
* @param 弾キャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CNormalBulletFactory::settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//初期位置の設定
	pMove->m_pos.set(posX, posY);

	//初速度の設定は固定
	pMove->m_speed = 5.0f;

	//弾の発射方向のベクトル
	pCharacter->m_shotLaunchVector = shotLaunchVector;
}
/**
* @desc	 テクスチャーを設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CNormalBulletFactory::settingTexture(CBulletCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_NORMAL_BULLET);
}
/**
* @desc	 アニメーションデータ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CNormalBulletFactory::settingAnimations(CBulletCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(0, 0, 16, 16));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 物理演算データ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CNormalBulletFactory::settingPhysicals(CBulletCharacter* pCharacter)
{

}
/**
* @desc	 アクションデータ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CNormalBulletFactory::settingActions(CBulletCharacter* pCharacter)
{
	pCharacter->m_intActionState = 0;

	//アクションデータ群の取得
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionMoveStraight();

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
}
/**
* @desc	 実体データを設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CNormalBulletFactory::settingBody(CBulletCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-8, 8, 8, -8);


}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CNormalBulletFactory::settingCollisionAreas(CBulletCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// 衝突判定空間の生成
	//========================================
	

	//画面外衝突判定空間の生成
	
	CCollisionArea* pOutOfScreenArea = new CCollisionAreaOutOfScreen(pCharacter->getBody());
	//画面右端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenRight());
	//画面左端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenLeft());

	//画面端の衝突空間を取り付ける
	pCollisionAreas->push_back(pOutOfScreenArea);

	//========================================
	// マップ衝突空間の生成
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//マップチップ衝突空間に領域を設定
	
	
	//右のマップチップ領域を生成
	CCollisionTerritory*  pCollisionTerritory = new CCollisionTerritoryMapChipRight();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	//右のマップチップ領域を生成
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipLeft();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionLeftCallback);
	//左のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);

	//基準点の設定
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, 2)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, -2)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, 2)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, -2)));


	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 初期化処理
* @param 弾キャラクターインスタンスのアドレス
*/
void CNormalBulletFactory::settingInitialize(CBulletCharacter* pCharacter)
{
	//状態の設定
	pCharacter->m_state = 0;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;

	//生きているフラグを立てる
	pCharacter->m_isAlive = true;

	//位置を反映
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//チップデータを反映
	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
}

//=======================================================
//
// カスタム弾工場クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CCustomBulletFactory::CCustomBulletFactory()
{

}

/**
* @desc デストラクタ
*/
CCustomBulletFactory::~CCustomBulletFactory()
{

}

/**
* @desc	 移動データを設定
* @param 弾キャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CCustomBulletFactory::settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//初期位置の設定
	pMove->m_pos.set(posX, posY);

	//初速度の設定は固定
	pMove->m_speed = 3.0f;

	//弾の発射方向のベクトル
	pCharacter->m_shotLaunchVector = shotLaunchVector;
}
/**
* @desc	 テクスチャーを設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CCustomBulletFactory::settingTexture(CBulletCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_NORMAL_BULLET);
}
/**
* @desc	 アニメーションデータ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CCustomBulletFactory::settingAnimations(CBulletCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(0, 0, 16, 16));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 物理演算データ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CCustomBulletFactory::settingPhysicals(CBulletCharacter* pCharacter)
{
	//物理演算データ群の取得
	pCharacter->m_intPhysicalState = 0;
	
	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//重力演算の設定
	pointerPhysical->push_back(new CPhysicalGravity(-0.15f));

	//重力演算の設定
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
}
/**
* @desc	 アクションデータ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CCustomBulletFactory::settingActions(CBulletCharacter* pCharacter)
{
	//アクションデータ群の取得
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionMoveStraight();

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;

}

/**
* @desc	 実体データを設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CCustomBulletFactory::settingBody(CBulletCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-8, 8, 8, -8);


}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CCustomBulletFactory::settingCollisionAreas(CBulletCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// 衝突判定空間の生成
	//========================================


	//画面外衝突判定空間の生成
	CCollisionArea* pOutOfScreenArea = new CCollisionAreaOutOfScreen(pCharacter->getBody());
	//画面右端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenRight());
	//画面左端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenLeft());
	//画面下端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenBottom());
	
	//画面端の衝突空間を取り付ける
	pCollisionAreas->push_back(pOutOfScreenArea);

	//========================================
	// マップ衝突空間の生成
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//マップチップ衝突空間に領域を設定


	//右のマップチップ領域を生成
	CCollisionTerritory*  pCollisionTerritory = new CCollisionTerritoryMapChipRight();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	//右のマップチップ領域を生成
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipLeft();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionLeftCallback);
	//左のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ下の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//下のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	//基準点の設定
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, 2)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(4, -2)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, 2)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-4, -2)));


	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(2, -4)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-2, -4)));


	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}

/**
* @desc	 初期化処理
* @param 弾キャラクターインスタンスのアドレス
*/
void CCustomBulletFactory::settingInitialize(CBulletCharacter* pCharacter)
{
	//状態の設定
	pCharacter->m_state = 0;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;

	//生きているフラグを立てる
	pCharacter->m_isAlive = true;

	//位置を反映
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//チップデータを反映
	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
}


//=======================================================
//
//ファイアーボール 弾キャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CFireBallBulletCreateFactory::CFireBallBulletCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CFireBallBulletCreateFactory::~CFireBallBulletCreateFactory()
{

}

/**
* @desc 弾キャラクターの生成
* @return 弾キャラクターのインスタンスのアドレス
*/
CFireBallBulletCharacter*  CFireBallBulletCreateFactory::createBullet(void)
{
	//弾キャラクターの生成
	CFireBallBulletCharacter* pCharacter = CFireBallBulletCharacter::create();

	//弾キャラクター部品生成工場の生成
	CBulletPartsFactory factory;

	//移動データの設定
	pCharacter->addMove(factory.getMove());
	//実体データの設定
	pCharacter->addBody(factory.getBody());
	//衝突判定データ群の設定
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}




//=======================================================
//
// ファイアーボール弾工場クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CFireBallBulletFactory::CFireBallBulletFactory()
{

}

/**
* @desc デストラクタ
*/
CFireBallBulletFactory::~CFireBallBulletFactory()
{

}

/**
* @desc	 移動データを設定
* @param 弾キャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CFireBallBulletFactory::settingMove(CBulletCharacter* pCharacter, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//初期位置の設定
	pMove->m_pos.set(posX, posY);

	//初速度の設定は固定
	pMove->m_speed = 3.0f;

	//弾の発射方向のベクトル
	pCharacter->m_shotLaunchVector = shotLaunchVector;
}
/**
* @desc	 テクスチャーを設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CFireBallBulletFactory::settingTexture(CBulletCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_FIREBALL_BULLET);
}
/**
* @desc	 アニメーションデータ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CFireBallBulletFactory::settingAnimations(CBulletCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipListAnimation(10, true);

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(0, 0, 16, 16));
	pointerAnimation->addChipData(new CChip(16, 0, 16, 16));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 物理演算データ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CFireBallBulletFactory::settingPhysicals(CBulletCharacter* pCharacter)
{
	//物理演算データ群の取得
	pCharacter->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//重力演算の設定
	pointerPhysical->push_back(new CPhysicalGravity(-0.15f));

	//重力演算の設定
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;	
}
/**
* @desc	 アクションデータ群を設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CFireBallBulletFactory::settingActions(CBulletCharacter* pCharacter)
{
	//アクションデータ群の取得
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionJump(3.0f, 4);
	(*mapAction)[1] = new CActionMoveStraight();

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
}

/**
* @desc	 実体データを設定
* @param 弾キャラクターインスタンスのアドレス
*/
void CFireBallBulletFactory::settingBody(CBulletCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-8, 8, 8, -8);
}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CFireBallBulletFactory::settingCollisionAreas(CBulletCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// 衝突判定空間の生成
	//========================================


	//画面外衝突判定空間の生成
	CCollisionArea* pOutOfScreenArea = new CCollisionAreaOutOfScreen(pCharacter->getBody());
	//画面右端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenRight());
	//画面左端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenLeft());
	//画面下端の領域を設定
	pOutOfScreenArea->addTerritory(new CCollisionTerritoryOutOfScreenBottom());

	//画面端の衝突空間を取り付ける
	pCollisionAreas->push_back(pOutOfScreenArea);

	//========================================
	// マップ衝突空間の生成
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//マップチップ衝突空間に領域を設定


	//右のマップチップ領域を生成
	CCollisionTerritory*  pCollisionTerritory = new CCollisionTerritoryMapChipRight();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	//右のマップチップ領域を生成
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipLeft();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionLeftCallback);
	//左のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ下の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//下のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	//基準点の設定
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, 4)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, -4)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, 4)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, -4)));


	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(4, -8)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-4, -8)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, -8)));

	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}



/**
* @desc	 初期化処理
* @param 弾キャラクターインスタンスのアドレス
*/
void CFireBallBulletFactory::settingInitialize(CBulletCharacter* pCharacter)
{
	//状態の設定
	pCharacter->m_state = 0;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;

	//生きているフラグを立てる
	pCharacter->m_isAlive = true;

	//位置を反映
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//チップデータを反映
	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
}


//=======================================================
//
// 弾キャラクター生成クラス管理クラス
//
// シングルトン
//
//=======================================================
//シングルトンインスタンス
CBulletFactoryManager* CBulletFactoryManager::m_pSharedManager = NULL;

/*
* @desc コンストラクタ
*/
CBulletFactoryManager::CBulletFactoryManager()
{
	//弾工場群の生成
	this->m_pFactories = new std::map<BULLET_TYPE, CBulletFactory*>();

	//工場を生成して取り付けていく
	//連想配列のキーはマップチップIDに設定
	//クリボー生成工場の取り付け
	(*this->m_pFactories)[BULLET_TYPE::NORMAL] = new CNormalBulletFactory();
	(*this->m_pFactories)[BULLET_TYPE::CUSTOM] = new CCustomBulletFactory();
	(*this->m_pFactories)[BULLET_TYPE::FIREBALL] = new CFireBallBulletFactory();
}

/**
* @desc デストラクタ
*/
CBulletFactoryManager::~CBulletFactoryManager()
{
	//弾生成工場群の破棄
	std::map<BULLET_TYPE, CBulletFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//弾生成工場群の破棄
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc シングルトン：：インスタンスの取得
* @return シングルトンインスタンス
*/
CBulletFactoryManager* CBulletFactoryManager::getInstance(void)
{
	if (CBulletFactoryManager::m_pSharedManager == NULL)
	{
		CBulletFactoryManager::m_pSharedManager = new CBulletFactoryManager();
	}
	return CBulletFactoryManager::m_pSharedManager;
}

/**
* @desc 弾キャラクターを生成
* @param 生成タイプ
* @param 初期座標X
* @param 初期座標Y
* @param 弾の発射方向のベクトル(弾の向きベクトル)
*/
CBulletCharacter* CBulletFactoryManager::create(BULLET_TYPE type, float posX, float posY, cocos2d::Vec2 shotLaunchVector)
{
	return (*this->m_pFactories)[type]->create(posX, posY,shotLaunchVector);
}

/**
* @desc シングルトンインスタンスの解放
*/
void CBulletFactoryManager::removeInstance()
{
	SAFE_DELETE(CBulletFactoryManager::m_pSharedManager);
}
