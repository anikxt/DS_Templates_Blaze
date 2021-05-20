#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i < b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

struct Node
{
  int data;
  Node *next;
};

// Inserting a node at beginning

Node *Insert(int x, Node *head)
{
  Node *temp = new Node;
  temp->data = x;
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
  return head;
}

void Print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  blaze;
  Node *head = NULL;
  int n;
  cin >> n;
  int x;
  for (int i = 0; i < n; ++i)
  {
    cin >> x;
    head = Insert(x, head);
    Print(head);
  }
  return 0;
}
