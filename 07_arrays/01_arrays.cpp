// flow of an answer : brute -> better -> optimal 

/*
array is a data structure which can have elements of any datatype such as int,char,string,pair<int,int> etc.
but arrays should be homegenous
*/



/*if we define an array of size (eg-6)  inside int main(){}; ie- locally
an array of some garbage value is defined.
all the positions inside the array that we have created will be stored with some garbage values.

but, if we define an array globally, all 6 element positions will be filled with 0.

int arr2[6]; (global)



int main(){

    int array1[6];  (local)
    
}

max array size can be 10^6 when declared locally 
10^7 globally

*/


/*
where is array stored in the computer's memory?

whenever we declare an array of size x, x blocks are created in the computer's memory

the first block is stored in some random Y memory location

element stored at index 0  = x (memory address)
element stored at index i  = x + i*k (memory address)
where, k is byte occupied by each element (depends on datatype)


*/


// ******* Q1) largest element in an array *********

/*brute force solution : sort the array then print the element present on the last index. 

if we use merge sort then t.c = O(n log n)  
*/

/* a better answer dont exist or is irrelevant, lets move to optimal solution
an optimal solution will reduce the t.c from O(n log n)
*/



// optimal solution : t.c = O(n)



#include <iostream>
#include <vector>
using namespace std;


/*
int main(){

    std::vector<int> vec = {3,2,1,5,2};
    int x = vec.size();

    int largest = vec[0];

    for(int i=0;i<x;i++){
        if(vec[i]>largest){
            largest = vec[i];
        }

    }

    std::cout<<largest;

    return 0;
}
*/







// ******* Q) second largest element in an array*********

// brute force solution : tc -> O(n log n + n)  (merge sort + for loops)


/*

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec1,int low,int mid,int high){
       vector<int> vec2;
   
    int p1 = low;
    int p2 = mid+1;

    while(p1<=mid && p2<=high){
        if(vec1[p1]<=vec1[p2]){
            vec2.push_back(vec1[p1]);
            p1++;
        }
        else{
            vec2.push_back(vec1[p2]);
            p2++;
        }
    }

    while(p1<=mid){
        vec2.push_back(vec1[p1]);
        p1++;
    }

    while(p2<=high){
        vec2.push_back(vec1[p2]);
        p2++;
    }


    for(int i=low;i<=high;i++){
        vec1[i]=vec2[i-low];
    }

 
}





void mergesort(vector<int> &vec1,int low,int high){

    if(low>=high){
        return;
    }

    int mid = low+ (high-low)/2;

    mergesort(vec1,low,mid);
    mergesort(vec1,mid+1,high);
    merge(vec1,low,mid,high); 


}


int main(){

    vector<int> vec1={1,4,2,7,5,7,6};
    int low=0;
    int high = vec1.size()-1;
  

    mergesort(vec1,low,high);

     int largest = vec1[high];
     int largestt;


    for(int i=high-1;i>=0;i--){
        if(vec1[i]!=largest){
            largestt = vec1[i];
            cout<<largestt;
            break;

        }

    }

    return 0;
}


*/





// better solution :  first pass longest approach 



/*
 int main(){


     vector<int> vec1={1,4,2,7,5,7,6,9,8};
     int largest = vec1[0];

     for(int i=0;i<vec1.size();i++){     // O(n)

        if(vec1[i]>largest){
            largest = vec1[i];
        }


     }
     int slargest = -1;     // (if array contains negative elements) take INT_MIN

     for(int i=0;i<vec1.size();i++){    // O(n)

        if(vec1[i]>slargest && vec1[i]<largest){

            slargest = vec1[i];


        }
     }

     cout<<slargest;




    return 0;
 }
*/


// t.c = O(n + n) = O(2n) approach
// we traverse the array twice and get the largest in the first pass, and second largest in the second pass







// optimal approach : second largest



/*

#include <climits>
int main(){

    std::vector<int> vec = {12,13,24,15};
    int x = vec.size();
    int slargest= INT_MIN;
    int largest = vec[0];

    
    for(int i=1;i<x;i++){
        

        if(vec[i]>largest){
            slargest = largest;
            largest = vec[i];
           
        }
        else if(vec[i]<largest && vec[i]>slargest){
            slargest = vec[i];
        }
    
    }
    
     std::cout<<slargest;

    return 0;
}

*/




// finding second smallest


/*#include <climits>

int main(){

    vector<int> vec={18,15,10,24,12};

    int secsmallest = INT_MAX;
    int smallest = vec[0];
    int x = vec.size();

    for(int i=1;i<x;i++){

        if(vec[i]<smallest){
            secsmallest = smallest;
            smallest = vec[i];
        }
        else if(vec[i]>smallest && vec[i]<secsmallest){

            secsmallest = vec[i];

        }
    }

    cout<<secsmallest;

    return 0;
}
*/

// t.c = O(n) as only one pass is done









// ******* Q)check if an array is sorted  *********

// no requirement of brute-better-optimal as its a small/straight forward question



/*
int main(){

    vector<int> vec1 = {1,2,3,84,5,2,6};
    // vector<int> vec1 = {1,2,3,4,5,6};
    int x = vec1.size();
    bool sorted=true;


    for(int i=0;i<x-1;i++){
        if(vec1[i]>vec1[i+1]){
            sorted = false;
            break;
        }

    }

    if(sorted){
        cout<<"the array is sorted from the start itself\n";
    }
    else{
        cout<<"the array was NOT sorted from the start";
    }


}
*/


// t.c = O(n);









// ******* Q) remove duplicate elements in place from an SORTED array *********

// brute force soln 


/*You are given a sorted array, and you must:
Remove all duplicate elements
Keep only unique elements at the beginning of the array
print number of elements that were unique */


// first intuition is to use set data structure (as it holds only unique elements pairs)

// set stores in ascending order


#include <set>

// int main(){

//     int arr1[7]={1,1,2,2,2,3,3};

//     set<int> s1;

//     for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++){
//         s1.insert(arr1[i]);
//     }
    
//     for(auto ele : s1){

//         cout<<ele<<" ";

//     }

//     cout<<endl;

//       cout<<"number of unique elements are "<<s1.size();

//     return 0;

// }



    
// t.c analysis
/*

in order to insert elements in a set, set takes O(log n) time
O(n) for iterating and printing using auto

total - O(nlogn)

s.c 

imagine if all the elements were unique, then all elements would be inserted and would occupy memory of n blocks
s.c - worst is O(n)


*/



// optimal solution -> 2 pointer approach (in that particular array itself)




int main(){

    int j=0;
    int i;

    int arr1[7]={1,1,2,2,2,3,3}; 

    for(i=1;i<7;i++){
        if(arr1[j]!=arr1[i]){
            arr1[j+1]=arr1[i];
            j++;
 

        }

    }

    cout<<j+1;
    



}

/*

t.c -> O(n)
sc - O(1) , as we are doing modifications in the particular array itself

*/