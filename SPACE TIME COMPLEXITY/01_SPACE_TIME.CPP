//                          TIME COMPLEXITY 

// its not the actual time taken to run a program but amount of time taken as function of input size (n).

// time complexity is machine independent. 

// a program may take different amount of time to compile on windows/mac/linux or web servers like leet code,code forces,code chef.

// time complexity - rate at which the time taken changes with respect to the input size 

//time complexity in expressed in terms of big O notation.
// symbol = O(n)


// eg- int x=10;
//  for(){} etc... these are operation.


/*   pseudo code-

// example - linear search 
// array size is let - n. (n may vary)

    for(i=0;i<n;i++){
    if arr[i]==target;
        return i;
    }
        return -1

*/

//in this program if n=1. the loop runs 1 times. number of operations =1.
// total operations = the number of time loop runs. (in case of O(n))

// if we are peforming linear search on an array of size = 20.
// if we get target element at 1st index = best case.
// if we get at last index = worst case.

// always measure time complexity in terms of worst case scenario
// avoid constants 
// avoid lower values

// in the linear search program
// if the loop runs 10 times for 10 elements, inside the loop 
// 4 things are happening per run.
// increment,searching target,return,verifying condition
// time complexity = O(4n) or nearly = O(n)
// in n doubles, 4n also doubles 
// the constant (4) wont determine how the programs is behaving,thus can be ommited.

// best case = target element at 1st index. O(1)
// average = somewhere between             O(5)  (best+worst)/2
// worst = last element was target.      O(10)


// let a program have time complexity of O(4n^3 + 3n^2 + 8)
// let n=10^5
// the 3*10^10 + 8 wont make any significance.


/*

   int x=5;                    (operation 1)


    for(i=0;i<n;i++){          (operation 2)
    if arr[i]==target;
        return i;
    }
        return -1

 O(3*N + 1) nearly  = O(3*N)
  
*/


// big o (O) = upper/highest or the worst case complexity.
// omega = lower bound/best case
//  thetha = average complexity 


// single loop - O(n)
// nested loop - O(n^2)


/*
for(i=0;i<n;i++){

    for(j=0;j<n;j++)
    
    }

when i=0,j=0  0
when i=1,j=0,1  1
when i=2,j=0,1,2  3 

.
.
.
.  
when i=n-1,j=0,1,2......n-1  n
.
.
.
.
.               

sum of all steps = sum of n natural numbers = n(n+1)/2 = n^2/2 + n/2 == O(n^2)
*/
 



 

