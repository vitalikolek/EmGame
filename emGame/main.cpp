#include <locale>
#include "Engine.h"
#include "SaveGame.h"

int main() {
    setlocale(LC_ALL, "");
    Engine* gameEngine = new Engine();
    SaveGame* saveGame = new SaveGame();

    if (saveGame->isHaveSave() == true) {
        saveGame->load();
        gameEngine->secondRound(saveGame->load());
        saveGame->save(saveGame->load());
    }
    else {
        Player* player = new Player(100, 0);
        gameEngine->firstRound(player);
        saveGame->save(player);
        gameEngine->secondRound(player);
        saveGame->save(player);
    }
}