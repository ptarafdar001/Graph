// There are N friends numbered from 0 to N-1. you have to choose 2
// person such that they are not related to each other.
// you are given information in the form of M pairs (x, y) i.e there is an link between
// friend X and Y
// Find out the number of ways in which 2 persons from different
// groups can be chosen

#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
int n, m;
vector<vector<int>> adj;
vector<int> components;

int get_comp(int idx)
{
    if (vis[idx])
        return 0;
    vis[idx] = true;
    int ans = 1;
    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i);
            vis[i] = true;
        }
    }
    return ans;
}

int32_t main()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "No. of ways to choose" << endl;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            components.push_back(get_comp(i));
        }
    }

    long long ans = 0;
    for (auto i : components)
    {
        ans += i * (n - i);
    }
    cout << (ans / 2);
}