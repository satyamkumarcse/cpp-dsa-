// two sum - brute force 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){

                if(nums[i]+nums[j]==target){

                    vector<int> result;
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return {};
        
    }
};


// two sum - optimal 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> m1;  // hashing approach 

        for(int i = 0; i < nums.size(); i++){
            int y = target - nums[i];

            if(m1.find(y) != m1.end()){
                return {m1[y], i};
            }
            else{ m1[nums[i]] = i;
            }



        }

        return {};
    }
};


// in two sum question, i just want to tell whether the indexes are present or not that sum to to the element, i dont want to return them

// routine answer 

        int x = nums.size();
        int left=0;
        int right=x-1;

        sort(nums.begin(),nums.end());

        while(left<right){
            if(nums[left]+nums[right]>target){
                right--;
            }
            else if(nums[left]+nums[right]<target){
                left++;
                
            }
            else{
                cout<<"yes";
                return;
            }
        }

        cout<<"no"

        








// majority element 


// brute force solution 


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x =nums[0];
        int count=0;
       for(int i=0;i<n;i++){


        count=1;

        for(int j=i+1;j<n;j++){

            if(nums[j]==nums[i]){
                count++;
                
            }
           
        }
         if(count>n/2){
                return nums[i];
                
            }



       }

       return x;
    
    }
};







// better solution 1.0 


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x =0;
        unordered_map<int,int> hash;

        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }

        for(auto it:hash){
            if(it.second>n/2){
                x = it.first;
                
            }
        }

     
        return x;
        

        
    }
};



// better solution - 2.0 (slightly better)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x =0;
        unordered_map<int,int> hash;

        for(int i=0;i<n;i++){
            hash[nums[i]]++;
            if(hash[nums[i]]>n/2){
                return nums[i];
            }
        }

    return x;
        

        
    }
};

// t.c = O(n) + O(n)
// or
// t.c = O(nlogn) + O(n) (if map is used)
// s.c = O(n) wosrt case only when all array elements are unique




// optimal solution - Moore's voting algorithm






class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = nums.size();
        int y;
        int count=0;

        for(int i=0;i<x;i++){
            
        if(count==0){
            count=1;
            y = nums[i];
        }
        else if(y == nums[i]){
            count++;
        }
        else{
            count--;
        }


        }
        int counter=0;

        for(int i=0;i<x;i++){
            if(nums[i]==y){
                counter++;
            }
            if(counter>x/2){
                return y;
            }
        }

        return -1;  

    }
};


// see screenshort
// [7 7 5 7 5 1 5 7 5 5 7 7 1 1 1 1] -> this has no majority element and will return 1, altho this will never happen as per questions constraints.

// [7 7 5 7 5 1 5 7 5 5 7 7 5 5 5 5] -> 5 is majority as it has   >n/2 appearance





// sort colours - inplace



// brute force - merge sort 


class Solution {
public: 
       void merge(vector<int>& nums,int low,int mid,int high){
            int p1 = low;
            int p2 = mid+1;
            vector<int> vec2;

            while(p1<=mid && p2<=high){
                if(nums[p1]>=nums[p2]){
                    vec2.push_back(nums[p2]);
                    p2++;
                }
                else{
                    vec2.push_back(nums[p1]);
                    p1++;
                }


            }

            while(p1<=mid){
                 
                    vec2.push_back(nums[p1]);
                    p1++;
                }
            

            while(p2<=high){
            
                    vec2.push_back(nums[p2]);
                    p2++;
            
            }

             for(int i=low;i<=high;i++){
                nums[i]=vec2[i-low];
            }
        };


        
    void sort(vector<int>& nums,int low,int high){

        if(low>=high){
            return;
        }

    int mid = low + (high-low)/2;

    sort(nums,low,mid);
    sort(nums,mid+1,high);
    merge(nums,low,mid,high);

    };

    void sortColors(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        sort(nums,low,high);


    }
};

// t.c = O(nlogn)
// s.c = o(n)



// better - since there is only 0,1,2 (given) in array. make 3 counters 


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x = nums.size();
        
    
        int c1=0;
        int c2=0;
        int c3=0;

        for(int i=0;i<x;i++){  //o(n)
            if(nums[i]==0){
                c1++;
            }
            else if(nums[i]==1){
                c2++;
            }
            else{
                c3++;
            }
        }

        for(int i=0;i<c1;i++){    //o(n1)
            nums[i]=0;
            
        }
        for(int i=c1;i<c1+c2;i++){  //o(n2)
             nums[i]=1;
        }
        for(int i=c1+c2;i<c1+c2+c3;i++){    //o(n3)
             nums[i]=2;
        }

        
        
    }
};

// n1+n2+n3 = n
// t.c = o(n) + o(n1+n2+n3) = o(n) + o(n) = o(2*n);
// s.c -> O(1)









// optimal solution -> dutch national flag algorithm  

// t.c = o(n)
// 3 pointer approach : low,mid,high
// [0......low-1] -> are zeroes. (extreme left)
// [low......mid-1] -> are ones. 
// [high+1......n-1] -> are twos. (extreme right)

// 3 rules are there 


// 0   low-1  low    mid-1    mid    high  high+1     n-1

// 00000000    111111111      0/1/2/0/2/1    2222222222222



// when we start with the question, we will be having an unsorted array with us, thus starting index is pointed by mid pointer, last index by high.
// if at starting index (mid) if we 0 


/*if 0 : low++; mid++;   swap(a[low],a[mid])
  if 1 : mid++;    
  if 2 : high--;   swap(a[mid],a[high])

  when mid becomes greater than high, mid>high. the area which we are sorting is over now. we get the sorted array.
*/


// why low and mid both point at index 0 , during starting 

/*At any moment:

indices [0 .. low-1] contain only 0s
indices [low .. mid-1] contain only 1s
indices [mid .. high] are unsorted
indices [high+1 .. n-1] contain only 2s


Why low = 0 and mid = 0 initially

At the beginning:

No 0s placed yet
No 1s placed yet
No elements examined yet

So:

The 0s region is empty
The 1s region is empty
The unsorted region starts from index 0

That means both low and mid must point to the first unprocessed element, which is index 0.*/


// t.c = O(n) : after n iteration, all n elements are sorted (linear)
// s.c -> o(n) 


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0;int mid = 0;int high = n-1;

        while(mid<=high){

            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
    
        }
    }

};




// 53 subarray with largest sum


// brute force - TLE (exceeded)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int x = nums.size();
    
        int sum=0;
        int temp=INT_MIN;
        

        for(int i=0;i<x;i++){
            sum = 0;
        
            for(int j=i;j<x;j++){
                sum+=nums[j];
                
                if(sum>temp){
                    temp=sum;
                }
                
            }
    
        }
       
        return temp;
        
    }
};


// t.c = o(n^2)
// s.c = o(1)







// optimal solution - kadane's algorithm
// assumptions - assume the maximum sum is non negative.



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int x = nums.size();
    
        int sum=0;
        int temp=INT_MIN;
    
        for(int i=0;i<x;i++){
            sum+=nums[i];
            
            if(sum<0){
                sum=0;
            }

            temp = max(temp,sum);

        }
       
        return temp;
        
    }
};


// t.c = o(n)
// s.c = o(1)



// print subarray with maximum sum (there can be multiple sub arrays)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = nums.size();

    int sum = 0;
    int maxSum = INT_MIN;

    int start = 0;
    int ansStart = 0, ansEnd = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        if (sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray: ";

    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

// t.c = o(n)
// s.c = o(1)