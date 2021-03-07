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

int RBinSearch(int arr[], int low, int high, int key)
{
  if (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (key == arr[mid])
      return mid;
    if (key < arr[mid])
      return RBinSearch(arr, low, mid - 1, key);
    else
      return RBinSearch(arr, mid + 1, high, key);
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a[] = {2, 4, 5, 6, 7};
  cin >> x;
  n = sizeof(a) / sizeof(a[0]);
  k = RBinSearch(a, 0, n - 1, x);
  deb(k);
  return 0;
}