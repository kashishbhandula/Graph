#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> color;
stack<int> st;
void Dfs(int root, int p = 0)
{

    color[root] = 1;
    for (auto it : graph[root])
    {
        if (color[it] == 0)
        {
            Dfs(it, root);
        }
    }
    st.push(root);
}
int main()
{
    int n, e;
    cin >> n >> e;
    graph.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    while (!st.empty())
        st.pop();
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            Dfs(i);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}