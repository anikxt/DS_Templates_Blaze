#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n;

int queen[20]; // queen[i] -> where is my queen in row i.

bool check(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        int prow = i;
        int pcol = queen[i];

        if (pcol == col or abs(col - pcol) == abs(row - prow))
        {
            return false;
        }
    }
    return true;
}

int rec(int level) // return -> number of ways to populate [level..n-1] rows for a valid configuration
{
    // level -> row in which we are placing the queen

    // pruning

    // basecase
    if (level == n)
    {
        return 1;
    }

    // compute
    int ans = 0;
    // loop over all choices
    for (int col = 0; col < n; ++col)
    {
        // check if the choice is valid
        if (check(level, col))
        {
            // place the queen
            queen[level] = col;
            // explore the option
            ans += rec(level + 1);
            // revert placing the queen
            queen[level] = -1;
        }
    }

    // return
    return ans;
}

void solve()
{
    cin >> n;
    memset(queen, -1, sizeof(queen));
    cout << rec(0) << endl;
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
