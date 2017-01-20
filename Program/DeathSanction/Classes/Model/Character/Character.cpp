#include "Character.h"

//�R���X�g���N�^
CCharacter::CCharacter()
{

}

//�f�X�g���N�^
CCharacter::~CCharacter()
{
	for (CCollisionArea* pCollisionArea : (*this->m_pCollisionAreas))
	{
		SAFE_DELETE(pCollisionArea);
	}

	SAFE_DELETE(this->m_pBody);
	
	for (CAction* pAction : (*m_pActions))
	{
		SAFE_DELETE(pAction);
	}

	SAFE_DELETE(this->m_pActions);
	for (CPhysical* pPhysical : (*m_pPhysicals))
	{
		SAFE_DELETE(pPhysical);
	}

	SAFE_DELETE(this->m_pPhysicals);
	SAFE_DELETE(this->m_pMove);

	for (CAnimation* pAnimation : (*m_pAnimations))
	{
		SAFE_DELETE(pAnimation);
	}
	SAFE_DELETE(this->m_pAnimations);
}

//����������
bool CCharacter::init()
{
	if (cocos2d::Sprite::init() == false)
	{
		CCLOG("CCharacter�̏������Ɏ��s");
		return false;
	}

	//update()�����o�Ăяo���֐�
	this->scheduleUpdate();

	return true;
}

//�X�V����
void CCharacter::update(float deltaTime)
{
	//�ړ�����
	this->moveFunc();

	//�A�j���[�V��������
	this->animationFunc();

	//��ԂƂ̏Փ˔��菈��
	this->collision();

	//��ԃ`�F�b�N
	this->checkState();

	//���f����
	this->applyFunc();
}

/**
* @desc �A�j���[�V�����f�[�^�Q�̒ǉ�
* @param �A�j���[�V�����f�[�^�Q
*/
void CCharacter::addAnimations(std::vector<CAnimation*>* pAnimations)
{
	//���Ƀf�[�^�������Ă�����x������
	if (this->m_pAnimations != NULL )
	{
		CCLOG("�������ɐݒ肳��Ă��܂�");
		return;
	}

	//�V�����f�[�^��ݒ肷��
	this->m_pAnimations = pAnimations;
}
/**
* @desc  �ړ��f�[�^�̒ǉ�
* @param�@�ړ��f�[�^
*/
void CCharacter::addMove(CMove* pMove)
{
	//���Ƀf�[�^�������Ă�����x������
	if (this->m_pMove != NULL)
	{
		CCLOG("�������ɐݒ肳��Ă��܂�");
		return;
	}

	//�V�����f�[�^��ݒ肷��
	this->m_pMove = pMove;
}
/**
* @desc		�������Z�f�[�^�Q�̒ǉ�
* @param	�������Z�f�[�^�Q
*/
void CCharacter::addPhysicals(std::vector<CPhysical*>* pPhysicals)
{ 
	//���Ƀf�[�^�������Ă�����x������
	if (this->m_pPhysicals != NULL)
	{
		CCLOG("�������ɐݒ肳��Ă��܂�");
		return;
	}

	//�V�����f�[�^��ݒ肷��
	this->m_pPhysicals = pPhysicals;
}
/**
* @desc		�A�N�V�����f�[�^�Q�̒ǉ�
* @param	�A�N�V�����f�[�^�Q
*/
void CCharacter::addActions(std::vector<CAction*>* pActions)
{ 
	//���Ƀf�[�^�������Ă�����x������
	if (this->m_pActions != NULL)
	{
		CCLOG("�������ɐݒ肳��Ă��܂�");
		return;
	}
	
	//�V�����f�[�^��ݒ肷��
	this->m_pActions = pActions;
}
/**
* @desc	���̃f�[�^�̒ǉ�
* @param�@���̃f�[�^
*/
void CCharacter::addBody(CBody* pBody)
{ 
	//���Ƀf�[�^�������Ă�����x������
	if (this->m_pBody != NULL)
	{
		CCLOG("�������ɐݒ肳��Ă��܂�");
		return;
	}

	//�V�����f�[�^��ݒ肷��
	this->m_pBody = pBody;
}

/**
* @desc	�Փ˔���̈�f�[�^�Q�̒ǉ�
* @param�@�Փ˔���̈�f�[�^�Q
*/
void CCharacter::addCollisionAreas(std::vector<CCollisionArea*>* pCollisionAreas)
{
	//���Ƀf�[�^�������Ă�����x������
	if (this->m_pCollisionAreas != NULL)
	{
		CCLOG("�������ɐݒ肳��Ă��܂�");
		return;
	}

	//�V�����f�[�^��ݒ肷��
	this->m_pCollisionAreas = pCollisionAreas;
}


/**
* @desc �A�j���[�V�����f�[�^�Q�̎擾
* @return �A�j���[�V�����f�[�^�Q
*/
std::vector<CAnimation*>* CCharacter::getAnimations(void)
{
	return this->m_pAnimations;
}


/**
* @desc �ړ��f�[�^�̎擾
* @return �ړ��f�[�^
*/
CMove* CCharacter::getMove(void)
{
	return this->m_pMove;
}

/**
* @desc �������Z�f�[�^�̎擾
* @return �������Z�f�[�^
*/
std::vector<CPhysical*>* CCharacter::getPhysicals(void)
{
	return this->m_pPhysicals;
}

/**
* @desc �A�N�V�����f�[�^�̎擾
* @return �A�N�V�����f�[�^
*/
std::vector<CAction*>*	CCharacter::getActions(void)
{
	return this->m_pActions;
}

/**
* @desc ���̃f�[�^�̎擾
* @return ���̃f�[�^
*/
CBody* CCharacter::getBody(void)
{
	return this->m_pBody;
}


/**
* @desc	�Փ˔���̈�f�[�^�Q�̎擾
* @return�@�Փ˔���̈�f�[�^�Q
*/
std::vector<CCollisionArea*>* CCharacter::getCollisionAreas()
{
	return this->m_pCollisionAreas;
}



//===============================================
// �L�����N�^�[�̏W����
//  �V���O���g���������đ��̃t�@�C���ň�����悤�ɂ��Ă���
//===============================================
//���L�C���X�^���X�{��
CCharacterAggregate* CCharacterAggregate::m_pSharedAggre = NULL;

/**
* @desc �R���X�g���N�^
*/
CCharacterAggregate::CCharacterAggregate()
{

}

/**
* @desc �f�X�g���N�^
*/
CCharacterAggregate::~CCharacterAggregate()
{

}

/**
* @desc ���L�C���X�^���X�̎擾
* @return ���L�C���X�^���X
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
* @desc ���L�C���X�^���X�̔j��
*/
void CCharacterAggregate::removeInstance()
{
	SAFE_DELETE(CCharacterAggregate::m_pSharedAggre);
}

/**
* @desc �L�����N�^�[�̏W�܂�̎Q�Ƃ�ݒ�
* @param �ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
*/
void CCharacterAggregate::set(std::vector<CCharacter*>* pCharacters)
{
	//���ɐݒ肳��Ă�����ݒ肵�Ȃ��悤�ɂ��Ă���
	if (this->m_pCharacters != NULL)
	{
		return;
	}

	this->m_pCharacters = pCharacters;
}

/**
* @desc �L�����N�^�[�̏W�܂���擾
* @return �L�����N�^�[�̏W�܂�
*/
std::vector<CCharacter*>* CCharacterAggregate::get(void)
{
	return this->m_pCharacters;
}

/**
* @desc �L�����N�^�[�P�̂��擾
* @param �Y���ԍ�
* @param �L�����N�^�[
*/
CCharacter* CCharacterAggregate::getAt(int index)
{
	//�ő吔�ȏ�Ȃ�NULL��Ԃ��悤�ɐݒ肵�Ă���
	if (this->m_pCharacters->size() <= index)
	{
		return NULL;
	}

	return (*this->m_pCharacters)[index];
}

/**
* @desc �^�O����肵�ăL�����N�^�[�P�̂��擾
* @param �^�O
* @return �L�����N�^�[
* ���݂��Ȃ����NULL��Ԃ�
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

	//���݂��Ȃ����NULL��Ԃ�
	return NULL;
}


/**
* @desc �L�����N�^�[�̒ǉ�
* @param �ǉ�����L�����N�^�[
*/
void CCharacterAggregate::add(CCharacter* pChara)
{
	this->m_pCharacters->push_back(pChara);
}

/**
* @desc �L�����N�^�[�̏W�܂�̎��t�����Ă��鐔���擾
* @return ���t�����Ă��鐔
*/
int CCharacterAggregate::getSize(void)
{
	return(int)this->m_pCharacters->size();
}