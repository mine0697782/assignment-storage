#include<ncurses.h>
#include<iostream>

using namespace std;

int main(){
    int row, col;

    cin >> row >> col;

    initscr();
    resize_term(row, col);
    mvprintw(2, 3, "C++ programming with ncurses");

    refresh();
    getch();
    endwin();

    return 0;
}
