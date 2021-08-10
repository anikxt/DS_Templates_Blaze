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

// Nearest Smaller Elements

/* the problem of finding for each array element the
nearest smaller element, i.e., the first smaller element that precedes the
element in the array. It is possible that no such element exists, in which case
the algorithm should report this. */

int main()
{
  blaze;
  cin >> n;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  vector<int> v;
  stack<int> s;
  s.push(a[0]);
  int i = 1;
  while (i < n)
  {
    if (a[i] > s.top())
    {
      s.push(a[i]);
      i++;
    }
    else
    {
      s.pop();
    }
  }
  if (s.empty())
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }

  return 0;
}
