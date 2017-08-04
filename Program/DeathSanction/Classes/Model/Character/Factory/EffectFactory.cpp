//==========================================
//
// File: EffectFactory.h
//
// �G�t�F�N�g�H��t�@�C��
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================
#include"EffectFactory.h"

/**
* @desc �R���X�g���N�^
*/
CEffectPartsFactory::CEffectPartsFactory()
{

}
/**
* @desc �f�X�g���N�^
*/
CEffectPartsFactory::~CEffectPartsFactory()
{

}


/**
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove*	CEffectPartsFactory::getMove(void)
{
	//�ړ��f�[�^�̍쐬
	return new CMove();
}


/**
* @desc ���̃f�[�^�̎擾
* @return ���̃f�[�^
*/
CBody*	CEffectPartsFactory::getBody(void)
{
	//���̃f�[�^�̍쐬
	return new CBody();
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̎擾
* @return �Փ˔���̈�f�[�^�Q
*/
std::vector<CCollisionArea*>* CEffectPartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}

/**
* @desc ��ԑJ�ڃ}�V���̎擾
* @return ��ԑJ�ڃ}�V���̃C���X�^���X
*/
CStateMachine* CEffectPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}
//EOF