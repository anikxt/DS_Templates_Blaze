#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// LCS

int k;
vector<string> s;

map<vector<int>, int> dp;

int rec(vector<int> l) { // s1[l1...n-1], s2[l2...m-1]
	for (int i = 0; i < k; ++i)
	{
		if (l[i] == s[i].length())
			return 0;
	}

	if (dp.find(l) != dp.end()) {
		return dp[l];
	}

	int ans = 0;
	set<char> st;
	for (int i = 0; i < k; ++i)
	{
		st.insert(s[i][l[i]]);
		if (st.size() > 1)
			break;
	}
	if (st.size() == 1) {
		vector<int> temp = l;
		for (int i = 0; i < k; ++i)
		{
			temp[i]++;
		}
		ans = 1 + rec(temp);
	}

	for (int i = 0; i < k; ++i)
	{
		l[i]++;
		ans = max(ans, rec(l));
		l[i]--;
	}

	return dp[l] = ans;
}

void solve()
{
	cin >> k;
	s.resize(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> s[i];
	}

	vector<int> temp(k, 0);
	cout << rec(temp) << endl;

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
