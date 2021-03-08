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

struct Node {
  int data;
  Node* next;
};

class HashTable {
 public:
  Node** HT;
  HashTable();
  int hash(int key);
  void Insert(int key);
  int Search(int key);
  ~HashTable();
};

HashTable::HashTable() {
  HT = new Node*[10];
  fo(i, 10) HT[i] = NULL;
}

int HashTable::hash(int key) { return key % 10; }

void HashTable::Insert(int key) {
  int hIdx = hash(key);
  Node* temp = new Node;
  temp->data = key;
  temp->next = nullptr;
  // Case: No nodes in the linked list
  if (HT[hIdx] == nullptr) {
    HT[hIdx] = temp;
  } else {
    Node* p = HT[hIdx];
    Node* q = HT[hIdx];
    // Traverse to find insert position
    while (p && p->data < key) {
      q = p;
      p = p->next;
    }
    // Case: insert position is first
    if (q == HT[hIdx]) {
      temp->next = HT[hIdx];
      HT[hIdx] = temp;
    } else {
      temp->next = q->next;
      q->next = temp;
    }
  }
}

int HashTable::Search(int key) {
  int hIdx = hash(key);
  Node* p = HT[hIdx];
  while (p) {
    if (p->data == key) {
      return p->data;
    }
    p = p->next;
  }
  return -1;
}

HashTable::~HashTable() {
  fo(i, 10) {
    Node* p = HT[i];
    while (HT[i]) {
      HT[i] = HT[i]->next;
      delete p;
      p = HT[i];
    }
  }
  delete[] HT;
}

int main() {
  int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
  int n = sizeof(A) / sizeof(A[0]);
  HashTable H;
  fo(i, 10) H.Insert(A[i]);
  co << "Successful Search" << endl;
  int key = 6;
  int value = H.Search(key);
  co << "Key: " << key << ", Value: " << value << endl;
  co << "Unsuccessful Search" << endl;
  key = 95;
  value = H.Search(key);
  co << "Key: " << key << ", Value: " << value << endl;

  return 0;
}