#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define int long long
const int MOD = 1e9 + 7;
int dp[100100][110];
vector<int> arr;

void solve()
{
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = n; i >= 0; --i)
    {
        for (int last = 1; last <= m; ++last)
        {
            if (i == n) {
                dp[i][last] = 1;
            } else {
                dp[i][last] = 0;
                if (arr[i] == 0) {
                    for (int diff = -1; diff <= 1; ++diff)
                    {
                        int cur = last + diff;
                        if (cur >= 1 and cur <= m)
                            (dp[i][last] += dp[i + 1][cur] % MOD) %= MOD;
                    }
                } else {
                    int cur = arr[i];
                    if (abs(cur - last) <= 1)
                        (dp[i][last] += dp[i + 1][cur] % MOD) %= MOD;
                }
            }
        }
    }

    int ans = 0;
    if (arr[0] == 0) {
        for (int cur = 1; cur <= m; ++cur)
        {
            (ans += dp[1][cur] % MOD) %= MOD;
        }
    } else {
        int cur = arr[0];
        (ans += dp[1][cur] % MOD) %= MOD;
    }

    cout << ans << endl;
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
