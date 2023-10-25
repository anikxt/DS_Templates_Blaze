#include<bits/stdc++.h>
using namespace std;

struct node {
	bool is_end;
	node * child[26];
};

node * get_new_node() {
	node * temp = new node();
	temp->is_end = false;
	for (int i = 0; i < 26; i++) {
		temp->child[i] = NULL;
	}
	return temp;
}

struct trie {
	node * root;
	trie() {
		root = get_new_node();
	}
	node* make_move(node* temp, char ch) { // O(1)
		if (temp == NULL)return NULL;
		return temp->child[ch - 'a'];
	}
	void insert(string s) { // O(len(s))
		node * cur_node = root;
		for (int i = 0; i < s.length(); i++) {
			node * new_node = make_move(cur_node, s[i]);
			if (new_node == NULL) {
				new_node = get_new_node();
				cur_node->child[s[i] - 'a'] = new_node;
			}
			cur_node = new_node;
		}
		cur_node->is_end = true;
	}
};

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	trie tt;

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string temp;
		cin >> temp;
		reverse(temp.begin(), temp.end());
		tt.insert(temp);
	}

	int dp[n];

	for (int i = 0; i < n; i++) {
		node * temp = tt.root;
		dp[i] = 0;

		for (int j = i; j >= 0; j--) {
			temp = tt.make_move(temp, s[j]);
			if (temp == NULL) {
				break;
			}
			if (temp->is_end == true) {
				if (j == 0 || dp[j - 1] == 1) {
					dp[i] = 1;
					break;
				}
			}
		}
	}

	cout << dp[n - 1] << endl;
}