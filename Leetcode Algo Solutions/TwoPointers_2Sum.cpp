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
int c, k, m, n, t, x, y;
//=======================

// Two Pointers - 2 Sum

/* given an array of n numbers and a
target sum x , find two array values such that their sum is x , or report that
no such values exist. */

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  int a[n];
  fo(i, n) { cin >> a[i]; }
  sort(a, a + n);
  int i = 0, j = n - 1, sum;
  while (i < j) {
    sum = a[i] + a[j];
    if (sum == x) {
      deb(a[i]);
      deb(a[j]);
      break;
    } else if (sum < x) {
      i++;
    } else {
      j--;
    }
  }
  return 0;
}