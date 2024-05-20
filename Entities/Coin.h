

#include "Character.h"
class Coin {
public:
    Character& character; // Reference to a Character object

    Coin(Character& c) : character(c) {} // Initialize the reference in the constructor

    void applyEffect() {
        character.gold = character.gold + 1;
    }
};