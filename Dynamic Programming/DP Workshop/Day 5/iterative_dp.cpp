#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// form 5 - game dp
/* 2 piles -> A, B stones in each pile
In one turn,
Take any number of stones from one pile
OR
Take equal number of stones from both4

Player -> who can't move loses
*/

int dp[1001][1001];

int rec(int x, int y)
{
    // pruning case

    // base case
    if (x == 0 and y == 0)
        return 0;

    // cache check
    if (dp[x][y] != -1)
        return dp[x][y];

    // compute
    int ans = 0;
    for (int z = 0; z < x; z++)
    {
        if (rec(z, y) == 0)
        {
            ans = 1;
            break;
        }
    }

    for (int z = 0; z < y; z++)
    {
        if (rec(x, z) == 0)
        {
            ans = 1;
            break;
        }
    }

    for (int z = 1; z <= min(x, y); z++)
    {
        if (rec(x - z, y - z) == 0)
        {
            ans = 1;
            break;
        }
    }

    // save and return
    return dp[x][y] = ans;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    // memset(dp, -1, sizeof(dp));
    // cout << rec(a, b) << endl;

    for (int x = 0; x <= a; x++)
    {
        for (int y = 0; y <= b; ++y)
        {
            if (x == 0 and y == 0)
                dp[x][y] = 0;

            // compute
            int ans = 0;
            for (int z = 0; z < x; z++)
            {
                if (dp[z][y] == 0)
                {
                    ans = 1;
                    break;
                }
            }

            for (int z = 0; z < y; z++)
            {
                if (dp[x][z] == 0)
                {
                    ans = 1;
                    break;
                }
            }

            for (int z = 1; z <= min(x, y); z++)
            {
                if (dp[x - z][y - z] == 0)
                {
                    ans = 1;
                    break;
                }
            }
            dp[x][y] = ans;
        }
    }

    cout << dp[a][b] << endl;
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
