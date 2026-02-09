// find missing element in an array. (N-> total element after including missing element)



     /*
     typical constraits in such questions 

    [3, 1, 4, 5]       // unsorted
    [1, 2, 3, 4]        // nothing missing
    [2, 3, 4, 5]        // missing at start
    [1, 2, 3, 4, 6]     // missing at end

    */


// brute force solution 


#include <iostream>
#include <vector>


using namespace std;

// int main(){

//     int N;
//     cin>>N;

//     int arr[N-1]={1,2,5,7,6,3};

//     for(int i=1;i<=N;i++){ 
//         int flag=0;
//         for(int j=0;j<N-1;j++){
//             if(arr[j]==i){
//                 flag=1;
//             }
//         }
//         if(flag==0){
//             cout<<i;

//         }
//     }

//     return 0;
// }


/*

t.c = O(n*n) -> worst case when missing element present at end.
s.c = O(1) 

*/


// better solution 
 


// int main(){
//       // x = 5, i<4 , i=1,2,3

//      vector<int> vec={1,2,3,5,6,4,8};
//      int x = vec.size()+1;
//      vector<int> hash(x+1,0);
   


//      for(int i=0;i<x-1;i++){
//         hash[vec[i]]=1;
//      }

//      for(int i=1;i<=x;i++){
//         if(hash[i]==0){
//             cout<<i;
//             break;
//         }
//      }
     
//     return 0;
// }


    /*better solution is to use hashing, assume the missing number to be found is between 1 to 5, then we have to declare an hash array till index 5. ie array of size 6 is declared.*/

    /*
    t.c = O(2*n)
    s.c = O(n) -> as we used a hash array*/



// optimal solution (2 optimal solutions are there)




// int main(){
//       // x = 5, i<4 , i=1,2,3
//       int x;
//       cin>>x;

//      vector<int> vec={1,2,3,5};

//      int y = x*(x+1)/2;
//      int sum=0;

//      for(auto ele : vec){
//         sum+=ele;
//      }

//      cout<<y-sum;

     

// }


   

// t.c ->  O(n)
// s.c ->  O(1)
// assume x = 10^5. then sum of first 10^5 numbers is nearly more than 10^10. can cause overflow in case of large input.
//  although we can datatype like long but eventually more memory is used(8 byte).




// more better optimal solution (with XOR concept)


// xor operation will never exceed the number itself. eg wont exceed 10^5 
// XOR = a^a = 0 
// if we XOR two numbers, we will get 0
// 2^2 = 0 
//  5^5 = 0
//   2^2^5^5 = 0
// 2^2^2^2^2 = 0^2 = 2

// 0^n -> n   // zero XOR with any number is the number itself 


// xor1 = 1^2^3^4^5
// xor2 = 1^2^4^5 
// xor1^xor2 = (1^1)^(2^2)......(4^4)^3 = 0^3 = 3 (the missing number)





// int main(){

//     int x;
//     cin>>x;

//     int arr1[x-1]={1,2,3,4,5,6,7,8,10};   // dont use arr[x-1] in general, use vector<int> vec, as arr[x-1] not good practice in c++

//     int xor_all=0;

//     for(int i=1;i<=x;i++){
//         xor_all = xor_all^i;
//     }


//     for(int i=0;i<x-1;i++){
//         xor_all=xor_all^arr1[i];
//     }

//     cout<<xor_all;

//     return 0;
// }





// maximum consecutive ones 


/*
typical constraints:

{1,1,1,1,1}
{0,0,0,0}
{1,0,1,0,1,0}
{1}
{0}
{1,1,1,0,1,0}
{0,1,0,1,1,1,1}
{0,0,1,1,1,1,0,0}
{1,1,0,1,1,1,1,0,1,1}
{}
{1,0,1,0,1}
{1,0,1,1,0,1,1,1,1,1,0,1}

*/

// brute force (not required to explain, directly jump to explain better)




// int main(){

//     vector<int>vec={0,1,0,1,1,1,1};

//     vector<int>temp;
//     int j=0;


//     for(int i=0;i<vec.size();i++){

//         if(vec[i]==0){
//             temp.push_back(j);
//             j=0;

//         }
//         else{
//             j++;
//         }
//     }

//     temp.push_back(j);
//     int max = -1;

//     if(temp.size()!=0){

//           for(auto ele : temp){
//         if(ele>max){
//             max=ele;
//         }
//     }
//       cout<<max;
//     }
//     else{
//         cout<<j;
//     }

//     return 0;

// }



// 







#include <algorithm>
#include <climits>


// int main(){

//     vector<int>vec={0,1,1,1,0,1,1,1,1,1,1,0};
//     int maxi=0;
//     int counter=0;

//     for(int i=0;i<vec.size();i++){
//         if(vec[i]==1){
//             counter++;
//             // maxi = max(counter,maxi);    // both will work
//             if(counter>maxi){
//                 maxi = counter;
//             }
//         }
//         else{
//             counter=0;
//         }

//     }

//     cout<<maxi;


//     return 0;
// }








// an array have elements, all appear twice, except one element, find that element 




/*brute - Your nested loop: O(n²) time, O(1) space - simplest brute force
*/



// int main(){

//     vector<int> arr={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};

//     int x = arr.size();
    

//     for(int i=0;i<x;i++){
//         int count =0;
//         int temp = arr[i];
//         for(int j=0;j<x;j++){
//             if(arr[j]==temp){
//                 count++;

//             }
//         }
//         if(count==1){
//             cout<<temp;
//             break;
//         }
        
//     }
//     return 0;

// }





// better solution (self thought) - Hash array: O(n) time, O(max_element) space - faster but space issue




// int main(){

//     vector<int> vec1={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};

//     int max=INT_MIN;

//     for(auto ele : vec1){     // O(n) -> depending on the input size(if large) this approach may or may not be good. thus we go with map data structure. map<long long,int>




//         if(ele>max){
//             max = ele;
//         }
//     }

//     vector<int> hash(max+1,0);

//     for(int i=0;i<vec1.size();i++){
//         hash[vec1[i]]+=1;


//     }

//     for(int i=0;i<hash.size();i++){
//         if(hash[i]==1){
//             cout<<i;
//             break;
//         }
    
//     }
//     return 0;
// }

// t.c = O(3*n)
// s.c = O(max_element) -> depends on input


// more better solution using map datastructure
#include <map> // -> ordered 
// but which one?


// ordered_map - t.c = o(nlogm) for inserting elements
// WHERE n -> array length, m -> map size : (N/2+1) 



// unordered_map - t.c = o(n) {best,avg} , but worst O(n^2) 
// if the element which appears once is present at end or critical cases (hash collisions etc)
// MENTION I 



// int main(){

//       vector<int> arr={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};

//      int x = arr.size();

//      map<long long,int> m1;    // long long is used, as element can be very large

//      for(int i=0;i<x;i++){   // O(Nlog(N/2+1)) -> for inserting in map
//         m1[arr[i]]+=1;

//      }

//      for(auto it : m1){
//         if(it.second==1){
//             cout<<it.first;    // O(N/2+1) 
//             break;
//         }
//      }

// // t.c = O(Nlog(N/2+1)) + O(N/2+1) 

     
//     return 0;
// }






// optimal solution 

// int main(){

//      vector<int> arr={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};

//      int x = arr.size();

//      int xor_num=0;

//      for(int i=0;i<x;i++){
//         xor_num=xor_num^arr[i];
//      }

//      cout<<xor_num;

//     return 0; 
// }

// // t.c - O(n)
// // s.c - O(1)
 

  