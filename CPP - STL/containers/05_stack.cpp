void explainstack(){
    //maninly has 3 functions [push,pop,top]

    stack<int> st;   // for creating a stack
    st.push(10);  //{10}
    st.push(21);//{21,10}
    st.push(24);//{24,21,10}
    st.push(32);//{32,24,21,10}
    st.emplace(5);//{5,32,24,21,10}

    cout<<st.top();    // prints the element present at top, here(5)
    // we cant access by indeding st[2] etc... not possible in stack.

    st.pop();  //{33,24,21,10}    ,  5 is popped

    cout<< st.top();   // 33  (tells what is present at top)

    cout<<st.size();   // size is 4
    cout<<st.empty();    // false 


    stack<int> st1,st2;   // for declaring 2 stack at once, having elements of int datatype.



}

// all the operations studied in stack are O(1) operations  (push,top,pop)
//  ie- const time complexity