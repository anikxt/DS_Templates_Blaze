#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<vector<pair<int, int>>> g;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    g.resize(n + mp.size() + 1);
    for (int i = 1; i < n; i++) {
        g[i].push_back({i + 1, a});
        g[i + 1].push_back({i, a});
    }
    int Dnode = n + 1;
    for (auto v : mp) {
        for (auto u : v.second) {
            g[Dnode].push_back({u, b});
            g[u].push_back({Dnode, 0});
        }
        Dnode++;
    }
}

signed main() {
    blaze;
    //int _t;cin>>_t;while(_t--)
    solve();
}