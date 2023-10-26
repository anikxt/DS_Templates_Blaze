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

// Application Form 2 - Hamiltonian Walk - Count Hamiltonian Walks

/*
Problem Statement:
A City is modelled using a Graph with N nodes and M edges.
The nodes are numbered from 1 to N.
There is a Person Standing at node i, and wants to visit a friend at City j.
He wants to visit every City exactly once.
Find the number of paths that exists of this form.

Constraints:
N <= 20
*/

/*
Time Complexity:
Overall: O((N+M)*2^N) ~ (N^2*2^N) in general, because number of edges can be of N^2.
*/

#define int long long
int n, m;
vector<vector<int>> g;
int dp[25][(1 << 20)];

int rec(int level, int mask) {
    // all one
    /*
    whenever n-th bit gets set, you just stop.
    this means, you never consider masks with the n-th bit set.
    */
    if (mask == ((1 << n) - 1))
        return 1;

    if (dp[level][mask] != -1)
        return dp[level][mask];

    int ans = 0;
    for (auto v : g[level]) {
        /*
        shifting v to v-1 position in bit so that it would remain between 0 to n-1.
        this is just an implementation level detail.
        */
        if (mask & (1 << (v - 1)))
            continue;

        (ans += rec(v, mask | (1 << (v - 1)))) %= MOD;
    }

    return dp[level][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(dp, -1, sizeof(dp));
        sum += rec(i, (1 << (i - 1)));
    }

    cout << sum << endl;
    return;
}
#undef int

int main()
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
