// Eulerian path and circuit for undirected graph
#include <iostream>
#include <list>
using namespace std;

class graph
{
private:
    int V;
    list<int> *adj;

public:
    graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~graph()
    {
        delete[] adj;
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int Eulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};

void graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    for (int neighbour : adj[v])
    {
        if (!visited[neighbour])
        {
            DFSUtil(neighbour, visited);
        }
    }
}
bool graph::isConnected()
{
    bool visited[V];
    int i;
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() != 0)
            break;
    }
    if (i == V)
    {
        return true;
    }
    DFSUtil(i, visited);

    for (i = 0; i < V; i++)
        if (visited[i] == false && adj[i].size() > 0)
            return false;

    return true;
}
int graph::Eulerian()
{
    if (isConnected() == false)
        return 0;

    int odd = 0;
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() & 1)
        {
            odd++;
        }
    }

    if (odd > 2)
        return 0;

    return (odd) ? 1 : 2;
}

void test(graph &g)
{
    int res = g.Eulerian();
    cout<<"hi";
    if (res == 0)
        cout << "graph is not Eulerian\n";
    else if (res == 1)
        cout << "graph has a Euler path\n";
    else
        cout << "graph has a Euler cycle\n";
}
int main()
{
    graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);
 
    graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);
 
    graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);
 
    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);
 

    graph g5(3);
    test(g5);

    return 0;
}