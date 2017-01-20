#include "Map.h"
#include "Constants.h"
#include "Data\Collision\Collision.h"
#include "Data\LaunchData\LaunchData.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"

/**
* @desc タイルの２次元配列上の座標を取得
* @param 左上を原点とした配列上の座標位置
*/
cocos2d::Point CMap::getTileCoord(cocos2d::Point pos)
{
	//マップの原点位置
	cocos2d::Point pt = this->getPosition();

	//マップタイルサイズ
	cocos2d::Size tileSize = this->getTileSize();

	//マップの配列サイズ
	cocos2d::Size mapSize = this->getMapSize();

	int x = (pos.x + pt.x) / tileSize.width;
	int y = ((mapSize.height * tileSize.height) - pos.y) / tileSize.height;

	//左上原点(enchant.js)の場合
	//int y = (pos_.y + this->getPosition().y)/this->getTileSize().height;

	return cocos2d::Point(x, y);
}

/**
* @desc タイル位置の取得
* @param 左下を原点として対象の座標位置
*/
cocos2d::Point CMap::getTilePosition(cocos2d::Point pos)
{
	//マップの原点位置
	cocos2d::Point pt = this->getPosition();

	//マップタイルサイズ
	cocos2d::Size tileSize = this->getTileSize();

	int x = (pos.x + pt.x) / tileSize.width;
	int y = (pos.y + pt.y) / tileSize.height;

	return cocos2d::Point(x * tileSize.width, y * tileSize.height);
}

/**
* @desc 点とマップチップとの衝突判定
* @param 対象位置X
* @param 対象位置Y
*/
bool CMap::hitTest(float posX, float posY)
{
	//対象の衝突判定の点
	CCollisionPoint cpt(cocos2d::Point(posX, posY));

	//点と衝突しているマップチップの原点（左下の点）を取得
	cocos2d::Point basePoint = this->getTilePosition(cocos2d::Point(posX, posY));

	//マップチップの位置（マップチップの中心位置）
	cocos2d::Point tilePos = cocos2d::Point(basePoint.x + 16.0f, basePoint.y + 16.0f);

	//(-16,16,16,-16)
	CCollisionRect crect(CBody(-16, 16, 16, -16), tilePos);

	//collisionを使用して判定
	return cpt.collision(&crect);
}

/**
* @desc　タイル番号の確認
* @param ２次元配列上のX位置
* @param ２次元配列上のY位置
* @param レイヤータイプ
* @return ブロックタイプ
*/
BLOCK_TYPE CMap::checkTile(float posX, float posY, LAYER_TYPE layerType)
{
	//レイヤーを取得
	cocos2d::TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//タイルの２次元配列上の座標を取得
	cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(posX, posY));

	//マップの配列サイズ
	cocos2d::Size mapSize = this->getMapSize();

	////////
	//タイルの２次元配列上の座標が0未満またはマップサイズより大きい場合
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false)
	{
		return BLOCK_TYPE::NONE;
	}

	//マップチップデータの取得
	return (BLOCK_TYPE)pLayer->getTileGIDAt(tileCoord);
}

/**
* @desc タイルの変更
* @param 変更するマップチップID
* @param 点が衝突しているタイル、その点のX座標
* @param 点が衝突しているタイル、その点のY座標
* @param レイヤータイプ
* @return true...成功
*/
bool CMap::changeTile(int mapChipID, float posX, float posY, LAYER_TYPE layerType)
{
	//レイヤーを取得
	cocos2d::TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//タイルの２次元配列上の座標を取得
	cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(posX, posY));

	//マップの配列サイズ
	cocos2d::Size mapSize = this->getMapSize();

	//////
	//タイルの２次元配列上の座標が０未満またはマップサイズより大きい場合
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false)
	{
		return false;
	}

	//マップチップデータの反映
	pLayer->setTileGID(mapChipID, tileCoord);

	return true;
}

/**
* @desc 敵の出撃判定
* @return 敵のタイプ
*/
void CMap::checkEnemyLaunch(float posX, float posY)
{
	//レイヤーの位置を取得
	cocos2d::Point pt = cocos2d::Point(posX,posY);

	//レイヤーのｘ位置に画面の右サイズ分を足すことで
	//表示されている画面の右端の位置を取得できる
	float checkPosX = -pt.x + WINDOW_RIGHT;

	//マップチップのサイズを取得(32,32)
	cocos2d::Size tileSize = this->getTileSize();

	//タイルの２次元配列上の座標を取得（X座標のみをチェック）
	cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(checkPosX, 0.0f));

	//現在参照中の敵出撃ラインのチェック
	if (this->m_lauchEnemyLine == tileCoord.x)
	{
		//下から順にタイルサイズ分づつタイルをチェックしていく
		for (float y = tileSize.height * 0.5f; y < WINDOW_TOP; y += tileSize.height)
		{
			//チェックするタイルの座標を設定（xは固定でy座標をチェックしていく）
			cocos2d::Point tilePos(checkPosX, y);

			//そのｘ座標の２次元配列上のｙ位置にある全てのタイルを取得
			//そのタイルのタイルタイプ（＝敵タイプ）を取得
			ENEMY_TYPE eneType = (ENEMY_TYPE)this->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_ENEMY);

			//敵のタイプがNONEじゃなかったら出撃
			if (eneType != ENEMY_TYPE::NONE)
			{
				//敵出撃データ（出撃の情報）の生成
				CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
					eneType,
					tilePos
				);

				if (pLaunchData)
				{
					//敵出撃後の敵出撃レイヤーのタイルを削除
					this->removeLaunchEnemyBlock(pLaunchData);

					//出撃トリガーを生成し、敵出撃データを設定
					CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

					//出撃トリガーを出撃スケジュールとして追加する
					CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

					return;
				}
			}
		}
		//敵出撃ラインの更新
		this->m_lauchEnemyLine++;
	}
}

/**
* @desc ギミックの出撃判定
*/
void CMap::checkGimmickLaunch(float posX, float posY)
{
	while (this->m_lauchGimmickLine < this->m_lauchEnemyLine)
	{
		//レイヤーの位置を取得
		cocos2d::Point pt = cocos2d::Point(posX, posY);

		//マップチップのサイズを取得(32,32)
		cocos2d::Size tileSize = this->getTileSize();

		float checkPosX = 0.0f;


		if (tileSize.width * this->m_lauchGimmickLine >= WINDOW_RIGHT)
		{
			checkPosX = -pt.x + WINDOW_RIGHT;
		}
		else
		{	
			checkPosX = -pt.x + this->m_lauchGimmickLine * tileSize.width;
		}


		//タイルの２次元配列上の座標を取得（X座標のみをチェック）
		cocos2d::Point tileCoord = this->getTileCoord(cocos2d::Point(checkPosX, 0.0f));

		//現在参照中の敵出撃ラインのチェック
		if (this->m_lauchGimmickLine == tileCoord.x)
		{
			//下から順にタイルサイズ分づつタイルをチェックしていく
			for (float y = tileSize.height * 0.5f; y < WINDOW_TOP; y += tileSize.height)
			{
				//チェックするタイルの座標を設定（xは固定でy座標をチェックしていく）
				cocos2d::Point tilePos(checkPosX, y);

				//そのｘ座標の２次元配列上のｙ位置にある全てのタイルを取得
				//そのタイルのタイルタイプ（＝敵タイプ）を取得
				GIMMICK_TYPE gimmickType = (GIMMICK_TYPE)this->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_GIMMICK);

				//敵のタイプがNONEじゃなかったら出撃
				if (gimmickType != GIMMICK_TYPE::NONE)
				{
					//敵出撃データ（出撃の情報）の生成
					CGimmickLaunchData* pLaunchData = new CGimmickLaunchData(
						gimmickType,
						tilePos
					);

					if (pLaunchData)
					{
						//敵出撃後の敵出撃レイヤーのタイルを削除
						this->removeLaunchGimmickBlock(pLaunchData);

						//出撃トリガーを生成し、敵出撃データを設定
						CGimmickLaunchTrigger* pTrigger = new CGimmickLaunchTrigger(pLaunchData);

						//出撃トリガーを出撃スケジュールとして追加する
						CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

						
					}
				}
			}
			//ギミック出撃ラインの更新
			this->m_lauchGimmickLine++;
		}
	}
}



/**
* @desc 敵出撃後の敵出撃レイヤーのタイルの削除
* @param 敵出撃データ
*/
void CMap::removeLaunchEnemyBlock(CEnemyLaunchData* pLaunchData)
{
	//出撃した場所の敵出撃レイヤーのマップチップをENEMY_TYPE::NONEにする
	this->changeTile((int)ENEMY_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::LAUNCH_ENEMY);
}

/**
* @desc ギミック出撃後の敵出撃レイヤーのタイルの削除
* @param ギミック出撃データ
*/
void CMap::removeLaunchGimmickBlock(CGimmickLaunchData* pLaunchData)
{
	//出撃した場所のギミック出撃レイヤーのマップチップをGIMMICK_TYPE::NONEにする
	this->changeTile((int)GIMMICK_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::LAUNCH_GIMMICK);
}




//=============================================================
// マップ管理クラス
//=============================================================

//共有インスタンス
CMapManager* CMapManager::m_pSharedMapManager = NULL;


//コンストラクタ
CMapManager::CMapManager()
{

}

//コンストラクタ
CMapManager::CMapManager(const CMapManager& customMapMgr_)
{

}

//共有インスタンスの取得
CMapManager* CMapManager::getInstance()
{
	if (CMapManager::m_pSharedMapManager == NULL)
	{
		CMapManager::m_pSharedMapManager = new CMapManager();
	}
	return CMapManager::m_pSharedMapManager;
}

//デストラクタ
CMapManager::~CMapManager()
{

}

//破棄
void CMapManager::removeInstance()
{
	SAFE_DELETE(CMapManager::m_pSharedMapManager);
}

//マップの生成
CMap* CMapManager::createMap(const std::string& fileName_)
{
	//既に生成されていたら生成されているものを返す
	if (this->m_pMap != NULL)
	{
		CCLOG("既に生成されています");
		return this->m_pMap;
	}

	//マップクラスの生成
	this->m_pMap = CMap::create(fileName_);

	if (this->m_pMap == NULL)
	{
		CCLOG("マップの生成に失敗しました!!");
		return NULL;
	}

	//初期位置の設定
	this->m_pMap->setPosition(0.0f, 0.0f);

	//取り付けられている全てのタイルのエイリアスのデフォルトをアンチエイリアスに設定
	//ちらつき防止
	for (const auto& child : this->m_pMap->getChildren())
	{
		static_cast<cocos2d::SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
	}

	return this->m_pMap;
}

//マップの取得
CMap* CMapManager::getMap()
{
	return this->m_pMap;
}
