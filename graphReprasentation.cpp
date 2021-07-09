#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vpi vector<pii>
#define f(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5 + 2, MOD = 1e9 + 7;

signed main()
{
    int n, m;
    cin >> n >> m;

    //Adjacency Matrix representation of a graph
    vii adjm(n + 1, vi(n + 1, 0));
    //input graph
    f(i, 0, m)
    {
        int x, y;
        cin >> x >> y;

        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    //display
    cout << "Adjacency Matrix Representation of the graph - " << endl;
    f(i, 1, n + 1)
    {
        f(j, 1, n + 1)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }

    //Adjacency List representation of a graph
    vi adjl[N];
    //input
    f(i, 0, m)
    {
        int x, y;
        cin >> x >> y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    //display
    cout << "Adjacency Matrix Representation of the graph - " << endl;
    f(i, 1, n + 1)
    {
        cout << i << " -> ";
        for (int x : adjl[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
