#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> color;
bool Dfs(int root, int p = 0)
{

    if (color[root] == 1)
        return true;
    color[root] = 1;
    for (auto it : graph[root])
    {
        if (color[it] != 2 && it != p)
        {
            if (Dfs(it, root))
                return true;
        }
    }
    color[root] = 2;
    return false;
}
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
    for (int i = 1; i <= n; i++)
    {
        if (color[i] != 2)
        {
            if (Dfs(i))
            {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}