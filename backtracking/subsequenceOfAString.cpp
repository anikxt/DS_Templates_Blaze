#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define deb(x) cout << #x << "=" << x << endl
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

// Subsequence of a string in lexicographical order

set<string> s;
string temp = "";

void go(string str, int pos)
{
    s.insert(temp);
    for (int i = pos; i < str.size(); ++i)
    {
        temp += str[i];
        go(str, i + 1);
        temp.pop_back();
    }
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    string str;
    cin >> str;
    go(str, 0);
    for (auto i : s)
    {
        cout << i << endl;
    }
    return 0;
}