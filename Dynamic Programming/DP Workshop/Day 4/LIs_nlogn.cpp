#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
INPUT
10
1 5 7 10 9 6 7 9 2 3
*/

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    // printing index array
    int insertedat[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> lis;
    for (int i = 0; i < n; ++i)
    {
        if (lis.empty() or lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
            insertedat[i] = lis.size();
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            insertedat[i] = it - lis.begin() + 1;
        }
    }

    vector<int> final_lis;
    int curlen = lis.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (insertedat[i] == curlen)
        {
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }

    reverse(final_lis.begin(), final_lis.end());
    for (auto v : final_lis)
        cout << v << " ";
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
