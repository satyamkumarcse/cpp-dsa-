

// brute force - here means a solution written by me, which works but is not fully optimised.

// 1672. Richest Customer Wealth - brute force 


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int count=0;
        for(auto ele = accounts.begin() ; ele != accounts.end() ; ele ++){
            vector<int> vecx = *(ele);
            
            int x = 0;
            for(auto ele : vecx){
                x+=ele;
            }
            if(x>count){
                count = x;
            }

            
        }
        return count;
        
    }
};

// "slower" or "badly optimized" is purely due to memory copying

// problematic line 
// vector<int> vecx = *(ele);
// this allocates new extra memory in the space
// copying of data from 1 vector to other
// the vector vecx is deleted after the loop terminates
// thus slower and not optimised
// if there were 1000 elements the program would become slow





// 0ms solution 

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {


        int sum=0;
        int tempsum=0;
        for(int i=0;i<accounts.size();i++){

            int j = accounts[i].size();
        tempsum=0;
            for(int k=0;k<j;k++){

                tempsum+=accounts[i][k];

            }

            if(tempsum>sum){
                sum=tempsum;
            }

            
        }
        return sum;
        
    }
};

// this solution is more optimised because it just access the elements using 
// accounts[i][k];
// no new vector is made, no copying, no deletion 







// 1295. Find Numbers with Even Number of Digits-  brute force 

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result_count = 0;

        for (auto ele : nums) {
            int count = 0;            // we should make a temp vble instead of directly modifying the ele as it create copies. just for clarity.

            while (ele > 0) {
                int x = ele % 10;     // unused variables not good 
                ele /= 10;
                count++;
            }

            if (count % 2 == 0) {
                result_count++;
            }
        }

        return result_count;
    }
};


//  optimised 0ms 

class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int x = nums.size();
        
        int result_count = 0;

        for(auto ele : nums){
            int count=0;
            int temp = ele;
        if (temp==0){count=1;};

            while(temp>0){
            
                temp/=10;
                count+=1;
            }

            if(count%2==0){
                result_count+=1;
            }
            
        }
        return result_count;
        
    }
};





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

// if i am searching for an element in an unordered map in c++. if i write x.find(n) where n is element. if element is present an iterator is returned otherwise x.end() is returned.

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





// 1572. Matrix Diagonal Sum - brute force 

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        
        int x = mat.size();
        int sum=0;
        if(x%2==1){

             for(int i=0;i<x;i++){
                sum+=mat[i][i];
                if(i!=(x-1)/2){
                sum+=mat[i][x-i-1];


                }
    }
            
                  
        }
        else{
            for(int k=0;k<x;k++){
                sum+=mat[k][k];
                sum+=mat[k][x-k-1];
            }
            
           
        }
        return sum;
    }
};


// 0ms best 



class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        
        int x = mat.size();
        int sum=0;
        

             for(int i=0;i<x;i++){
                sum+=mat[i][i];
                
                sum+=mat[i][x-i-1];     
    }

    if(x%2!=0){
        sum-=mat[(x-1)/2][(x-1)/2];
    }         
       
        return sum;
    }
};



// 724. Find Pivot Index : brute force 



class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        
        int x = nums.size();
       

        for(int i=0;i<x;i++){
             int sum1=0;
             int sum2=0;

            for(int j=0;j<i;j++){
                sum1+=nums[j];

            }
            for(int k=i+1;k<x;k++){
                sum2+=nums[k];
            }
            if(sum1==sum2){
                return i;
            }

        }
        return -1;

  
    }
};



//  best answer 0ms

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalsum=0;
         int leftsum=0;
        
        
        int x = nums.size();
        

        for(auto ele : nums){

            totalsum+=ele;
            
        }

        for(int i=0;i<x;i++){
        
          
            int sumright = totalsum - leftsum - nums[i];
            

            if(leftsum==sumright){
                return i;
            }
              leftsum+=nums[i];
            

        }

        return -1;
    
    }
};



// 1991. Find the Middle Index in Array -0 ms 


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalsum=0;
        int x=nums.size();
        for(auto ele : nums){
            totalsum+=ele;

        }

        int leftsum=0;
    

        for(int i=0;i<x;i++){


            int rightsum = totalsum - leftsum - nums[i];

            
            if(leftsum==rightsum){
                return i;
            }

            leftsum+=nums[i];


        }
        return -1;


        
    }
};





// 121. Best Time to Buy and Sell Stock



class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int x = prices.size();
        int diff = 0;

         for(int i=0;i<x;i++){
            for(int j=i+1;j<x;j++){
                if(prices[j]-prices[i]>diff){
                    diff = prices[j]-prices[i];
                }
                


            }
            
         }

         return diff;
        

        
    }
};



//  best 0ms 


// INT_MAX is used to safely initialize a variable when you want to track a minimum value.
// int x = INT_MAX;        x = largest possible value that can be stored by x integer;


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minprice = INT_MAX; 
        int profit = 0;


        for(int i=0;i<prices.size();i++){

            minprice = min(minprice,prices[i]);
            profit = max(profit,prices[i]-minprice);

        }

        return profit;

        
    }
};


//  best time to buy stock is when price is minimum
// best time to sell, when profit is max.

<<<<<<< HEAD


// 35. Search Insert Position - brute force
=======
// 1732. Find the Highest Altitude





//  brute force 

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x = gain.size();

        vector<int> vec1(x+1);

        vec1[0]=0;
        int sum=0;
        for(int i=1;i<=x;i++){
            sum+=gain[i-1];
            vec1[i]=sum;
        }
        int max=-(INT_MAX);


        for(int j=0;j<x+1;j++){
            if(vec1[j]>max){
                max = vec1[j];
            }
        }
        return max;
    
        
    }
};


// 0ms best optimal 
// initialize current  to 0. in case if all the sum's values are negative 0 will be returned.
// otherwise peak will be returned.
>>>>>>> 746414b48f48fcf6567d776337169d00b1a499b4


class Solution {
public:
<<<<<<< HEAD
    int searchInsert(vector<int>& nums, int target) {

        int x = nums.size();
        for(int i=0;i<x;i++){
            if(target==nums[i]){
                return i;
            }
            else{
                if(target<nums[i]){
                    return i;
                }
                

            }
        }
        return x;
        
    }
};



// 0ms best o(log n)  binary search 



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l=0;
        int u = nums.size()-1;
        int midval;

       

        while(l<=u){
            midval = l+(u-l)/2;
            if(nums[midval]==target){
                return midval ;
                

            }
            else if(target>nums[midval]){
                l = midval + 1;
            }
            else if(target<nums[midval]){

                u = midval-1;
            }
        }
        return l;


        
    }
};


// insert is a costly fxn as it shifts all elements by 1 index. but inserting at the end of an array is amortised to O(1)
// insert(vec.begin(),4)  -> O(n)
// when inside a loop -> O(n^2)  (costly kind off)




// 66. Plus One -  brute force (only visible 3 cases pass) overflow/runtime


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int x = digits.size();
        int result;
        string s = "";

        for (int i = 0; i < x; i++) {
            s += digits[i] + '0';
        }

        result = stoi(s);
        result += 1;

        vector<int> vec;
        while (result > 0) {
            int k = result % 10;
            vec.insert(vec.begin(), k);
            result /= 10;
=======
    int largestAltitude(vector<int>& gain) {

        int x = gain.size();
        int sum=0;
        int current =0;

        for(int i=0;i<x;i++){
            sum+=gain[i];
            if(sum>current){
                current =sum;
            }
        

            
        }
        return current;
        
    }
};


// reverse a string - 0ms best


class Solution {
public:
    void reverseString(vector<char>& s) {

        int i = 0;
        int j = s.size()-1;
        while(i<j){

            char x = s[i];
            s[i]=s[j];
            s[j]=x;
        
            i++;
            j--;

        }
        

        
    }
};







// brute force - 977. Squares of a Sorted Array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int x = nums.size();
        for(int i=0;i<x;i++){

            nums[i]=pow(nums[i],2);
        }

        sort(nums.begin(),nums.end());    // time com = O(n log n)
        return nums;
    }
};

// 0 ms best 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int x = nums.size();
        vector<int> vec(nums);

        int leftside = 0;
        int rightside = x - 1;
        int idx = x - 1; 

        while (leftside <= rightside) {

            int l = nums[leftside] * nums[leftside];
            int u = nums[rightside] * nums[rightside];

            if (l > u) {
                vec[idx] = l;
                leftside++;
            } else {
                vec[idx] = u;
                rightside--;
            }

            idx--;
>>>>>>> 746414b48f48fcf6567d776337169d00b1a499b4
        }

        return vec;
    }
};


<<<<<<< HEAD
// best 0ms - optimal
=======
// wrong code 
>>>>>>> 746414b48f48fcf6567d776337169d00b1a499b4


class Solution {
public:
<<<<<<< HEAD
    vector<int> plusOne(vector<int>& digits) {

        int x = digits.size();

        for(int i=x-1;i>=0;i--){

            if(digits[i]<9){
                digits[i]++;
                return digits;

            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
        
        
    }
};


// in C++ a char is an integer data type
// string x = "";
// x += (5 + '0');
// x += (6 + '0');


/*
eg- 

vector<int> plusOne(vector<int>& digits) {
    int x = digits.size();
    int result;
    string s = "";

    for (int i = 0; i < x; i++) {

        s += digits[i] + '0';

    }
}


*/
=======
    vector<int> sortedSquares(vector<int>& nums) {
        
        int x = nums.size();
        vector<int>vec(nums);
        int leftside = 0;
        int rightside = x-1;
        int idx = 0;

        while(leftside<=rightside){

            int l = nums[leftside]*nums[leftside];
            int u = nums[rightside]*nums[rightside];

            if(u>l){
                vec[idx]=l;
                leftside++;

            }
            else{
                vec[idx]=u;   // wrong : The ends contain the largest absolute values, so their squares are the largest, not the smallest.
                  rightside--;
            }
            
          
            idx++;
            
        }

        

        
        return nums;
    }
};
>>>>>>> 746414b48f48fcf6567d776337169d00b1a499b4
