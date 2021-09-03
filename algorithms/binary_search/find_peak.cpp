// Find peak - The array increases and then decreases. Find the maximum.

int solve()
{
  cin >> n;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int prev = (mid + n - 1) % n;
    int next = (mid + 1) % n;
    if (mid == 0 or a[prev] < a[mid])
    {
      m = mid;
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return m;
}
