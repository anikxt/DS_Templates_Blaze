// Idea - Simple binary search implementation

int solve()
{
  cin >> n;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  cin >> t;
  sort(a, a + n);
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] == t)
    {
      return mid;
    }
    else if (a[mid] < t)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}
