// Idea - Simple binary search implementation

int solve()
{
  int a[n]; // sorted
  int t; // target element
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
