#include<ncurses.h>
#include<locale.h>
#include<fstream>

enum ColorPreset{
    PRIMARY,
    BACKGROUND,

};

int ***maps;

void getMap(){
    int total, num;
    int x, y, px, py;
    ifstream fin;
    fin.open("Maps.txt");
    fin >> total;
    maps = new int**[total];
    for (int i; i<total; i++){
        fin >> y >> x >> py >> px;
        maps[i] = new *int[y];
        for (int j=0; j<y; j++){
            maps[i][j] = new int[x];
            for (int k=0; k<x; k++){
                fin >> maps[i][j][k];
            }
        }
    }
}

//int ***maps;

/*
const int map[9][7] = {
{1, 1, 1, 1, 4, 4, 4},
{1, 3, 0, 1, 1, 4, 4},
{1, 3, 0, 0, 1, 4, 4},
{1, 3, 0, 2, 1, 4, 4},
{1, 1, 2, 0, 1, 1, 1},
{4, 1, 0, 2, 0, 0, 1},
{4, 1, 0, 0, 0, 0, 1},
{4, 1, 0, 0, 1, 1, 1},
{4, 1, 1, 1, 1, 4, 4}};
*/

int play_map[9][7];

int charX = 2;
int charY = 2;

int Box[3][2] = {{1, 1}, {2, 1}, {3, 1}};
int box_num = 3;

bool map_clear(){
    for(int i = 0; i<box_num; i++){
        if (play_map[Box[i][0]][Box[i][1]] == 3) return false;
    }
    return true;
}

void showMap(WINDOW *win){
    for (int i=0; i<9; i++){
        for (int j=0; j<7; j++){
            mvwprintw(win, 3+i, j, "\u2B1B");
        }
    } 
    wrefresh(win);
}

ColorPreset set_bg(BACKGROUND);

int main(){
    WINDOW *win1;
   
    setlocale(LC_ALL, "");
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    
    //win1 = newwin(20, 20, 5, 2);
    
    init_pair(set_bg, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_MAGENTA);

    bkgd(COLOR_PAIR(set_bg));
    attron(COLOR_PAIR(set_bg));
    border('|', '|', '-', '-', '+', '+', '+', '+');
    refresh();
    getch();
    mvprintw(5, 5, "\u2B1B");
    getch();

    win1 = newwin(20, 20, 5, 2);
    //wbkgd(win1, COLOR_PAIR(2));
    wattron(win1, COLOR_PAIR(2));
    wborder(win1, '@', '@', '@', '@', '@', '@', '@', '@');
    showMap(win1);
    mvwprintw(win1, 5, 5, "\u2B1B");

    wattroff(win1, COLOR_PAIR(set_bg));

    refresh();
    getch();
    delwin(win1);
    endwin();
    return 0;

}
