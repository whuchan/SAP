#pragma once
//=========================================================================
// ステータスクラス
//=========================================================================

class CStatus {
public:
	CStatus() {}
	~CStatus() {}


private:
	// ＨＰ
	float m_hp = 0;

	// 最大ＨＰ
	float m_maxHp = 0;

	// スタミナ
	float m_stamina = 0;

	// 最大スタミナ
	float m_maxStamina = 0;


	// 速度
	float m_speed = 0;

	// 攻撃力
	int m_attackPt = 0;

public:

	/**
	*	@desc 設定
	*	@param ＨＰ
	*	@param 最大ＨＰ
	*	@param 攻撃力
	*	@param 移動速度
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

	//スピードを設定する
	void setSpeed(float speed) {
		this->m_speed = speed;
	}

	// ＨＰの取得
	float getHp() {
		return this->m_hp;
	}

	// 最大ＨＰの取得
	float getmaxHp() {
		return this->m_maxHp;
	}

	// スタミナの取得
	float getStamina() {
		return this->m_stamina;
	}

	// 最大スタミナの取得
	float getMaxStamina() {
		return this->m_maxStamina;
	}

	// 攻撃力の取得
	int getAttackPt() {
		return this->m_attackPt;
	}

	// スピードの取得
	float getSpeed() {
		return this->m_speed;
	}



	/**
	*	@desc ＨＰの減少
	*	@param 減少する値（相手の攻撃力）
	*/

	void decreaseHP(int attackPt) {
		this->m_hp -= attackPt;

		if (this->m_hp < 0)
		{
			this->m_hp = 0;
		}
	}

	/**
	*	@desc Staminaの減少
	*	@param 減少するスタミナ値（相手のスタミナ）
	*/
	void decreaseStamina(float value) {
		this->m_stamina -= value;

		if (this->m_stamina < 0.0f)
		{
			this->m_stamina = 0.0f;
		}
	}

	/**
	*	@desc ＨＰの全回復
	*/

	void recoveryHp() {
		this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc ＨＰの１回復
	*/

	void CureHp(int hp) {
		this->m_hp += hp;
		if (this->m_hp > this->m_maxHp)
			this->m_hp = this->m_maxHp;
	}

	/**
	* @desc スタミナの回復
	*/
	void cureStamina(float value)
	{
		this->m_stamina += value;
		if (this->m_stamina >= this->m_maxStamina)
		{
			this->m_stamina = this->m_maxStamina;
		}
	}

	/**
	*	@desc スピードの１UP
	*/

	void SpeedVel(float speed) {
		this->m_speed += speed;

	}
	
};

