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