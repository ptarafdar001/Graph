//problem
// the game of snake and ladder
// you are at squre 1 and have to reach squre 100. you have
// complete control over the die and get any number from 1 - 6.
// for given ladders and snakes, find the minimam steps to reach

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int ladders, snakes;
    cin >> ladders;
    map<int, int> lad;
    map<int, int> snk;
    for (int i = 0; i < ladders; i++)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }
    cin >> snakes;
    for (int i = 0; i < snakes; i++)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }
    int moves = 0;
    queue<int> q;
    q.push(1); //initial square starts in 1
    bool found = false;
    vector<int> vis(101, 0);
    vis[1] = true;
    while (!q.empty() and !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                if (t + die == 100)
                    found = true;
                if (t + die <= 100 and lad[t + die] and !vis[lad[t + die]])
                {
                    vis[lad[t + die]] = true;
                    if (lad[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(lad[t + die]);
                }
                else if (t + die <= 100 and snk[t + die] and !vis[snk[t + die]])
                {
                    vis[snk[t + die]] = true;
                    if (snk[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(snk[t + die]);
                }
                else if (t + die <= 100 and !snk[t + die] and !lad[t + die] and !vis[t + die])
                {
                    vis[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }
    if (found)
        cout << moves << "\n";
    else
        cout << -1 << "\n";
}

/*
input 
2 ----laders
3 90
56 76
3 -----snakes
99 10
30 20
20 5
output
3 -- min no. of moves to reach

 */