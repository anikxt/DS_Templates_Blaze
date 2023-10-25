const int ALPHABET = 26;

struct trie {
    struct node {
        // represents the end of a complete word (string).
        bool ends;
        // stores count of strings that have this node as a prefix.
        int prefix = 0;
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
        }
        cur->prefix++;
        cur->ends = true;
    }

    bool find(const string &s) {
        node* cur = root;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            int x = where(s[i]);
            if (cur->child[x] == NULL) {
                return false;
            }
            cur = cur->child[x];
        }
        return cur->ends;
    }

    void erase(const string &s) { // Must be present
        node* cur = root;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            cur->prefix--;
            int x = where(s[i]);
            cur = cur->child[x];
        }
        cur->prefix--;
        if (cur->prefix == 0) {
            cur->ends = false;
        }
    }

    int prefix(const string &s) { // Number of strings which have s as prefix
        node *cur = root;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            int x = where(s[i]);
            if (cur->child[x] == NULL) {
                return 0;
            }
            cur = cur->child[x];
        }
        return cur->prefix;
    }

    // helper function for deleting nodes in the trie during destruction
    void delt(node* cur) {
        if (cur == NULL)
            return;

        for (int i = 0; i < 26; ++i)
        {
            delt(cur->child[i]);
        }
        delete cur;
    }

    // destructor
    ~trie() {
        delt(head);
    }
};