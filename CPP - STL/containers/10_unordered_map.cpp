// most imp and frequently used map in dsa is unordered map

// normal map -> arrange data in sorted order.
// unordered map -> the data remains unordered, so specific order is followed. ie- data is stored in random order.
// duplicates key can exist only in multimap


#include <bits/stdc++.h>
using namespace std;

int main(){ 

    unordered_map<string,int> m;
    
    m["tv"] = 100;
    m["laptop"] = 50;
    m["phone"] = 150;
    m["tablet"] = 250;
    m["headphone"] = 300;
    

    for(auto p : m){

        cout<<p.first<< " " <<p.second <<endl;
    }
    return 0;

}

// multimap is rarely used
// unordered is used most

// difference between unordered_map & map 
// huge difference is present in time complexity 

// inside map:  functions like insert,erase,count works at log(n) time complexity 
// map is internally implemented as self balancing tree

// unordered map is implemented especially
// insert,erase,count have o(1) (amortised time) ie- avg time   
// in very rare cases its o(n). (when collision occur in maps)


