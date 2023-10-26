#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// find max skill gain you can get

int n;
int t[1001];
int s[1001];
int x, k;

int taken[1001];

int check(int level)
{
    int timetaken = 0;
    int itemtaken = 0;
    for (int i = 0; i < level; ++i)
    {
        if (taken[i])
        {
            timetaken += t[i];
            itemtaken += s[i];
        }
    }

    timetaken += t[level];
    itemtaken++;

    if (itemtaken <= x and itemtaken <= k)
    {
        return 1;
    }

    return 0;
}

int rec(int level) // max skill i can make from [level..n-1].. if [0..level-1 is decided].
{
    // level -> current item in [0...n-1]

    // pruning

    // basecase
    if (level == n)
    {
        return 0;
    }

    // compute
    // loop over choice
    // choice 1: don't take
    int ans = rec(level + 1);
    // choice 2: take
    if (check(level))
    {
        // place the change
        taken[level] = 1;
        // move
        ans = max(ans, s[level] + rec(level + 1)); // max in [level+1..n]
        // revert
        taken[level] = 0;
    }

    // return
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> s[i];
    }
    cin >> x >> k;
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
