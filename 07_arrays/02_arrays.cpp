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
// brute

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*
int main(){
    int n;
    cout << "rotate an array by n places to the right: enter n ";
    cin >> n;

 

    vector<int> vec = {1,2,3,4,5,6,7};
    // 3 -> 5 6 7 1 2 3 4
    vector<int> temp;

    int x = vec.size();

    
       n = n%x;


    for(int i=0;i<n;i++){
        temp.push_back(vec[x-n+i]);
    }

    for(int i=x-n-1;i>=0;i--){
        vec[i+n] = vec[i];
    }

    for(int i=0;i<n;i++){
        vec[i]=temp[i];
    }

    for(auto ele : vec){
        cout<<ele<<" ";
    }

    return 0;

}
*/

// optimised 



/*
int main(){
    int n;
    cout << "rotate an array by n places to the right: enter n ";
    cin >> n;

 

    vector<int> vec = {1,2,3,4,5,6,7};
    // 3 -> 5 6 7 1 2 3 4
    vector<int> temp;

    int x = vec.size();

    
       n = n%x;

       

       reverse(vec.end()-n,vec.end());
       reverse(vec.begin(),vec.end()-n);
       reverse(vec.begin(),vec.end());


       for(auto ele : vec){
        cout<<ele<<" ";
    }

    return 0;

}
*/







// moving zeroes to the end of the array
// brute approach 

/*
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
*/


// t.c = O(2*n)
// s.c = O(n) as we create a temp array
// if assume no element is 0 then, entire array will be transferred in the temp array occupying n blocks stack space (wotst case)


/*wrong answer as order of non zero elements are not maintained*/
 
/*
int main(){

    vector<int> vec = {1,0,2,3,2,0,0,4,5,1};
    
    int x = vec.size()-1;
    int j = x;

    for(int i=0;i<x;i++){
        if(vec[i]==0){
            int temp = vec[i];
            vec[i]=vec[x];
            vec[x]=temp;
            x--;
        }
    }
    for(auto ele : vec){
        cout<<ele<<" ";
    }

    return 0;

}
*/


/*wrong answer*/
// int main(){

//     vector<int> vec = {1,0,2,3,2,0,0,4,5,1};
    
//     int x = vec.size()-1;
//     int j;
    
//     for(int i=0;i<x;i++){
//         j = i+1;
//         if((vec[i]==0 && vec[j]==0) || (vec[i]!=0 && vec[j]==0)){
        
//            j++;
//         }
//         else if(vec[i]==0 && vec[j]!=0){
//              int temp = vec[j];
//             vec[j] = vec[i];
//             vec[i] = temp;
//         }
//     }

//       for(auto ele : vec){
//         cout<<ele<<" ";
//     }

//     return 0;

// }




/*correct but unoptimised O(n^2)*/


// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){

//     vector<int> vec = {1,0,2,3,2,0,0,4,5,1};
//     int n = vec.size();

//     for(int pass = 0; pass < n; pass++){          // repeat passes
//         for(int i = 0; i < n-1; i++){
//             if(vec[i] == 0 && vec[i+1] != 0){
//                 int temp = vec[i];
//                 vec[i] = vec[i+1];
//                 vec[i+1] = temp;
//             }
//         }
//     }

//     for(auto ele : vec){
//         cout << ele << " ";
//     }

//     return 0;
// }




// optimised answer - optimal

/*
int main(){

    vector<int> vec = {1,0,2,3,2,0,0,4,5,1};
    
    int x = vec.size();
    int j=-1;

    

    for(int i=0;i<x;i++){   // t.c = O(x); x is first index where 0 was found
        if(vec[i]==0){
            j=i;
            break;
        }
    }

    for(int i=j+1;i<x;i++){   // t.c = O(n-x)
        if(vec[i]!=0){
            int temp = vec[i];
            vec[i]=vec[j];
            vec[j] = temp;
            j++;
        }
    }

    for(auto ele : vec){
        cout << ele << " ";
    }

    return 0;


}
*/

// t.c = total is O(n)
// s.c = O(1) (no extra space is used, the existing array is only beign modified)









// linear search 

// arr[]=[6,7,8,4,1,4] ; num=4 (tell first occurence of num = 4)


 /*
int main(){

    vector<int> vec = {1,0,2,3,2,0,0,4,5,1,4};
    
    int x = vec.size(); 

    for(int i=0;i<x;i++){
        if(vec[i]==4){
            cout<<"the first occurence of 4 is at "<<i<<"th index.";
            break;
        }
    }

    return 0;

}
*/










/*union of 2 sorted arrays*/
// brute force

/*
#include <set>     // dont use unordered set, as we need a sorted order
//n1 , n2 are size of set. we cant precisely determine t.c for a set

int main(){

    vector<int> vec1 = {1,1,2,3,4,5};
    vector<int> vec2 = {2,3,4,4,5,6};

    set<int> s1;
    int i=0;

    for(int i=0;i<vec1.size();i++){
        s1.insert(vec1[i]);     //t.c = O(n1logn1)
       
    }

    for(int i=0;i<vec2.size();i++){   //t.c = O(n2logn2)
        s1.insert(vec2[i]);
       
    }

    vector<int> vec3(s1.size());   // vec3 here union array (used to return the ans)

    


    for(auto it : s1){      // t.c = O(n1+n2) worst case
        vec3[i++]=it;      // we cant access element of set vector like s1[i].
    }

    for(auto ele : vec3){

        cout<<ele<<" ";

    }


    return 0;

}
*/

// total t.c = is O((n1 + n2) log (n1 + n2)) + O(n1+n2)
// s.c = O(n1+n2) + O(n1+n2) = O(n1+n2)
// one is used to solve problem, one is used to return the answer.
// extra space is also known as auxiliary space 

// dont use unordered set, as we need a sorted order
//n1 , n2 are size of set. we cant precisely determine t.c for a set




// union of two sorted arrays - optimal 



/*
int main(){

    // vector<int> arr1= {1,1,2,3,4,5};
    // vector<int> arr2= {1,3,4,4,5,6}; 

    vector<int> arr1 = {1,2,2,2,3};
    vector<int> arr2 = {2,2,2,4};

    
    vector<int> unionarr;
    
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0,j=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(unionarr.size()==0 || unionarr.back()!=arr1[i]){
            unionarr.push_back(arr1[i]);
        }
        i++;
        }
        else{
            if(unionarr.size()==0 || unionarr.back()!=arr2[j]){
            unionarr.push_back(arr2[j]);
        }
        j++;
            
        }
        
    }

    while(i<n1){
        if(unionarr.size()==0 || unionarr.back()!=arr1[i]){
            unionarr.push_back(arr1[i]);
        }
        i++;

    }

    while(j<n2){
        if(unionarr.size()==0 || unionarr.back()!=arr2[j]){
            unionarr.push_back(arr2[j]);
        }
        j++;

    }

    for(auto ele : unionarr){
        cout<<ele<<" ";
    }

    return 0;

    // arr1.back() -> last element of the container 


}
*/


// t.c -> O(n1+n2) 
// s.c -> O(n1+n2)  // this space is used for returning the result array 







// **************intersection of two sorted arrays*****************
// brute force (my intuition) (wrong partially)



/*
#include<set>

int main(){


    vector<int> vec1={1,2,2,3,3,4,5,6};

    vector<int> vec2={2,3,3,5,6,6,7};

    vector<int> result;
        set<int> s1;

    for(int i=0;i<vec1.size();i++){
         for(int j=0;j<vec2.size();j++){
            if(vec1[i]==vec2[j]){
                result.push_back(vec1[i]);
                break;
            }
            
         } 

        }

    for(int i=0;i<result.size();i++){
            s1.insert(result[i]);
        }


    for(auto ele : s1){
        cout<<ele<<" ";
    }

        return 0;
    }
*/


// t.c -> O(n1*n2) + O(k log k)
// s.c -> O(k)



// better brute force 


/*
#include<set>

int main(){


    vector<int> vec1={1,2,2,3,3,4,5,6};
    vector<int> vec2={2,3,3,5,6,6,7};
    vector<int> result;

    vector<int> visited(vec2.size(),0);    // using this we avoided set STL CONTAINER 

    for(int i=0;i<vec1.size();i++){
        for(int j=0;j<vec2.size();j++){
            if(vec1[i]==vec2[j] && visited[j]==0){
                result.push_back(vec1[i]);
                visited[j]=1;
                break;
            }
            if(vec2[j]>vec1[i]){
                break;
            }
        }
    }

    for(auto ele : result){
        cout<<ele<<" ";
    }

    return 0;


}
*/

// t.c = O(n1*n2) 
// s.c = O(n2) or O(n1) {if smaller array is visited arry,more optimised by some extent} 


/*
int main(){

    vector<int> vec1={1,2,2,3,3,4,5,6};
    vector<int> vec2={2,3,3,5,6,6,7};
    vector<int> result;


    int i = 0;
    int j = 0;

    int n1 = vec1.size();
    int n2 = vec2.size();


    while(i<n1 && j<n2){

        if(vec1[i]<vec2[j]){
            i++;
        }
        else if(vec1[i]>vec2[j]){
            j++;

        }
        else{
                
            result.push_back(vec1[i]);
            i++;
            j++;
        
    }

}

    for(auto ele : result){
        cout<<ele<<" ";
    }

    return 0;
}
*/



// in intersection, if indices go out of bound, either i or j, then intersection ends.

// t.c -> worst case -> O(n1+n2) 
// this will happen, when i++; increments and then j++ increments (see image)
// s.c -> O(1) -> auxiliary space 
// Memory used to store the final answer is not counted in auxiliary space. 
/*
Auxiliary space = O(1)
Output space = O(k)
Why we do this

Otherwise every algorithm that returns an array would be O(n) space, which makes comparison meaningless.

So we measure only the extra working memory.
*/