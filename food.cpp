#include "food.h"
#include<vector>
#include<utility>
#include<ncurses.h>
#include "constant.h"
#include "experimental/random" //this library has "random" function that allows u to
                               //get random value from particular location to particular location
using namespace std;

vector<pair<int,int>>food_items{};



// {
//     {2,3}, i=0  food_items[0].first =>2 , food_items[0].second=>3
//     {4,5},i=1
//     {6,9},i=2
// }


//randint(minimum,maximum) => function of "experimental/random library which 
                              //pick a random number between min. ans max. ,both inclusive


// initFood : Generates food items equal to MAX_FOOD_ITEM (not print only generates)
void addFood()
{
    int x= experimental::randint(1,LINES-2); //some random integer btw 1 to COLS-2 so that food is not in the border
int y= experimental::randint(1,COLS-2 ); //some random integer btw 1 to COLS-2 so that food is not in the border
food_items.push_back({x,y}); ////very important line see " ()  and {} CAREFULLY"

}
void initFood()    
{
food_items.clear();
for(int i=0;i<MAX_FOOD_ITEMS;++i)
{
addFood();
}
}
bool consumeFood(int x,int y)   //arguments so that we know which are eaten or need to be disappeared
{
    for(int i=0;i<MAX_FOOD_ITEMS;++i)
    {
        if(food_items[i].first==x && food_items[i].second==y)
        {
            food_items.erase(food_items.begin()+i);
             addFood();
             return true;
        }
    }
return false;
}

void printFood()
{

int num_of_foods=food_items.size();
for(int i=0;i<num_of_foods;i++)
{
int x=food_items[i].first;
int y=food_items[i].second;

move(x,y);
addstr("\u25cb");

}

}




