#include "GameManager.h"
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#endif

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(): running(false){}

GameManager::~GameManager(){
    delete coin;
    delete hero;
}

GameManager* GameManager::getInstance(){
    if (instance == nullptr) {
        instance = new GameManager();
    }
    return instance;
}

void GameManager::init(){
    // Initialization logic
    CharacterBuilder builder;
    hero = builder.setHealth(69)
                    ->setStrength(3)
                    ->setGold(0)
                    ->getCharacter();
    hero->setPos(WIDTH/2, HEIGHT-3);

    coin = new Coin(*hero);

    std::cout << "Ballad of a Fallen Hero" << std::endl;
    initGrid(grid);
    // Load resources, set up initial state, etc.
}

void GameManager::start(){
    running = true;
    mainLoop();
}

void GameManager::stop(){
    running = false;
}

void GameManager::mainLoop(){
    hideCursor();

    while (running) {
        auto frameStart = std::chrono::steady_clock::now();

        // Handle input
        handleInput();

        // Update game state
        update();

        // Render the game
        renderer.render(grid, hero);

        // Cap the frame rate
        std::this_thread::sleep_until(frameStart + std::chrono::milliseconds(50)); // 20 FPS
    }

    showCursor();
}

void GameManager::initGrid(std::vector<std::vector<char>>& grid){
    // Resize the vector to the correct dimensions
    grid.resize(HEIGHT, std::vector<char>(WIDTH));

    // Initialize the array with the desired characters
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if ((i == 0 || i == HEIGHT - 1) && (j == 0 || j == WIDTH - 1)) {
                // Corners
                grid[i][j] = '+';
            } else if (i == 0 || i == HEIGHT - 1) {
                // Top and bottom borders
                grid[i][j] = '~';
            } else if (j == 0 || j == WIDTH - 1) {
                // Left and right borders
                grid[i][j] = '|';
            } else {
                // Interior
                j%2==0 ? grid[i][j] = ' ' : grid[i][j] = '.';
            }
        }
    }
}

void GameManager::updateGrid(){
    initGrid(grid);
    grid[hero->getPos().getY()][hero->getPos().getX()] = 'P';
}

void GameManager::handleInput() {
        // Example input handling
    if (inputHandler.isKeyPressed('A') && hero->getPos().getX() > 1) {
        hero->setPosX(-1);
    }
    if (inputHandler.isKeyPressed('D') && hero->getPos().getX() < WIDTH-2) {
        hero->setPosX(1);
    }
    if (inputHandler.isKeyPressed('W') && hero->getPos().getY() > 1) {
        hero->setPosY(-1);
    }
    if (inputHandler.isKeyPressed('S') && hero->getPos().getY() < HEIGHT-2) {
        hero->setPosY(1);
    }
    if (inputHandler.isKeyPressed(VK_SPACE)) {
        coin->applyEffect();
    }
}

void GameManager::update(){
    updateGrid();
}

void GameManager::hideCursor(){
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = false; // Set the cursor visibility to false
        SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
        std::cout << "\033[?25l"; // ANSI escape code to hide cursor on Unix-like systems
#endif

}

void GameManager::showCursor(){
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = true; // Set the cursor visibility to true
        SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
        std::cout << "\033[?25h"; // ANSI escape code to show cursor on Unix-like systems
#endif

}
