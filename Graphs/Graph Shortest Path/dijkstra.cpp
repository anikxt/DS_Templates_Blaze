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


/*
Consider the undirected graph with just edge 1 2 1 and the directed graph with edge 1 2 1.
The distance between 2 to 1 in the undirected graph is 1, but in the directed graph is +inf.
*/

class prioritize {
public: bool operator ()(pii &p1, pii &p2) {
		return p1.s > p2.s;
	}
};

int n, m;
vector<pii> g[100100];

ll dist[100100];
int vis[100100];

void dijkstra(int sc) {
	priority_queue<pii, vector<pii>, prioritize> pq;
	dist[sc] = 0;
	pq.push(mp(sc, 0));

	while (!pq.empty()) {
		pii fs = pq.top();
		pq.pop();

		if (vis[fs.f])
			continue;
		vis[fs.f] = 1;

		for (auto v : g[fs.f]) {
			int neigh = v.f;
			int wt = v.s;
			if (dist[neigh] > dist[fs.f] + wt) {
				dist[neigh] = dist[fs.f] + wt;
				pq.push(mp(neigh, dist[neigh]));
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