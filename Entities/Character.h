#ifndef CHARACTER_H
#define CHARACTER_H

#include "../Utils/Vector2D.h"
class Character {
    public:
        int health;
        int strength;
        int gold;
    private:
        Vector2D pos;
    public:
        void setPos(int x, int y){
            pos.setX(x);
            pos.setY(y);
        }

        Vector2D getPos(){
            return pos;
        }

        void setPosX(int x){
            pos.setX(pos.getX() + x);
        }

        void setPosY(int y){
            pos.setY(pos.getY() + y);
        }
};

#endif //CHARACTER_H