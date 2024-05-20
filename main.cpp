#include "CoreComponents/GameManager.h"

int main() {
    system("cls");
    GameManager* gameManager = GameManager::getInstance();
    gameManager->init();
    gameManager->start();

    return 0;
}