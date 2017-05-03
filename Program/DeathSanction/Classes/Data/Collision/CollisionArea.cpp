#include "CollisionArea.h"
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"


/**
* @desc イベントコールバックの呼び出し
* @param 呼び出すインスタンス
* マップチップの際はブロックタイプをイベントとして渡すが
* 画面端などにイベントは存在しないので
* デフォルト値として０を設定しておく
*/
void CCollisionTerritory::callEventCallback(CCharacter* pChara, int event)
{
	//イベントコールバックが設定されていなければ、
	//つまりNULLなら呼び出しを行わない
	if (this->m_pEventCallback != NULL)
	{
		//イベントコールバックを呼び出すメンバ関数が実装されている
		//キャラクターから呼び出しを行う
		(pChara->*m_pEventCallback)(event);
	}
}


//======================================
// 下にある画面端領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryEndOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//下に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{
		//下に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_BOTTOM;

			//最終的に戻す値
			pChara->m_pMove->m_pos.y -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;

		}
	}
}

//======================================
// 上にある画面端領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryEndOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//上に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.y > 0.0f)
	{
		//上に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_TOP;

			//最終的に戻す値
			pChara->m_pMove->m_pos.y -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}


//======================================
// 右にある画面端領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryEndOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//上に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.x > 0.0f)
	{
		//上に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_RIGHT;

			//最終的に戻す値
			pChara->m_pMove->m_pos.x -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}

//======================================
// 左にある画面端領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryEndOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//左に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.x < 0.0f)
	{
		//左に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_LEFT;

			//最終的に戻す値
			pChara->m_pMove->m_pos.x -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}


//======================================
// 下にある画面外領域との衝突判定
//======================================
/**
* @desc コンストラクタ
* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
*/
CCollisionTerritoryOutOfScreenBottom::CCollisionTerritoryOutOfScreenBottom()
	: CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
{

}

/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryOutOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//下に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{
		//下に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}

//======================================
// 上にある画面外領域との衝突判定
//======================================
/**
* @desc コンストラクタ
* 領域タイプの設定を初期化子でTERRITORY_TYPE::TOPに設定しておく
*/
CCollisionTerritoryOutOfScreenTop::CCollisionTerritoryOutOfScreenTop()
	: CCollisionTerritory(TERRITORY_TYPE::TOP)
{

}

/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryOutOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//上に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.y > 0.0f)
	{
		//下に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}


//======================================
// 右にある画面外領域との衝突判定
//======================================
/**
* @desc コンストラクタ
* 領域タイプの設定を初期化子でTERRITORY_TYPE::RIGHTに設定しておく
*/
CCollisionTerritoryOutOfScreenRight::CCollisionTerritoryOutOfScreenRight()
	: CCollisionTerritory(TERRITORY_TYPE::RIGHT)
{
	
}

/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryOutOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	

	//右に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.x > 0.0f)
	{
		//右に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT * 3)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}


//======================================
// 左にある画面外領域との衝突判定
//======================================
/**
* @desc コンストラクタ
* 領域タイプの設定を初期化子でTERRITORY_TYPE::LEFTに設定しておく
*/
CCollisionTerritoryOutOfScreenLeft::CCollisionTerritoryOutOfScreenLeft()
	: CCollisionTerritory(TERRITORY_TYPE::LEFT)
{

}

/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryOutOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//左に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.x < 0.0f)
	{
		//左に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			if (pChara->m_charaType == CHARACTER_TYPE::BULLET)
			{
				pChara->m_activeFlag = false;
			}
		}
	}
}


//======================================
// 下にあるマップチップ領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryMapChipBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//下に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{

		//衝突してきた点(キャラクターの点)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//衝突していた


			//ブロックのタイプを取得
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapChipID != BLOCK_TYPE::NONE)
			{
				//イベントコールバックの呼び出し
				this->callEventCallback(pChara, (int)mapChipID);

				//戻すべき位置の計算

				//タイルサイズ（32，32）
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロック数＊ブロックの高さ
				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

				//戻すべき位置
				// 修正位置（キャラクターがめり込んでいるブロックの上の位置）= 
				// キャラクターがめり込んでいるブロックの下のブロックの位置　＋　ブロック一個分ー位置ｙ
				float boundary = pt.y - (blockPos + tileSize.height);

				//最終的に戻す値（めり込んだ分を戻す）
				pChara->m_pMove->m_pos.y -= boundary;

				//リセットする値
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;
			}
		}
		
		//下に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) < WINDOW_BOTTOM)
		{
			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) - WINDOW_BOTTOM;

			//最終的に戻す値
			pChara->m_pMove->m_pos.y -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}

//======================================
// 上にあるマップチップ領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryMapChipTop::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//上に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.y > 0.0f)
	{

		//衝突してきた点(キャラクターの点)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//衝突していた


			//ブロックのタイプを取得
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapChipID != BLOCK_TYPE::NONE)
			{
				//イベントコールバックの呼び出し
				this->callEventCallback(pChara, (int)mapChipID);

				//戻すべき位置の計算

				//タイルサイズ（32，32）
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの上のブロックの位置　＝　ブロック数＊ブロックの高さ
				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

				//戻すべき位置
				// 修正位置（キャラクターがめり込んでいるブロックの下の位置）= 
				// キャラクターがめり込んでいるブロックの下のブロックの位置　＋　ブロック一個分ー位置ｙ
				float boundary = pt.y - blockPos;

				//最終的に戻す値（めり込んだ分を戻す）
				pChara->m_pMove->m_pos.y -= boundary;

				//リセットする値
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;
			}
		}
	}
}

//======================================
// 右にあるマップチップ領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryMapChipRight::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//上に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.x > 0.0f)
	{

		//衝突してきた点(キャラクターの点)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//衝突していた


			//ブロックのタイプを取得
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapChipID != BLOCK_TYPE::NONE)
			{

				//イベントコールバックの呼び出し
				this->callEventCallback(pChara, (int)mapChipID);

				//戻すべき位置の計算

				//タイルサイズ（32，32）
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの上のブロックの位置　＝　ブロック数＊ブロックの幅
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//戻すべき位置
				// 修正位置（キャラクターがめり込んでいるブロックの下の位置）= 
				// キャラクターがめり込んでいるブロックの下のブロックの位置　＋　ブロック一個分ー位置ｙ
				float boundary = pt.x - blockPos;

				//最終的に戻す値（めり込んだ分を戻す）
				pChara->m_pMove->m_pos.x -= boundary;

				//リセットする値
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}
	}
}

//======================================
// 左にあるマップチップ領域との衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryMapChipLeft::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//上に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.x < 0.0f)
	{

		//衝突してきた点(キャラクターの点)
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);


		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y))
		{
			//衝突していた


			//ブロックのタイプを取得
			BLOCK_TYPE mapChipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapChipID != BLOCK_TYPE::NONE)
			{
				//イベントコールバックの呼び出し
				this->callEventCallback(pChara, (int)mapChipID);

				//戻すべき位置の計算

				//タイルサイズ（32，32）
				cocos2d::Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの上のブロックの位置　＝　ブロック数＊ブロックの高さ
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//戻すべき位置
				// 修正位置（キャラクターがめり込んでいるブロックの下の位置）= 
				// キャラクターがめり込んでいるブロックの下のブロックの位置　＋　ブロック一個分ー位置ｙ
				float boundary = pt.x - (blockPos + tileSize.width);
				
				//最終的に戻す値（めり込んだ分を戻す）
				pChara->m_pMove->m_pos.x -= boundary;

				//リセットする値
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}

		
	}
}


//======================================
// 画面端との衝突判定空間
//======================================
/**
* @desc コンストラクタ
* @param 衝突判定用実体データ
*/

CCollisionAreaEndOfScreen::CCollisionAreaEndOfScreen(CBody* pBody)
{
	cocos2d::Point pt;
	//Bottom
	pt.setPoint(0, pBody->m_bottom);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, pt));
	//Top
	pt.setPoint(0, pBody->m_top);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, pt));
	//Right
	pt.setPoint(pBody->m_right, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, pt));
	//Left
	pt.setPoint(pBody->m_left, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, pt));
}

/**
* @desc 衝突判定
* @param 衝突判定のキャラクター
*/
void CCollisionAreaEndOfScreen::collision(CCharacter* pChara)
{
	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara,pBasePt->m_pt);
			}
		}
		
	}
}


//======================================
// 画面外との衝突判定空間
//======================================
//コンストラクタ
CCollisionAreaOutOfScreen::CCollisionAreaOutOfScreen()
{

}


/**
* @desc コンストラクタ
* @param 衝突判定用実体データ
*/
CCollisionAreaOutOfScreen::CCollisionAreaOutOfScreen(CBody* pBody)
{
	cocos2d::Point pt;

	//Bottom
	pt.setPoint(0, pBody->m_top);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, pt));
	//Top
	pt.setPoint(0, pBody->m_bottom);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, pt));
	//Right
	pt.setPoint(pBody->m_left, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, pt));
	//Left
	pt.setPoint(pBody->m_right, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, pt));


	/*
//Bottom
	pt.setPoint(0, pBody->m_bottom);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, pt));
	//Top
	pt.setPoint(0, pBody->m_top);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, pt));
	//Right
	pt.setPoint(pBody->m_right, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, pt));
	//Left
	pt.setPoint(pBody->m_left, 0);
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, pt));
	*/
}


//デストラクタ
CCollisionAreaOutOfScreen::~CCollisionAreaOutOfScreen()
{

}

/**
* @desc 衝突判定
* @param 衝突判定のキャラクター
*/
void CCollisionAreaOutOfScreen::collision(CCharacter* pChara)
{
	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}

	}
}


/**
* @desc 衝突判定
* @param 衝突判定のキャラクター
*/
void CCollisionAreaMap::collision(CCharacter* pChara)
{
	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}
}

/**
* @desc 衝突判定
* @param 衝突判定のキャラクター
*/
void CCollisionAreaLine::collision(CCharacter* pChara)
{
	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
	{
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type)
			{
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}
}


//======================================
// 下にあるラインとの衝突判定
//======================================
/**
* @desc 衝突判定
* @param 衝突対象
* @param 基準点
*/
void CCollisionTerritoryLineBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//下に移動しているかどうかをチェック
	if (pChara->m_pMove->m_vel.y < 0.0f)
	{
		enum LINE
		{
			FRONT = 0,
			CENTER = 1,
			BACK = 2,
		};

		float floatGround = 0.0f;

		switch (pChara->m_intCurrentLine)
		{
		case FRONT:		floatGround = 32.0f;
						break;
		case CENTER:
						floatGround = 96.0f;
						break;
		case BACK:		
						floatGround = 160.0f;
						break;
		}
		//下にライン端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) < floatGround)
		{
			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom) - floatGround;

			//最終的に戻す値
			pChara->m_pMove->m_pos.y -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}
//EOF