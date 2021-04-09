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

// Inserting a node at the beginning

struct Node {
  int data;
  Node* next;
};

Node* head;

void Insert(int x) {
  Node* temp = new Node;
  temp->data = x;
  if (head == NULL)
    temp->next = NULL;
  else
    temp->next = head;
  head = temp;
}

void Print() {
  Node* temp = head;
  while (temp != NULL) {
    co << temp->data << " ";
    temp = temp->next;
  }
}

int main() {
  quick;
  head = NULL;
  Insert(4);
  Insert(6);
  Print();
  return 0;
}