// lower bound - Find first value >= x

int solve()
{
  cin >> n;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  cin >> t;
  sort(a, a + n);
  int low = 0, high = n - 1, res = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] >= t)
    {
      res = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return res;
}
