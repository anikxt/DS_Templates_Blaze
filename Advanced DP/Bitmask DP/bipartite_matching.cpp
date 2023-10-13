#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pr(v) for(auto &z: v) cout << z << ' '; cout << '\n'
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
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
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
//=======================

// Application Form 1 - Bipartite Matching

/*
Problem Statement:
There are N Ranks and M students in a class.
Each student has a happiness value for the rank in the class he gets.
The ith Student gets happy[i][j] on getting a rank j.
Its ok to not keep all students in the ranks (They get 0 happiness).
At most one student can be assigned to a rank.
The total happiness of the assignment can be calculated as
Sum of Happiness of each of the students in the class.
Find the best way to calculate maximum happiness attainable.

Constraints:
1 <= N <= 15.
1 <= M <= 50.
0<= happy[i][j] <= 10^5.
*/

/*
Strategy:
A. Iterate on one set. (students)
B. Keep track of elements taken already on the other set. (ranks, because ranks are smaller)
*/

/*
Time Complexity:
#state -> (M*2^N)
#transitions -> O(N)
Overall: O(N*M*2^N)
*/

#define MAXM 55
#define MAXN 15

#define int long long
int n, m;
int arr[MAXM][MAXN];
int dp[MAXM][(1 << MAXN)];

/*
rec(level, mask) -> Maximum happiness that can be collected
after level students processed and mask ranks blocked.
*/

// level ~ 50,  mask ~ 2^n
int rec(int level, int mask) {
    if (level == m)
        return 0;

    if (dp[level][mask] != -1)
        return dp[level][mask];

    // don't match this student
    int ans = rec(level + 1, mask);
    for (int i = 0; i < n; ++i)
    {
        // if rank not already alloted
        if ((mask & (1 << i)) == 0) {
            ans = max(ans, rec(level + 1, mask | (1 << i)) + arr[level][i]);
        }
    }

    return dp[level][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
    return;
}
#undef int

int main()
{
    blaze;
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