#pragma once
#include "Unit.h"

class Weapon {
protected:
	int damage = 0;
	string weaponName = "";
public:
	Weapon(int damage, string weaponName) {
		this->damage = damage;
		this->weaponName = weaponName;
	}

	int getDamage() {
		return this->damage;
	}

	string getName() {
		return this->weaponName;
	}

	~Weapon() {
	}
};