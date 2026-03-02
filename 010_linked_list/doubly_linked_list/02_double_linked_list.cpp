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

node* insert_before_head(node* head){

    node* newnode = new node(10);

    if(head==NULL){
        head=newnode;
        return head;
    }
 
    newnode->next=head;
    head->back=newnode;
    head=newnode;

    return head;

}


node* insert_before_tail(node* head){

    node* newnode = new node(55);

    if(head==NULL){
        head=newnode;
        return head;
    }
    if(head->next==NULL){
        newnode->next=head;  
        head->back=newnode;
        head=newnode;
        return head;
    }

    node* temp = head;
    
    while(temp->next->next!=NULL){

        temp=temp->next;

    }

    node* front = temp->next;
    
    newnode->next=temp->next;
    front->back=newnode;
    newnode->back=temp;
    temp->next=newnode;

    return head;

    

}

/*
If the list is empty, do not insert. Delete newnode and return NULL.
ele is never greater than the length.
ele >= 1.
*/

node* inserting_before_kth_ele(node* head,int ele,int value){
    
    node* newnode = new node(value);

    if(head==NULL){
        delete newnode;
        return NULL;
    }

      if(ele==1){
    newnode->next=head; 
    head->back=newnode;
    head=newnode;

    return head;


      }

    //   node* temp=head;
    //   int count=1;

    //   while(temp!=NULL && count<ele-1){
    //     temp=temp->next;
    //     count++;

    //   }

    //   if(temp==NULL || temp->next==NULL){
    //     delete newnode; 
    //     return head;
    // }
      
    //   node* front = temp->next;
    //   newnode->next=front;
    //   front->back=newnode;
    //   newnode->back=temp;
    //   temp->next=newnode;

    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==ele){break;}
        temp=temp->next;
    }



    node* prev = temp->back;
    newnode->next=temp;
    temp->back=newnode;
    newnode->back=prev;
    prev->next=newnode;

      return head;





}

void inserting_before_kth_node(node* temp){   // kth != 1 , we are not inserting before 1st node

    node* newnode = new node(10);
    if(temp==NULL){return;}

    node* prev = temp->back;
    newnode->next = temp;
    temp->back=newnode;
    prev->next=newnode;
    newnode->back=prev;



}




int main(){


    vector<int> arr={20,30,40,50,60};
    node* head = arr_to_2DLL(arr);
    print2dLL(head);
    // head = insert_before_head(head);
    // print2dLL(head);

    // head =  insert_before_tail(head);
    // print2dLL(head);

    // inserting_before_kth_node(head->next->next);
    //  print2dLL(head);

    head = inserting_before_kth_ele(head,5,99);
    print2dLL(head);


}






/*


node* insert_after_tail(node* head,int value){

    node* newnode = new node(value);
    if(head==NULL){

    head = newnode;
    return head;

    }

    node*temp=head;
    while(temp->next!=NULL){
    temp=temp->next;}

    temp->next=newnode;
    newnode->next=NULL;
    newnode->back=temp;
    return head;



}


*/