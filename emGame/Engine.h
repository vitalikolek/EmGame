#pragma once
#include "Monster.h"
#include "Player.h"

#include <conio.h>
#include <Windows.h>

class Engine {
protected:
	bool gameOver = true;
public:
	Engine() {
	};

	void setUp() {
		this->gameOver = false;
	}

	void punchPlayer(Player* player, Monster* mob) {
		if (player->getPlayerDefence() > mob->getDamage()) {
		}
		else {
			player->setHp(player->getHp() - (mob->getDamage() - player->getPlayerDefence()));
		}
	}

	void punchMonster(Player* player, Monster* mob) {
		if (mob->getDefence() > player->getPlayerDamage()) {
		}
		else {
			mob->setHp(mob->getHp() - (player->getPlayerDamage() - mob->getDefence()));
		}
	}

	Weapon* choiceWeapon() {
		int ch = 0;
		int damage = 0;
		string weaponName = "";

		cout << "ќберiть зброю: " << endl;
		cout << "1 - Glock, 2 - Updated Glock, 3 - Magnum, 4 - MP-40" << endl;
		cin >> ch;

		switch (ch) {
		case 1:
			damage = 3;
			weaponName = "Glock";
			break;
		case 2:
			damage = 5;
			weaponName = "Updated Glock";
			break;
		case 3:
			damage = 7;
			weaponName = "Magnum";
			break;
		case 4:
			damage = 10;
			weaponName = "MP-40";
			break;
		default:
			damage = 3;
			weaponName = "Glock";
			break;
		}

		Weapon* object = new Weapon(damage, weaponName);

		return object;
	}

	Armor* choiceArmor() {
		int ch = 0;
		int defence = 0;
		string armorName = "";

		cout << "оберiть броню: " << endl;
		cout << "1 - armor lvl 1, 2 - armor lvl 2, 3 - armor lvl 3, 4 - armor lvl 4" << endl;
		cin >> ch;

		switch (ch) {
		case 1:
			defence = 1;
			armorName = "Armor lvl 1";
			break;
		case 2:
			defence = 2;
			armorName = "Armor lvl 2";
			break;
		case 3:
			defence = 3;
			armorName = "Armor lvl 3";
			break;
		case 4:
			defence = 5;
			armorName = "Armor lvl 4";
			break;
		default:
			defence = 1;
			armorName = "Armor lvl 1";
			break;
		}

		Armor* object = new Armor(defence, armorName);

		return object;
	}

	void fight(Player* player, Monster* monster) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'f':
				punchMonster(player, monster);
				if (int randNum = rand() % 2 == 1) {
					punchPlayer(player, monster);
				}
				break;
			}
		}
	}

	void firstRound(Player* player) {
		if (player->getSkillLvl() == 0) {
			Monster* firstMonster = new Monster(50, 0, 4, 1);
			player->maxHitPoint();

			player->setWeapon(choiceWeapon());
			player->setArmor(choiceArmor());
			//!firstMonster->isDead() || !player->isDead()
			
			cout << "First round" << endl;
			Sleep(1000);

			while (!firstMonster->isDead()) {
				system("cls");
				fight(player, firstMonster);
				cout << "Your hp: " << player->getHp() << endl;
				cout << "Monster hp: " << firstMonster->getHp();
				if (firstMonster->isDead() == true) {
					player->setSkillLvl(player->getSkillLvl());
					player->lvlUp();
				}
				player->isDead();
			}
			player->hillHp();
		}
	}

	void secondRound(Player* player) {
		if (player->getSkillLvl() == 1) {
			Monster* firstMonster = new Monster(55, 0, 5, 1);

			cout << endl << "Second round" << endl;
			Sleep(1000);

			while (!firstMonster->isDead()) {
				system("cls");
				fight(player, firstMonster);
				cout << "Your hp: " << player->getHp() << endl;
				cout << "Monster hp: " << firstMonster->getHp();
				if (firstMonster->isDead() == true) {
					player->setSkillLvl(player->getSkillLvl());
					player->lvlUp();
				}
				player->isDead();
			}
			player->hillHp();
		}
	}

	~Engine() {
	};
};