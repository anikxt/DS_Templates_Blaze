#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

void solve() {
    int n;
    cin >> n;
    vector<int> h(n), dp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }

    for (int i = 1; i < n; ++i)
    {
        dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], i > 1 ? abs(h[i] - h[i - 2]) + dp[i - 2] : INT_MAX);
    }

    cout << dp[n - 1] << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}