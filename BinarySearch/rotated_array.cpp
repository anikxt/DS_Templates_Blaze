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
#define quick ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
int c, k, m, n, t, x, y;
//=======================

// Rotated array (find the smallest element)

int solve() {
  cin >> n;
  int a[n];
  fo(i, n) { cin >> a[i]; }
  int low = 0, high = n - 1;
  while (low <= high) {
    if (a[low] <= a[high]) {
      return low;
    }
    int mid = low + (high - low) / 2;
    int prev = (mid + n - 1) % n;
    int next = (mid + 1) % n;
    if (a[mid] < a[prev] and a[mid] < a[next]) {
      return mid;
    } else if (a[mid] < a[high]) {
      high = mid - 1;
    } else if (a[low] < a[mid]) {
      low = mid + 1;
    }
  }
  return -1;
}

// Rotated array (find the target element)

int solveT() {
  cin >> n;
  int a[n];
  fo(i, n) { cin >> a[i]; }
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (t == a[mid]) {
      return mid;
    }
    if (a[mid] < a[high]) {
      if (a[mid] < t and t <= a[high])
        low = mid + 1;
      else
        high = mid - 1;
    } else {
      if (a[low] <= t and t < a[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
  }
  return -1;
}

int main() {
  quick;
  co << solve() << endl;
  return 0;
}
