#pragma once
#include "Data/Animation/Animation.h"
#include "Data/Physical/Physical.h"
#include "Data/ActionController/ActionController.h"
#include "Data/Collision/Collision.h"
#include "Data\Collision\CollisionArea.h"
#include "Data\StateMachine\StateMachine.h"

//==============================================
// キャラクタータイプ
//==============================================
enum class CHARACTER_TYPE : int
{
	NONE =	-1,	//無し
	PLAYER	= 0,//プレイヤー
	ENEMY	= 1,//敵
	BULLET	= 2,//プレイヤー弾
	GIMMICK = 3,//ギミック
	DAMAGE	= 4,//ダメージ
	EFFECT	= 5,//エフェクト
};



//==============================================
// キャラクタークラス
//　全てのキャラクターの雛形となる抽象クラス
//
//==============================================
class CCharacter : public cocos2d::Sprite 
{
public:
	//コンストラクタ
	CCharacter();

	//デストラクタ
	virtual ~CCharacter();

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update(float deltaTime)override;

	//移動データ
	CMove* m_pMove = NULL;

	//弾の発射方向のベクトル
	cocos2d::Vec2 m_shotLaunchVector = cocos2d::Vec2(0.0f,0.0f);

	//実体データ（衝突判定データの元となるデータ)
	CBody* m_pBody = NULL;

	//衝突判定空間群
	std::vector <CCollisionArea*>* m_pCollisionAreas = NULL;

	//アニメションデータ群マップ配列
	std::map<int,CAnimation*>				m_mapAnimation;

	//適用させる物理演算群マップ配列
	std::map<int, std::vector<CPhysical*>*> m_mapPhysical;

	//アクションデータ群マップ配列
	std::map<int, std::map<int,CAction*>*> m_mapAction;


	//状態（派生先によってタイプが変化する）
	int m_state = 0;

	//状態遷移マシン
	CStateMachine* m_stateMachine = NULL;

	//適用させる物理演算の状態（派生先によってタイプが変化する）
	int m_intPhysicalState = 0;
	
	//行えるアクションの状態（派生先によってタイプが変化する）
	int m_intActionState = 0;

	//アニメーションの状態（派生先によってタイプが変化する）
	int m_intAnimationState = 0;

	int m_intCurrentLine = 0;

	//有効フラグ
	bool m_activeFlag = false;

	//タグ
	int m_tag = 0;

	//生きているか死んでいるかのフラグ
	//true...生きている false...死んでいる
	bool m_isAlive = false;

	//キャラクタータイプ
	CHARACTER_TYPE m_charaType = CHARACTER_TYPE::NONE;

protected:
	//移動処理
	virtual void moveFunction(float deltaTime) = 0;
	//アニメーション処理
	virtual void animationFunction(float deltaTime) = 0;
	//空間との衝突判定処理
	virtual void collision() = 0;
	//状態チェック
	virtual void checkState(float deltaTime) = 0;
	//反映処理
	virtual void applayFunction() = 0;

public:

	/**
	* @desc キャラクター１体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	virtual bool collision(CCharacter* pChara) = 0;

	/**
	* @desc 衝突判定後の処理
	* @param 衝突してきたキャラクタ-
	*/
	virtual void hits(CCharacter* pChara) = 0;


	/**
	* @desc 下領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionBottomCallback(int event)
	{

	}

	/**
	* @desc 上領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionTopCallback(int event)
	{

	}

	/**
	* @desc 右領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionRightCallback(int event)
	{

	}

	/**
	* @desc 左領域と衝突した際のイベントコールバック
	* @param マップチップID
	* 画面端の際は０
	*/
	virtual void collisionLeftCallback(int event)
	{

	}

	/**
	* @desc アニメーションデータ群の追加
	* @param アニメーションデータ群
	*/
	void addAnimations(std::vector<CAnimation*>* pAnimations);
	/**
	* @desc  移動データの追加
	* @param　移動データ
	*/
	void addMove(CMove* pMove);
	/**
	* @desc		物理演算データ群の追加
	* @param	物理演算データ群
	*/
	void addPhysicals(std::vector<CPhysical*>* pPhysicals);
	/**
	* @desc		アクションデータ群の追加
	* @param	アクションデータ群
	*/
	void addActions(std::vector<CAction*>* pActions);
	/**
	* @desc	実体データの追加
	* @param　実体データ
	*/
	void addBody(CBody* pBody);

	/**
	* @desc	衝突判定領域データ群の追加
	* @param　衝突判定領域データ群
	*/
	void addCollisionAreas(std::vector<CCollisionArea*>* pCollisionAreas);

	/**
	* @desc	状態遷移マシンの追加
	* @param　状態遷移マシン
	*/
	void addStateMachine(CStateMachine* pStateMachine);


	/**
	* @desc 移動データの取得
	* @return 移動データ
	*/
	CMove* getMove(void);


	/**
	* @desc 実体データの取得
	* @return 実体データ
	*/
	CBody* getBody(void);

	/**
	* @desc	衝突判定領域データ群の取得
	* @return　衝突判定領域データ群
	*/
	std::vector<CCollisionArea*>* getCollisionAreas(void);
};

//===============================================
// キャラクターの集合体
// シングルトン化させて他のファイルを扱えるようにしておく
//===============================================
class CCharacterAggregate
{
private:
	//===============================================
	// シングルトン設定はここから
	//===============================================
	//共有インスタンス
	static CCharacterAggregate* m_pSharedAggre;

	/**
	* @desc コンストラクタ
	*/
	CCharacterAggregate();

public:
	/**
	* @desc デストラクタ
	*/
	~CCharacterAggregate();

	/**
	* @desc 共有インスタンスの取得	
	*/
	static CCharacterAggregate* getInstance();
	
	/**
	* @desc 共有インスタンスの破棄
	*/
	static void removeInstance();
	//===============================================
	// シングルトン設定はここまで
	//===============================================

private:
	//キャラクターの集まり
	std::vector<CCharacter*>* m_pCharacters = NULL;

public:
	/**
	* @desc キャラクターの集まりの参照を設定
	* @param 設定するキャラクターの集まりのアドレス
	*/
	void set(std::vector<CCharacter*>* pCharacters);

	/**
	* @desc キャラクターの集まりを取得
	* @return キャラクターの集まり
	*/
	std::vector<CCharacter*>* get(void);

	/**
	* @desc キャラクター１体を取得
	* @param 添字番号
	* @param キャラクター
	*/
	CCharacter* getAt(int index);

	/**
	* @desc タグを特定してキャラクター１体を取得
	* @param タグ
	* @return キャラクター
	* 存在しなければNULLを返す
	*/
	CCharacter* getAtTag(int tag);

	/**
	* @desc キャラクターの追加
	* @param 追加するキャラクター
	*/
	void add(CCharacter* pChara);

	/**
	* @desc キャラクターの集まりの取り付けられている数を取得
	* @return 取り付けられている数
	*/
	int getSize(void);
};
//EOF