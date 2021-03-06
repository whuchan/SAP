#include"EnemyFactory.h"

/**
* @desc コンストラクタ
*/
CEnemyPartsFactory::CEnemyPartsFactory()
{

}
/**
* @desc デストラクタ
*/
CEnemyPartsFactory::~CEnemyPartsFactory()
{

}


/**
* @desc 移動データの取得
* @return 移動データ
*/
CMove*	CEnemyPartsFactory::getMove(void)
{
	//移動データの作成
	return new CMove();
}


/**
* @desc 実体データの取得
* @return 実体データ
*/
CBody*	CEnemyPartsFactory::getBody(void)
{
	//実体データの作成
	return new CBody();
}

/**
* @desc 衝突判定領域データ群の取得
* @return 衝突判定領域データ群
*/
std::vector<CCollisionArea*>* CEnemyPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}

/**
* @desc 状態遷移マシンの取得
* @return 状態遷移マシンのインスタンス
*/
CStateMachine* CEnemyPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}

///**
//* @desc コンストラクタ
//*/
//CKuriboFactory::CKuriboFactory()
//{
//
//}
//
///**
//* @desc デストラクタ
//*/
//CKuriboFactory::~CKuriboFactory()
//{
//
//}
//
///**
//* @desc	 移動データを設定
//* @param 敵キャラクターインスタンスのアドレス
//* @param 初期座標X
//* @param 初期座標Y
//*/
//void CKuriboFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
//{
//	//移動データの取得
//	CMove* pMove = pCharacter->getMove();
//
//	//初期位置の設定
//	pMove->m_pos.set(posX, posY);
//
//	//初速度の設定は固定（デバッグとしてクリボーの速度は等加速度運動）
//	pCharacter->getMove()->m_vel.set(-1.0f, 0.0f);
//
//}
///**
//* @desc	 テクスチャーを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKuriboFactory::settingTexture(CEnemyCharacter* pCharacter)
//{
//	//テクスチャの設定
//	pCharacter->setTexture(IMAGE_ENEMY);
//}
///**
//* @desc	 アニメーションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKuriboFactory::settingAnimations(CEnemyCharacter* pCharacter)
//{
//	pCharacter->m_intAnimationState = 0;
//
//	CAnimation* pointerAnimation = new CChipNotAnimation();
//
//	//直立アニメーションに設定する為のチップデータの設定
//	pointerAnimation->addChipData(new CChip(0, 0, 64, 64));
//
//	pCharacter->m_mapAnimation[0] = pointerAnimation;
//}
///**
//* @desc	 物理演算データ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKuriboFactory::settingPhysicals(CEnemyCharacter* pCharacter)
//{
//	//物理演算データ群の取得
//	pCharacter->m_intPhysicalState = 0;
//
//	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();
//
//	//重力演算の設定
//	pointerPhysical->push_back(new CPhysicalGravity());
//
//	//重力演算の設定
//	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
//}
///**
//* @desc	 アクションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKuriboFactory::settingActions(CEnemyCharacter* pCharacter)
//{
//	//アクションデータ群の取得
//	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();
//
//	(*mapAction)[0] = new CActionEnemyDead(2.0f, 6.0f);
//
//	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
//}
///**
//* @desc	 実体データを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKuriboFactory::settingBody(CEnemyCharacter* pCharacter)
//{
//	//実体データの取得
//	CBody* pBody = pCharacter->getBody();
//
//	//実体データの設定
//	pBody->set(-32, 32, 32, -32);
//
//
//}
//
///**
//* @desc 衝突判定領域データ群の設定
//* @param 衝突判定領域データ群
//*/
//void CKuriboFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
//{
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();
//
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());
//
//
//	//画面下端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
//	//画面左端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
//
//	//画面端の衝突空間を取り付ける
//	pCollisionAreas->push_back(pEndOfScreenArea);
//
//	//========================================
//	// マップ衝突空間の生成
//	//========================================
//	CCollisionArea* pMapArea = new CCollisionAreaMap();
//
//	//マップチップ衝突空間に領域を設定
//	//下のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
//	//上のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
//	//右のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
//	//左のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());
//
//
//	//基準点の設定
//	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16, -32)));
//	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-16, -32)));
//
//	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16, 32)));
//	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-16, 32)));
//
//	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, 16)));
//	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, -16)));
//
//	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, 16)));
//	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, -16)));
//
//
//	//画面端の衝突判定空間を取り付ける
//	pCollisionAreas->push_back(pMapArea);
//}
///**
//* @desc	 初期化処理
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKuriboFactory::settingInitialize(CEnemyCharacter* pCharacter)
//{
//	//状態の設定
//	pCharacter->m_state = 0;
//
//	//有効フラグを立てる
//	pCharacter->m_activeFlag = true;
//
//	//生きているフラグを立てる
//	pCharacter->m_isAlive = true;
//
//	//位置を反映
//	pCharacter->setPosition(pCharacter->m_pMove->m_pos);
//
//	//チップデータを反映
//	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
//}
//
//
//
////=======================================================
////
//// 緑ノコノコ生成工場クラス
////
////=======================================================
///**
//* @desc コンストラクタ
//*/
//CGreenNokoNokoFactory::CGreenNokoNokoFactory()
//{
//
//}
//
///**
//* @desc デストラクタ
//*/
//CGreenNokoNokoFactory::~CGreenNokoNokoFactory()
//{
//
//}
//
///**
//* @desc	 移動データを設定
//* @param 敵キャラクターインスタンスのアドレス
//* @param 初期座標X
//* @param 初期座標Y
//*/
//void CGreenNokoNokoFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
//{
//	//移動データの取得
//	CMove* pMove = pCharacter->getMove();
//
//	//初期位置の設定
//	pMove->m_pos.set(posX, posY);
//
//	//初速度の設定
//	pCharacter->getMove()->m_vel.set(-1.0f, 0.0f);
//
//}
///**
//* @desc	 テクスチャーを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenNokoNokoFactory::settingTexture(CEnemyCharacter* pCharacter)
//{
//	//テクスチャの設定
//	pCharacter->setTexture(IMAGE_NOKONOKO);
//
//	//左向きに設定
//	pCharacter->setScale(-1.0f,-1.0f);
//}
///**
//* @desc	 アニメーションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenNokoNokoFactory::settingAnimations(CEnemyCharacter* pCharacter)
//{
//	pCharacter->m_intAnimationState = 0;
//
//	CAnimation* pointerAnimation = new CChipListAnimation(10, true);
//
//	//歩行アニメーション
//	pointerAnimation->addChipData(new CChip(0, 0, 32, 54));
//	pointerAnimation->addChipData(new CChip(32, 0, 32, 54));
//
//	pCharacter->m_mapAnimation[0] = pointerAnimation;
//}
///**
//* @desc	 物理演算データ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenNokoNokoFactory::settingPhysicals(CEnemyCharacter* pCharacter)
//{
//	//物理演算データ群の取得
//	pCharacter->m_intPhysicalState = 0;
//
//	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();
//
//	//重力演算の設定
//	pointerPhysical->push_back(new CPhysicalGravity());
//
//	//重力演算の設定
//	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
//}
///**
//* @desc	 アクションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenNokoNokoFactory::settingActions(CEnemyCharacter* pCharacter)
//{
//	//アクションデータ群の取得
//	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();
//
//	(*mapAction)[0] = new CActionEnemyDead(2.0f, 6.0f);
//
//	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
//
//}
///**
//* @desc	 実体データを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenNokoNokoFactory::settingBody(CEnemyCharacter* pCharacter)
//{
//	//実体データの取得
//	CBody* pBody = pCharacter->getBody();
//
//	//実体データの設定
//	pBody->set(-16, 27, 16, -27);
//
//
//}
//
///**
//* @desc 衝突判定領域データ群の設定
//* @param 衝突判定領域データ群
//*/
//void CGreenNokoNokoFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
//{
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();
//
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());
//
//
//	//画面下端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
//	//画面左端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
//
//	//画面端の衝突空間を取り付ける
//	pCollisionAreas->push_back(pEndOfScreenArea);
//
//	//========================================
//	// マップ衝突空間の生成
//	//========================================
//	CCollisionArea* pMapArea = new CCollisionAreaMap();
//
//	//マップチップ衝突空間に領域を設定
//	//下のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
//	//上のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
//	//右のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
//	//左のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());
//
//
//	//基準点の設定
//	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16, -32)));
//	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-16, -32)));
//
//	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16, 32)));
//	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-16, 32)));
//
//	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, 16)));
//	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, -16)));
//
//	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, 16)));
//	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, -16)));
//
//
//	//画面端の衝突判定空間を取り付ける
//	pCollisionAreas->push_back(pMapArea);
//}
///**
//* @desc	 初期化処理
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenNokoNokoFactory::settingInitialize(CEnemyCharacter* pCharacter)
//{
//	//状態の設定
//	pCharacter->m_state = 0;
//
//	//有効フラグを立てる
//	pCharacter->m_activeFlag = true;
//
//	//生きているフラグを立てる
//	pCharacter->m_isAlive = true;
//
//	//位置を反映
//	pCharacter->setPosition(pCharacter->m_pMove->m_pos);
//
//	//チップデータを反映
//	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
//}
//
//
//
////=======================================================
////
//// 緑パタパタ生成工場クラス
////
////=======================================================
///**
//* @desc コンストラクタ
//*/
//CGreenPataPataFactory::CGreenPataPataFactory()
//{
//
//}
//
///**
//* @desc デストラクタ
//*/
//CGreenPataPataFactory::~CGreenPataPataFactory()
//{
//
//}
//
///**
//* @desc	 移動データを設定
//* @param 敵キャラクターインスタンスのアドレス
//* @param 初期座標X
//* @param 初期座標Y
//*/
//void CGreenPataPataFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
//{
//	//移動データの取得
//	CMove* pMove = pCharacter->getMove();
//
//	//初期位置の設定
//	pMove->m_pos.set(posX, posY);
//}
///**
//* @desc	 テクスチャーを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenPataPataFactory::settingTexture(CEnemyCharacter* pCharacter)
//{
//	//テクスチャの設定
//	pCharacter->setTexture(IMAGE_PATAPATA);
//
//	//テクスチャのデフォルトの向きを左向きに設定
//	pCharacter->setScale(-1.0f, 1.0f);
//}
///**
//* @desc	 アニメーションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenPataPataFactory::settingAnimations(CEnemyCharacter* pCharacter)
//{
//	pCharacter->m_intAnimationState = 0;
//
//	CAnimation* pointerAnimation = new CChipListAnimation(10, true);
//
//	//直立アニメーションに設定する為のチップデータの設定
//	pointerAnimation->addChipData(new CChip(0, 0, 56, 56));
//	pointerAnimation->addChipData(new CChip(56, 0, 56, 56));
//
//	pCharacter->m_mapAnimation[0] = pointerAnimation;
//}
///**
//* @desc	 物理演算データ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenPataPataFactory::settingPhysicals(CEnemyCharacter* pCharacter)
//{
//}
///**
//* @desc	 アクションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenPataPataFactory::settingActions(CEnemyCharacter* pCharacter)
//{
//	//アクションデータ群の取得
//	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();
//
//	(*mapAction)[0] = new CActionEnemyDeadAndCreateEnemy((int)ENEMY_TYPE::NOKONOKO);
//	(*mapAction)[1] = new CActionUpAndDownMove(pCharacter->m_pMove->m_pos, 100, 0.02f);
//
//	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
//}
///**
//* @desc	 実体データを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenPataPataFactory::settingBody(CEnemyCharacter* pCharacter)
//{
//	//実体データの取得
//	CBody* pBody = pCharacter->getBody();
//
//	//実体データの設定
//	pBody->set(-28, 28, 28, -28);
//
//
//}
//
///**
//* @desc 衝突判定領域データ群の設定
//* @param 衝突判定領域データ群
//*/
//void CGreenPataPataFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
//{
//	/*
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();
//
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());
//
//
//	//画面下端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
//	//画面左端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
//
//	//画面端の衝突空間を取り付ける
//	pCollisionAreas->push_back(pEndOfScreenArea);
//
//	//========================================
//	// マップ衝突空間の生成
//	//========================================
//	CCollisionArea* pMapArea = new CCollisionAreaMap();
//
//	//マップチップ衝突空間に領域を設定
//	//下のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
//	//上のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
//	//右のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
//	//左のマップチップ領域を設定
//	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());
//
//
//	//基準点の設定
//	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16, -32)));
//	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようXを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-16, -32)));
//
//	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16, 32)));
//	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（Xを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-16, 32)));
//
//	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, 16)));
//	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, -16)));
//
//	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, 16)));
//	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（Yを少しずらす）
//	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, -16)));
//
//
//	//画面端の衝突判定空間を取り付ける
//	pCollisionAreas->push_back(pMapArea);
//	*/
//}
///**
//* @desc	 初期化処理
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CGreenPataPataFactory::settingInitialize(CEnemyCharacter* pCharacter)
//{
//	//状態の設定
//	pCharacter->m_state = 0;
//
//	//有効フラグを立てる
//	pCharacter->m_activeFlag = true;
//
//	//生きているフラグを立てる
//	pCharacter->m_isAlive = true;
//
//	//位置を反映
//	pCharacter->setPosition(pCharacter->m_pMove->m_pos);
//
//	//チップデータを反映
//	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
//}
//
//
//
//
////=======================================================
////
//// キラー生成工場クラス
////
////=======================================================
///**
//* @desc コンストラクタ
//*/
//CKillerFactory::CKillerFactory()
//{
//
//}
//
///**
//* @desc デストラクタ
//*/
//CKillerFactory::~CKillerFactory()
//{
//
//}
//
///**
//* @desc	 移動データを設定
//* @param 敵キャラクターインスタンスのアドレス
//* @param 初期座標X
//* @param 初期座標Y
//*/
//void CKillerFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
//{
//	//移動データの取得
//	CMove* pMove = pCharacter->getMove();
//
//	//初期位置の設定
//	pMove->m_pos.set(posX, posY);
//
//	//初速度の設定
//	pCharacter->getMove()->m_vel.set(-3.0f, 0.0f);
//
//}
///**
//* @desc	 テクスチャーを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerFactory::settingTexture(CEnemyCharacter* pCharacter)
//{
//	//テクスチャの設定
//	pCharacter->setTexture(IMAGE_KILLER);
//
//	//左向きに設定
//	pCharacter->setScale(-1.0f, -1.0f);
//}
///**
//* @desc	 アニメーションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerFactory::settingAnimations(CEnemyCharacter* pCharacter)
//{
//	pCharacter->m_intAnimationState = 0;
//
//	CAnimation* pointerAnimation = new CChipNotAnimation();
//
//	//直立アニメーションに設定する為のチップデータの設定
//	pointerAnimation->addChipData(new CChip(32, 0, 32, 32));
//
//	pCharacter->m_mapAnimation[0] = pointerAnimation;
//}
///**
//* @desc	 物理演算データ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerFactory::settingPhysicals(CEnemyCharacter* pCharacter)
//{
//
//}
///**
//* @desc	 アクションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerFactory::settingActions(CEnemyCharacter* pCharacter)
//{
//	//アクションデータ群の取得
//	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();
//
//	(*mapAction)[0] = new CActionEnemyDeadAndAddGravity(2.0f, 6.0f);
//
//	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
//}
///**
//* @desc	 実体データを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerFactory::settingBody(CEnemyCharacter* pCharacter)
//{
//	//実体データの取得
//	CBody* pBody = pCharacter->getBody();
//
//	//実体データの設定
//	pBody->set(-16, 16, 16, -16);
//}
//
///**
//* @desc 衝突判定領域データ群の設定
//* @param 衝突判定領域データ群
//*/
//void CKillerFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
//{
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();
//
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());
//
//	//画面下端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
//	//画面左端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
//
//	//画面端の衝突空間を取り付ける
//	pCollisionAreas->push_back(pEndOfScreenArea);
//}
///**
//* @desc	 初期化処理
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerFactory::settingInitialize(CEnemyCharacter* pCharacter)
//{
//	//状態の設定
//	pCharacter->m_state = 0;
//
//	//有効フラグを立てる
//	pCharacter->m_activeFlag = true;
//
//	//生きているフラグを立てる
//	pCharacter->m_isAlive = true;
//
//	//位置を反映
//	pCharacter->setPosition(pCharacter->m_pMove->m_pos);
//
//	//チップデータを反映
//	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
//}
//
//
////=======================================================
////
//// キラー生成工場クラス
////
////=======================================================
///**
//* @desc コンストラクタ
//*/
//CKillerBatteryFactory::CKillerBatteryFactory()
//{
//
//}
//
///**
//* @desc デストラクタ
//*/
//CKillerBatteryFactory::~CKillerBatteryFactory()
//{
//
//}
//
///**
//* @desc	 移動データを設定
//* @param 敵キャラクターインスタンスのアドレス
//* @param 初期座標X
//* @param 初期座標Y
//*/
//void CKillerBatteryFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY)
//{
//	//移動データの取得
//	CMove* pMove = pCharacter->getMove();
//
//	//初期位置の設定
//	pMove->m_pos.set(posX+16.0f, posY);
//}
///**
//* @desc	 テクスチャーを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerBatteryFactory::settingTexture(CEnemyCharacter* pCharacter)
//{
//	//テクスチャの設定
//	pCharacter->setTexture(IMAGE_KILLER);
//
//}
///**
//* @desc	 アニメーションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerBatteryFactory::settingAnimations(CEnemyCharacter* pCharacter)
//{
//	pCharacter->m_intAnimationState = 0;
//
//	CAnimation* pointerAnimation = new CChipNotAnimation();
//
//	//直立アニメーションに設定する為のチップデータの設定
//	pointerAnimation->addChipData(new CChip(0, 0, 32, 32));
//
//	pCharacter->m_mapAnimation[0] = pointerAnimation;
//}
///**
//* @desc	 物理演算データ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerBatteryFactory::settingPhysicals(CEnemyCharacter* pCharacter)
//{
//
//}
///**
//* @desc	 アクションデータ群を設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerBatteryFactory::settingActions(CEnemyCharacter* pCharacter)
//{
//	//アクションデータ群の取得
//	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();
//
//	(*mapAction)[0] = new CActionEnemyDeadAndAddGravity(2.0f, 6.0f);
//	(*mapAction)[1] = new CActionIntervalCreateEnemy((int)ENEMY_TYPE::KILLER,
//														30,
//														cocos2d::Point(-16.0f, 0.0f));
//
//	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
//}
///**
//* @desc	 実体データを設定
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerBatteryFactory::settingBody(CEnemyCharacter* pCharacter)
//{
//	//実体データの取得
//	CBody* pBody = pCharacter->getBody();
//
//	//実体データの設定
//	pBody->set(-16, 16, 16, -16);
//}
//
///**
//* @desc 衝突判定領域データ群の設定
//* @param 衝突判定領域データ群
//*/
//void CKillerBatteryFactory::settingCollisionAreas(CEnemyCharacter* pCharacter)
//{
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();
//
//	//========================================
//	// 衝突判定空間の生成
//	//========================================
//	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());
//
//	//画面下端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
//	//画面左端の領域を設定
//	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
//
//	//画面端の衝突空間を取り付ける
//	pCollisionAreas->push_back(pEndOfScreenArea);
//}
///**
//* @desc	 初期化処理
//* @param 敵キャラクターインスタンスのアドレス
//*/
//void CKillerBatteryFactory::settingInitialize(CEnemyCharacter* pCharacter)
//{
//	//状態の設定
//	pCharacter->m_state = 0;
//
//	//有効フラグを立てる
//	pCharacter->m_activeFlag = true;
//
//	//生きているフラグを立てる
//	pCharacter->m_isAlive = true;
//
//	//位置を反映
//	pCharacter->setPosition(pCharacter->m_pMove->m_pos);
//
//	//チップデータを反映
//	pCharacter->setTextureRect(pCharacter->m_mapAnimation[pCharacter->m_intAnimationState]->getCurrentChip());
//}
//
//
//
