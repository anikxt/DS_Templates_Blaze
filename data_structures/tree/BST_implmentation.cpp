#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define elif else if
#define co cout
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
vi g[N];
int a[N];
int c, k, m, n, t, x, y;
//=======================

struct BSTnode
{
	int data;
	int frequency;
	BSTnode *left;
	BSTnode *right;
};

BSTnode *getNewNode(int data)
{
	BSTnode *newNode = new BSTnode;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTnode *Insert(int data, BSTnode *root)
{
	if (root == NULL)
	{
		root = getNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(data, root->left);
	}
	else
	{
		root->right = Insert(data, root->right);
	}
	return root;
}

bool Search(int data, BSTnode *root)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(data, root->left);
	}
	else
	{
		return Search(data, root->right);
	}
}

int findMinIterative(BSTnode *root)
{
	if (root == NULL)
	{
		return -1;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int findMinRecursive(BSTnode *root)
{
	if (root == NULL)
	{
		return -1;
	}
	else if (root->left == NULL)
	{
		return root->data;
	}
	findMinRecursive(root->left);
}

int findMaxIterative(BSTnode *root)
{
	if (root == NULL)
	{
		return -1;
	}
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

int findMaxRecursive(BSTnode *root)
{
	if (root == NULL)
	{
		return -1;
	}
	else if (root->right == NULL)
	{
		return root->data;
	}
	findMinRecursive(root->right);
}

int Height(BSTnode *root)
{
	if (root = NULL)
		return -1;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void levelOrder(BSTnode *root)
{
	if (root == NULL)
		return;
	queue<BSTnode *> q;
	q.push(root);
	while (!q.empty())
	{
		BSTnode *current = q.front();
		q.pop();
		cout << current->data << " ";
		if (current->left)
			q.push(current->left);
		if (current->right)
			q.push(current->right);
	}
}

void Preorder(BSTnode *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data;
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(BSTnode *root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout << root->data;
	Inorder(root->right);
}

void InorderIterative(BSTnode *root)
{
	if (root == NULL)
		return;
	stack<BSTnode *> s;
	while (true)
	{
		if (root)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			if (s.empty())
				break;
			root = s.top();
			s.pop();
			cout << root->data << endl;
			root = root->right;
		}
	}
}

void Postorder(BSTnode *root)
{
	if (root == NULL)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data;
}

bool IsBstUtil(BSTnode *root, int minValue, int maxValue)
{
	if (root == NULL)
		return true;
	if (root->data > minValue and root->data < maxValue and
		IsBstUtil(root->left, minValue, root->data) and
		IsBstUtil(root->right, root->data, maxValue))
	{
		return true;
	}
	else
		return true;
}

bool IsBinarySearchTree(BSTnode *root)
{
	return IsBstUtil(root, INT_MIN, INT_MAX);
}

vector<int> v;
void InorderIsBST(BSTnode *root)
{
	if (root == NULL)
	{
		return;
	}
	InorderIsBST(root->left);
	v.push_back(root->data);
	InorderIsBST(root->right);
}

int main()
{
	blaze;
#ifndef ONLINE_JUDGE
	freopen("/media/blaze/Data/ATOM_CP/input.txt", "r", stdin);
	freopen("/media/blaze/Data/ATOM_CP/output.txt", "w", stdout);
#endif
	BSTnode *root = NULL;
	root = Insert(15, root);
	return 0;
}
