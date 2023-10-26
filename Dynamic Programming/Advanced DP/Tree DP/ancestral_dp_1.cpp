#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Problem Statement:
A tree with N nodes numbered from 1 to N, rooted at 1.
Given a positive integer M, the value of each node can be anything from 1 to M.
Count number of ways such that gcd of values of all nodes from root to leaf is equal to 1.

Constraints:
1 ≤ N ≤ 1e5
1 ≤ M ≤ 20
*/

/*
Time Complexity:
#State - O(N*M)
#Transitions - O(M)
Overall - O(N*(M^2))
*/

int n, m;
vector<int> g[100100];

// dp(node, path gcd from root) = Summ. (x = 1 to M) (Prod. of all childs (dp(ch, GCD(G,X))))
int dp[100100][20];

void dfs(int node, int gc, int parent) {
    /*
    can also write base case at the top,
    if(g[node].size() == 0 or (g[node].size() == 1 and parent != 0)){}
    */

    if (dp[node][gc] != -1)
        return dp[node][gc];

    int ans = 0;
    for (int col = 1; col <= m; ++col)
    {
        int temp = 1;
        int cntch = 0;
        for (auto v : g[node]) {
            if (v != parent) {
                cntch++;
                temp *= dfs(v, __gcd(gc, col), node);
            }
        }

        // this means its a leaf, base case basically.
        if (cntch == 0) {
            if (__gcd(gc, col) == 1) {
                ans++;
            } else {
                // dont do anything
            }
        } else {
            ans += temp;
        }
    }

    return dp[node][gc] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 0) << endl;
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
