#include<iostream>

using namespace std;

#define max 6

//int max = 6;
int graph[max][max] = {
    {0, 0, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1, 0},
};
int front = -1, rear = -1, queue[5];
char visited[max] = {'t','f','f','f','f','f'};

void enque(int num){
    queue[++front] = num;
}

int deque(){
    return queue[++rear];
}

int Qempty(){
    return front == rear;
}

void bfs(){
    int v, w;
    enque(0);
    v = 0;//deque();
    cout << " v" << v;
    while(!Qempty()){
        for (w=0; w<6; w++) {
            //cout << "check 1" << endl;
            if (visited[w] == 'f' && (graph[v][w]!=0)) {
                //cout << "check 2" << endl;
                enque(w);
                visited[w] = 't';
                cout << " v" << w;
            }
        }
        v = deque();
    }
    cout << endl;
}

main(){
    cout << "\t v0\t v1\t v2\t v3\t v4\t v5\t" << endl;
    for (int i=0; i<max; i++){
        cout << "v" << i << "\t";
        for (int j=0; j<6; j++){
        cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
    
    bfs();
    
    return 0;
}
