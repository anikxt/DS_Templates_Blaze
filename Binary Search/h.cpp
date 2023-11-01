#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Binary Search on Each Start

/*
This is a typical Binary Search on Each Start Problem

Problem Statement:
Find the # of subarray that you can make all 1's by <= k flips

Constraints:
1 <= N <= 1e5
0 <= K <= N
0 <= Ai <= 1

Idea:
# of 0's (st, end) <= k
*/

int n, k;
int arr[100100];
int p[100100];

int numZero(int l, int r) {
    int ans = (r - l + 1) - (p[r] - (l > 0 ? p[l - 1] : 0));
    return ans;
}

bool check(int st, int x) {
    return numZero(st, x) <= k;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        p[i] = arr[i];
        if (i)p[i] += p[i - 1];
    }

    long long total = 0;
    for (int st = 0; st < n; ++st)
    {
        int lo = st;
        int hi = n - 1;
        int ans = st - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(st, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // (end - start + 1)
        total += (ans - (st - 1));
    }

    cout << total << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}