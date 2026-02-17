// find duplicates in an array

// brute solution (nested 2 for loop) - TLE

// better solution : 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int x = nums.size();

        unordered_map<long long,int> m1;

        for(int i=0;i<x;i++){
            m1[nums[i]]++;

        }

        for(auto it : m1){
            if(it.second>1){
                return it.first;
            }
        }

    
        return -1;
      
    }
};

// t.c & s.c is O(n)


