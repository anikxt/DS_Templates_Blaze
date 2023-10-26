#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Coin Change Problem Infinite Supply - Target Sum

void solve()
{
    int n, m;
    cin >> n >> m;
    int x[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    int dp[n + 1][m + 1];
    for (int level = n; level >= 0; --level)
    {
        for (int sum_left = 0; sum_left <= m; ++sum_left)
        {
            // compute for (level,sum_left)
            if (level == n)
            {
                if (sum_left == 0)
                {
                    dp[level][sum_left] = 1;
                }
                else
                {
                    dp[level][sum_left] = 0;
                }
            }
            // general
            dp[level][sum_left] = 0;
            if (dp[level + 1][sum_left])
            {
                dp[level][sum_left] = 1;
            }
            if (sum_left >= x[level] and dp[level][sum_left - x[level]])
            {
                dp[level][sum_left] = 1;
            }
        }
    }

    cout << dp[n][m] << endl;
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
