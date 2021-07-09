// problem
// Given a 2d board containing 'X' and 'O', capture
// all regions surroundex by 'X'.

// a region in captured by flipping all 'O's into 'X' in that
// surrunded region.

#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &Grid, int x, int y)
{
    Grid[x][y] = '*';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx >= 0 and cx < Grid.size() and Grid[cx][cy] == 'O')
        {
            change(Grid, cx, cy);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> Grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Grid[i][j];
        }
    }
    // change cornar or side 'O' to *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
                if (Grid[i][j] == 'O')
                    change(Grid, i, j); // * convert
        }
    }
    // change remainning 'O'(captured by 'X') to 'X'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Grid[i][j] == 'O')
                Grid[i][j] = 'X';
        }
    }
    // Now change '*' to 'O'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Grid[i][j] == '*')
                Grid[i][j] = 'O';
        }
    }
    // display the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << Grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
INPUT
4 4
XXXX
XOOX
XXOX
XOXX

OUTPUT
XXXX
XXXX
XXXX
XOXX

*/