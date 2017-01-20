#include"FireBallBulletCharacter.h"

//コンストラクタ
CFireBallBulletCharacter::CFireBallBulletCharacter()
{
	//キャラクタータイプを敵キャラクターに設定
	this->m_charaType = CHARACTER_TYPE::BULLET;

}

//デストラクタ
CFireBallBulletCharacter::~CFireBallBulletCharacter()
{

}

/**
* @desc 下領域と衝突した際のイベントコールバック
* @param マップチップID
* 画面端の際は０
*/
void CFireBallBulletCharacter::collisionBottomCallback(int event)
{
	//ジャンプを再開させる
	(*this->m_pActions)[0]->restart(this);
}

