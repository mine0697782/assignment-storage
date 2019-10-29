#include <ncurses.h>
#include <iostream>
#include <algorithm>
#include <locale.h>
#include <fstream>

enum Position {
    Y_POS,
    X_POS,
};

Position xpos(X_POS);
Position ypos(Y_POS);



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
int **play_map; // 지금까지 진행된 맵 플레이 상황

int x = 2; // 캐릭터 좌표
int y = 2;

int Box[3][2] = {{1, 1}, {2, 1}, {3, 1}}; // 박스 좌표
int box_num = 3; // 박스 개수

int move_character_num; // 캐릭터 이동 횟수
int move_box_num; // 박스 이동 횟수

bool map_clear() // 박스가 모두 올바른ㅇ 위치에 옮겨졌는지 검사
{
    for(int i = 0 ; i < box_num ; i++){
        if(play_map[Box[i][ypos]][Box[i][xpos]] == 3) return false;
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

int main()
{
    int key;

    setlocale(LC_ALL, "");
    initscr();
    resize_term(999, 50);
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_MAGENTA);
    attron(COLOR_PAIR(1));
    bkgd(COLOR_PAIR(1));
    std::copy(&map[0][0], &map[0][0] + 9 * 7, &play_map[0][0]);
    while(!map_clear()){
        printw("moving character num : %d\n", move_character_num);
        printw("moving box num : %d\n\n", move_box_num);
        play_map[y][x] = 5;
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 7 ; j++){
                
                switch(play_map[i][j]){
                    case 4:
                    case 1:   // Wall
                        mvprintw(i+3, j*2+3, "XX");
                        break;
                    case 0:   // Space
                        mvprintw(i+3, j*2+3, "  ");
                        break;
                    case 2:   // Box
                        mvprintw(i+3, j*2+3, "\u2B1B");
                        break;
                    case 3:   // Goal
                        mvprintw(i+3, j*2+3, "\u2B1C");
                        break;
                    case 5:
                        mvprintw(i+3, j*2+3, "P1");
                        break;
                }
                
            }
        }
        refresh();
        key = getch();
        if(key == KEY_UP) Move(-1, 0);
        else if(key == KEY_RIGHT) Move(0, 1);
        else if(key == KEY_DOWN) Move(1, 0);
        else if(key == KEY_LEFT) Move(0, -1);
        else if(key == 'a') break;
        clear();
    }
    clear();
    refresh();
    resize_term(2, 50);
    printw("clear!\nif you want end game press any key");
    refresh();
    getch();
    endwin();
    return 0;
}
    
