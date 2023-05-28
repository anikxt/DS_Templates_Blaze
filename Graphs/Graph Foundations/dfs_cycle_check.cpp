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

// cycle check + print using parent

int n, m;
vvi g;
vi col;
vi parent;
bool is_cycle = 0;
vi any_cycle;

void dfs(int node, int par) { // O(N + M)
    parent[node] = par;
    col[node] = 2;
    for (auto v : g[node]) {
        // add for undirected
        // if (v == parent[node])continue;
        if (col[v] == 1) {
            // node - v is a forward edge
            dfs(v, node);
        } else if (col[v] == 2) {
            // node - v is a back edge
            // We found a cycle !!
            cout << "Hit: " << node << endl;
            if (is_cycle == 0) {
                int temp = node;
                while (temp != v) {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(all(any_cycle));
            }
            is_cycle = 1;

        } else if (col[v] == 3) {
            // node - v is a cross edge
            // unimportant
        }
    }
    col[node] = 3;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (col[i] == 1) {
            dfs(i, 0);
        }
    }

    for (auto v : any_cycle) {
        cout << v << " ";
    }
    cout << endl;
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