#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
private:
    int **cost;         // 비용을 동적 배열로 저장하는 매트릭스
    bool *found;        // 이미 방문한 노드를 체크하는 배열
    const int size;     // 노드의 갯수
    int *distance;      // 각 노드까지의 거리를 저장하는 배열
    ifstream &reader;   // 메인함수에서 만든 객체를 받는 레퍼런스 변수

public:
    Graph(int _size, ifstream &_reader) : size(_size), reader(_reader)
    {       // 배열의 크기는 상수이므로 생성과 동시에 초기화해준다. 
        cost = new int *[size];             // 배열을 입력받은 크기만큼 할당
        for (int i = 0; i < size; i++)      
        {
            cost[i] = new int[size];        // 각 행마다 열 길이만큼 할당
        }

        for (int i = 0; i < size; i++)      
        {
            for (int j = 0; j < size; j++)  
            {
                reader >> cost[i][j];       // 파일로부터 그래프를 입력받는다.
            }
        }
        found = new bool[size];             // found 배열 초기화
        distance = new int[size];           // distance 배열 초기화
    }

    void printGraph()   // 현재 그래프를 출력하는 함수
    {       
        cout << "Cost Matrix\n\t";
        for (int i = 0; i < size; i++)
            cout << i << "\t";
        cout << endl;

        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";
            for (int j = 0; j < size; j++)
            {
                cout << cost[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void shortestPath(int v)    // 시작점을 입력받아 가장 짧은 거리를 구해서 출력하는 함수
    {
        int i, u, w;
        for (i = 0; i < size; i++)      // 거리와 검사 배열을 초기화하는 반복문
        {
            found[i] = false;           // 최단거리가 확정된 노드를 체크하는 배열         
            distance[i] = cost[v][i];   // 시작노드부터 각 노드까지의 거리로 초기화
        }
        found[v] = true;    // 처음 시작하는 노드는 더이상 검사하지 않도록 체크
        distance[v] = 0;    // 자기 자신을 향한 거리는 0이기 때문에 값 재설정
        for (i = 0; i < size - 1; i++)
        {
            u = choose();   // 현재까지 최단거리로 확정되지 않은 노드 중 가장 가까운 노드 선택

            if (i == 0)     // 거리를 출력할 때 초기값임을 알려주기 위한 부가적인 출력
                cout << "Begin ";   
            cout << "Distance : ";  
            for (int j = 0; j < size; j++)
            {
                cout << distance[j] << " "; // 현재의 노드별 거리 출력
            }
            cout << "\t(selected Node) : " << u << endl;    // 현재 가리키는 노드를 출력

            found[u] = true;    // 현재 가리키는 노드의 방문 여부를 true로 스위칭
            for (w = 0; w < size; w++)  // 첫 노드로부터 각 노드별로 하나씩 방문
            {
                if (!found[w])  // 방문하지 않은 노드만 계산
                {
                    if (distance[u] + cost[u][w] < distance[w]) 
                        //! 기존의 거리보다 현재 노드를 거쳐가는 거리가 더 짧으면
                        distance[w] = distance[u] + cost[u][w];
                        // 노드의 새로운 거리 갱신
                }
            }
        }
        cout << endl;
    }

    int choose()    // 거쳐가지 않은 노드 중 가장 거리가 짧은 노드를 반환하는 함수
    {
        int i, minnode, min = 99999;    // 비교대상으로 최댓값 초기화

        for (i = 0; i < size; i++)
        {
            if (distance[i] < min && !found[i]) // 현재 최솟값보다 작고 방문하지 않았으면
            {
                min = distance[i];  // 해당 노드까지의 거리를 최솟값으로 넣고
                minnode = i;        // 위치를 저장한다
            }
        }
        return minnode;     // 모든 노드를 검사했으면 마지막까지 최솟값이였던 노드 번호 반환
    }
};

int main()
{
    char file1[100] = "Shortest_Path_Input1.txt";
    char file2[100] = "Shortest_Path_Input2.txt";
    int size;
    ifstream reader;

    reader.open(file1);
    reader >> size;
    Graph g1(size, reader);
    g1.printGraph();
    g1.shortestPath(0);
    reader.close();

    reader.open(file2);
    reader >> size;
    Graph g2(size, reader);
    g2.printGraph();
    g2.shortestPath(4);
    reader.close();

    return 0;
}