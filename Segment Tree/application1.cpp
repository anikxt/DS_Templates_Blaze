#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Design a DS

N Arr

Query:
1 x v -> Update pos x with v
2 l r -> min of range [l, r] and count of min
*/

int n;
int arr[100100];

struct node {
   int mini;
   int cnt;
   node(int m = 1e9, int c = 0) {
      mini = m;
      cnt = c;
   }
};

node merge(node a, node b) {
   if (a.mini == b.mini) {
      return node(a.mini, a.cnt + b.cnt);
   } else if (a.mini < b.mini) {
      return a;
   } else return b;
}

node t[400400];

void build(int index, int l, int r) {
   if (l == r) {
      t[index] = node(arr[l], 1);
      return;
   }

   int mid = (l + r) / 2;
   build(index * 2, l, mid);
   build(index * 2 + 1, mid + 1, r);
   t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val) {
   if (pos < l or pos > r)
      return;
   if (l == r) {
      t[index] = node(val, 1);
      arr[l] = val;
      return;
   }

   int mid = (l + r) / 2;
   update(index * 2, l, mid, pos, val);
   update(index * 2 + 1, mid + 1, r, pos, val);
   t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node query(int index, int l, int r, int lq, int rq) {
   if (l > rq or lq > r)
      return 0;
   if (lq <= l and r <= rq) {
      // lq <= l <= r <= rq
      return t[index];
   }

   int mid = (l + r) / 2;
   return merge(query(index * 2, l, mid, lq, rq), query(index * 2 + 1, mid + 1, r, lq, rq));
}

void solve()
{
   cin >> n;
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }
   build(1, 0, n - 1);
   int q;
   cin >> q;
   for (int i = 0; i < n; ++i)
   {
      int ch;
      cin >> ch;
      if (ch == 1) {
         int x, v;
         cin >> x >> v;
         update(1, 0, n - 1, x, v);
      } else {
         int l, r;
         cin >> l >> r;
         node x = query(1, 0, n - 1, l, r);
         cout << x.mini << endl;
         cout << x.cnt << endl;
      }
   }
   return;
}

signed main()
{
   blaze;
   int _t = 1;
   cin >> _t;
   while (_t--) {
      solve();
   }
   return 0;
}