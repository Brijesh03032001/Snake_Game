#include "snake.h"
//snake is an array of co-ordinates ...therefore represented by vector 

#include<vector>
#include<utility>
#include "ncurses.h"

std::vector<std::pair<int,int>>snake;
std::pair<int,int>snake_head;
 int last_snake_x; //cordinates of the latest tail that was removed
  int last_snake_y; // //cordinates of the latest tail that was removed

void InitSnake()
{

 snake.clear();

    //initial length  and initial cordinates
    snake.push_back({LINES/2,COLS/2});
snake.push_back({LINES/2,COLS/2+1});
snake.push_back({LINES/2,COLS/2+2});
snake_head.first=LINES/2;
snake_head.second=COLS/2;

last_snake_x=LINES/2;
last_snake_y=COLS/2 +3;

paintSnake();

}


void paintSnake()
{
    for(int i=0;i<snake.size();i++)
    {
        int x=snake[i].first;
        int y=snake[i].second;
        move(x,y);
        addstr("\u2588");

    }
}


std::pair<int,int> moveSnake(int key)
{

    last_snake_x=snake[0].first;
    last_snake_y=snake[0].second;
    
    //remove tail's index ....ab kya krna hai ki tail wale ko remove krna aur 
    //head mein ek bda dena block ...aur bdake usko snake se jod dena

    snake.pop_back();
    int pre_head_x=snake_head.first;
    int pre_head_y=snake_head.second;
    int next_head_x;
    int next_head_y;

    if(key==KEY_UP)   
    {

        next_head_x=pre_head_x-1;
        next_head_y=pre_head_y;

    }
    else if(key==KEY_DOWN)
    {
next_head_x=pre_head_x+1;
        next_head_y=pre_head_y;
        
    }
    else if (key==KEY_LEFT)
    {
next_head_x=pre_head_x;
        next_head_y=pre_head_y-1;
        
    }
    else if(key==KEY_RIGHT)
    {
next_head_x=pre_head_x;
        next_head_y=pre_head_y+1;
        
    }

 ///ab nye head ko jodna hai (mtlb insert krna hai) shuru mein (i.e snake.begin()) snake vector ke    
snake.insert(snake.begin(),{next_head_x,next_head_y});
snake_head={next_head_x,next_head_y};
return snake_head;

}




bool detectCollision()
{
    int head_x=snake[0].first;
    int head_y=snake[0].second;

        //check if the head of the snake does not collide with boundary or with the snake itself
   if(head_x==0 || head_x==LINES-1)
   {
       return true ;

   }
   if(head_y==0 || head_x==COLS-1)
   {
       return true ;

   }
   for(int i=1;i<snake.size();i++)
   {
       if(snake[i]==std::make_pair(head_x,head_y))
       {
           return true;
       }


   }
   return FALSE;




}

void GrowSnake()
{
    snake.push_back({last_snake_x,last_snake_y});
    

}
