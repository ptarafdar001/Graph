// Dijkstra Algo - for Undirected Graph
// Single source sortest path

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
const int N = 1e5;

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(N, inf);
    vector<vector<pair<int, int>>> graph(N);

    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;

    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : graph[x.second])
        {
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] < inf)
        {
            cout << dist[i] << " ";
        }
    }
}