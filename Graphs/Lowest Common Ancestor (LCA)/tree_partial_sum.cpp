#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

void addX(int u, int v, int x) {
	partial[u] += x;
	partial[v] += x;
	int lc = lca(u, v);
	partial[lc] -= x;
	partial[par[lc][0]] -= x;
}

void pushAll(int node, int pp) {
	for (auto v : neigh[node]) {
		if (v != pp)
			pushAll(v, node);
	}
	partial[par[node][0]] += partial[node];
}

int main() {
	blaze;

	return 0;
}