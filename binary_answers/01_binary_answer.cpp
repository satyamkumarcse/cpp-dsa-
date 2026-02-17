// maximum integer whose square is <=n



// floor concept : 
// eg-  6.2 => 6
// 5.8 => 5


//  brute force 

#include <iostream>
#include <vector>
using namespace std;

// int main(){

//     int n = 28;
//     int ans =1;
//     int i;

//     for(i=1;i<=n;i++){

//         if(i*i<=n){
//             ans=i;
//         }
//         else{
//             break;
//         }
//     }

//     cout<<ans;
    

//     return 0;
// }
// t.c = o(n)



// optimal solution - binary search 





// int main(){

//     int n = 28;


//     int l =1;
//     int h = n;
//     int m=0;
//     int ans=1;
    
//     while(l<=h){

//         m = l+(h-l)/2;

//         if(m*m>n){
//             h = m-1;
//         }
//         else if(m*m<=n){
//             ans = m;
//             l=m+1;
//         }
        

//     }

//     cout<<h;
//     // cout<<ans;


// }



/*

   ✓   ✓   ✓   ✓   ✗   ✗   ✗   ✗   ✗
   1   2   3   4   5    6    7   8    9


   after the termination case, low always points on first cross, high on first tick

   
*/


// binary search on answer
/*general idea is that you will always know a range of answers,in above exmaple it was asked to find floor of sqrt of n*/

// minimum/maximum/floor/ceil 
// answer range
// use binary search






// find nth root of m (if not integer return -1)
#include <cmath>


int main(){

    int n=3;
    int M=27;

    int l=1;
    int h=27;
    int m=0;
    int ans=-1;

    while(l<=h){

        m = l+(h-l)/2;

        if(m<=pow(M,pow(n,-1))){
            ans=m;
            l=m+1;

        }
        else{

            h=m-1;
            
        }


    }

    cout<<ans;

    return 0;
}


// binary search can be implemented on any search space which is monotonic in nature (ie- linearly increasing or decreasing)

// eg- monotonic incresing fxn : 1 - 1,2 - 8,3 - 27,4 - 64
// wherever the answer lies becomes the search space


