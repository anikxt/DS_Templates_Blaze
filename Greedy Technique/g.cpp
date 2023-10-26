#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

//  Find the maximum profit that can be obtained by buying and selling the stocks.
// allowed to perform as many transactions as you want.

#define int long long
int max_profit(vector<int> &prices) {
	int profit = 0;
	for (int i = 1; i < n; ++i)
	{
		if (prices[i] > prices[i - 1])
			profit += prices[i] - prices[i - 1];
	}
	return profit;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int ans = max_profit(arr);
	cout << ans << endl;
	return;
}

signed main()
{
	blaze;
	int _t = 1;
	cin >> _t;
	while (_t--) {
		solve();
	}
	return 0;
}