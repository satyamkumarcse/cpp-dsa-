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