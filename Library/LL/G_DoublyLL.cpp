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
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
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
    cout << temp->data << " ";
    temp = temp->prev;
  }
  cout << endl;
}

int main()
{
  blaze;
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
