
# Dynamic Programming
Big idea, hard, yet simple.
> * Powerful algorithmic design technique.
> * Large class of seemingly exponential problems have a polynomial solution (“only”)
via DP.
> * Particularly for optimization problems (min / max) (e.g., shortest paths).

\* DP ≈ “controlled brute force”  
\* DP ≈ recursion + re-use


 ## *Terminology:*
> ***States***: The answers we have stored.  
> ***Transitions***: The relations between states.  
> ***Base Case***: The initial conditions.
 
 ## *Cost:*
> ***Space Complexity***: Number of states.  
> ***Time Complexity*** : Number of states * Avg. time required to answer one state.

<p>&nbsp</p>

## *Quick Definitions:*

> * DP ≈ “careful brute force”
> * DP ≈ guessing + recursion + memoization
> * DP ≈ dividing into reasonable # subproblems whose solutions relate  
  >> * — acyclicly —  
  >> * usually via guessing parts of solution.
> * time = # subproblems × time/subproblem  
  >> * treating recursive calls as O(1) (usually mainly guessing)  
  >> * essentially an amortization  
  >> * count each subproblem only once; after first time, costs O(1) via memoization
> * DP ≈ shortest paths in some DAG

<p>&nbsp</p>

## *5 Easy Steps to Dynamic Programming:*

1. define subproblems 
	> _count # subproblems_
2. guess (part of solution)
	> _count # choices_
3. relate subproblem solutions 
	> _compute time/subproblem_
4. recurse + memoize
OR 
build DP table bottom-up
	> _check subproblems acyclic/topological order_
	>
	> _time = time/subproblem · # sub-problems_ 

6. solve original problem = a subproblem
OR 
by combining subproblem solutions
	> _extra time_

**Example:** Fibonacci Numbers

| 						                |   					                                        | 			     	         |
| --------------------------- | --------------------------------------------------- | -------------------- |
| <u>_subproblems:_</u>       | _F<sub>k</sub> for 1 $\leq$ k $\leq$ n_             | _# subprobs: n_			 |       
| <u>_guess:_</u>     	      | _nothing_ 				 						                      | _# choices: 1_		   |       
| <u>_recurrence:_</u>        | _F<sub>k</sub> = F<sub>k-1</sub> + F<sub>k-2</sub>_ | _# time/subpr: Θ(1)_ |       
| <u>_topological order:_</u> | _for k = 1,...,n_  								                  | _# total time: Θ(n)_ |       
| <u>_original problem:_</u>  | _F<sub>n</sub>_  								                  	| _# extra time: Θ(1)_ |       

<p>&nbsp</p>

## *2 kinds of guessing:*
 * In (2) & (3), guess which other subproblems to use in order to solve the bigger subproblem (used by every DP except Fibonacci).
 * In (1), create more subproblems to guess/remember more structure of solution (used by knapsack DP). 
      * effectively report many solutions to subproblem.
      * lets parent subproblem know features of solution.

<p>&nbsp</p>

## *Useful problems for strings/sequences x:*
| 				  	        |           	 		  |   	                        |
| ------------------- | ----------------- | --------------------------- |
| suffixes x[i :]     | Θ(\|x\|)          | ← cheaper ⇒ use if possible | 
| prefixes x[: i]     | Θ(\|x\|) 		      | ← cheaper ⇒ use if possible |
| substrings x[i : j] | Θ(x<sup>2</sup> ) |             						    |

<p>&nbsp</p>

## *Parent Pointers:*
To recover actual solution in addition to cost, store <u>parent pointers</u> (which guess used at each subproblem) & walk back.
> * typically: remember argmin/argmax in addition to min/max
> * just like memoization & bottom-up, this transformation is <u>automatic</u>
no thinking required!

<p>&nbsp</p>

## *Polynomial and Pseudopolynomial time*
 - Time Complexity is based on the input. 
 - In knapsack problem, Inputs are the no. of items N, knapsack capacity W, weight & value arrays. We construct dp table as _**N * W**_. so we feel as its of polynomial time complexity. 
 - But, **input W is an integer**, _not an array_. So, it will be _O(**N** * **(no. of bits required to store given W)**)_.
 -  If no. of bits increases by 1, then the running time actually get doubles. Thus, it is exponential, thereby pseudo-polynomial.

| Remember:        |       |
|:---------------- | ----- |
| polynomial 	   | GOOD  |
| exponential 	   | BAD   |
| pseudopolynomial | SO SO |




