// set is a container that stores unqiue values in a sorted(ordered) way

// set <int> s;

// for inserting data we can use insert, emplace function.

#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> st;
    
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    st.insert(6);

    // st.insert(3);
    // st.insert(4);      //if duplicate values are tried to store in set, then they wont be stored. size also remains same
    // st.insert(5);

    for(auto val : st){

        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"size of set is: "<<st.size()<<endl;

//     output: 10 20 30 40 50 
//             size of set is: 5
/*other functions like count,erase,size,find,empty works the same*/
// insert,count,erase --> o(logn)  ; because it uses self balancing tree internally.


// two additional functions in set 
// lowerbound 
// upperbound

// lowerbound : set a condition 
// eg - s = {1,2,3,4,5,6}  
// s.lowerbound(4);   --> it will return an iterator for 4.
// *(s.lowerbound) will get only 4 if it exists, or the element just higher than 4 in value. ie- 4 & 5 (comment 15,20 to check)
cout<<"lower bound is: "<<*(st.lower_bound(4))<<endl;  // 4
cout<<"upper bound is: "<<*(st.upper_bound(4))<<endl;   // 5
//if the element written in lower bound is not in set, andn also if no element greater than the lower bound is there. then st.end() will be displayed. 0 is displayed.


// • lower_bound returns iterator
// • iterator must be dereferenced to access actual value
// • must check for end() before dereferencing to avoid crash


//upper bound

// set1 = {a,a,b,b,b,c,c,d}   
// if we set lower_bound("b")  --> should not less than the key. (2 and above)
//  upper_bound("b")  --> greater than the key. (5 and above)
// lb = index = 2
// up = index = 5


    return 0;
}