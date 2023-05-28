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

// components connectivity

int n, m;
vvi g;
vi vis;

void dfs(int node, int comp) {
    vis[node] = comp;
    for (auto v : g[node]) {
        if (!vis[v]) {
            dfs(v, comp);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    vector<pii> edgelist;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        edgelist.push_back({a, b});
    }

    int num_comp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i]) {
            num_comp++;
            dfs(i, num_comp);
        }
    }

    vi num_of_edge(num_comp + 1);
    for (auto v : edgelist) {
        num_of_edge[vis[v.first]]++;
    }
    return;
}

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