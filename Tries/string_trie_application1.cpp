#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Implementing Search Recomendations

From a set of Strings, Answer Q queries, which are:
? 'S' K -> Find the Lexicographically smallest Top K results
           for prefix match of 'S'.
           If there is no word with a common prefix print a blank line.
*/

const int ALPHABET = 26;

struct trie {
    struct node {
        // represents the end of a complete word (string).
        bool ends;
        // stores count of strings that have this node as a prefix.
        int prefix = 0;
        // store complete words (or "word endings")
        multiset<string> wend;
        /* an array of pointers to other nodes,
        represents the next possible characters in the alphabet. */
        array<node*, ALPHABET> child;

        node() {
            ends = false;
            for (int i = 0; i < 26; ++i)
            {
                child[i] = NULL;
            }
            prefix = 0;
        }
    };

    inline int where(char c) {
        return c - 'a';
    }

    node* root = NULL;
    trie() {
        root = new node();
    }

    void insert(const string &s) {
        node* cur = root;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            cur->prefix++;

            int x = where(s[i]);
            if (cur->child[x] == NULL) {
                cur->child[x] = new node();
            }
            cur = cur->child[x];
            cur->wend.insert(s);
        }
        cur->prefix++;
        cur->ends = true;
    }

    void query(const string &s, int k) {
        node* cur = root;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            int x = where(s[i]);
            if (cur->child[x] == NULL) {
                while (i < (int)s.size()) {
                    cout << endl;
                    i++;
                }
                continue;
            }

            cur = cur->child[x];
            if (cur->prefix > 0) {
                auto it = cur->wend.begin();
                for (int j = 0; j < k; ++j)
                {
                    if (it != cur->wend.end()) {
                        cout << (*it) << " ";
                        it++;
                    } else {
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
};

int main() {
    blaze;
    int n, maxlen, q;
    cin >> n >> maxlen >> q;
    trie t;
    for (int i = 0; i < n; ++i)
    {
        int len;
        string s;
        cin >> len >> s;
        t.insert(s);
    }

    while (q--) {
        int len, k;
        string s;
        cin >> len >> s >> k;
        t.query(s, k);
    }
    return 0;
}