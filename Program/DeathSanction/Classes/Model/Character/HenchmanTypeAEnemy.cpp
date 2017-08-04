#include "HenchmanTypeAEnemy.h"
#include "Lib\Input\InputManager.h"
#include "Model\Map\Map.h"

//コンストラクタ
CHenchmanTypeAEnemy::CHenchmanTypeAEnemy()
{
	//キャラクタータイプを敵キャラクターに設定
	this->m_charaType = CHARACTER_TYPE::ENEMY;

}

//デストラクタ
CHenchmanTypeAEnemy::~CHenchmanTypeAEnemy()
{

}
//EOF