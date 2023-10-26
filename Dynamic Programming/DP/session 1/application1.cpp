#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// palindrome partitioning

int n;
string s;

int dp1[1010][1010];
// 0-based indexing
int rec1(int l, int r) { // check palindrome
   if (l >= r)
      return 1;

   if (dp1[l][r] != -1)
      return dp[l][r];

   int ans = 0;
   if (s[l - 1] == s[r - 1] and rec1(l + 1, r - 1))
      ans = 1;

   return dp1[l][r] = ans;
}

int dp2[1010];
// 1-based indexing
int rec2(int i) { // min cuts for [1...i]
   if (i == 0) {
      return -1;
   }

   if (dp2[i] != -1) {
      return dp2[i];
   }

   int ans = 1e9;
   for (int j = 0; j < i; ++j)
   {
      if (rec1(j + 1, i)) {
         ans = min(ans, rec2(j) + 1);
      }
   }

   return dp2[i] = ans;
}

void solve()
{
   cin >> n;
   cin >> s;
   memset(dp1, -1, sizeof(dp1));
   memset(dp2, -1, sizeof(dp2));
   cout << rec2(n) << endl;
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
