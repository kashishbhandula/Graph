#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<int> color, dis;

int main()
{
    int n, e;
    cin >> n >> e;
    graph.assign(n + 1, vector<pair<int, int>>());
    color.assign(n + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    dis.assign(n + 1, 1e8);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[1] = 0;
    q.push({0, 1});
    vector<int> par(n + 1, -1);
    while (!q.empty())
    {
        int root = q.top().second;
        q.pop();
        for (auto it : graph[root])
        {
            if (dis[root] + it.second < dis[it.first])
            {
                dis[it.first] = dis[root] + it.second;
                q.push({dis[it.first], it.first});
                par[it.first] = root;
            }
        }
    }
    cout << dis[n] << endl;

    return 0;
}