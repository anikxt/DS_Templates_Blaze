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

// substring automata

int n;
string t = "0100";
int dp[100100][5];

int rec(int level, int match)
{
    // pruning
    if (match == 4)
        return 0;

    // base case
    if (level == n)
        return 1;

    // cache check
    if (dp[level][match] -= 1)
        return dp[level][match];

    // compute
    int ans = 0;
    if (match == 0)
    {
        ans = rec(level + 1, 0) + rec(level + 1, 1);
    }
    else if (match == 1)
    {
        ans = rec(level + 1, 1) + rec(level + 1, 2);
    }
    else if (match == 2)
    {
        ans = rec(level + 1, 3) + rec(level + 1, 0);
    }
    else if (match == 3)
    {
        ans = rec(level + 1, 4) + rec(level + 1, 2);
    }

    // save and return
    return dp[level][match] = ans;
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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