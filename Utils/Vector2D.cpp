#include "Vector2D.h"

Vector2D::Vector2D(){}
Vector2D::Vector2D(int x, int y){
    this->x = x;
    this->y = y;
}
void Vector2D::setX(int val) {
    x = val;
}
void Vector2D::setY(int val) {
    y = val;
}
int Vector2D::getX() {
    return x;
}
int Vector2D::getY() {
    return y;
}