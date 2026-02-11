// immplementation of lower bound 

// what is lower bound? 

// The index of the first element that is greater than or equal to the target.
// lower bound is smallest index such that arr[index]>=target
// array has to be sorted for lower bound to be immplemented 
// index ie- lower bound (lb)

/*
Normal binary search answers:
“Does the element exist?”

Lower bound answers:
“Where should this element be inserted so that the array stays sorted?”

*/
/*
arr1[]={3,5,8,15,19}
let...target=8
so we get arr[index]>=8 for index = 2 

similarly....
target=9 -> index 3
target=16 -> index 4

target=20 -> index 5 (hypothetical index after last)


arr2[]={3,5,8,15,19,19,19}
target = 19 
lb = 4 (as we smallest)


*/

// implementation of lower bound code (using binary search)
// if lower bound dont exist, we will return size of array (hypothetical index)
// vector<int> nums={1,2,3,3,7,8,9,9,9,11};
/*
take this case, where target element is 1. l=0.u=9. we get m = 4. ie- 7. but 7 is not the smallest element **just** >= target. so returning its index ie-4 is wrong.
search space goes from 10->4->1->0-> -1. (when high crosses low stop.)

*/


#include <iostream>
#include <vector>
using namespace std;


int main(){
    // vector<int> nums={1,2,3,3,7,8,9,9,9,11};
    vector<int> nums={1,2,3,3,5,8,8,10,10,11};
    int target = 9;

    int x = nums.size();
    int l = 0;
    int u = x-1;
    int m;
    int ans = x;

    while(l<=u){

        m = l + (u-l)/2;

        if(nums[m]>=target){
            ans = m;     //potential answer, so store 
            u = m-1;
        }
        else{
            l = m+1;
        }


    }

    cout<<"index is: "<<ans;

    return 0;

}

/*
Time complexity: O(log n)

Space complexity: O(1)
*/


// // direct formual to find lowerbound 

// int x = lower_bound(arr.begin(),arr.end(),target)-arr.begin()

// // iterator is returned, it has to be subtracted by arr.begin() to get the index

// // if asked to find lower bound only between 2nd to 6th index in the array 

// int x = lower_bound(arr.begin()+2,arr.begin()+7,target)-(arr.begin()+2);








// binary upper bound 




// upper bound : arr[index]>target;
// recall lower bound was : arr[index]>=target;

// upper bound implementation 


// #include <iostream>
// #include <vector>
// using namespace std;


// int main(){
//     // vector<int> nums={1,2,3,3,7,8,9,9,9,11};
//     vector<int> nums={2,3,6,7,8,8,11,11,11,12};
//     int target = 11;

//     int x = nums.size();
//     int l = 0;
//     int u = x-1;
//     int m;
//     int ans = x;

//     while(l<=u){

//         m = l + (u-l)/2;

//         if(nums[m]>target){     // just make change here 
//             ans = m;
//             u = m-1;
//         }
//         else{
//             l = m+1;
//         }


//     }

//     cout<<ans; 

//     return 0;

// }

// // t.c = o(logn)
// // s.c = o(1)




// // direct formual to find upperbound 

// int x = upper_bound(arr.begin(),arr.end(),target)-arr.begin()

// // iterator is returned, it has to be subtracted by arr.begin() to get the index

// // if asked to find upper bound only between 2nd to 6th index in the array 

// int x = ypper_bound(arr.begin()+2,arr.begin()+7,target)-(arr.begin()+2);


