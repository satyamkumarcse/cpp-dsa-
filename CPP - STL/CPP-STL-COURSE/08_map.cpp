// map container is used to store key:value pairs
// the keys are always unique. there cant be a duplicate key. eg-roll no,product_ids
// eg- productid : quantity 
// quantity bought may be same for 2 products, but product cant.

//  syntax : map<datatype key,datatype value> m;


// map<string,int> mp;


// for changing or inserting new key values we use this syntax 
// m[key]=value;
// if already a key exists with that name 
// its value will be overwrite/updated


// p.first  // gives key string
// p.second // gives value int
/*
p is a pair, not a struct/class with named fields like first, second, third.

A map stores exactly two things per element:

• first = key
• second = value

*/



#include <bits/stdc++.h>
using namespace std;

int main(){

    map<string,int> m;

    m["tv"] = 100;
    m["laptop"] = 50;
    m["phone"] = 150;
    m["tablet"] = 250;
    m["headphone"] = 300;
    // m. insert({"camera",25});
    m. emplace("camera",25);     
    m.erase("tv");  // erases the "tv" key and the associate value.


    for(auto p : m){

        cout<<p.first<< " " <<p.second <<endl;
    }

    //  p.count("key") returns number of keys 
    cout<<m.count("laptop")<<endl;   // output is 1.
    // if i want to print the value
    cout<<m["laptop"]<<endl;  // output : 50 

    // headphone 300
    // laptop 50
    // phone 150
    // tablet 250
    // tv 100

    // we will observe that all the items are printed in a ascending sorted order. sorted order of keys (lexographically)
    // "map" bydefault sorts data in the ascending order of key



    // find 
    // searches for a key,value pair in the map container.
    // if found -> returns an iterator pointing to the element.
    // not found -> returns m.end(); value just after end element.

    // auto it = vec.begin();  // returns iterator to first element
    //auto it = s.find(10);   // returns iterator pointing to key=10, or s.end() if not found 

    if(m.find("camera") !=m.end()){

        cout<<"found!!\n";
    }
    else{
        cout<<"not found\n";


    }



    return 0;
}

