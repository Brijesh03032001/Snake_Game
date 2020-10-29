#include<utility>

void InitSnake();
void paintSnake();
void GrowSnake();
std::pair<int,int> moveSnake(int key);
bool detectCollision(); //true if snake bites itself or collide to wall

