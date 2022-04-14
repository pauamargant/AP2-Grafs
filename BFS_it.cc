#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using Node = int;
using Graph = vector<vector<Node>>;

/*
    Makes a BFS of the Graph G starting from node V. Uses a boolean list visited where visited[u]
    is True if u has been visited anf False otherwise

    Runtime
    *******
    O(m+n) where m=|E|, n=|V|

*/

void BFS(Graph &G, Node v, vector<bool> &visited)
{
    visited[v] = true;
    queue<Node> Q;
    while (not Q.empty())
    {
        Node u = Q.front();
        Q.pop();
        for (Node w : G[u])
        {
            if (not visited[w])
            {
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}
