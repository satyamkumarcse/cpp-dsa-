// other maps are multimap & unordered map

// multiple keys can be stored in case of multimap
// all other functionalities are same
// as multiple keys are there, square bracket notation [] cant be used


#include <bits/stdc++.h>
using namespace std;

int main(){

    multimap<string,int> m;

    
    // m["tv"] = 100;
    // m["laptop"] = 50;    
    // m["phone"] = 150;    // cant use
    // m["tablet"] = 250;
    // m["headphone"] = 300;

    m.emplace("tv",100);
    m.emplace("tv",100);
    m.emplace("tv",100);
    m.emplace("tv",100);

    //m.erase("tv");    // will erase all instances tv 

    /*if i want to delete only first instance of tv, i have to pass iterator
    when an iterator is passed inside m.erase , the m.erase() will fetch the memory location to where iterator is pointing to and erase it.*/
    m.erase(m.find("tv"));



    for(auto p:m){

        cout<<p.first<<" "<<p.second<<endl;
    }

    //in case of normal "map" if we inserted "tv" multiple times.
    //  it would have been printed only once.
    // but in case of multimap 4 times it will print




    return 0;
}

// in multimap [] cant be used. 
// [] or emplace is used in both map & unordered_map 
// if a key already exist, and emplace is used again with same key written in it, then its ignored. exception : multimap
// emplace() is not used for updating values.
// It attempts to insert a new key–value pair only.

/*Container	  operator[] (insert/update)	       emplace() insert
map             	yes                      	    yes
unordered_map	    yes	                            yes
multimap	         no	                             yes
*/