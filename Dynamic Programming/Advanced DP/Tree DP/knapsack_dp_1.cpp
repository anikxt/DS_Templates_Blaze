#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Problem Statement:
Maximize the sum of value taken such that no 2 adjacent node should be selected
*/

int n;
int arr[100100];
vector<int> g[100100];

// dp(node, parent taken/not) -> best you can do
int dp[100100][2];
void indfs(int node, int parent) {
    // 0 means I am forcefully taking this particular node right now
    dp[node][0] = arr[node];
    dp[node][1] = 0;

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            dp[node][1] += dp[v][0];
            dp[node][0] += dp[v][1];
        }
    }
    /*
    think about it when there is no child,
    the above auto for loop code will not execute at all,
    and it would be just max of the parent taken or not taken.
    */
    dp[node][0] = max(dp[node][0], dp[node][1]);
}

// dp2(node, take this/not this) -> best you can do
int dp2[100100][2];
void indfs2(int node, int parent) {
    // if(1) then take, if(0) then dont take
    dp2[node][1] = arr[node];
    dp2[node][0] = 0;

    for (auto v : g[node]) {
        if (v != parent) {
            indfs(v, node);
            dp2[node][1] += dp2[v][0];
            dp2[node][0] += max(dp2[v][0], dp2[v][1]);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // its upto you how you want to keep the meaning of the dp
    indfs(1, 0);
    indfs2(1, 0);
    cout << dp[1][0] << endl;
    cout << max(dp2[1][0], dp2[1][1]) << endl;
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
