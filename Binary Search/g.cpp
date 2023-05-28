#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;

const int MOD = 1e9 + 7;
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}