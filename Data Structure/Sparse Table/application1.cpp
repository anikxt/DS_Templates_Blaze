#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl
#define pr(v) for(auto &x: v) cout << x << ' '; cout << '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// https://codeforces.com/contest/1919/problem/D

// Bottom-Up Approach

/*
Rationale for Weak Forest on the Right Side:

Tree Structure:
In a valid forest, each subtree rooted at a node with value order
must have elements with value order + 1.

Root Nodes: The ind element (with value order) is a potential root node,
and its children should be on its right side.

Multiple Roots: A weak forest allows for multiple nodes
with the same value (order) to be roots.
This means the right side could potentially have multiple subtrees
with the same root value, hence the need for weak forest checking.

Left Side: The left side doesn't need weak forest checking
because elements to the left of ind cannot be part of subtrees rooted at ind.
They are either part of a previous subtree or roots themselves
*/

struct sparse {
    /*
    s[k][i] -> stores the index of the minimum value in the range a[i...i+2^k-1].
    */
    vector<vector<int>> s;
    vector<int> a;
    sparse(const vector<int>& a) : s(1, vector<int>(a.size())), a(a) {
        const int n = a.size();
        for (int i = 0; i < n; ++i)
            s[0][i] = i;
        int l = 1;
        int x = 0;
        while (l < a.size()) {
            s.push_back(s.back());
            for (int i = 0; i < n; ++i)
                if (i + l >= n)
                    s[x + 1][i] = s[x][i];
                else if (a[s[x][i]] <= a[s[x][i + l]])
                    s[x + 1][i] = s[x][i];
                else
                    s[x + 1][i] = s[x][i + l];
            ++x;
            l <<= 1;
        }
    }

    int find_min(int x, int y) const { // finds index, not the value
        int length = y - x;
        int l = 31 - __builtin_clz(length);
        int ind1 = s[l][x], ind2 = s[l][y - (1 << l)];
        if (a[ind1] <= a[ind2])
            return ind1;
        else
            return ind2;
    }
};

bool check_forest(const sparse& s, const int l, const int r, const int order);
bool check_weak_forest(const sparse& s, const int l, const int r, const int order) {
    if (r == l) return true;
    int ind = s.find_min(l, r);
    if (s.a[ind] == order)
        return check_forest(s, l, r, order);
    else
        return check_forest(s, l, r, order + 1);
}

bool check_forest(const sparse& s, const int l, const int r, const int order) {
    if (r == l) return true;
    int ind = s.find_min(l, r);
    if (s.a[ind] != order)
        return false;
    return check_forest(s, l, ind, order + 1) && check_weak_forest(s, ind + 1, r, order);
}

// [l, idx), [idx + 1, r)
bool check_tree(const sparse& s, const int l, const int r, const int order) {
    int ind = s.find_min(l, r);
    if (s.a[ind] != order)
        return false;
    return check_forest(s, l, ind, order + 1) && check_forest(s, ind + 1, r, order + 1);
}

bool find_ans(const vector<int>& a) {
    sparse s(a);
    return check_tree(s, 0, a.size(), 0);
}

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << (find_ans(a) ? "YES" : "NO") << '\n';
}

int main()
{
    blaze;
    int _t; cin >> _t; while (_t--)
        solve_test();
    return 0;
}