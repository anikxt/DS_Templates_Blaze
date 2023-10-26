#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<int> g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subtreeSz[100100];
int numChild[100100];

void dfs(int node, int parent, int depth) {
	dep[node] = depth;
	par[node] = parent;

	subtreeSz[node] = 1;

	numChild[node] = 0;
	for (auto v : g[node]) {
		if (v != parent) {
			numChild[node]++;
			dfs(v, node, depth + 1);
			subtreeSz[node] += subtreeSz[v];
		}
	}
	if (numChild[node] == 0) {
		isLeaf[node] = 1;
	}
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0, 0);
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