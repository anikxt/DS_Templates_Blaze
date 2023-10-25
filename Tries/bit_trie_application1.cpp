#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Finding Maximum XOR element in Trie

-> Given a set of elements S in Trie,
for any query x, find y in S such that x^y is MAX
*/

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

    void erase(int n) { // Must be present
        node* cur = root;
        for (int i = 31; i >= 0; --i)
        {
            cur->cnt--;
            int x = (n & (1 << i)) ? 1 : 0;
            cur = cur->child[x];
        }
        cur->cnt--;
    }

    int query(int n) {
        node* cur = root;
        int ans = 0;
        for (int i = 31; i >= 0; --i)
        {
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[1 ^ x] != NULL and cur->child[1 ^ x]->cnt > 0) {
                ans ^= (1 << i);
                cur = cur->child[1 ^ x];
            } else {
                cur = cur->child[x];
            }
        }
        return ans;
    }
};

int main() {
    blaze;
    trie t;
    t.insert(0);
    int q;
    cin >> q;
    while (q--) {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == '+') {
            t.insert(x);
        } else if (ch == '-') {
            t.erase(x);
        } else {
            cout << t.query(x) << endl;
        }
    }
    return 0;
}