// Rotated array (find the smallest element)

int solve()
{
  cin >> n;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  int low = 0, high = n - 1;
  while (low <= high)
  {
    if (a[low] <= a[high])
    {
      return low;
    }
    int mid = low + (high - low) / 2;
    int prev = (mid + n - 1) % n;
    int next = (mid + 1) % n;
    if (a[mid] < a[prev] and a[mid] < a[next])
    {
      return mid;
    }
    else if (a[mid] < a[high])
    {
      high = mid - 1;
    }
    else if (a[low] < a[mid])
    {
      low = mid + 1;
    }
  }
  return -1;
}

// Rotated array (find the target element)

int solveT()
{
  cin >> n;
  int a[n];
  fab(0, n, i) { cin >> a[i]; }
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (t == a[mid])
    {
      return mid;
    }
    if (a[mid] < a[high])
    {
      if (a[mid] < t and t <= a[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
    else
    {
      if (a[low] <= t and t < a[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
  }
  return -1;
}
