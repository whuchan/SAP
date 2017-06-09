#pragma once
//=========================================================================
// �X�e�[�^�X�N���X
//=========================================================================

class CStatus {
public:
	CStatus() {}
	~CStatus() {}


private:
	// �g�o
	float m_hp = 0;

	// �ő�g�o
	float m_maxHp = 0;

	// �X�^�~�i
	float m_stamina = 0;

	// �ő�X�^�~�i
	float m_maxStamina = 0;


	// ���x
	float m_speed = 0;

	// �U����
	int m_attackPt = 0;

public:

	/**
	*	@desc �ݒ�
	*	@param �g�o
	*	@param �ő�g�o
	*	@param �U����
	*	@param �ړ����x
	*/

	void set(	float hp, float maxHp,
				float stamina, float maxStamina,
				int attackPt,int speed) {

		this->m_hp = hp;
		this->m_maxHp = maxHp;
		this->m_stamina = stamina;
		this->m_maxStamina = maxStamina;
		this->m_attackPt = attackPt;
		this->m_speed = speed; 

	}

	//�X�s�[�h��ݒ肷��
	void setSpeed(float speed) {
		this->m_speed = speed;
	}

	// �g�o�̎擾
	float getHp() {
		return this->m_hp;
	}

	// �ő�g�o�̎擾
	float getmaxHp() {
		return this->m_maxHp;
	}

	// �X�^�~�i�̎擾
	float getStamina() {
		return this->m_stamina;
	}

	// �ő�X�^�~�i�̎擾
	int getMaxStamina() {
		return this->m_maxStamina;
	}

	// �U���͂̎擾
	int getAttackPt() {
		return this->m_attackPt;
	}

	// �X�s�[�h�̎擾
	float getSpeed() {
		return this->m_speed;
	}



	/**
	*	@desc �g�o�̌���
	*	@param ��������l�i����̍U���́j
	*/

	void decreaseHP(int attackPt) {
		this->m_hp -= attackPt;

		if (this->m_hp < 0)
		{
			this->m_hp = 0;
		}
	}

	/**
	*	@desc Stamina�̌���
	*	@param ��������X�^�~�i�l�i����̃X�^�~�i�j
	*/
	void decreaseStamina(int value) {
		this->m_stamina -= value;

		if (this->m_stamina < 0)
		{
			this->m_stamina = 0;
		}
	}

	/**
	*	@desc �g�o�̑S��
	*/

	void recoveryHp() {
		this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc �g�o�̂P��
	*/

	void CureHp(int hp) {
		this->m_hp += hp;
		if (this->m_hp > this->m_maxHp)
			this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc �X�s�[�h�̂PUP
	*/

	void SpeedVel(float speed) {
		this->m_speed += speed;

	}
	
};

