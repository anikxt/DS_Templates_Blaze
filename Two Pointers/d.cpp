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

// 3 SUM

void solve()
{
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int cnt = 0;
    for (int j = 0; j < n; ++j)
    {
        int i = 0;
        int k = n - 1;
        while (i < j and j < k)
        {
            if (arr[i] + arr[j] + arr[k] == target)
            {
                int itemp = i;
                int ktemp = k;
                while (itemp < j and arr[itemp] == arr[i])
                {
                    itemp++;
                }
                while (ktemp > j and arr[ktemp] == arr[k])
                {
                    ktemp--;
                }
                cnt += (itemp - i) * (ktemp - k);
                i = itemp;
                k = ktemp;
            }
            else if (arr[i] + arr[j] + arr[k] < target)
            {
                i++;
            }
            else
            {
                k--;
            }
        }
    }
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