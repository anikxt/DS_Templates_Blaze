#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// https://www.codechef.com/problems/TACNTSTR

#define int long long
string P;
int len;
int dp[100100][2][2];

// t1 -> tight for same as P from start or not.
// t2 -> tight for same or smaller as P from end or not.
int rec(int level, int t1, int t2) {
    if (level == len) {
        // as lexicographically larger both tight bound has to be false.
        // t1 = 1 or t2 = 1 till the end means Q = P itself.
        if (t1 == 0 and t2 == 0)
            return 1;
        return 0;
    }

    if (dp[level][t1][t2] != -1)
        return dp[level][t1][t2];

    int ans = 0;
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        if (t1 == 1 and i < P[level])
            continue;

        // maintain tight for t1.
        int nt1;
        if (t1 == 0) {
            nt1 = 0;
        } else {
            if (i > P[level]) {
                nt1 = 0;
            } else {
                nt1 = 1;
            }
        }

        // maintain tight for t2, suffix match
        /* same comparison happens while going forward, i.e. if(i == P[level])
           whatever the previous value of t2, that's what we will use,
           i.e. t2 will be reserved.
        */
        int nt2;
        if (i == P[level]) {
            nt2 = t2;
        } else if (i < P[level]) {
            nt2 = 1;
        } else {
            nt2 = 0;
        }

        (ans += rec(level + 1, nt1, nt2)) %= MOD;
    }

    return dp[level][t1][t2] = ans;
}

void solve()
{
    cin >> P;
    len = P.size();

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1) << endl;
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
