#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// maximum value of the sum of arr[i] * i

#define int long long
int maximum_value(vector<int> &arr) {
	int n = arr.size(), ans = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; ++i)
	{
		ans = arr[i] * i;
	}
	return ans;
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
	int ans = maximum_value(arr);
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