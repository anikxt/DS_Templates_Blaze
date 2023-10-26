#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Application Form 1 - Bipartite Matching

/*
Problem Statement:
There are N Ranks and M students in a class.
Each student has a happiness value for the rank in the class he gets.
The ith Student gets happy[i][j] on getting a rank j.
Its ok to not keep all students in the ranks (They get 0 happiness).
At most one student can be assigned to a rank.
The total happiness of the assignment can be calculated as
Sum of Happiness of each of the students in the class.
Find the best way to calculate maximum happiness attainable.

Constraints:
1 <= N <= 15.
1 <= M <= 50.
0<= happy[i][j] <= 10^5.
*/

/*
Strategy:
A. Iterate on one set. (students)
B. Keep track of elements taken already on the other set. (ranks, because ranks are smaller)
*/

/*
Time Complexity:
#state -> (M*2^N)
#transitions -> O(N)
Overall: O(N*M*2^N)
*/

#define MAXM 55
#define MAXN 15

#define int long long
int n, m;
int arr[MAXM][MAXN];
int dp[MAXM][(1 << MAXN)];

/*
rec(level, mask) -> Maximum happiness that can be collected
after level students processed and mask ranks blocked.
*/

// level ~ 50,  mask ~ 2^n
int rec(int level, int mask) {
    if (level == m)
        return 0;

    if (dp[level][mask] != -1)
        return dp[level][mask];

    // don't match this student
    int ans = rec(level + 1, mask);
    for (int i = 0; i < n; ++i)
    {
        // if rank not already alloted
        if ((mask & (1 << i)) == 0) {
            ans = max(ans, rec(level + 1, mask | (1 << i)) + arr[level][i]);
        }
    }

    return dp[level][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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