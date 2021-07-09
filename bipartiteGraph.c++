#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> color;
bool bipart;

void coloring(int u, int curr)
{
    if (color[u] != -1 and color[u] != curr)
    {
        bipart = false;
        return;
    }
    color[u] = curr;
    if (vis[u])
        return;
    vis[u] = true;
    for (auto i : adj[u])
    {
        coloring(i, curr xor 1);
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    bipart = true;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    color = vector<int>(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            coloring(i, 0);
        }
    }
    if (bipart)
        cout << "Graph is bipartite";
    else
        cout << "Graph is not Bipartite";
}