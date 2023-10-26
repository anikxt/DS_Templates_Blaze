#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*

N arr
Q <= 1e5

Query -
RQ 1 l r   -> find sum of element in [l, r]
RQ 2 l r   -> find max of element in [l, r]
RU 3 l r v -> Arr[i] = v for all i belongs to [l, r]

*/

struct node {
   int sum, maxr, lazy;
   node() {
      sum = 0;
      maxr = 0;
      lazy = 0;
   }
};

node merge(node a, node b) {
   node temp;
   temp.sum = a.sum + b.sum;
   temp.maxr = max(a.maxr, b.maxr);
   return temp;
}

#define MAXN 100100
node t[4 * MAXN];

void push(int index, int l, int r) {
   if (t[index].lazy) {
      t[index].sum = t[index].lazy * (r - l + 1);
      t[index].maxr = t[index].lazy;
      if (l != r) {
         t[index << 1].lazy = t[index].lazy;
         t[index << 1 | 1].lazy = t[index].lazy;
      }
      t[index].lazy = 0;
   }
}

void update(int index, int l, int r, int lq, int rq, int v) {
   push(index, l, r);
   if (l > rq or lq > r)
      return;
   if (lq <= l and r <= rq)
   {
      t[index].lazy = v;
      push(index, l, r);
      return;
   }

   int mid = (l + r) >> 1;
   update(index << 1, l, mid, lq, rq, v);
   update(index << 1 | 1, mid + 1, r, lq, rq, v);
   t[index] = merge(t[index << 1], t[index << 1 | 1]);
}

node query(int index, int l, int r, int lq, int rq) {
   push(index, l, r);
   if (l > rq or lq > r)
      return node();
   if (lq <= l and r <= rq) {
      return t[index];
   }

   int mid = (l + r) >> 1;
   return merge(query(index << 1, l, mid, lq, rq), query(index << 1 | 1, mid + 1, r, lq, rq));
}

// Every number given in the input is positive
void solve()
{
   update(1, 0, 9, 0, 5, 3);
   update(1, 0, 9, 6, 9, 4);
   node x = query(1, 0, 9, 3, 6);
   cout << x.sum << " " << x.maxr << endl;
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