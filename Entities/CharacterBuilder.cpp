#include "Characterbuilder.h"
CharacterBuilder::CharacterBuilder() {
    character = new Character();
}

Character* CharacterBuilder::getCharacter() {
    return character;
}

CharacterBuilder* CharacterBuilder::setHealth(int health) {
    character->health = health;
    return this;
}

CharacterBuilder* CharacterBuilder::setStrength(int strength) {
    character->strength = strength;
    return this;
}

CharacterBuilder* CharacterBuilder::setGold(int gold) {
    character->gold = gold;
    return this;
}