#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/*
Implement a Spelling Correction Mechanism

Given a set of Strings. Answer Q queries of the form:
? S K: Find all strings in set that have atmost K position mismatch with S.
*/

const int ALPHABET = 26;
string s, gb;
int k;
int ans = 0;

struct trie {
	struct node {
		/* an array of pointers to other nodes,
		represents the next possible characters in the alphabet. */
		array<node*, ALPHABET> child;
		multiset<string> wend;
		node() {
			for (int i = 0; i < 26; ++i)
			{
				child[i] = NULL;
			}
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
			int x = where(s[i]);
			if (cur->child[x] == NULL) {
				cur->child[x] = new node();
			}
			cur = cur->child[x];
		}
	}

	void query(node *cur, int misMatch) {
		if (misMatch > k)
			return;

		ans++;

		for (int i = 0; i < 26; ++i)
		{
			if (cur->child[i] != NULL) {
				int isBad = 1 - (gb[i] - '0');
				query(cur->child[i], misMatch + isBad);
			}
		}
	}
};

void solve() {
	cin >> s >> gb >> k;
	trie t;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		string z = s.substr(i);
		t.insert(z);
	}

	ans = 0;
	t.query(t.root, 0);

	// dont count root as a valid substring
	cout << ans - 1 << endl;
}

int main() {
	blaze;
	solve();
	return 0;
}