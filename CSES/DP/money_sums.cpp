#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// bitset idea

void solve()
{
    int n;
    cin >> n;
    bitset<100100> temp;
    temp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        temp |= temp << x;
    }

    vector<int> ans;
    for (int i = 1; i <= 100000; ++i)
    {
        if (temp[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v << " ";
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
