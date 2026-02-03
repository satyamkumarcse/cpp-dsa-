// left rotate the array by one place (without using any one array)


/*
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int arr[5]={1,2,3,4,5}; 
    // output : 2,3,4,5,1
    int x = sizeof(arr)/sizeof(arr[0]);

    int temp = arr[0];

    for(int i=1;i<x;i++){
        
        arr[i-1]=arr[i];

    }

    arr[x-1]=temp;

    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
*/




// t.c - O(n) 
// s.c - O(1); since no extra space is used by making any new array or something, were making modifications in the array itself.
// what is the space that we are using to solve the problem?
// O(n) : as we are using an array of n element in our algorithm
// what is the extra space youre using?
// O(1) : no extra space 

/*
the extra space im using is O(1), but in order to solve this problem, im using this following array ([1,2,3,4,5]) ie- O(n) space is beign used */







// left rotate an array by d places 



/*wrong answer*/

/*
int main(){
    int n;
    cout<<"rotate an array by n places: enter n ";
    cin>>n;
    
    int arr[7]={1,2,3,4,5,6,7};

    int x = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        int temp = arr[i];
        arr[i]=arr[x-i-1];
        arr[n+i]=temp;
 
    }

    // for(int i=2*n;i<x;i++){
    //     arr[2*i-x]=arr[2*i]   
    // }

    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}

*/




// explanation
// observe that rotating by 7 times, returns back to its original state 
// 9 rotations = 7 + 2  (just do 2)
// 15 = 7 + 7 + 1  (just do 2)


// so technically, whatever d is given to you, doesnt matter 
// number of rotations = d%x    (x is array size (total index + 1))
    

// brute force approach 
// the elements that will be affected due to shift, put them in a array named as temp.




// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     int n;
//     cout << "rotate an array by n places: enter n ";
//     cin >> n;

//     vector<int> vec = {1,2,3,4,5,6,7};
//     int x = vec.size();

//      n = n % x;   // important

//     vector<int> temp; 

//     // store first n elements
//     for(int i = 0; i < n; i++){
//         temp.push_back(vec[i]);
//     }

//     // shift left
//     for(int i = 0; i < x - n; i++){
//         vec[i] = vec[i + n];
//     }

//     // copy back
//     for(int i = 0; i < n; i++){
//         vec[x - n + i] = temp[i];
//     }

//     for(auto ele : vec){
//         cout << ele << " ";
//     }

//     return 0;
// }




// t.c = O(n) + O(x-n) + O(n) = O(n+x);
// extra space used is O(n) -> cause we used a temp array to store values  whose indexes where beign replaced (1,2,3) 
// s.c = O(n);







// optimal solution -> avoids O(n) extra space use 





/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void reverse(vector<int> &vec,int start,int end);



int main(){
    int n;
    cout << "rotate an array by n places: enter n ";
    cin >> n;

    vector<int> vec = {1,2,3,4,5,6,7};
    int x = vec.size();
    int end = vec.size()-1;
    int start = 0;

    n = n%x;

    reverse(vec,start,n-1);
    reverse(vec,n,x-1);
    reverse(vec,start,x-1);

    

    // reverse(vec.begin(),vec.begin()+n);
    // reverse(vec.begin()+n,vec.begin()+x);      //build in c++ stl libraries (or create user defined)
    // reverse(vec.begin(),vec.begin()+x);

    for(auto ele : vec){
        cout<<ele<<" ";
    }

    return 0;

}


void reverse(vector<int> &vec,int start,int end){


    while(start<=end){
        int temp = vec[start];
        vec[start] = vec[end];
        vec[end] = temp;
        start++;
        end--;
        
    }

}
*/










// dry run


        // reverse(arr,arr+n)
        // reverse(arr+n,x)
        // reverse(x,arr)

        /* t.c = O(n)+O(x-n)+O(x) = O(2*x)   (t.c increases tradeoff)
        s.c = O(1) (no extra space) */


/*
c++ stl feature for reverse 

#include <algorithm>
reverse(arr.begin(),arr.end());
or arr+n,arr+d etc...
*/



// rotate array by d places to right (hw)






// moving zeroes to the end of the array

#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> vec = {1,0,2,3,2,0,0,4,5,1};
    int j=0;
    int x = vec.size();
    vector<int> temp;

    for(int i=0;i<x;i++){
        if(vec[i]!=0){
            temp.push_back(vec[i]);
 
        }
        else{
            j++;
        }
    }

    for(int i=0;i<j;i++){
        temp.push_back(0);
    }

    for(int i=0;i<x;i++){
        vec[i]=temp[i];
    }

    for(auto ele : vec){
        cout<<ele<<" ";
    }

    return 0;
}


// t.c = O(2*n)
// s.c = O(n) as we create a temp array
// if assume no element is 0 then, entire array will be transferred in the temp array occupying n blocks stack space.

