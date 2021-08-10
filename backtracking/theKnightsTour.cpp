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

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool valid(int i, int j, int n, vector<vector<int>> &v)
{
    return (i >= 0 and i < n and j >= 0 and j < n and v[i][j] == 0);
}

bool go(vector<vector<int>> &v, int x, int y, int n, int mv)
{
    if (mv == n * n)
        return true;

    for (int k = 0; k < 8; ++k)
    {
        int newx = x + dx[k];
        int newy = y + dy[k];
        if (valid(newx, newy, n, v))
        {
            v[newx][newy] = mv;
            if (go(v, newx, newy, n, mv + 1))
                return true;
            v[newx][newy] = 0; // backtracking
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
    freopen("/media/blaze/Data/Ember/error.txt", "w", stderr);
#endif
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    v[0][0] = 1;
    go(v, 0, 0, n, 2);
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << v[i][j] << "\t";
        cout << endl;
    }
    return 0;
}