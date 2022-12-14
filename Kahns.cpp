#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> color, Indegree;

int main()
{
    int n, e;
    cin >> n >> e;
    graph.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    Indegree.assign(n + 1, 0);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        Indegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (Indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int root = q.front();
        cout << root << " ";
        q.pop();
        for (auto it : graph[root])
        {
            Indegree[it]--;
            if (Indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    cout << endl;
}