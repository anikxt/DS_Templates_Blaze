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

#define MAXN 100100
vector<int> g[MAXN];
int inTime[MAXN], loTime[MAXN];
int timer = 0;

int numSplit[MAXN]; // if this is deleted how many new components will be formed

int dfs(int node, int par) {
    timer++;
    inTime[node] = loTime[node] = timer;
    bool isArti = false;
    int child = 0;

    numSplit[node] = 1;
    for (auto x : g[node]) {
        if (x == par)continue;
        if (!inTime[x]) { // node - x forward edge
            child++;
            dfs(x, node);
            loTime[node] = min(loTime[node], loTime[v]);
            if (loTime[x] >= inTime[node]) {
                isArti = true;
                numSplit[node]++;
                // x will be a new component
            }

            if (loTime[v] > inTime[node]) {
                // node - x is a bridge
                // pr(node, x);
            }
        } else { // node - x is a back edge
            loTime[node] = min(loTime[node], inTime[x]);
        }
    }

    if (par == 0) {
        numSplit[node] = child;
    }

    if ((par == 0 and child >= 2) or (par != 0 and isArti)) {
        // this node is an articulation point
        // pr("Art", node);
    }
}

void solve()
{   int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int comp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!inTime[i]) {
            comp++;
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (g[i].size() == 0) {
            cout << comp - 1 << " ";
        } else {
            cout << comp - 1 + numSplit[i] << " ";
        }
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