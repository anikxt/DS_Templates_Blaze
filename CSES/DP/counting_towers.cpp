#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define int long long
const int MOD = 1e9 + 7;
int dp[1000100][2];

void solve()
{
    for (int i = 1; i <= 1000000; ++i)
    {
        if (i == 1) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        } else {
            dp[i][0] = ( 2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
        }
    }
    return;
}

signed main()
{
    blaze;
    solve();
    int _t = 1;
    cin >> _t;
    for (int i = 1; i <= _t; ++i)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}