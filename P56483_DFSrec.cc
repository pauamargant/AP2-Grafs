#include <iostream>
#include <vector>
using namespace std;

using Node = int;
using Graph = vector<vector<Node>>;

// Returns a non directed Graph with n vertices, m edges
Graph read_graph()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; ++i)
    {
        Node u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    return G;
}

void explore(Graph &G, vector<bool> &visited, Node v)
{
    visited[v] = true;
    for (Node u : G[v])
    {
        if (not visited[u])
            explore(G, visited, u);
    }
}

vector<Node> DFS(Graph &G)
{
    int n = G.size();
    vector<bool> visited(n, false);
    for (int v = 0; v < n; ++v)
    {
        if (not visited[v])
            explore(G, visited, v);
    }
}

int main()
{
    Graph G = read_graph();
    Node v, u;
    while (cin >> v >> u)
    {

        vector<bool> visited(G.size(), false);
        explore(G, visited, v);
        if (visited[u])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
