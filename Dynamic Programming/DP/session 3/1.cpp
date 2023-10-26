#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// coin combination

int n;
int arr[1005];

int dp[1005][1005];
int rec(int level, int taken) {
   if (taken > n or level > n) {
      return 0;
   }

   if (level == n) {
      if (taken == n) {
         return 1;
      }
   }

   if (dp[level][taken] != -1)
      return dp[level][taken];

   return dp[level][taken] = rec(level, taken + arr[level]) + rec(level + 1, taken);

}

void solve()
{
   cin >> n;
   for (int i = 1; i <= n; ++i)
   {
      arr[i] = i;
   }

   memset(dp, -1, sizeof(dp));
   cout << rec(1, 0) << endl;
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
