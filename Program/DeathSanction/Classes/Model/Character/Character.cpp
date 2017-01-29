#include "Character.h"

//コンストラクタ
CCharacter::CCharacter()
{

}

//デストラクタ
CCharacter::~CCharacter()
{
	for (CCollisionArea* pCollisionArea : (*this->m_pCollisionAreas))
	{
		SAFE_DELETE(pCollisionArea);
	}

	SAFE_DELETE(this->m_pBody);

	//アクション群データの削除
	std::map<int, std::map<int,CAction*>*>::iterator iteratorActionStateIndex = this->m_mapAction.begin();
	while (iteratorActionStateIndex != this->m_mapAction.end()) {

		if (iteratorActionStateIndex->second)
		{
			std::map<int, CAction*>::iterator iteratorActionIndex = iteratorActionStateIndex->second->begin();

			while (iteratorActionIndex != iteratorActionStateIndex->second->end()) {

				//クラスのインスタンスを削除
				SAFE_DELETE(iteratorActionIndex->second);

				iteratorActionIndex++;
			}
			//クラスのインスタンスを削除
			SAFE_DELETE(iteratorActionStateIndex->second);
		}
		iteratorActionStateIndex++;
	}
	
	//物理演算データ群の削除
	std::map<int, std::vector<CPhysical*>* >::iterator iteratorPhysicalIndex = this->m_mapPhysical.begin();
	while (iteratorPhysicalIndex != this->m_mapPhysical.end()) {

		if (iteratorPhysicalIndex->second)
		{
			std::vector<CPhysical*>* pointerPhysicals = iteratorPhysicalIndex->second;

			for (CPhysical* pointerTarget : *pointerPhysicals)
			{
				SAFE_DELETE(pointerTarget);
			}
			//クラスのインスタンスを削除
			SAFE_DELETE(iteratorPhysicalIndex->second);
		}
		//イテレーターを更新
		iteratorPhysicalIndex++;
	}

	//アニメーションデータ群の削除
	std::map<int, CAnimation* >::iterator iteratorIndexAnimation = this->m_mapAnimation.begin();
	while (iteratorIndexAnimation != this->m_mapAnimation.end()) {
		//クラスのインスタンスを削除
		SAFE_DELETE(iteratorIndexAnimation->second);
		//イテレーターを更新
		iteratorIndexAnimation++;
	}

	SAFE_DELETE(this->m_pMove);
}

//初期化処理
bool CCharacter::init()
{
	if (cocos2d::Sprite::init() == false)
	{
		CCLOG("CCharacterの初期化に失敗");
		return false;
	}

	//update()メンバ呼び出し関数
	this->scheduleUpdate();

	return true;
}

//更新処理
void CCharacter::update(float deltaTime)
{
	//移動処理
	this->moveFunc();

	//アニメーション処理
	this->animationFunc();

	//空間との衝突判定処理
	this->collision();

	//状態チェック
	this->checkState();

	//反映処理
	this->applyFunc();
}

/**
* @desc アニメーションデータ群の追加
* @param アニメーションデータ群
*/
void CCharacter::addAnimations(std::vector<CAnimation*>* pAnimations)
{
	
}
/**
* @desc  移動データの追加
* @param　移動データ
*/
void CCharacter::addMove(CMove* pMove)
{
	//既にデータが入っていたら警告する
	if (this->m_pMove != NULL)
	{
		CCLOG("もう既に設定されています");
		return;
	}

	//新しいデータを設定する
	this->m_pMove = pMove;
}
/**
* @desc		物理演算データ群の追加
* @param	物理演算データ群
*/
void CCharacter::addPhysicals(std::vector<CPhysical*>* pPhysicals)
{ 
	
}
/**
* @desc		アクションデータ群の追加
* @param	アクションデータ群
*/
void CCharacter::addActions(std::vector<CAction*>* pActions)
{ 

}
/**
* @desc	実体データの追加
* @param　実体データ
*/
void CCharacter::addBody(CBody* pBody)
{ 
	//既にデータが入っていたら警告する
	if (this->m_pBody != NULL)
	{
		CCLOG("もう既に設定されています");
		return;
	}

	//新しいデータを設定する
	this->m_pBody = pBody;
}

/**
* @desc	衝突判定領域データ群の追加
* @param　衝突判定領域データ群
*/
void CCharacter::addCollisionAreas(std::vector<CCollisionArea*>* pCollisionAreas)
{
	//既にデータが入っていたら警告する
	if (this->m_pCollisionAreas != NULL)
	{
		CCLOG("もう既に設定されています");
		return;
	}

	//新しいデータを設定する
	this->m_pCollisionAreas = pCollisionAreas;
}

/**
* @desc 移動データの取得
* @return 移動データ
*/
CMove* CCharacter::getMove(void)
{
	return this->m_pMove;
}


/**
* @desc 実体データの取得
* @return 実体データ
*/
CBody* CCharacter::getBody(void)
{
	return this->m_pBody;
}


/**
* @desc	衝突判定領域データ群の取得
* @return　衝突判定領域データ群
*/
std::vector<CCollisionArea*>* CCharacter::getCollisionAreas()
{
	return this->m_pCollisionAreas;
}



//===============================================
// キャラクターの集合体
//  シングルトン化させて他のファイルで扱えるようにしておく
//===============================================
//共有インスタンス本体
CCharacterAggregate* CCharacterAggregate::m_pSharedAggre = NULL;

/**
* @desc コンストラクタ
*/
CCharacterAggregate::CCharacterAggregate()
{

}

/**
* @desc デストラクタ
*/
CCharacterAggregate::~CCharacterAggregate()
{

}

/**
* @desc 共有インスタンスの取得
* @return 共有インスタンス
*/
CCharacterAggregate* CCharacterAggregate::getInstance()
{
	if (CCharacterAggregate::m_pSharedAggre == NULL)
	{
		CCharacterAggregate::m_pSharedAggre = new CCharacterAggregate();
	}
	return CCharacterAggregate::m_pSharedAggre;
}

/**
* @desc 共有インスタンスの破棄
*/
void CCharacterAggregate::removeInstance()
{
	SAFE_DELETE(CCharacterAggregate::m_pSharedAggre);
}

/**
* @desc キャラクターの集まりの参照を設定
* @param 設定するキャラクターの集まりのアドレス
*/
void CCharacterAggregate::set(std::vector<CCharacter*>* pCharacters)
{
	//既に設定されていたら設定しないようにしておく
	if (this->m_pCharacters != NULL)
	{
		return;
	}

	this->m_pCharacters = pCharacters;
}

/**
* @desc キャラクターの集まりを取得
* @return キャラクターの集まり
*/
std::vector<CCharacter*>* CCharacterAggregate::get(void)
{
	return this->m_pCharacters;
}

/**
* @desc キャラクター１体を取得
* @param 添字番号
* @param キャラクター
*/
CCharacter* CCharacterAggregate::getAt(int index)
{
	//最大数以上ならNULLを返すように設定しておく
	if (this->m_pCharacters->size() <= index)
	{
		return NULL;
	}

	return (*this->m_pCharacters)[index];
}

/**
* @desc タグを特定してキャラクター１体を取得
* @param タグ
* @return キャラクター
* 存在しなければNULLを返す
*/
CCharacter* CCharacterAggregate::getAtTag(int tag)
{
	for(CCharacter* pChara : (*this->m_pCharacters))
	{
		if (pChara->m_tag == tag)
		{
			return pChara;
		}
	}

	//存在しなければNULLを返す
	return NULL;
}


/**
* @desc キャラクターの追加
* @param 追加するキャラクター
*/
void CCharacterAggregate::add(CCharacter* pChara)
{
	this->m_pCharacters->push_back(pChara);
}

/**
* @desc キャラクターの集まりの取り付けられている数を取得
* @return 取り付けられている数
*/
int CCharacterAggregate::getSize(void)
{
	return(int)this->m_pCharacters->size();
}