#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;

const int MOD = 1e9 + 7;
//=======================
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
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
		dist[a][b] = min(dist[a][b], c);
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