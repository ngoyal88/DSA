#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class graph
{

    int vertices;
    vector<vector<int>> adjencyList;

public:
    graph(int v) : vertices(v), adjencyList(v) {}

    void addEdge(int v, int w)
    {
        adjencyList[v].push_back(w);
    }

    void BFS(int startvertex)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[startvertex] = true;
        q.push(startvertex);

        while (!q.empty())
        {
       
            int currVertex = q.front();
            q.pop();

            cout << currVertex << " ";

            for (int adjacent : adjencyList[currVertex])
            {
                if (!visited[adjacent])
                {
                    q.push(adjacent);
                    visited[adjacent] = true;
                }
            }
        }
    }
};

int main()
{
    graph gp(6);
    gp.addEdge(0,4);
    gp.addEdge(4,2);
    gp.addEdge(4,1);
    gp.addEdge(1,3);
    gp.addEdge(1,5);
    gp.addEdge(3,5);
   
    gp.BFS(0);
    return 0;
}