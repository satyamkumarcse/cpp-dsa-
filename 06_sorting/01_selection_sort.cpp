// selection sort 

// step 1

/*
we select minimums
[13,46,24,52,20,9]
in an array, search for minimum element. the minimum element is 9. take that 9 and place it on first index. 
the element present at the first place will go to the place of 9
array becomes : [9,46,24,52,20,13]
*/


// step 2
/*we are certain that the starting portion of the array is sorted, which is till 9. -> [9,46,24,52,20,13]
lets try to sort the remaining part
in rest of the array 13 is minimum
13 comes at the first place (of unsorted part)
array becomes : [9,13,24,52,20,46]
*/


// repeat, get the next minimum and swap if the first element of the unsorted region 

/*

steps 1 to 5:

13  46  24  52  20  9
9  13  24  52  20  46
9  13  20  52  24  46
9  13  20  24  52  46
9  13  20  24  46  52

*/ 


// At every step, you assume the first unsorted element is the minimum, then scan the rest of the array to find the true minimum, and swap it into place.

#include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &vec1,int x){

    
    for(int i=0;i<x-1;i++){
        int min = i;
        int j;
        for(j=i+1;j<x;j++){
            if(vec1[j]<vec1[min]){
                min = j; 
            }
        }
        int temp = vec1[i];
        vec1[i]=vec1[min];
        vec1[min]=temp;

    }

}





int main(){

    vector<int> vec1={13,46,24,52,20,9};

    int x = vec1.size();

    selectionsort(vec1,x);
    
    for(auto it : vec1){
         
        cout<<it<<" ";

    }

}

// time complexity 
// O(n^2) -> best,worst & average case 
 