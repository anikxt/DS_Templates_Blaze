#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
abcde/fghij = N
*/

int n;

void solve1()
{
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cin >> n;
	do {
		int abcde = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[4];
		int fghij = arr[0 + 5] * 10000 + arr[1 + 5] * 1000 + arr[2 + 5] * 100 + arr[1 + 5] * 10 + arr[4 + 5];
		if (abcde % fghij == 0) {
			cout << abcde << " " << fghij << " " << abcde / fghij << endl;
		}
	} while (next_permutation(all(arr)));
	return;
}

void solve2() {
	cin >> n;
	for (int fghij = 1234; fghij <= 98765 / n; ++fghij)
	{
		int abcde = n * fghij;
		set<int> st;

		int temp = abcde;
		for (int i = 0; i < 5; ++i)
		{
			st.insert(temp % 10);
			temp /= 10;
		}

		temp = fghij;
		for (int i = 0; i < 5; ++i)
		{
			st.insert(temp % 10);
			temp /= 10;
		}

		if (st.size() == 10) {
			cout << abcde << " " << fghij << endl;
		}
	}
}

int main()
{
	blaze;
	int _t = 1;
	// cin >> _t;
	while (_t--) {
		solve1();
	}
	return 0;
}