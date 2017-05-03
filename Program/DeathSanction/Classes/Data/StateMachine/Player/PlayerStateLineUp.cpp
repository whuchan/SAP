#include"PlayerStateLineUp.h"
#include "Model\Character\PlayerCharacter.h"
#include "Lib\Input\InputManager.h"

using namespace cocos2d;

//==========================================
//
// Class: CPlayerStateLineUp
//
// �v���C���[ ���C���A�b�v ��ԃN���X
//
// 2017/05/03
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerStateLineUp::CPlayerStateLineUp(CPlayerCharacter* const pOwner) :CPlayerState(pOwner)
{

}

/**
* @desc	�f�X�g���N�^
*/
CPlayerStateLineUp::~CPlayerStateLineUp(void)
{

}

/**
* @desc	�J�n����
*/
void CPlayerStateLineUp::enter(void)
{
	this->m_pOwner->m_intCurrentLine++;

	// 1�b�����āA�X�P�[�����k������
	ScaleTo* pOrder = ScaleTo::create(0.5, 1.0f - this->m_pOwner->m_intCurrentLine * 0.2f);
	this->m_pAction = this->m_pOwner->runAction(pOrder);
	CC_SAFE_RETAIN(this->m_pAction); // ����ɊJ������Ȃ��悤�ɎQ�ƃJ�E���^�𑝂₷

	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
	//(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::ACTION::JUMP])[0]->start();

	this->m_pOwner->m_pMove->m_vel.y = sqrtf(((CPhysicalGravity::GRAVITY * 30.0f) * (CPhysicalGravity::GRAVITY * 30.0f)) / 2.0f);
}

/**
* @desc	�X�V����
*/
void CPlayerStateLineUp::execute(float deltaTime)
{
#ifdef _DEBUG_PLAYER_STATE
	log("Player: LineUp");
#endif //_DEBUG_PLAYER_STATE
	if (this->m_pAction->isDone())
	{
		//�ҋ@��Ԃֈڍs
		this->toIdle();
		return;
	}

	static float vel = 0.0f;

	//this->m_pOwner->m_pMove->m_vel.y = sqrtf(((CPhysicalGravity::GRAVITY * 1.0f) * (CPhysicalGravity::GRAVITY * 1.0f))/2.0f) * deltaTime;

	//this->m_pOwner->m_pMove->m_vel.y *= 300.0f;

	//vel += this->m_pOwner->m_pMove->m_vel.y;

	//log("���x%f", this->m_pOwner->m_pMove->m_vel.y);

	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
	//(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::ACTION::JUMP])[0]->start();
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerStateLineUp::exit(void)
{
	this->m_isNext = false;

	//�g��Ȃ��Ȃ�����������
	CC_SAFE_RELEASE(this->m_pAction);

	//(*this->m_pOwner->m_mapAction[(int)CPlayerCharacter::ACTION::JUMP])[0]->restart(this->m_pOwner);
}
//EOF