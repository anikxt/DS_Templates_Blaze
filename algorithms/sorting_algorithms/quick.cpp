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

int partition(int a[], int start, int end)
{
  int pivot = a[end], pIndex = start;
  fab(start, end, i)
  {
    if (a[i] <= pivot)
    {
      swap(a[i], a[pIndex]);
      pIndex++;
    }
  }
  swap(a[pIndex], a[end]);
  return pIndex;
}

int randomizedPartition(int a[], int start, int end)
{
  int pivotIndex = start + (rand() % (end - start + 1));
  swap(a[pivotIndex], a[end]);
  return partition(a, start, end);
}

void quickSort(int a[], int start, int end)
{
  if (start >= end)
    return;
  int pIndex = randomizedPartition(a, start, end);
  quickSort(a, 0, pIndex - 1);
  quickSort(a, pIndex + 1, end);
}

int main()
{
  blaze;
  int a[] = {2, 7, 4, 1, 5, 3};
  int n = sizeof(a) / sizeof(a[0]);
  quickSort(a, 0, n);
  fab(0, n, i)
  {
    cout << a[i] << " ";
  }
  return 0;
}

/* Analysis Of Quick Sort

1) Divide and Conquer
2) Recursive
3) Not Stable
4) Time complexity
    theta(nlogn) -> Best or Average case
    theta(n^2) -> Worst Case 
    
*/