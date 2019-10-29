#include <ncurses.h>
#include <iostream>
#include <algorithm>
#include <locale.h>

WINDOW *win1;

int map[2][9][7] = {{{1, 1, 1, 1, 4, 4, 4},
                     {1, 3, 0, 1, 1, 4, 4},
                     {1, 3, 0, 0, 1, 4, 4},
                     {1, 3, 0, 2, 1, 4, 4},
                     {1, 1, 2, 0, 1, 1, 1},
                     {4, 1, 0, 2, 0, 0, 1},
                     {4, 1, 0, 0, 0, 0, 1},
                     {4, 1, 0, 0, 1, 1, 1},
                     {4, 1, 1, 1, 1, 4, 4}},

                    {{1, 1, 1, 1, 1, 4, 4},
                     {1, 0, 0, 0, 1, 4, 4},
                     {1, 3, 3, 3, 1, 4, 4},
                     {1, 2, 2, 2, 1, 1, 4},
                     {1, 0, 0, 0, 0, 1, 4},
                     {1, 0, 0, 0, 0, 1, 4},
                     {1, 1, 1, 1, 1, 1, 4},
                     {4, 4, 4, 4, 4, 4, 4},
                     {4, 4, 4, 4, 4, 4, 4}}};

int map_size[2][2] = {{9, 7}, {9, 7}};
int character_yx[2][2] = {{2, 2}, {5, 3}};

int play_map[9][7]; // 지금까지 진행된 맵 플레이 상황

int x = 2; // 현재 캐릭터 위치
int y = 2;

int Box[2][3][2] = {{{1, 1}, {2, 1}, {3, 1}},
                    {{2, 1}, {2, 2}, {2, 3}}}; // 박스 위치

int box_num[2] = {3, 3}; // 박스 개수

int stage; // 현재 스테이지 = stage + 1
int move_character_num; // 캐릭터 이동 횟수
int move_box_num; // 박스 이동 횟수

bool clear_stage() // 박스가 모두 올바른 위치에 옮겨졌는지 검사
{
    for(int i = 0 ; i < box_num[stage] ; i++){
        if(play_map[Box[stage][i][0]][Box[stage][i][1]] == 5 || play_map[Box[stage][i][0]][Box[stage][i][1]] == 3) return false;
    }
    return true;
}

void Move(int my, int mx) // 이동 함수
{
    if(play_map[y + my][x + mx] != 1){ // 벽이면 안됌
        if(play_map[y + my][x + mx] == 2){ // 박스라면
            if(play_map[y + my * 2][x + mx * 2] == 0 || play_map[y + my * 2][x + mx * 2] == 3){
                // 박스를 이동했을때의 위치가 빈공간이거나 옮겨야 할 위치(3)일 경우
                if(map[stage][y + my][x + mx] == 3) play_map[y + my][x + mx] = 3;
                else play_map[y + my][x + mx] = 0;
                move_box_num++;
                play_map[y + my * 2][x + mx * 2] = 2;
            }
            else return; // 박스 이동하는 위치가 벽이면 바로 종료
        }
        play_map[y][x] = map[stage][y][x]; // 캐릭터가 이동하기 전 자리는 0이나 3으로 바뀌어야함
        if(map[stage][y][x] == 2) play_map[y][x] = 0; //박스를옮기고 그위치에 캐릭터가 있는상태에서 다른곳으로 이동할경우 기존 map에서 가져오면 박스가 다시생기므로 그것을 방지
        x += mx;
        y += my;
        play_map[y][x] = 5; // 현재 캐릭터 위치
        move_character_num++;
    }
}

void window_map(int map_y, int map_x)
{
    WINDOW *win1;
    win1 = newwin(map_y + 2, map_x * 2 + 2, 5, 5);
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
    wborder(win1, '#', '#', '#', '#', '#', '#', '#', '#');
    wrefresh(win1);
}

void window_move_num()
{
    WINDOW *win2;
    win2 = newwin(7, 26, 5, 30);
    wbkgd(win2, COLOR_PAIR(3));
    wattron(win2, COLOR_PAIR(3));
    mvwprintw(win2, 1, 1, " 현재 스테이지 : %d", stage + 1);
    mvwprintw(win2, 3, 1, " 캐릭터 이동 횟수 : %d", move_character_num);
    mvwprintw(win2, 5, 1, " 박스 이동 횟수 : %d", move_box_num);
    wborder(win2, '#', '#', '#', '#', '#', '#', '#', '#');
    wrefresh(win2);
}

void window_menu()
{
    WINDOW *win3;
    win3 = newwin(7, 21, 14, 30);
    wbkgd(win3, COLOR_PAIR(4));
    wattron(win3, COLOR_PAIR(4));
    mvwprintw(win3, 1, 1, " 다시하기 : R");
    mvwprintw(win3, 3, 1, " 다음 스테이지 : N");
    mvwprintw(win3, 5, 1, " 게임 종료 : E");
    wborder(win3, '#', '#', '#', '#', '#', '#', '#', '#');
    wrefresh(win3);
}
    

int main()
{
    int key;

    setlocale(LC_ALL, "");
    initscr();
    start_color();
    resize_term(25, 61);
    
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);

    attron(COLOR_PAIR(1));
    bkgd(COLOR_PAIR(1));
    
    //border('#', '#', '#', '#', '#', '#', '#', '#');
    //refresh();
    while(stage < 2){
        int stage_y = map_size[stage][0];
        int stage_x = map_size[stage][1];
        y = character_yx[stage][0];
        x = character_yx[stage][1];
        move_character_num = 0;
        move_box_num = 0;

        std::copy(&map[stage][0][0], &map[stage][0][0] + stage_y * stage_x, &play_map[0][0]);
        while(true){
            clear();
            border('#', '#', '#', '#', '#', '#', '#', '#');
            refresh();
            window_map(9, 7);
            window_move_num();
            window_menu();

            if(clear_stage()){
                if(stage < 1){
                    mvprintw(2, 10, "스테이지 클리어");
                    mvprintw(3, 10, "아무키나 누르시면 다음스테이지로 넘어갑니다");
                    getch();
                }
                else{
                    mvprintw(2, 10, "모든 스테이지 클리어!");
                    mvprintw(3, 10, "아무키나 누르시면 게임이 종료됩니다.");
                }
                stage++;
                break;
            }

            key = getch();
            if(key == KEY_UP) Move(-1, 0);
            else if(key == KEY_RIGHT) Move(0, 1);
            else if(key == KEY_DOWN) Move(1, 0);
            else if(key == KEY_LEFT) Move(0, -1);

            else if(key == 'r' || key == 'R'){
                break;
            }
            else if(key == 'n' || key =='N'){
                if(stage == 1)mvprintw(2, 10, "마지막 스테이지 입니다.");
                else {
                    stage++;
                    break;
                }
            }
            else if(key == 'e' || key == 'E'){
                mvprintw(2, 10, "게임 종료 버튼을 누르셨습니다.");
                mvprintw(3, 10, "아무키나 누르시면 게임이 종료됩니다.");
                stage += 999;
                break;
            }
        }
    }
    refresh();
    getch();
    endwin();
    return 0;
}
    
