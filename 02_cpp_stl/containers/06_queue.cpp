void explainqueue(){

    queue<int> q;
    q.push(1);   //{1}
    q.push(2); //{1,2}
    q.emplace(4);  //{1,2,4}

    q.back()+=5;     //{1,2,9}

    cout<<q.back();   //prints 9
    cout<<q.front();   // prints 1

    q.pop();   // deletes 1
    cout<<q.front();    // prints 2

    // size,swap,empty same as stack


}

// O(1) const time : all operations
// push,front,pop (o(1))