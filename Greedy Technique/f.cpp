#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// minimum number of operations such that the gcd of the array becomes equal or multiple of k

#define int long long
int minimum_operation(vector<int> &arr, int k) {
	int n = arr.size(), ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] != 1 and arr[i] > k) {
			ans += min(arr[i] % k, k - arr[i] % k);
		}
		else ans += (k - arr[i]);
	}
	return ans;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int ans = minimum_operation(arr, k);
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