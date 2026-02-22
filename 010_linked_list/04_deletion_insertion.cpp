/*

1 -> 8 ->9 -> 3 -> null 

let is be a linked list, and you are told to delete the head {first element} of the linked list.
we can simply move head to the 2nd node, and free up the memory occupied by first node and thus delete it.

*/

/*
node* deletehead(node* head){

    node* temp = head;
    head=head->next;   // we shifted the head forward, so linked list starts from 2nd node now
    free(temp);   // the node that was head is deleted now
    return head;

}
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;

    node(int data1){
        data = data1;
        next = NULL;
    }


};

node* vec_to_LL(vector<int> &arr){
    if(arr.size()==0){return NULL;}
    node* head = new node(arr[0]);
    node *mover = head;


    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;


}

void print_LL(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }


}

node* delete_head(node* head){
    if(head==NULL){      // if head is null, return the same head given to us by the 
        return NULL;
    }
    node* temp=head;
    head=head->next;
    free(temp);   // free up the space alloted to our previous head in heap
    // delete temp;     //writing this will aldo do same, delete
    // if we dont free up the memory, code might still work, but there are chances of memory leak 
    return head;

}


node* delete_tail_LL(node* head){  //since we are told to delete tail of a linked list, there should be atleast 2 nodes. if the LL has 0 nodes or 1 nodes, return null;

        if(head==NULL || head->next==NULL){
            return NULL;
        }

        node*temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        
        

        return head;


}


node* delete_kth_ele(node* head,int k){   // nothing is deleted, if k>size of LL
 // t.c = O(k)
    if(head==NULL){return NULL;}

    if(k==1){
        node* temp = head;
        head=head->next;
        free(temp);
        return head;
        
    }

    int counter=0; node* temp=head; node* prev = NULL;
    while(temp!=NULL){    // covers all cases for deletion except deletion of first node.
        counter++;
        if(counter==k){

            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp=temp->next;

    }

    return head;

}

node* delete_value_node(node* head,int value){

    if(head==NULL){return NULL;}
    node* temp = head;
    node* prev = NULL;

    while(temp!=NULL && temp->data!=value){
        prev = temp;
        temp=temp->next;

    }

    if(temp==NULL){ return head;}
    if(prev==NULL){
        node* temp=head;
        head=head->next; 
        free(temp);
        return head;
    }
   
    prev->next=prev->next->next;
    free(temp);

    return head;

}



int main(){

    vector<int> arr={12,5,8,7};
    
    node *head = vec_to_LL(arr);

    print_LL(head);
    cout<<endl;

    // node* nhead = delete_head(head);
    // print_LL(nhead);

    // node* head = delete_tail_LL(head);
    // print_LL(head);

    // node* mhead = delete_kth_ele(head,2);
    // print_LL(mhead);

    // node* ahead = delete_kth_ele(head,3);
    //   print_LL(ahead);

     node* vhead = delete_value_node(head,18);
       print_LL(vhead);
    
    

}




        node* temp = node;
        node* prev = NULL;
        while(temp!=NULL && temp!=node){
            prev = temp;
            temp=temp->next;
        }
        if(temp==NULL){return node;}
        prev->next=temp->next;
        free(temp);

        return node;
        

        