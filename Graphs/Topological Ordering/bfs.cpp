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

vvi g;
vi indeg;

vi topo;
void kahn() {
    // for lexographical ordering, use priority queue.
    // priority_queue<int> q;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0) {
            // q.push(-i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        // int cur = -q.top();
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto v : g[cur]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                // q.push(-v);
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahn();
    if (topo.size() != n) {
        cout << "there is a cycle\n" << endl;
    } else {
        for (auto v : topo) {
            cout << v << endl;
        }
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