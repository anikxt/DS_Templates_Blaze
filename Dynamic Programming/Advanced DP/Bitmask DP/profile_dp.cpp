#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Application Form 5 - Profile DP

/*
Problem Statement:
Given a Rectangular Board of NxM board,
Find the number of ways of Tiling the Board with Dominos.

Constraints:
1 <= N, M <= 12
*/

/*
Time Complexity:
#State = O(N*M*(2^M))
#Transitions = O(1)
Overall = O(N*M*(2^M))
*/

#define int long long
const int N = 15;
int n, m;
int dp[N][N][1 << N];

void get_next_point(int i, int j, int *ansi, int *ansj) {
    if (j == m - 1) {
        *ansi = i + 1;
        *ansj = 0;
    } else {
        *ansi = i;
        *ansj = j + 1;
    }
}

int rec(int i, int j, int mask) {
    if (i == n) {
        return (mask == (1 << m) - 1);
    }

    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];

    int ans = 0;
    int nexti, nextj;
    get_next_point(i, j, &nexti, &nextj);

    // Leave
    if (i == 0 or (mask & 1)) {
        ans += rec(nexti, nextj, (mask >> 1));
    }

    // Config-2 (V)
    if (i > 0 and (!(mask & 1))) {
        int nMask = (mask >> 1);
        nMask |= (1 << (m - 1));
        ans += rec(nexti, nextj, nMask);
    }

    // Config-1 (H)
    if (j != 0 and !((mask >> (m - 1)) & 1)) {
        if (i == 0 or (i > 0 and (mask & 1))) {
            int nMask = (mask >> 1);
            nMask |= (1 << (m - 1));
            nMask |= (1 << (m - 2));
            ans += rec(nexti, nextj, nMask);
        }
    }

    return dp[i][j][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
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
