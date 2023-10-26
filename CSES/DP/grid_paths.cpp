#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int dp[1010][1010];
const int MOD = 1e9 + 7;
vector<string> arr;

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 and j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
                if (i)(dp[i][j] += dp[i - 1][j] ) %= MOD;
                if (j)(dp[i][j] += dp[i][j - 1] ) %= MOD;
            }
            if (arr[i][j] == '*')dp[i][j] = 0;
        }
    }

    cout << dp[n - 1][n - 1] << endl;
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
