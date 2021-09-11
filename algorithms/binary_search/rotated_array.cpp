// Rotated array (How many times is a sorted array rotated?)

// if(duplicates)linear search; else binary search; 

int solve()
{
    int n;
    int a[n];
    int low = 0, high = n - 1;
    while (low <= high)
    {
        if (a[low] < a[high]) // Case 1
            return low;
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n, prev = (mid + n - 1) % n;
        if (a[mid] < a[prev] and a[mid] < a[next]) // Case 2
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

// Rotated array (Search element in a circular sorted array)

int solveT()
{
    int n;
    int a[n];
    int target;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < a[high])
        {
            if (target > a[mid] and target <= a[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else if (a[low] < a[mid])
        {
            if (target >= a[low] and target < a[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}
