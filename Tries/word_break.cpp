#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
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