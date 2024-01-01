#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// https://codeforces.com/contest/1913/problem/D

#define int long long
const int N = 3e5 + 10, MOD = 998244353;
/*dp(i,0/1) indicates whether to select the i-th number,
last_min(i) indicates the subscript of the number from 1~i-1 that is closest to nums[i]
and is smaller than nums[i],
sum[i] represents the sum of the reachable array among the first i numbers
*/
int dp[N][2], last_min[N], sum[N];
int nums[N];
int n;

void solve()
{
    cin >> n;
    // Initialization
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        last_min[i] = 0;
        sum[i] = 0;
        dp[i][0] = dp[i][1] = 0;
    }

    // Monotone stack, used to process last_min
    stack<int> stk;
    for (int i = 1; i <= n; i++)
    {
        // If the top of the stack is greater than nums[i], pop everything
        while (stk.size() && nums[stk.top()] > nums[i])
            stk.pop();

        /*
        If there is a number smaller than nums[i] on the top of the stack,
        then it must be the number closest to nums[i]
        */
        if (stk.size())
            last_min[i] = stk.top();

        // Push onto the stack
        stk.push(i);
    }


    dp[0][0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // If there is a number smaller than nums[i]
        if (last_min[i])
        {
            /*
            If you want to select nums[i],
            then you should subtract the part containing last_min[i]
            (because if last_min[i] exists, nums[i] definitely does not exist,
            */
            /*
            Because last_min[i] must be smaller than nums[i],
            this will cause nums[i] to be deleted)
            */
            /*
            At the same time, if last_min[i] is not included,
            the number of last_min[i] that is not selected should also be added,
            that is, dp[last_min[i]][0]
            */
            dp[i][1] = (sum[i - 1] - sum[last_min[i] - 1] + dp[last_min[i]][0] + MOD) % MOD;
            /*
            If you do not select nums[i],
            it means that last_min[i] or a smaller part must be selected,
            so just add all the circumstances of last_min.
            */
            dp[i][0] = (dp[last_min[i]][1] + dp[last_min[i]][0]) % MOD;
        }
        else
        {
            /*
            If there is no number smaller than nums[i],
            it means that nums[i] can definitely be selected,
            and the equivalent number of options is sum[i-1]
            */
            dp[i][1] = sum[i - 1];
        }
        // Accumulate the total number of plans
        sum[i] = (sum[i - 1] + dp[i][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}
#undef int

int main()
{
    blaze;
    int _t; cin >> _t; while (_t--)
        solve();
    return 0;
}