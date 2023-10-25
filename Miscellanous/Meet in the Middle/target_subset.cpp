#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Target Subsets

From a Set of N Given Numbers,
Find the number of subsets having sum of elements <= X for a given X.

Time Complexity: O(N*(2^N/2))
*/

#define int long long
vector<int> generate(vector<int> arr) {
    int n = arr.size();
    vector<int> subVals;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (mask & (1 << j))
                sum += arr[j];
        }
        subVals.push_back(sum);
    }
    sort(subVals.begin(), subVals.end());
    return subVals;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int ans = 0;
    vector<int> newarr[2];

    for (int i = 0; i < arr.size(); ++i)
    {
        newarr[i & 1].push_back(arr[i]);
    }

    vector<int> sub0 = generate(newarr[0]);
    vector<int> sub1 = generate(newarr[1]);

    // iterate on one, binary search on other
    for (auto v : sub0) {
        ans += upper_bound(sub1.begin(), sub1.end(), x - v) - sub1.begin();
    }

    cout << ans << endl;
}
#undef int

int main() {
    blaze;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}