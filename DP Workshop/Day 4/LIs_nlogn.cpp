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

/*
INPUT
10
1 5 7 10 9 6 7 9 2 3
*/

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    // printing index array
    int insertedat[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> lis;
    for (int i = 0; i < n; ++i)
    {
        if (lis.empty() or lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
            insertedat[i] = lis.size();
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            insertedat[i] = it - lis.begin() + 1;
        }
    }

    vector<int> final_lis;
    int curlen = lis.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (insertedat[i] == curlen)
        {
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }

    reverse(all(final_lis));
    for (auto v : final_lis)
        cout << v << " ";
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
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}