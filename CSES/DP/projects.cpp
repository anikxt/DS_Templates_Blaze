#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

#define int long long
const int INF = 1000000000;

void solve()
{
    int n;
    cin >> n;
    pair<int, pair<int, int>> arr[n];
    for (int i = 0; i < n; ++i)
    {
        int l, r, p;
        cin >> l >> r >> p;
        arr[i] = {l, {r, p}};
    }

    sort(arr, arr + n);
    int dp[n + 1];
    for (int i = n; i >= 0; --i)
    {
        if (i == n) {
            dp[i] = 0;
        } else {
            // don't take
            dp[i] = dp[i + 1];
            // take
            int nextVal = arr[i].second.first;
            auto it = upper_bound(arr, arr + n, make_pair(nextVal, make_pair(INF, INF))) - arr;
            dp[i] = max(dp[i], arr[i].second.second + dp[it]);
        }
    }

    cout << dp[0] << endl;
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
