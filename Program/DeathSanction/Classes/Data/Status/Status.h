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
	int m_hp = 0;

	// 最大ＨＰ
	int m_maxHp = 0;

	// スタミナ
	int m_stamina = 0;

	// 最大スタミナ
	int m_maxStamina = 0;


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

	void set(	int hp, int maxHp,
				int stamina, int maxStamina,
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
	int getHp() {
		return this->m_hp;
	}

	// 最大ＨＰの取得
	int getmaxHp() {
		return this->m_maxHp;
	}

	// スタミナの取得
	int getStamina() {
		return this->m_stamina;
	}

	// 最大スタミナの取得
	int getMaxStamina() {
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
	*	@desc スピードの１UP
	*/

	void SpeedVel(float speed) {
		this->m_speed += speed;

	}
	
};

