void explaindeque(){

    deque<int> dq;   //initializing a deque
    dq.push_back(1);  //{1}
    dq.emplace_back(2);  // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(3);  // {3,4,1,2}

    dq.pop_back()    //{2,4,1}
    dq.pop_front()// {4,1}

    dq.back();    // returns the last element
    dq.front();   // returns the first element

    // rest functions are same as vector 
    // begin,end,rbegin,rend,clear,insert,size,swap

    
}