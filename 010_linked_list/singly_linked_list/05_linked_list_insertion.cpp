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


node* insert_first(node* head,int value){  
    node* nnode = new node(value);

    nnode->next=head;    // head can be null here, in case there is 0 element in LL
    head=nnode;

    return head;
}

node* insert_last(node* head,int value){
    

    node* lnode = new node(value);
    if(head==NULL){
        head=lnode;
        return lnode;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=lnode;
    return head;
}


node* insert_kth(node* head,int kth,int value){

    if(kth==1){
        node *newnode = new node(value);
        newnode->next=head;
        head = newnode;
        return head;

    }
    if(head==NULL){

        return head;
        
    }

    int counter=1;
    node* temp=head;
    while(temp!=NULL && counter<kth-1){
        temp=temp->next;
        counter++;
    }

    if(temp==NULL){return head;}

     node *newnode = new node(value);
     newnode->next = temp->next;
     temp->next=newnode;


    return head;

}

node* insert_before_value(node* head,int value,int ele){

    if(head==NULL){
        return head;
    }

    node*temp=head;
    node*prev=temp;
    int count=0;
    while(temp!=NULL && temp->data!=value){
        prev = temp;
        temp=temp->next;
        count++;
    }

    if(temp==NULL){return head;}
    if(count==0){
        node* newnode = new node(ele);
        newnode->next=head;
        head=newnode;
        return newnode;

    }
    node* newnode = new node(ele);
    newnode->next=prev->next;
    prev->next=newnode;

    return head;


}



int main(){

    vector<int> arr={12,45,67,89};
    
    node *head = vec_to_LL(arr);

    print_LL(head);
    cout<<endl; 
    // node* nnhead = insert_first(head,5);
    // print_LL(nnhead);
    // cout<<endl;
    // node* llhead = insert_last(head,33);
    //  print_LL(llhead)
    // node* nhead = insert_kth(head,1,99);
    // print_LL(nhead);

    node* h = insert_before_value(head,700,66);
    print_LL(h);

    cout<<endl;

    

}
