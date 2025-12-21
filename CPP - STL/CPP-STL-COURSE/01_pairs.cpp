#include <bits/stdc++.h>   // includes all the header files present in c++

// c++ stl is divided into four parts

// algorithm 
// containers --> (vector/queue/set/map)
// functions 
// iterators 


// pairs 

pairs are a part of utility library 

void explainpair(){

    int a=2;   // for storing a single integer

    pair<int,int> p = {1,3};        // for storing couple of integers
    /*
    if i want to store 1 & 3, i can only store it in a pair.
    int,int datatype of both elements (1,3)
    you can use any datatype (int,string,char)
    */

    cout<<p.first<<" "<<p.second;   

    /*
    it i want to access the individual integers or anything stored in a pair.
    */

    pair <int,pair<int,int>> p = {1,{3,4}};    // for storing 3 v'bles
    // first element --> int datatype
    // second element --> pair datatype (can store a pair in itself)

    cout<<p.first<<" "<<p.second.first<<" "<<cout<<p.second.second;
    //output : 1,  3,4

    /*
    till now we were declaring array as 
    int arr[]={1,2,3};
    string arr[4];
    char arr[]={"hi","hello"};
    */

    // for declaring pair array 
    pair<int,int> arr[] = {{1,2},{3,4},{6,8}} 
    cout<<arr[1].second;
    // - index 0,1,2
    // by looking at all examples pairs can de treated as a datatype
    // present in utility header file
