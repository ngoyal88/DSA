#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printEdge()
    {
        for (auto i : adj)
        {
            cout << i.first << "->"<< " ";
            for (auto j : i.second)
            {
                cout <<j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph gp;
    gp.addEdge(1,2,0);
    gp.addEdge(2,3,0);
    gp.addEdge(3,2,0);
gp.printEdge();
    return 0;
}