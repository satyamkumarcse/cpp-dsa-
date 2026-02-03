//  while(x--) runs exactly x times, stopping when x becomes zero.
// character hasing can be done using arrays



// intuitive code (wrong technically)

#include <iostream>
#include <string.h>
using namespace std;



// int main(){

//     string s = "abcdabefc";
//     int x = s.length();
    
//     int hashfrq[26]={0};


//     for(int i=0;i<x;i++){
//         hashfrq[s[i]-'a']+=1;

//     }
    

//     for(int i=0;i<x;i++){

    
//         cout<<"frequency of "<<s[i]<<" is "<<hashfrq[s[i]-'a']<<endl;
        
        
//     }


//     return 0;
// }



/*frequency of b is 2
frequency of c is 2
frequency of d is 1
frequency of a is 2
frequency of b is 2
frequency of e is 1
frequency of f is 1
frequency of c is 2*/

// its correct but characters are repeating.
// stated that, all characters are lower case.





// good solln non optimal

 



// int main(){

//     string s = "abcdabefccc";
//     int x = s.length(); 
    
    
//     bool visited[x]={false};


//     for(int i=0;i<x;i++){
//         int count=1;
//         if(visited[i]){
//             continue;
//         }
        

//         for(int j=i+1;j<x;j++){

        
//             if(s[i]==s[j]){
//                 count++;
//                 visited[j]=true;

//             }
            
            
//         } 

//     cout<<"frequency of "<<s[i]<<" is "<<count<<endl;

// }
//     return 0;
// }



// here we trade off with t.c. t.c increased to O(n^2)



// good optimal soln 



// we create array of size 26.
// int x = 'a'   -> x here, stores the ascii value which is 97 
// a syntax error will not be thrown, the 'a' will be typecasted





#include <bits/stdc++.h>
 using namespace std;

 int main(){

    string s = "gdufuffsyfsthedgg";
    int x = 'a';
    bool detect[26]={false};

    int arr[26]={0};

    for(int i=0;i<s.length();i++){

        arr[s[i]-x]+=1;

    }


    for(int i=0;i<s.length();i++){
        if(detect[s[i]-x]){
            continue;
        }
        else{

             cout<<"frequency of "<<s[i]<<" "<<arr[s[i]-x]<<endl;
             detect[s[i]-x]=true;

        }

    }

    return 0;
 }



//  if not mentioned that all letters are lowercases. instead of 26. take hash array as size of 256



// in number hasing we saw if we go beyond 10^7 or 10^6 etc, we will get errors
// in case of character hasing we will not get problem as max to max there are 256 ASCII characters & 256 characters can be stored by them.

//  arr[(int(s[i]))] can also be written as arr[s[i]] , the arr[], the brackets needs an integer. 
// even if we write an character, it will be autocasted to its integer value.




// max size of arrays while creating a hash arrays were 10^7. 
// in order to create arrays of more length, we can use STL like map,unordered_map 


// map in c++
// map <key,value> map1
// if we have declared a map stl but it has no values in it 
// map1[1] -> is 0
// map[1]++ -> becomes 0 + 1 = 1


// so in general

// map1[arr[i]]++     -> can be used to store frequency of letters/numbers ie- hashing 


// in case of hashing using array, it was required to declare an array of size 13,26,256 IN ADVANCE in order to store an element of value 12 etc...
// but in case of stl map, only those mappings are done that are required,so map takes less memory.


// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     int x;
//     cin >> x;

//     vector<int> arr1(x);
//     for (int i = 0; i < x; i++) {
//         cin >> arr1[i];
//     }

//     // Build frequency map
//     map<int, int> map1;
//     for (int i = 0; i < x; i++) {
//         map1[arr1[i]]++;
//     }

//     int y;
//     cin >> y;

//     while (y--) {
//         int numx;
//         cin >> numx;

//         // If key not present, map gives 0 by default when accessed
//         cout << map1[numx] << endl;
//     }

//     return 0;
// }



/*
input:

5
1 3 2 1 3
5
1
4
2
3
12

output:

2
0
1
2
0


*/

// the map store all the values in sorted order













// unordered map can also be used in string hashing 

// int main(){

//     string s = "sattudonnnnnnn";
//     int x = s.length();

//     unordered_map<char,int> mpp1;

//     for(int i=0;i<x;i++){
//         mpp1[s[i]]++;
//     }
//     for(auto it : mpp1){

//         cout<<it.first<<" --> "<<it.second<<endl;
//     }
// }





// Time complexity of map  
// in map, we store or fetch 
// it takes t.c = log(n) in all the cases
// best,avg and worst
// even if we take an unordered map, the programs written above will run 
// map -> stores in sorted order
// unordered_map -> unsorted 


// unordered_map has some advantages 
// storing & fetching has t.c of O(1) in average and best case
// O(n) -> linear time in worst cases 

// so in worst case, running a loop & using map features 
//  for(int i=0;i<x;i++){
//         mpp1[s[i]]++;
//     }

// tc for unordered map becomes -> O(n^2)
// prioritised using unordered map, but if there is a runtime error 
// then switch map
// worst case happens because of internal collisions

/*

unordered_map

No ordering guarantee
Faster average lookup O(1) (best & average)


map

Keys always sorted
Lookup O(log n)

*/



  

// array hashmaps has limit of around 10^6 o 10^7 
// but map dont have any limit, lets see the logic 

// implementation of map data structure 
// 1) division method 2) folding method 3) mod square method


// division method 
 

// take an array -> {2,5,16,26,139}
// we can peform operations on this array by creating an array of size 140 and mapping values etc.

// assume a constraint is given in the question that, the array size cant be more than 10.
// we can use division method to hash it 
// we will modulate the array elements with 10 -> arr[i]%10
// divison method trimmed down the elements 
// we get -> {2,5,6,6,9}
// now array hasing is possible
// for input 139 -> 139%10 == 9, then the frequency of 9 is checked 


// a case may arise where after moduluo with 10, we are getting same numbers
// [2,5,16,28,139,38,48,28,18]
// here 28,38,18 will give 8 as result after moduluo 10 
// linear chaining is done, we cant store them directly, so we chain it (see pic)
// 28->38->48
// use linked list concept to insert 18 it between.(see img)

// now when an element%10 gives 8
//  we get to 8 branch, and peform search algorithms like binary search.
// by this, we can get element frequency in minimal duration time



// worst case
// [8,18,28,38......1008]
// all elements going to a same hash index is a collison scenario (see image)
// in this case, worst will happen -> O(n)
  



// map<key,value> map1
// the key can be any datatype, even  eg- map<pair<int,int>,<int>> map1  


// in unordered 
// only individual data types can be the key like (int,double,char,string)




// INT_MAX = 2^31 - 1
// INT_MIN = -2^31



