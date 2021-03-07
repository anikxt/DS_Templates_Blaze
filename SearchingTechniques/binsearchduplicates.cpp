#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define elif else if
#define co cout
#define endl '\n'
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================
vi g[N];
int a[N];
int c, n, m, k, x, y;
//=======================

int BinarySearch(int a[], int n, int x, bool searchFirst)
{
  int low = 0, high = n - 1, result = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] == x)
    {
      result = mid;
      if (searchFirst)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else if (x < a[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return result;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a[] = {2, 4, 5, 5, 5};
  cin >> x;
  int low = BinarySearch(a, sizeof(a) / sizeof(a[0]), x, true);
  int high = BinarySearch(a, sizeof(a) / sizeof(a[0]), x, false);
  k = high - low + 1;
  deb(low);
  deb(high);
  deb(k);
  return 0;
}
