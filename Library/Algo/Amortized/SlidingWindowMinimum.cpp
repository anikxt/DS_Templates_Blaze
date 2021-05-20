#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

// Sliding Window Minimum

/* The sliding window minimum can be calculated using a similar idea that
we used to calculate the nearest smaller elements. We maintain a queue where
each element is larger than the previous element, and the first element always
corresponds to the minimum element inside the window. After each window
move, we remove elements from the end of the queue until the last queue element
is smaller than the new window element, or the queue becomes empty. We also
remove the first queue element if it is not inside the window anymore. Finally,
we add the new window element to the end of the queue. */

int main()
{
  blaze;
  cin >> n >> k;
  int a[n];
  // for First K elements
  fab(0, n, i) { cin >> a[i]; }
  deque<int> q;
  vector<int> v;
  fab(0, k, i)
  {
    while (!q.empty() && a[i] <= a[q.back()])
    {
      // Remove the indices of elements that are smaller than the current
      // elements
      q.pop_back();
    }
    q.push_back(i);
  }
  // the element at the front has index of the highest element in the window
  v.push_back(q.front());
  // for rest elements
  fab(k, n, i)
  {
    // drop the elements that are out of window
    while (!q.empty() && q.front() <= i - k)
    {
      q.pop_front();
    }
    // remove those elements smaller than the current element from back
    while (!q.empty() && a[i] <= a[q.back()])
    {
      q.pop_back();
    }
    q.push_back(i);
    v.push_back(q.front());
  }
  fab(0, v.size(), i) { deb(v[i]); }
  return 0;
}

// 2 1 4 5 3 4 1 2
