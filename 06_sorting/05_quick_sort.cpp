/* quick sort -> sorting in ascending order of data structure 
or with some minor changes, in descending order.
also known as divide and conquer algorithm


t.c -> O(n logn)
s.c -> O(1)   -> as it dont use any temp array like in the merge sort

quick sort is thus slightly better than merge sort 

eg - [4,6,2,5,7,9,1,3]
*/


/*

steps:
pick a pivot (which can be any element in the array) & put it at its correct place in the sorted array.
lets us pick element (4) which is present at index 0, as pivot element.
now we have to place it in its correct place in the sorted array
correct place of (4) is at 3rd index. its currently at 0th index.  

pick a pivot element, place smaller element on the left, larger on the right

4 6 2 5 7 9 1 3
2 1 3 4 6 5 7 9 - 1st step
after the first step itself, one element is at its correct place (4)
we are done with 4 


i) take all element at left of pivot-

2 1 3
pick 2 as pivot 
now, smaller on left, larger on right
1 2 3 
we are left with 2 arrays now ([1] and [3]) since an array with single element is sorted itself, no need to do anything. (base case)

ii) now take all element present at right of pivot 
6 5 7 9

take 6 as pivot 
5 6 7 9 
6 has been placed at its correct place
5 also 
pick 7 9 
7 9 are also placed at correct place


*/


/*
after choosing a pivot element, we dont create new arrays at left and right 
we will use concepts of pointers (low & high etc....)
*/






/*
[4,6,2,5,7,9,1,3]
low = 0; 
high = arr.length()-1;
let us take first element as pivot (we can take any)
pivot = arr[low];

take pointer i,j. place them on 0 and end resp
now try to find the first element which is greater than the pivot

from the left side, using pointer i, check whether the elements written at right are greater than th pivot. if yes, move i.
i moves to the index =1. element =6. 

from the end, check elements smaller than the pivot from the right, and move left

now swap 

initially 
6 _ _ _ 4 _ _ _ 3
now ->  3 _ _ _ 4 _ _ _ 6

you have to stop when you find an element which is greater than the pivot (in left side), vive versa in right.

we will stop at the time, when j crosses i.and we will not swap anymore
the index at which 4 is present can be called as partition index
*/

/*
[4,6,2,5,7,9,1,3]
[2,1,3,4,6,5,7,9]
[1,2,3,4,6,5,7,9]
[1,2,3,4,5,6,7,9]
[1,2,3,4,5,6,7,9]
*/

/*
the new subarrays that from 
(low,partition-1)  (partition+1,high)
peform quick sort algo on both of them 
*/



/*
routine code 

qs(arr,low,high){


    if(low<high){


       int partition =  f(arr,low,high)      -> this fxn will find pivot, place it at correct place and tell us at which index it was placed (partition index) and return it and also do swapping. 

       now again call the function 
       qs(arr,low,partition-1);   -> for left array
       qs(arr,partition+1,high); -> for right array  
       (116,117 lines can be swapped , order dont matter)
    
    }

}

int f(arr,low,high){

        pivot = arr[low];
        i = low;
        j = high;

        while(i<j){

        while(arr[i]<=arr[pivot] && i<=high-1){     //on left we place everything less than equal to pivot ele
        i++;
        }

        while(arr[j]>arr[pivot] && j>=low+1){      // on right we place everything greater than   . these solve edge cases where pivot element is repeated.
        j--;
        }

        if(i<j){       // if j crosses i, do not swap anymore. the moment j crosses i, that index becomes pivot index {j}
            swap(arr[i],arr[j]); 

        }

        swap(arr[low],arr[j]);
        return j;

        }

    }


*/



#include <bits/stdc++.h>
using namespace std;


int fxnpvt(vector<int> &vec1,int low,int high){

    int pivot = vec1[low];
    int i=low;             // i,j are temp vble (pointers) so we can iterate
    int j=high;

while(i<j){

        
    while(vec1[i]<=pivot && i<=high-1){
        i++;
    }

    while(vec1[j]>pivot && j>=low+1){
        j--;
    }

    if(i<j){
        int temp = vec1[j];
        vec1[j] = vec1[i];
        vec1[i] = temp;

    }


    }


    int temp = vec1[j];
    vec1[j] = vec1[low];
    vec1[low] = temp;

    return j;

}

void qs(vector<int> &vec1,int low,int high){

  

    if(low<high){

        int pivot = fxnpvt(vec1,low,high);
        qs(vec1,low,pivot-1);
        qs(vec1,pivot+1,high);


    }
    


}

int main(){

    vector<int> vec1={4,6,2,5,7,9,1,3};

    int low = 0;
    int high = vec1.size()-1;

    qs(vec1,low,high);

    for(auto ele : vec1){

        cout<<ele<<" ";
    }


    return 0;
}




// This while(low < high) never changes low or high inside the loop.
// So after recursion returns, the while condition is still true → infinite recursion risk.


// t.c -> n log2(n)
// n   → work done in each partition step  
// log n → number of times partitioning happens (recursion depth)

// s.c -> O(1); as no new vector is created, so no vector is waiting in the stack space (like during function call) 

