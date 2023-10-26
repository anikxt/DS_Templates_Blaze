#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int dp[1000100];

set<int> getDigits(int x) {
    set<int> dig;
    while (x) {
        dig.insert(x % 10);
        x /= 10;
    }
    return dig;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i)
    {
        if (i == 0) {
            dp[i] = 0;
        } else {
            dp[i] = 1e9;
            for (auto d : getDigits(i)) {
                dp[i] = min(dp[i], 1 + dp[i - d]);
            }
        }
    }

    cout << dp[n] << endl;
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
