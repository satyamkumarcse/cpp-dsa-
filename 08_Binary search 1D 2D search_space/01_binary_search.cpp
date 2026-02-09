// explain 


// Binary Search is used to find an element in a sorted array by repeatedly dividing the search space into half.

// How it works
// Take two pointers: left and right
// Find the middle index mid
// Compare target with arr[mid]
// If equal, return mid

// If target is smaller, update upper bound

// If target is larger, update lower bound

// Repeat until left > right
// (these 3 operations above change length of search space)


// Key requirements
// Array must be sorted
// Works only on random access data structures (like arrays, vectors)

// Time and space complexity
// Time: O(log n) 
// Space: O(1) (iterative version)

/*
Binary search is a searching technique used on a sorted array. The core idea is to eliminate half of the search space at every step instead of checking elements one by one
If the array is sorted, comparing with the middle element tells you which half cannot contain the target.
Without sorting, that information does not exist.*/


// iterative approach 
// return index of target, if not found then -1



// class Solution {
// public:
//     int search(vector<int>& nums, int target) {

//         int x = nums.size();
//         int l = 0;
//         int u = x-1;

//         while(l<=u){
//             int m = l + (u-l)/2;

//             if(target==nums[m]){
//                 return m;
//             }
//             else if(target>nums[m]){
//                 l = m+1;
//             }
//             else{
//                 u = m-1;
//             }
//         }

//         return -1;
//         // return l;      // if asked to return where to insert target element to keep order sorted
        
//     }
// };






// using recursive approach



class Solution {
public:
    int recursivesearch(vector<int>& nums,int l,int u,int target){

        if(l>u){
            return -1;
        }
         int m = l + (u-l)/2;
        
        if(target==nums[m]){
            return m;

        }
        else if(target>nums[m]){
            return recursivesearch(nums,m+1,u,target);
        }
        else{
            return recursivesearch(nums,l,m-1,target);

        }

    }


    int search(vector<int>& nums, int target) {

        
        int x = nums.size();int l = 0;int u = x-1;


        int y = recursivesearch(nums,l,u,target);

       

        return y;
        
        
    }

    
};

/*Time complexity: O(log n)

Space complexity: O(log n) due to recursion stack*/

// let us check overflow case 

// arrays in general have size of about 10^5-10^7 without overflows.
// binary search algorithm is not limited to search in an array, if can be searching operation on a diactionary,answers,words etc.

// let us take a search space from 0 to INT_MAX 
// now let us assume out target word/ele/value is present at last element 
// mid = (l+u)/2 
// as l=u=INT_MAX 
// overflow will occur while adding as 2*INT_MAX cant be stored in an integer



// solutions 

// take long long for assingning low and high 
// or mid = low + (high-low)/2 ; if we are sure that search space is under INT_MAX 

