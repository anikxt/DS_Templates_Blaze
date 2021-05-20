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

// Two Pointers - 2 Sum

/* given an array of n numbers and a
target sum x , find two array values such that their sum is x , or report that
no such values exist. */

int main()
{
  blaze;
  cin >> n >> x;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  sort(a, a + n);
  int i = 0, j = n - 1, sum;
  while (i < j)
  {
    sum = a[i] + a[j];
    if (sum == x)
    {
      deb(a[i]);
      deb(a[j]);
      break;
    }
    else if (sum < x)
    {
      i++;
    }
    else
    {
      j--;
    }
  }
  return 0;
}
