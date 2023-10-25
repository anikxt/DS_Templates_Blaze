#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
4 Sum - Variant 1

Problem Statement:
From an array of N numbers Arr, and given a target TARGET,
Can you find 4 values, a,b,c,d such that:
Arr[a] + Arr[b]+ Arr[c] + Arr[d] == TARGET

Constraints:
1 <= N <= 1000
0 <= a < b < c < d <= N-1

Time Complexity: O(N^2*(logN))
*/

void solve() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    /*
    1. consider B, loop A, check [T - (A+B)]
    shift by 1
    2. (C = B), loop D, add (C+D)
    */

    map<int, pair<int, int>> pos;
    for (int b = n - 2; b >= 1; --b)
    {
        for (int a = b - 1; a >= 0; --a)
        {
            if (pos.find(target - (arr[a] + arr[b])) != pos.end()) {
                pair<int, int> ans = pos[target - (arr[a] + arr[b])];
                cout <<  a << " " << b << " " << ans.first << " " << ans.second;
                return;
            }
        }

        int c = b;
        for (int d = c + 1; d < n; ++d)
        {
            pos[arr[c] + arr[d]] = {c, d};
        }
    }

    cout << "can't find :/" << endl;
    return;
}

int main() {
    blaze;
    solve();
    return 0;
}