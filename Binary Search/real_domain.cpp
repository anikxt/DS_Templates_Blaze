#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// Binary Search on Real Domain
void solve1() {
    long long EPS = 1e9;
    long double lo = 0, hi = n;
    while (abs(hi - lo) >= EPS) {
        long double mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    long double ans = (lo + hi) / 2;
    return;
}

// Alternative (Better)
void solve2() {
    long double lo = 0, hi = n;
    for (int i = 0; i < 40; ++i) // choose as needed (2^10 ~ 1e3)
    {
        long double mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    long double ans = (lo + hi) / 2;
    return;
}

int main()
{
    blaze;
    // int _t; cin >> _t; while (_t--)
    return 0;
}