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

int n, m;
int arr[1001][1001];
int dp[1001][1001];
bool done[1001][1001];

int rec(int r, int c)
{
    // pruning
    if (r < 0 or c < 0)
        // not possible
        return -1e9;

    // base case
    if (r == 0 and c == 0)
        return arr[r][c];

    // cache and check
    if (done[r][c])
        return dp[r][c];

    // compute
    int ans = -1e9;
    if (r != 0)
    {
        ans = max(ans, rec(r - 1, c) + arr[r][c]);
    }
    if (c != 0)
    {
        ans = max(ans, rec(r, c - 1) + arr[r][c]);
    }

    // save and return
    done[r][c] = 1;
    return dp[r][c] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
            done[i][j] = 0;
        }
    }
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