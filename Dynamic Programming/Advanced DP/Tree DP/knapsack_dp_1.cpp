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

/*
Problem Statement:
Maximize the sum of value taken such that no 2 adjacent node should be selected
*/

int n;
int arr[100100];
vector<int> g[100100];

// dp(node, parent taken/not) -> best you can do
int dp[100100][2];
void indfs(int node, int parent) {
    // 0 means I am forcefully taking this particular node right now
    dp[node][0] = arr[node];
    dp[node][1] = 0;

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            dp[node][1] += dp[v][0];
            dp[node][0] += dp[v][1];
        }
    }
    /*
    think about it when there is no child,
    the above auto for loop code will not execute at all,
    and it would be just max of the parent taken or not taken.
    */
    dp[node][0] = max(dp[node][0], dp[node][1]);
}

// dp2(node, take this/not this) -> best you can do
int dp2[100100][2];
void indfs2(int node, int parent) {
    // if(1) then take, if(0) then dont take
    dp2[node][1] = arr[node];
    dp2[node][0] = 0;

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            dp2[node][1] += dp2[v][0];
            dp2[node][0] += max(dp2[v][0], dp2[v][1]);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // its upto you how you want to keep the meaning of the dp
    indfs(1, 0);
    indfs2(1, 0);
    cout << dp[1][0] << endl;
    cout << max(dp2[1][0], dp2[1][1]) << endl;
    return;
}

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