#include"PlayerAttack1Factory.h"


///////////////////////////////////////////////////////////////////////

/**
* @desc コンストラクタ
*/
CPlayerAttack1Factory::CPlayerAttack1Factory()
{

}

/**
* @desc デストラクタ
*/
CPlayerAttack1Factory::~CPlayerAttack1Factory()
{

}

/**
* @desc	 移動データを設定
* @param 敵キャラクターインスタンスのアドレス
* @param 初期座標X
* @param 初期座標Y
*/
void CPlayerAttack1Factory::settingMove(CCharacter* pCharacter, float posX, float posY)
{
	//移動データの取得
	CMove* pMove = pCharacter->getMove();

	//初期位置の設定
	pMove->m_pos.set(posX, posY);

	//初速度の設定は固定（デバッグとしてクリボーの速度は等加速度運動）
	pCharacter->getMove()->m_vel.set(-1.0f, 0.0f);

}
/**
* @desc	 テクスチャーを設定
* @param 敵キャラクターインスタンスのアドレス
*/
void CPlayerAttack1Factory::settingTexture(CCharacter* pCharacter)
{
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_ENEMY);
}
/**
* @desc	 アニメーションデータ群を設定
* @param 敵キャラクターインスタンスのアドレス
*/
void CPlayerAttack1Factory::settingAnimations(CCharacter* pCharacter)
{
	pCharacter->m_intAnimationState = 0;

	CAnimation* pointerAnimation = new CChipNotAnimation();

	//直立アニメーションに設定する為のチップデータの設定
	pointerAnimation->addChipData(new CChip(0, 0, 64, 64));

	pCharacter->m_mapAnimation[0] = pointerAnimation;
}
/**
* @desc	 物理演算データ群を設定
* @param 敵キャラクターインスタンスのアドレス
*/
void CPlayerAttack1Factory::settingPhysicals(CCharacter* pCharacter)
{
	/*
	//物理演算データ群の取得
	pCharacter->m_intPhysicalState = 0;

	std::vector<CPhysical*>*  pointerPhysical = new std::vector<CPhysical*>();

	//重力演算の設定
	pointerPhysical->push_back(new CPhysicalGravity());

	//重力演算の設定
	pCharacter->m_mapPhysical[pCharacter->m_intPhysicalState] = pointerPhysical;
	*/
}
/**
* @desc	 アクションデータ群を設定
* @param 敵キャラクターインスタンスのアドレス
*/
void CPlayerAttack1Factory::settingActions(CCharacter* pCharacter)
{
	/*
	//アクションデータ群の取得
	std::map<int, CAction*>* mapAction = new std::map<int, CAction*>();

	(*mapAction)[0] = new CActionEnemyDead(2.0f, 6.0f);

	pCharacter->m_mapAction[pCharacter->m_intActionState] = mapAction;
	*/
}
/**
* @desc	 実体データを設定
* @param 敵キャラクターインスタンスのアドレス
*/
void CPlayerAttack1Factory::settingBody(CCharacter* pCharacter)
{
	//実体データの取得
	CBody* pBody = pCharacter->getBody();

	//実体データの設定
	pBody->set(-32, 32, 32, -32);


}

/**
* @desc 衝突判定領域データ群の設定
* @param 衝突判定領域データ群
*/
void CPlayerAttack1Factory::settingCollisionAreas(CCharacter* pCharacter)
{
	//========================================
	// 衝突判定空間の生成
	//========================================
	std::vector<CCollisionArea*>* pCollisionAreas = pCharacter->getCollisionAreas();

	//========================================
	// 衝突判定空間の生成
	//========================================
	CCollisionArea* pEndOfScreenArea = new CCollisionAreaEndOfScreen(pCharacter->getBody());


	//画面下端の領域を設定
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端の領域を設定
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//画面端の衝突空間を取り付ける
	pCollisionAreas->push_back(pEndOfScreenArea);

	//========================================
	// マップ衝突空間の生成
	//========================================
	CCollisionArea* pMapArea = new CCollisionAreaMap();

	//マップチップ衝突空間に領域を設定
	//下のマップチップ領域を設定
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
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
* @param 敵キャラクターインスタンスのアドレス
*/
void CPlayerAttack1Factory::settingStateMachine(CCharacter* pCharacter)
{
	/*
	//待機状態
	pCharacter->m_stateMachine->registerState((int)CPlayerAttack1Enemy::STATE::IDLE, new CPlayerAttack1StateIdle((CPlayerAttack1Enemy*)pCharacter));

	
	//歩行状態
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::WALK, new CPlayerStateWalk(pCharacter));

	//ラインアップ状態
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_UP, new CPlayerStateLineUp(pCharacter));

	//ラインダウン状態
	pCharacter->m_stateMachine->registerState((int)CPlayerCharacter::STATE::LINE_DOWN, new CPlayerStateLineDown(pCharacter));
	

	//初期状態の設定
	pCharacter->m_stateMachine->setStartState((int)CPlayerAttack1Enemy::STATE::IDLE);

	*/
}

/**
* @desc	 初期化処理
* @param 敵キャラクターインスタンスのアドレス
*/
void CPlayerAttack1Factory::settingInitialize(CCharacter* pCharacter)
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
//EOF