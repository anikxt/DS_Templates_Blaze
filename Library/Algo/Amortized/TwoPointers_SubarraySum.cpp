#include <bits/stdc++.h>
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

// Two Pointers - Subarray Sum

/* consider a problem where we are given an array of n positive
integers and a target sum x , and we want to find a subarray whose sum is x or
report that there is no such subarray. */

int main()
{
  blaze;
  cin >> n >> x;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  int i = 0, j = 0, sum = a[0];
  while (j < n)
  {
    if (sum > x)
    {
      sum -= a[i];
      i++;
      if (sum == x)
      {
        break;
      }
    }
    else if (sum < x)
    {
      j++;
      sum += a[j];
      if (sum == x)
      {
        break;
      }
    }
  }
  deb(i);
  deb(j);
  return 0;
}
