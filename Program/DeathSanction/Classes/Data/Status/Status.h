#pragma once
//=========================================================================
// ƒXƒe[ƒ^ƒXƒNƒ‰ƒX
//=========================================================================

class CStatus {
public:
	CStatus() {}
	~CStatus() {}


private:
	// ‚g‚o
	float m_hp = 0;

	// Å‘å‚g‚o
	float m_maxHp = 0;

	// ƒXƒ^ƒ~ƒi
	float m_stamina = 0;

	// Å‘åƒXƒ^ƒ~ƒi
	float m_maxStamina = 0;


	// ‘¬“x
	float m_speed = 0;

	// UŒ‚—Í
	int m_attackPt = 0;

public:

	/**
	*	@desc İ’è
	*	@param ‚g‚o
	*	@param Å‘å‚g‚o
	*	@param UŒ‚—Í
	*	@param ˆÚ“®‘¬“x
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

	//ƒXƒs[ƒh‚ğİ’è‚·‚é
	void setSpeed(float speed) {
		this->m_speed = speed;
	}

	// ‚g‚o‚Ìæ“¾
	float getHp() {
		return this->m_hp;
	}

	// Å‘å‚g‚o‚Ìæ“¾
	float getmaxHp() {
		return this->m_maxHp;
	}

	// ƒXƒ^ƒ~ƒi‚Ìæ“¾
	float getStamina() {
		return this->m_stamina;
	}

	// Å‘åƒXƒ^ƒ~ƒi‚Ìæ“¾
	int getMaxStamina() {
		return this->m_maxStamina;
	}

	// UŒ‚—Í‚Ìæ“¾
	int getAttackPt() {
		return this->m_attackPt;
	}

	// ƒXƒs[ƒh‚Ìæ“¾
	float getSpeed() {
		return this->m_speed;
	}



	/**
	*	@desc ‚g‚o‚ÌŒ¸­
	*	@param Œ¸­‚·‚é’li‘Šè‚ÌUŒ‚—Íj
	*/

	void decreaseHP(int attackPt) {
		this->m_hp -= attackPt;

		if (this->m_hp < 0)
		{
			this->m_hp = 0;
		}
	}

	/**
	*	@desc Stamina‚ÌŒ¸­
	*	@param Œ¸­‚·‚éƒXƒ^ƒ~ƒi’li‘Šè‚ÌƒXƒ^ƒ~ƒij
	*/
	void decreaseStamina(int value) {
		this->m_stamina -= value;

		if (this->m_stamina < 0)
		{
			this->m_stamina = 0;
		}
	}

	/**
	*	@desc ‚g‚o‚Ì‘S‰ñ•œ
	*/

	void recoveryHp() {
		this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc ‚g‚o‚Ì‚P‰ñ•œ
	*/

	void CureHp(int hp) {
		this->m_hp += hp;
		if (this->m_hp > this->m_maxHp)
			this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc ƒXƒs[ƒh‚Ì‚PUP
	*/

	void SpeedVel(float speed) {
		this->m_speed += speed;

	}
	
};

