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

unordered_set<string> r;

void go(string s, int len, string res)
{
    for (int i = 1; i <= len; ++i)
    {
        string pre = s.substr(0, i);
        if (r.find(pre) != r.end())
        {
            if (i == len)
            {
                res += pre;
                cout << res << endl;
            }
            go(s.substr(i, len - i), len - i, res + pre + " ");
        }
    }
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    r.insert("I");
    r.insert("love");
    r.insert("ham");
    r.insert("and");
    r.insert("beef");
    r.insert("andbeef");
    string s = "Ilovehamandbeef";
    go(s, s.size(), "");
    return 0;
}
