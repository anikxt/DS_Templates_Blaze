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

// find max skill gain you can get

int n;
int t[1001];
int s[1001];
int x, k;

int taken[1001];

int check(int level)
{
    int timetaken = 0;
    int itemtaken = 0;
    for (int i = 0; i < level; ++i)
    {
        if (taken[i])
        {
            timetaken += t[i];
            itemtaken += s[i];
        }
    }

    timetaken += t[level];
    itemtaken++;

    if (itemtaken <= x and itemtaken <= k)
    {
        return 1;
    }

    return 0;
}

int rec(int level) // max skill i can make from [level..n-1].. if [0..level-1 is decided].
{
    // level -> current item in [0...n-1]

    // pruning

    // basecase
    if (level == n)
    {
        return 0;
    }

    // compute
    // loop over choice
    // choice 1: don't take
    int ans = rec(level + 1);
    // choice 2: take
    if (check(level))
    {
        // place the change
        taken[level] = 1;
        // move
        ans = max(ans, s[level] + rec(level + 1)); // max in [level+1..n]
        // revert
        taken[level] = 0;
    }

    // return
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> s[i];
    }
    cin >> x >> k;
    cout << rec(0) << endl;
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