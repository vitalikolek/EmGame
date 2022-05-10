#pragma once
#include "Unit.h"

class Default : public Unit {
public:
	Default(int hp, int skillLvl) {
		this->hp = hp;
		this->skillLvl = skillLvl;
	}

	int getHp() {
		return this->hp;
	}

	int getSkillLvl() {
		return this->skillLvl;
	}

	void setHp(int hp) {
		this->hp = hp;
	}

	void setSkillLvl(int skillLvl) {
		this->skillLvl = skillLvl;
	}

	bool isDead() {
		if (this->hp <= 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void maxHitPoint() {
		this->maxHp = this->hp;
	}

	void hillHp() {
		this->hp += 30;
		if (this->hp > this->maxHp) {
			this->hp = this->maxHp;
		}
	}

	~Default() {
	}
};