#pragma once
#include "Default.h"
#include "Armor.h"
#include "Weapon.h"

class Player : public Default {
protected:
	Weapon* playerWeapn = NULL;
	Armor* playerArmor = NULL;
public:
	Player(int hp, int skillLvl) : Default(hp, skillLvl) {
	}

	void setWeapon(Weapon* weapon) {
		this->playerWeapn = weapon;
	}

	void setArmor(Armor* armor) {
		this->playerArmor = armor;
	}

	int getPlayerDamage() {
		return this->playerWeapn->getDamage();
	}

	int getPlayerDefence() {
		return this->playerArmor->getDefence();
	}

	void lvlUp() {
		this->maxHp += 10;
		this->hp += 10;
		this->skillLvl += 1;
		this->damage += 1;
	}

	~Player() {
	}
};