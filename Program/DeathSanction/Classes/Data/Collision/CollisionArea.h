#pragma once

#include"cocos2d.h"
#include"Constants.h"


//======================================
// 前方宣言
//======================================
class CCharacter;
class CBody;

//======================================
// 領域タイプ
//======================================
enum class TERRITORY_TYPE :int
{
	LEFT,
	TOP,
	RIGHT,
	BOTTOM
};

//======================================
// 衝突判定基準点
//======================================
class CCollisionBasePoint
{
public:
	//領域タイプ
	TERRITORY_TYPE m_type;
	//基準点
	cocos2d::Point m_pt;

	//コンストラクタ
	CCollisionBasePoint(TERRITORY_TYPE type, cocos2d::Point pt) :m_type(type), m_pt(pt)
	{

	}
};


//======================================
// 衝突判定領域
//======================================
class CCollisionTerritory
{
public:
	//領域タイプ
	TERRITORY_TYPE m_type;

	//コンストラクタ
	CCollisionTerritory(TERRITORY_TYPE type) :m_type(type)
	{

	}

	virtual ~CCollisionTerritory()
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara,cocos2d::Point basePt) = 0;

public:
	//イベントコールバック
	//void (CCharacter::*型名)(int event)のtypedef
	//typedefをクラス内に記述する事で
	//クラスにだけ有効なtypedefとなる
	typedef void(CCharacter::*EventCallback)(int event);

protected:
	//イベントコールバック
	EventCallback m_pEventCallback = NULL;

public:
	/**
	* @desc イベントコールバックの設定
	* @param 設定するイベントコールバック
	* @tips 領域を生成し、生成した領域に
	* イベントコールバック（メンバ関数ポインタ）を設定する事で
	* その領域のイベントが発生した時に
	* 登録したメンバ関数ポインタが呼び出される
	*/
	void setEventCallback(EventCallback pEventCallback)
	{
		this->m_pEventCallback = pEventCallback;
	}

	/**
	* @desc イベントコールバックの呼び出し
	* @param 呼び出すインスタンス
	* @param イベント
	*		マップチップの際はマップチップIDをイベントとして渡すが
	*		画面端などはイベントは存在しないので
	*		デフォルト値として０を設定しておく
	* @tips 領域のイベントの発生時んいこのメンバ関数を呼び出す事で
	* 登録したメンバ関数ポインタが呼び出される
	*/
	void callEventCallback(CCharacter* pChara, int event = 0);
};


//======================================
// 下にある画面端領域との衝突判定
//======================================
class CCollisionTerritoryEndOfScreenBottom:public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryEndOfScreenBottom(): CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// 上にある画面端領域との衝突判定
//======================================
class CCollisionTerritoryEndOfScreenTop :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryEndOfScreenTop() : CCollisionTerritory(TERRITORY_TYPE::TOP)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// 右にある画面端領域との衝突判定
//======================================
class CCollisionTerritoryEndOfScreenRight :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryEndOfScreenRight() : CCollisionTerritory(TERRITORY_TYPE::RIGHT)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// 左にある画面端領域との衝突判定
//======================================
class CCollisionTerritoryEndOfScreenLeft :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryEndOfScreenLeft() : CCollisionTerritory(TERRITORY_TYPE::LEFT)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// 下にある画面外領域との衝突判定
//======================================
class CCollisionTerritoryOutOfScreenBottom :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryOutOfScreenBottom();
	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// 上にある画面外領域との衝突判定
//======================================
class CCollisionTerritoryOutOfScreenTop :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryOutOfScreenTop();
	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//======================================
// 右にある画面外領域との衝突判定
//======================================
class CCollisionTerritoryOutOfScreenRight :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::RIGHTに設定しておく
	*/
	CCollisionTerritoryOutOfScreenRight();
	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//======================================
// 左にある画面外領域との衝突判定
//======================================
class CCollisionTerritoryOutOfScreenLeft :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::LEFTに設定しておく
	*/
	CCollisionTerritoryOutOfScreenLeft();
	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//======================================
// 下にあるマップチップ領域との衝突判定
//======================================
class CCollisionTerritoryMapChipBottom :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryMapChipBottom() : CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// 上にあるマップチップ領域との衝突判定
//======================================
class CCollisionTerritoryMapChipTop :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::TOPに設定しておく
	*/
	CCollisionTerritoryMapChipTop() : CCollisionTerritory(TERRITORY_TYPE::TOP)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
//　右にあるマップチップ領域との衝突判定
//======================================
class CCollisionTerritoryMapChipRight :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::RIGHTに設定しておく
	*/
	CCollisionTerritoryMapChipRight() : CCollisionTerritory(TERRITORY_TYPE::RIGHT)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// 左にあるマップチップ領域との衝突判定
//======================================
class CCollisionTerritoryMapChipLeft :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::LEFTに設定しておく
	*/
	CCollisionTerritoryMapChipLeft() : CCollisionTerritory(TERRITORY_TYPE::LEFT)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};

//======================================
// 衝突判定空間
//======================================
class CCollisionArea
{
protected:
	//衝突基準点群
	std::vector<CCollisionBasePoint*>* m_pBasePoints = NULL;

	//衝突判定領域群
	std::vector<CCollisionTerritory*>* m_pTerritories = NULL;

public:
	//コンストラクタ
	CCollisionArea()
	{
		//衝突基準点群の生成
		this->m_pBasePoints = new std::vector<CCollisionBasePoint*>();

		//衝突判定領域群の生成
		this->m_pTerritories = new std::vector<CCollisionTerritory*>();
	}

	//デストラクタ
	virtual ~CCollisionArea()
	{
		//衝突基準点群の解放
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints))
		{
			SAFE_DELETE(pBasePt);
		}
		SAFE_DELETE(this->m_pBasePoints);

		//衝突判定領域群の解放
		for (CCollisionTerritory* pTerritory : (*this->m_pTerritories))
		{
			SAFE_DELETE(pTerritory);
		}
		SAFE_DELETE(this->m_pTerritories);
	}


	/**
	* @desc 衝突基準点の追加
	* @param 衝突基準点
	*/
	virtual void addBasePoint(CCollisionBasePoint* pBasePoint)
	{
		this->m_pBasePoints->push_back(pBasePoint);
	}

	/**
	* @desc 衝突判定領域の追加
	* @param 衝突判定領域
	*/
	virtual void addTerritory(CCollisionTerritory* pTerritory)
	{
		this->m_pTerritories->push_back(pTerritory);
	}

	/**
	* @desc 衝突判定
	* @param 衝突判定のキャラクター
	* @tips 毎フレーム呼び出す
	*/
	virtual void collision(CCharacter* pChara) = 0;
};


//======================================
// 画面端との衝突判定空間
//======================================
class CCollisionAreaEndOfScreen : public CCollisionArea
{
public:
	//コンストラクタ
	CCollisionAreaEndOfScreen()
	{

	}

	/**
	* @desc コンストラクタ
	* @param 衝突判定用実体データ
	*/
	CCollisionAreaEndOfScreen(CBody* pBody);


	//デストラクタ
	~CCollisionAreaEndOfScreen()
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突判定のキャラクター
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// 画面外との衝突判定空間
//======================================
class CCollisionAreaOutOfScreen : public CCollisionArea
{
public:
	//コンストラクタ
	CCollisionAreaOutOfScreen();
	/**
	* @desc コンストラクタ
	* @param 衝突判定用実体データ
	*/
	CCollisionAreaOutOfScreen(CBody* pBody);


	//デストラクタ
	~CCollisionAreaOutOfScreen();

	/**
	* @desc 衝突判定
	* @param 衝突判定のキャラクター
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// 画面上にある全てのマップチップとの衝突判定空間
// （マップとの衝突判定空間）
//======================================
class CCollisionAreaMap : public CCollisionArea
{
public:
	//コンストラクタ
	CCollisionAreaMap()
	{

	}

	//デストラクタ
	~CCollisionAreaMap()
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突判定のキャラクター
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// 画面上にある全てのマップチップとの衝突判定空間
// （マップとの衝突判定空間）
//======================================
class CCollisionAreaLine : public CCollisionArea
{
public:
	//コンストラクタ
	CCollisionAreaLine()
	{

	}

	//デストラクタ
	~CCollisionAreaLine()
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突判定のキャラクター
	*/
	void collision(CCharacter* pChara)override;
};


//======================================
// 下にあるラインとの衝突判定
//======================================
class CCollisionTerritoryLineBottom :public CCollisionTerritory
{
public:
	/**
	* @desc コンストラクタ
	* 領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに設定しておく
	*/
	CCollisionTerritoryLineBottom() : CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
	{

	}

	/**
	* @desc 衝突判定
	* @param 衝突対象
	* @param 基準点
	*/
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
