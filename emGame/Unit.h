#pragma once
#include <iostream>
#include <string>

using namespace std;

class Unit {
protected:
	int hp = 0;
	int maxHp = 0;
	int damage = 0;
	int protection = 0;
	int skillLvl = 0;
public:
	Unit() {
	}

	string speak() {
		return "???";
	}

	~Unit() {
	}
};