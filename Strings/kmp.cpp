#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// string = "abadabab"

vector<int> kmp(string s) {
	int n = s.length();
	vector<int> res(n + 1);
	int i = 0, j = -1;
	res[0] = -1;
	while (i < n) {
		while (j != -1 and s[i] != s[j]) {
			j = res[j];
		}
		i++;
		j++;
		res[i] = j;
	}
	return res;
}

int main() {
	blaze;
	string s;
	cin >> s;
	vector<int> ans = kmp(s);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}