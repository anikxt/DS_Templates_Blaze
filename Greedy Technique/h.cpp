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

// Remove k digits from string to make it as smallest as possible.

string remove_k_digits(string &num, int k) {
	int n = num.size();
	string ans;
	stack<char> res;
	int i;
	for (i = 0; i < n; ++i)
	{
		while (!res.empty() and res.top() > num[i] and k > 0) {
			k--;
			res.pop();
		}
		res.push(num[i]);
	}
	while (!res.empty()) {
		ans.push_back(res.top());
		res.pop();
	}
	reverse(all(ans));
	while (k--)
		ans.pop_back();
	i = 0;
	while (i < n and ans[i] == '0')
		i++;
	ans = ans.substr(i);
	if (ans.empty())
		return "0";
	return ans;
}


void solve()
{
	string num;
	cin >> num;
	int k;
	cin >> k;
	string ans = remove_k_digits(num, k);
	cout << ans << endl;
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