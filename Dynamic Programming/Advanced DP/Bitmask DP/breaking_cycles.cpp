#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Application Form 4 - Breaking Cycles

/*
Problem Statement:
Given a Directed Graph with N nodes,
Find the Minimum Number of Edges to Delete from the Graph,
so that it becomes a DAG.

Constraints:
N <= 20
*/

/*
Sample Input:
5
1 1 0 0 0
0 1 0 1 1
0 1 0 1 1
0 1 0 0 0
0 0 1 1 1

Sample Output:
2
*/

/*
Time Complexity:
#State = O(2^N)
#Transitions = O(N^2)
Overall = O((N^2)*(2^N))
*/

/*
Idea:
Breaking Cycle (Tough to handle cycles)
~ Create a Topological Ordering with Forward Edge (Just a Pemutation !!)
*/

#define int long long
const int N = 15;
int n;
int arr[N][N];
int dp[1 << N];

/*
we are at position level of the permutation and need to decide,
which vertex to put in this position of the permutation array.
*/

// returns min cost to create DAG from level...n-1
int rec(int level, int mask) {
    if (mask == ((1 << n) - 1))
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = 1e9;
    for (int i = 0; i < n; ++i)
    {
        // pick a new vertex for the permutation array
        if (mask & (1 << i))
            continue;

        // the number of back edges(we would have to delete all back edges to get a DAG)
        int temp = 0;
        for (int j = 0; j < n; ++j)
        {
            // pick a vertex which is already in the permutation array
            if ((mask & (1 << j))) {
                if (arr[i][j])
                    temp++;
            }
        }

        ans = min(ans, temp + rec(level + 1, mask | (1 << i)));
    }

    return dp[mask] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
    return;
}
#undef int

int main()
{
    blaze;
    int _t = 1;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}
