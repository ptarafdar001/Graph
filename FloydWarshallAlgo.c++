#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int32_t main()
{
    /*
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0));
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin >> x >> y>> w;

        adjm[x][y] = w;
        adjm[y][x] = w;
    }
    */
    vector<vector<int>> graph = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};

    int n = graph.size();
    vector<vector<int>> dist = graph;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}