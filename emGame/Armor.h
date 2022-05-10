#pragma once
#include "Unit.h"

class Armor {
protected:
	int defence = 0;
	string name = "";
public:
	Armor(int defence, string name) {
		this->defence = defence;
		this->name = name;
	}

	int getDefence() {
		return this->defence;
	}

	string getName() {
		return this->name;
	}

	void giveArmor(int num) {
		switch (num) {
		case 1:
			this->defence = 1;
			this->name = "Armor lvl 1";
			break;
		case 2:
			this->defence = 2;
			this->name = "Armor lvl 2";
			break;
		case 3:
			this->defence = 3;
			this->name = "Armor lvl 3";
			break;
		case 4:
			this->defence = 5;
			this->name = "Armor lvl 4";
			break;
		default:
			this->defence = 1;
			this->name = "Armor lvl 1";
			break;
		}
	}

	~Armor() {
	}
};