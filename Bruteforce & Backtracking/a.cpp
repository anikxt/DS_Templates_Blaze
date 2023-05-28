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

/*
abcde/fghij = N
*/

const int MOD = 1e9 + 7;
//=======================
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
//=======================

int n;

void solve1()
{
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cin >> n;
	do {
		int abcde = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[4];
		int fghij = arr[0 + 5] * 10000 + arr[1 + 5] * 1000 + arr[2 + 5] * 100 + arr[1 + 5] * 10 + arr[4 + 5];
		if (abcde % fghij == 0) {
			cout << abcde << " " << fghij << " " << abcde / fghij << endl;
		}
	} while (next_permutation(all(arr)));
	return;
}

void solve2() {
	cin >> n;
	for (int fghij = 1234; fghij <= 98765 / n; ++fghij)
	{
		int abcde = n * fghij;
		set<int> st;

		int temp = abcde;
		for (int i = 0; i < 5; ++i)
		{
			st.insert(temp % 10);
			temp /= 10;
		}

		temp = fghij;
		for (int i = 0; i < 5; ++i)
		{
			st.insert(temp % 10);
			temp /= 10;
		}

		if (st.size() == 10) {
			cout << abcde << " " << fghij << endl;
		}
	}
}

int main()
{
	blaze;
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		// cout << "Case #" << i << ": ";
		solve1();
	}
	// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}