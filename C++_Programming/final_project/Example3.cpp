#include<ncurses.h>

int main(){
    char key;
    char userName[8];

    initscr();

    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    printw("User name: ");
    scanw("%s", userName);

    printw("%s \n", userName);
    printw("Enter a Key and delete screen.");
    refresh();

    getch();
    clear();
    refresh();

    getch();
    endwin();
    return 0;
}
