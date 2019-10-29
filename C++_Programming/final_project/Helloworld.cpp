#include<ncurses.h>

int main(){
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);


    getch();
    //refresh();

    attron(COLOR_PAIR(1));
    printw("Hello world!");
    attroff(COLOR_PAIR(1));

    getch();
    refresh();
    getch();
    printw("OOOOO");
    getch();
    endwin();

    return 0;
}
