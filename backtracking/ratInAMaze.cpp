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

bool vis[100][100];

bool go(vector<vector<int>> &v, int sx, int sy, int dx, int dy, int r, int c)
{
    if (sx < 0 or sy < 0 or sx >= r or sy >= c or v[sx][sy] == 0 or vis[sx][sy] == true)
        return false;
    if (sx == dx and sy == dy)
        return true;
    vis[sx][sy] = true;
    // backtracking
    // right
    if (go(v, sx, sy + 1, dx, dy, r, c))
        return true;
    // left
    if (go(v, sx, sy - 1, dx, dy, r, c))
        return true;
    // down
    if (go(v, sx + 1, sy, dx, dy, r, c))
        return true;
    // up
    if (go(v, sx - 1, sy, dx, dy, r, c))
        return true;
    return false;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
            cin >> v[i][j];
    }
    memset(vis, false, sizeof(vis));
    cout << go(v, 0, 0, r - 1, c - 1, r, c) << endl;
    return 0;
}

/* Test Case
4 4
1 0 0 0
1 1 1 0
0 1 1 0
1 1 1 1
*/
