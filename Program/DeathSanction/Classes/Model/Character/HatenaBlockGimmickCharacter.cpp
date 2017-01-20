#include"HatenaBlockGimmickCharacter.h"
#include "Data\LaunchTrigger\LaunchTrigger.h"
#include "Model\Character\PlayerCharacter.h"


//�R���X�g���N�^
CHatenaBlockGimmickCharacter::CHatenaBlockGimmickCharacter()
{


}

//�f�X�g���N�^
CHatenaBlockGimmickCharacter::~CHatenaBlockGimmickCharacter()
{

}


/**
* @desc �v���C���[�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CHatenaBlockGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara)
{
	CGimmickCharacter::hitsPlayerCharacter(pChara);

	if (pChara->m_pMove->m_pos.y < this->m_pMove->m_pos.y + this->m_pBody->m_bottom)
	{
		if (this->m_state == (int)STATE::NONE && pChara->m_state == (int)CPlayerCharacter::STATE::JUMPING)
		{
			//==================================
			// �����ł͏o���̏����o���g���K�[�Ƃ���
			// �o���X�P�W���[���[�Ɏ��t���邾��
			//==================================
			//�G�o���f�[�^�i�o���̏��j�̐���
			CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(
				ENEMY_TYPE::NOKONOKO,
				this->m_pMove->m_pos
			);

			//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
			CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

			//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
			CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

			this->m_state = (int)STATE::USED;
			this->m_intAnimationState = (int)STATE::USED;
		}
	}
}

/**
* @desc �G�Ƃ̏Փ˔����̏���
* @param �Փ˂��Ă����L�����N�^-
*/
void CHatenaBlockGimmickCharacter::hitsEnemyCharacter(CCharacter* pChara)
{

}

