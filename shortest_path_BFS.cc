#include <vector>
#include <queue>
#include <climits>
using namespace std;

using Node = int;
using Graph = vector<vector<Node>>;
/*
    Given a Graph G and a node s, returns the distance from s to each node in G.
    If a node w is not connected with s, distance[w]=infinity
*/
vector<int> shortest_path(Graph &G, Node s)
{
    int n = G.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);
    distance[s] = 0;
    queue<Node> Q;
    Q.push(s);
    while (not Q.empty())
    {
        Node v = Q.front();
        Q.pop();
        for (Node w : G[v])
        {
            if (not visited[w])
            {
                visited[w] = true;
                distance[w] = distance[v] + 1;
                Q.push(w);
            }
        }
    }
}