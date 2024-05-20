#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <vector>
#include "../Entities/CharacterBuilder.h"

#ifdef _WIN32
#include <windows.h>
#endif

enum Color {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

class Renderer{
    private:
        int hp, str, g;
    public:
        void render(std::vector<std::vector<char>>&, Character* hero);
    private:
        void clearConsole();
        void printGrid(std::vector<std::vector<char>>&);
        void setColor(int color);
        void printCharacterInfo();
};

#endif // RENDERER_H