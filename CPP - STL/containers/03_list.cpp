// list is similar to vector, unique thing is that you have front operations as well 

void explainlist(){

    list<int> ls;   // initialize an empty list

    ls.push_back(2)  // {2}
    ls.emplace_back(4)  // {2,4}
    ls.push_front(5);  // {5,2,4}  (unique function in case of list)
    
    
    // in vectors, we used "insert" operation to insert at front.
    // these are costly functions. time complexity wise. avoid it.

    // insert(pos, value) → O(n)
    // Reason: shifts all elements to the right by 1 unit.

    // erase(pos) → O(n)
    // Reason: shifts elements left.

    // using list is preffered in such cases.


    ls.emplace_front(); //{0,5,2,4}
    ls.sort(); //{0,2,4,5}
    // rest functions same as v9ector 
    // begin,end,rbegin,rend,clear,insert,size,swap

}
