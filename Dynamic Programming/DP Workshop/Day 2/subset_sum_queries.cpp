#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// subset sum exactly equal to T

int n;
int t;
int x[101];

int dp[105][10005];

int rec(int level, int left)
{
    // pruning
    if (left < 0)
        return 0;

    // base case
    if (level == n + 1)
    {
        if (left == 0)
            return 1;
        else
            return 0;
    }

    // cache check
    if (dp[level][left] != -1)
        return dp[level][left];

    // compute
    int ans = 0;
    if (rec(level + 1, left))
    {
        ans = 1;
    }
    else if (rec(level + 1, left - x[level]))
    {
        ans = 1;
    }

    // save and return
    return dp[level][left] = ans;
}

void solve()
{
    int r;
    cin >> r;
    cout << rec(1, r);
    return;
}

int main()
{
    blaze;
    int _t = 1;
    cin >> _t;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    memset(dp, -1, sizeof(dp));
    while (_t--) {
        solve();
    }
    return 0;
}