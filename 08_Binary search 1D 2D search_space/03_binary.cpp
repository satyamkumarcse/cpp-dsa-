// floor and ceil 

// floor - largest number in the array either equal or less than x 

// ceil - smallest number in the array either equal or more than x 

// imagine room walls from 0 to x metres coordinates

// eg1- arr = [10 20 30 40 50]
// x = 25 has floor = 20 , and ceil = 30

// eg2- arr = [10 20 25 30 40] : x = 25
// floor = ceil = 25

// return -1 if no floor or ceil exist







// code for floor of a target




// #include <iostream>
// #include <vector>
// using namespace std;


// int main(){
    
//     vector<int> nums={10, 20, 30, 40, 50};
//     int target = 2;

//     int low=0;
//     int m;
//     int high = nums.size()-1;

//     while(low<=high){

//         m = low + (high-low)/2;

//         if(nums[m]<=target){

//             low = m+1;

//         }
//         else{

//             high = m-1;
//         }
        

//     }

//     if(target<nums[0]){
//         cout<<-1;
//     }
//     else{
//          cout<<nums[high];


//     }

//     return 0;


// }


// t.c = o(logn)
// s.c = o(1)







// code of ceil for a target


// #include <iostream>
// #include <vector>
// using namespace std;


// int main(){
    
//     vector<int> nums={10, 20, 30, 40, 50};
//     int target = 23;

//     int low=0;
//     int m;
//     int high = nums.size()-1;

//     while(low<=high){

//         m = low + (high-low)/2;

//         if(nums[m]<=target){

//             low = m+1;

//         }
//         else{

//             high = m-1;
//         }
        

//     }

//     if(target>nums[nums.size()-1]){
//         cout<<-1;
//     }
//     else{
//          cout<<nums[low];


//     }

//     return 0;


// }




// 34. Find First and Last Position of Element in Sorted Array - brute force



// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//            int x = nums.size();
//            int first = -1;
//            int last = -1;
//            bool found = false;

//         for(int i=0;i<x;i++){
//             if(nums[i]==target){
//                 found = true;
//                 if(first ==-1){first = i;}
//                 last = i;
//             }
//         }

        
//         if(found){
//             return{first,last};
//         }
//         else{
//             return {-1,-1};

//         }
        
//     }
// };



// t.c = o(n)







// optimal solution will have log(n) as t.c 
// optimal solution 

//  using lower bound and upper bound



// class Solution {
// public:
//     int lowerbound(vector<int>& nums,int n,int target){
        

//             int low=0;
//             int high = nums.size()-1;
//             int ans = nums.size();

//             while(low<=high){
//                 int m = low + (high-low)/2;
//                 if(nums[m]>=target){
//                     ans = m;
//                     high = m-1;

//                 }
//                 else{
//                     low = m+1;
//                 }

//             }

//             return ans;
//         }

//     int upperbound(vector<int>& nums,int n,int target){

//             int low=0;
//             int high = nums.size()-1;
//             int ans = nums.size();

//             while(low<=high){
//                 int m = low + (high-low)/2;
//                 if(nums[m]>target){
//                     ans = m;
//                     high = m-1;

//                 }
//                 else{
//                     low = m+1;
//                 }

//             }

//             return ans;
//         }

//     vector<int> searchRange(vector<int>& nums, int target) {

//         int n = nums.size();

//         int lb = lowerbound(nums,nums.size()-1,target);
//         int ub = upperbound(nums,nums.size()-1,target);

//         if(lb == n || nums[lb]!=target){return {-1,-1};}   // if target element is not present or lower bound wrt target cant be found in array (nums[n] is outofbound) thus, we return {-1,-1}
//         else{
//             return {lb,ub-1};
//         }

//     }
// };


// t.c = 2*o(log n)
// s.c = o(1)








// plane binary search code for this question 

// arr = [2,8,8,8,8,11,13];





// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){

//     vector<int>arr = {2,8,8,8,8,11,13};
//     int target = 8;

//     // FIRST OCCURRENCE
//     int low1 = 0;
//     int high1 = arr.size() - 1;
//     int m1;

//     while(low1 <= high1){
//         m1 = low1 + (high1 - low1) / 2;

//         if(arr[m1] == target){
//             high1 = m1 - 1;       //  Search LEFT for earlier occurrence
//         }
//         else if(arr[m1] < target){
//             low1 = m1 + 1;        //  Go RIGHT
//         }
//         else{  // arr[m1] > target
//             high1 = m1 - 1;       //  Go LEFT
//         }
//     }

//     int x = low1;  //  After loop, low1 points to first occurrence


//     // LAST OCCURRENCE
//     int low2 = 0;
//     int high2 = arr.size() - 1;
//     int m2;

//     while(low2 <= high2){
//         m2 = low2 + (high2 - low2) / 2;

//         if(arr[m2] == target){
//             low2 = m2 + 1;        //  Search RIGHT for later occurrence
//         }
//         else if(arr[m2] < target){
//             low2 = m2 + 1;        //  Go RIGHT
//         }
//         else{  // arr[m2] > target
//             high2 = m2 - 1;       //  Go LEFT
//         }
//     }

//     int y = high2;  //  After loop, high2 points to last occurrence

//     cout << x << " " << y;

//     return 0;
// }







// for leetcode, for returning -1,-1 if target element not present 


// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){

//     vector<int>arr = {2,8,8,8,8,11,13};
//     int target = 8;

//     // FIRST OCCURRENCE (eliminate right search space)
//     int low1 = 0;
//     int high1 = arr.size() - 1;
//     int first = -1;  //  Use a proper variable, not m1

//     while(low1 <= high1){
//         int m1 = low1 + (high1 - low1) / 2;

//         if(arr[m1] == target){
//             first = m1;           //  Store potential answer
//             high1 = m1 - 1;       //  Search LEFT for earlier occurrence
//         }
//         else if(arr[m1] < target){
//             low1 = m1 + 1;        //  Go RIGHT
//         }
//         else{  // arr[m1] > target
//             high1 = m1 - 1;       //  Go LEFT
//         }
//     }

//     // LAST OCCURRENCE (eliminate left search space)
//     int low2 = 0;
//     int high2 = arr.size() - 1;
//     int last = -1;  //  Use a proper variable, not m2

//     while(low2 <= high2){
//         int m2 = low2 + (high2 - low2) / 2;

//         if(arr[m2] == target){
//             last = m2;            //  Store potential answer
//             low2 = m2 + 1;        //  Search RIGHT for later occurrence
//         }
//         else if(arr[m2] < target){
//             low2 = m2 + 1;        //  Go RIGHT
//         }
//         else{  // arr[m2] > target
//             high2 = m2 - 1;       //  Go LEFT
//         }
//     }

//     cout << first << " " << last;

//     return 0;
// }






/*
Trace for FIRST Occurrence
Array: {2, 8, 8, 8, 8, 11, 13}, Target: 8

Iteration | low1 | high1 | m1 | arr[m1] | Action
----------|------|-------|----|---------|---------------------------------
    1     |  0   |   6   | 3  |    8    | Found! first = 3, high1 = 2
    2     |  0   |   2   | 1  |    8    | Found! first = 1, high1 = 0
    3     |  0   |   0   | 0  |    2    | < 8, low1 = 1
   End    |  1   |   0   | -  |    -    | low1 > high1, loop exits

After loop ends:
- low1 = 1 ✅ (points to first occurrence)
- high1 = 0 ❌ (points to index 0, which is 2, NOT the target!)
- first = 1 ✅ (stored when we last found target)
*/






// count occurences of a number in a sorted array with duplicates
// brute solution





// int main(){

//     vector<int>arr = {2,2,8,8,8,11,11,13};
//     int target = 11;
//     int count = 0;

//     for(int i=0;i<arr.size();i++){

//         if(arr[i]==target){

//             count++;
//         }
//     }

//     cout<<count;
//     return 0; 

// }

// t.c - O(n)
// s.c - O(1)


// optimal solution - if we simply find first and last occurence by using lower / upper bound concept, then we can do last-first+1 to find number of occurences



#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int>arr = {2,2,8,8,11,11,11};
    int target = 12;
    int ans1 = -1;  // Initialize to -1 to handle "not found" case
    int ans2 = -1;
    int l1 = 0;
    int h1 = arr.size()-1;

    // Find FIRST occurrence
    while(l1<=h1){
        int m1 = l1 + (h1-l1)/2;

        if(arr[m1] == target){  // 
            ans1 = m1;
            h1 = m1-1;  // Continue searching in left half
        }
        else if(arr[m1] < target){
            l1 = m1+1;
        }
        else{
            h1 = m1-1;
        }
    }

    int l2 = 0;
    int h2 = arr.size()-1;

    // Find LAST occurrence
    while(l2<=h2){
        int m2 = l2 + (h2-l2)/2;

        if(arr[m2] == target){  // Changed: == instead of >
            ans2 = m2;
            l2 = m2+1;  // Continue searching in right half
        }
        else if(arr[m2] < target){
            l2 = m2+1;
        }
        else{
            h2 = m2-1;
        }
    }

    // Check if target was found
    if(ans1 == -1 || ans2 == -1){
        cout << 0 << endl;
    }
    else{
        cout << ans2 - ans1 + 1 << endl;  // Now +1 is correct
    }

    return 0;
}