#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int dist[404][404];
int par[404][404];

// i -> x -> ... y -> par[i][j] -> j

void printPath(int i, int j) {
	if (i != j)
		printPath(i, par[i][j]);
	cout << j << endl;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
				dist[i][j] = 1e9;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
		// dist[a][b] = c;
	}

	// Reachability
	// for (int k = 0; k < n; ++k)
	// {
	// 	for (int i = 0; i < n; ++i)
	// 	{
	// 		for (int j = 0; j < n; ++j)
	// 		{
	// 			dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
	// 		}
	// 	}
	// }

	// Length of shortest cycle
	// for (int k = 0; k < n; ++k)
	// {
	// 	for (int i = 0; i < n; ++i)
	// 	{
	// 		for (int j = 0; j < n; ++j)
	// 		{
	// 			dist[i][j] = min(dist[i][j], dist[k][j]);
	// 		}
	// 	}
	// }

	// int ans = 1e9;
	// for (int i = 0; i < n; ++i)
	// {
	// 	ans = min(ans, dist[i][i]);
	// }
	// cout << ans << endl;

	// Checking if there is a negative cycle
	// If smallest cycle length is negative then YES else NO
	// if (ans < 0) {
	// 	cout << "YES" << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }

	// Diameter of a graph -> Longest (Shortest Path between any i to j).
	// Taking the maximum of the whole array excluding the unreachables(1e9) would give the diameter.


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			par[i][j] = i;
		}
	}


	// Note the order of the loops
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					par[i][j] = p[k][j];
				}
			}
		}
	}

	// dist[a][b]

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