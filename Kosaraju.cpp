// toposort ,transpose the graph, dfs according to the graph
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph, graph1;
vector<int> color;
void Dfs(int root, stack<int> &st)
{
    color[root] = 1;
    for (auto it : graph[root])
    {
        if (color[it] == 0)
        {
            Dfs(it, st);
        }
    }
    st.push(root);
}
void Dfs(int root)
{
    color[root] = 1;
    cout << root << " ";
    for (auto it : graph[root])
    {
        if (color[it] == 0)
        {
            Dfs(it);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    graph.assign(n + 1, vector<int>());
    graph1.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    stack<int> st;
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v;
        graph[u].push_back(v);
        graph1[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            Dfs(i, st);
        }
    }
    color.assign(n + 1, 0);
    graph = graph1;
    while (!st.empty())
    {
        int root = st.top();
        st.pop();
        if (color[root] == 0)
        {
            Dfs(root);
            cout << endl;
        }
    }
}