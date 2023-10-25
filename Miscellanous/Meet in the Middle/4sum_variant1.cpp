#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
4 Sum - Variant 1

Problem Statement:
From an array of N numbers Arr, and given a target TARGET, Does there
exists 4 values, a,b,c,d such that:
Arr[a] + Arr[b]+ Arr[c] + Arr[d] == TARGET

Constraints:
1 <= N <= 1000
0 <= a,b,c,d <= N-1

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

    map<int, int> pos;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            pos[arr[i] + arr[j]] = 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (pos[target - (arr[i] + arr[j])]) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
    return;
}

int main() {
    blaze;
    solve();
    return 0;
}