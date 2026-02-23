/*
singly linked list - we just stored the data and next pointer
pointer - pointing to the address of the next node

node = [[data][next]]
*/

/*
in case of doubly linked list, we can go in both the direction
node = [[back ],[data],[next]]
the last element and first element of a doubly linked list points to null.
*/


// double linked list - deletion - all cases
#include <bits/stdc++.h>
using namespace std;


struct node{
    public:
    int data;
    node *next;
    node *back;

    node(int data1,node* next1,node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    node(int data1){
        data = data1;
        next = NULL;   // initially both next and back are NULL  
        back = NULL;
    }

};


// conversion of array into doubly linked list 



node* arr_to_2DLL(vector<int> &arr){

    node* head = new node(arr[0]);
    node* prev = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i],NULL,prev);
        prev->next=temp;
        prev=prev->next; 

    }

    return head;

}

void print2dLL(node* head){

    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}

node* delete_head(node* head){

    if(head==NULL){return NULL;}   // if no element in LL
    if(head->next==NULL){    // only one node in LL
        delete head;
        return NULL;
    }
    node* temp = head;
    head=head->next;
    head->back=NULL;
    temp->next=NULL;
    delete temp;

    return head;
 
} 

node* delete_tail(node* head){

    node* temp=head;
    if(head==NULL){return NULL;}   // if no element in LL
    if(head->next==NULL){    // only one node in LL
        delete head;
        return NULL;
    }
    
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
   
    temp->next->back=NULL;
    node* tail = temp->next;
    temp->next=NULL;
    delete tail;

    return head;
    
}



node* delete_kth_ele(node* head,int ele){

    if(head==NULL){return NULL;}
  node* temp=head;
    if(ele==1){
      
        head=head->next;
        if(head!=NULL){
            head->back=NULL;
        }
        delete temp;
        return head;
       
    }

    int count=1;
    while(temp!=NULL && count<ele){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){return head;}
    if(temp->next==NULL){
        temp->back->next=NULL;
        delete temp;
        return head;
   
    }
    temp->back->next=temp->next;
    temp->next->back=temp->back;
    temp->next=NULL;
    temp->back=NULL;

    delete temp;

    return head;
    
    }

// a node will be given, we have to delete it {the given node will not be head of the 2d LL}
void delete_node(node* temp){

    node* prev  = temp->back;
    node* front = temp->next;

    if(front != NULL){
        prev->next=temp->next;
        front->back=temp->back;
        
        temp->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }

    prev->next = NULL;
    temp->back = NULL;
    delete temp;
    return;

}

 
 
int main(){


    vector<int> arr={12,34,50,67,45,67,22,33,44,66};
    node* head = arr_to_2DLL(arr);
    print2dLL(head);

    // node* nhead = delete_head(head);
    // print2dLL(nhead);
    
    // node* thead= delete_tail(head);
    // print2dLL(thead);

    // node* khead = delete_kth_ele(head,1);
    //  print2dLL(khead);

     delete_node(head->next->next);
         print2dLL(head);

    
}