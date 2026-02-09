// length of longest subarray with sum K [positive elements only in array]

// brute force solution t.c O(n^3)(almost), s.c = O(1)


#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


// int main(){

//     vector<int> vec={1,2,3,1,1,1,4,2,3};
//     int k =3;
//     int x = vec.size();
//     int len=0;
//     int sum=0;
//     int i,j,p;

//     for(i=0;i<x;i++){
        
//         for(j=i;j<x;j++){
//             int sum=0;
            
//         for(p=i;p<=j;p++){

//             sum+=vec[p];

//         }

//             if(sum==k){
//                  len = max(len,j-i+1);
//             }
//         }

//     }

//     cout<<len;

   
//     return 0;
// }





// better brute force t.c = O(n^2),s.c = o(1)





// int main(){

//     vector<int> vec={1,2,3,1,1,1,4,2,3};
//     int k =3;
//     int x = vec.size();
//     int length=0;

//     for(int i=0;i<x;i++){
//         int sum=0;
//         for(int j=i;j<x;j++){

//             sum+=vec[j];

//             if(sum==k){
//                 length = max(length,j-i+1);
//             }

//             if(sum>k){
//                 break;     // for reducing number of unnecessary steps 
//             }
            
//         }
//     }

//     cout<<length;

//     return 0;
// }






// better solution (using hashing)  for arrays with only positives (greater than 0)




// int main(){

    
//     vector<int> vec={1,2,3,1,1,1,4,2,3};
//     int k =3;
//     int x = vec.size();
//     int length=0;
//     long long sum=0;

//     map<long long,int> s1;

//     for(int i=0;i<x;i++){
//         sum+=vec[i];

//         if(sum==k){
//             length = max(length,i+1);
//         }

//         long long presum = sum-k;

//         if(s1.find(presum)!=s1.end()){    // to deal with 0 
//             int len = i - s1[presum];
//             length = max(length,len);
//         }
        
//             s1[sum]=i;
        

//     }
//     cout<<length;


//     return 0;
// }





// with arrays including all number in integer line including zero and negatives
// this is optimal solution


// for arrays with element >=0. this is better solution but not optimal






// int main(){

//     vector<int> vec={-1,5,-1,0,0,3,1,2,-1,-2,3};
//     int k =3;
//     int x = vec.size();
//     int length=0;
//     long long sum=0;
   

//     map<long long,int> s1;    // if it given that there is no internal collisons, we can use unordered_map for t.c = O(n)
//     // otherwise t.c would become o(n^2), so using map is good
//     // in map t.c = o(nlogn)


//     for(int i=0;i<x;i++){
//         sum+=vec[i];

//         if(sum==k){
//             length = max(length,i+1);
//         }

//         long long presum = sum-k;

//         if(s1.find(presum)!=s1.end()){
//             int len = i - s1[presum];
//             length = max(length,len);
//         }
//         if(s1.find(sum)==s1.end()){
//             s1[sum]=i;
//         }

//     }



//     cout<<length<<endl; 
//     cout<<counter;


//     return 0;
// }





// t.c = o(nlogn) (if map) 
// s.c = o(n)




// most optimal solution arrays[non negative elements & including 0]
// two pointer & sliding window technique


// int main(){

    
//     vector<int> vec={1,2,3,1,0,1,1,1,3,3};
//     int k =6; 
//     int x = vec.size();
//     int sum=0;
//     int length = 0;
//     int j=0; 

//     for(int i=0;i<x;i++){
//         sum+=vec[i];

        
//         while(sum>k){                    // this while loop dont run everytime
//             sum = sum - vec[j++];

//         }

//         if(sum==k){
//             length = max(length,i-j+1);
        
//         }

//     }

//     cout<<length<<endl;

    
//     return 0;

// }



// time O(2*n)    and not O(n^2)
/*For two loops with iterators i and j, the time complexity is O(n²) only when, for a given value of i, j runs n times.
But here, whenever j is incremented, i is also incremented.*/
/*If the outer loop runs n times, then in the worst case, the inner loop will run in total n times.
And that is why the time complexity is O(2*n).
If for every value of the outer loop, the inner loop would run n times, then it would be O(n²).*/
// space O(1)





// count of total number of subarrays with sum k 


// wrong answer, only works when all element are strictly positive

// int main(){

    
    // vector<int> vec={1,2,3,1,0,1,1,1,3,3};
//     vector<int> vec={3,1,2,4};
//     int k =6; 
//     int x = vec.size();
//     int sum=0;
//     int j=0;
//     int count=0;


//     for(int i=0;i<x;i++){
//         sum+=vec[i];

//         while(sum>k){
//             sum = sum - vec[j++];
//         }

//         if(sum==k){
//             count++;
//         }

//     }

//     cout<<count;

//     return 0; 

// }







// brute force solution -  count of total number of subarrays with sum k



// int main(){

    
//     vector<int> vec={1,2,3,1,0,1,1,1,3,3};
//     // vector<int> vec={1,0,1,0,1};
//     // vector<int> vec={0,0,0};
//     int k =6; 
//     int x = vec.size();
//     int sum=0;
//     int j=0;
//     int count=0;


//     for(int i=0;i<x;i++){
//         sum=0;
//         for(int j=i;j<x;j++){
//             sum+=vec[j];
//              if(sum==k){
//             count++;
//         }
//         if(sum>k){
//             break;
//         }


//         }

//     }

//     cout<<count;

//     return 0; 

// }






// optimal solution 
// #include <unordered_map> 


// int main(){

    
//     // vector<int> vec={1,2,3,1,0,1,1,1,3,3};
//     // vector<int> vec={1,0,1,0,1};
//     vector<int> vec={0,0,0};
//     unordered_map<int,int> s1;
//     int k =0; 
//     int x = vec.size();
//     int prefixsum=0;
//     int count=0;

//     for(int i=0;i<x;i++){
//         prefixsum+=vec[i];

//         if(prefixsum==k){
//             count++;
//         }

//         if(s1.find(prefixsum-k)!=s1.end()){
//             count+=s1[prefixsum-k];
//         }

//         s1[prefixsum]++;

//     }

//     cout<<count;
//     return 0; 


// }















#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = nums.size();

    int sum = 0;
    int maxSum = INT_MIN;

    int start = 0;
    int arrStart = 0, arrEnd = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        if (sum > maxSum){ 
            maxSum = sum;
            arrStart = start;
            arrEnd = i;
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
