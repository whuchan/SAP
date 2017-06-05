#pragma once
#include "Data/Animation/Animation.h"
#include "Data/Physical/Physical.h"
#include "Data/ActionController/ActionController.h"
#include "Data/Collision/Collision.h"
#include "Data\Collision\CollisionArea.h"
#include "Data\StateMachine\StateMachine.h"

//==============================================
// �L�����N�^�[�^�C�v
//==============================================
enum class CHARACTER_TYPE : int
{
	NONE =	-1,	//����
	PLAYER	= 0,//�v���C���[
	ENEMY	= 1,//�G
	BULLET	= 2,//�v���C���[�e
	GIMMICK = 3,//�M�~�b�N
	DAMAGE	= 4,//�_���[�W
	EFFECT	= 5,//�G�t�F�N�g
};



//==============================================
// �L�����N�^�[�N���X
//�@�S�ẴL�����N�^�[�̐��`�ƂȂ钊�ۃN���X
//
//==============================================
class CCharacter : public cocos2d::Sprite 
{
public:
	//�R���X�g���N�^
	CCharacter();

	//�f�X�g���N�^
	virtual ~CCharacter();

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update(float deltaTime)override;

	//�ړ��f�[�^
	CMove* m_pMove = NULL;

	//�e�̔��˕����̃x�N�g��
	cocos2d::Vec2 m_shotLaunchVector = cocos2d::Vec2(0.0f,0.0f);

	//���̃f�[�^�i�Փ˔���f�[�^�̌��ƂȂ�f�[�^)
	CBody* m_pBody = NULL;

	//�Փ˔����ԌQ
	std::vector <CCollisionArea*>* m_pCollisionAreas = NULL;

	//�A�j���V�����f�[�^�Q�}�b�v�z��
	std::map<int,CAnimation*>				m_mapAnimation;

	//�K�p�����镨�����Z�Q�}�b�v�z��
	std::map<int, std::vector<CPhysical*>*> m_mapPhysical;

	//�A�N�V�����f�[�^�Q�}�b�v�z��
	std::map<int, std::map<int,CAction*>*> m_mapAction;


	//��ԁi�h����ɂ���ă^�C�v���ω�����j
	int m_state = 0;

	//��ԑJ�ڃ}�V��
	CStateMachine* m_stateMachine = NULL;

	//�K�p�����镨�����Z�̏�ԁi�h����ɂ���ă^�C�v���ω�����j
	int m_intPhysicalState = 0;
	
	//�s����A�N�V�����̏�ԁi�h����ɂ���ă^�C�v���ω�����j
	int m_intActionState = 0;

	//�A�j���[�V�����̏�ԁi�h����ɂ���ă^�C�v���ω�����j
	int m_intAnimationState = 0;

	int m_intCurrentLine = 0;

	//�L���t���O
	bool m_activeFlag = false;

	//�^�O
	int m_tag = 0;

	//�����Ă��邩����ł��邩�̃t���O
	//true...�����Ă��� false...����ł���
	bool m_isAlive = false;

	//�L�����N�^�[�^�C�v
	CHARACTER_TYPE m_charaType = CHARACTER_TYPE::NONE;

protected:
	//�ړ�����
	virtual void moveFunction(float deltaTime) = 0;
	//�A�j���[�V��������
	virtual void animationFunction(float deltaTime) = 0;
	//��ԂƂ̏Փ˔��菈��
	virtual void collision() = 0;
	//��ԃ`�F�b�N
	virtual void checkState(float deltaTime) = 0;
	//���f����
	virtual void applayFunction() = 0;

public:

	/**
	* @desc �L�����N�^�[�P�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	virtual bool collision(CCharacter* pChara) = 0;

	/**
	* @desc �Փ˔����̏���
	* @param �Փ˂��Ă����L�����N�^-
	*/
	virtual void hits(CCharacter* pChara) = 0;


	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionBottomCallback(int event)
	{

	}

	/**
	* @desc ��̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionTopCallback(int event)
	{

	}

	/**
	* @desc �E�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionRightCallback(int event)
	{

	}

	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	* ��ʒ[�̍ۂ͂O
	*/
	virtual void collisionLeftCallback(int event)
	{

	}

	/**
	* @desc �A�j���[�V�����f�[�^�Q�̒ǉ�
	* @param �A�j���[�V�����f�[�^�Q
	*/
	void addAnimations(std::vector<CAnimation*>* pAnimations);
	/**
	* @desc  �ړ��f�[�^�̒ǉ�
	* @param�@�ړ��f�[�^
	*/
	void addMove(CMove* pMove);
	/**
	* @desc		�������Z�f�[�^�Q�̒ǉ�
	* @param	�������Z�f�[�^�Q
	*/
	void addPhysicals(std::vector<CPhysical*>* pPhysicals);
	/**
	* @desc		�A�N�V�����f�[�^�Q�̒ǉ�
	* @param	�A�N�V�����f�[�^�Q
	*/
	void addActions(std::vector<CAction*>* pActions);
	/**
	* @desc	���̃f�[�^�̒ǉ�
	* @param�@���̃f�[�^
	*/
	void addBody(CBody* pBody);

	/**
	* @desc	�Փ˔���̈�f�[�^�Q�̒ǉ�
	* @param�@�Փ˔���̈�f�[�^�Q
	*/
	void addCollisionAreas(std::vector<CCollisionArea*>* pCollisionAreas);

	/**
	* @desc	��ԑJ�ڃ}�V���̒ǉ�
	* @param�@��ԑJ�ڃ}�V��
	*/
	void addStateMachine(CStateMachine* pStateMachine);


	/**
	* @desc �ړ��f�[�^�̎擾
	* @return �ړ��f�[�^
	*/
	CMove* getMove(void);


	/**
	* @desc ���̃f�[�^�̎擾
	* @return ���̃f�[�^
	*/
	CBody* getBody(void);

	/**
	* @desc	�Փ˔���̈�f�[�^�Q�̎擾
	* @return�@�Փ˔���̈�f�[�^�Q
	*/
	std::vector<CCollisionArea*>* getCollisionAreas(void);
};

//===============================================
// �L�����N�^�[�̏W����
// �V���O���g���������đ��̃t�@�C����������悤�ɂ��Ă���
//===============================================
class CCharacterAggregate
{
private:
	//===============================================
	// �V���O���g���ݒ�͂�������
	//===============================================
	//���L�C���X�^���X
	static CCharacterAggregate* m_pSharedAggre;

	/**
	* @desc �R���X�g���N�^
	*/
	CCharacterAggregate();

public:
	/**
	* @desc �f�X�g���N�^
	*/
	~CCharacterAggregate();

	/**
	* @desc ���L�C���X�^���X�̎擾	
	*/
	static CCharacterAggregate* getInstance();
	
	/**
	* @desc ���L�C���X�^���X�̔j��
	*/
	static void removeInstance();
	//===============================================
	// �V���O���g���ݒ�͂����܂�
	//===============================================

private:
	//�L�����N�^�[�̏W�܂�
	std::vector<CCharacter*>* m_pCharacters = NULL;

public:
	/**
	* @desc �L�����N�^�[�̏W�܂�̎Q�Ƃ�ݒ�
	* @param �ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
	*/
	void set(std::vector<CCharacter*>* pCharacters);

	/**
	* @desc �L�����N�^�[�̏W�܂���擾
	* @return �L�����N�^�[�̏W�܂�
	*/
	std::vector<CCharacter*>* get(void);

	/**
	* @desc �L�����N�^�[�P�̂��擾
	* @param �Y���ԍ�
	* @param �L�����N�^�[
	*/
	CCharacter* getAt(int index);

	/**
	* @desc �^�O����肵�ăL�����N�^�[�P�̂��擾
	* @param �^�O
	* @return �L�����N�^�[
	* ���݂��Ȃ����NULL��Ԃ�
	*/
	CCharacter* getAtTag(int tag);

	/**
	* @desc �L�����N�^�[�̒ǉ�
	* @param �ǉ�����L�����N�^�[
	*/
	void add(CCharacter* pChara);

	/**
	* @desc �L�����N�^�[�̏W�܂�̎��t�����Ă��鐔���擾
	* @return ���t�����Ă��鐔
	*/
	int getSize(void);
};
//EOF