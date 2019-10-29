#include<clocale>
#include<ncurses.h>
#include<iostream>

int main(){
    setlocale(LC_ALL, "");
    initscr();

    mvprintw(3, 4, "\u2B1B \u2B1C");
    refresh();
    getch();

    endwin();
    return 0;
}
