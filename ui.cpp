#include<iostream>
#include <ncurses.h>
#include "ui.h"
void print_border()
{
    // COLS and LINES 
    // COLS FOR width
    //LINES for height

    int i;
    for(i=0;i<COLS;i++)
    {
      move(0,i);
      addstr("\u2588");
      move(LINES-1,i);
       addstr("\u2588");
    }
    for(i=0;i<LINES;i++)
    {
      move(i,0);
       addstr("\u2588");
      move(i,COLS-1);
       addstr("\u2588");

    }
    refresh();
}

//       stdscr wo hai jispe input or output liya jata hai

void init_ui()
{
  setlocale(LC_ALL,"");  
initscr(); // used to initialise the ncurses data structure (or initialises the ncurses mode)
curs_set(0); //hide the cursor

noecho();  //prevents printinng out whtever u typed
cbreak(); //generates or interrupt on (ctrl+c)
nodelay(stdscr,TRUE); //ye hmne isliye lgaya taaki jb key=getch() ho toh wo wait naa kre input lene ki 
                     // sidha chl jaaye

keypad(stdscr,TRUE);
}
void tear_down_ui()
{
endwin();   //exists the ncurses mode and restore the previous terminal

}
