#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
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
    int _t = 1;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}