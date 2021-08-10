#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
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
int c, k, m, n, t, y;
ll x = 1, maxi = 0;
//=======================

// https://quanticdev.com/algorithms/dynamic-programming/sliding-window/

/* Easy: Statically Sized Sliding Window: Given an array of integers,
find maximum/minimum sum subarray of a given size */

int Easy()
{
    int arr[] = {-1, 2, 3, 1, -3, 2};
    int subarraySize = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    int currentSum = 0, maxSum = 0, maxSumStartIndex = 0;

    for (int i = 0; i < n; ++i)
    {
        currentSum += arr[i];
        if (i < subarraySize)
        {
            maxSum = currentSum;
        }
        else
        {
            currentSum -= arr[i - subarraySize];
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxSumStartIndex = i - subarraySize + 1;
        }
    }
    return maxSum;
}
// Time complexity: O(n)
// Space complexity: O(1)

/* Medium: Dynamically Sized Sliding Window: Given an array of positive integers,
find the subarrays of integers that add up to a given number */

void MediumV1()
{
    int arr[] = {1, 7, 4, 3, 1, 2, 1, 5, 1};
    int desired = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0, sumStartIndex = 0, i;
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        while (sum > desired)
        {
            sum -= arr[sumStartIndex];
            sumStartIndex++;
        }

        if (sum == desired)
            break;
    }
    deb(sumStartIndex);
    deb(i);
    for (int j = sumStartIndex; j <= i; ++j)
    {
        cout << arr[j] << " ";
    }
    return;
}
// Time complexity: O(n)
// Space complexity: O(1)

/* Variation (Medium): Same question but for an array with all integers (positive, 0, negative).
The optimal solution is Kadane’s Algorithm,
but Sliding Window can still be applied with modifications (not recommended though) */

void MediumV2()
{
    int arr[] = {-1, -4, 0, 5, 3, 2, 1};
    int desiredSum = 5;
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0, sumStartIndex = 0, i;
    for (i = 0; i < n; ++i)
    {
        if (sum + arr[i] < sum)
        {
            sumStartIndex = i + 1;
        }
        else
        {
            sum += arr[i];
        }

        if (sum == desiredSum)
            break;
    }
    for (int j = sumStartIndex; j <= i; ++j)
    {
        cout << arr[j] << " ";
    }
    return;
}

/* Medium: Flipping/Swapping: Given an array of 0’s and 1’s, 
find the maximum sequence of continuous 1’s that can be formed by flipping at-most k 0’s to 1’s */

void MediumV3()
{
    int arr[] = {0, 1, 0, 1, 0, 0, 1, 1};
    int maxFlips = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    int subArrStart = 0, subArrEnd = 0, flippedZeros = 0, maxConsecutiveOne = 0;

    for (subArrEnd = 0; subArrEnd < n; ++subArrEnd)
    {
        if (arr[subArrEnd] == 0)
            flippedZeros++;

        if (flippedZeros > maxFlips)
        {
            if (arr[subArrStart] == 0)
                flippedZeros--;
            subArrStart++;
        }

        maxConsecutiveOne = max(maxConsecutiveOne, subArrEnd - subArrStart + 1);
    }

    deb(maxConsecutiveOne);
    return;
}
// Time complexity: O(n)
// Space complexity: O(1)

/* Hard: Strings: Given a string and n characters, 
find the shortest substring that contains all desired characters */

void Hard()
{
    string str = "asb2.9d/d!304#b$%^%!ksd,2294iubasdmc", desiredCharacters = "b$#2";
    unordered_map<char, int> map1, map2;

    int count = 0, x, y, flag = 0;
    int start = 0, end = 0, mini = INT_MAX;

    for (int i = 0; i < desiredCharacters.size(); ++i)
    {
        map1[desiredCharacters[i]]++;
    }

    for (end = 0; end < str.size(); ++end)
    {
        map2[str[end]]++;
        if (map2[str[end]] <= map1[str[end]])
        {
            count++;
        }
        if (count == desiredCharacters.size())
        {
            while (start <= end)
            {
                if (mini > end - start + 1)
                {
                    mini = end - start + 1;
                    x = start;
                    y = end;
                    deb2(x, y);
                }
                if (map2.find(str[start]) != map2.end())
                {
                    map2[str[start]]--;
                }
                if (map2[str[start]] < map1[str[start]])
                {
                    count--;
                    flag = 1;
                    break;
                }
                start++;
            }
        }
        if (flag == 1)
        {
            start++;
            flag = 0;
        }
    }
    for (int i = x; i <= y; ++i)
    {
        cout << str[i];
    }
    return;
}
// Time complexity: O(n)
// Space complexity: O(m) where “m” is the number of distinct chars in the “Desired Characters” list.

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    Hard();
    return 0;
}
