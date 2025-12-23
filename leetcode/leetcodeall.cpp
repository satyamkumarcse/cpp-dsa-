
// brute force 1470. Shuffle the Array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> vec1;
        
        for(int i=0;i<n;i++){
            vec1.push_back(nums[i]);
            vec1.push_back(nums[i+n]);

        }

        return vec1;

    }

    
};

// best case 

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> result(2 * n);
        

        for(int i = 0; i < n; i++) {
            result[2 * i] = nums[i];
        
            result[2 * i + 1] = nums[i + n];
        }
        
        return result;
    }
};

// Direct Indexing vec[i]=nums[i]     tc - O(1)
// push_back -  tc -  average may be more than o(1). worst is o(n)



// two sum brute force 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int x = nums.size();

        for (int i = 0; i < x; i++) {
            for (int j = i + 1; j < x; j++) {

                if (nums[i] + nums[j] == target) {
                    return {i, j};      // directly return
                }
            }
        }

        return {}; // if no result found
    }
};

// remember one approach, if you want to iterate through all the elements of a list. you can do it using nested loop.
// but if its said to do it using a single loop, then try doing the same thing (iterate through all the elements of a list) using single loop.




// 0 ms- best approach 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x = nums.size();
        unordered_map<int,int> st;
        for(int i=0;i<x;i++){
            int n;
            n = target - nums[i];
            if(st.find(n)!=st.end()){
                return {i,st[n]};

            }
            st[nums[i]]=i;
        }
        
    return {};
    }
};





// BRUTE FORCE 1480 RUNNING SUM OF 1D ARRAY

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) { 

        int x = nums.size(); 
        
        vector<int> result(x);

        for(int i=1;i<=x;i++){
            int sum=0;

            for(int j=0;j<i;j++){

                sum+=nums[j];

            }
            result[i-1]=sum;

        }
        return result;

        
    
    }
};


// best case 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int x = nums.size();
        vector <int> result(x);
        int sum=0;
        for(int i=0;i<x;i++){

            sum+=nums[i];
            result[i]=sum;

        }

        return result;

    }
};



// LeetCode 1920: Build Array from Permutation.

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {

        int x = nums.size();
        vector<int> result(x);

        for(int i=0;i<x;i++){
            result[i]=nums[nums[i]];

        }
        return result;

        
    }
};


// array concatenation 1929 best case 

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

    
        int x = nums.size();
        vector <int> result(2*x);
        
        for(int i=0;i<x;i++){

            result[i]=nums[i];
            result[i+x]=nums[i];


        }

        return result;

        
    }
};



// palindrome bast case - 9

class Solution {
public:
    bool isPalindrome(int x) {
        while(x<0){

            return false;
        }

        int original = x;
        int number=0;
        

        while(x>0){
            int digit = x%10;
            number = number*10 + digit;
            x=x/10;


        }
        return number==original;
        
    }
};

// 1480 running  Sum of 1d Array - bestcase 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int x = nums.size();
        vector <int> result(x);
        int sum=0;
        for(int i=0;i<x;i++){

            sum+=nums[i];
            result[i]=sum;

        }

        return result;


    }
};


// 1431. Kids With the Greatest Number of Candies - best 0ms 

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        bool highest_candies;
        int x = candies.size();
        vector<bool> vect(x);
        int max=0;
        for(auto ele : candies){
            if(ele>max){
                max = ele;
            }

        }
        for(int i=0;i<x;i++){
            if(candies[i]+extraCandies>=max){

                vect[i]=true;

            }
            else{

                vect[i]=false;
                
            }
        }
        return vect;
    }
};

// can also be used to find max ele.
auto it = max_element(v.begin(), v.end());


