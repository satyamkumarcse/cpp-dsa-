// program to return frequency of a element of array.





#include <iostream>
using namespace std;

// int frequencycount(int arr[],int x){
//     int count=0;

//     for(int i=0;i<10;i++){
//         if(arr[i]==x){
//             count++;
//         }
//     }
//     return count;
// }

// int main(){

//     int arr[10]={1,2,3,2,1,3,4,4,3,2};
//     int x = 1;

//     int y=frequencycount(arr,x);

//     cout<<"frequency of "<<x<<" is "<<y;

//     return 0;
// }





 

// above we founded the frequency of 1 element, for which the for loop was running 10 times. 
// so for all 10 elements, loop will run 100 times or in general O(N^2)





// for a program to give frequency of all the elements, not only one.
// time complexity -> 10*O(n);   {as there is a for loop}

// in case of a very large dataset or array, its inefficent
// assume there are 10^5 elements, and thus   for   loops runs for 10^5 times
// time complexity -> O(10^10);



// for 10^8 operations -> 1 sec 
// so for 10^10 -> 100 sec
// for such situations, hashing is suitable




// HASHING -> is defined as a process where pre-storing and fetching of something happens.

// used when we require some sort of frequency restoring algorithms
// the number of computations reduced.


// This is not hashing.
// This is a simple nested loop frequency count. Hashing means using direct indexing or a hash table to avoid the inner loop


// int hashfrq[100000];


int main(){

    int arr[5]={1,3,2,1,3};
    int check[5]={1,4,2,3,12};


    int hashfrq[100000]={0};    // the following is called as a hash array


    for(int i=0;i<5;i++){

              hashfrq[arr[i]]+=1;

        }

        
    for(int i=0;i<5;i++){

        cout<<"frequency of "<<check[i]<<" is "<<hashfrq[check[i]]<<endl;

    }
        
      

    }


// in the above example, the hash array had around till 13 elements.
// but there can be cases when a we have 10^9 to 10^15 numbers. 
// an array of 10^9+1 size has to be declared then, but is not feasable 


// max size of array that can be declared inside main(){} is 10^6. of int type. for bool array -> 10^7
// declaring an array larger than that will throw segmentation fault.

// array size can go near 10^7+1 if declared globally (for int array)
// for bool array declared globally, 10^8.

// if an array is declare globally, no need to write {0}
// int arr[1000];



  



   
    








 