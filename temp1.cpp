#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

void solve() {
    int i;
    cin >> i;
    cout << i <<  endl;
    map<int, int> mp;
    mp[0] = 1;
    for (auto [key, value] : mp) {
        cout << key << " " << value << endl;
    }

    // while (true) {
    //     cout << 2 << endl;
    // }
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}