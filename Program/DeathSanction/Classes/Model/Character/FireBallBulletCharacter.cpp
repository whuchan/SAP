#include"FireBallBulletCharacter.h"

//�R���X�g���N�^
CFireBallBulletCharacter::CFireBallBulletCharacter()
{
	//�L�����N�^�[�^�C�v��G�L�����N�^�[�ɐݒ�
	this->m_charaType = CHARACTER_TYPE::BULLET;

}

//�f�X�g���N�^
CFireBallBulletCharacter::~CFireBallBulletCharacter()
{

}

/**
* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
* @param �}�b�v�`�b�vID
* ��ʒ[�̍ۂ͂O
*/
void CFireBallBulletCharacter::collisionBottomCallback(int event)
{
	//�W�����v���ĊJ������
	(*this->m_pActions)[0]->restart(this);
}

