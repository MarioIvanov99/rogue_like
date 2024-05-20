#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Renderer.h"
#include "InputHandler.h"
#include "../Entities/Coin.h"
#include <vector>

const int WIDTH = 39;
const int HEIGHT = 10;

class GameManager {
    private:
        static GameManager* instance;
        Character* hero;
        Coin* coin;
        bool running;
        std::vector<std::vector<char>> grid;
        Renderer renderer;
        InputHandler inputHandler;
        
        GameManager();
        ~GameManager();

    public:
        static GameManager* getInstance();
        void init();
        void start();
        void stop();

    private:
        void mainLoop();
        void initGrid(std::vector<std::vector<char>>&);
        void updateGrid();
        void handleInput();
        void update();
        void hideCursor();
        void showCursor();
};

#endif // GAMEMANAGER_H