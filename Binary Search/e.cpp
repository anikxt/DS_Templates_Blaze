#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Painter's Partition Problem (Classical)
int n, k;
int arr[100100];

bool check(int x)
{
    int lastleft = 0;
    int needed = 0;
    for (int i = 0; i < n; ++i)
    {
        if (lastleft >= arr[i])
        {
            lastleft -= arr[i];
        }
        else
        {
            needed++;
            lastleft = x - arr[i];
        }
        if (needed > k)
            return 0;
    }
    return 1;
}

void solve()
{
    cin >> n >> k;
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }

    int ans = 0; // default answer
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
    // cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}