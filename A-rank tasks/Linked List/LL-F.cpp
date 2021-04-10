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
#define quick ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
int c, k, m, n, t, x, y;
//=======================

// Reverse a linked list using recursion

struct Node {
  int data;
  Node* next;
};

Node* head;

void Insert(int x, int n) {
  Node* temp = new Node;
  temp->data = x;
  if (n == 1) {
    temp->next = head;
    head = temp;
    return;
  } else {
    Node* temp1 = head;
    for (int i = 0; i < n - 2; ++i) {
      temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
  }
}

void Reverse(Node* p) {
  if (p->next == NULL) {
    head = p;
    return;
  } else {
    Reverse(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
  }
}

void Print(Node* head) {
  if (head == NULL) {
    return;
  } else {
    co << head->data << " ";
    Print(head->next);
  }
}

int main() {
  quick;
  head = NULL;
  Insert(2, 1);
  Insert(3, 2);
  Insert(4, 3);
  Insert(5, 4);
  Print(head);
  co << endl;
  Reverse(head);
  Print(head);
  co << endl;
  return 0;
}