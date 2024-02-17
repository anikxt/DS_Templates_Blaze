//Include the following header files in your code to use PBDS:
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//Namespace
using namespace __gnu_pbds;
//Templates
//defining template when all elements are distinct
template <class T> using Name_given_to_structure = tree<T, null_type,
                         less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//defining template when duplicate elements are also used
template <class T> using Name_given_to_structure = tree<T, null_type,
                         less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;