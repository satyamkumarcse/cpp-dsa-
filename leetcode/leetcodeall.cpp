#include <bits/stdc++.h>

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
                count++;
                ele /= 10;
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



// palindrome best case - 9

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



// 35. Search Insert Position - brute force


class Solution {
public:
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
        }

        return vec;
    }
};


// best 0ms - optimal


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
//  977 - squares of sorted array - wrong ans 

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



// best soln 0ms sorted squares 

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
        }

        return vec;
    }
};



// toupper or tolower functions works only on single string character.

string s = "HeLLo"; 

for (char &c : s) {
    c = tolower(c);
}


// best 0ms - 709. To Lower Case 



class Solution {
public:
    string toLowerCase(string s) {

        int x = s.length();

        for(int i=0;i<x;i++){
            if(65<=s[i] &&  s[i]<=90){
                s[i]+=32;
            }
        }
        return s;
        
    }
};

// ASCII - 65-90 (A-Z)  &   97-122 (a-z) 

// valid palindrome - brute force
   
class Solution {
public:
    bool isPalindrome(string s) {

        int x = s.length();
        string result = "";

        // Convert uppercase to lowercase
        for (int i = 0; i < x; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }

        // Keep only lowercase letters and digits
        for (int j = 0; j < x; j++) {
            if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')) {
                result += s[j];
            }
        }

        string final_result = "";

        // Reverse result (correct length)
        for (int k = result.length() - 1; k >= 0; k--) {
            final_result += result[k];
        }

        return final_result == result;
    }
};



//  valid palindrome - brute force using builtin functions


class Solution {
public:
    bool isPalindrome(string s) {

        
        int x = s.length();
        string result="";
        string final_result = "";


            for(int k=0;k<x;k++){
                if(isalnum(s[k])){
                    result+=tolower(s[k]);
                }
            

        }

         for(int l=result.length()-1;l>=0;l--){
            final_result +=result[l];

        }

        return (final_result == result);
    }
};


// brute force - without using build in functions



class Solution {
public:
    bool isPalindrome(string s) {

        
        int x = s.length();
        string result="";
        string final_result = "";

            
            for(int g=0;g<x;g++){
                if(s[g]>=97 && s[g]<=122){

                    result+=s[g];
                }
                else if(s[g]>=65 && s[g]<=90){

                    result+=s[g]+32;
                }
                else if(s[g]>='0'&&s[g]<='9'){
                    result+=s[g];
                }
            }
        
        for(int l=result.length()-1;l>=0;l--){
            final_result +=result[l];

        }

        return(final_result == result);
    }
};


// best soln 0ms 


class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.length()-1;

        while(i<j){

            if(!isalnum(s[i])){
                i++;
                continue;
 
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }

            if(tolower(s[i])!=tolower(s[j])){
                return false;     // there is no need to check further
            }
            i++;
            j--;

        }

        return true;
        
    }
};



// one more best 0ms 


class Solution {
public:
    bool isPalindrome(string s) {

        int i=0;
        int j = s.length();

        while (i < j) {

    while (i < j && !isalnum(s[i])) i++;
    while (i < j && !isalnum(s[j])) j--;

    if (tolower(s[i]) != tolower(s[j])) {
        return false;
    }

    i++;
    j--;
}
return true;
        
    }
};



// Why this is optimal
// Single pass over the string
// No extra strings or arrays
// Uses two pointers
// Stops early on mismatch

// Handles:
// Uppercase and lowercase
// Digits
// Spaces and symbols

// Time complexity: O(n)
// Space complexity: O(1)

// How this improves your brute force logic

// Your version:

// Creates two extra strings
// Reverses the string manually
// Uses more memory
// Always processes full input

// This version:

// Compares only what is needed
// Skips junk characters directly
// Exits immediately on failure




// prefer functions like alnum and tolower , toupper

// over 

// if ((s[i] >= 'a' && s[i] <= 'z') ||
// (s[i] >= 'A' && s[i] <= 'Z') ||
// (s[i] >= '0' && s[i] <= '9'))





// length of last word - 58 
// wrong soln

class Solution {
public:
    int lengthOfLastWord(string s) {

        int x = s.length();
        int length=0;

        for(int i=0;i<x;i++){

            if(s[i]==' '){
                length=0;
                continue;
            }
            else if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122){       // except spaces " " was asked. i wrote for alphabets (upper & lower case). also no temp vble used to store.
                length++;
            }
        }
        return length;
    
    }
};


// brute force soln 


class Solution {
public:
    int lengthOfLastWord(string s) {

        int x = s.length();
        int length=0;
        int temp=0;
        

        for(int i=0;i<x;i++){

            if(s[i]==' '){
            
                
                length=0;
                continue;
            }
            else if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122){
                length++;
                
            }
            temp = length;
        }
        return temp;
    
    }
};

// problem with the brute force ans
// we only care about the last word, but:
// You process every character, even those that cannot affect the answer.
// Characters before the last word are useless to compute.


// best optimal 


class Solution {
public:
    int lengthOfLastWord(string s) {

        int x = s.length()-1;
        int length=0;

        while(x>=0 && s[x]==' '){
            x--;
        
        
        }
        while(x>=0 && s[x]!=' '){
            
            length++;
            x--;
            
        }
        return length;
        

        
    }
};


// 344 reverse string - 0ms - best 

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




//  242 - valid anagram 

// Two strings are anagrams if:
// They have the same length
// Each character appears the same number of times in both strings

// visible test cases passed : wrong answer code (we are not keeping track of what variables have been used and how many times)
class Solution {
public:
    bool isAnagram(string s, string t) {

        int x = s.size();
        int y = t.size();
        int i,j;
        vector <int>vecs(x);
        vector <int>vect(y);
        bool anagramm;
        for(int i=0;i<x;i++){
            vecs[i]=s[i];     // we were not keeping map : eg "aabbbc"  and   "aabbcc" will return true but they are not

        }
        for(int j=0;j<x;j++){
            vect[j]=t[j];

        }

        if(x==y){

             for(int k=0;k<x;k++){
            for(int m=0;m<x;m++){

                if(vecs[k]!=vect[m]){
                    anagramm=false;
                    continue;       
                }
                else{
                    anagramm = true;
                    break;
                    
                }
                
      
            }
            
                
            }

            
        }
       
            return anagramm;
           
            
           
        }   
    
};


// best answer - 0ms


class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()){
            return false;
        }

        int arr[26]={0};

        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            
        }

        for(int j=0;j<t.size();j++){
            arr[t[j]-'a']--;
            
        }

        for(int k=0;k<26;k++){
            if(arr[k]!=0){
                return false;
            }
        }
        return true;
        
    }
};