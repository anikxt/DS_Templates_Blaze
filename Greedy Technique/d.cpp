#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// minimum product of a subset of numbers of an array

#define int long long
int minProductSubset(vector<int, int> &a, int n) {
	if (n == 1)
		return a[0];
	int max_neg = INT_MIN;
	int min_pos = INT_MAX;
	int cnt_neg = 0, cnt_zero = 0;
	int prod = 1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0) {
			cnt_zero++;
			continue;
		}
		if (a[i] < 0) {
			cnt_neg++;
			max_neg = max(max_neg, a[i]);
		}
		if (a[i] > 0) {
			min_pos = min(min_pos, a[i]);
		}
		prod = prod * a[i];
	}
	if (cnt_zero == n or (cnt_neg == 0 and cnt_zero > 0))
		return 0;
	if (cnt_neg == 0)
		return min_pos;
	if (!(cnt_neg & 1) && cnt_neg != 0) {
		prod = prod / max_neg;
	}
	return prod;
}


void solve()
{
	int n;
	cin >> n;
	vector<int, int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int ans = minProductSubset(a, n);
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