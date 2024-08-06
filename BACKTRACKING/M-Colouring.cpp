#include <iostream>
#include <vector>
using namespace std;
#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
        {
            return false;
        }
    }
    return true;
}

bool graphcoloringutil(bool graph[V][V], int m, int color[], int v)
{
    // reched last node OR assigned every node a colour

    if (v == V)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(v, graph, color, i))
        {
            color[v] = i;

            if (graphcoloringutil(graph, m, color, v + 1) == true)
            {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

bool graphcoloring(bool graph[V][V], int m)
{
    // initialize color array with zero
    int color[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = 0;
    }

    // calling for vertex 0
    if (graphcoloringutil(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(color);
    return true;
}
void printSolution(int color[V])
{
    cout << "Solution Exists :";
    cout << "Following are the assigned colors :"<<endl;
    for (int i = 0; i < V; i++)
    {
        cout << " " << color[i] << endl;
    }
}
int main()
{
    /*
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; 

 
    graphcoloring(graph, m);
    return 0;
}