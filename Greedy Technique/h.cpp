#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
	reverse(ans.begin(), ans.end());
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