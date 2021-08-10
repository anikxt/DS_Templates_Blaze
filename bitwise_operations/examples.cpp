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

// 1) How to check if a given number is a power of 2 ?
bool isPower(int n)
{
    if (n == 0)
        return false;
    while (n % 2 == 0)
        n /= 2;
    return (n == 1);
}
// Time complexity of the above code is O(logN).

bool isPowerOfTwoBitwise(int n)
{
    return (n and !(n & (n - 1)));
}
// binary representation of (n-1) can be obtained by simply flipping all the bits to the right of rightmost 1 in x and also including the rightmost 1.

/* Properties for numbers which are powers of 2, is that they have one and only one bit set in their binary representation.
If the number is neither zero nor a power of two, it will have 1 in more than one place.
So if n is a power of 2 then n & (n-1) will be 0. */

// 2) Count the number of ones in the binary representation of the given number.
int countOne(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
// Complexity: O(K), where K is the number of ones present in the binary form of the given number.

/*Why this algorithm works ?
As explained in the previous algorithm, the relationship between the bits of n and n-1. So as in n-1, the rightmost 1 and bits right to it are flipped, then by performing n&(n-1), and storing it in x, will reduce x to a number containing number of ones(in its binary form) less than the previous state of x, 
thus increasing the value of count in each iteration. */

// 3) Check if the ith bit is set in the binary form of the given number.
bool checkSet(int n, int i)
{
    if (n & (1 << i))
        return true;
    return false;
}
/* The binary form of 2i contains only ith bit as set (or 1), else every bit is 0 there. 
When we will AND it with N, and if the ith bit of N is set, then it will return a non zero number (2i to be specific), else 0 will be returned. */

// 4) How to generate all the possible subsets of a set ?
void possibleSubsets(char A[], int N)
{
    for (int i = 0; i < (1 << N); ++i)
    {
        for (int j = 0; j < N; ++j)
            if (i & (1 << j))
                cout << A[j] << " ";
        cout << endl;
    }
}

// 5) Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.
long largest_power(long N)
{
    //changing all right side bits to 1.
    N = N | (N >> 1);
    N = N | (N >> 2);
    N = N | (N >> 4);
    N = N | (N >> 8);

    // as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by 2.
    return (N + 1) >> 1;
}
// Idea: Change all the bits which are at the right side of the most significant digit, to 1.

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    // cout << isPower(n);
    // cout << isPowerOfTwoBitwise(n);
    // cout << countOne(n);
    cout << checkSet(n, 1);
    return 0;
}
