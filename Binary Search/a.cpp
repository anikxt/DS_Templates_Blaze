#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Search for first 1
int n;
int arr[100100];

// 0 0 0 0 0 1 1 1 1

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int lo = 0;
    int hi = n - 1;
    int ans = -1; // default answer
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] != 1)
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid;
            hi = mid - 1;
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