#include <bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Consider the undirected graph with just edge 1 2 1 and the directed graph with edge 1 2 1.
The distance between 2 to 1 in the undirected graph is 1, but in the directed graph is +inf.
*/

#define int long long
class prioritize {
public: bool operator ()(pair<int, int> &p1, pair<int, int> &p2) {
		return p1.S > p2.S;
	}
};

int n, m;
vector<pair<int, int>> g[100100];

int dist[100100];
int vis[100100];

void dijkstra(int sc) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, prioritize> pq;
	dist[sc] = 0;
	pq.push(make_pair(sc, 0));

	while (!pq.empty()) {
		pair<int, int> fs = pq.top();
		pq.pop();

		if (vis[fs.F])
			continue;
		vis[fs.F] = 1;

		for (auto v : g[fs.F]) {
			int neigh = v.F;
			int wt = v.S;
			if (dist[neigh] > dist[fs.F] + wt) {
				dist[neigh] = dist[fs.F] + wt;
				pq.push(make_pair(neigh, dist[neigh]));
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
	}

	for (int i = 1; i <= n; ++i)
	{
		dist[i] = 1e18;
		vis[i] = 0;
	}

	dijkstra(1);
	return;
}

signed main()
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