#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
	int _t = 1;
	// cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}