#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Game DP
// Chips prob - x chips (pick 2^m chips in one turn where m <= log2(x))

int dp[100100];

int rec(int x)
{
    // pruning

    // base case
    if (x == 0)
        return 0;

    // cache check
    if (dp[x] != -1)
        return dp[x];

    // compute
    int ans = 0;
    for (int m = 0; (1 << m) <= x; ++m)
    {
        if (rec(x - (1 << m)) == 0)
        {
            ans = 1;
            break;
        }
    }

    // save and return
    return dp[x] = ans;
}

void solve()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
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
