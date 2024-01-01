#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
P1352 A dance without a boss

Maximum weight independent set problem

There are N employees in a certain university, numbered 1~N.
Every employee invited to the banquet will increase
the happiness index Ri by a certain amount.
However, if a certain employee's boss comes to the dance,
then the employee will not come to the dance no matter what.
Calculate which staff to invite to maximize the happiness index,
and find the maximum happiness index.
*/

int n;
vector<int> h;
vector<vector<int>> g;
vector<int> isroot;

int dp[10000][2];
void indfs(int node) {
    dp[node][0] = 0;
    dp[node][1] = h[node];

    for (auto v : g[node]) {
        indfs(v);
        dp[node][0] += max(dp[v][0], dp[v][1]);
        dp[node][1] += dp[v][0];
    }
}

void solve() {
    cin >> n;

    h.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }

    g.resize(n + 1), isroot.resize(n + 1);
    for (int i = 1; i <= n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        isroot[a] = 1;
    }

    int root;
    for (int i = 1; i <= n; ++i)
    {
        if (!isroot[i]) {
            root = i;
            break;
        }
    }

    indfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    solve();
    return 0;
}