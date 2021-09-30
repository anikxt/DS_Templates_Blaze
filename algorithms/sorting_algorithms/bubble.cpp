#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n)
{
    for(int i = 0, i < n - 1, ++i)
    {
        int flag = 0;
        for(int j = 0, j < n - i - 1, ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    
    for(int i = 0, i < n, ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[6] = {2, 7, 4, 1, 5, 3};
    int n = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, n);
    return 0;
}

// Best Case - O(n)
// Average Case - O(n^2)
// Worst Case - O(n^2)
