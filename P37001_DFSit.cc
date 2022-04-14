#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
using namespace std;

using Node = string;
using Graph = vector<vector<Node>>;

Graph read_graph(map<Node, int> &pos)
{
    int n, m;
    cin >> n;
    Graph G(n);
    for (int i = 0; i < n; ++i)
    {
        Node city;
        cin >> city;
        pos[city] = i;
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        Node c1, c2;
        cin >> c1 >> c2;
        G[pos[c1]].push_back(c2);
    }
    return G;
}

void explore(const Graph &G, map<Node, int> &pos, vector<bool> &visited, Node x)
{
    stack<Node> pila;
    pila.push(x);
    while (not pila.empty())
    {
        Node v = pila.top();
        pila.pop();
        if (not visited[pos[v]])
        {
            visited[pos[v]] = true;
            for (Node u : G[pos[v]])
                pila.push(u);
        }
    }
}

bool connected(const Graph &G, map<Node, int> &pos, Node x, Node y)
{
    int n = G.size();
    vector<bool> visited(n, false);
    explore(G, pos, visited, x);
    return visited[pos[y]];
}

int main()
{
    map<Node, int> pos;
    Graph G = read_graph(pos);
    Node x, y;
    while (cin >> x >> y)
    {
        if (connected(G, pos, x, y))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}