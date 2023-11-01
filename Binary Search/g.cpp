#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Kth Sum Value
#define int long long
int n, m, k;
vector<int> a, b;

int check(int x)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt += upper_bound(b.begin(), b.end(), x - a[i]) - b.begin();
    }

    return cnt >= k;
}

void solve()
{
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    if (n > m)
    {
        swap(n, m);
        swap(a, b);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lo = a[0] + b[0];
    int hi = a.back() + b.back();
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