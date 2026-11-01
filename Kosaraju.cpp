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



///////////////////////////////////////////



class Solution {
public:
    int timer = 0;

    vector<int> disc, low;
    vector<bool> inStack;
    stack<int> st;

    vector<vector<int>> scc;

    void dfs(int u, vector<vector<int>>& adj) {

        // 1. Assign discovery time
        disc[u] = low[u] = timer++;

        // 2. Push node into stack
        st.push(u);
        inStack[u] = true;

        // 3. Explore neighbours
        for (int v : adj[u]) {

            // Case 1: Neighbour not visited
            if (disc[v] == -1) {

                dfs(v, adj);

                low[u] = min(low[u], low[v]);
            }

            // Case 2: Neighbour is still in stack
            else if (inStack[v]) {

                low[u] = min(low[u], disc[v]);
            }
        }

        // 4. Found root of an SCC
        if (low[u] == disc[u]) {

            vector<int> component;

            while (true) {

                int node = st.top();
                st.pop();

                inStack[node] = false;

                component.push_back(node);

                if (node == u)
                    break;
            }

            scc.push_back(component);
        }
    }

    vector<vector<int>> tarjans(int n, vector<vector<int>>& adj) {

        disc.assign(n, -1);
        low.assign(n, 0);
        inStack.assign(n, false);

        for (int i = 0; i < n; i++) {

            if (disc[i] == -1) {
                dfs(i, adj);
            }
        }

        return scc;
    }
};
