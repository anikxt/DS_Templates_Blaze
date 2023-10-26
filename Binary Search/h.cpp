#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Consecutive one
#define int long long
int n, k;
int arr[100100];

int check(int x)
{
    int cnt = 0, i;
    for (i = 0; i < x; ++i)
    {
        if (arr[i] == 0)
            cnt++;
    }

    if (cnt <= k)
        return true;

    for (i = x; i < n; ++i)
    {
        if (arr[i - x] == 0)
            cnt--;
        if (arr[i] == 0)
            cnt++;
        if (cnt <= k)
            return true;
    }
    return false;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int lo = k;
    int hi = n;
    int ans = lo;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return;
}

signed main()
{
    blaze;
    int _t = 1;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}