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

// LCS

int k;
vector<string> s;

map<vector<int>, int> dp;

int rec(vector<int> l) { // s1[l1...n-1], s2[l2...m-1]
	for (int i = 0; i < k; ++i)
	{
		if (l[i] == s[i].length())
			return 0;
	}

	if (dp.find(l) != dp.end()) {
		return dp[l];
	}

	int ans = 0;
	set<char> st;
	for (int i = 0; i < k; ++i)
	{
		st.insert(s[i][l[i]]);
		if (st.size() > 1)
			break;
	}
	if (st.size() == 1) {
		vector<int> temp = l;
		for (int i = 0; i < k; ++i)
		{
			temp[i]++;
		}
		ans = 1 + rec(temp);
	}

	for (int i = 0; i < k; ++i)
	{
		l[i]++;
		ans = max(ans, rec(l));
		l[i]--;
	}

	return dp[l] = ans;
}

void solve()
{
	cin >> k;
	s.resize(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> s[i];
	}

	vector<int> temp(k, 0);
	cout << rec(temp) << endl;

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