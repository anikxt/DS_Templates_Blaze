#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*

N <= 1e5
A[i] <= 1e9
D <= 1e9

N A:(3 5 7 1 2 1)

Find the longest subsequence A1, A2, A3,..., Ax

abs(A1 - A2) <= D

*/

#define int long long
int n, D, arr[100100];

map<int, int> compVal;

int t[400400];

#define mid ((l + r)>>1)
void update(int index, int l, int r, int pos, int val) {
   if (pos<l or pos > r)
      return;

   if (l == r) {
      t[index] = max(t[index], val);
      return;
   }

   update(index << 1, l, mid, pos, val);
   update(index << 1 | 1, mid + 1, r, pos, val);
   t[index] = max(t[index << 1], t[index << 1 | 1]);
}

int query(int index, int l, int r, int lq, int rq) {
   if (l > rq or lq > r )
      return 0;

   if (lq <= l and r <= rq) {
      // lq <= l <= r <= rq
      return t[index];
   }

   return max(query(index << 1, l, mid, lq, rq), query(index << 1 | 1, mid + 1, r, lq, rq));
}
#undef mid

void solve()
{
   cin >> n >> D;
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
      compVal[arr[i]];
   }

   int cnt = 0;
   for (auto &v : compVal) {
      v.second = cnt++;
   }

   int ans = 0;
   int dp[n];
   for (int i = 0; i < n; ++i)
   {
      int lo = arr[i] - D;
      int hi = arr[i] + D;

      auto it = compVal.upper_bound(hi);
      it--; hi = it->second;

      it = compVal.lower_bound(lo);
      lo = it->second;

      dp[i] = query(1, 0, cnt - 1, lo, hi) + 1;
      ans = max(ans, dp[i]);
      update(1, 0, cnt - 1, compVal[arr[i]], dp[i]);
   }

   cout << ans << endl;

   return;
}

signed main()
{
   blaze;
   int _t = 1;
   // cin >> _t;
   while (_t--) {
      solve();
   }
   return 0;
}