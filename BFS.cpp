#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool visit[N];
vector<int> adjl[N];

void BFS()
{
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while (!q.empty())
    {
        int node = q.front();

        q.pop();
        cout << node << " ";

        vector<int>::iterator it;
        for (it = adjl[node].begin(); it != adjl[node].end(); it++)
        {
            if (!visit[*it])
            {
                visit[*it] = 1;
                q.push(*it);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
        visit[i] = 0;

    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    //DFS Travarsal of Graph
    BFS();
    return 0;
}