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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================
vi g[N];
int a[N];
int c, n, m, k, x, y;
//=======================

// Insert a node at the nth position

struct Node
{
  int data;
  Node *next;
};

Node *Insert(int data, int n, Node *head)
{
  Node *temp1 = new Node;
  temp1->data = data;
  temp1->next = NULL;
  Node *temp2 = head;
  if (n == 1)
  {
    temp1->next = temp2;
    head = temp1;
    return head;
  }
  fo(i, n - 2)
  {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
  return head;
}

void Print(Node *head)
{
  while (head != NULL)
  {
    co << head->data << " ";
    head = head->next;
  }
}

int main()
{
  Node *head = NULL;
  head = Insert(2, 1, head);
  head = Insert(3, 2, head);
  head = Insert(4, 1, head);
  head = Insert(5, 2, head);
  Print(head);
  return 0;
}
