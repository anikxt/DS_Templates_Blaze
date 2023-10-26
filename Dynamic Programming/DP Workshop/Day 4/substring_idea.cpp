#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n;
string t = "0100";
int dp[100100][16];

int rec(int level, int lastthree)
{
    // pruning

    // base case
    if (level == n)
        return 1;

    // cache check
    if (dp[level][lastthree] != -1)
        return dp[level][lastthree];

    // compute
    int ans = 0;
    if (level >= 3 and lastthree == 2)
    {   // 10.. ... .010
        // don't allow
        ans = rec(level + 1, 5);
    }
    else
    {
        // add a zero
        ans = rec(level + 1, (lastthree << 1 | 0) & 7);
        // add a one
        ans += rec(level + 1, (lastthree << 1 | 1) & 7);
    }

    // save and return
    return dp[level][lastthree] = ans;
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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
