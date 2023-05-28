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

// polygon triangulation - form 4 LR DP

int n;
pair<double, double> p[101];

double sq(double x)
{
    return x * x;
}

double cost(int x, int y)
{
    double dist = sqrt(sq(p[x].first - p[y].first) + sq(p[x].second - p[y].second));
    return sin(dist);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].first >> p[i].second;
    }

    int dp[n + 1][n + 1];
    for (int len = 0; len <= n; ++len)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            // dp[l][r]
            if (len == 3)
            {
                cout << 0 << endl;
                return;
            }
            // compute
            double ans = 1e9;
            for (int x = l + 1; x <= r - 1; x++)
            {
                if (x == l + 1)
                {
                    ans = max(ans, cost(l + 1, r) + dp[l + 1][r]);
                }
                else if (x == r - 1)
                {
                    ans = max(ans, cost(l, r - 1) + dp[l][r - 1]);
                }
                else
                {
                    ans = max(ans, cost(l, x) + cost(r, x) + dp[l][x] + dp[x][r]);
                }
            }
            dp[l][r] = ans;
        }
    }
    cout << dp[1][n] << endl;
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
    //   cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}