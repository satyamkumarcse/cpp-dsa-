#include <iostream>
using namespace std;

int main(){



//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

// output:
// *****
// *****
// *****
// *****
// *****



    // for(int i=0;i<5;i++){
    //     for (int j=0;j<i+1;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

// output:
// *
// **
// ***
// ****
// *****

    //  for(int i=0;i<5;i++){
    //     for (int j=0;j<i+1;j++){
    //         cout<<i+1;
    //     }
    //     cout<<endl;
    // }

//  output:
// 1
// 22
// 333
// 4444
// 55555



//     for(int i=0;i<5;i++){
//         for(int j=5;j>i;j--){
            
//             cout<<"*";
//         }
//         cout<<endl;

//     }

// output:
// *****
// ****
// ***
// **
// * 



    // for(int i=0;i<5;i++){

    //     for(int j=5;j>i+1;j--){
            
    //         cout<<" ";  
    //     }

    //     for(int k=0;k<2*(i+1)-1;k++){

    //         cout<<"*";
    //     }
        
    //     cout<<endl;

    // }

//     output:
//     *
//    ***
//   *****
//  *******
// *********



//   for(int i=4;i>=0;i--){

//         for(int j=0;j<4-i;j++){
                
//                 cout<<" ";  
//             }

      
//         for(int j=2*(i+1)-1;j>0;j--){

//             cout<<"*";
//         }
//         // by using two variables also this question can be solved. 
//         // This works because j goes out of scope after each inner loop, so you can reuse it.

   
//         cout<<endl;

//     }


//  output:
// *********
//  *******
//   *****
//    ***
//     *



//  for(int i=0;i<5;i++){
//         for(int j=5;j>i+1;j--){    
//             cout<<" ";  
//         }
//         for(int k=0;k<2*(i+1)-1;k++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

//   for(int i=3;i>=0;i--){
//         for(int j=0;j<4-i;j++){       
//                 cout<<" ";  
//             }
//         for(int j=2*(i+1)-1;j>0;j--){
//             cout<<"*";
//         }
//         cout<<endl;
//     }


//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *



// for(int i=0;i<5;i++){
//     for(int j=0;j<i+1;j++){
//         cout<<"*";
//     }
//     cout<<endl;
// }


// for(int i=4;i>0;i--){
//     for(int j=0;j<i;j++){
//         cout<<"*";
//     }
//     cout<<endl;
// }


// output:

// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *

    int r;

    cout<<"enter number of rows you want: ";
    cin>>r;
    
    // for(int i=1;i<=r;i++){
        
    //     for(int j=0;j<i;j++){

    //         cout<<(i+j)%2;
          
    //     }
    //     cout<<endl;

    // }


// output:
// 1
// 01
// 101
// 0101
// 10101



    // for(int i=1;i<=r;i++){
    //     for(int j=1;j<=i;j++){

    //         cout<<j;
            
    //     }

    //     for(int k=0;k<2*r-2*i;k++){
    //             cout<<" ";
    //         }

    //     for(int j=i;j>0;j--){

    //         cout<<j;
            
    //     }

    //     cout<<endl;

    // }

// output:
// 1      1
// 12    21
// 123  321
// 12344321




    // int sum=0;
    // for(int i=1;i<=r;i++){

    //     for(int j=0;j<i;j++){

    //         sum+=1;
    //         cout<<sum<<" ";
    //     }
        
    //     cout<<endl;

    // }


    // char x = 'A';

    //  for(int i=1;i<=r;i++){

    //     for(int j=0;j<i;j++){
    //           cout<<char (x+i-1);
          
    //     }
    //            cout<<endl;
 
    // }

//     output:
// A
// BB
// CCC
// DDDD
// EEEEE



    // char x = 'A';

    //  for(int i=1;i<=r;i++){

    //     for(int j=0;j<i;j++){
    //           cout<<char (x+j);
          
    //     }
    //            cout<<endl;
 
    // }

    

//  output:
// A
// AB
// ABC
// ABCD
// ABCDE
























    return 0;
}