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

// atmost m flights

int n, k, m;
int a[100010], b[100010];

const int INF = 1e9;
int dp[2][100010];

int rec(int level, int num)
{
    // pruning
    if (level < 1)
        return INF;

    // base case
    if (level == 1 and num == 0)
        return 0;
    else if (level == 1)
        return INF;

    // cache check
    if (dp[num][level] != -1)
        return dp[num][level];

    // transition
    int ans = rec(level - 1, num) + b[level - 1];

    if (num > 0)
        for (int j = 1; j <= k; ++j)
        {
            ans = min(ans, rec(level - j, num - 1) + a[level - j] + a[level]);
        }

    // save and return
    return dp[num][level] = ans;
}

struct monotone_deque
{
    deque<int> dq;
    void insert(int x)
    {
        while (!dq.empty() and dq.back() > x)
        {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void remove(int x)
    {
        if (!dq.empty())
        {
            if (dq.front() == x)
            {
                dq.pop_back();
            }
        }
    }

    int getmin()
    {
        if (!dq.empty())
        {
            return dq.front();
        }
        else
        {
            return 0;
        }
    }
};

void input()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> b[i];
    }
}

void solve()
{
    input();
    for (int j = 0; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            // (i, j)
            if (i == 0 and j == 0)
            {
                dp[j][i] = 0;
            }
            else if (i == 1)
            {
                dp[j][i] = INF;
            }

            dp[j][i] = dp[j][i - 1] + b[i - 1];

            if (j > 0)
                for (int x = 1; x <= k; ++x)
                {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + a[i - x] + a[i]);
                }
        }
    }
    cout << dp[n] << endl;
    return;
}

void solve2()
{
    input();
    monotone_deque dq;
    for (int j = 0; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            // (i, j)
            if (i == 0 and j == 0)
            {
                dp[j & 1][i] = 0;
            }
            else if (i == 1)
            {
                dp[j & 1][i] = INF;
            }
            else
            {
                dp[j & 1][i] = dp[j & 1][i - 1] + b[i - 1];

                if (j > 0)
                {
                    dq.insert(dp[(j - 1) & 1][i - 1] + a[i - 1]);
                    if (i - k - 1 >= 1)
                        dq.remove(dp[(j - 1) & 1][i - k - 1] + a[i - k - 1]);

                    dp[j & 1][i] = min(dp[j & 1][i], dq.getmin() + a[i]);
                }
            }
        }
    }
    cout << dp[n] << endl;
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