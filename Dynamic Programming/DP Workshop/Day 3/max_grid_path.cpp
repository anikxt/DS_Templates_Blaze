#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n, m;
int arr[1001][1001];
int dp[1001][1001];
bool done[1001][1001];

int rec(int r, int c)
{
    // pruning
    if (r < 0 or c < 0)
        // not possible
        return -1e9;

    // base case
    if (r == 0 and c == 0)
        return arr[r][c];

    // cache and check
    if (done[r][c])
        return dp[r][c];

    // compute
    int ans = -1e9;
    if (r != 0)
    {
        ans = max(ans, rec(r - 1, c) + arr[r][c]);
    }
    if (c != 0)
    {
        ans = max(ans, rec(r, c - 1) + arr[r][c]);
    }

    // save and return
    done[r][c] = 1;
    return dp[r][c] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
            done[i][j] = 0;
        }
    }
    return;
}

int main()
{
    blaze;
    int _t = 1;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}
