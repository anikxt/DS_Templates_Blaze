# STL Containers

<pre>
- A container is a holder object that stores a collection of other objects (its elements). 
- They are implemented as class templates, which allows a great flexibility in the types supported as elements.

- The container manages the storage space for its elements and provides member functions to access them, either directly or through                        
  iterators (reference objects with similar properties to pointers).

- stack, queue and priority_queue are implemented as container adaptors. Container adaptors are not full container classes, but 
  classes that provide a specific interface relying on an object of one of the container classes (such as deque or list) to handle 
  the elements. 
- The underlying container is encapsulated in such a way that its elements are accessed by the members of the container adaptor 
  independently of the underlying container class used.

- Associative containers refer to the group of class templates used to implement associative arrays. 
- They are used to store elements but have some constraints placed on their elements.
- Most complexities are in logarithmic terms O(logN).
- Two important characteristics of these containers are:
    1.There exists a key. In case of map and set, key is unique.
    2.Elements follow strict weak ordering.

- A Strict Weak Ordering is a Binary Predicate that compares two objects, returning true if the first precedes the second.
- A Binary Predicate is a Binary Function whose result represents the truth or falsehood of some condition. 
- A Binary Predicate might, for example, be a function that takes two arguments and tests whether they are equal. 
- What they roughly mean is that a Strict Weak Ordering has to behave the way that "less than" behaves: if a is less than b then b is 
  not less than a, if a is less than b and b is less than c then a is less than c, and so on.

- Random access iterator that can be moved to point to any element in constant time O(1). Can perform pointer arithmetic with it.
  Bi-directional iterator that can be moved in both directions (i.e. incremented and decremented).

- array, vector and deque all support fast random access to the elements.
- list supports bidirectional iteration.
- forward_list supports only unidirectional iteration.
- stack, queue and priority_queue are implemented as container adaptors.
- associative containers used to implement sorted data structures such as map, set etc.
</pre>

<pre>
ostream is an output stream, the & is to pass by reference ( the only way to pass streams to functions )
your function should be called like this: print(cout,number);
It allows to print to standard output ( cout ) or to any other stream ( like files ).
</pre>

<pre>
Iterator in C++ is basically a pointer to element but then why can't it print the address of the memory block to which it is pointing to?

- Because the ostream operator is not defined for an iterator.
- Assume a vector v. If we try to cout&lt;&lt;v; it would throw an error. For the same reason it would throw an error for the iterator.
- There's no ostream operator defined for directly printing the vector or any other container.
- Just like you can print elements of the vector but not the complete vector itself.
- cout&lt;&lt;v[i]; prints a value, similarly deferencing an iterator will also print a value.
</pre>

## Topic: Array

## std::array

<pre>
1. std::array is a container that encapsulates fixed size arrays.
2. array size is needed at compile time.
3. Assign by value is actually by value.
4. Access Elements:
   a. at() // bound safe
   b. []
   c. front()
   d. back()
   e. data() // gives access to the underlying array
   f. fill(), swap(), comparison operators(lexicographical comparison), empty(), size(), max_size(), begin(), end()
</pre>

<pre>
int main() {

  // Declare
  array<int, 5> myarray;

  // Initialization
  array<int, 5> myarray = {1, 2, 3, 4, 5};  // initializer list
  array<int, 5> myarray2{1, 2, 3, 4, 5};  // uniform initialization (new method c++)

  // Assign using initializer list
  array<int, 5> myarray;
  myarray = {1, 2, 3, 4, 5};

  return 0;
}
</pre>

## Topic: Vector

## std::vector

<pre>
1. std::vector is a sequence container and also known as Dynamic Array or Array List.
2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

ELEMENT ACCESS:
at(), [], front(), back(), data()

MODIFIERS:
insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear(), insert()

CAPACITY:
size(), empty(), capacity()
</pre>

<pre>
int main() {

  // Declarations
  vector<int> arr1;
  vector<int> arr2(5, 20);             // range based (size place, value place)
  vector<int> arr3 = {1, 2, 3, 4, 5};  // initializer list
  vector<int> arr4{1, 2, 3, 4, 5};     // uniform intialization

  // Accessing Elements
  arr2[3] = 10; // [] is overloaded
  arr2.at(3) = 10;

  return 0;
}
</pre>

## Topic: Set

## std::set

<pre>
1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
2. It is usually implemented using Red-Black Tree.
3. Insertion, Removal, Search have logarithmic complexity.
4. If we want to store user defined data type in set then we will have to provide
   compare function so that set can store them in sorted order.
5. We can pass the order of sorting while constructing set object.

BOTTOM LINE:
It store unique elements and they are stored in sorted order (A/D)
</pre>

<pre>
int main() {

  set<int, greater> Set = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; // less is default
  for (const auto& e : Set) {
    cout << e << endl;
  }

  // 5 4 3 2 1

  return 0;
}
</pre>

<pre>
// User defined types - Use of compare functions

class Person {
  public:
   float age;
   string name;
  bool operator<(const Person& rhs) const { return age < rhs.age; }
  bool operator>(const Person& rhs) const { return age > rhs.age; }
};

int main() {
  set<Person, greater<>> Set = {{30, "Rick"}, {25, "Harry"}, {22, "John"}};
  for (const auto& e : Set) {
    cout << e.age << " " << e.name << endl;
  }

  /* 30 Rick
     25 Harry
     22 John */

  return 0;
}
</pre>

## Topic: Container Inside Container

<pre>
int main() // just an implementation example
{
  vector<vector<int>> Tree;
  int edge, n1, n2;

  cin >> edge;
  Tree.resize(edge);

  for (int i = 0; i < edge; ++i) {
    cin >> n1 >> n2;
    Tree[n1].push_back(n2);
  }

  for (const auto &e1 : Tree) {
    for (const auto &e2 : e1) {
      cout << e2;
    }
    cout << endl;
  }

  /* I/P: 6
          1 2
  		  1 3
  		  2 4
  		  2 5
  		  3 6
  		  3 8

  	 O/P: 23
  	 	  45
  	 	  68 */

  return 0;
}
</pre>

## Topic: Map

## std::map

<pre>
1. std::map is associative container that store elements in key value combination
   where key should be unique, otherwise it overrides the previous value.
2. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
3. It store key value pair in sorted order on the basis of key (assending/decending).
4. std::map is generally used in Dictionay type problems.
5. Few Available Operations
   operators = at, [ ], empty, size, max_size, insert, insert_or_assign, erase, clear, begin, end, find
</pre>

<pre>
// EXAMPLE: Dictionary

int main() {

  // map<string, int, less<>> Map;
  map<string, vector<int>, less<>> Map;
  Map["Banana"].push_back(90);
  Map["Apple"].push_back(23);
  // Map.insert(make_pair("Cherry",45))
  Map["Apple"].push_back(36);

  // Loop through map
  for (auto &el1 : Map) {
    cout << el1.first << endl;
    for (auto &el2 : el1.second) {
      cout << el2 << " ";
    }
    cout << endl;
  }

  /* Apple
     23 36
     Banana
     90  */

  // Access using [] operator
  // cout << Map["Banana"] << endl;

  return 0;
}
</pre>

## Topic: List

## std::list

<pre>
1. This is double linked list what we know from C prgramming language.
2. List is sequence container that allow non-contiguous memory allocation.
3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of
   insertion, removal and moving elements in any position provided we have the iterator of the position.
4. We should use this class instead of traditional double linked list because
   a. Well tested
   b. Bunch of available function
5. Few Available Operations
   operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back, push_front
   pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize, comparison operators(lexicographical comparison).
</pre>
<pre>
int main() {

  list<int> list1 = {5,2,4,6,2};
  list<int> list2 = {7,6,1,9};

  return 0;
}
</pre>

## Topic: Pair

## std::pair

<pre>
0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
1. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures.
2. operator =, swap, make_pair, comparison operators(lexicographical comparison)
</pre>

<pre>
void print(pair<int, int>& obj) {
cout << obj.first << " " << obj.second << endl;
}

int main() {
  {
    pair<int, int> obj(10, 20);
    print(obj);
  }
  {
    pair<int, int> obj = make_pair(10, 20);
    print(obj);
  }
  {
    vector<pair<string, uint>> list;
    list.push_back(make_pair("Ron", 30));
    list.push_back(make_pair("Harry", 28));
    list.push_back(pair<string, int>("Bran", 22));
    list.push_back(make_pair("Peter", 18));
    for (auto& elm : list) {
      cout << elm.first << " " << elm.second << endl;
    }
  }

  /* 10 20
	 10 20
	 Ron 30
	 Harry 28
	 Bran 22
	 Peter 18 */

  return 0;
}
</pre>

## Topic: Unordered Map

## std::unordered_map

<pre>
0. std::unordered_map is an associative container that contains key-value pairs with unique keys.
1. Search, insertion, and removal have average constant-time complexity.
2. Internally, the elements are organized into buckets.
3. It uses hashing to insert elements into buckets.
4. This allows fast access to individual elements, because after computing the hash of the value it refers to the exact bucket the element is placed into.

WHY UNORDERED_MAP? 0. maintain a collection of uniqe {key:value} pairs with fast insertion and removal.
</pre>

<pre>
int main()
{
  unordered_map<int, char> umap = {{1, 'a'}, {2, 'b'}};

  // Access
  cout << umap[1] << endl;
  cout << umap[2] << endl;

  // Update
  umap[1] = 'c';

  // Iterate
  for (auto& elm : umap) {
    cout << elm.first << " " << elm.second << " ";
  }
  cout << endl;

  // Find
  auto result = umap.find(2);
  if (result != umap.end()) {
    cout << "Found " << result->first << " " << result->second << '\n';
  } else {
    cout << "Not found\n";
  }

  /* a
     b
     2 b 1 c
     Found 2 b */

  return 0;
}
</pre>

# STL Iterator

<pre>
Operations: 
1.advance(iterator i, int distance)
2.distance(iterator first, iterator last)
3.next(iterator i, int i)
4.prev(iterator i, int i)
5.begin()
6.end()
</pre>

# STL Algorithms

## Sorting:

<pre>
sort                     Sort elements in range
partial_sort             Partially sort elements in range
is_sorted                Check whether range is sorted
</pre>

## Binary search (operating on partitioned/sorted ranges):

<pre>
lower_bound              Return iterator to lower bound
upper_bound              Return iterator to upper bound
equal_range              Get subrange of equal elements
binary_search            Test if value exists in sorted sequence
</pre>

## Non-modifying sequence operations:

<pre>
for_each                 Apply function to range
find                     Find value in range
count                    Count appearances of value in range
mismatch                 Return first position where two ranges differ
equal                    Test whether the elements in two ranges are equal
is_permutation           Test whether range is permutation of another
search                   Search range for subsequence
search_n                 Search range for elements
</pre>

## Modifying sequence operations:

<pre>
copy                     Copy range of elements
copy_n                   Copy elements
fill                     Fill range with value
fill_n                   Fill sequence with value
move                     Move range of elements
transform                Transform range
generate                 Generate values for range with function
swap                     Exchange values of two objects
swap_ranges              Exchange values of two ranges
reverse                  Reverse range
reverse_copy             Copy range reversed
rotate                   Rotate left the elements in range
unique                   Remove consecutive duplicates in range
unique_copy              Copy range removing duplicates
</pre>

## Min/max:

<pre>
min                      Return the smallest
max                      Return the largest
minmax                   Return smallest and largest elements
min_element              Return smallest element in range
max_element              Return largest element in range
minmax_element           Return smallest and largest elements in range
</pre>

## Other:

<pre>
lexicographical_compare Lexicographical less-than comparison
next_permutation        Transform range to next permutation
prev_permutation        Transform range to previous permutation
</pre>
