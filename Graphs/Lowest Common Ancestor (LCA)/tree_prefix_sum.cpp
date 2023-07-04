#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

void dfs(int node, int dep, int par, int val) {
	prefix[node] = val + prefix[par];

	// build things needed for LCA.
	for (auto v : neigh[node]) {
		if (v.first != par)
			dfs(v.first, dep + 1, node, v.second);
	}
}

int getSum(int u, int v) {
	return prefix[u] + prefix[v] - 2 * prefix[lca(u, v)];
}

int main() {
	blaze;

	return 0;
}