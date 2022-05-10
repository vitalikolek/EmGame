#pragma once
#include "Player.h"
#include <fstream>

using namespace std;

class SaveGame {
private:
    ifstream ifstream;
public:
	SaveGame() {
	}

    bool save(Player* player) {
        ofstream outputFile;

        outputFile.open("saveGameProgres.txt", ofstream::app);

        if (!outputFile.is_open()) {
            cout << "Error!";
            return false;
        }

        outputFile.write((char*)player, sizeof(Player));

        outputFile.close();

        cout << endl << "file saved";

        return true;
    }

    bool isHaveSave() {
        this->ifstream;

        ifstream.open("saveGameProgres.txt");

        if (!ifstream.is_open()) {
            return false;
        }
        else {
            return true;
        }
    }

    Player* load() {
        this->ifstream;
        Player* player = new Player(0, 0);

        isHaveSave();

        ifstream.read((char*)player, sizeof(Player));

        ifstream.close();

        return player;
    }

	~SaveGame() {
	}
};

