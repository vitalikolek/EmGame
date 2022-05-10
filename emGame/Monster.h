#pragma once
#include "Default.h"
#include "Armor.h"
#include "Weapon.h"

class Monster : public Default {
protected:
	int damage = 0;
	int defence = 0;
public:
	Monster(int hp, int skillLvl, int damage, int defence) : Default(hp, skillLvl) {
		this->damage = damage;
		this->defence = defence;
	}

	int getDamage() {
		return this->damage;
	}

	int getDefence() {
		return this->defence;
	}

	~Monster() {
	}
};