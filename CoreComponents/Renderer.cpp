#include "Renderer.h"

void Renderer::render(std::vector<std::vector<char>>& grid, Character* hero){
    hp = hero->health;
    str = hero->strength;
    g = hero->gold;
    clearConsole();
    printCharacterInfo();
    printGrid(grid);
}

void Renderer::printGrid(std::vector<std::vector<char>>& grid){
    for (const auto& row : grid) {
        for (const auto& ch : row) {
            if (ch == 'P') {
                setColor(CYAN);
            }
            else {
                setColor(WHITE);
            }
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

void Renderer::printCharacterInfo(){
    std::cout << "Health: " << hp << std::endl;
    std::cout << "Attack: " << str << std::endl;
    std::cout << "Gold: " << g << std::endl;
}

void Renderer::setColor(int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Renderer::clearConsole(){
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 1};
    SetConsoleCursorPosition(hConsole, coord);
#else
    std::cout << "\033[H";
#endif

}