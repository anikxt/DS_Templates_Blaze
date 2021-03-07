<<<<<<< HEAD
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

// Doubly linked list

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

Node *head;

Node *GetNewNode(int x)
{
  Node *newNode = new Node;
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void InsertAtHead(int x)
{
  Node *newNode = GetNewNode(x);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void Print()
{
  Node *temp = head;
  while (temp != NULL)
  {
    co << temp->data << " ";
    temp = temp->next;
  }
  co << endl;
}

void ReversePrint()
{
  Node *temp = head;
  if (temp == NULL)
    return; // empty list, exit
  // Going to last Node
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  // Traversing backward using prev pointer
  while (temp != NULL)
  {
    co << temp->data << " ";
    temp = temp->prev;
  }
  co << endl;
}

int main()
{
  head = NULL; // empty list
  InsertAtHead(2);
  Print();
  ReversePrint();

  InsertAtHead(4);
  Print();
  ReversePrint();

  InsertAtHead(6);
  Print();
  ReversePrint();
  return 0;
}
||||||| 7b60224
=======
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

// Doubly linked list

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

Node *head;

Node *GetNewNode(int x)
{
  Node *newNode = new Node;
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void InsertAtHead(int x)
{
  Node *newNode = GetNewNode(x);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void Print()
{
  Node *temp = head;
  while (temp != NULL)
  {
    co << temp->data << " ";
    temp = temp->next;
  }
  co << endl;
}

void ReversePrint()
{
  Node *temp = head;
  if (temp == NULL)
    return; // empty list, exit
  // Going to last Node
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  // Traversing backward using prev pointer
  while (temp != NULL)
  {
    co << temp->data << " ";
    temp = temp->prev;
  }
  co << endl;
}

int main()
{
  head = NULL; // empty list
  InsertAtHead(2);
  Print();
  ReversePrint();

  InsertAtHead(4);
  Print();
  ReversePrint();

  InsertAtHead(6);
  Print();
  ReversePrint();
  return 0;
}
>>>>>>> 9d06a3584f45c4fbbf55aae17280b2ff569d2590
