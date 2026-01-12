
// multiple recursion calls
// n number of recursion calls happening inside a  function  

/*


f(){


    f()
    f()
    f()..... and so on
     
}


*/

// fibbonaci using recursion




// int fib(int x){
    

//     if(x<=1){

//         return x;

//     }

//     int last = fib(x-1);
//     int slast = fib(x-2);

//     return last + slast;
    
    
// }


// int main(){

//     int x;
    
//     cout<<"write till which N you want to find fib(N): ";
//     cin>>x;

//     int y = fib(x);
//     cout<<y;

    
// }




// multiple recursion calls are beign made here within the fib fucntion 
// these calls dont happen simultaneously 
// first f(n-1) call goes and come back 
// then f(n-2) call goes and come back 
// so basically it happens line by line, whichever recursion call is made first is executef first (is fib recursion screenshort)
// see recursion tree fib ss 
 

// take example of fib(n=4)
// f(4)->f(3)->f(2)->f(1)-> base case hit 


// time complexity - O(2^n) near about 2^n not exactly 
// exponential in nature basically
// (observe tree)












// now where is multiple recursion call concept used?
// its used when asked to print all "subsequences"
// the order of the given array should be followed to be a subsequence


/*

First, consider an array:

A = [3, 7, 1, 9, 4]

Subsequence
A subsequence is a sequence formed by selecting some elements from the array in the same order as they appear. You may skip elements, but you cannot change the order of the remaining ones.

Examples of subsequences:
[3, 1, 4]
[7, 9]
[3, 7, 1, 9, 4] (the entire array)
[9]

Non examples:
[7, 3] (order changed, so not a subsequence)

Contiguous (continuous) subsequence
A contiguous subsequence means the selected elements must be next to each other in the array with no gaps. This is also commonly called a subarray.

Examples of contiguous subsequences:
[3, 7]
[7, 1, 9]
[1]
[9, 4]

Non contiguous subsequence
A non contiguous subsequence is simply a subsequence where skipped elements exist.

Examples:
[3, 1, 4] (skipped 7 and 9)
[7, 4] (skipped 1 and 9)

[] -> empty set is also a subsequence 

*/ 


// let [3,1,2] be an array 
// [3,2] is a subsequence 


/*





code flow:
Include 3 → f(1, [3])
Include 1 → f(2, [3,1])
Include 2 → f(3, [3,1,2]) → base case prints [3,1,2]
Exclude 2 → f(3, [3,1]) → base case prints [3,1]
Exclude 1 → f(2, [3])
Include 2 → f(3, [3,2]) → prints [3,2]
Exclude 2 → f(3, [3]) → prints [3]

Exclude 3 → f(1, [])
Include 1 → f(2, [1])
Include 2 → f(3, [1,2]) → prints [1,2]
Exclude 2 → f(3, [1]) → prints [1]
Exclude 1 → f(2, [])
Include 2 → f(3, [2]) → prints [2]
Exclude 2 → f(3, []) → prints []
 */


/*
outputs: 

3 1 2
3 1
3 2
3
1 2
1
2
{}
*/

 

//   for each and every index we have 2 options, either take or not take. & a for loop
// so, time complexity is O(2^n * n)
// space complexity -> O(n) as, at max N number of function calls will wait

#include <bits/stdc++.h>
using namespace std;

#include <vector>
void subsequence(int ind,int n,int arr1[],vector<int> &vec1){

    if(ind == n){

         if(vec1.size()==0){
        cout<<"{}"<<endl;
    }

        for(auto it: vec1){
            cout<<it<<" ";
          
        }
        cout<<endl;
        return;
        
    }
   

    vec1.push_back(arr1[ind]);
    subsequence(ind+1,n,arr1,vec1);
    vec1.pop_back();
    subsequence(ind+1,n,arr1,vec1);



}



int main(){
    
    int arr1[5]={3,1,2,4,6};
    int n=5;

    vector<int> vec1;

    subsequence(0,n,arr1,vec1);


    return 0;
}



