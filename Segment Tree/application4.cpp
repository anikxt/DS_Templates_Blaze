#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int n;
int h[100100], p[100100];
const int N = 1e5;

int t[400400];

int merge(int a, int b) {
   return a + b;
}

void build(int index, int l, int r) {
   if (l == r) {
      t[index] = 1;
      return;
   }

   int mid = (l + r) / 2;
   build(index * 2, l, mid);
   build(index * 2 + 1, mid + 1, r);
   t[index] = merge(t[index * 2], t[index * 2 + 1]);
}

void update(int index, int l, int r, int pos, int par) {
   if (pos < l or pos > r)
      return;

   if (l == r) {
      t[index] = par;
      return;
   }

   int mid = (l + r) / 2;

   update(index * 2, l, mid, pos, par);
   update(index * 2 + 1, mid + 1, r, pos, par);
   t[index] = merge(t[index * 2], t[index * 2 + 1]);
}

int query(int index, int l, int r, int k) {
   if (l == r) {
      return l;
   }

   int mid = (l + r) / 2;
   if (k <= t[2 * index])
      query(index * 2, l, mid, k);
   else query(index * 2 + 1, mid + 1, r, k - t[index * 2]);
}

void solve()
{
   cin >> n;
   const int N = 1e5;

   for (int i = 0; i < n; ++i)
      cin >> h[i];

   for (int i = 0; i < n; ++i)
      cin >> p[i];

   vector<pair<int, int>> pr(n);
   for (int i = 0; i < n; ++i)
   {
      pr[i] = make_pair(h[i], p[i]);
   }

   sort(pr.begin(), pr.end());
   build(1, 0, n - 1);

   vector<int> ans(n);

   for (int i = 0; i < n; ++i)
   {
      int idx = query(1, 0, n - 1, pr[i].second + 1);
      deb(idx);
      ans[idx] = pr[i].first;
      update(1, 0, n - 1, idx, 0);
   }

   for (int i = 0; i < n; ++i)
   {
      cout << ans[i] << " ";
   }
   return;
}

int main()
{
   blaze;
   int _t = 1;
   // cin >> _t;
   while (_t--) {
      solve();
   }
   return 0;
}