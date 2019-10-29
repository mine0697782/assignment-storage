#include <ncurses.h>
#include <iostream>
#include <algorithm>
#include <locale.h>
#include <fstream>

int ***maps;
int **map;

void getMap(ifstream &fin){
    int total, num;
    int x, y, px, py;
    //ifstream in;
    fin.open("Maps.txt");
    fin >> total;
    maps = new int **[total];
    for (int i=0; i<total; i++){
        fin >> y >> x >> py >> px;
        maps[i] = new int*[y];
        for (int j=0; j<y; j++){
            maps[i][j] = new int[x];
            for (int k=0; k<x; k++){
                fin >> maps[i][j][k];
            }
        }
    }
    map = new int*[9];
    for (int i=0; i<9; i++){
        map[i] = new int[7];
    }
}

WINDOW *win1;
/*
int **map;
map = new int*[9];
for (int i=0; i<9; i++){
    map[i] = new int[7];
}
*/

/*
int map[9][7] = {{1, 1, 1, 1, 4, 4, 4}, // 게임 맵
                {1, 3, 0, 1, 1, 4, 4},
                {1, 3, 0, 0, 1, 4, 4},
                {1, 3, 0, 2, 1, 4, 4},
                {1, 1, 2, 0, 1, 1, 1},
                {4, 1, 0, 2, 0, 0, 1},
                {4, 1, 0, 0, 0, 0, 1},
                {4, 1, 0, 0, 1, 1, 1},
                {4, 1, 1, 1, 1, 4, 4}};
*/
int play_map[9][7]; // 지금까지 진행된 맵 플레이 상황

int x = 2; // 캐릭터 좌표
int y = 2;

int Box[3][2] = {{1, 1}, {2, 1}, {3, 1}}; // 박스 좌표
int box_num = 3; // 박스 개수

int move_character_num; // 캐릭터 이동 횟수
int move_box_num; // 박스 이동 횟수

bool map_clear() // 박스가 모두 올바른ㅇ 위치에 옮겨졌는지 검사
{
    for(int i = 0 ; i < box_num ; i++){
        if(play_map[Box[i][0]][Box[i][1]] == 5 || play_map[Box[i][0]][Box[i][1]] == 3) return false;
    }
    return true;
}

void Move(int my, int mx) // 이동 함수
{
    if(play_map[y + my][x + mx] != 1){ // 벽이면 안됌
        if(play_map[y + my][x + mx] == 2){ // 박스라면
            if(play_map[y + my * 2][x + mx * 2] == 0 || play_map[y + my * 2][x + mx * 2] == 3){
                // 박스를 이동했을때의 위치가 빈공간이거나 옮겨야 할 위치(3)일 경우
                if(map[y + my][x + mx] == 3) play_map[y + my][x + mx] = 3;
                else play_map[y + my][x + mx] = 0;
                move_box_num++;
                play_map[y + my * 2][x + mx * 2] = 2;
            }
            else return; // 박스 이동하는 위치가 벽이면 바로 종료
        }
        play_map[y][x] = map[y][x]; // 캐릭터가 이동하기 전 자리는 0이나 3으로 바뀌어야함
        if(map[y][x] == 2) play_map[y][x] = 0; //박스를옮기고 그위치에 캐릭터가 있는상태에서 다른곳으로 이동할경우 기존 map에서 가져오면 박스가 다시생기므로 그것을 방지
        x += mx;
        y += my;
        play_map[y][x] = 5; // 현재 캐릭터 위치
        move_character_num++;
    }
}

void window_map()
{
    WINDOW *win1;
    win1 = newwin(13, 18, 2, 2);
    wbkgd(win1, COLOR_PAIR(2));
    wattron(win1, COLOR_PAIR(2));
    play_map[y][x] = 5;
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            switch(play_map[i][j]){
                case 4:
                case 0:
                    mvwprintw(win1, i + 1, j * 2 + 1, "  ");
                    break;
                case 1:
                    mvwprintw(win1, i + 1, j * 2 + 1, "\u25A6");
                    break;
                case 2:
                    mvwprintw(win1, i + 1, j * 2 + 1, "\u22A0");
                    break;
                case 3:
                    mvwprintw(win1, i + 1, j * 2 + 1, "\u25A0");
                    break;
                case 5:
                    mvwprintw(win1, i + 1, j * 2 + 1, "\u263A");
                    break;
            }
        }
    }
    wborder(win1, 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X');
    wrefresh(win1);
}

void window_move_num()
{
    WINDOW *win2;
    win2 = newwin(4, 15, 4, 30);
    wbkgd(win2, COLOR_PAIR(3));
    wattron(win2, COLOR_PAIR(3));
    mvwprintw(win2, 1, 1, "mcn : %d", move_character_num);
    mvwprintw(win2, 2, 1, "mbn : %d", move_box_num);
    wborder(win2, '@', '@', '@', '@', '@', '@', '@', '@');
    wrefresh(win2);
}

void window_menu()
{
    WINDOW *win3;
    win3 = newwin(7, 21, 10, 30);
    wbkgd(win3, COLOR_PAIR(4));
    wattron(win3, COLOR_PAIR(4));
    mvwprintw(win3, 1, 1, " restart stage : R");
    mvwprintw(win3, 3, 1, " next stage : N");
    mvwprintw(win3, 5, 1, " end game : E");
    wborder(win3, '#', '#', '#', '#', '#', '#', '#', '#');
    wrefresh(win3);
}
    

int main()
{
    int key;

    setlocale(LC_ALL, "");
    initscr();
    start_color();
    resize_term(60, 60);
    
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);

    attron(COLOR_PAIR(1));
    bkgd(COLOR_PAIR(1));
    //ifstream fin;
    //fin.open("Maps.txt");
    getMap(&fin);
    std::copy(&maps[0][0][0], &maps[0][0][0] + 9 * 7, &play_map[0][0]);
    while(!map_clear()){
        border('o', 'o', 'o', 'o', 'o', 'o', 'o', 'o');
        refresh();
        window_map();
        window_move_num();
        window_menu();

        key = getch();
        if(key == KEY_UP) Move(-1, 0);
        else if(key == KEY_RIGHT) Move(0, 1);
        else if(key == KEY_DOWN) Move(1, 0);
        else if(key == KEY_LEFT) Move(0, -1);

        else if(key == 'r' || key == 'R'){
            std::copy(&map[0][0], &map[0][0] + 9 * 7, &play_map[0][0]);
            y = 2;
            x = 2;
            move_character_num = 0;
            move_box_num = 0;
        }
        else if(key == 'e' || key == 'E'){
            break;
        }
        clear();
    }
    refresh();
    resize_term(2, 50);
    printw("clear!\nif you want end game press any key");
    refresh();
    getch();
    endwin();
    return 0;
}
    
