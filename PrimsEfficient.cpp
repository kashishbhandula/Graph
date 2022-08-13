#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<int> color, par, dis;

int main()
{
    int n, e;
    cin >> n >> e;
    graph.assign(n + 1, vector<pair<int, int>>());
    color.assign(n + 1, 0);
    dis.assign(n + 1, 1e8);
    par.assign(n + 1, -1);
    par[1] = 0;

    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int root = pq.top().second;
        pq.pop();

        color[root] = 1;
        for (auto it : graph[root])
        {
            if (color[it.first] == 0 && it.second < dis[it.first])
            {
                par[it.first] = root;
                dis[it.first] = it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }
}