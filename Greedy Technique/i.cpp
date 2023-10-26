#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Find the number of flip operations that can be performed on k consecutive elements of the array such that the final array does not contain 0 or else return -1.

int minimum_flips(vector<int> &a, int k) {
	queue<int> flips;
	int res = 0, n = a.size();
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != (flips.size() % 2 ? 0 : 1)) {
			res++;
			flips.push(i + k - 1);
		}
		if (!flips.empty() and flips.front() <= i)
			flips.pop();
	}
	return flips.empty() ? res : -1;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int k;
	cin >> k;
	int ans = minimum_flips(a, k);
	cout << ans << endl;
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