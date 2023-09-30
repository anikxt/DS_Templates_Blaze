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

// Two follow up probs -> max MST, pesudo node creation

#define int long long
using state = pair<int, int>;

struct UnionFind {
	int n, set_size;
	vector<int> par, sz;
	UnionFind() {}
	UnionFind(int a) {
		n = set_size = a;
		par.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int x) {
		if (x == par[x])return x;
		else return (par[x] = find(par[x])); // path compression, updating the parents as well
	}

	// size compression
	void unite(int x, int y) { // merge sety into setx
		int xroot = find(x);
		int yroot = find(y);
		if (xroot == yroot)
			return;
		if (sz[xroot] < sz[yroot])swap(xroot, yroot); // merging smaller set to larger
		sz[xroot] += sz[yroot];
		par[yroot] = xroot;
		set_size -= 1;
	}

	void reset() {
		set_size = n;
		for (int i = 1; i <= n; ++i)
		{
			par[i] = i;
			sz[i] = 1;
		}
	}

	int size() {
		return set_size;
	}

	void print() {
		for (int i = 1; i <= n; ++i)
		{
			cout << i << " " << par[i] << endl;
		}
	}
};


void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<state>> g(n + 1);
	vector<pair<int, state>> edgeList; // weight, {a,b}
	UnionFind uf(n);

	for (int i = 0; i < m; ++i)
	{
		int a, b, wt;
		cin >> a >> b >> wt;
		edgeList.push_back({wt, {a, b}});
	}

	sort(edgeList.begin(), edgeList.end());

	int mst_cost = 0;
	int cnt = 0;
	for (auto edge : edgeList) {
		int a = edge.second.first;
		int b = edge.second.second;
		int wt = edge.first;
		if (uf.find(a) != uf.find(b)) {
			cnt++;
			mst_cost += wt;
			// creating mst graph
			g[a].push_back({b, edge.first});
			g[b].push_back({a, edge.first});
			uf.unite(a, b);
		}
	}

	// how to check if MST found or not? To keep the track of the number of edges you have added.
	if (cnt == n - 1) {
		cout << mst_cost << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
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