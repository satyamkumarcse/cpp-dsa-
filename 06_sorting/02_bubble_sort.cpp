
/*
bubble sort pushes the maximum element to the last
by swapping with elements present at the adjacent (adjacent swapping)
[13,46,24,52,20,9]
after one complete round of element swapping (outer loop 1 iteration)
the largest element of the array reachers at the last
[13,46,24,52,20,9]
*/



/*
same algorithm will be performed until the entire array is sorted. 
after every round, the larger elements bubble up at the end.  -> thus inner loop goes from n-i-1
thus the loop goes to n -i -1
[13,24,20,4,46,52]   -> the last 2 element are sorted now after 2 rounds
*/


/*
Initial:
[52,13,24,46,20,9]
After Pass 1:
[13,24,46,20,9,52]
After Pass 2:
[13,24,20,9,46,52]
After Pass 3:
[13,20,9,24,46,52]
After Pass 4:
[13,9,20,24,46,52]
After Pass 5:    -> i goes till n-1
[9,13,20,24,46,52]
*/



#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &vec1,int x){

    for(int i=0;i<x-1;i++){
        // int swapped=0;
        for(int j =0;j<x-i-1;j++){
            if(vec1[j]>vec1[j+1]){             // in best case, this condition is false from start itself
                int temp = vec1[j];
                vec1[j]=vec1[j+1];
                vec1[j+1]=temp;
                // swapped =1;
        
            }
            

        }

        // if(swapped==0){
        //     break;
        // }


        cout<<"runs\n";   // for checking how many times it runs (6 times normally, 3 times if we optimise)
    }

}



int main(){


    vector<int> vec1 = {1,2,3,84,5,2,6};
    int x = vec1.size();


    bubblesort(vec1,x);

    for(auto ele : vec1){
        cout<<ele<<" ";
    }

    

}


// if we try to access an index that is not present, a RUNTIME error is thrown 

// time complexity for bubble sort 
// time complexity = O(n^2)  {as its a nested loop}
// O(n^2) is the worst complexity or average complexity 

// for a already sorted array (best case) = O(n)
// the inner loop does not runs, the array is an ascending order 
// there was no need of swap.


// let us optimise the code by some extent 

 

/*
    for(int i=0;i<x-1;i++){
        int didswap =0;
        for(int j = 0;j<x-i-1;j++){

            if(vec1[j]>vec1[j+1]){
                int temp = vec1[j];
                vec1[j]=vec1[j+1];
                vec1[j+1]=temp;
                didswap=1;
        
            }

               if(didswap==0){
                break;
            }

        }
    }
    

 
 // instead of running the loop till end (till i==n-1), if in case the array gets sorted in between, break out of the loop
//  eg - [6 5 4 3 2 1]
// no need to run the outer loop multiple time, after first iteration itself, array gets sorted.





