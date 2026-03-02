// delete node in a linked list 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode *temp = node->next;
        node->val=temp->val;
        node->next=temp->next;   // copy value of next node in the node "node" and delete the next node 
        delete temp;

           
    }
};



// middle of a linked list 

// brute force - 2 pass algorithm : o(1.5n)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* temp = head;
        int count=1;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        int x =0;

        if(count%2==0){
            x=count/2;
        }
        else{
            x=(count)/2+1;
        }

         temp = head;


        while(x>1){
            temp=temp->next;
            x--;
        }

        return temp;


        
        
    }
};



// optimal
 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        
      
        ListNode* slow = head;
        ListNode* fast = head;
     
            while(fast!=NULL && fast->next!=NULL){   // these are 2 edge cases
            slow = slow->next;
            fast = fast->next->next;   // use two pointers, slow and fast.
        
         

        }

        return slow;
        
    }
};



// reverse a linked list 


// stack : LIFO
// use a stack data structure to store the linked list nodes
// put nodes->data in stack, then pop the data and replace it, we get nodes in reversed order
// finally stack becomes empty, and the linked list is reversed " just in terms of data"


// brute force - stack - 2 pass algorithm


class Solution {
public:
    ListNode* reverseList(ListNode* head) {  

        stack<int> vec;
        ListNode* temp = head;

    while(temp!=NULL){    // o(n)
        vec.push(temp->val);
        temp=temp->next;

    }

    temp=head;
    
    while(temp!=NULL){    // o(n)
        temp->val=vec.top();
        vec.pop();
        temp=temp->next;
      

        
    }

    return head;
     
    }
};


/*
t.c = o(2*n)
s.c = o(n) - as we are storing the elements in the stack
the data is replaced just, the links of the linked list is not tampered
*/



// optimal solution (for iterative)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        //s.c = o(1)

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!=NULL){   // t.c = o(n)


               ListNode* front = temp->next;
               temp->next = prev;
               prev=temp;
               temp=front;


        }

        return prev;
        
        
    }
};


// recursive approach 

/*

the problem is broken into small small problems
N nodes as input -> becomes n-1 nodes -> n-2 and so no.... 
n->n-1->n-2....until 1 {base case}
we solve the problem for 1 node, then 1 bigger than it then ... upto n nodes 

base case : 
as in a linked list with 1 node, its reverse is same
if(head==NULL || head->next==NULL){return head;}

reverse(4)

reverse(3)

reverse(2)

reverse(1)

*/



class Solution {
public:

      ListNode* reverse(ListNode* head){

        if(head==NULL || head->next==NULL){
        return head;
        }

        
        ListNode* newnode = reverse(head->next);
           
        ListNode* front = head->next;
        front->next=head;
        head->next=NULL;

        return newnode;
        
          } 


    ListNode* reverseList(ListNode* head) {

    ListNode* ans = reverse(head);

    return ans;

        
    }
};


/*
T.C = O(n)   {see image} - for 4 nodes, 4 function calls (all 4 nodes are traversed )
s.c = o(n)  {recursive stack space}
*/



// linked list cycle 

/*wrong incorrect answer*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode> vec;   // should be vector<listnode*> vec;
        ListNode* temp = head;
        int i=0;
        while(temp!=NULL){
            auto it = vec.find(temp);    // does not exist in vector stl, use find(vec.begin(),vec.end(),ele)
            if(it !=vec.end()){return true;}
            vec[i]=temp;    // this is not possible, push_back is used  9But vec is empty. You never resized or pushed.
            temp=temp->next;
            
        }

        return false;
        
        
    }
};





/*we have to compare nodes by thier addresses not by thier values, as values can repeat
for vector STL we have : find(vec.begin(), vec.end(), temp)

in order to find a value*/



// brute force solution  


class Solution {
public:
    bool hasCycle(ListNode *head) {

        vector<ListNode*> vec;   // better "brute force" uses map data structure
        ListNode *temp = head;

        while(temp!=NULL){

            auto it = find(vec.begin(),vec.end(),temp);
            if(it!=vec.end()){return true;}
            vec.push_back(temp);
            temp=temp->next;

        }

        return false;
        
        
    }
};


/*Traverse the list.

Store every visited node.
For each new node, scan previously visited nodes to check repetition.

That is brute force because:

You are doing repeated linear search.
You are not optimizing lookup.
Time complexity is O(n^2).*/



// better brute force 
// instead of repeated linear search, we can use hashing  
// map<node*,int x>

// if(int x =0) {have not seen the node before}
// if(int x=1) {have sen the nod before}
// it may happen that the values might repeat in the node, so store entire node {entire object itself} not the values
  



class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*,int> mp;   // s.c = o(N)
        ListNode *temp = head;

        while(temp!=NULL){    // t.c = o(n)

            if(mp.find(temp)==mp.end()){   // checking in map

                    mp[temp]=1;   // inserting in map
                    temp=temp->next;

            }
            else{
                return true;
            }

        }

        return false;
        
        
    }
};


// t.c avg = o(1) , worst o(n)  
// s.c = o(n)