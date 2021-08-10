#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(int i, int j, int m, int n)
{
    return (i >= 0 and i < m and j >= 0 and j < n and vis[i][j] == 0);
}

void go(int sx, int sy, int m, int n, ll &pt)
{
    if (sx == m - 1 and sy == n - 1)
        pt++;

    vis[sx][sy] = 1;
    for (int k = 0; k < 4; ++k)
    {
        int newsx = sx + dx[k];
        int newsy = sy + dy[k];
        if (valid(newsx, newsy, m, n))
        {
            go(newsx, newsy, m, n, pt);
        }
    }
    // backtracking
    vis[sx][sy] = 0;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
    freopen("/media/blaze/Data/Ember/error.txt", "w", stderr);
#endif
    int m, n;
    cin >> m >> n;
    memset(vis, 0, sizeof(vis));
    ll pt = 0;
    go(0, 0, m, n, pt);
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    deb(pt);
    return 0;
}
