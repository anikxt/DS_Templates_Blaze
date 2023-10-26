#include <bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*

N arr
Q: ? L R K -> # of elements in range [L, R] <= K

*/

int n, q;
int arr[100100];

int t[400400];

void build(int index, int l, int r) {
   t[index] = 0;
   int mid = (l + r) / 2;
   build(index << 1, l, mid);
   build(index << 1 | 1, mid + 1, r);
}

void update(int index, int l, int r, int pos, int val) {
   if (pos < l or pos > r)
      return;
   if (l == r) {
      t[index] = val;
      return;
   }

   int mid = (l + r) / 2;
   update(index << 1, l, mid, pos, val);
   update(index << 1 | 1, mid + 1, r, pos, val);
   t[index] += t[index << 1] + t[index << 1 | 1];
}

int query(int index, int l, int r, int lq, int rq) {

}

void solve()
{
   cin >> n >> q;
   vector<pair<int, int>> vals;
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
      vals.push_back({arr[i], i});
   }

   sort(vals.begin(), vals.end());
   vector<pair<pair<int, int>, pair<int, int>>> queries;
   for (int i = 0; i < q; ++i)
   {
      int l, r, k;
      cin >> l >> r >> k;
      queries.push_back({k, i}, {l, r});
   }

   sort(queries.begin(), queries.end());
   int ans[q];
   build(1, 0, n - 1);
   int pos = 0;
   for (auto v : queries) {
      while (pos < vals.size() and vals[pos].F <= v.F.F) {
         update(1, 0, n - 1, vals[pos].S, 1);
         pos++;
      }
      ans[v.F.S] = query(1, 0, n - 1, v.S.F, v.S.S);
   }
   for (int i = 0; i < q; ++i)
   {
      cout << ans[i] << endl;
   }

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