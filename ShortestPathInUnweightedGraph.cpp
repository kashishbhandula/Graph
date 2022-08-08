#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> color, dis;

int main()
{
    int n, e;
    cin >> n >> e;
    graph.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dis.assign(n + 1, 1e8);
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    vector<int> par(n + 1, -1);
    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        for (auto it : graph[root])
        {
            if (dis[root] + 1 < dis[it])
            {
                dis[it] = dis[root] + 1;
                q.push(it);
                par[it] = root;
            }
        }
    }
    cout << dis[n] << endl;

    return 0;
}