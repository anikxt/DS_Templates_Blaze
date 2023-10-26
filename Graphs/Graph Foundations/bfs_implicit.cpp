#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
6 6
1 2
2 3
1 4
3 4
4 5
4 6
*/

int n, m;
vector<vector<int>> g;

void bfs(int st) {
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = 1e9;
    }
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto v : g[cur]) {
            if (dist[cur] + 1 < dist[v]) {
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    int st, en;
    cin >> st >> en;
    bfs(st);
    cout << dist[en] << endl;
    return;
}

int main()
{
    blaze;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}