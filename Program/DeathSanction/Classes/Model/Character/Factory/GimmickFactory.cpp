#include"GimmickFactory.h"
#include"Model\Character\TikuwaBlockGimmickCharacter.h"
#include"Model\Character\NoteBlockGimmickCharacter.h"
/**
* @desc コンストラクタ
*/
CGimmickFactory::CGimmickFactory()
{

}

/**
* @desc デストラクタ
*/
CGimmickFactory::~CGimmickFactory()
{

}

/**
* @desc ギミックキャラクターを生成
* @param 初期座標X
* @param 初期座標Y
*/
CGimmickCharacter* CGimmickFactory::create(float posX, float posY)
{
	//ギミックキャラクターの生成
	CGimmickCharacter* pCharacter = this->createGimmick();


	//実体データの設定
	this->settingBody(pCharacter);
	//アニメーションデータ群の設定
	this->settingAnimations(pCharacter);
	//移動データの設定
	this->settingMove(pCharacter, posX, posY);
	//物理演算データ群の設定
	this->settingPhysicals(pCharacter);
	//アクションデータ群の設定
	this->settingActions(pCharacter);
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
// ギミックキャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CDamageBlockGimmickCreateFactory::CDamageBlockGimmickCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CDamageBlockGimmickCreateFactory::~CDamageBlockGimmickCreateFactory()
{

}

/**
* @desc ギミックキャラクターの生成
* @return ギミックキャラクターのインスタンスのアドレス
*/
CGimmickCharacter*  CDamageBlockGimmickCreateFactory::createGimmick(void)
{
	//ギミックキャラクターの生成
	CGimmickCharacter* pCharacter = CDamageBlockGimmickCharacter::create();

	//ギミックキャラクター部品生成工場の生成
	CGimmickPartsFactory factory;

	//アニメーションデータ群の設定
	pCharacter->addAnimations(factory.getAnimations());
	//移動データの設定
	pCharacter->addMove(factory.getMove());
	//物理演算データ群の設定
	pCharacter->addPhysicals(factory.getPhysicals());
	//アクションデータ群の設定
	pCharacter->addActions(factory.getActions());
	//実体データの設定
	pCharacter->addBody(factory.getBody());
	//衝突判定データ群の設定
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}



/**
* @desc コンストラクタ
*/
CGimmickPartsFactory::CGimmickPartsFactory()
{

}
/**
* @desc デストラクタ
*/
CGimmickPartsFactory::~CGimmickPartsFactory()
{

}

/**
* @desc アニメーションデータ群の取得
* @return アニメーションデータ群
*/
std::vector<CAnimation*>* CGimmickPartsFactory::getAnimations(void)
{
	//アニメーションデータ群の作成
	return new std::vector<CAnimation*>();
}

/**
* @desc 移動データの取得
* @return 移動データ
*/
CMove*	CGimmickPartsFactory::getMove(void)
{
	//移動データの作成
	return new CMove();
}
/**
* @desc 物理演算データ群取得
* @return 物理演算データ群
*/
std::vector<CPhysical*>* CGimmickPartsFactory::getPhysicals(void)
{
	//適用させる物理演算作成
	return new std::vector<CPhysical*>();
}

/**
* @desc アクションデータ群の取得
* @return アクションデータ群
*/
std::vector<CAction*>* CGimmickPartsFactory::getActions(void)
{
	//行えるアクション群を作成
	return new std::vector<CAction*>();
}

/**
* @desc 実体データの取得
* @return 実体データ
*/
CBody*	CGimmickPartsFactory::getBody(void)
{
	//実体データの作成
	return new CBody();
}

/**
* @desc 衝突判定領域データ群の取得
* @return 衝突判定領域データ群
*/
std::vector<CCollisionArea*>* CGimmickPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}



//=======================================================
//
//　ダメージブロックギミック工場クラス
//
//=======================================================

/**
* @desc コンストラクタ
*/
CDamageBlockGimmickFactory::CDamageBlockGimmickFactory(int type):m_type(type)
{

}

/**
* @desc デストラクタ
*/
CDamageBlockGimmickFactory::~CDamageBlockGimmickFactory()
{

}

/**
* @desc	 移動データを設定
* @param ギミックキャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CDamageBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//初期位置の設定
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 テクスチャーを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CDamageBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_DAMAGEBLOCK_GIMMICK);
}
/**
* @desc	 アニメーションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CDamageBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//アニメーションデータ群の取得
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//直立アニメーションの設定
	pAnimations->push_back(new CChipNotAnimation());


	switch ((TYPE)this->m_type)
	{
	case TYPE::LEFT:	//直立アニメーションに設定する為のチップデータの設定
						(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));
						break;

	case TYPE::UP:		//直立アニメーションに設定する為のチップデータの設定
						(*pAnimations)[0]->addChipData(new CChip(32, 0, 32, 32));
						break;

	case TYPE::RIGHT:	//直立アニメーションに設定する為のチップデータの設定
						(*pAnimations)[0]->addChipData(new CChip(64, 0, 32, 32));
						break;

	case TYPE::DOWN:	//直立アニメーションに設定する為のチップデータの設定
						(*pAnimations)[0]->addChipData(new CChip(96, 0, 32, 32));
						break;
	}

	
}
/**
* @desc	 物理演算データ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CDamageBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 アクションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CDamageBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 実体データを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CDamageBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CDamageBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//上のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//下のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	//基準点の設定
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 初期化処理
* @param ギミックキャラクターインスタンスのアドレス
*/
void CDamageBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
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
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}

//=======================================================
//
// ギミックキャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CRollBlockGimmickCreateFactory::CRollBlockGimmickCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CRollBlockGimmickCreateFactory::~CRollBlockGimmickCreateFactory()
{

}

/**
* @desc ギミックキャラクターの生成
* @return ギミックキャラクターのインスタンスのアドレス
*/
CGimmickCharacter*  CRollBlockGimmickCreateFactory::createGimmick(void)
{
	//ギミックキャラクターの生成
	CGimmickCharacter* pCharacter = CRollBlockGimmickCharacter::create();

	//ギミックキャラクター部品生成工場の生成
	CGimmickPartsFactory factory;

	//アニメーションデータ群の設定
	pCharacter->addAnimations(factory.getAnimations());
	//移動データの設定
	pCharacter->addMove(factory.getMove());
	//物理演算データ群の設定
	pCharacter->addPhysicals(factory.getPhysicals());
	//アクションデータ群の設定
	pCharacter->addActions(factory.getActions());
	//実体データの設定
	pCharacter->addBody(factory.getBody());
	//衝突判定データ群の設定
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}



//=======================================================
//
//　回るブロックギミック工場クラス
//
//=======================================================

/**
* @desc コンストラクタ
*/
CRollBlockGimmickFactory::CRollBlockGimmickFactory()
{

}

/**
* @desc デストラクタ
*/
CRollBlockGimmickFactory::~CRollBlockGimmickFactory()
{

}

/**
* @desc	 移動データを設定
* @param ギミックキャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CRollBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//初期位置の設定
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 テクスチャーを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CRollBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_ROLLBLOCK_GIMMICK);
}
/**
* @desc	 アニメーションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CRollBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//アニメーションデータ群の取得
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//直立アニメーションの設定
	pAnimations->push_back(new CChipNotAnimation());

	//直立アニメーションに設定する為のチップデータの設定
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));

	//直立アニメーションの設定
	pAnimations->push_back(new CChipAnimation(10,4,true));
	//直立アニメーションに設定する為のチップデータの設定
	(*pAnimations)[1]->addChipData(new CChip(0, 0, 32, 32));
}
/**
* @desc	 物理演算データ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CRollBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 アクションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CRollBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 実体データを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CRollBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CRollBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//上のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//下のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	//基準点の設定
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 初期化処理
* @param ギミックキャラクターインスタンスのアドレス
*/
void CRollBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
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
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}

//=======================================================
//
// ギミックキャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CTikuwaBlockGimmickCreateFactory::CTikuwaBlockGimmickCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CTikuwaBlockGimmickCreateFactory::~CTikuwaBlockGimmickCreateFactory()
{

}

/**
* @desc ギミックキャラクターの生成
* @return ギミックキャラクターのインスタンスのアドレス
*/
CGimmickCharacter*  CTikuwaBlockGimmickCreateFactory::createGimmick(void)
{
	//ギミックキャラクターの生成
	CGimmickCharacter* pCharacter = CTikuwaBlockGimmickCharacter::create();

	//ギミックキャラクター部品生成工場の生成
	CGimmickPartsFactory factory;

	//アニメーションデータ群の設定
	pCharacter->addAnimations(factory.getAnimations());
	//移動データの設定
	pCharacter->addMove(factory.getMove());
	//物理演算データ群の設定
	pCharacter->addPhysicals(factory.getPhysicals());
	//アクションデータ群の設定
	pCharacter->addActions(factory.getActions());
	//実体データの設定
	pCharacter->addBody(factory.getBody());
	//衝突判定データ群の設定
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}


//=======================================================
//
//　落ちるブロックギミック工場クラス
//
//=======================================================

/**
* @desc コンストラクタ
*/
CTikuwaBlockGimmickFactory::CTikuwaBlockGimmickFactory()
{

}

/**
* @desc デストラクタ
*/
CTikuwaBlockGimmickFactory::~CTikuwaBlockGimmickFactory()
{

}

/**
* @desc	 移動データを設定
* @param ギミックキャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CTikuwaBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//初期位置の設定
	pMove->m_pos.set(posX, posY);
}
/**
* @desc	 テクスチャーを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CTikuwaBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_TIKUWABLOCK_GIMMICK);
}
/**
* @desc	 アニメーションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CTikuwaBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//アニメーションデータ群の取得
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//直立アニメーションの設定
	pAnimations->push_back(new CChipNotAnimation());

	//直立アニメーションに設定する為のチップデータの設定
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));
}
/**
* @desc	 物理演算データ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CTikuwaBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 アクションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CTikuwaBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 実体データを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CTikuwaBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-16, 16, 16, -16);
}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CTikuwaBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// マップ衝突空間の生成
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

}
/**
* @desc	 初期化処理
* @param ギミックキャラクターインスタンスのアドレス
*/
void CTikuwaBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
{
	//状態の設定
	pCharacter->m_state = 0;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;

	//生きているフラグを立てる
	pCharacter->m_isAlive = true;

	//位置を反映
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	//基準点を設定
	((CTikuwaBlockGimmickCharacter*)pCharacter)->m_vec2BasePosition = pCharacter->getPosition();

	

	//チップデータを反映
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}


//=======================================================
//
// ギミックキャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CNoteBlockGimmickCreateFactory::CNoteBlockGimmickCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CNoteBlockGimmickCreateFactory::~CNoteBlockGimmickCreateFactory()
{

}

/**
* @desc ギミックキャラクターの生成
* @return ギミックキャラクターのインスタンスのアドレス
*/
CGimmickCharacter*  CNoteBlockGimmickCreateFactory::createGimmick(void)
{
	//ギミックキャラクターの生成
	CGimmickCharacter* pCharacter = CNoteBlockGimmickCharacter::create();

	//ギミックキャラクター部品生成工場の生成
	CGimmickPartsFactory factory;

	//アニメーションデータ群の設定
	pCharacter->addAnimations(factory.getAnimations());
	//移動データの設定
	pCharacter->addMove(factory.getMove());
	//物理演算データ群の設定
	pCharacter->addPhysicals(factory.getPhysicals());
	//アクションデータ群の設定
	pCharacter->addActions(factory.getActions());
	//実体データの設定
	pCharacter->addBody(factory.getBody());
	//衝突判定データ群の設定
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}


//=======================================================
//
//　跳ねるブロックギミック工場クラス
//
//=======================================================

/**
* @desc コンストラクタ
*/
CNoteBlockGimmickFactory::CNoteBlockGimmickFactory()
{

}

/**
* @desc デストラクタ
*/
CNoteBlockGimmickFactory::~CNoteBlockGimmickFactory()
{

}

/**
* @desc	 移動データを設定
* @param ギミックキャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CNoteBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//初期位置の設定
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 テクスチャーを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CNoteBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_NOTEBLOCK_GIMMICK);
}
/**
* @desc	 アニメーションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CNoteBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//アニメーションデータ群の取得
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//直立アニメーションの設定
	pAnimations->push_back(new CChipAnimation(10,4,true));

	//直立アニメーションに設定する為のチップデータの設定
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));
}
/**
* @desc	 物理演算データ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CNoteBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 アクションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CNoteBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 実体データを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CNoteBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CNoteBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//上のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//下のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	//基準点の設定
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 初期化処理
* @param ギミックキャラクターインスタンスのアドレス
*/
void CNoteBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
{
	//状態の設定
	pCharacter->m_state = 0;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;

	//生きているフラグを立てる
	pCharacter->m_isAlive = true;

	//位置を反映
	pCharacter->setPosition(pCharacter->m_pMove->m_pos);

	((CNoteBlockGimmickCharacter*)pCharacter)->m_vec2BasePosition = pCharacter->getPosition();

	//チップデータを反映
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}

//=======================================================
//
// ギミックキャラクター生成クラス
//
//=======================================================
/**
* @desc コンストラクタ
*/
CHatenaBlockGimmickCreateFactory::CHatenaBlockGimmickCreateFactory()
{

}

/**
* @desc デストラクタ
*/
CHatenaBlockGimmickCreateFactory::~CHatenaBlockGimmickCreateFactory()
{

}

/**
* @desc ギミックキャラクターの生成
* @return ギミックキャラクターのインスタンスのアドレス
*/
CGimmickCharacter*  CHatenaBlockGimmickCreateFactory::createGimmick(void)
{
	//ギミックキャラクターの生成
	CGimmickCharacter* pCharacter = CHatenaBlockGimmickCharacter::create();

	//ギミックキャラクター部品生成工場の生成
	CGimmickPartsFactory factory;

	//アニメーションデータ群の設定
	pCharacter->addAnimations(factory.getAnimations());
	//移動データの設定
	pCharacter->addMove(factory.getMove());
	//物理演算データ群の設定
	pCharacter->addPhysicals(factory.getPhysicals());
	//アクションデータ群の設定
	pCharacter->addActions(factory.getActions());
	//実体データの設定
	pCharacter->addBody(factory.getBody());
	//衝突判定データ群の設定
	pCharacter->addCollisionAreas(factory.getCollisionAreas());

	return pCharacter;
}


//=======================================================
//
//　キャラクターが出現するブロックギミック工場クラス
//
//=======================================================

/**
* @desc コンストラクタ
*/
CHatenaBlockGimmickFactory::CHatenaBlockGimmickFactory()
{

}

/**
* @desc デストラクタ
*/
CHatenaBlockGimmickFactory::~CHatenaBlockGimmickFactory()
{

}

/**
* @desc	 移動データを設定
* @param ギミックキャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CHatenaBlockGimmickFactory::settingMove(CGimmickCharacter* pCharacter, float posX, float posY)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//初期位置の設定
	pMove->m_pos.set(posX + pBody->m_right, posY);
}
/**
* @desc	 テクスチャーを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CHatenaBlockGimmickFactory::settingTexture(CGimmickCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_HATENABLOCK_GIMMICK);
}
/**
* @desc	 アニメーションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CHatenaBlockGimmickFactory::settingAnimations(CGimmickCharacter* pCharacter)
{
	//アニメーションデータ群の取得
	std::vector<CAnimation*>* pAnimations = pCharacter->getAnimations();

	//通常アニメーションの設定
	pAnimations->push_back(new CChipAnimation(10,4,true));

	//通常アニメーションに設定する為のチップデータの設定
	(*pAnimations)[0]->addChipData(new CChip(0, 0, 32, 32));

	//衝突後アニメーションの設定
	pAnimations->push_back(new CChipNotAnimation());

	//衝突後アニメーションに設定する為のチップデータの設定
	(*pAnimations)[1]->addChipData(new CChip(128, 0, 32, 32));

}
/**
* @desc	 物理演算データ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CHatenaBlockGimmickFactory::settingPhysicals(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 アクションデータ群を設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CHatenaBlockGimmickFactory::settingActions(CGimmickCharacter* pCharacter)
{

}
/**
* @desc	 実体データを設定
* @param ギミックキャラクターインスタンスのアドレス
*/
void CHatenaBlockGimmickFactory::settingBody(CGimmickCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-16, 16, 16, -16);


}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CHatenaBlockGimmickFactory::settingCollisionAreas(CGimmickCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

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


	pCollisionTerritory = new CCollisionTerritoryMapChipTop();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	//上のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);

	pCollisionTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ右の衝突した際のイベントを設定
	pCollisionTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//下のマップチップ領域を設定
	pMapArea->addTerritory(pCollisionTerritory);


	//基準点の設定
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, 8)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(16, -8)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, 8)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-16, -8)));

	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, 16)));
	//上のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, 16)));

	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8, -16)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-8, -16)));

	//画面端の衝突判定空間を取り付ける
	pCollisionAreas->push_back(pMapArea);
}
/**
* @desc	 初期化処理
* @param ギミックキャラクターインスタンスのアドレス
*/
void CHatenaBlockGimmickFactory::settingInitialize(CGimmickCharacter* pCharacter)
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
	pCharacter->setTextureRect((*pCharacter->m_pAnimations)[pCharacter->m_state]->getCurrentChip());
}


//=======================================================
//
// ギミックキャラクター生成クラス管理クラス
//
// シングルトン
//
//=======================================================
//シングルトンインスタンス
CGimmickFactoryManager* CGimmickFactoryManager::m_pSharedManager = NULL;

/*
* @desc コンストラクタ
*/
CGimmickFactoryManager::CGimmickFactoryManager()
{
	//ギミック工場群の生成
	this->m_pFactories = new std::map<GIMMICK_TYPE, CGimmickFactory*>();

	//工場を生成して取り付けていく
	//連想配列のキーはマップチップIDに設定
	//クリボー生成工場の取り付け
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_LEFT] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_LEFT);
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_RIGHT] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_RIGHT);
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_UP] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_UP);
	(*this->m_pFactories)[GIMMICK_TYPE::DAMEGE_DOWN] = new CDamageBlockGimmickFactory((int)GIMMICK_TYPE::DAMEGE_DOWN);
	(*this->m_pFactories)[GIMMICK_TYPE::ROLL] = new CRollBlockGimmickFactory();
	(*this->m_pFactories)[GIMMICK_TYPE::TIKUWA] = new CTikuwaBlockGimmickFactory();
	(*this->m_pFactories)[GIMMICK_TYPE::NOTE] = new CNoteBlockGimmickFactory();
	(*this->m_pFactories)[GIMMICK_TYPE::HATENA] = new CHatenaBlockGimmickFactory();
}

/**
* @desc デストラクタ
*/
CGimmickFactoryManager::~CGimmickFactoryManager()
{
	//ギミック生成工場群の破棄
	std::map<GIMMICK_TYPE, CGimmickFactory*>::iterator itr = this->m_pFactories->begin();

	while (itr != this->m_pFactories->end())
	{
		SAFE_DELETE(itr->second);
		itr++;
	}
	//ギミック生成工場群の破棄
	SAFE_DELETE(this->m_pFactories);
}

/**
* @desc シングルトン：：インスタンスの取得
* @return シングルトンインスタンス
*/
CGimmickFactoryManager* CGimmickFactoryManager::getInstance(void)
{
	if (CGimmickFactoryManager::m_pSharedManager == NULL)
	{
		CGimmickFactoryManager::m_pSharedManager = new CGimmickFactoryManager();
	}
	return CGimmickFactoryManager::m_pSharedManager;
}

/**
* @desc ギミックキャラクターを生成
* @param 生成タイプ
* @param 初期座標X
* @param 初期座標Y
* @param ギミックの発射方向のベクトル(ギミックの向きベクトル)
*/
CGimmickCharacter* CGimmickFactoryManager::create(GIMMICK_TYPE type, float posX, float posY)
{

	return (*this->m_pFactories)[type]->create(posX, posY);

}

/**
* @desc シングルトンインスタンスの解放
*/
void CGimmickFactoryManager::removeInstance()
{
	SAFE_DELETE(CGimmickFactoryManager::m_pSharedManager);
}
