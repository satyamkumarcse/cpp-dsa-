// first container that we will learn is vectors 
#include <bits/stdc++.h>
using namespace std;

void explainvector(){

    vector<int> vec;       // creates an empty container
    vec.push_back(1);      // 1 is filled in empty container
    vec.emplace_back(2);   // emplace back is comparatively faster than pushback
    // dynamically the size increases, and 2 is pushed 

    /*
    why emplace back is faster?

    push_back

    You pass an already-created object.

    Steps when inserting:

    Construct object outside vector

    Copy/move it into vector storage



    emplace_back

    Constructs the object directly in vector memory using constructor arguments.

    eliminates one move or copy operation. 



    Operation	          push_back(obj)	emplace_back(args…)
    Construct object      outside vector	  inside vector
    Copy/move needed	        Yes	               No

    emplace_back is faster than push_back because:

    It constructs elements directly in place.

    It avoids temporary object creation.

    It avoids extra move/copy operations.
    */
    


    // vector of pair datatype 

    vector<pair<int,int>> vec;     // vector has a pair inside it, having elements in int datatype
    vec.push_back({1,2});
    vec.emplace_back(1,2);    // emplace back automatically assumes it to be a pair and takes it as an input and inserts into the vector that you have defined. assumes that pair is already made.

    vector<int> vec(5,100);    // 100 is a element appearing 5 times inside the vector.

    vector<int> vec(5);      // a vector with 5 instances of 0 or any garbage value is declared (depending on a compiler)
    // even if size is declared as 5, if you try to push_back 6th element, it can be done, as dynamic nature.
    

    vector<int> v2(v1);   // initialising a vector v2 with elements of vector v1

    //for getting element of a vector, 2 ways
    // 1st
    v[index];
    v.at(index);

    // 2nd 
    // by using iterator 
    // vec = [10,20,30,40]  assume
    vector<int>::iterator itr = v.begin();               //   ::iterator   -->  used for looping for elements present inside a vector container.

    itr++;

    // or write -- v.begin()+ 1

    cout<<*(itr)<<" "; 

    // iterator points to the memory address of the element present in the container.
    // use * to derefrence and print actual value present on that address.

    // v.begin() -- points to element present at 0th index (10).
    vector<int>::iterator itr = v.end();
    // v.end() -- "end" points to somewhere right after the last element.
    // it--;  --> now it points to the last element(40)
    vector<int>::iterator itr = v.rend(); // pointing just before (10)
    vector<int>::iterator itr = v.rbegin();   // pointing at 40
    // in case of rbegin 
    // itr++ --> moves from 40-30-20-10 (reverse iterator)
    // v.back() --> points at 40


    // printing elements of a vector  

    // using vector iterator

    vector<int> vec;
    for( vector<int>::iterator it= vec.begin();it!=vec.end();it++){

        cout<<*(it)<<" ";
    }

    // vector<int>::iterator --> auto  (short abbrevation) "auto" is used to automatically assing to a "vector iterator" act. 
    // the datatype is also automatically determined by auto.
     

    for( auto it= vec.begin();it!=vec.end();it++){

        cout<<*(it)<<" ";              // as iterator points to memory address, there is a need to use *, in order to print the value stored inside.
    }

    for(auto elements : vec){

        cout<<elements<<" ";    // dont use *, not an iterator
    }

    // If you want to modify elements in range-based loop, use reference:

    for(auto &it : vec){
        it += 10;
    } 

    //  Otherwise copies are modified, not original vector.




    // deletion in a vector
    // let a vector be {10,20,12,23} 
    v.erase(v.begin()+1);     // location of the address you want to delete
    // 20 will be deleted : {10,12,13}
    v.erase(v.begin()+2,v.begin()+4);   // end is excluded from range.

    // insert function 

    vector<int>v(2,100);
    // {100,100}
    v.insert(v.begin(),300);
    // {300,100,100}
    v.insert(v.begin()+1,3,10);
    // {300,10,10,10,100,100}    // starts inserting at that particular index
    

    // inserting some vector (copy) into other (v).

    // let us make a vector named as copy
    // v = {30,10,10,100,100}
    vector<int> copy(2,50);
    v.insert(v.begin()+1,copy.begin(),copy.end())  
    // {30,50,50,10,10,100,100}

    // v.size() --> number of elements that are present (increases by 1)
    // v.capacity() --> that it can hold 
    //  increases geometrically (1,2,4,8.....)

    // v1 = {10,20}
    // v2 = {30,40}
    v1.swap(v2)  
    // v2 = {10,20}
    // v1 = {30,40}
    // v.clear()  --> erases the vector 
    // erase/insert is in general costly function time complexity wise.
     
}









 