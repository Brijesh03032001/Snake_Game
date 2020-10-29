
#include <chrono>
#include "constant.h"
#include "ui.h"
#include "game.h"
#include "food.h"
using namespace std;

//.h is a header file and .cpp is a code file

int key=ERR;    
/*Difference between 'key' and 'k'
hmm shuru mein ek default key rkh rhe hai taaki hmari game chle uss key pe aur wo ruke 
naa aur hmara 'tick' function chle jaaye aur 
'k' hai jo wo ye bta rha ki agr hmne bich mein key press kri taaki game start ho 
toh hmm key=k kr denge aur tb bhi tick function chla denge .

AISE KRKE dono mein tick function chl jayega hmare input ka wait krne ya na krne 
ke bina */
void event_loop()
{
    auto last_time=chrono::system_clock::now();
    auto current_time=chrono::system_clock::now();
    
     int delta_t;
      
    while(true)
    {
        current_time=chrono::system_clock::now();
    
        delta_t=chrono::duration_cast<chrono::milliseconds>(current_time- last_time).count();
        
        if(delta_t>TICK_INTERVAL)
        {
           int k=getch();   

            //0.1 sec passed ;
            if(k!=ERR)
            {
            key=k;
            }
           tick(key);
            refresh();
           
            last_time=current_time;
            
        }    
    }
}
int main()
{
    init_ui();
//print_border();

   event_loop();
   
    tear_down_ui();

    return 0;
}