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
outdp(node) = Summ. (outdp(parent) + indp(parent) - (indp(node) - subtreeSz(node)) + (N - subtreeSz(node)))

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
ans(i) = height if you root at i, for all (i = 1 to N)
basically, ans(1), ans(2), ..., ans(n)
*/

int n;
vector<int> g[100100];

int indp[100100];
int outdp[100100];

int ans[100100];

void indfs(int node, int parent) {
    // set it value as if its a leaf
    indp[node] = 0;

    for (auto ch : g[node]) {
        if (ch != parent) {
            indfs(ch, node);
            indp[node] = max(indp[node], indp[ch] + 1);
        }
    }
}

void outdfs(int node, int parent, int outVal) {
    outdp[node] = outVal;

    int max1 = -1, max2 = -1;
    for (auto ch : g[node]) {
        if (ch != parent) {
            if (indp[ch] > max1) {
                max2 = max1;
                max1 = indp[ch];
            } else if (indp[ch] > max2) {
                max2 = indp[ch];
            }
        }
    }

    for (auto ch : g[node]) {
        if (ch != parent) {
            if (indp[ch] == max1) {
                outdfs(ch, node, max(max2 + 2, outdp[node] + 1));
            } else {
                outdfs(ch, node, max(max1 + 2, outdp[node] + 1));
            }
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
    outdfs(1, 0, 0);
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = max(indp[i], outdp[i]);
        cout << ans[i] << " ";
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