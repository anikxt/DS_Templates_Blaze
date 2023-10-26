#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // can also use a single variable to store current index optimum value instead of a dp array
    long long dp[n];
    long long ans = -1e9;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            dp[i] = arr[i];
        }
        else
        {
            dp[i] = max(dp[i - 1] + arr[i], 1LL * arr[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
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
