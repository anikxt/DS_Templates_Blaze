#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Create a Data-Structure, that supports the following Queries efficiently:

+ X : Insert the number X in the Data-Structure
- X : Delete the number X that is already present in Data-Structure
? Y K : Find the Number of X in the Data-Structure that Satisfies (X^Y) <= K
*/

#define int long long
const int BIT = 2;

struct trie {
    struct node {
        int cnt;
        /* an array of pointers to other nodes,
        represents the next possible bits in the BIT. */
        array<node*, BIT> child;

        node() {
            cnt = 0;
            child[0] = child[1] = NULL;
        }
    };

    node* root = NULL;
    trie() {
        root = new node();
    }

    void insert(int n) {
        node* cur = root;
        for (int i = 31; i >= 0; --i)
        {
            cur->cnt++;

            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[x] == NULL) {
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }

    int query(int n, int k) {
        node* cur = root;
        int ans = 0;
        for (int i = 31; i >= 0 and cur != NULL; --i)
        {
            int b = (n & (1 << i)) ? 1 : 0;
            int c = (k & (1 << i)) ? 1 : 0;

            if (b == 1) {
                if (c == 1) {
                    if (cur->child[1] != NULL)
                        ans += cur->child[1]->cnt;
                    cur = cur->child[0];
                } else {
                    cur = cur->child[1];
                }
            } else {
                if (c == 1) {
                    if (cur->child[0] != NULL)
                        ans += cur->child[0]->cnt;
                    cur = cur->child[1];
                } else {
                    cur = cur->child[0];
                }
            }
        }

        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    trie t;
    t.insert(0);

    int p = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        p ^= x;
        ans += t.query(p, k);
        t.insert(p);
    }

    cout << ans << endl;
}
#undef int

int main() {
    blaze;
    int _t;
    cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}
