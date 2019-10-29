#include<iostream>

using namespace std;

const int size = 6;

int visit[size];

int graph[size][size] = {
{0, 0, 0, 0, 1, 1},
{0, 0, 1, 1, 0, 1},
{0, 1, 0, 1, 1, 0},
{0, 1, 1, 0, 0, 0},
{1, 0, 1, 0, 0, 1},
{1, 1, 0, 0, 1, 0}};

class Node{
    public:
        Node *link;
        int data;
        Node(){link = 0;}
        Node(int key){data = key; link = 0;}
};

int queue[size];
int rear, front;

void BFS(int v){
    int i;

    visit[v] = 1;
    cout << "BFS" << endl << v << " ";
    queue[rear++] = v;
    
    while(front != rear){ // if queue not empty
        v = queue[front++];
        for (i = 0; i < size; i++){
            if (graph[v][i] == 1 && !visit[i]){
                cout << i << " ";
                queue[rear++] = i;
                visit[i] = 1;
            }
        }
    }
}


main(){
    BFS(0);
    cout << endl;
    return 0;
}
