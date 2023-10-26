#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n, m;
vector<pair<int, int>> g[200200]; // adj. list
int dist[200200];

void BFS01(int sc) {
	deque<int> dq;
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = 1e9;
	}

	dist[sc] = 0;
	dq.push_back(sc);
	while (!dq.empty()) {
		int xx = dq.front();
		dq.pop_front();

		for (auto v : g[xx]) {
			int neigh = v.f;
			int weigh = v.s;
			if (dist[neigh] > dist[xx] + weigh) {
				dist[neigh] = dist[xx] + weigh;

				if (weigh == 0) {
					dq.push_front(neigh);
				} else {
					dq.push_back(neigh);
				}
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	int sc;
	cin >> sc;

	BFS01(sc);

	// t -> For all the node
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