#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Read the trick properly once.
Vertex i + j*n corresponds to the fact that i is of type j.
For two vertex with same group, unite u + j*n and v + j*n for all 3 j.
For eating unite similarly. Try to pose the problem as 2-SAT
*/

// one question, how do you deduce the number of groupings that you need to consider?
/*
Same(i,j) == ((i,A) implies (j,A)) and ((i,B) implies (j,B)) and ((i,C) implies (j,C))
Eats(i,j) == ((i,A) implies (j,B)) and ((i,B) implies (j,C)) and ((i,C) implies (j,A))
*/

struct dsu {
    int n;
    vector<int> parent;
    vector<int> siz;
    dsu(int sz) : n(sz) {
        parent.resize(n);
        siz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    inline bool cmp(int a, int b) { // Give indices here
        return siz[a] < siz[b];
    }

    inline int find(int x) { // Give index here
        assert(x >= 0 && x < n);
        while (x != parent[x]) x = parent[x] = parent[parent[x]];
        return x;
    }

    bool combine(int a, int b) { // Give indices here, (returns true if a and b are in different sets)
        assert(min(a, b) >= 0 && max(a, b) < n);
        if ((a = find(a)) != (b = find(b))) {
            if (cmp(a, b))swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
            return true;
        }
        return false;
    }

    inline bool same(int a, int b) { // Returns true if a and b are in same set
        assert(min(a, b) >= 0 && max(a, b) < n);
        return find(a) == find(b);
    }

    inline int size(int x) { // Returns the size of the set containing x
        assert(x >= 0 && x < n);
        return siz[find(x)];
    }
};

void testcase() {
    int n, k;
    cin >> n >> k;

    dsu tr(3 * n);

    auto same = [&](int i, int j) {
        tr.combine(i, j);
        tr.combine(i + n, j + n);
        tr.combine(i + 2 * n, j + 2 * n);
    };

    auto diff = [&](int i, int j) {
        tr.combine(i, j + n);
        tr.combine(i + n, j + 2 * n);
        tr.combine(i + 2 * n, j);
    };

    int ans = 0;
    while (k--) {
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;

        if (max(x, y) >= n) {
            ans++;
            continue;
        }

        if (t == 1 && !tr.same(x, y + n) && !tr.same(x, y + 2 * n)) {
            same(x, y);
        }
        else if (t == 2 && !tr.same(x, y) && !tr.same(x, y + 2 * n)) {
            diff(x, y);
        }
        else {
            ans++;
        }
    }

    cout << ans << '\n';
}


int main() {
    blaze;
    int _t;
    cin >> _t;
    while (_t--) {
        testcase();
    }
    return 0;
}