#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
private:
    int **cost;
    bool *found;
    const int size;
    int *distance;
    ifstream &reader;

public:
    Graph(int _size, ifstream &_reader) : size(_size), reader(_reader)
    {
        cost = new int *[size];
        for (int i = 0; i < size; i++)
        {
            cost[i] = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                reader >> cost[i][j];
            }
        }
        found = new bool[size];
        distance = new int[size];
    }

    void printGraph()
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

    void shortestPath(int v)
    {
        int i, u, w;
        for (i = 0; i < size; i++)
        {
            found[i] = false;
            distance[i] = cost[v][i];
        }
        found[v] = true;
        distance[v] = 0;
        for (i = 0; i < size - 1; i++)
        {
            u = choose();

            if (i == 0)
                cout << "Begin ";
            cout << "Distance : ";
            for (int j = 0; j < size; j++)
            {
                cout << distance[j] << " ";
            }
            cout << "\t(selected Node) : " << u << endl;

            found[u] = true;
            for (w = 0; w < size; w++)
            {
                if (!found[w])
                {
                    if (distance[u] + cost[u][w] < distance[w]) // Segmentation Error occured
                        distance[w] = distance[u] + cost[u][w];
                }
            }
        }
        cout << endl;
    }

    int choose()
    {
        int i, min, minnode;

        for (i = 0; i < size; i++)
        {
            if (distance[i] < min && !found[i])
            {
                min = distance[i];
                minnode = i;
            }
        }
        return minnode;
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