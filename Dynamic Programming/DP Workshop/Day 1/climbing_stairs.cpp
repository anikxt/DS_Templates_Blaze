#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n;

int rec(int level) // return -> number of way to N if we are at stair level.
{
    // level -> stair i am at

    // pruning
    if (level > n)
    {
        return 0;
    }

    // base case
    if (level == n)
    {
        return 1;
    }

    int ans = 0;
    // loop over choice
    for (int step = 1; step <= 3; ++step)
    {
        // check -> is a valid choice
        if (level + step <= n)
        {
            // move
            int ways = rec(level + step);
            ans += ways;
        }
    }

    return ans; // for this level.
}

void solve()
{
    cin >> n;
    cout << rec(1) << endl;
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
