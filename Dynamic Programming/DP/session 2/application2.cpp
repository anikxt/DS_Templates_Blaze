#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}
