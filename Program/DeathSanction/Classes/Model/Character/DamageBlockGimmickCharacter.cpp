#include"DamageBlockGimmickCharacter.h"


//�R���X�g���N�^
CDamageBlockGimmickCharacter::CDamageBlockGimmickCharacter()
{


}

//�f�X�g���N�^
CDamageBlockGimmickCharacter::~CDamageBlockGimmickCharacter()
{

}

/**
* @desc �v���C���[�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CDamageBlockGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	CGimmickCharacter::hitsPlayerCharacter(pChara);
	
	CCLOG("���ɂ܂���");
}

/**
* @desc �G�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CDamageBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

