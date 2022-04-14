#include <iostream>
#include <stack>
#include <vector>
using namespace std;

using Node = int;
using Graph = vector<vector<Node>>;

void explore(Graph &G, Node v, vector<Node> connected, int cnum)
{
    stack<Node> pila;
    pila.push(v);
    while (not pila.empty())
    {
        Node u = pila.top();
        pila.pop();
        if (connected[u] == -1)
        {
            connected[u] = cnum;
            for (Node w : G[u])
                pila.push(w);
        }
    }
}
/*
    Given an undirected Graph G returns its connected components

    Parameter
    ---------
    Graph G

    Returns
    -------
    connected: vector<int>
        Where for all the Nodes u1,...,uk in the same component, connected[ui] is the same
        and if v and u are not connected, connected[u]!=connected[v]
*/
vector<int> Connected_Components(Graph &G)
{
    int n = G.size();
    vector<Node> connected(n, -1);
    int cnum = 1;
    for (Node i = 0; i < n; ++i)
    {
        if (connected[i] == -1)
        {
            explore(G, i, connected, cnum);
            cnum++;
        }
    }
}