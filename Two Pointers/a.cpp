#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;

const int MOD = 1e9 + 7;
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}