
// 33. Search in Rotated Sorted Array



// brute force - o(n)

class Solution {
public:
    int search(vector<int>& nums, int target) {

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
                
            }
        }
        return -1;
        
    }
};



// eg - take example of arr [1,2,3,4,5]
// target element = 1 
// target element = 5

// when target element was 1 , mid = 3. so we will not search in the right side this was made sure 
// when target element was 5, mid=3, left side of search space will be eliminated. so we will not search in the left side this was made sure 



/*wrong answer, wrong approach*/

class Solution {
public:

    void merge(vector<int>& nums, int low, int m, int high){

        int p1 = low;
        int p2 = m + 1;
        vector<int> temp;

        while(p1 <= m && p2 <= high){
            if(nums[p1] <= nums[p2]){
                temp.push_back(nums[p1]);
                p1++;
            }
            else{
                temp.push_back(nums[p2]);
                p2++;
            }
        }

        while(p1 <= m){
            temp.push_back(nums[p1]);
            p1++;
        }

        while(p2 <= high){
            temp.push_back(nums[p2]);
            p2++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }

    void sort(vector<int>& nums, int low, int high){
        if(low >= high){
            return;
        }

        int m = low + (high - low) / 2;

        sort(nums, low, m);
        sort(nums, m + 1, high);
        merge(nums, low, m, high);
    }


    int search(vector<int>& nums, int target) {

        int x = nums.size();
        int low = 0;
        int high = x-1;
        int m = low + (high-low)/2;
        sort(nums,low,high);

        while(low<=high){

            m = low + (high-low)/2;

            if(nums[m]==target){
                return m;
                
            }
            else if(nums[m]>target){
                high = m-1;
            }
            else{
                low = m+1;
            }

        }

        return -1;
        
    }
};



// optimal solution 

// it was mentioned that the array has been sorted and then rotated. sorting it again makes no sense and we also loose the track of the index of target element.

// Find the middle element
// 2. Identify which half is sorted:
//    - If arr[left] <= arr[mid], left half is sorted
//    - Otherwise, right half is sorted
   
// 3. Check if target is in the sorted half:
//    - If yes, search that half and eliminate the other one
//    - If no, search the other half and eliminate (vive versa)




class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            // Found target
            if(nums[mid] == target){
                return mid;
            }
            
            // CASE A: Left half [low...mid] is sorted
            if(nums[low] <= nums[mid]){
                // Check if target is in sorted left half
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;  // Search left
                }
                else{
                    low = mid + 1;   // Search right (unsorted half)
                }
            }
            // CASE B: Right half [mid...high] is sorted
            else{
                // Check if target is in sorted right half
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;   // Search right
                }
                else{
                    high = mid - 1;  // Search left (unsorted half)
                }
            }
        }
        
        return -1;  // Not found
    }
};





// ## The Problem

// **Given**: A sorted array that has been rotated at some pivot  
// **Example**: `[0,1,2,4,5,6,7]` rotated becomes `[4,5,6,7,0,1,2]`  
// **Task**: Find target in O(log n) time

// ---

// ## Why Regular Binary Search Fails

// **Regular Binary Search** assumes the **entire array is sorted**.

// ```
// Regular sorted: [0,1,2,4,5,6,7]
//                     ↑
//                    mid
// If target < mid → search left
// If target > mid → search right
// ```

// **Rotated array**: `[4,5,6,7,0,1,2]`
// ```
//                     ↑
//                    mid=7
// If target=0 (which is < 7)
// Regular binary search → search left [4,5,6]
// But 0 is actually on the RIGHT [0,1,2] ❌
// ```

// The rotation **breaks the sorted property**, so we can't blindly compare target with mid.

// ---

// ## The Key Insight

// **In a rotated sorted array, at least ONE half is always sorted.**

// ```
// Array: [4,5,6,7,0,1,2]
//         ↑      ↑      ↑
//        low    mid   high

// Left half:  [4,5,6,7] ✓ SORTED
// Right half: [0,1,2]   ✓ SORTED

// Array: [6,7,0,1,2,4,5]
//         ↑      ↑      ↑
//        low    mid   high

// Left half:  [6,7,0]   ✗ NOT sorted (has rotation point)
// Right half: [1,2,4,5] ✓ SORTED
// ```

// **Strategy**: 
// 1. **Identify which half is sorted**
// 2. **Check if target lies in the sorted half**
// 3. **Search accordingly**

// ---

// ## How to Identify the Sorted Half

// Compare `nums[low]` with `nums[mid]`:

// ```cpp
// if(nums[low] <= nums[mid]){
//     // Left half is sorted
// }
// else{
//     // Right half is sorted
// }
// ```

// **Why this works?**

// **Case 1**: Left half sorted
// ```
// [4,5,6,7,0,1,2]
//  ↑      ↑
// low    mid

// 4 <= 7 ✓ → Left is sorted [4,5,6,7]
// ```

// **Case 2**: Right half sorted
// ```
// [6,7,0,1,2,4,5]
//  ↑      ↑
// low    mid

// 6 <= 1 ✗ → Left has rotation, so Right is sorted [1,2,4,5]
// ```

// ---

// ## The Complete Algorithm Logic

// ### Step 1: Check if mid is the target
// ```cpp
// if(nums[mid] == target){
//     return mid;  // Found it!
// }
// ```

// ### Step 2: Determine which half is sorted

// #### **Case A: Left half is sorted** (`nums[low] <= nums[mid]`)

// ```
// [4,5,6,7,0,1,2]  target = 5
//  ↑      ↑      ↑
// low    mid   high

// Left: [4,5,6,7] is sorted
// ```

// **Now check**: Is target in this sorted range?

// ```cpp
// if(nums[low] <= target && target < nums[mid]){
//     // Target is in sorted left half
//     high = mid - 1;  // Search left
// }
// else{
//     // Target must be in right half
//     low = mid + 1;   // Search right
// }
// ```

// **Example 1**: target = 5
// - `nums[low]=4 <= 5` ✓
// - `5 < nums[mid]=7` ✓
// - Target IS in left sorted range → search left

// **Example 2**: target = 0
// - `nums[low]=4 <= 0` ✗
// - Target NOT in left sorted range → search right

// ---

// #### **Case B: Right half is sorted** (`nums[low] > nums[mid]`)

// ```
// [6,7,0,1,2,4,5]  target = 4
//  ↑      ↑      ↑
// low    mid   high

// Right: [1,2,4,5] is sorted
// ```

// **Now check**: Is target in this sorted range?

// ```cpp
// if(nums[mid] < target && target <= nums[high]){
//     // Target is in sorted right half
//     low = mid + 1;   // Search right
// }
// else{
//     // Target must be in left half
//     high = mid - 1;  // Search left
// }
// ```

// **Example 1**: target = 4
// - `nums[mid]=1 < 4` ✓
// - `4 <= nums[high]=5` ✓
// - Target IS in right sorted range → search right

// **Example 2**: target = 7
// - `nums[mid]=1 < 7` ✓
// - `7 <= nums[high]=5` ✗
// - Target NOT in right sorted range → search left

// ---

// ## Complete Code with Theory

// --

// ## Dry Run Example

// **Array**: `[4,5,6,7,0,1,2]`, **Target**: `0`

// ### Iteration 1:
// ```
// [4,5,6,7,0,1,2]
//  ↑      ↑      ↑
// low    mid   high

// mid = 3, nums[mid] = 7
// nums[low]=4 <= nums[mid]=7 → Left sorted
// Is target in [4,5,6,7]? 
//   4 <= 0? NO
//   → Search RIGHT
// low = mid + 1 = 4
// ```

// ### Iteration 2:
// ```
// [4,5,6,7,0,1,2]
//         ↑  ↑  ↑
//        low mid high

// mid = 5, nums[mid] = 1
// nums[low]=0 <= nums[mid]=1 → Left sorted
// Is target in [0,1]?
//   0 <= 0 < 1? YES
//   → Search LEFT
// high = mid - 1 = 4
// ```

// ### Iteration 3:
// ```
// [4,5,6,7,0,1,2]
//         ↑
//      low=mid=high

// mid = 4, nums[mid] = 0
// nums[mid] == target → FOUND!
// Return 4
// ```

// ---

// ## Why This Works: The Guarantee

// **Mathematical guarantee**: 

// In a rotated sorted array, when you divide it at any point:
// - **At least one half MUST be completely sorted**
// - The other half MAY contain the rotation point

// This is because there's **only ONE rotation point** in the array.

// ```
// Original: [0,1,2,3,4,5,6,7]
// Rotated:  [5,6,7,0,1,2,3,4]
//               ↑
//           rotation point

// Any mid point creates:
// - Either: both halves sorted (mid before rotation)
// - Or: one sorted, one with rotation point
// - Never: both halves unsorted
// ```

// ---

// ## Summary

// 1. **Rotated array** = one sorted array with one rotation point
// 2. **At least one half is always sorted**
// 3. **Identify the sorted half** using `nums[low] <= nums[mid]`
// 4. **Check if target is in sorted half** using range comparison
// 5. **If yes → search sorted half, if no → search other half**
// 6. **Time**: O(log n) because we eliminate half each iteration

// This is why the algorithm works! 🎯


class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int x = nums.size();
        int low = 0;
        int high = x-1;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(nums[mid]==target){

                return true;

            }

            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[low]<=nums[mid]){

                if(nums[low]<=target && nums[mid]>target){

                    high = mid - 1;
                }
                else{
                    low = mid+1;
                }
            }
            else{

                if(nums[mid]<target && nums[high]>=target){

                    low = mid+1;
                }
                else{

                    high = mid-1;
                }



            }


        }

        return false;
        
    }
};







// Search in Rotated Sorted Array II - dupicate elements are present 


class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int x = nums.size();
        int low = 0;
        int high = x-1;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(nums[mid]==target){

                return true;

            }

            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[low]<=nums[mid]){

                if(nums[low]<=target && nums[mid]>target){

                    high = mid - 1;
                }
                else{
                    low = mid+1;
                }
            }
            else{

                if(nums[mid]<target && nums[high]>=target){

                    low = mid+1;
                }
                else{

                    high = mid-1;
                }



            }


        }

        return false;
        
    }
};


/*Why needed?
When nums[low] == nums[mid] == nums[high], we can't determine which side is sorted.
Example: [1,1,1,1,1,1,1] or [1,0,1,1,1]
We must linearly shrink the search space by moving both pointers inward.*/







