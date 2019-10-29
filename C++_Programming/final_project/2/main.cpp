#include <fstream>
#include <ncurses.h>
#include <iostream>
#include <algorithm>
#include <locale.h>
#include "di.h"

using namespace std;

WINDOW *win1;

class WindowManager
{
private:
    WINDOW *win_map;
    WINDOW *win_notice;
    WINDOW *win_menu;

    int x_start = 1;
    int y_start = 1;

public:
    WindowManager()//primalSetup()
    {
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

        refresh();
    }

    void showMap(int map_y, int map_x, int **play_map, int px, int py)
    {
        win_map = newwin(map_y + 2, map_x * 2 + 2, 5, 5);
        wbkgd(win_map, COLOR_PAIR(2));
        wattron(win_map, COLOR_PAIR(2));
        play_map[py][px] = 5;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                switch (play_map[i][j])
                {
                case 4:
                case 0:
                    mvwprintw(win_map, i + y_start, j * 2 + x_start, "  ");
                    break;
                case 1:
                    mvwprintw(win_map, i + y_start, j * 2 + x_start, "\u25A6");
                    break;
                case 2:
                    mvwprintw(win_map, i + y_start, j * 2 + x_start, "\u22A0");
                    break;
                case 3:
                    mvwprintw(win_map, i + y_start, j * 2 + x_start, "\u25A0");
                    break;
                case 5:
                    mvwprintw(win_map, i + y_start, j * 2 + x_start, "\u263A");
                    break;
                }
            }
        }
        wborder(win_map, '#', '#', '#', '#', '#', '#', '#', '#');
        wrefresh(win_map);
    }

    void showNotice(int stage, int move_character_num, int move_box_num)
    {
        win_notice = newwin(7, 26, 5, 30);
        wbkgd(win_notice, COLOR_PAIR(3));
        wattron(win_notice, COLOR_PAIR(3));
        mvwprintw(win_notice, 1, 1, " 현재 스테이지 : %d", stage + 1);
        mvwprintw(win_notice, 3, 1, " 캐릭터 이동 횟수 : %d", move_character_num);
        mvwprintw(win_notice, 5, 1, " 박스 이동 횟수 : %d", move_box_num);
        wborder(win_notice, '#', '#', '#', '#', '#', '#', '#', '#');
        wrefresh(win_notice);
    }

    friend class GameManager;
};

class GameManager
{
    private:
        WindowManager w;
        int key;
        int ***map;
        int **play_map;
        int px, py;
        int box_num;
        int Box[3][2];
        int **map_size;

        int stage = 0;
        int stages;
        int move_character_num = 0;
        int move_box_num = 0;
        int **character_yx;

    public:
        GameManager()
        {
            WindowManager wm();
        }

        void readMaps(ifstream &fin)
        {
            fin >> stages;
            map_size = new int*[stages];
            map = new int **[stages];
            character_yx = new int *[stages];
            for (int i = 0; i < stages; i++)
            {
                map_size[i] = new int[2];
                character_yx[i] = new int[2];
                fin >> map_size[i][0] >> map_size[i][1] >> character_yx[i][0] >> character_yx[i][1];
                map[i] = new int *[map_size[i][0]];
                for (int j = 0; j < map_size[i][0]; j++)
                {
                    map[i][j] = new int[map_size[i][1]];
                    for (int k = 0; k < map_size[i][1]; k++)
                    {
                        fin >> map[i][j][k];
                    }
                }
            }
        }

        void makeMap()
        {
            copy(&map[stage][0][0], &map[stage][0][0] + map_size[stage][0] * map_size[stage][1], &play_map[0][0]);
        }

        bool clear_stage()
        {
            for (int i = 0; i < box_num; i++)
            {
                if (play_map[Box[i][0]][Box[i][1]] == 5 || play_map[Box[i][0]][Box[i][1]] == 3) return false;
            }
            return true;
        }

        void Move(int my, int mx)
        {
            if (play_map[py + my][px + mx] != 1)
            { // 벽이면 안됌
                if (play_map[py + my][px + mx] == 2)
                { // 박스라면
                    if (play_map[py + my * 2][px + mx * 2] == 0 || play_map[py + my * 2][px + mx * 2] == 3)
                    {
                        // 박스를 이동했을때의 위치가 빈공간이거나 옮겨야 할 위치(3)일 경우
                        if (map[stage][py + my][px + mx] == 3)
                            play_map[py + my][px + mx] = 3;
                        else
                            play_map[py + my][px + mx] = 0;
                        move_box_num++;
                        play_map[py + my * 2][px + mx * 2] = 2;
                    }
                    else
                        return; // 박스 이동하는 위치가 벽이면 바로 종료
                }
                play_map[py][px] = map[stage][py][px]; // 캐릭터가 이동하기 전 자리는 0이나 3으로 바뀌어야함
                if (map[stage][py][px] == 2)
                    play_map[py][px] = 0; //박스를옮기고 그위치에 캐릭터가 있는상태에서 >    
                    //다른곳으로 이동할경우 기존 map에서 가져오면 박스가 다시생기므로 그것을 방지
                px += mx;
                py += my;
                play_map[py][px] = 5; // 현재 캐릭터 위치
                move_character_num++;
            }
        }

        void playGame(ifstream &fin)
        {
            readMaps(fin);
            while (stage < stages)
            {
                cout << "11" << endl;
                copy(&map[stage][0][0], &map[stage][0][0] + map_size[stage][0] * map_size[stage][1], &play_map[0][0]);
                //makeMap();
                cout << "16" << endl;
                int stage_y = map_size[stage][0];
                int stage_x = map_size[stage][1];
                cout << "14" << endl;
                py = character_yx[stage][0];
                px = character_yx[stage][1];
                cout << "15" << endl;
                move_character_num = 0;
                move_box_num = 0;
                cout << "12" << endl;
                while (1)
                {
                    clear();
                    border('#', '#', '#', '#', '#', '#', '#', '#');
                    refresh();
                    w.showMap(map_size[stage][0], map_size[stage][1], play_map, px, py);
                    w.showNotice(stage, move_character_num, move_box_num);

                    if (clear_stage())
                    {
                        if (stage < stages-1)
                        {
                            mvprintw(2, 10, "스테이지 클리어");
                            mvprintw(3, 10, "아무키나 누르시면 다음스테이지로 넘어갑니다");
                            getch();
                        }
                        else
                        {
                            mvprintw(2, 10, "모든 스테이지 클리어!");
                            mvprintw(3, 10, "아무키나 누르시면 게임이 종료됩니다.");
                        }
                        stage++;
                        break;
                    }
                    cout << "13" << endl;
                    key = getch();
                    if (key == KEY_UP)
                        Move(-1, 0);
                    else if (key == KEY_RIGHT)
                        Move(0, 1);
                    else if (key == KEY_DOWN)
                        Move(1, 0);
                    else if (key == KEY_LEFT)
                        Move(0, -1);

                    else if (key == 'r' || key == 'R')
                    {
                        break;
                    }
                    else if (key == 'n' || key == 'N')
                    {
                        if (stage == 1)
                            mvprintw(2, 10, "마지막 스테이지 입니다.");
                        else
                        {
                            stage++;
                            break;
                        }
                    }
                    else if (key == 'e' || key == 'E')
                    {
                        mvprintw(2, 10, "게임 종료 버튼을 누르셨습니다.");
                        mvprintw(3, 10, "아무키나 누르시면 게임이 종료됩니다.");
                        stage += 999;
                        break;
                    }
                }
            }
        }
};

int main()
{
    int key;

    GameManager gm;
    ifstream fin;
    fin.open("Maps.txt");
    gm.playGame(fin);

    refresh();
    getch();
    endwin();
    return 0;
}
