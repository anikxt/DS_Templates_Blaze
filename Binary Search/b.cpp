#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// lower_bound (first number >= X)
int n, X;
int arr[100100];

bool check(int x)
{
    if (arr[x] < X)
        return 0;
    else
        return 1;
}

void solve()
{
    cin >> n >> X;
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