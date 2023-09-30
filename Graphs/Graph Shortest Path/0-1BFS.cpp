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