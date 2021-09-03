// sqrt(x) - Is x a perfect square?

int solve()
{
  cin >> n;
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (mid * mid == n)
    {
      return mid;
    }
    else if (mid * mid < n)
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
