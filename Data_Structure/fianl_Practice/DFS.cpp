#include<iostream>

using namespace std;

const int Size = 6;

//int visit[Size];

int matrix[Size][Size] = {
{0, 1, 1, 0, 0, 0},
{1, 0, 1, 1, 0, 0},
{1, 1, 0, 0, 0, 1},
{0, 1, 0, 0, 1, 1},
{0, 0, 0, 1, 0, 1},
{0, 0, 1, 1, 1, 0}};

void DFS(int v, int *visit){
    int i;

    visit[v] = 1;
    cout << v << " ";

    for (i = 0; i < Size; i++){
        if (matrix[v][i] == 1 && !visit[i]){
            //cout << v << " ";
            DFS(i, visit);
        }
    }
}


main(){
    int visit[Size] = {0};
    DFS(0, visit);
    cout << endl;
}
