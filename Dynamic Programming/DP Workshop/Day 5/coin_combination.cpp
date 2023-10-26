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

// Coin Change Problem Infinite Supply - Target Sum

void solve()
{
    int n, m;
    cin >> n >> m;
    int x[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    int dp[n + 1][m + 1];
    for (int level = n; level >= 0; --level)
    {
        for (int sum_left = 0; sum_left <= m; ++sum_left)
        {
            // compute for (level,sum_left)
            if (level == n)
            {
                if (sum_left == 0)
                {
                    dp[level][sum_left] = 1;
                }
                else
                {
                    dp[level][sum_left] = 0;
                }
            }
            // general
            dp[level][sum_left] = 0;
            if (dp[level + 1][sum_left])
            {
                dp[level][sum_left] = 1;
            }
            if (sum_left >= x[level] and dp[level][sum_left - x[level]])
            {
                dp[level][sum_left] = 1;
            }
        }
    }

    cout << dp[n][m] << endl;
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