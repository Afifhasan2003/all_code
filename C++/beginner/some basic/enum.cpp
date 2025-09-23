#include <iostream>
using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

void moveDir(Direction d) {
    switch (d) {
        case UP: cout << "Moving up\n"; break;
        case DOWN: cout << "Moving down\n"; break;
        case LEFT: cout << "Moving left\n"; break;
        case RIGHT: cout << "Moving right\n"; break;
    }
}

int main() {
    moveDir(LEFT);
    moveDir(UP);
    // moveDir(3);
    // moveDir(0);


    moveDir((Direction)2); // C-style cast
    moveDir(static_cast<Direction>(3));



}
