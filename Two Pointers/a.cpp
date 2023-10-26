#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Find longest subarray with <= K 0s

/*
General rule to write two pointers:

step 1: move head as far as possible
step 2: process current window
step 3: tail++, update accordingly

Two Types of Two Pointers problem:
1. cnt # of subarray
2. maxlen/minlen subarray
*/

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // DS for two pointers condition checking
    int cntzero = 0;
    // pointers
    int head = -1, tail = 0;
    int ans = 0;
    while (tail < n)
    {
        // while there is a next element to take and we will not violate any condition
        // ((arr[head+1]==0) + cntzero <= k),
        while (head + 1 < n and ((arr[head + 1] == 1 and cntzero <= k) or (arr[head + 1] == 0 and cntzero < k)))
        {
            head++;
            if (arr[head] == 0)
                cntzero++;
        }
        // H = O(1)

        // Debug
        // cout << tail << " " << head << endl;

        // update the answer accordingly.
        // both are inclusive that's why add +1
        ans = max(ans, head - tail + 1);
        // A = O(1)

        // move tail ahead and remove the last element's contribution
        if (head >= tail)
        {
            // T = O(1)
            if (arr[tail] == 0)
                cntzero--;
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    // O(N)

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