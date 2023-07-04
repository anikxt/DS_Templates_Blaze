#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// pre processing step
void dfs(int node, int prev, int dep) {
	par[node][0] = prev;
	depth[node] = dep;
	for (int i = 1; i < 20; i++) {
		par[node][i] = par[par[node][i - 1]][i - 1];
	}

	for (auto v : neigh[node]) {
		if (v != prev) {
			dfs(v, node, dep + 1);
		}
	}
}

// query step
int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	for (int i = 19; i >= 0; i--) {
		if ((depth[u] - depth[v]) & (1 << i)) {
			u = par[u][i];
		}
	}

	if (u == v)
		return u;

	for (int i = 19; i >= 0; i--) {
		if (par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}

	return par[u][0];
}

int main() {
	blaze;

	return 0;
}