#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

vector<vector<int>> g;
vector<int> indeg;

vector<int> topo;
void kahn() {
    // for lexographical ordering, use priority queue.
    // priority_queue<int> q;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0) {
            // q.push(-i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        // int cur = -q.top();
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto v : g[cur]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                // q.push(-v);
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahn();
    if (topo.size() != n) {
        cout << "there is a cycle\n" << endl;
    } else {
        for (auto v : topo) {
            cout << v << endl;
        }
    }
    return;
}

int main()
{
    blaze;
    int _t = 1;
    // cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}