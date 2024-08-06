#include <iostream>
#include <vector>
#include <stack>
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

    void DFS(int startvertex)
    {
        vector<bool> visited(vertices, false);
        stack<int> s;

        visited[startvertex] = true;
        s.push(startvertex);

        while (!s.empty())
        {
       
            int currVertex = s.top();
            s.pop();

            cout << currVertex << " ";

            for (int adjacent : adjencyList[currVertex])
            {
                if (!visited[adjacent])
                {
                    s.push(adjacent);
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
    gp.DFS(0);
    return 0;
}