#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// # of subarrays with # of distinct elements <= k - (Optimized)

// DS for two pointers condition checking
int distinct = 0;
int freq[1000100];

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // pointers
    int head = -1,
        tail = 0;
    ll ans = 0;
    while (tail < n)
    {
        // while there is a next element to take and we will not violate any condition
        // ((arr[head+1]==0) + cntzero <= k),
        while (head + 1 < n and ((freq[arr[head + 1]] == 0 and distinct < k) or (freq[arr[head + 1]] > 0 and distinct <= k)))
        {
            head++;
            if (freq[arr[head]] == 0)
                distinct++;
            freq[arr[head]]++;
        }
        // H = O(1)

        // Debug
        // cout << tail << " " << head << endl;
        // cout << distinct << endl;

        // update the answer accordingly.
        ans += head - tail + 1;
        // A = O(1)

        // move tail ahead and remove the last element's contribution
        if (head >= tail)
        {
            // T = O(1)
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0)
                distinct--;
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    // O(n)

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