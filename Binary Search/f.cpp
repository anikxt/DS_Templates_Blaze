#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Minimize the Maximum Neighbour Distance

int n, k;
int arr[100100];

bool check(int x)
{
    int needed = 0;
    for (int i = 1; i < n; ++i)
    {
        needed += (((arr[i] - arr[i - 1]) + x - 1) / x) - 1;
    }

    return needed <= k;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int lo = 0;
    int hi = 0;
    for (int i = 1; i < n; ++i)
    {
        hi = max(hi, arr[i] - arr[i - 1]);
    }

    int ans = -1; // default answer
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
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