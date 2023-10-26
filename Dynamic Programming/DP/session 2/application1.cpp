#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// substring automata

int n;
string t = "0100";
int dp[100100][5];

int rec(int level, int match)
{
    // pruning
    if (match == 4)
        return 0;

    // base case
    if (level == n)
        return 1;

    // cache check
    if (dp[level][match] -= 1)
        return dp[level][match];

    // compute
    int ans = 0;
    if (match == 0)
    {
        ans = rec(level + 1, 0) + rec(level + 1, 1);
    }
    else if (match == 1)
    {
        ans = rec(level + 1, 1) + rec(level + 1, 2);
    }
    else if (match == 2)
    {
        ans = rec(level + 1, 3) + rec(level + 1, 0);
    }
    else if (match == 3)
    {
        ans = rec(level + 1, 4) + rec(level + 1, 2);
    }

    // save and return
    return dp[level][match] = ans;
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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
