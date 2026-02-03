// Merge sort 
/*
all algorithms stuided till now, takes O(N^2) t.c. merge sort is better and much more optimised sorting algorithm.
*/

// take example of an array of size = 9. 
// [3,1,2,4,1,5,2,6,4]

// merge sort -> divide and merge algo.

/*
this algo divids the array hypothetically into two parts
lets divide the array of 9 elements into 4-5 or 5-4 and so on.
take p1 part and divide it again to sub arrays. n+1-n



                [3,1,2,4,1,5,2,6,4]
        /                               \
[3,1,2,4,1]                         [5,2,6,4]
    /         \                      /        \
[3,1,2]     [4,1]                 [5,2]       [6,4]
  /    \      /   \                /   \        /   \
[3,1] [2]  [4]   [1]             [5]   [2]     [6]   [4]
 /   \
[3]  [1]   <- cant divide single number further, so stop now. (bae case)

after reaching this point, peform second half of the algorithm, which is to merge them. (two pointers are used for it)

---------------- MERGE PHASE ----------------

subarrays        SORTED arrays 
[3] [1]        → [1,3]   
[1,3] [2]      → [1,2,3]   
[4] [1]        → [1,4]
[1,2,3] [1,4]  → [1,1,2,3,4]    


[5] [2]        → [2,5]
[6] [4]        → [4,6]
[2,5] [4,6]    → [2,4,5,6]

[1,1,2,3,4] [2,4,5,6] → [1,1,2,2,3,4,4,5,6]  -> a point will come when the pointer present on the p1 array moves out of bound, it basically means that all the p1 array element have been added in the final result array.
without doing any further comparasions, pick up all elements from the p2 and put it in the result array.  

the resultant array that we get after merging is always sorted


*/

/*
instead of actually diving the array, we manupulate the indexes

low = 0;
high = arr.size()-1;

we take these, as start and ending points of the array

*/






/*
routine code - 
take eg- [3,2,4,1,3] 




          [3,2,4,1,3]
        /             \
   [3,2,4]          [1,3]
    /     \           /   \
 [3,2]   [4]       [1]   [3]
  /   \
[3]  [2]

-------------- MERGE PHASE --------------

[3] [2]        → [2,3]
[2,3] [4]      → [2,3,4]

[1] [3]        → [1,3]

[2,3,4] [1,3]  → [1,2,3,3,4]


low=0,high=4;

void mergesort(arr[],low,high) {

    if(low==high){
        return 0;
    }

    mid = (low+high)/2;

    mergesort(arr,low,mid);   <- for sorting the p1 part
    mergesort(arr,mid+1,high);   <- for sorting p2 part
    merge(arr,low,mid,high);   <- for merging them back in sorted way, routine code will be written later

    //instead of actually dividing the array, we changes the indexes.


}
*/

// see pic of merge sort dry run.

// for merge routine code, lets take example of this array 
// [1,1,2,3,4]  [2,4,5,6]
// 0        4    5     8 



/*
merge(arr,low,mid,high){
    temp[high]={0};
    p1 = low;
    p2 = mid+1;
    while(p1<=mid && p2<=high){

    if(arr[p1]<arr[p2]){

    temp.add(arr[p1])
    p1++;

    }

    else{
    temp.add(arr[p2])
    p2++;
    }

    //while loop may become false when, either p1 of p2 pointer exaust (either of them goes out of bound)

    while(p1<=mid){

    temp.add(arr[p1]);
    p1++;
    
    
    }


    while(p2<=high){

    temp.add(arr[p2]);
    p2++;
    
    
    }

    for(int i=low;i<high;i++){

    arr[i]=temp[i-low];
    
    
    } 

}
    



}

*/



// final code 


#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec1,int low,int mid,int high){
       vector<int> vec2;
   
    int p1 = low;
    int p2 = mid+1;

    while(p1<=mid && p2<=high){
        if(vec1[p1]<=vec1[p2]){
            vec2.push_back(vec1[p1]);
            p1++;
        }
        else{
            vec2.push_back(vec1[p2]);
            p2++;
        }
    }

    while(p1<=mid){
        vec2.push_back(vec1[p1]);
        p1++;
    }

    while(p2<=high){
        vec2.push_back(vec1[p2]);
        p2++;
    }


    for(int i=low;i<=high;i++){
        vec1[i]=vec2[i-low];
    }

 
}





void mergesort(vector<int> &vec1,int low,int high){

    if(low>=high){
        return;
    }

    int mid = low+ (high-low)/2;

    mergesort(vec1,low,mid);
    mergesort(vec1,mid+1,high);
    merge(vec1,low,mid,high); 


}


int main(){

    vector<int> vec1={3,1,2,4,1,5,2,6,4};
    int low=0;
    int high = vec1.size()-1;
  

    mergesort(vec1,low,high);

    for(auto it : vec1){
        cout<<it<<" ";
    }

    return 0;
}


/*
If you try to write directly back into the original vector while still reading from it, you will overwrite values that you have not yet compared. That destroys data you still need, thats the reason why another temporary vector is createrd. vec2


*/

// time complexity of merge sort 
// for divison of array part-
// the array at every call gets divided into half. n->n/2->n/4
// so t.c -> O(log2(n))
// the division of array approximately happens logarithemic times

// for merging part
// eg- [2,3,5]   [7,1]
// in order to merge these 2 array, at least we will require 5 steps (5 comparison)
// worst case O(n) 

// so final time complexity is - O(n log n) (best/average/worst) 
// space complexity - O(n) -> as we create a temp array (vec2) during merge process, these merge calls in total n calls can wait in space at worst
