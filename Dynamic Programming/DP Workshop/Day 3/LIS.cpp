#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n;
int arr[10010];
int dp[10010];

int rec(int level)
{
    // best LIS ending at level.
    // pruning
    if (level < 0)
        return 0;

    // base case

    // cache check
    if (dp[level] != -1)
        return dp[level];

    // compute
    int ans = 1;
    for (int prev_taken = 0; prev_taken < level; prev_taken++)
    {
        if (arr[prev_taken] < arr[level])
        {
            ans = max(ans, 1 + rec(prev_taken));
        }
    }

    // save and return
    return dp[level] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int best = 0;
    for (int i = 0; i < n; ++i)
    {
        best = max(best, rec(i));
    }

    cout << best << endl;
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
