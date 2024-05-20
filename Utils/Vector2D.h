#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{
    private:
        int x;
        int y;
    public:
        Vector2D(int x, int y);
        Vector2D();
        void setX(int val);
        void setY(int val);
        int getX();
        int getY();
};

#endif //VECTOR2D_H