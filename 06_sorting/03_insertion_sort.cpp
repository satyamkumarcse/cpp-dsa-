/*
INSERTION SORT 

takes an element and places it at its correct place in the sorted region of the array
[14 9 15 12 6 8 13]
take just one element 14, and make an array which just has 14.
[14]
the array is sorted

now take, [14,9]
here, its 9 is not at its correct position. 
so basically you go to the next element and see on the left side, where it shold have been placed, so that the array is sorted.
[9,14]
[9,14,15]
[9,14,15,12] -> not sorted,so sort it.
[9,14,12,15] -> again swap -> [9,12,14,15]
go to the left, till it cant be swapped.
*/

// we take an element from unsorted part and place it at its correct place in sorted part 

/*[14,9,15,12,6,8,13]
[9,14,15,12,6,8,13]
[9,14,15,12,6,8,13]
[9,12,14,15,6,8,13]
[6,9,12,14,15,8,13]
[6,8,9,12,14,15,13]
[6,8,9,12,13,14,15]
*/



#include <bits/stdc++.h>
using namespace std;


void insertionsort(vector<int> &vec1,int x){
    int i,j;

    for(i=0;i<=x-1;i++){
        j=i;
        while(j>0 && vec1[j-1]>vec1[j]){
            int temp = vec1[j];
            vec1[j]=vec1[j-1];
            vec1[j-1]=temp;
            cout<<"run"<<endl;     // to check how many time it runs
            j--;
        }


    }

}

int main(){

    // vector<int> vec1={13,46,24,52,20,9,45,78,12,45,23,56,99,22,11};
    vector<int> vec1={34,54,23,77,12,46,89,33};   // the swapping (while) loop dont run at all {best case O(n)}

    int x = vec1.size();

    insertionsort(vec1,x);
    
    for(auto it : vec1){
         
        cout<<it<<" ";

    }

}

// [5 4 3 2 1]
// time complexity -> for first iteration, we were at 5
// so the loop did not run : 0 times
// when it went to 4, it swapped 1 places
// at 3, 2 places
// at 2, 3 places 
// 1+2+3+4....n -> n(n+1)/2 == nearly n^2
// O(n^2) is time complexity (worst & average case)
// O(n) -> best case



 
