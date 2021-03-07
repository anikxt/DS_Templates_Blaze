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

// Quick Sort (selecting an element finding a position)

// Partition function

int Partition(int a[], int low, int high)
{
  int pivot = a[low];
  int i = low, j = high;
  do
  {
    do
    {
      i++;
    } while (a[i] <= pivot);
    do
    {
      j--;
    } while (a[j] > pivot);
    if (i < j)
    {
      swap(a[i], a[j]);
    }
  } while (i < j);

  swap(a[low], a[j]); // swapping the pivot
  return j;
}

// Quick Sort

void QuickSort(int a[], int low, int high)
{
  int j;
  if (low < high)
  {
    j = Partition(a, low, high);
    QuickSort(a, low, j);      // Recursive Quick Sort on the lhs of Partitioning Position
    QuickSort(a, j + 1, high); // Recursive Quick Sort on the rhs of Partitioning Position
  }
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int a[n];
  fo(i, n)
  {
    cin >> a[i];
  }

  QuickSort(a, 0, n); // 0 1 ... n-1 int32_max
  fo(i, n)
  {
    co << a[i] << " ";
  }
  return 0;
}
