#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define deb(x) cout << #x << "=" << x << endl
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

int vis[100][100];

bool posValidator(int x, int y, int n)
{
    for (int row = 0; row < x; ++row)
    {
        if (vis[row][y] == 1)
            return false;
    }

    int row = x, col = y;
    while (row >= 0 and col >= 0)
    {
        if (vis[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = x, col = y;
    while (row >= 0 and col < n)
    {
        if (vis[row][col] == 1)
            return false;
        row--;
        col++;
    }

    return true;
}

bool nQueen(int x, int n)
{
    if (x == n)
        return true;
    for (int col = 0; col < n; ++col)
    {
        if (posValidator(x, col, n))
        {
            vis[x][col] = 1;
            if (nQueen(x + 1, n))
                return true;
            vis[x][col] = 0; // backtracking
        }
    }
    return false;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    memset(vis, 0, sizeof(vis));
    nQueen(0, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// set, recursive call, unset
