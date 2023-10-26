#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Application Form 2 - Hamiltonian Walk - Count Hamiltonian Walks

/*
Problem Statement:
A City is modelled using a Graph with N nodes and M edges.
The nodes are numbered from 1 to N.
There is a Person Standing at node i, and wants to visit a friend at City j.
He wants to visit every City exactly once.
Find the number of paths that exists of this form.

Constraints:
N <= 20
*/

/*
Time Complexity:
Overall: O((N+M)*2^N) ~ (N^2*2^N) in general, because number of edges can be of N^2.
*/

#define int long long
int n, m;
vector<vector<int>> g;
int dp[25][(1 << 20)];

int rec(int level, int mask) {
    // all one
    /*
    whenever n-th bit gets set, you just stop.
    this means, you never consider masks with the n-th bit set.
    */
    if (mask == ((1 << n) - 1))
        return 1;

    if (dp[level][mask] != -1)
        return dp[level][mask];

    int ans = 0;
    for (auto v : g[level]) {
        /*
        shifting v to v-1 position in bit so that it would remain between 0 to n-1.
        this is just an implementation level detail.
        */
        if (mask & (1 << (v - 1)))
            continue;

        (ans += rec(v, mask | (1 << (v - 1)))) %= MOD;
    }

    return dp[level][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(dp, -1, sizeof(dp));
        sum += rec(i, (1 << (i - 1)));
    }

    cout << sum << endl;
    return;
}
#undef int

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
