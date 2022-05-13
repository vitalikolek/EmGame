#include <locale>
#include "Engine.h"
#include "SaveGame.h"

int main() {
    setlocale(LC_ALL, "");
    Engine* gameEngine = new Engine();
    SaveGame* saveGame = new SaveGame();

    Player* player = new Player(100, 0);

    if (saveGame->isHaveSave() == true) {
        player = saveGame->load();
    }

    gameEngine->firstRound(player);
    saveGame->save(player);
    gameEngine->secondRound(player);
    saveGame->save(player);
}
