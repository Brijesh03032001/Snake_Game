#include "snake.h"
#include "game.h"
#include "ui.h"
#include "ncurses.h"
#include<utility>
#include "constant.h"
#include "food.h"
int current_game_state=GAME_BEFORE_START;
int current_score=0;
int current_direction=KEY_UP;
void PrintStatus()
{
    move(0,5);
    if(current_game_state==GAME_BEFORE_START)
    {

    
    printw("Press any key to start the game");
    }
    else{
    printw("Current Score: %d",current_score);
}
}


 //this "void tick() Function " decides if state of game is started :
 //show snake 
 //show food//move the snake etc etc...
 //else:
 //print border
 //print started


 void start_game()
 {
     current_score=0;
     current_game_state=GAME_STARTED;
     current_direction=KEY_UP;
     erase();
     initFood();
      InitSnake();
      printFood();



 }
void tick(int key)  
{
     if(current_game_state==GAME_BEFORE_START)
    {
        erase();  //clears out all the screen 
    print_border();
    PrintStatus();
    if(key!=ERR)
    {
        start_game();

    }
    }
    else
    {
        erase();  //clears out all the screen 
          std::pair<int,int> snake_head_cord;

        if(key==KEY_UP && current_direction!=KEY_DOWN)
        {
            current_direction=KEY_UP;

        }
        else if(key==KEY_DOWN && current_direction!=KEY_UP)
        {
            current_direction=KEY_DOWN;

        }
        else if(key==KEY_LEFT && current_direction!=KEY_RIGHT)
        {
            current_direction=KEY_LEFT;

        }
        else if(key==KEY_RIGHT && current_direction!=KEY_LEFT)
        {
            current_direction=KEY_RIGHT;

        }
        snake_head_cord=moveSnake(current_direction);

        
        if(key!=ERR)
        {
      

    if(consumeFood(snake_head_cord.first,snake_head_cord.second))
{
    //food iteam was eaten so the snake grow
    GrowSnake();
    current_score=current_score+1;

}
        }
    print_border();
    PrintStatus();
    

    printFood();
    paintSnake();
 if(detectCollision())
 {
  current_game_state=GAME_BEFORE_START;

 }
    }
    


}