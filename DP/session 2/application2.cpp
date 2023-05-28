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

string S - length N
# of distinct subsequences of S

*/

// dp(i) -> # of new seq. created ending at i, in s[0...i]
// sum(i) -> summ. (j = 0 to i)	dp(j)
// dp(i) = sum(i-1) - sum(last(s(i))-1)
void solve()
{
	int n;
	string s;
	cin >> s;
	n = s.size();
	int dp[n + 1];
	int sum[n + 1];
	dp[0] = 1;
	sum[0] = 1;
	int last[26];
	memset(last, 0, sizeof(last));
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = sum[i - 1];
		if (last[s[i - 1] - 'A'] > 0) {
			dp[i] -= sum[last[s[i - 1] - 'A'] - 1];
		}
		last[s[i - 1] - 'A'] = i;
		sum[i] = dp[i] + sum[i - 1];
	}
	cout << sum[n] << endl;
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