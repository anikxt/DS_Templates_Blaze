#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Kth Sum Value
ll n, m, k;
vector<ll> a, b;

ll check(ll x)
{
    ll cnt = 0;
    for (ll i = 0; i < n; ++i)
    {
        cnt += upper_bound(all(b), x - a[i]) - b.begin();
    }

    return cnt >= k;
}

void solve()
{
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    if (n > m)
    {
        swap(n, m);
        swap(a, b);
    }
    sortall(a);
    sortall(b);

    ll lo = a[0] + b[0];
    ll hi = a.back() + b.back();
    ll ans = -1; // default answer
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
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