/*
// reversing all values present in a vector 
{1,2,3,4,5,6,7,8}

reverse(v.begin,v.end());        {8,7,6,5,4,3,2,1}

// reversing values within a particular range

reverse(v.begin()+2,v.begin()+5);        {1,2,5,4,3,6,7,8}


// these 2 above can also be done with sorting

next_permutation(v.begin(),v.end()); 

// gives the next permutation for an array with int or string
// "abc"  -> 3!  -> total 6 permutations -> generally -> n! 
//  abc acb bac bca cab cba    -> lexographically

*/



 #include <bits/stdc++.h>
 using namespace std;

 int main(){

    string s = "abc";
    next_permutation(s.begin(),s.end());
    prev_permutation(s.begin(),s.end());
    cout<<s<<endl;   // returns the next permutation
 
    cout<< max(4,5) <<" "<< min(6,10) << endl;

    int a=45,b=56;
    swap(a,b); 
    cout<<a<<" "<<b<<endl;

    vector<int> vec={23,56,78,43,56,11,33,55};
    cout<<*(max_element(vec.begin(),vec.end()))<<endl;   //  -> returns iterator of the element that is max/min. use * to derefrence and print the value
    cout<<*(min_element(vec.begin(),vec.end()))<<endl; 

    // binary search
    // returs a bool value, whether the target exist or not  0- false, 1 - true
    // works only on sorted vector 
    sort(vec.begin(),vec.end());
    cout<<binary_search(vec.begin(),vec.end(),43)<<endl; 

     

    // count set bits -> this fxn is used to count setbits in a number
    // eg - 15. takes 4 byte memory . 1111 
    // 4 byte = 32 bits 
    //  0000000...........1111 -> total 32 digits
    // but set bits -> 4 only

    int n1=15;
    long int n2=12;
    long long int n3 = 15;
    cout<<__builtin_popcount(n1);  // output is 4
    cout<<__builtin_popcountl(n2);  // a trailing "L" is added
    cout<<__builtin_popcountll(n3);  // one more l 

    



    return 0;
 }