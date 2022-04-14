#include <iostream>
#include <vector>
#include <stack>
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
    stack<Node> pila;
    pila.push(v);
    while (not pila.empty())
    {
        Node v = pila.top();
        pila.pop();
        if (not visited[v])
        {
            visited[v] = true;
            for (Node u : G[v])
            {
                if (not visited[u])
                    pila.push(u);
            }
        }
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
