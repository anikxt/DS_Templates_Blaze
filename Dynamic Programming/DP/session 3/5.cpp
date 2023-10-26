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

N <- A : [1, 5, 3, 2, 7]
M <- B: [5, 9, 3, 7, 1]

given - all elements are distinct

(N, M <= 1e5)

find LCS

*/

int lis(vector<int> &arr) {
	vector<int> temp;
	for (auto v : arr) {
		if (temp.empty() or temp.back() < v) {
			temp.push_back(v);
		} else {
			auto it = lower_bound(temp.begin(), temp.end(), v);
			*it = v;
		}
	}
	return temp.size();
}

void solve()
{
	vector<int> A, B, temp;
	map<int, int> mp;
	for (int i = 0; i < A.size(); ++i)
	{
		mp[A[i]] = i;
	}
	for (auto v : B) {
		if (mp.find(v) != mp.end()) {
			temp.push_back(mp[v]);
		}
	}

	cout << lis(temp) << endl;
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