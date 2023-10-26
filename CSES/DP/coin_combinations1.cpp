#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define int long long
const int MOD = 1e9 + 7;
int dp[1000100];

void solve()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }

    for (int i = 0; i <= x; ++i)
    {
        if (i == 0) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
            for (int j = 0; j < n; ++j)
            {
                if (c[j] <= i)
                    dp[i] += dp[i - c[j]];
            }
            dp[i] %= MOD;
        }
    }

    cout << dp[x] << endl;
    return;
}
#undef int

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
