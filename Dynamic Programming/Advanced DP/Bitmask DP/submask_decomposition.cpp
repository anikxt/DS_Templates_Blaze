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

// https://atcoder.jp/contests/dp/tasks/dp_u

// Application Form 6 - Submask Decomposition

/*
Problem Statement:
We have a class of N students, and they are asked to form Teams of any size.
If a student X and Y are in the same team,
they contribute Happy[X][Y] score to the final score of the decomposition.
Find the best way to form the teams so that maximum happiness can be generated.
Its given that Happy[X][Y] = Happy[Y][X].

Constraints:
N <= 15
-10^9 <= Happy[i][j] <= 10^9
*/

/*
Time Complexity:
Preprocessing = O((2^N)*N)
// Iterating through all masks with their submasks.
Overall = O(3^N)
*/

#define int long long
const int N = 17;
int n;
int dp[1 << N];
int g_happiness[1 << N];
int happy[N][N];

// preprocessing group happiness score
void precompute_happiness_group() {
    g_happiness[0] = 0;
    for (int mask = 1; mask < (1 << N); ++mask)
    {
        int temp = -1;
        for (int i = 0; i < N; ++i)
        {
            // find first element where it is 1
            if (mask & (1 << i)) {
                temp = i;
                break;
            }
        }

        g_happiness[mask] = 0;
        // looping over all elements
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1 << i)) {
                g_happiness[mask] += happy[i][temp];
            }
        }
        // reusing the value that is previously computed
        g_happiness[mask] += g_happiness[mask ^ (1 << temp)];
    }
}

/*
DP(mask) = best way to decompose people in mask.
DP(mask) = (for all submask which is a subset of mask)
 max(DP(mask^submask) + happiness[submask])
*/
int rec(int mask) {
    if (mask == 0)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = 0;
    for (int submask = mask; submask; submask = (submask - 1)&mask)
    {
        int temp = g_happiness[submask];
        ans = max(ans, temp + rec(mask ^ submask));
    }

    return dp[mask] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> happy[i][j];
        }
    }

    int mask = 0;
    for (int i = 0; i < n; ++i)
    {
        mask |= (1 << i);
    }
    precompute_happiness_group();
    memset(dp, -1, sizeof(dp));
    cout << rec(mask) << endl;
    return;
}

signed main()
{
    blaze;
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
