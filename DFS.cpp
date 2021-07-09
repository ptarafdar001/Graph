#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool visit[N];
vector<int> adjl[N];

void DFS(int vartex)
{
    //preorder
    visit[vartex] = 1;
    cout << vartex << " ";

    //inorder
    vector<int>::iterator it;

    for (it = adjl[vartex].begin(); it != adjl[vartex].end(); it++)
    {
        if (visit[*it])
            ;
        else
        {
            DFS(*it);
        }
    }

    //postorder
    //cout << vartex << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        visit[i] = false;

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    DFS(1);
}