#include "Character.h"
class CharacterBuilder {
protected:
    Character* character;
public:
    CharacterBuilder();

    Character* getCharacter();
    CharacterBuilder* setHealth(int health);
    CharacterBuilder* setStrength(int strength);
    CharacterBuilder* setGold(int gold);
};