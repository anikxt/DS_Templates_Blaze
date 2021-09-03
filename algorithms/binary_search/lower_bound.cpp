// lower bound - Find first value >= x

int solve()
{
  int a[n]; // sorted
  int x; // target element
  int low = 0, high = n - 1, res = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] >= x)
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
