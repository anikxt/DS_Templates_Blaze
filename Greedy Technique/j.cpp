#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// minimum number of operations required to convert x to y.

void solve()
{
	int x, y;
	cin >> x >> y;
	if (x >= y)
		return x - y;
	int ans = 0;
	int temp = y;
	while (temp > x) {
		if (temp % 2)
			temp++;
		else temp /= 2;
		ans++;
	}
	ans += x - temp;
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