/// low[it]>=ins[node] &&par!=0
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> color, low, ins;
int timer = 1;
void Dfs(int root, int p = 0)
{

    color[root] = 1;
    int child = 0;
    low[root] = ins[root] = timer++;
    for (auto it : graph[root])
    {
        if (color[it] == 0)
        {
            Dfs(it, root);
            low[root] = min(low[root], low[it]);
            child++;
            if (low[it] >= ins[root] && p != 0)
            {
                cout << root << endl;
            }
        }
        else if (it != p)
        {
            low[root] = min(low[root], ins[it]);
        }
    }
    if (p == 0 && child > 1)
    {
        cout << root << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    timer = 1;
    graph.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    low.assign(n + 1, 0);
    ins.assign(n + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Dfs(1);
    return 0;
}