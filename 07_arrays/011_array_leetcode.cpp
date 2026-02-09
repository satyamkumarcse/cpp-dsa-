nums.back() is the last element of the array.


inplace meaning - 
Modify the same array that is given to you
Do not use another array for the result (only O(1) extra space)



26. Remove Duplicates from Sorted Array (inplace)



// brute (not inplace)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int x = nums.size();

        vector<int> result;
        int count=0;
        int i=0;

        while(i<x){

            if(result.size()==0 || result.back()!=nums[i]){
                result.push_back(nums[i]);
                count++;
                
            }
            i++;


        }

        for(int i=0;i<count;i++){
            nums[i]=result[i];
        }
        
        return result.size();
        
        
    }
};



// optimised - best solution 


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int x = nums.size();
        int count=1;
        int i=1;
        while(i<x){

            if(nums[i-1]!=nums[i]){
                nums[count]=nums[i];
                count++;
                
            }
            i++;

        }

        return count;  
        
    }
};


// 
// Code
// 189. Rotate Array to the right - brute 


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int x = nums.size();

        vector<int> temp;

        k = k%x;


        for(int i=0;i<k;i++){
            temp.push_back(nums[x-k+i]);

        }

        for(int i=x-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }

        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }

        return;
    }
};



// optimised solution - 0ms 

class Solution {
public:
    void rotate(vector<int>& vec, int k) {

        int x = vec.size();

        k = k%x;

        reverse(vec.begin(),vec.begin()+x-k);
        reverse(vec.begin()+x-k,vec.begin()+x);
        reverse(vec.begin(),vec.begin()+x);

        return;
    }
};



// move zeroes brute 


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int x = nums.size();
        int i=0;
        int j=-1;

        for(i=0;i<x;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        for(int i=0;i<x;i++){
            for(int j=1;j<=x-i-1;j++){
                if(nums[j-1]==0 && nums[j]!=0){
                    int temp = nums[j];
                    nums[j]=nums[j-1];
                    nums[j-1]=temp;

                }

            }
        }

        return;
   
    }
};



// move zeroes better 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int x = nums.size();
        
        int j=0;

        for(int i=0;i<x;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
             if(i==x-1){
                return;
        }

        }
        for(int i=j+1;i<x;i++){
            if(nums[i]!=0){
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;
            }
        }
        
        return;

    }
};


// best - optimal 