/*

memory space used by linked list

inside a node we store data and a pointer

assuming we are storing data in a 32 bit system, 
int -> 4 bytes
 * -> 4 bytes

so total : 8 bytes occupied in memory space

64 bit sysem,

int -> 4 bytes
 * -> 8 bytes

total : 12 bytes

*/



//implementation of linked list from arrays;
// in leetcode etc, we will just return the head of a linked list, not the entire linked list


#include <bits/stdc++.h>
using namespace std;

struct node{

    public:
    int data;
    node* next;

    node(int data1,node* next1){
        data = data1;
        next = next1;
    }


    node(int data1){
        data = data1;
        next = NULL;
    }

}; 



node* convertarrtoLL(vector<int> &vec){

    node* head = new node(vec[0]);
    node* mover = head;    // we directly dont move head, it will delete elements 

    for(int i=1;i<vec.size();i++){    // t.c = o(n) as we are traversing
        node* temp = new node(vec[i]);
        mover->next = temp;   // initially mover->next = NULL 
        mover = temp;
    }

    return head;
}



// traversing through a linkedlist 
// 2 -> 3 -> 1 -> 8 -> NULL
//head  
// first rule : never tamper/mode head of a LL
// because if me move the head of a LL, eg- if we move it to 2nd node, we will forget or delete the first node


// length of a LL : head is given 
int lengthofLL_traversingLL(node* head){
    int count=0;
    node*temp=head;
     while(temp!=NULL){

        cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    
    }

    return count;

}

bool search_in_a_LL(node *head,int target){

    node*temp = head;
    while(temp!=NULL){

        if(temp->data==target){
            return true;

        }
        temp=temp->next;


    }

    return false;


}



int main(){
    vector<int> vec={12,34,11,6,4};

    node* head = convertarrtoLL(vec);
    cout<<head->data<<endl;

    int x = lengthofLL_traversingLL(head);  // both has t.c = o(n)
    cout<<x<<endl;

    bool g = search_in_a_LL(head,12);    // t.c =  o(n)
    cout<<g;

    return 0;
}



//anywhere, if its written you're given with a linked list, you will be given with the head of the LL
// in all questions, we will do some operation on the linked list and return head of the linked list after modifying it