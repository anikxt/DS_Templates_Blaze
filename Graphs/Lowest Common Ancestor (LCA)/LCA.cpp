#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl
#define pr(v) for(auto &z: v) cout << z << ' '; cout << '\n'
#define pb push_back
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
#define int long long
using state = pair<int, int>;
int n, q;
vector<vector<int>> g, par;
vector<int> dep;

/*  LCA with Binary Lifting( with DFS time ) ~ O(NlogN + QlogN) for Q LCA queries.
*   supports finding kth ancestor of any node in O(logN) per query.
*   supports path aggregates(gcd, sum, max, min, XOR, etc.)
*/

// pre-processing step
// O(N*logN)-> logN bcoz of precomputation.
void dfs(int node, int parent, int depth) {
	// parent[node][i] denotes the 2^i th parent of node.
	par[node][0] = parent;
	dep[node] = depth;
	for (int i = 1; i < 20; ++i)
	{
		par[node][i] = par[par[node][i - 1]][i - 1];
	}

	for (auto v : g[node]) {
		if (v != parent) {
			dfs(v, node, depth + 1);
		}
	}
}

int walk(int u, int k) {
	// kth ancestor of u, only possible when level[u]>=k.
	if (k > dep[u])
		return -1;

	for (int i = 19; i >= 0; i--) {
		if ((k >> i) & 1)
			u = par[i][u];
	}

	return u;
}

// query step
// returns lca of u and v when root is = 1, O(logN) per queries.
int lca(int u, int v) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}

	// try to bring u to the same level as v
	for (int i = 19; i >= 0; --i)
	{
		if ((dep[u] - dep[v]) & (1 << i)) {
			u = par[u][i];
		}
	}

	// after being at same level try to bring them to the LCA node
	if (u == v)
		return u;

	for (int i = 19; i >= 0; --i)
	{
		if (par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}

	return par[u][0];
}

int dist(int u, int v) { // dist b/w u <---> v.
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

//Problem 1 (Dynamic Diameter): https://codeforces.com/problemset/problem/379/F
//Solution 1: https://codeforces.com/contest/379/submission/45960185

void solve()
{
	cin >> n;
	g.clear(); // clearing the graph for next test.
	g.resize(n + 1), par.resize(n + 1, vector<int> (20)), dep.resize(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, 0, 0);

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int u, v, z;
		cin >> u >> v >> z;
		int uv = lca(u, v), uz = lca(u, z), vz = lca(z, v);
		if (uz == uv) { // z is in v branch
			cout << vz;
		} else if (vz == uv) { // z is in u branch
			cout << uz;
		} else { // when z is in neither u/v branch
			cout << uv;
		}
		cout << endl;
		// can also do
		// cout << (uz ^ vz ^ uv) << endl;
	}
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