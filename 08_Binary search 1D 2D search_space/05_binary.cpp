// finding single element in a sorted array 

//  wrong answer, not all test cases pass

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int x = nums.size();
        

        for(int i=0;i<x;i++){

            if(i==0){
                if(nums[i]==nums[i+1]){
                    continue;
                }
                else{
                    return nums[i];
                }
            }
            else if(i==x){
                if(nums[x]==nums[x-1]){
                    continue;
                }
                else{
                    return nums[x];
                }
            }
            else{
                if(nums[i]==nums[i+1] || nums[i-1]==nums[i]){
                    
                    continue;
                }
                else{
                    return nums[i];
                }
            }

            
        }

        return -1;
        
    }
};



// in case when index gets out of bound, we get runtime error
// wrong - indexing issue. no need to check == case. check != case and move on the else,else if block. approaching question with == is indirect and lenghthy 






// brute force solution 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int x = nums.size();

        if(x==1){
            return nums[0];
        }
        

        for(int i=0;i<x;i++){

            if(i==0){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }
            else if(i==x-1){
                if(nums[i]!=nums[i-1]){
                    return nums[i];
                }
            }
            else{
                if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }

            
            }

            
        

        return -1;
        
    }
};




// another brute force - hashing 




class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();
        int count=0;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]+=1;
        }

        for(auto it : mp){
            if(it.second==1){
                return it.first;
            }
        }

        return -1;
        
              
    }
};

// trade off for space complexity 



// optimal solution 
// since the array is ""sorted"" and we have to "search" for element with single occurence, use binary search.

// in binary search we eliminate at each step 
// array shrinks to n->n/2->n/4... approximately.

// find out a property of the element with single occurence, which can justify the elimination 

// let us do some observations: 
// [1 1 2 2 3 3 4 5 5 6 6]
// all the elements present at the left of the element which has 1 occurence, are in pairs of (even,odd) index
// all the elements present at the right of the element which has 1 occurence, are in pairs of (odd,even) index

// if (even,odd) -> im on left half 
// if (odd,even) -> im on right half 


// in binary search here, if we go traditionlly use pointers like low,mid and m index. there will a a lot of edge cases 

// nums[i]!=nums[i-1] && nums[i]!=nums[i+1]

/*if(i==0){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }
            else if(i==x-1){
                if(nums[i]!=nums[i-1]){
                    return nums[i];
                }
            }*/


// try to eliminate these edge cases 
// eg-         if(x==1){
        //     return nums[0];
        // }


// all these observation are from brute force approach 
// in order to avoid edge cases, we can trim the search space 
// low at index 1 instead of 0
// high at index n-2 instead of n-1
// do seprate checks for indexes 0 and n-1, instead of including in the search space 
// this eliminate extra conditional statements
// e- even, o-odd, 1-element with 1 occurence

// e,o e,o e,o e,o 1 o,e o,e o,e o,e 

  



// optimal  solution 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int x = nums.size();
        int low = 1;
        int high=x-2;

        if(x==1){
            return nums[0];
        }

        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[x-1]!=nums[x-2]){
            return nums[x-1];
        }

        while(low<=high){

            int m = low+(high-low)/2;

            if((nums[m]!=nums[m+1]) && (nums[m-1]!=nums[m])){
                return nums[m];
            }
            else if((nums[m]==nums[m-1] && m%2==1) || (nums[m]==nums[m+1] && m%2==0)) {
                low = m+1;
            }
            else{
                high = m-1;
            }
        }

        return -1;
        
    }
};

// t.c = log(n)
// s.c = o(1)











// 162 find peak element and return index - brute force (arr[i-1]!=arr[i])


class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int x = nums.size();

        if(x==1){
            return 0;
        }

        if(nums[x-1]>nums[x-2]){
            return x-1;
        }

        if(nums[0]>nums[1]){
            return 0;
        }

        int low=1;
        int high = x-2;

        while(low<=high){

            
            if(nums[low]>nums[low+1] && nums[low]>nums[low-1]){
                return low;
                
            }
            else{
                low++;
                
            }
        }
        return -1;

    
    }
};


// another brute force (similar, all statements combined)



class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int x = nums.size();

        for(int i=0;i<x;i++){
            if((i==0 || nums[i]>nums[i-1]) && (i==x-1 || nums[i]>nums[i+1])){
                return i;
            }
        }

        return -1;
    
    }
};



// t.c = o(n)
// s.c = o(1)




// optimal solution

// since we are "searching" for a peak element, binary search could be our option 
// we have an array with sorted tendency (mountain graph)
// some portion is sorted in itself (ascending and dscending)
 

// let us first solve for assumption : array has 1 peak
// if array has just 1 element : return 0;


/*if array has 1 peak, then graph of magnittude of element follow this trend


    /\
   /  \
  /    \
 /      \
/        \


*/

// low   mid   high 
// the peak element will be either at left of mid or right of mid

// [1 2 3 4 5 6 7 8 5 1]
// low=0;high=n-1; we get mid as element = 5;
// now, 5>4 but is 5<6 so we are present on the increasing slope 
// this the peak element is present at right 
// low = m+1; (left search space is eliminated)
// now, new mid is 8, which is 8>7 and  8>5, so its out peak element







// [1 10 13 7 6 5 4 2 1 0]
// mid =6; on decreasing curve 
// high = m-1
// mid = 10; 
// peak on right
// mid = 13
// peak we get 13 at end as 13>10 and 13>7
// avoid edge cases for arr[0] and arr[n-1]
// shrink binary search space by 1 from both side, to avoid overflow cases 



// optimal solution : if 1 peak element only in array 


int f(nums,n){

    if(nums.size()==1){
        return 0;
    }
    if(nums[0]>nums[1]){
        return 0;
    }
    if(nums[n-1]>nums[n-2]){
        return n-1;
    }

    int low=1;
    int high = n-2;

    while(low<=high){

        int mid = low+(high-low)/2;

        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
            return mid;
        }
        else if(nums[mid]<nums[mid+1] ){
            low = mid+1;
        }
        else if(nums[mid-1]>nums[mid]){
            high = mid-1;

        }

    }

    return -1; 
}










int f(arr,n){

while(x<=y){

        }

    return -1;    //since the function as int as return type

}

    // we have offcouse return type inside conditional statement and it will always execute at the end, but since its inside a conditional statement, the program assumes that a condition might never happen
    // so a return statement has to be written

// the code will work even for arrays with multiple peaks,(after some changes) if we eliminate a search space which had peaks, we will be still left with search space that has peaks


// see image binary 5 ss 1

// critical edge case:  [1  5  1  2  1]

// here 1 -> mid 
// 1>2 false , 1>5 false 




