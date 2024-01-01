#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

const int N = 200200;
int n;
vector<int> g[N];
int dep[N], par[N];
int len_d; // diameter

void dfs(int node, int parent, int depth) {
	dep[node] = depth;
	par[node] = parent;
	for (auto v : g[node]) {
		if (v != parent) {
			dfs(v, node, depth + 1);
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

	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	dfs(1, 0, 0);
	int maxch = 1;
	for (int j = 2; j <= n; ++j)
	{
		if (dep[j] > dep[maxch]) {
			maxch = j;
		}
	}

	dfs(maxch, 0, 0);
	maxch = 1;
	for (int j = 2; j <= n; ++j)
	{
		if (dep[j] > dep[maxch]) {
			maxch = j;
		}
	}

	len_d = dep[maxch];
	// tracking back len_d/2 times to get the center
	int cen1 = maxch;
	int ops = 0;
	while (ops != len_d / 2) {
		cen1 = par[cen1];
		ops++;
	}

	int cen2 = -1;
	if (len_d % 2 == 1) {
		// 2 centers
		cen2 = par[cen1];
	}

	cout << (cen2 == -1 ? cen1 : -1) << endl;
	return;
}

int main()
{
	blaze;
	// int _t; cin >> _t; while (_t--)
	solve();
	return 0;
}