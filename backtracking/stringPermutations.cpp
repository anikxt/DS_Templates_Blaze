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

void stringPermutations(string s)
{
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

void permutationBacktrack(string s, int n, int i)
{
    if (i == n - 1)
    {
        cout << s << endl;
        return;
    }
    for (int j = i; j < n; ++j)
    {
        swap(s[i], s[j]);
        permutationBacktrack(s, n, i + 1);
        // Backtrack state to restore string to it's original state
        swap(s[i], s[j]);
    }
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    permutationBacktrack(s, s.size(), 0);
    return 0;
}