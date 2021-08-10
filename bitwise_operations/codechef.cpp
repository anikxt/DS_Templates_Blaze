// https://www.codechef.com/COOK128A/problems/OROFAND

#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

void solve()
{
    int n, q;
    cin >> n >> q;

    int i, j, k, l;

    vector<int> a(n);
    vector<int> fre(32, 0);

    auto editt = [&](int x, int ext)
    {
        int i, j;
        int base = 1;
        for (i = 0; i < 32; ++i)
        {
            if (x & base)
                fre[i] += ext;

            base *= 2;
        }
    };

    for (i = 0; i < n; ++i)
    {
        cin >> a[i];
        editt(a[i], 1);
    }

    auto cal = [&]()
    {
        int i;
        int ans = 0;

        int base = 1;

        for (int i = 0; i < 32; ++i)
        {
            if (fre[i])
                ans += base;

            base *= 2;
        }

        return ans;
    };

    cout << cal() << endl;

    while (q--)
    {
        int idx, val;
        cin >> idx >> val;

        idx--;

        editt(val, 1);
        editt(a[idx], -1);

        a[idx] = val;

        cout << cal() << endl;
    }
}

signed main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}