#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

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

	return;
}

int main()
{
	blaze;
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}