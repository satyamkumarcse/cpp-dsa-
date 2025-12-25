// sorting algorithm 

// for sorting an array 
// we have a simple function : sort()
// sort(arr,arr+n)      // end not include


// suppose we have an array {1,8,5,3}
// we will pass a pointer, which is pointing at start

// sort(arr,arr+n)           {arr+n-1}  -> points at the last element.



// in case of array


//  #include <bits/stdc++.h>
//  using namespace std;

//  int main(){

//     int arr1[5] = {2,8,4,10,7};
//     sort(arr1,arr1+6);

//     for(int ele : arr1){

//         cout<<ele<<" ";
//     }


//     return 0;
//  }


// in case of stl vector

// sort(vec1.begin(), vec1.end())
// sort(vec1.begin(), vec1.end(), greater<int>())



 
//  #include<bits/stdc++.h>
//  using namespace std;

//  int main(){

//     vector<int> vec = {1,3,5,4,0,9,7};     
//     //sort(vec.begin(),vec.end());       // vec.begin() -> its an iterator pointing at 1st ele location.
//     // vec.end() -> ending iterator.
//     sort(vec.begin(),vec.end(),greater<int>());
//        for(int ele : vec){

//         cout<<ele<<" ";
//     }
 
//     // output : sorting in ascending order

 
//     return 0;
//  }

// for sorting in descending order 
// we pass a comparator or functor

// by default the comparison logic (comparator) inside sort() fxn is in ascending order
// greater<int>()  -> sorts in dscending




//for a vector container having pair inside it 




//  #include<bits/stdc++.h>
//  using namespace std;

//  int main(){

//     vector<pair<int,int>> vec = {{3,1},{2,1},{7,1},{5,2}};

//     sort(vec.begin(),vec.end());
//     for(auto p : vec){

//         cout<<p.first<<" "<<p.second<<endl;
//     }

//     // output:
//     // 2 1
//     // 3 1      // by default sorting happends on basic on first value 
//     // 5 2
//     // 7 1



//     return 0;
//  }


// if i want the sorting to happen on the basis of second value
// then we need to define a custom comparator function.
// comparators -> these are boolean functions that return true/false based upon some comparasions
// then pass comparator as third arguement in sort fxn.





//  #include <bits/stdc++.h>
//  using namespace std;

// bool comparator(pair<int,int> p1,pair<int,int> p2){

//     if(p1.second<p2.second){return true;}
//     else{return false;}
// }

//  int main(){
//     vector<pair<int,int>> vec={{3,6},{2,4},{7,4},{5,4}};

//     sort(vec.begin(),vec.end(),comparator);

//     for(auto ele : vec) {
//         cout<<ele.first<<" "<<ele.second<<endl;
//     }

 
   /*using comparator concept, sorting done on the basis on second value
   output:
    5 2
    7 3
    2 4
    3 6
   */


//     return 0;
//  }

//  in the comparator function we will pass 2 instances of pair
// say... p1 p2
// now we will write the logic to sort these pair on the basis on second parameter(value)

//  {a,b} {c,d}
// if p1.second<p2.second
// return true
// else return false 



// if second values of multiple pairs are equal then sorting to be done on the basis of first


 #include <bits/stdc++.h>
 using namespace std;

bool comparator(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second){return true;}
    if(p1.second>p2.second){return false;}

    if(p1.first<p2.first){return true;}
    else{return false;}
}


 int main(){

     vector<pair<int,int>> vec={{3,6},{2,4},{7,4},{5,4}};

    sort(vec.begin(),vec.end(),comparator);

    for(auto ele : vec) {
        cout<<ele.first<<" "<<ele.second<<endl;
    }



    return 0;
 }