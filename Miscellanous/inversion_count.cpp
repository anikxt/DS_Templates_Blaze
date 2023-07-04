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

int inv_cnt = 0;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> final;
	int i = 0, j = 0;
	while (i < left.size() and j < right.size()) {
		if (left[i] <= right[j]) {
			final.push_back(left[i]);
			i++;
		} else {
			final.push_back(right[j]);
			j++;
			inv_cnt += left.size() - i;
		}
	}

	while (i < left.size()) {
		final.push_back(left[i]);
		i++;
	}

	while (j < right.size()) {
		final.push_back(right[j]);
		j++;
	}

	return final;
}

vector<int> merge_sort(vector<int> arr) {
	int n = arr.size();
	if (n <= 1) {
		return arr;
	}

	int half = n / 2;
	vector<int> left, right;
	for (int i = 0; i < n; ++i)
	{
		if (i < half)left.push_back(arr[i]);
		else right.push_back(arr[i]);
	}

	left = merge_sort(left);
	right = merge_sort(right);
	return merge(left, right);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	arr = merge_sort(arr);
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