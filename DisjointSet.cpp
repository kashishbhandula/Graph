#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> color, Rank, par;
int find(int node)
{
    if (node == par[node])
    {
        return node;
    }
    return par[node] = find(par[node]);
}
void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (Rank[u] < Rank[v])
    {
        par[u] = v;
    }
    else if (Rank[v] < Rank[u])
    {
        par[v] = u;
    }
    else
    {
        par[v] = u;
        Rank[u]++;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    graph.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    Rank.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    
}