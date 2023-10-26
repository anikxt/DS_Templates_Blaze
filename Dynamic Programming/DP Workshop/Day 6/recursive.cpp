#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n, k;
int a[100010], b[100010];

const int INF = 1e9;
int dp[100010];

int rec(int level)
{
    // pruning
    if (level < 1)
        return INF;

    // base case
    if (level == 1)
        return 0;

    // cache check
    if (dp[level] != -1)
        return dp[level];

    // transition
    int ans = rec(level - 1) + b[level - 1];
    for (int j = 1; j <= k; ++j)
    {
        ans = min(ans, rec(level - j) + a[level - j] + a[level]);
    }

    // save and return
    return dp[level] = ans;
}

void input()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> b[i];
    }
}

void solve()
{
    input();
    cout << rec(n) << endl;
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
