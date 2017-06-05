//==========================================
//
// File: DamageFactory.h
//
// �_���[�W�H�� �t�@�C��
//
// 2017/06/06
//						Author Shinya Ueba
//==========================================


#include"DamageFactory.h"

/**
* @desc �R���X�g���N�^
*/
CDamagePartsFactory::CDamagePartsFactory()
{

}
/**
* @desc �f�X�g���N�^
*/
CDamagePartsFactory::~CDamagePartsFactory()
{

}


/**
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove*	CDamagePartsFactory::getMove(void)
{
	//�ړ��f�[�^�̍쐬
	return new CMove();
}


/**
* @desc ���̃f�[�^�̎擾
* @return ���̃f�[�^
*/
CBody*	CDamagePartsFactory::getBody(void)
{
	//���̃f�[�^�̍쐬
	return new CBody();
}

/**
* @desc �Փ˔���̈�f�[�^�Q�̎擾
* @return �Փ˔���̈�f�[�^�Q
*/
std::vector<CCollisionArea*>* CDamagePartsFactory::getCollisionAreas(void)
{
	return new std::vector<CCollisionArea*>();
}

/**
* @desc ��ԑJ�ڃ}�V���̎擾
* @return ��ԑJ�ڃ}�V���̃C���X�^���X
*/
CStateMachine* CDamagePartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}
//EOF