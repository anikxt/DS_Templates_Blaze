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

Design a DS

N arr

Query:
1 l r v -> for [l, r] do arr[i] += v
2 x     -> find arr[i]

*/

int n;
int arr[100100];

int t[400400];

void update(int index, int l, int r, int pos, int val) {
	if (pos < l or pos > r)
		return;

	if (l == r) {
		t[index] += val;
		return;
	}

	int mid = (l + r) / 2;
	update(index * 2, l, mid, pos, val);
	update(index * 2 + 1, mid + 1, r, pos, val);
	t[index] = t[index * 2] + t[index * 2 + 1];
}


int query(int index, int l, int r, int lq, int rq) {
	if (l > rq or lq > r)
		return 0;

	if (lq <= l and r <= rq) {
		// lq <= l <= r <= rq
		return t[index];
	}

	int mid = (l + r) / 2;
	return query(index * 2, l, mid, lq, rq) + query(index * 2 + 1, mid + 1, r, lq, rq);
}

void solve()
{
	cin >> n;

	memset(arr, 0, sizeof(arr));
	memset(t, 0, sizeof(t));

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int ch;
		cin >> ch;
		if (ch == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			update(1, 0, n - 1, l, v);
			if (r + 1 < n)
				update(1, 0, n - 1, r + 1, -v);
		} else {
			int x;
			cin >> x;
			cout << query(1, 0, n - 1, 0, x) << endl;
		}
	}

	return;
}

int main()
{
	blaze;
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}