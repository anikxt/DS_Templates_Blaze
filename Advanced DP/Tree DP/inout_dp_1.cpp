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

In-Out DP Tree:
indp(node) = Summ. (indp(child) + subtreeSz(child))
outdp(node) = Summ. (outdp(parent) + indp(parent) - (indp(node) + subtreeSz(node)) + (N - subtreeSz(node)))

ans(node) = indp(node) + outdp(node)

      root  (outdp(root) = 0) (we build from top to bottom)
      / \
     /   \
     B    C
    / \
   /   \
 leaf leaf (indp(leaf) = 0) (we build from bottom to top)

*/

/*
Problem Statement:
ans(i) = Summ. (x = 1 to N) (dist(i, x)), for all (i = 1 to N)
basically, ans(1), ans(2), ..., ans(n)
*/

int n;
vector<int> g[100100];
int subtreeSz[100100];
int indp[100100];
int outdp[100100];

void indfs(int node, int parent) {
    indp[node] = 0;
    subtreeSz[node] = 1;

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            subtreeSz[node] += subtreeSz[v];
            indp[node] += indp[v] + subtreeSz[v];
        }
    }
}

void outdfs(int node, int parent) {
    if (node == 1) {
        outdp[node] = 0;
    } else {
        outdp[node] = outdp[parent] + indp[parent] - (indp[node] + subtreeSz[node]) + (n - subtreeSz[node]);
    }

    for (auto v : g[node]) {
        if (v != parent) {
            outdfs(v, node);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1, 0);
    outdfs(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout << indp[i] + outdp[i] << " ";
    }
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