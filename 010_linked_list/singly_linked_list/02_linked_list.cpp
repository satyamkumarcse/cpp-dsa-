/*
arrays are of fixed size, they are allocated memory in stack
the elements of an array are stored in contigous locations 
ie- if index 0 of an int arr is at memory location
index 0 - 1000
index 1 - 1004
index 2 - 1008 
and so on...

size of array is fixed

1D linked list : in one direction, does not remembers or stores whats there in the previous node {prev is not there}
linked list - storing is not done in contigous location, storing can be done anywhere
storing is done in heap
we can store multiple data types like int,double,strings,char similar to arrays, the only difference is that they are not stored in contigous locations and size can be increased or decreased at any movement 


traverse in linked list:

in arrays:
int arr[]={1,2,3,4}
elements are at index 0,1,2,3 .... they can easily be traversed
in linked list: 
as storing is done in heap and is done randomly, we cant simply traverse like a array/list
so for each "node" present in a linked list, inside each node : we have data and next

starting point of a linked list is known as head of the linked list 
let there be a linked list with 4 nodes {1,3,2,5}, notes stored at m1,m2,m3,m4 locations respectively 

head = m1 {data =1, next =m2}
in the 'next' of first node has stored m2 stored in it
next of last node has NULL stored in it
last node also called as tail of the linked list
a sort of link is made (see image)

head = m1 {data =1, next =m2}
m2 {data=3,next=m3}
m3 {data=2,next=m4}
m4 {data=5,next=null}

now if i want to insert a new node at the end, i will change in

m4 : from next = null to next = m5
*/

/*

in stacks, queues linked list is used, arrays cant be used as they are not flexible in size
in real life: used in browsers
*/

/*
each node of linked list store 2 things, data and pointer to the next

since a linked list node has 2 things, int data and int* next, it cant have a one datatype.
we make a self defined data type called as node
node : self defined data type

*/

// self defined datatype syntax 

/*
struct node{
    int data;
    node* next;

    node(int data1,int next1){    // constructor 
        data=data1;
        next=next1;
    }
}
*/



/*
creating a node and making a pointer point to it 
node x = node(2,nullptr)
node* y = &x;

dynamically 
node* y = new node(2,nullptr)
this automatically stores pointer to a memory location
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
// class node{    // use any
    public:
    int data;
    node* next;

    node(int data1,node* next1){    // constructor
        data = data1;
        next = next1;

    }

    node(int data1){   // another constructor
        data = data1;
        next = NULL;
    }

};


int main(){

    vector<int> vec={2,4,5,7};
    
    node *y = new node(vec[0]);
    cout<<y->data;   // prints 2
    cout<<y->next;   // prints 0
}

