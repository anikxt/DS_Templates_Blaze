#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

bool f(int x, int y)
{
	return x > y;
}

void vectorDemo()
{
	vector<int> A = {1, 2, 3, 14};

	cout << A[1] << endl;

	sort(A.begin(), A.end()); // O(NlogN)

	//2, 3, 11, 14
	// O(logN)
	bool present = binary_search(A.begin(), A.end(), 3); //true
	present = binary_search(A.begin(), A.end(), 4);		 //false

	A.push_back(100);
	present = binary_search(A.begin(), A.end(), 100); //true

	//2, 3, 11, 14, 100
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	//2, 3, 11, 14, 100, 100, 100, 100, 100, 103
	A.push_back(123);

	auto it = lower_bound(A.begin(), A.end(), 100);	 // >=
	auto it2 = upper_bound(A.begin(), A.end(), 100); // >

	cout << *it << " " << *it2 << endl;
	cout << it2 - it << endl; //5

	sort(A.begin(), A.end(), f);

	for (int &x : A) //reference
	{
		x++;
	}
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << endl;
}

void setDemo()
{
	set<int> S;
	S.insert(1);
	S.insert(2);
	S.insert(-1);
	S.insert(-10);

	for (int x : S)
		cout << x << " ";

	cout << endl;

	//-10 -1 1 2
	auto it = S.find(-1);
	if (it == S.end())
	{
		cout << "not present\n";
	}
	else
	{
		cout << "present\n";
		cout << *it << endl;
	}

	auto it2 = S.upper_bound(-1);
	auto it3 = S.upper_bound(0);
	cout << *it2 << " " << *it3 << endl;

	auto it4 = S.upper_bound(2);
	if (it4 == S.end())
	{
		cout << "oops! sorry cant find something like that\n";
	}

	/* You can also erase an element from set in log(N) time.
	   S.erase(1) */
}

void mapDemo()
{
	map<int, int> A;
	A[1] = 100;
	A[2] = -1;
	A[3] = 200;
	A[1000232] = 1;

	map<char, int> cnt;
	string x = "Blaze";

	for (char c : x)
	{
		cnt[c]++;
	}

	cout << cnt['z'] << " " << cnt['z'] << endl;

	/* You can also find/delete a key in map or not in just log(N) time.
	   A.find(key) and A.erase(key) */
}

void PowerOfStl()
{
	// [x,y]
	/* add[2, 3]
	   add[10, 20]
	   add[2, 400]
	   add[2, 450]
	   give me the interval 401*/
	set<pair<int, int>> S;

	S.insert({401, 450});
	S.insert({10, 20});
	S.insert({2, 3});
	S.insert({30, 400});

	//2, 1
	//10, 20
	//30, 400
	//401, 450

	int point = 1;

	auto it = S.upper_bound({point, INT_MAX});
	if (it == S.begin())
	{
		cout << "the given point is not lying in any interval..\n";
		return;
	}

	it--;
	pair<int, int> current = *it;
	if (current.first <= point && point <= current.second)
	{
		cout << "yes its present: " << current.first << " " << current.second << endl;
	}
	else
	{
		cout << "the given point is not lying in any interval..\n";
	}

	/* Pair {a,b} is smaller than pair {c,d}
	    iff (a < b) or (a == b and c < d)


	   The values in pair X = {a, b} can be accessed using
	   			X.first and X.second */
}

void unorderedMapDemo()
{
	map<char, int> M;
	unordered_map<char, int> U;

	string s = "Blaze";
	//add(key, value) - logN, O(1)
	//erase(key) - logN, O(1)

	for (char c : s)
		M[c]++; //O(NlogN) N = |s|

	for (char c : s)
		U[c]++; // O(N)
}

void arrayDivisionCF()
{
	// Codeforces D. Array Division
	int n;
	cin >> n;
	vector<int> A(n + 5, 0);
	long long S = 0;
	for (int i = 0; i < n; i++)
		cin >> A[i], S += A[i];
	if (S & 1)
	{
		cout << "NO\n";
		return;
	}

	unordered_map<long long, int> first, second;

	first[A[0]] = 1;
	long long sdash = 0;

	for (int i = 0; i < n; i++)
	{
		sdash = A[i]; //first i numbers
		if (sdash == S / 2)
		{
			cout << "YES\n";
			return;
		}
		if (sdash < S / 2)
		{
			long long x = S / 2 - sdash;
			//delete element from second half, and insert into first half
			if (second[x] > 0)
			{
				cout << "YES\n";
				return;
			}
		}
		else
		{
			long long y = sdash - S / 2;
			if (first[y] > 0)
			{
				cout << "YES\n";
				return;
			}
		}
		//i+1
		first[A[i + 1]]++;
		second[A[i + 1]]--;
	}
	cout << "NO\n";
	return;
}

int main()
{
	//C++ STL
	PowerOfStl();
	arrayDivisionCF();

	return 0;
}