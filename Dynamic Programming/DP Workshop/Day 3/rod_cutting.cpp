#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// LR DP aka Interval DP

int n;
int x[1001];
int dp[1001][1001];

int rec(int l, int r)
{
    // pruning

    // base case
    if (l + 1 == r)
        return 0;

    // cache check
    if (dp[l][r] != -1)
        return dp[l][r];

    // compute
    int ans = 1e9;
    for (int p = 0; p <= r - 1; ++p)
    {
        ans = min(ans, x[r] - x[l] + rec(l, p) + rec(p, r));
    }

    // save and return
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    x[0] = 0;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n) << endl;
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
