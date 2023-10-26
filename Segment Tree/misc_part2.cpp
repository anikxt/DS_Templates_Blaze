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

/*

Merge-Sort Tree
Build(NlogN)
Query((logN)^2)
Memory Complexity(NlogN)

*/

int n, q;
int arr[100100];

vector<int> t[400400];

void build(int index, int l, int r) {
   if (l == r) {
      t[index].push_back(arr[l]);
      return;
   }
   int mid = (l + r) / 2;
   build(index << 1, l, mid);
   build(index << 1 | 1, mid + 1, r);
   merge(all(t[index << 1]), all(t[index << 1 | 1]), t[index].begin());
}

int query(int index, int l, int r, int lq, int rq, int k) {
   if (lq > r or l > rq)
      return 0;
   if (lq <= l and r <= rq) {
      return upper_bound(all(t[index]), k) - t[index].begin();
   }

   int mid = (l + r) / 2;
   return query(index << 1, l, mid, lq, rq, k) + query(index << 1 | 1, mid + 1, r, lq, rq, k);
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
   vector<pair<pii, pii>> queries;
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