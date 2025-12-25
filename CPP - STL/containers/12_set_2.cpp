// multiset & unordered set

// multiset -> can store multiple duplicate elements.
// unordered -> stored in random order. o(1) is time complexity
// in rare cases o(n)
// in unordered --> no concept of lower & upper bound


// unordered set and unordered map are very optimised data structures and are used frequently in dsa questions.



#include <bits/stdc++.h>
using namespace std;
int main(){

    unordered_set<int> st; // will store unique values and no particular order is followed. unsorted.

     
    //multiset<int> st;     // duplicate elements are also stored in the set container in case of multiset. ascending order.
    
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    

    st.insert(1);
    st.insert(2);    
    st.insert(3);

    for(auto val : st){

        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"size of set is: "<<st.size()<<endl;

    return 0;
}
