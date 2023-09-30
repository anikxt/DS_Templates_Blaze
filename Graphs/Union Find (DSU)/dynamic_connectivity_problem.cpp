#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pr(v) for(auto &z: v) cout << z << ' '; cout << '\n'
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;

const int MOD = 1e9 + 7;
//=======================
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
//=======================

// https://codeforces.com/gym/100551/problem/A
// traverse O(N) nodes * activate/deactivate O(logN) nodes * at a cost of O(logN)
// Overall: O(Nlog^2(N)) complexity

#define int long long
const int N = 3e5 + 9;

struct persisent_dsu {
    struct state {
        int u, v, rnku, rnkv;
        state() {
            u = -1;
            v = -1;
            rnku = -1;
            rnkv = -1;
        }

        state(int _u, int _rnku, int _v, int _rnkv) {
            u = _u;
            rnku = _rnku;
            v = _v;
            rnkv = _rnkv;
        }
    };

    int n, set_size;
    vector<int> par, sz;
    stack<state> st;
    persisent_dsu() {}

    void init(int a) {
        n = set_size = a;
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }

    // without path compression
    int find(int x) {
        if (x == par[x])
            return x;
        return find(par[x]);
    }

    // size compression
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            st.push(state());
            return;
        }

        if (sz[x] < sz[y])
            swap(x, y);

        sz[x] += sz[y];
        par[y] = x;
        set_size--;
        st.push(state(y, sz[y], x, sz[x]));
    }

    // how many last edges you want to erase
    void rollback(int c) {
        while (!st.empty() and c != 0) {
            if (st.top().u == -1) {
                st.pop();
                c--;
                continue;
            }

            auto x = st.top();
            st.pop();
            par[x.u] = x.u;
            par[x.v] = x.v;
            sz[x.u] = x.rnku;
            sz[x.v] = x.rnkv;
            c--;
            set_size++;
        }
    }
} dsu;

vector<pair<int, int>> alive[4 * N];
pair<int, int> p;
int query[N];
vector<pair<int, int>> ans;

void update(int id, int l, int r, int lq, int rq) {
    if (lq > r or l > rq)
        return;
    if (lq <= l and r <= rq) {
        /* add the edge at this node where it is minimally
        covered in the range */
        alive[id].push_back(p);
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, lq, rq);
    update(id << 1 | 1, mid + 1, r, lq, rq);
}

void dfs(int id, int l, int r) {
    /* when you enter this node how many edges were currently there
    in your current union find, so its like the position in stack */
    int prevsz = dsu.st.size();
    // go ahead and add all the edges that is activated over here
    for (auto v : alive[id]) {
        dsu.unite(v.first, v.second);
    }

    // if it is a leaf node then store the answer
    if (l == r) {
        if (query[l] != -1) {
            ans.push_back(make_pair(query[l], dsu.set_size));
        }
    }
    // else divide on both the sides and find the answers, standard dfs
    else {
        int mid = (l + r) >> 1;
        dfs(id << 1, l, mid);
        dfs(id << 1 | 1, mid + 1, r);
    }

    // rollback to the previous configuration
    dsu.rollback(dsu.st.size() - prevsz);
}

void solve()
{
    int n, k;
    cin >> n >> k;

    dsu.init(n);
    // mapping which edge got actived and deactivated
    map<pair<int, int>, int> mp;
    // empty queries initially
    memset(query, -1, sizeof(query));

    for (int i = 0; i < k; ++i)
    {
        char ch;
        cin >> ch;
        if (ch == '+') {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            // this edge got added at i
            mp[make_pair(a, b)] = i;
        } else if (ch == '-') {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            p = make_pair(a, b);
            // update this incoming edge in the segment tree [mp[eed], i]
            update(1, 0, k, mp[p], i);
            /* if the edge is already present
            then remove it off because now on this edge will not be present */
            if (mp.find(p) != mp.end())
                mp.erase(mp.find(p));
        } else {
            query[i] = i;
        }
    }

    for (auto v : mp) {
        p = v.first;
        /* update it from the range since it is present till the very end k,
        basically [i, k] */
        update(1, 0, k, v.second, k);
    }

    dfs(1, 0, k);
    // sort the answers based on offline query id
    sort(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it.second << endl;
    }
    return;
}
#undef int

int main()
{
    blaze;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}