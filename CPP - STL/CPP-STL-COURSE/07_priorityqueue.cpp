#include <bits/stdc++.h>
void explainPQ(){

    // main fxn - push,top,pop

    //in a priority queue, largest value will(char,int,string) stay on top by default ie- max heap  by default
    //the following is not a linear data structure. a tree datastructure is maintained.
    // the data is not stored in a linear fashion basically

    priority_queue<int> pq;
 


    pq.push(5);       // top = 5   // {5}   
    pq.push(17);      // top = 17   // {17,5}
    pq.push(11);      // top = 17   // {17,11,5}
    pq.emplace(4);    // top = 17    // {17,11,5,4}

    pq.pop();    //pops 17 (the topmost element)


    cout<<pq.top();  // prints 11


    // minimum priority queue - min heap
    //  syntax : priority_queue<datatype,vector<int>,greater<int>> pq;

    priority_queue <int,vector<int>,greater<int>> pq;
    pq.push(5);   // {5}
    pq.push(2);   // {2,5}
    pq.push(8);  // {2,5,8}
    pq.emplace(10);   // {2,5,8,10}

    cout<<pq.top(); // prints 2

}

// time complexity 
// increases to log n from 1. sorting algorithm is involved. 
// push -> log(n)
// top -> o(1)
// pop -> log(n)